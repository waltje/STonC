/* 
 * mem.c - the 68000 memory
 *
 * Taken from STonX (C) 1994-1997 Marinos Yannikos & Martin D. Griffiths
 * Modified for STonC (C) 1998-2002 Laurent Vogel
 * Covered by the GPL version 2 or later; see COPYING for details
 */

#define IN_MEM
#include "defs.h"
#include "mem.h"
#include "io.h"
#include <stdio.h>
#include <string.h>

extern int boot_dev, drive_bits;
extern int warmboot;
extern volatile UL vbase;
int tos_1 = 0;

void init_mem (void)
{
        memset(mem, 0, MEMSIZE);

	/* warmboot = 1; HO */
        if (warmboot) {
                SM_UL(MEM(0x420),0x752019f3);
                SM_UL(MEM(0x43a),0x237698aa);
                SM_UL(MEM(0x51a),0x5555aaaa);   /* might break older TOSes <1.02? */
#if SMALL
                SM_UB(MEM(0x424),10);
                SM_UL(MEM(0x42e),0x400000);
                SM_UL(MEM(0x436),0x3f8000);
#error "this should not happen"
#else
                SM_UB(MEM(0x424),15);
                SM_UL(MEM(0x42e),0xe00000);
                SM_UL(MEM(0x436),0xdf8000);
#endif
                SM_UL(MEM(0x4ba),16000);
        }
        boot_dev = 0;
        SM_W(ADDR(0x446), boot_dev);
        SM_W(ADDR(0x4a6), 0); /* _nflops may be different if we have FDC emul.*/
        SM_L(ADDR(0x4c2), drive_bits);

#if 0
        ec_stderr("boot_dev = %d cmdload = %d\n",boot_dev, LM_W(ADDR(0x482)));
#endif
}


