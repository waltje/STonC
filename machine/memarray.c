/* 
 * memarray.c - 68000 memory 
 *
 * Taken from STonX (C) 1994-1997 Marinos Yannikos & Martin D. Griffiths
 * Covered by the GPL version 2 or later; see COPYING for details
 */

#include "defs.h"
#include "mem.h"

/* This is a kludge, necessary for compiling with g++. If I put this in 
 * mem.c, g++ will put it in the data segment, causing the executable's size 
 * to grow to over 16MB ... Any hints? Malloc'ing is out of the question, 
 * since it requires one additional memory access most of the time to load
 * the pointer value.
 */

B mem[MEMSIZE];

