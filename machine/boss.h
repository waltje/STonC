/*
 * boss.h : the manager of the emulator.
 *
 * Part of STonC (C) 1998-2002 Laurent Vogel
 * Covered by the GPL version 2 or later; see COPYING for details
 */
 
/* the boss owns the terminals, and calls the cpu for a while
 * and calls the ui when commands have to be interpreted.
 */

#ifndef BOSS_H
#define BOSS_H
 
#include "emulc.h"
 
/* TODO:  the interface between boss.c and ui.c is a mess */
 
extern Term serial_term;
extern Term ui_term;
extern Term screen_term;

/* the terminal that is to be shown by default when 'go'ing */
extern Term show_term;

/* prototypes */

int boss_run(void);
int boss_init(void);
void boss_halt(void);
void boss_do_cmd(void *dummy, char *p);
int boss_reinit(void);
void boss_reset(void);
void boss_stop(void);
void boss_end(void);
int boss_run(void);
void boss_event_loop(void);

/* commands */

int boss_cmd_loadtos(int argc, char **argv);

#endif /* BOSS_H */
