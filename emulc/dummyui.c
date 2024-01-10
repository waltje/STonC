/*
 * ui.c : user interface for EmulC.
 *
 * Copyright (C) 2000-2001 Laurent Vogel 
 * This file is part of EmulC, the Emulator on Curses library.
 *
 * This is free software covered by the GPL version 2 or later, and
 * comes with NO WARRANTY - read the file COPYING for details.  
 */

#include <stdio.h>
#include <stdlib.h>

#include "emulc.h"
#include "vtime.h"
#include "rline.h"

void kill_ui(void);
void ui_do_cmd(void *dummy, char *p);
void init_ui(void);

int cpu_run(void);
void boss_halt(void);

/*
 * ui_loop : the place where commands are read and executed.
 * 
 */

Term ui_term;
Term tty_term;

Rline ui_rline;

static int ui_exit_flag = 0;

void ui_do_cmd(void *dummy, char *p)
{
  int n;
  (void) dummy;

  n = strlen(p)-1;
        
  while((n >= 0) && (p[n] == ' ')) {
    p[n] = 0;
    n--;
  }
  n ++;
                
  if((!strcmp(p, "exit")) || (!strcmp(p, "quit"))) {
    ui_exit_flag = 1;
    boss_halt();
    return;
  }
  if(!strcmp(p, "fatal")) {
    ec_fatal("essai");
  }
  if(!strcmp(p, "assert")) {
    assert(0);
  }
  if(!strcmp(p, "attr")) {
    te_output_string(ui_term, "\033[mnormal\n");
    te_output_string(ui_term, "\033[1mbold\033[m\n");
    te_output_string(ui_term, "\033[4munderline\033[m\n");
    te_output_string(ui_term, "\033[1m\033[4mbold underline\033[m\n");
    te_output_string(ui_term, "\033[7mreverse\033[m\n");
    te_output_string(ui_term, "\033[7m\033[1mreverse bold\033[m\n");
    te_output_string(ui_term, "\033[7m\033[4mreverse underline\033[m\n");
    te_output_string(ui_term, "\033[7m\033[1m\033[4mreverse bold underline\033[m\n");
  }
  if((p[0] == 'e') && (p[1] == 'c') && 
     (p[2] == 'h') && (p[3] == 'o') && 
     (p[4] == ' ')) {
    te_output_string(ui_term, p+5);
    te_output_char(ui_term, '\n');
  }
  if(!strcmp(p, "go")) {

    ec_non_block_mode();
    te_select_term(tty_term);
    vt_resume();
    cpu_run();
    vt_halt();
    te_select_term(ui_term);
        
    ec_block_mode();
    if(ui_exit_flag){
      ec_end();
      exit(0);
    }
           
  }
  free(p);
}



/*
 * init_ui : initialize the user interface AND the machine.
 */
 
void init_ui(void)
{
  /* initialize the virtual terminal environment */
  
  ec_init();
  ui_term = te_new_term();
  tty_term = te_new_term();
  te_set_kbd_handler(tty_term, te_ansi_key_handler, (void *)tty_term);
  te_select_term(ui_term);
  ui_rline = rline_init(ui_term, ui_do_cmd, NULL, NULL);
  rline_set_prompt(ui_rline, "dummy> ");
  rline_prompt(ui_rline);
  ec_block_mode();
  vt_init();
}

void kill_ui(void)
{
        ec_end();
}

void ui_loop(void)
{
  while(!ui_exit_flag) {
    ec_periodic_tasks();
  }
}

/*
 *void output_char(char c) 
 *{
 *  te_output_char(ui_term, c);
 *}
 */

/*
 *int kbd_getch(void)
 *{
 *  int c = te_get_char(ui_term);
 *  if(c == -1) {
 *    ec_fatal("c == -1");
 *  }
 *  return c;
 *}
 */


