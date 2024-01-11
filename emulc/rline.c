/*
 * rline - event-driven readline ersatz.
 *
 * Copyright (C) 2000-2001 Laurent Vogel 
 * This file is part of EmulC, the Emulator on Curses library.
 *
 * This is free software covered by the GPL version 2 or later, and
 * comes with NO WARRANTY - read the file COPYING for details.  
 */

/*
 * this is an ersatz of editline.c, itself a clone of the readline library.
 * I did not use editline after all because it was too difficult to
 * make it event-driven (that is, whenever a key is available, rline is
 * requested to do something with it).
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "emulc.h"
#include "rline.h"

/* structures */

#define RLINE_MAX_LINE 200
#define RLINE_MAX_SCREEN 400
#define RLINE_MAX_PROMPT 200

#define RLINE_STATE_INACTIVE 0
#define RLINE_STATE_ACTIVE 1
#define RLINE_STATE_CTRL_V 2
#define RLINE_STATE_COMPL 3

struct rline_info {
  Term term;
  void (*cmd_handler)(void *obj, char *cmd);
  void *cmd_handler_obj;
  Rlhist hist;
  Rlcmpl compl;
  int hist_pos;
  char prompt[RLINE_MAX_PROMPT];
  char buf[RLINE_MAX_LINE];
  char screen[RLINE_MAX_SCREEN];
  int max_len;  /* = 80 - prompt_len, for we do not handle multi lines yet */
  int prompt_len;
  int row;   /* pos in screen, 0 at the right of prompt (empty line) */
  int pos;   /* pos in memory, 0 at the beginning of the line */
  int state;
};


/* private prototypes */

static void rline_redraw(Rline r);
static void rline_repos(Rline r);
static void delete_char(char *p);
static void insert_char(char *p, char c);
static void rline_do_key(Rline r, int key);
static void rline_show_hist_pos(Rline r);
static void rline_do_char(Rline r, char c);

/* implementation */


Rline rline_init(Term t, void (*handler)(void*,char*), void* obj, Rlhist h)
{
  Rline r;
  r = malloc(sizeof(*r));
  if(r == NULL) {
    ec_fatal("no memory for rline_init()");
  }
  r->term = t;
  te_set_kbd_handler(t, rline_got_key, r);

  r->cmd_handler = handler;
  r->cmd_handler_obj = obj;
  if(h == NULL) {
    h = rlhist_init();
  }
  r->hist = h;
  r->hist_pos = rlhist_bottom(h);

  r->compl = rlcmpl_init(r);

  r->prompt_len = 0;
  r->prompt[0] = 0;
  r->buf[0] = 0;
  r->screen[0] = 0;
  r->row = 0;
  r->pos = 0;
  r->state = RLINE_STATE_INACTIVE;
  return r;
}

void rline_set_prompt(Rline r, char *prompt)
{
  char *p, *q;
  int len, p_len;
  assert(r);

  /* funny way of computing the prompt_len if there are escape sequences
     in the prompt. only 'esc' '[' nnn 'm' is allowed. */
  p = prompt;
  q = r->prompt;
  len = 0;
  p_len = 0;
  while(*p) {
    if(*p == 033) {
      while(*p && (*p != 'm') && (len < RLINE_MAX_PROMPT - 1)) {
        *q++ = *p++;
        len++;
      }
      if(len >=  RLINE_MAX_PROMPT - 1) {
        /* cancel last esc sequence */
        while(*q != 033) { --q; --len; }
        *q = 0;
        break;
      }
      p_len--; /* for the remaining 'm' */
    }
    if(len >=  RLINE_MAX_PROMPT - 1) {
      *q = 0;
      break;
    }
    *q++ = *p++ ;
    len ++;
    p_len ++;
  }
  r->prompt_len = p_len;
  
  if(r->state) { 
    rline_redraw(r);
  }
}

void rline_prompt(Rline r)
{
  r->state = RLINE_STATE_ACTIVE;
  rline_redraw(r);
}

static void rline_redraw(Rline r)
{
  te_output_char(r->term, '\r');
  te_output_string(r->term, r->prompt);
  te_output_string(r->term, r->screen);
  te_output_string(r->term, "\033[K");
  rline_repos(r);
}

#define TWO_CHARS(c) ((((c) >= 0) && ((c) < 32)) || ((c) == 127))

static void rline_sync_screen(Rline r)
{
  char *p = r->buf;
  char *q = r->screen;

  while(*p) {
    if((*p > 0) && (*p < 32)) {
      *q++ = '^';
      *q++ = (*p) +'@';
    } else if(*p == 127) {
      *q++ = '^';
      *q++ = '?';
    } else {
      *q++ = *p;
    }
    p++;
  }
  *q = 0;
}

static void rline_goto(Rline r, int n)
{
  int row = 0;
  char *p = r->buf;
  r->pos = n;
  while(n--) {
    if(TWO_CHARS(*p)) {
      row += 2;
    } else {
      row ++;
    }
    p++;
  }
  r->row = row;
  rline_repos(r);
}

static void rline_repos(Rline r)
{
  char esc_buf[10];
  int offset;

  offset = r->prompt_len + r->pos;
  sprintf(esc_buf, "\r\033[%dC", offset);
  te_output_string(r->term, esc_buf);
}

void rline_got_key(void * Rline_r, int key)
{
  Rline r = (Rline) Rline_r;
#if 0
  ec_stderr("rline_got_key(%d)\n", key);
#endif

  switch(r->state) {
  case RLINE_STATE_INACTIVE:
    return;
  case RLINE_STATE_ACTIVE:
    rline_do_key(r, key);
    break;
  case RLINE_STATE_CTRL_V:
    if(key > 255) {
      /* some trouble to fit this in a char ... */
      key = 0;
    }
    r->state = RLINE_STATE_ACTIVE;
    rline_do_char(r, (char)key);
    break;
  case RLINE_STATE_COMPL:
#ifndef __TINYC__
    rlcmpl_got_key(r->compl, key);
    r->state = RLINE_STATE_ACTIVE;
#endif
  }
}
 

static void delete_char(char *p) 
{
  while(*p) {
    *p = p[1];
    p++;
  }
}

static void insert_char(char *p, char c)
{
  /* CAUTION : does not check string against bounds !!! */
  int i = 0;
  while((i < 100) && (*p++)) i++;
  while(i-->=0) {
    p--;
    p[1] = *p;
  }
  *p = c;
}

#include <curses.h>

static void rline_do_key(Rline r, int key)
{
  char *p;
  char *q;
  switch(key) {
  case KEY_UP:
    r->hist_pos = rlhist_up(r->hist, r->hist_pos);
    rline_show_hist_pos(r);
    break;
  case KEY_DOWN:
    r->hist_pos = rlhist_down(r->hist, r->hist_pos);
    rline_show_hist_pos(r);
    break;
  case KEY_LEFT:
    if(r->pos > 1) {
      r->pos --;
      p = r->buf + r->pos;
      if(TWO_CHARS(*p)) {
        te_output_char(r->term, 8);
        r->row --;
      }
      te_output_char(r->term, 8);
      r->row --;
    }
    break;
  case KEY_RIGHT:
    p = r->buf + r->pos;
    if(*p) {
      q = r->screen + r->row;
      if(TWO_CHARS(*p)) {
        te_output_char(r->term, *q++);
        r->row ++;
      }
      te_output_char(r->term, *q++);
      r->row ++;
      r->pos++;
    }
    break;
  case KEY_END:
  case 'E'-'@':
    r->pos = strlen(r->buf);
    r->row = strlen(r->screen);
    rline_repos(r);
    break;
  case KEY_HOME:
  case 'A'-'@':
    r->pos = 0;
    r->row = 0;
    rline_repos(r);
    break;
  case 'L'-'@':
    rline_redraw(r);
    break;
  case 'K'-'@':
    /* clear to end of line */
    p = r->buf + r->pos;
    *p = 0;
    q = r->screen + r->row;
    p = q;
    while(*q) {
      *q++ = ' ';
    }
    q = p;
    te_output_string(r->term, q);
    *q = 0;
    rline_repos(r);
    break;
  case KEY_BACKSPACE:
  case 8:
    if(r->pos >= 1) {
      r->pos --;
      /* do it ... */
      p = r->buf + r->pos;
      q = r->screen + r->row;
      if(TWO_CHARS(*p)) {
        q -= 2;
        r->row -= 2;
        te_output_string(r->term, "\010\010\033[2P");   /* delete chars */
        delete_char(q);
        delete_char(q);
      } else {
        q--;
        r->row --;
        te_output_string(r->term, "\010\033[P");
        delete_char(q);
      }
      delete_char(p);
    }
    break;
  case KEY_DC:
  case 127:
    if(r->pos >= 0) {
      p = r->buf + r->pos;
      q = r->screen + r->row;
      if(TWO_CHARS(*p)) {
        te_output_string(r->term, "\033[2P");   /* delete chars */
        delete_char(q);
        delete_char(q);
      } else {
        te_output_string(r->term, "\033[P");
        delete_char(q);
      }
      delete_char(p);
    }
    break;
  case 'V'-'@':
    r->state = RLINE_STATE_CTRL_V;
    break;
  case 9:
#ifndef __TINYC__
    if(!rlcmpl_do_tab(r->compl)) {
      r->state = RLINE_STATE_COMPL;
    }
#endif
    break;
  case 10:
  case 13:
    te_output_char(r->term, 10);
    /* add to history */
    rlhist_add(r->hist, r->buf);
    r->hist_pos = rlhist_bottom(r->hist);
    /* ship this command. */
    p = malloc(strlen(r->buf)+1);
    if(p == NULL) ec_fatal("memory in rline");
    strcpy(p, r->buf);
    r->buf[0] = 0;
    r->screen[0] = 0;
    r->pos = 0;
    r->row = 0;
    r->cmd_handler(r->cmd_handler_obj, p);
  /* it is responsibility of cmd handler to redraw the prompt */
  /* rline_prompt(r); */
    break;
  default:
    if((key > 255) || (key < 32)) 
      break ;
    /* now it is a plain char */
    rline_do_char(r, (char)key);
  }
}
      
static void rline_show_hist_pos(Rline r)
{
  char *p, *q;
  p = r->buf;
  q = r->screen;
  strncpy(p, rlhist_get_nth_line(r->hist, r->hist_pos), RLINE_MAX_LINE-1);
  p[RLINE_MAX_LINE -1] = 0;

  rline_sync_screen(r);
  rline_redraw(r);
  rline_goto(r, strlen(r->buf));
  return;

  /* position at beginning and draw */
  r->pos = 0;
  r->row = 0;
  rline_repos(r);
  te_output_string(r->term, r->screen);
  te_output_string(r->term, "\033[K");
  /* position at the end */
  rline_goto(r, strlen(r->buf));
  r->pos = p - r->buf;
  r->row = q - r->screen;
}

static void rline_do_char(Rline r, char c)
{
  char *p, *q;
  p = r->buf + r->pos;
  q = r->screen + r->row;
  if((c >= 0) && (c < 32)) {
    insert_char(q, c + '@');
    insert_char(q, '^');
    te_output_string(r->term, "\033[2@^");
    te_output_char(r->term, c+'@');
    r->row +=2;
  } else if(c == 127) {
    insert_char(q, '?');
    insert_char(q, '^');
    te_output_string(r->term, "\033[2@^");
    te_output_char(r->term, '?');
    r->row +=2;
  } else {
    insert_char(q, c);
    te_output_string(r->term, "\033[@");
    te_output_char(r->term, c);
    r->row ++;
  }
  insert_char(p, c);
  r->pos ++;
  r->buf[RLINE_MAX_LINE-1] = 0;
  r->screen[RLINE_MAX_SCREEN-2] = 0;
}

/******************************** Rline History ******************************/


#define RLHIST_SIZE     80
#define RLHIST_BUF_SIZE (40 * RLHIST_SIZE)

struct rlhist_info {
  int size;
  char buf[RLHIST_BUF_SIZE], *beg, *beg_free, *end_free, *end ; 
  char *lines[RLHIST_SIZE];
};

/* simple structure. we delete old lines when no room left. */
/*
 *  beg          beg_free     end_free    end   
 *   |______________|____________|__________|
 *   <---occupied--->   (free)   <-occupied->
 *
 * We will delete old lines until the free zone after pos is big enough for
 * the line to add. If needed, we continue deleting old lines starting from
 * beg.  end_free will always be the beginning of the oldest line, or end if
 * the thing is empty.
 */

/* private prototypes */

static void rlhist_delete_oldest(Rlhist h);

/* implementation */

Rlhist rlhist_init(void)
{
  Rlhist h;
  h = malloc(sizeof(*h));
  if(h == NULL)
    ec_fatal("no memory for rlhist_init");
  h->beg = h->buf ;
  h->beg_free = h->beg;
  h->end = h->beg + RLHIST_BUF_SIZE;
  h->end_free = h->end;
  h->size = 0; /* number of lines in h->lines */
  return h;
}

/* h->lines[0] is newest line */
int rlhist_down(Rlhist h, int pos)
{
  (void) h;
  pos --;
  if(pos < 0)
    pos = -1;
  return pos;
}

int rlhist_up(Rlhist h, int pos)
{
  pos ++;
  if(pos >= h->size)
    pos = h->size - 1;
  if(pos < 0)
    pos = -1;
  return pos;
}

int rlhist_bottom(Rlhist h)
{
  (void) h;
  return -1;
}

char *rlhist_get_nth_line(Rlhist h, int pos)
{
  if((pos < 0) || (pos >= h->size)) {
    return "";
  }
  return h->lines[pos];
}

void rlhist_add(Rlhist h, char *p)
{
  int i;
  int len;
  len = strlen(p) + 1;
  

  if(len > 200) len = 200;

  if(h->size >= RLHIST_SIZE) {
    rlhist_delete_oldest(h);
  }

  while(h->end_free - h->beg_free < len) {
    rlhist_delete_oldest(h);
  }
  for(i = h->size ; i > 0 ; i--) {
    h->lines[i] = h->lines[i-1];
  }
  h->lines[0] = h->beg_free;
  h->size ++;
  strncpy(h->lines[0], p, len -1);
  h->lines[0][len-1] = 0;
  h->beg_free += len ;
}

static void rlhist_delete_oldest(Rlhist h)
{
  int i;
  if(h->size <= 0) {
    h->beg_free = h->beg;
    h->end_free = h->end;
    h->size = 0;
    return;
  }
  for(i = 0 ; i < h->size - 1 ; i++) {
    h->lines[i] = h->lines[i+1];
  }
  h->end_free = h->lines[h->size -1];
  if(h->end_free == h->beg) {
    h->end_free = h->end;
  }
  if(h->end_free <= h->beg_free) {
    h->beg_free = h->beg;
  }
}




/***************************** Rline Completion **********************/
#ifndef __TINYC__

#include <stdio.h>
#include <stdlib.h>

#ifdef x_WIN32
#include <sys/dirent.h>
#else
#include <sys/types.h>
#include <dirent.h>
#endif

#define RLCMPL_SIZE     500
#define RLCMPL_BUF_SIZE 2000

#define RLCMPL_STATE_DONE 0
#define RLCMPL_STATE_YN 1

struct rlcmpl_info {
  int size;
  char buf[RLCMPL_BUF_SIZE], *end; 
  char *words[RLCMPL_SIZE];
  Rline rline;
  int state;
};
#endif


Rlcmpl rlcmpl_init(Rline r)
{
  Rlcmpl h = NULL;
#ifndef __TINYC__
  h = malloc(sizeof(*h));
  if(h == NULL)
    ec_fatal("no memory for rlcmpl_init");
  h->size = 0; 
  h->end = h->buf + RLCMPL_BUF_SIZE;
  h->rline = r;
  h->state = RLCMPL_STATE_DONE;
#endif
  return h;
}

#ifndef __TINYC__
static int my_strcmp(const void *a, const void *b)
{
  return strcmp(*(char **)a, *(char **)b);
}

/* returns the number of completions */
static int rlcmpl_find_cmpls(Rlcmpl h, char *dir, char *file)
{
  struct dirent *entry;
  DIR *dp;
  char *p;
  char *q;
  int len, n;
  
  len = strlen(file);
  dp = opendir(dir);
  if(dp == NULL) return 0;
  h->size = 0;
  p = h->buf;
  
  while((entry = readdir(dp)) != NULL) {
    q = entry->d_name;
    if(q[0] == '.') {
      if(q[1] == 0) continue;
      if(q[1] == '.' && q[2] == 0) continue;
    }
    if(len && strncmp(q, file, len) != 0) {
            continue;
    }
    n = strlen(q);
    if(p + n + 1 >= h->end) {
      closedir(dp);
      return -1;
    }
    if(h->size >= RLCMPL_SIZE) {
      closedir(dp);
      return -1;
    }
    strcpy(p, entry->d_name);
    h->words[h->size++] = p;
    p += n;
    *p++ = 0;
  } 
  closedir(dp);
  qsort(h->words, h->size, sizeof(char *), my_strcmp);
  return h->size;
}

static void rlcmpl_quote(char *src, char *dst)
{
  char *p, *q;
  p = src;
  q = dst;
  
  while(*p) {
    switch(*p) {
    case '\'':
    case '\"':
    case '\\':
      *q++ = '\\';
      *q++ = *p++;
      break;
    default:
      *q++ = *p++;
    }
  }
  *q = 0;
}

#include <sys/stat.h>
#ifndef _WIN32
# include <unistd.h>
#endif

static void rlcmpl_add_slash(char *dir, char *file)
{
  char tmp[200];
  struct stat Sb;

  strcpy(tmp, dir);
  strcat(tmp, "/");
  strcat(tmp, file);
  if (stat(tmp, &Sb) >= 0)
    strcat(file, S_ISDIR(Sb.st_mode) ? "/" : " ");
}


/* returns 1 if done, 0 if still in dialog */
int rlcmpl_got_key(Rlcmpl h, int key) 
{
  switch(h->state) {
  case RLCMPL_STATE_YN:
    if(key == 'y' || key == 'Y') {
      rlcmpl_list_names(h);
    } else {
      te_output_char(h->rline->term, '\n');
      rline_prompt(h->rline);
      rline_redraw(h->rline);
    }
    h->state = RLCMPL_STATE_DONE;
    return 1;
  default:
    ec_fatal("bad state %d in rlcmpl_got_key(key = %d)\n", h->state, key);
    return 0;
  }
}
  
void rlcmpl_list_names(Rlcmpl h) 
{
  int i, j;
  int max;
  int cols;
  int width;
  int rows;
  int n;
  
  /* find max len */
  max = 0;
  for(i = 0 ; i < h->size ; i++) {
    n = strlen(h->words[i]);
    if(n > max) max = n;
  }
  /* len : column width */
  if(max > 38) {
    /* display in one column */
    for(i = 0 ; i < h->size ; i++) {
      te_output_char(h->rline->term, '\n');
      te_output_string(h->rline->term, h->words[i]);
    }
  } else {
    /* nr of columns */
    cols = (80 / (max + 2)) - 1;
    /* width of each column */
    width = max + 2;
    /* number of names per column */
    rows = (h->size + cols - 1) / cols;
    
    for(i = 0 ; i < rows ; i++) {
      te_output_char(h->rline->term, '\n');
      for(j = i ; j < h->size ; j += rows) {
        n = strlen(h->words[j]);
        te_output_string(h->rline->term, h->words[j]);
        if(j + rows >= h->size) continue;
        while(n++ < width) {
          te_output_char(h->rline->term, ' ');
        }
      }
    }
  }
  te_output_char(h->rline->term, '\n');
  rline_prompt(h->rline);
  rline_redraw(h->rline);
}
  
static void rlcmpl_word_to_dir_file(char *word, char *dir, char *file)
{
  char *p, *q;
  q = 0;
  for(p = word; *p; p++) {
    if(*p == '/') q = p;
  }
  if(q == 0) {
    strcpy(dir, ".");
    strcpy(file, word);
  } else {
    for(p = word; p <= q; p++) {
      *dir++ = *p;
    }
    *dir = 0;
    strcpy(file, p);
  }
}
  
/* returns 1 if done, 0 if still in dialog */
int rlcmpl_do_tab(Rlcmpl h) 
{
  /* obtain the word before the cursor */
  char word[200];
  char tmp[200];
  char qword[200];
  char dir[200];
  char file[200];
  char *p, *q, *r, *s;
  int n;
  int i, j;
  
  p = h->rline->buf;
  r = p + h->rline->pos;
  q = h->rline->buf;
  while(p < r) {
    if(*p == ' ') {
      q = p;
    } else if(*p == '\\') {
      p++;
      if(p >= r) {
        break;
      }
    } else if(*p == '\'') {
      p++;
      while(p < r) {
        if(*p == '\'') {
          break;
        }
        p++;
      }
    } else if(*p == '\"') {
      p++;
      while(p < r) {
        if(*p == '\"') {
          break;
        }
        p++;
      }
    }
    p++;
  }
  while(*q == ' ') q++;
  /* so, q is the beginning of the word, r the end of it, and we must decode
    it into word[] before searching 
  */
  
  p = q;
  s = word;
  while(p < r) {
    if(*p == '\\') {
      p++;
      if(p >= r) break;
      *s++ = *p++;
    } else if(*p == '\'') {
      p++;
      while(p < r) {
        if(*p == '\'') {
          p++;
          break;
        }
        *s++ = *p++;
      }
    } else if(*p == '\"') {
      p++;
      while(p < r) {
        if(*p == '\"') {
          p++;
          break;
        }
        *s++ = *p++;
      }
    } else {
      *s++ = *p++;
    }
  }
  *s = 0;
  /* TODO, check bounds before */
  assert(s < word + 199);
  /* now, word[] contains the parsed word. Try and complete it */
  
  rlcmpl_word_to_dir_file(word, dir, file);

#if 0
ec_stderr("dir <%s>, file <%s>\n", dir, file);
#endif  

  n = rlcmpl_find_cmpls(h, dir, file);
    
  if(n <= 0) {
    /* nothing to do. */
    return 1;
  } else if(n == 1) {
    /* the file is in h->words[0] */
    if(dir[0] != '.' && dir[1] != 0) {
      strcpy(word, dir);
      s = word + strlen(word);
    } else {
      s = word;
    }
    strcpy(s, h->words[0]);
    rlcmpl_add_slash(dir, s);
    /* quote word */
    rlcmpl_quote(word, qword);
    /* replace the word between q and r by word */
    strcpy(tmp, r);
    strcpy(q, qword);
    n = strlen(h->rline->buf);
    strcat(h->rline->buf+n, tmp);
    rline_sync_screen(h->rline);
    rline_redraw(h->rline);
    rline_goto(h->rline, n);
  } else {
    /* find the longest common part */
    int len = strlen(h->words[0]);
    for(i = 0 ; i < h->size ; i++) {
      for(j = 0 ; j < len ; j++) {
        if(h->words[i][j] != h->words[0][j]) {
          len = j;
          break;
        } 
      }
      if(len == 0) {
        break;
      }
    }
    if(len > strlen(file)) {
      /* add this part */
      if(dir[0] != '.' && dir[1] != 0) {
        strcpy(word, dir);
        s = word + strlen(word);
      } else {
        s = word;
      }
      for(i = 0 ; i < len ; i++) {
        *s++ = h->words[0][i];
      }
      *s = 0;
      rlcmpl_quote(word, qword);
      strcpy(tmp, r);
      strcpy(q, qword);
      n = strlen(h->rline->buf);
      strcat(h->rline->buf+n, tmp);
      rline_sync_screen(h->rline);
      rline_redraw(h->rline);
      rline_goto(h->rline, n);
    }
    if(1){
      /* print the file names unless they are too many */
      if(h->size > 100) {
        te_output_string(h->rline->term, "\nDisplay all ");
        sprintf(tmp, "%d possibilities ? (y or n)", h->size);
        te_output_string(h->rline->term, tmp);
        h->state = RLCMPL_STATE_YN;
        return 0;
      } else {
        rlcmpl_list_names(h);
      }
    }
  }
  h->state = RLCMPL_STATE_DONE;
  return 1;
}

#endif	/*__TINYC__*/
