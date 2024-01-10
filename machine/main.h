/* 
 * main.h - some general definitions
 *
 * Taken from STonX (C) 1994-1997 Marinos Yannikos & Martin D. Griffiths
 * Modified for STonC (C) 1998-2002 Laurent Vogel
 * Covered by the GPL version 2 or later; see COPYING for details
 */

#ifndef MAIN_H
#define MAIN_H

/* still a bit unflexible, but it will have to do for now... */
#define MODE_MONO       0
#define MODE_COLOR      1
#define MODE_NO_SCREEN  2
extern int gr_mode;

extern int boot_dev;
extern int fix_screen;
extern int midi;

#endif /* MAIN_H */

