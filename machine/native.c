/* 
 * native.c - native implementation of some TOS stuff
 *
 * Taken from STonX (C) 1994-1997 Marinos Yannikos & Martin D. Griffiths
 * Modified for STonC (C) 1998-2002 Laurent Vogel
 * Covered by the GPL version 2 or later; see COPYING for details
 */


#include "mem.h"
#include "defs.h"
#include <stdio.h>
#include <stdlib.h>
#include "native.h"
#include "utils.h"
#include "gemdos.h"

#include "profile.h"

/* from biosdisk.c */
extern int bios_disk_rw(char *as);
extern int bios_disk_bpb(int dev);
extern void bios_disk_init(void);
extern void bios_Initialize(void);

extern void ex_linea(void);

/* Print string from emulated side */
void write_native(char * addr)
{
    char buf[1024];
    int n;

    for(n=0;n<1023;n++) {       /* Fill string char by char */
        if ((buf[n]=LM_UB(MEM(addr++))) == 0) break;
    }
    buf[1023] = 0;
    ec_stderr("%s", buf );
}

void call_native(UL as, UL func)
{
#if 0
        ec_stderr("Calling native %d\n",func);
#endif
        switch (func)
        {
        case 0:
                /* Get the address, where string begins*/
                write_native((char *)LM_UL(MEM(as)));
                break;
        case 1:
                bios_disk_rw((char *)MEM(as));
                break;
        case 2:
                bios_disk_bpb(LM_W(MEM(as)));
                break;
        case 3:
                bios_disk_init();
                break;
        case 4:
                /* was move_native */
                break;
        case 5:
          Gemdos(as); 
                break;
        case 6:
          /* was vdi_post(); */
                break;
        case 7:
                /* was linea_post */
                break;
        case 8:
                /* was Vdi */
                break;
        case 9:
                bios_Initialize();
                break;
        case 10:
          /* was Init_Linea(); */
                break;
        case 11:
                /* gemdos_post(); */
                break;
        case 12:
#if PROF68k
          prof_api(LM_L(MEM(as)));
                break;
#endif
        default:
          pc -= 6;
#if DEBUG
                ec_stderr("native function #%d out of range (pc=%lx)\n", func, pc);
                {
                  int i;
                  for(i = pc - 10 ; i < pc+10 ; i+=2) {
                    ec_stderr("%8.8lx: dc.w 0x%4.4x\n", i, LM_UW(MEM(i)));
                  }
                }
#endif
                ex_linea();
        }
}




