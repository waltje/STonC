/* 
 * ecterm.c : EmulC terminal stuff 
 *
 * Copyright (C) 2000-2001 Laurent Vogel 
 * This file is part of EmulC, the Emulator on Curses library.
 *
 * This is free software covered by the GPL version 2 or later, and
 * comes with NO WARRANTY - read the file COPYING for details.  
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
             
#include "emulc.h"
#include "ecpriv.h"
#ifdef PDCURSES
# define PDC_DLL_BUILD
#endif
#include <curses.h>

/* virtual terminal stuff */

#define EC_LOG_FILE 0

#if EC_LOG_FILE
FILE *ec_log_file = NULL;
#endif

void te_init(void)
{
  /* start the screen rendering part */
  ts_init();

#if EC_LOG_FILE
  ec_log_file = fopen("ec_log.txt", "w");
#endif
}

#define MAX_TERM_NR 20

static Term the_terms[MAX_TERM_NR];
static int last_term_nr = 0;

Term te_new_term(void) 
{
  int r, c;
  Term t = malloc(sizeof(struct ec_terminal));
  if(t == NULL) {
    ec_fatal("te_new_term : no memory");
  }
  if(last_term_nr >= MAX_TERM_NR) {
    ec_fatal("te_new_term: too many terminals");
  }
  the_terms[last_term_nr++] = t;
  t->row = 0;
  t->col = 0;

  t->key_handler = te_dummy_key_handler;
  t->key_handler_obj = NULL;

  t->attr = 0;
  t->seq_index = 0;
  for(c = 0 ; c < EC_COLS ; c++) {
    for(r = 0 ; r < EC_ROWS ; r++) {
      t->buffer[r*EC_COLS+c] = ' ';
    }
  }
  t->curs_visibility = 1;
  return t;
}

/* the active terminal (shown on the screen) */
static Term term_active = NULL;

Term te_get_active_term(void)
{
  return term_active;
}

void te_dummy_key_handler(void *dummy, int key)
{
  (void)dummy;
  (void)key;
  ec_stderr("te_dummy_key_handler(%d)\n",key);

}

void te_key_received(int key)
{
  Term t = term_active;

  (t->key_handler)(t->key_handler_obj, key);
}

void te_set_kbd_handler(Term t, ec_key_handler handler, void *obj)
{
  t->key_handler = handler;
  t->key_handler_obj = obj;
}

void te_select_term(Term t)
{
  if(t == term_active)
    return;
  term_active = t;
  ts_curs_set(t->curs_visibility);
  te_redraw(t);
}

Term te_get_term_by_nr(int n)
{
  if((n < 0) || (n >= last_term_nr)) {
    ec_fatal("te_get_term_by_nr(%d) : wrong number", n);
  }
  return the_terms[n];
}

int te_get_nr_of_terms(void)
{
  return last_term_nr;
}


void te_redraw(Term t) 
{
  ts_redraw(t);
}

void te_curs_set(Term t, int visibility)
{
  t->curs_visibility = visibility;
  if(t == term_active) 
    ts_curs_set(visibility);
}

static void print_quoted_esc(Term t);
static int check_num(Term t, int *arg1, int *arg2);
static void add_to_seq(Term t, int ch);

void te_move(Term t, int row, int col)
{
  if(row < 0) {
    row = 0;
  } else if(row >= EC_ROWS) {
    row = EC_ROWS - 1;
  } 
  if(col < 0) {
    col = 0;
  } else if(col >= EC_COLS) {
    col = EC_COLS - 1;
  } 
  t->row = row;
  t->col = col;
  ts_move(t, row, col);
}

void te_set_attr(Term t, int attr)
{
  t->attr = attr;
  ts_set_attr(t, t->attr);
}

static void print_quoted_esc(Term t)
{
  int i;
  int save_seq_index;
  int save_attr;
  char buf[100], *bufptr;
  unsigned char c;

  bufptr = buf;
  for(i = 0 ; i < t->seq_index ; i++) {
    c = t->seq_buf[i];
    if(c < 32) {
      bufptr += sprintf(bufptr, "^%c", c + 64);
    } else {
      if(c == 127) {
        bufptr += sprintf(bufptr, "^?");
      } else {
        bufptr += sprintf(bufptr, "%c", c);
      }
    }
  }
  *bufptr = 0;
  save_seq_index = t->seq_index;
  t->seq_index = 0;
  save_attr = t->attr;
  te_set_attr(t, TE_ATTR_BOLD);
  te_output_string(t, buf);
  te_set_attr(t, save_attr);
  t->seq_index = save_seq_index;
}

static int check_num(Term t, int *arg1, int *arg2)
{
  int i;
  int n;
  int *arg = arg1;
  char c;

  n = 0;
  if(t->seq_index <=2)
    return 0;
  for(i = 2 ; i < t->seq_index ; i++) {
    c = t->seq_buf[i];
    if((c >= '0') && (c <= '9')) {
      n = n*10+(c-'0');
    } else {
      if(c == ';') {
        if(arg == arg2)
          return -1;
        if(n <0) {
          ec_stderr("check_num: n = %d\n", n);
          n = 0;
        }
        *arg = n;
        n = 0;
        arg = arg2;
      } else 
        return -1;
    }
  }
  if(n <0) {
    ec_stderr("check_num: n = %d\n", n);
    n = 0;
  }
  *arg = n;
  if(arg == arg1)
    return 1;
  else 
    return 2;
}

static void add_to_seq(Term t, int ch)
{
  int arg1, arg2, argc;

  if(t->seq_index == 1) {
    switch(ch) {
    case '[':   
      t->seq_buf[t->seq_index++] = '[';
      return;
    case 'M':
      te_ins_one_line(t);
      break;
    default:
      t->seq_buf[t->seq_index++] = ch;
      print_quoted_esc(t);
      break;
    }
  } else {
  
    if(t->seq_index >= KBD_BUF_SIZ) {
      print_quoted_esc(t);
      t->seq_index = 0;
      return;
    }
        
    switch(ch) {
    case 'A':   /* UP */
      argc = check_num(t, &arg1, &arg2);
      if((argc == -1) || (argc >= 2)) {
        goto error;
      }
      if(argc == 0) 
        arg1 = 1;
      
      if(t->row > arg1)
        t->row -= arg1;
      else
        t->row = 0;
      ts_move(t, t->row, t->col);
      break;
    case 'B':   /* DOWN */
      argc = check_num(t, &arg1, &arg2);
      if((argc == -1) || (argc >= 2)) {
        goto error;
      }
      if(argc == 0) 
        arg1 = 1;
      
      if(t->row + arg1 < EC_ROWS - 1)
        t->row += arg1;
      else
        t->row = EC_ROWS-1;
      ts_move(t, t->row, t->col);
      break;
    case 'C':   /* RIGHT */
      argc = check_num(t, &arg1, &arg2);
      if((argc == -1) || (argc >= 2)) {
        goto error;
      }
      if(argc == 0) 
        arg1 = 1;
      
      if(t->col + arg1 < EC_COLS - 1)
        t->col+=arg1;
      else
        t->col = EC_COLS - 1 ;
      ts_move(t, t->row, t->col);
      break;
      
    case 'D':   /* LEFT */
      argc = check_num(t, &arg1, &arg2);
      if((argc == -1) || (argc >= 2)) {
        goto error;
      }
      if(argc == 0) 
        arg1 = 1;
                                
      if(t->col > arg1)
        t->col -= arg1;
      else
        t->col = 0;
      ts_move(t, t->row, t->col);
      break;
    case 'J':
      argc = check_num(t, &arg1, &arg2);
      if(argc) {
        if(arg1 == 0) {
          te_clrtobot(t);
        } else if(arg1 == 2) {
          t->row = 0;
          t->col = 0;
          ts_move(t, t->row, t->col);
          te_clrtobot(t);
        } else {
          goto error;
        }
      } else {
        te_clrtobot(t);
      }
      break;
    case 'K':
      if(check_num(t, &arg1, &arg2) != 0)
        goto error;
      te_clrtoeol(t);
      break;
    case 'H':
      argc = check_num(t, &arg1, &arg2);
      if(argc == 2) {
        if(arg1<=0)     arg1 = 1;
        if(arg2<=0)     arg2 = 1;
        if(arg1>EC_ROWS-1) arg1 = EC_ROWS;
        if(arg2>EC_COLS-1) arg2 = EC_COLS;
                
        t->row = arg1-1;
        t->col = arg2-1;
        ts_move(t, t->row, t->col);
      } else {
        if(argc == 0) {
          t->row = 0;
          t->col = 0;
          ts_move(t, t->row, t->col);
        } else {
          goto error;
        }
      }
      break;
    case 'P':
      argc = check_num(t, &arg1, &arg2);
      if((argc == -1) || (argc >= 2)) {
        goto error;
      }
      if(argc == 0)
        arg1 = 1;
      te_del_n_chars(t, arg1);
      break;
    case 'M':
      argc = check_num(t, &arg1, &arg2);
      if((argc == -1) || (argc >= 2)) {
        goto error;
      }
      if(argc == 0)
        arg1 = 1;
      te_del_n_lines(t, arg1);
      break;
    case 'L':
      argc = check_num(t, &arg1, &arg2);
      if((argc == -1) || (argc >= 2)) {
        goto error;
      }
      if(argc == 0)
        arg1 = 1;
      te_ins_n_lines(t, arg1);
      break;
    case '@':
      argc = check_num(t, &arg1, &arg2);
      if(argc >= 2) {
        goto error;
      }
      if(argc == 0)
        arg1 = 1;
      te_ins_n_chars(t, arg1);
      break;
    case 'm':
      argc = check_num(t, &arg1, &arg2);
      if((argc <= -1) || (argc >= 2)) {
        goto error;
      }
      if(argc == 0) {
        arg1 = 0;
      }
      switch(arg1) {
      case 0: t->attr = 0; break;
      case 1: t->attr |= TE_ATTR_BOLD; break;
      case 4: t->attr |= TE_ATTR_UC; break;
      case 7: t->attr = TE_ATTR_SO; break;
      default: goto error; 
      }
      ts_set_attr(t, t->attr);
      break;
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case ';':
      t->seq_buf[t->seq_index++] = ch;
      return;
    default:
    error:
      t->seq_buf[t->seq_index++] = ch;
      print_quoted_esc(t);
      break;
    }
  }
  t->seq_index = 0;
  ts_refresh(t);
}

void te_clear(Term t)
{
  te_move(t,0,0);
  te_clrtobot(t);
}

void te_clrtobot(Term t)
{
  int row, col, old_row, old_col;
  row = t->row;
  col = t->col;
  old_row = row;
  old_col = col;
  te_clrtoeol(t);
  while(t->row < EC_ROWS -1) {
    t->row++;
    t->col = 0;
    te_clrtoeol(t);
  }
  t->row = old_row;
  t->col = old_col;
  ts_move(t, t->row, t->col);
}

void te_clrtoeol(Term t)
{
  int row, col;
  
  row = t->row;
  col = t->col;
  while(col < EC_COLS) {
    t->buffer[row*EC_COLS+col] = ' ';
    col ++;
  }
  /* TODO erase line */
  ts_clrtoeol(t);
}

void te_del_n_chars(Term t, int n)
{
        /* not optimal, but I'm lazy */
        while(--n >= 0) {
                te_del_one_char(t);
        }
}

void te_ins_n_chars(Term t, int n)
{
        /* not optimal, but I'm lazy */
        while(--n >= 0) {
                te_ins_one_char(t);
        }
}


void te_del_one_char(Term t)
{
  int row, col;

  row = t->row;
  col = t->col;
  while(col < EC_COLS-1) {
    t->buffer[row*EC_COLS+col] = t->buffer[row*EC_COLS+col+1];
    col++;
  }
  t->buffer[row*EC_COLS+col] = ' ';
  ts_delch(t);
}

void te_ins_one_char(Term t) 
{
  int i;
  for(i = EC_COLS-1 ; i > t->col ; i--) {
    t->buffer[t->row*EC_COLS+i] = t->buffer[t->row*EC_COLS+i-1];
  }
  ts_insch(t, ' ');
}

void te_del_n_lines(Term t, int n)
{
  /* not optimal, but I'm lazy */
  while(--n >= 0) {
    te_del_one_line(t);
  }
}

void te_ins_n_lines(Term t, int n)
{
  /* not optimal, but I'm lazy */
  while(--n >= 0) {
    te_ins_one_line(t);
  }
}

/* insert one line around the cursor, and scroll what was below it 
   one line downward, loosing the last line. the cursor does not move */
void te_ins_one_line(Term t)
{
  int i;
  for(i = EC_COLS*(EC_ROWS-1) ; i > t->row*EC_COLS ; i--)
    t->buffer[i+EC_COLS] = t->buffer[i];
  for(i = 0 ; i < EC_COLS ; i++) 
    t->buffer[(t->row)*EC_COLS+i] = ' ';
  ts_insertln(t);
}


/* delete one line and scroll what was below it one line upward,
   erasing the last line */
void te_del_one_line(Term t)
{
  int i;
  t->col = 0;
  for(i = t->row*EC_COLS ; i < EC_COLS*(EC_ROWS-1) ; i++)
    t->buffer[i] = t->buffer[i+EC_COLS];
  for(i = 0 ; i < EC_COLS ; i++) 
    t->buffer[(EC_ROWS-1)*EC_COLS+i] = ' ';
  ts_deleteln(t);
}


#define ESC 27
#define TAB 9

#if EC_LOG_FILE

static char * quote(char ch)
{
  int c = ch & 0xFF;
  static char buf[10];
  if((c >= 0 && c < 32) || (c == 127) || (c >= 128 && c <= 160)) {
    if(c == '\n') {
      sprintf(buf, "\\n");
    } else if(c == '\t') {
      sprintf(buf, "\\t");
    } else {
      sprintf(buf, "\\%c%c%c",'0'+((c&0700)>>6),'0'+((c&070)>>3),'0'+(c&07));
    }
  } else {
    if((c == '\\') || (c == '\'')) {
      sprintf(buf, "\\%c", c);
    } else {
      sprintf(buf, "%c", c);
    }
  }
  return buf;
}

#endif /* EC_LOG_FILE */

void te_output_char(Term t, char c)
{
  int ch = ((int)c) & 0xFF;

#if EC_LOG_FILE
  fprintf(ec_log_file, "%s", quote(c));
  fflush(ec_log_file);
#endif /* EC_LOG_FILE */

  if(t->seq_index) {
    add_to_seq(t, ch);
    return;
  }
  switch(ch) {
  case ESC:     
#if 0
    output_string(t, "^["); 
    return;
#endif          
    t->seq_buf[t->seq_index++] = ESC;
    return;
  case TAB:
    while(t->col & 7) {
      t->buffer[t->row*EC_COLS+t->col]= ' '+t->attr;
      /* TODO add char ' '*/
      ts_addch(t, ' ');
      t->col++;
    }
    break;
  case 10:
    t->col = 0;
    t->row ++;
    /* check after break that we do not have to scroll down ... */
    break;
  case 13:
    t->col = 0;
    ts_move(t, t->row, t->col);
    ts_refresh(t);
    return;
  case 8:
    if(t->col > 0) {
      t->col --;
      ts_move(t, t->row, t->col);
    }
    ts_refresh(t);
    return;
  case 7:
    ts_bell(t);
    return;
  default:
    if(((ch >= 0) && (ch < 32)) || (ch == 127)) {
      t->seq_buf[t->seq_index++] = ch;
      print_quoted_esc(t);
      t->seq_index = 0;
      break;
    }

    t->buffer[t->row*EC_COLS+t->col] = ch+t->attr;
    ts_addch(t, ch);
    t->col++;
  }
  /* check that we did not overflow */
  if(t->col >= EC_COLS) {
    t->col = 0;
    t->row ++;
  }
  if(t->row >= EC_ROWS) {
    /* scroll up : */
    t->row = 0;
    te_del_one_line(t);
    t->row = EC_ROWS - 1;
  }
  ts_move(t, t->row, t->col);
  ts_refresh(t);
}


void te_output_string(Term t, char *s)
{
  while(*s)
    te_output_char(t, *s++);
}

void te_replace_line(Term t, int row, te_wchar *line)
{
  static chtype cline[EC_COLS];
  int i, c, attr, old_attr, save_attr, save_row, save_col;
  chtype cur_attr = 0;
  te_wchar *p = t->buffer + EC_COLS * row;
  save_row = t->row;
  save_col = t->col;
  old_attr = -1;
  save_attr = t->attr;
  for(i = 0 ; i < EC_COLS ; i++) {
    c = *p++ = *line++;
    attr = c & TE_ATTR_MASK;
    if(attr != old_attr) {
      cur_attr = ts_attr_to_curses(attr);
      old_attr = attr;
    }
    cline[i] = cur_attr + (c & 0xFF);
  }
  ts_move(t, row, 0);
  ts_addchstr(t, cline);
}

/*********************** serial input buffer *************************/

#ifndef _WIN32
#include <curses.h>
#endif

static void te_add_input_char(Term t, char c);

void te_ansi_key_handler(void * Term_t, int c)
{
  char buf[20];
  char *s;
  Term t = (Term) Term_t;

  if(c >= 0 && c < 0400) {
    buf[0] = c;
    buf[1] = 0;
    s = buf;
  } else {
    switch(c) {
    case KEY_DOWN:  s = "\033[B"; break;
    case KEY_UP:  s = "\033[A"; break;
    case KEY_LEFT:  s = "\033[D"; break;
    case KEY_RIGHT:  s = "\033[C"; break;
    case KEY_BACKSPACE:  s = "\010"; break;
    case KEY_DC:  s = "\177"; break;
#ifdef KEY_SHIFT_R   /* for PDCurses 2.4, which returns the modifiers ! */
    case KEY_SHIFT_R:
    case KEY_SHIFT_L:
    case KEY_CONTROL_R:
    case KEY_CONTROL_L:
    case KEY_ALT_R:
    case KEY_ALT_L:  return;
#endif  /* PDCUrses 2.4 returning the modifiers */
    default: 
        sprintf(buf, "\\%c%c%c%c", '0'+((c&0700)>>6), 
                '0'+((c&0070)>>3), '0'+(c&0007), 0); 
        s = buf; break;
    }
  }

  while(*s) {
    te_add_input_char(t, *s++);
  }
}

static void te_add_input_char(Term t, char c)
{
  if(t->kbd_nr >= KBD_BUF_SIZ) {
    /* buffer full, return */
    return;
  }
  if(t->kbd_last >= KBD_BUF_SIZ) 
    t->kbd_last = 0;
  t->kbd_buf[t->kbd_last++] = c;
  t->kbd_nr ++;
}

int te_get_char(Term t)
{
  int c;
  if(t->kbd_nr <= 0) {
      return -1;
  }
  if(t->kbd_first >= KBD_BUF_SIZ) 
    t->kbd_first = 0;
  c = (unsigned char) (t->kbd_buf[t->kbd_first ++]);
  t->kbd_nr --;
  return c;
}


void te_refresh(Term t) 
{
  ts_refresh(t);
}




/************************************************
 * 
 * ts_ functions : terminal screen rendering.
 *
 */

#ifndef _WIN32
#include <curses.h>
#endif

void ts_move(Term t, int row, int col) 
{
  if(t != term_active)
    return;
  move(row, col);
}

void ts_bell(Term t) 
{
  (void) t;
  beep();
}

void ts_addch(Term t, char c) 
{
  if(t != term_active)
    return;
  mvaddch(t->row, t->col, c & 0xFF);
}

void ts_delch(Term t) 
{
  if(t != term_active)
    return;
  mvdelch(t->row, t->col);
}

void ts_insch(Term t, char c) 
{
  if(t != term_active)
    return;
  mvinsch(t->row, t->col, c);
}

void ts_deleteln(Term t) 
{
  if(t != term_active)
    return;
  move(t->row, t->col);
  deleteln();
}

void ts_insertln(Term t) 
{
  if(t != term_active)
    return;
  move(t->row, t->col);
  insertln();
}

void ts_refresh(Term t) 
{
  if(t != term_active)
    return;
  refresh();
}

void ts_clrtoeol(Term t) 
{
  if(t != term_active)
    return;
  move(t->row, t->col);
  clrtoeol();
}

void ts_redraw(Term t)
{
  int row, col;
  int attr, old_attr ;
  te_wchar c;
  clear();
  old_attr = -1;
  for(row = 0; row < EC_ROWS ; row++) {
    for(col = 0; col < EC_COLS ; col++) {
      c = t->buffer[row*EC_COLS+col];
      attr = c & TE_ATTR_MASK;
      if(attr != old_attr) {
        ts_set_attr(t, attr);
        old_attr = attr;
      }
      mvaddch(row, col, t->buffer[row*EC_COLS+col] & TE_CHAR_MASK);
    }
  }
  move(t->row, t->col);
  ts_set_attr(t, t->attr);
  refresh();
}

void ts_init(void)
{
  initscr();
  if((LINES < 25) || (COLS < 80)) {
    endwin();
    ec_fatal("screen size %dx%d is too small (minimum 80x25)", LINES, COLS);
  }
  atexit(ts_end);
  raw();
  noecho();
  nonl();
  intrflush(stdscr, FALSE);
  keypad(stdscr, TRUE);
  meta(stdscr, TRUE);
  typeahead(-1);
}

void ts_end(void)
{
  endwin();
}

int ts_getch(void)
{
#ifdef KEY_SHIFT_L
  int c;
  do {
    c = getch();
  } while((c == KEY_SHIFT_L) || (c == KEY_SHIFT_R) ||
    (c == KEY_CONTROL_L) || (c == KEY_CONTROL_R) ||
    (c == KEY_ALT_L) || (c == KEY_ALT_R));
  return c;
#else
  return getch();
#endif
}


void ts_non_block_mode(void)
{
#if 0
  timeout(0);
#else
  nodelay(stdscr, TRUE);
#endif

}

void ts_block_mode(void)
{
#if 0
  timeout(-1);
#else
  nodelay(stdscr, FALSE);
#endif
}

int ts_attr_to_curses(int attr) 
{
  int cur_attr = 0;
#ifndef WIN32  /* standard */
  if(attr & TE_ATTR_BOLD) cur_attr |= A_BOLD;
  if(attr & TE_ATTR_UC)   cur_attr |= A_UNDERLINE;
  if(attr & TE_ATTR_REV)  cur_attr |= A_REVERSE;
  if(attr & TE_ATTR_SO)   cur_attr |= A_STANDOUT;
#else  /* hack for pdcurses on win32 console */
  if((attr & TE_ATTR_REV) || (attr & TE_ATTR_SO)) {
    cur_attr |= A_REVERSE;
    if(attr & TE_ATTR_BOLD) cur_attr ^= A_BLINK;
    if(attr & TE_ATTR_UC)   cur_attr ^= A_BOLD;
  } else {
    if(attr & TE_ATTR_BOLD) cur_attr ^= A_BOLD | A_BLINK;
    if(attr & TE_ATTR_UC)   cur_attr ^= A_BOLD;
  }
#endif
  return cur_attr;
}

void ts_set_attr(Term t, int attr)
{
  if(t != term_active)
    return;
  attrset(ts_attr_to_curses(attr));
}

void ts_addchstr(Term t, void *l)
{
  if(t != term_active)
    return;
#if 0
  addchstr((chtype *)l);
#else
  addchnstr((chtype *)l, 80);
#endif
}

void ts_curs_set(int visibility)
{
  curs_set(visibility);
}
 

