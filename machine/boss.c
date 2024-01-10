/*
 * boss.c - the manager of the emulator
 *
 * Part of STonC (C) 1998-2003 Laurent Vogel
 * Covered by the GPL version 2 or later; see COPYING for details
 */

/* the boss owns the terminals, and calls the cpu for a while
 * and calls the ui when commands have to be interpreted.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "emulc.h"
#include "vtime.h"
#include "rline.h"
#include "utils.h"

Term serial_term = NULL;
Term ui_term = NULL;
Term screen_term = NULL;
Term show_term = NULL;

#include "defs.h"
#include "mem.h"
#include "main.h"

#include "boss.h"

#include "io.h"
#include "fdc.h"
#include "mfp.h"
#include "hdc.h"
#include "ui.h"
#include "ikbd.h"
#include "cpu.h"
#include "stkbd.h"
#include "ocr.h"
#include "gemdos.h"
#include "nf.h"

int boot_dev=0;
int warmboot=0;
int midi = 0;

int nocart = 1;

extern char *parallel_dev;
int gr_mode = MODE_COLOR;


int boss_done = 0;

/* prototypes */

int boss_init(void);
int boss_reinit(void);
int boss_run(void);
void boss_go(void);



void kbd_check(void)
{
  ec_periodic_tasks();
}

static void boss_emulc_alarm(void * dummy)
{
  (void)dummy;

  /* here we call the emulc periodic tasks 
  *  (check the keyboard typically) 
  */  
  ec_periodic_tasks();
  set_alarm(0.02, boss_emulc_alarm, 0);
}

static void load_file (char *file, char *d)
{
  FILE *f = fopen(file, "rb");
  if (f == NULL) {
    ec_fatal( "Error: File `%s' not found!\n", file);
  }
  ec_stderr( "Loading `%s'...\n", file);
  fread(d,0x7fffffff,1,f); /* FIXME */
  fclose(f);
}

static void load_tos_file (char *file)
{
  UB buf[12];
  char *d;
  FILE *f = fopen(file, "rb");
  size_t count;
  
  if (f == NULL) {
    ec_fatal( "Error: File `%s' not found!\n", file);
  }
  fread(buf, 12, 1, f);
  fseek(f, 0, SEEK_SET);
  if(buf[9] == 0xFC) {
    tos_1 = 1;
    d = (char *)MEM(0xFC0000);
  } else {
    tos_1 = 0;
    d = (char *)MEM(0xE00000);
  }
  ec_stderr( "Loading TOS%d image `%s'...\n", 2-tos_1, file);
  count = fread(d, 1, 0x100000, f); /* FIXME */
  fclose(f);
}


/*
 * boss_init is only called from the ui when all parameters 
 * have been set. 
 * returns 0 if no problem.
 */

static char *tosfilename = "tos.img";

#if 0 /* by default, no cartridge */
static char *cartfilename = "cartridge.img";
#else
static char *cartfilename = NULL;
#endif

int emul_running = 0;

static void boss_magic_handler(int c) 
{
  switch(c) {
  case ' ':
    te_select_term(ui_term);
    boss_halt();
    break;
  case 'a':
    te_select_term(screen_term);
    break;
  case 'b':
    te_select_term(serial_term);
    break;
  case 'c':
    te_select_term(ui_term);
    break;
  default:
    break;
  }
}

static char boss_cmd_buf[200];

void boss_do_cmd(void *dummy, char *p)
{
  UNUSED(dummy);
  
  strncpy(boss_cmd_buf, p, 199);
  boss_cmd_buf[199] = 0;
  flags |= F_UI;
}

void boss_screen_redraw(void * dummy)
{
  (void) dummy;
  if(te_get_active_term() == screen_term) {
    ocr_screen_shifter();
  }
  set_alarm(0.2, boss_screen_redraw, 0);
}

Rline ui_rline;

void boss_set_gr_mode(int g)
{
  if(g == gr_mode) return;
  switch(g) {
  case MODE_NO_SCREEN:
    /* TODO */
    break;
  case MODE_COLOR:
    gr_mode = g;
    mfp_set_gpip_bit(0x80,0);
    break;
  case MODE_MONO:
    gr_mode = g;
    mfp_set_gpip_bit(0x80,0x80);
  }
}

/* Commands */

int boss_cmd_show(int argc, char **argv)
{
  char *w;
  if(argc == 1) {
    if(show_term == NULL) {
      show_term = screen_term;
    }
    te_select_term(show_term);
    return 0;
  } 
  if(argc != 2) {
    ec_stderr("usage: show {<terminal name>}\n");
    return 1;
  }
  w = argv[1];
  if(!strcmp(w, "screen")) {
    show_term = screen_term;
  } else if(!strcmp(w, "ui")) {
    show_term = ui_term;
  } else if(!strcmp(w, "serial")) {
    show_term = serial_term;
  } else {
    ec_stderr("<terminal> must be one of ui, screen, serial\n");
    return 1;
  }
  te_select_term(show_term);
  return 0;
}

int boss_cmd_screen(int argc, char **argv)
{
  if(argc != 2) {
  usage:
    ec_stderr("usage: screen mono|color|none\n");
    return 1;
  }
  if(!strcmp(argv[1],"none")) {
    boss_set_gr_mode(MODE_NO_SCREEN);
  } else if(!strcmp(argv[1],"color")) {
    boss_set_gr_mode(MODE_COLOR);
  } else if(!strcmp(argv[1],"mono")) {
    boss_set_gr_mode(MODE_MONO);
  } else {
    goto usage;
  }
  return 0;
}

int boss_cmd_exit(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  boss_done = 1;
  return 0;
}

int boss_cmd_reset(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  boss_reset();
  return 0;
}

int boss_cmd_halt(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  boss_halt();
  return 0;
}

int boss_cmd_loadtos(int argc, char **argv)
{
  if(argc != 2) {
    ec_stderr("usage: loadtos <tos image file name>\n");
    return 1;
  }
  tosfilename = xstrdup(argv[1]);
  return 0;
}

int boss_cmd_loadcart(int argc, char **argv)
{
  if(argc != 2) {
    ec_stderr("usage: loadcart <cartridge image file name>\n");
    return 1;
  }
  nocart = 0;
  cartfilename = xstrdup(argv[1]);
  return 0;
}


int boss_cmd_go(int argc, char **argv)
{
  static int boss_first_time = 1;

  UNUSED(argc);
  UNUSED(argv);
  
  if(boss_first_time) {
    if(boss_reinit()) {
      ec_stderr("emulator could not initialize itself\n");
      return 1;
    }
    boss_first_time = 0;
  }
  boss_go();
  return 0;
}

/* initialization */

void biosdisk_init(void);


int boss_init(void) 
{
  /* register commands */
  
  ui_register_command("loadtos", boss_cmd_loadtos, "TODO");
  ui_register_command("loadcart", boss_cmd_loadcart, "TODO");
  ui_register_command("go", boss_cmd_go, "TODO");
  ui_register_command("show", boss_cmd_show, "TODO");
  ui_register_command("reset", boss_cmd_reset, "TODO");
  ui_register_command("halt", boss_cmd_halt, "TODO");
  ui_register_command("quit", boss_cmd_exit, "TODO");
  ui_register_command("exit", boss_cmd_exit, "TODO");
  ui_register_command("screen", boss_cmd_screen, "TODO");

  /* initialize the terminals */
  /* TODO, move this in ui ?? */

  ec_init();
  ui_term = te_new_term();
  te_select_term(ui_term);
  ec_set_msg_term(ui_term);

  ec_block_mode();
  vt_init();
  emul_running = 0;

  ec_set_magic_handler(' ', boss_magic_handler);
  ec_set_magic_handler('a', boss_magic_handler);
  ec_set_magic_handler('b', boss_magic_handler);
  ec_set_magic_handler('c', boss_magic_handler);

  serial_term = te_new_term();
  te_set_kbd_handler(serial_term, te_ansi_key_handler, (void *)serial_term);

  /* screen and keyboard */
  
  kbd_init();
  
  screen_term = te_new_term();
/*te_set_kbd_handler(screen_term, te_ansi_key_handler, (void *)screen_term);*/
  te_set_kbd_handler(screen_term, kbd_key_handler, (void *)screen_term);


  show_term = screen_term;

  te_select_term(ui_term);
  ui_rline = rline_init(ui_term, boss_do_cmd, NULL, NULL);
  rline_set_prompt(ui_rline, "\033[1mstonc>\033[m ");
        
  hdc_init();
  init_fdc();
  biosdisk_init();
  init_gemdos();

  ocr_screen_open();
  
  set_alarm(0.02, boss_emulc_alarm, 0);
  return 0;
}

int boss_reinit(void) 
{
  flags = 0;
  if(serial_term == NULL) {
    serial_term = te_new_term();
  }
  
  set_alarm(0.2, boss_screen_redraw, 0);
  parallel_dev = NULL;
  
  mfp_init();

  init_mem();
  load_tos_file(tosfilename);
  
  if (cartfilename != NULL) {
    load_file(cartfilename, (char *)MEM(0xfa0000));
  }
  
#if 0 
  if (midi) init_midi();
#endif
  init_hardware();
  init_ikbd();
#if 0 /* parallel port */
  if (parallel_dev != NULL) init_parallel();
#endif
  nf_init();
  init_cpu();
  flags = 0;
  return 0;
}

void boss_reset(void)
{
  /* the reset button on the back, not the reset instruction that
   * resets peripherals.
   */ 
  cpu_reset();
}

void boss_stop(void)
{
  te_select_term(ui_term);
  boss_halt();
  /* TODO */
  flags |= F_UI;
}

void boss_halt(void)
{
  emul_running = 0;
  ec_block_mode();
}

void boss_go(void)
{
  boss_cmd_buf[0] = 0;
  emul_running = 1;
  ec_non_block_mode();
  te_select_term(show_term);
}

void boss_end(void)
{
  kill_hardware();
#if 0 /* MONITOR */
  kill_monitor();
#endif
#if 0
  if (parallel_dev != NULL) done_parallel();
#endif

  ec_end();
}

int boss_run(void)
{
  set_alarm(0.02, boss_emulc_alarm, 0);
 
  /* execute instructions until the cpu encounters a 
   * flag it cannot handle 
   */  
  execute_start(pc);

  clear_alarm_by_func(boss_emulc_alarm);
  return 0;
}

void boss_event_loop(void)
{
  rline_prompt(ui_rline);
  for(;;) {
    ec_periodic_tasks();
    if(emul_running) {
      vt_resume();
      boss_run();
      vt_halt();
    }
    if(flags & F_UI) {
      ui_do_command(boss_cmd_buf);
      if(! boss_done) 
        rline_prompt(ui_rline);
      flags &= ~F_UI;
    }
    if(boss_done) {
      break;
    }
  }
}



