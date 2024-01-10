/* 
 * native.h - native implementation of some TOS stuff
 *
 * Taken from STonX (C) 1994-1997 Marinos Yannikos & Martin D. Griffiths
 * Modified for STonC (C) 1998-2002 Laurent Vogel
 * Covered by the GPL version 2 or later; see COPYING for details
 */

#ifndef NATIVE_H
#define NATIVE_H

#include "defs.h"

extern int add_drive (char drive, char *fname);
extern void call_native (UL as, UL func);
extern int Bios(void);
extern void disk_init(void);

#endif /* NATIVE_H */
