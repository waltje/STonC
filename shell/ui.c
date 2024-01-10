/*
 * ui.c - user interface for STonC
 *
 * Part of STonC (C) 2000-2003 Laurent Vogel
 * Covered by the GPL version 2 or later; see COPYING for details
 */

#include <stdio.h>
#include <stdlib.h>
#ifndef _WIN32
# include <unistd.h>  /* for chdir */
#endif
#include <string.h>

#include "utils.h"
 
#include "emulc.h"
#include "vtime.h"

#include "hash.h"
#include "ui.h"
#include "vars.h"
 
extern char *readline(void);
extern void add_history(void);

/*
 * ui_loop : the place where commands are read and executed.
 */

static Hash ui_commands = NULL;
static Hash ui_help_pages = NULL;

extern Term ui_term;

static void ui_parse_command(char *p);

static int ui_argc;
static char *ui_argv[64];
static char ui_argv_buf[2000];
static char ui_var_name[80];

static int expand_var(char **pp, char **qq, char *qmax)
{
  char *p = *pp;
  char *q = *qq;
  char *r = ui_var_name;
  char *rmax = ui_var_name + 80;
  char *s;
  p++;
  if(*p == '{') {
    p++;
    for(;;) {
      if(*p == 0) {
        ec_stderr("unterminated ${...} variable name\n");
        return 1;
      }
      if(*p == '}') {
        p++;
        goto name_end;
      }
      *r++ = *p++;
      if(r >= rmax) {
        ec_stderr("too long variable name\n");
        return 1;
      }
    }
  } else if(*p == '_' || (*p>='a' && *p<='z') || (*p>='A' && *p<='Z')) {
    for(;;) {
      if(*p == '_' || (*p>='a' && *p<='z') || (*p>='A' && *p<='Z') ||
          (*p>='0' && *p<='9')) {
        *r++ = *p++;
        if(r >= rmax) {
          ec_stderr("too long variable name\n");
          return 1;
        }
      } else {
        goto name_end;
      }
    }
  } else {
    if(*p != 0) {
      *r++ = *p++;
    }
  }
name_end:
  *r = 0;
  if(ui_var_name == r) {
    ec_stderr("null variable name\n");
    return 1;
  }
  s = get_var(ui_var_name);
  if(s == NULL) {
    /* no value */
    *pp = p;
    return 0;
  }
  r = s;
  for(;;) {
    if(*r == 0) {
      break;
    }
    *q++ = *r++;
    if(q >= qmax) {
      ec_stderr("ui_argv_buf overflow\n");
      return 1;
    }
  }
  *pp = p;
  *qq = q;
  return 0;
} 
    
static void ui_parse_command(char *p)
{
  char *q = ui_argv_buf;
  char *qmax = ui_argv_buf+2000;

  /* parse command into words */
  ui_argc = 0;
  for(;;) {
    while((*p == ' ') || (*p == '\t')) {
      p++;
    }
    if((*p == '#') || (*p == 0)) break;
    /* begin new word */
    ui_argv[ui_argc++] = q;
    for(;;) {
      if(*p == '\'') {
        p++;
        for(;;) {
          if(*p == 0) {
            ec_stderr("unterminated simple quote\n");
            ui_argc = 0;
            return;
          }
          if(*p == '\'') {
            p++;
            break;
          }
          *q++ = *p++;
          if(q >= qmax) {
            ec_stderr("ui_argv_buf overflow\n");
            ui_argc = 0;
            return;
          }
        }
        continue;
      }
      if(*p == '"') {
        p++;
        for(;;) {
          if(*p == 0) {
            ec_stderr("unterminated double quote\n");
            ui_argc = 0;
            return;
          }
          if(*p == '"') {
            p++;
            break;
          }
          if(*p == '\\') {
            p++;
            if(*p == 0) {
              ec_stderr("unterminated backslash escape\n");
              ui_argc = 0;
              return;   
            }
            if(*p == 'n') {
              *p = '\n';
            }
            *q++ = *p++;
            if(q >= qmax) {
              ec_stderr("ui_argv_buf overflow\n");
              ui_argc = 0;
              return;
            }
            continue;
          }
          if(*p == '$') {
            if(expand_var(&p, &q, qmax)) {
              ui_argc = 0;
              return;
            }
            continue;
          }
          *q++ = *p++;
          if(q >= qmax) {
            ec_stderr("ui_argv_buf overflow\n");
            ui_argc = 0;
            return;
          }
        }
        continue;
      }
      if(*p == '\\') {
        p++;
        if(*p == 0) {
          ec_stderr("unterminated backslash escape\n");
            ui_argc = 0;
          return;       
        }
        if(*p == 'n') {
          *p = '\n';
        }
        *q++ = *p++;
        if(q >= qmax) {
          ec_stderr("ui_argv_buf overflow\n");
          ui_argc = 0;
          return;
        }
        continue;
      }
      if((*p == ' ') || (*p == '\t') || (*p == 0)) {
        *q++ = 0;
        q++;
        if(q >= qmax) {
          ec_stderr("ui_argv_buf overflow\n");
          ui_argc = 0;
          return;
        }
        break;
      }
      if(*p == '$') {
        if(expand_var(&p, &q, qmax)) {
          ui_argc = 0;
          return;
        }
        continue;
      }
      *q++ = *p++;
      if(q >= qmax) {
        ec_stderr("ui_argv_buf overflow\n");
        ui_argc = 0;
        return;
      }
    }
  }
}

static void ui_quote(char *);

void ui_register_command(char *cmd, int (*func)(int,char**), char *help)
{
  /*
  ** ec_stderr("ui_register_command(\"%s\")\n", cmd);
  */

  if(ui_commands != NULL) {
    HashInsert(ui_commands, cmd, (void *)func);
    {
      void *f = HashLookup(ui_commands, cmd);
      if((int(*)(int,char**))f != func) {
        ec_stderr("command \"%s\" not in hash\n", cmd);
      }
      if(f == NULL) {
        ec_stderr("command \"%s\" has NULL function\n", cmd);
      }
    }
  } else {
    ec_fatal("ui_commands NULL when registering\n");
  }
  if(ui_help_pages != NULL) {
    HashInsert(ui_help_pages, cmd, (void *)help);
  } else {
    ec_fatal("ui_help_pages NULL when registering\n");
  }
}

void ui_register_help(char *topic, char *help)
{
  if(ui_help_pages != NULL) {
    HashInsert(ui_help_pages, topic, (void *)help);
  } else {
    ec_fatal("ui_help_pages NULL when registering\n");
  }
}

static void ui_show_hash_elem(char *w, void *o)
{
  ec_stderr("key \"%s\" : value 0x%08lx\n", w, (long)o);
}

void ui_test_hashes(void)
{
  HashForeach(ui_commands, ui_show_hash_elem);

}

static void ui_quote(char *w) 
{
  int c;
  ec_stderr("ui_quote : \"");
  while(*w) {
    c= *w++;
    if(c < 32 || c > 127) {
      ec_stderr("\\%c%c%c", ((c & 0700)>> 6) + '0', 
                ((c & 070) >> 3) + '0', 
                (c & 7) + '0');
    } else if (c == '\\' || c == '"') {
      ec_stderr("\\%c", c); 
    } else {
      ec_stderr("%c", c);
    }
  }
  ec_stderr("\"\n");
}

static void ui_show_topic(char *val, void *o)
{
  (void)o;
  ec_stderr("  %s\n", val);
}

void ui_cmd_help(int argc, char **argv)
{
  if(argc != 2) {
    ec_stderr("type help <page> to get more help on a command or a topic. Pages are :\n");
    HashForeach(ui_help_pages, ui_show_topic);
    /* TODO, display in columns, using a pager */
    return;
  } else {
    char *h = (char *) HashLookup(ui_help_pages, argv[1]);
    if(h == NULL) {
      ec_stderr("no help on topic \"%s\"\n", argv[1]);
    } else {
      /* TODO, pager */
      ec_stderr("%s\n\n",h);
    }
  } 
}

int ui_cmd_log(int argc, char **argv)
{
  if(argc == 2) {
    if(!strcmp("none", argv[1])) {
      ec_set_log_style(LOGNONE, NULL);
    } else if(!strcmp("stderr", argv[1])) {
      ec_set_log_style(LOGSTDERR, NULL);
    } else {
      goto fail;
    }
  } else if(argc == 3) {
    if(!strcmp("file", argv[1])) {
      ec_set_log_style(LOGFILE, argv[2]);
    } else if(!strcmp("both", argv[1])) {
      ec_set_log_style(LOGBOTH, argv[2]);
    } else {
      goto fail;
    }
  } else {
    goto fail;
  }
  return 0;
fail:
  ec_stderr("usage: log none, log stderr, log file <filename>, log both <filename>\n");
  return 1;
}

int ui_cmd_cd(int argc, char **argv)
{
  if(argc != 2) {
    ec_stderr("usage: cd <directory>\n");
    return 1;
  }
  chdir(argv[1]);
  return 0;
}

int ui_cmd_ls(int argc, char **argv)
{
  /* TODO, re-use rline completion */
  UNUSED(argc);
  UNUSED(argv);
  return 0;
}


int check_equal(char *w)
{
  char *a;

  a = w;
  if( (*a != '_') 
      && !((*a >= 'a') && (*a <= 'z')) 
      && !((*a >= 'A') && (*a <= 'Z'))) {
    return 0;
  }
  a++;  
  while(*a) {
    if(*a == '=') {
      *a++ = 0;
      if(ui_argc > 1) {
        ec_stderr("syntax: <variable>=<value>\n");
        return 0;
      }
      set_var(w, a);
      return 1;
    } 
    if( (*a != '_') 
        && !((*a >= 'a') && (*a <= 'z')) 
        && !((*a >= '0') && (*a <= '9')) 
        && !((*a >= 'A') && (*a <= 'Z'))) {
      return 0;
    }
    a++;
  }
  return 0;
}

void ui_do_command(char *p)
{
  char *w;
  ui_parse_command(p);
  if(ui_argc == 0)
    return;
  w = ui_argv[0];

  if(check_equal(w)) {
    return;
  }

  if(ui_commands != NULL) {
    void *func = HashLookup(ui_commands, w);
    if(func != NULL) {
      ((int(*)(int,char**))func)(ui_argc,ui_argv);
      return;
     }
  } else {
    ec_fatal("ui_commands NULL\n");
  }

/* some builtins - should be cleaned up a little bit */
  if(!strcmp(w, "hashes")) {
    ui_test_hashes();
  } else if(!strcmp(w, "assert")) {
    assert(0);
  } else if(!strcmp(w, "fatal")) {
    ec_fatal("fatal");
  } else if(!strcmp(w, "help")) {
    ui_cmd_help(ui_argc, ui_argv);
  } else if(!strcmp(w, "set")) {
    if(ui_argc != 3) {
      ec_stderr("usage: set <variable> <value>\n");
      return;
    }
    set_var(ui_argv[1], ui_argv[2]);
  } else if(!strcmp(w, "unset")) {
    if(ui_argc != 2) {
      ec_stderr("usage: unset <variable>\n");
      return;
    }
    unset_var(ui_argv[1]);
  } else if((!strcmp(w, ".")) || (!strcmp(w, "include"))) {
    if(ui_argc != 2) {
      ec_stderr("usage: %s <file>\n", w);
      return;
    }
    ui_config_file(ui_argv[1]);
  } else if(!strcmp(w, "attr")) {
    te_output_string(ui_term, "\033[mnormal\n");
    te_output_string(ui_term, "\033[1mbold\033[m\n");
    te_output_string(ui_term, "\033[4munderline\033[m\n");
    te_output_string(ui_term, "\033[1m\033[4mbold underline\033[m\n");
    te_output_string(ui_term, "\033[7mreverse\033[m\n");
    te_output_string(ui_term, "\033[7m\033[1mreverse bold\033[m\n");
    te_output_string(ui_term, "\033[7m\033[4mreverse underline\033[m\n");
    te_output_string(ui_term, "\033[7m\033[1m\033[4mreverse bold underline\033[m\n");
  } else if(!strcmp(w, "echo")) {
    int i;
    for(i = 1 ; i < ui_argc ; i++) {
      if(i != 1) {
        te_output_char(ui_term, ' ');
      }
      te_output_string(ui_term, ui_argv[i]);
    }
    te_output_string(ui_term, "\n");
  } else {
    ec_stderr("unknown command : \"%s\"\n", w);
  }
}
  

 
static void do_config_file(FILE *f)
{
  char buf[200], *p;
  int at_eof = 0;
  for(;;) {
#if 0
    p = fgets(buf, 200, f);
#else
    {
      char *q = buf;
      int i = 200;
      int c;
      for(i = 0 ; i < 199 ; i++) {
        c = getc(f);
        if(c == EOF) {
          at_eof = 1;
          *q = 0;
          break;
        }
        if((c == 10) || (c == 13)) {
          *q = 0;
          break;
        }
        *q++ = c;
      }
      *q = 0;
      p = buf;
      if(q == p)
        p = NULL;
    }
#endif
    if(p == NULL) {
      if(at_eof) break;
      continue;
    }
    while((*p == ' ') || (*p == '\t')) {
      p++;
    }
    if(*p == '#') continue;
    ui_do_command(p);
  }
}

void ui_config_file(char *fname)
{
  FILE *f ;
  f = fopen(fname, "r");
  if(f == NULL) {
    ec_stderr("cannot open file %s\n", fname);
    return;
  }
  do_config_file(f);
  fclose(f);
}

int ui_try_startup_file(char *fname)
{
  FILE *f ;
  f = fopen(fname, "r");
  if(f == NULL) {
    return 0;
  }
  ec_stderr("reading startup file %s\n", fname);
  do_config_file(f);
  fclose(f);
  return 1;
}

/*
 * init_ui : initialize the user interface AND the machine.
 */
 
void init_ui(void)
{
        /* initialize the virtual terminal environment */
#if 0
  ec_stderr("init_ui()\n");
#endif
  ui_commands = HashNew(50);
  if(ui_commands == NULL) {
    ec_fatal("could not allocate ui_commands hash\n"); 
    return;
  }
  ui_help_pages = HashNew(50);
  if(ui_help_pages == NULL)  {
    ec_fatal("could not allocate ui_help_pages hash\n"); 
    return;
  }
  ui_register_command("log", ui_cmd_log, 
    "sets the file to which all error messages get logged (default none)");
  ui_register_command("cd", ui_cmd_cd, 
    "change working directory");
  ui_register_command("ls", ui_cmd_ls, 
    "list files");
  ui_register_command("dir", ui_cmd_ls, 
    "list files");
  var_init();
  
}

void kill_ui(void)
{

}

void ui_welcome(char *msg)
{
  /*  te_output_string(ui_term, "\033[H\033[J"); */
  te_output_string(ui_term, msg);
}


