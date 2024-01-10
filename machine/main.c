/* 
 * main.c 
 *
 * Part of STonC (C) 1998-2003 Laurent Vogel
 * Covered by the GPL version 2 or later; see COPYING for details
 */


#include "defs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#include "utils.h"

#include "boss.h"
#include "ui.h"
#include "vars.h"

#include "version.h"
 
#define MAINTAINER "Laurent Vogel <lvl2@club-internet.fr>"

char *config_file = NULL;

int no_startup = 0;

static void process_args (int argc, char *argv[]);

static void usage(void)
{
  printf(
"usage: stonc [options]\n"
"Options:\n"
"  -h, --help            Display this information\n"
"  -v, --version         Print the version and exit\n"
"  -n, --no-startup      Do not read the startup file\n"
"  -f FILE, --file=FILE  Read commands from FILE\n"
"  --dump-builtins       Dump builtin strings, file names, ...\n"
"\n"
"Report bugs to " MAINTAINER ".\n"
"\n"
"Inside stonc, type help on the prompt to get more info.\n"
  );
  
  exit(1);
}

static void process_args (int argc, char *argv[])
{
  int i;
  for (i=1; i<argc; i++)
  {
    char *x = argv[i];
    if (!strcmp(x, "--version") || !strcmp(x, "-v")) {
      printf("version " VERSION "\n");
      exit(0);
    } else if(!strcmp(x, "--dump-builtins")) {
      printf(
"startup file: the first file found among (in this order):\n"
"  $STONCRC, $HOME/.stoncrc, $STONCDIR/stoncrc\n"
"$STONCDIR is set to " STONCDIR " if not already set.\n"
"MAGIC key is one of '²' or 'ý' (on a pc, the key just above TAB).\n"
      );
      exit(0);
    } else if(!strcmp(x, "-n") || !strcmp(x, "--no-startup")) {
      no_startup = 1;
    } else if(!strcmp(x, "-f")) {
      if (i == argc-1) {
        usage();
      }
      if(config_file != NULL) {
        printf("at most one command file is supported.\n");
        exit(1);
      }
      config_file = argv[i+1];
      i++;
    } else if(!strncmp("--file=", x, 7)) {
      if(config_file != NULL) {
        printf("at most one command file is supported.\n");
        exit(1);
      }
      config_file = argv[i] + 7;
    } else {
      usage();
    }
  }
}

int main (int argc, char *argv[])
{
        process_args (argc, argv);
        
        init_ui();
        boss_init();
        ui_welcome(
"This is STonC version " VERSION ", based on STonX version 0.6.7-epsilon.\n"
"STonC port (C) 1998-2004 by Laurent Vogel;\n"
"STonX (C) 1994-1997 by Marinos Yannikos and Martin D. Griffiths.\n\n"
"Report bugs to " MAINTAINER ".\n\n"
"This is free software, with NO WARRANTY! Read the file COPYING for details.\n");

  if(!defined_var("STONCDIR")) {
    set_var("STONCDIR", STONCDIR);
  }
  set_var("VERSION", VERSION);
  
  if(!no_startup) {
    char *fname;
    /* by default, load the first file found among
       $STONCRC, $HOME/.stoncrc, $STONCDIR/stoncrc
       in this order.
       $STONCDIR is set to /usr/local/share/stonc if 
       not already present in the environment.
    */
    fname = get_var("STONCRC");
    if(fname && ui_try_startup_file(fname)) {
      goto end_startup;
    }
    fname = get_var("HOME");
    if(fname != NULL) {
      fname = malloc(10 + strlen(fname));
      if(fname != NULL) {
        strcpy(fname, get_var("HOME"));
        strcat(fname, "/.stoncrc");
        if( ui_try_startup_file(fname)) {
          goto end_startup;
        }
      }
    }
    fname = get_var("STONCDIR");
    fname = malloc(10 + strlen(fname));
    if(fname != NULL) {
      strcpy(fname, get_var("STONCDIR"));
      strcat(fname, "/stoncrc");
      if( ui_try_startup_file(fname)) {
        goto end_startup;
      }
    }
    ec_stderr("Warning: no global startup file found.\n");
  }
  
  end_startup:
        if(config_file) {
                ui_config_file(config_file);
        }
        boss_event_loop();              
        boss_end();
        return 0;
}




