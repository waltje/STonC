/* 
 * syscalls.h - trace BIOS and GEMDOS calls
 *
 * Taken from STonX (C) 1994-1997 Marinos Yannikos & Martin D. Griffiths
 * Modified for STonC (C) 1998-2002 Laurent Vogel
 * Covered by the GPL version 2 or later; see COPYING for details
 */

#ifndef SYSCALLS_H
#define SYSCALLS_H

#define TRACE_SYSCALLS 0

extern void trace_syscall(int nex);

#endif /* SYSCALLS_H */
