/* 
 * stkbd.h - convert curses keys to atari st scancodes
 *
 * Part of STonC (C) 2000-2002 Laurent Vogel
 * Covered by the GPL version 2 or later; see COPYING for details
 */

#ifndef STKBD_H
#define STKBD_H

/*
 * commands
 */  

int do_ikbdreset(int argc, char **argv);
int do_modifier(int argc, char **argv);
int do_scancode(int argc, char **argv);
int do_bind(int argc, char **argv);

/* init the module */
int kbd_init(void);

/* key handler to be submitted for the appropriate terminal */
void kbd_key_handler(void *object, int key);


#endif /* STKBD_H */

