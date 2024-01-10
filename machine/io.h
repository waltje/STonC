/* 
 * io.h - miscellaneous hardware devices
 *
 * Taken from STonX (C) 1994-1997 Marinos Yannikos & Martin D. Griffiths
 * Modified for STonC (C) 1998-2002 Laurent Vogel
 * Covered by the GPL version 2 or later; see COPYING for details
 */

#ifndef IO_H
#define IO_H

#include "defs.h"

extern void set_vbase(UL n);

extern void init_hardware(void);
extern void kill_hardware(void);

extern int init_parallel(void);
extern void write_parallel(unsigned char c);
extern void done_parallel(void);
extern int parallel_stat(void);

#endif /* IO_H */
