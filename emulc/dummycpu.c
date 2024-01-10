/* 
 * dummycpu.c : placeholder for testing emulc
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

static long inst_count, old_inst_count ;
int second_count;

static void my_display_char(int c);

static Term my_terminal;
extern Term tty_term;

int flags;

volatile int stupid;

#define FLAG_DONE 1
#define FLAG_KEY 2
#define FLAG_UI 4

void boss_halt(void)
{
  flags |= FLAG_UI;
}

int cpu_run(void);
int cpu_init(void);

#include "vtime.h"

static void cpu_key_alarm(void * dummy)
{
  int c;
  (void)dummy;
  /* we check that there is no key */
  c = te_get_char(my_terminal);
  if(c != -1) {
    my_display_char(c);
  }
  set_alarm(0.1, cpu_key_alarm, 0);
}

static void cpu_emulc_alarm(void * dummy)
{
  (void)dummy;

  /* here we call the emulc periodic tasks */
  ec_periodic_tasks();
  set_alarm(0.02, cpu_emulc_alarm, 0);
}

static void cpu_time_alarm(void * dummy)
{
  char buf[80];
  double rt, et;
  
  (void) dummy;
  
  vt_stats(&rt, &et);
  
  second_count ++;
  sprintf(buf, "\ntime %d (inst %ld) rt %f et %f\n", 
        second_count, inst_count, rt, et);
  old_inst_count = inst_count;
  inst_count = 0;
  te_output_string(my_terminal, buf);
  set_alarm(1.0, cpu_time_alarm, 0);
}

extern Term ui_term;

static void cpu_magic_handler(int c) 
{
  switch(c) {
  case ' ':
    te_select_term(ui_term);
    boss_halt();
    break;
  case 'a':
    te_select_term(tty_term);
    break;
  case 'b':
    te_select_term(ui_term);
    break;
  default:
    break;
  }
}

int cpu_init(void) 
{
  flags = 0;
  inst_count = 0;
  old_inst_count = 0;
  second_count = 0;
  ec_set_magic_handler(' ', cpu_magic_handler);
  ec_set_magic_handler('a', cpu_magic_handler);
  ec_set_magic_handler('b', cpu_magic_handler);
  my_terminal = tty_term;
  set_alarm(1.0, cpu_time_alarm, 0);
  set_alarm(0.1, cpu_key_alarm, 0);
  return 0;
}

static void my_display_char(int c)
{
  if((c >= 0) && (c < 32)){
    te_output_char(my_terminal,'^');
    te_output_char(my_terminal,c+'@');
  } else {
    if(c == 127){
      te_output_char(my_terminal,'^');
      te_output_char(my_terminal,'?');
    } else {
      if(c <0) {
        te_output_char(my_terminal, (c & 0x7F) + 128);
      } else {
        te_output_char(my_terminal, c);
      }
    }
  }
}
      

int cpu_run(void)
{
  int i;
  set_alarm(0.02, cpu_emulc_alarm, 0);
  while(1) {
    while(!flags) {
      /* spend some time executing the instruction */
      for(i = 0 ; i < 2 + (random() & 3) ; i++)
        stupid = i;
      inst_count ++;
      spent_cycles(2);
    }
    if(flags & FLAG_UI) {
      flags &= ~FLAG_UI;
      te_output_string(my_terminal, "halt\n");
      clear_alarm_by_func(cpu_emulc_alarm);
      return 1;
    }
  }
}


extern void kill_ui(void);
extern void ui_loop(void);
extern void init_ui(void);

int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;

  init_ui();
  cpu_init();
  
  ui_loop();
  kill_ui();

  exit(0);
  return 0;
}
 

