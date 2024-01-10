/* 
 * profile.c - used to profile 68k code
 *
 * Part of STonC (C) 1998-2002 Laurent Vogel
 * Covered by the GPL version 2 or later; see COPYING for details
 */

#include "defs.h"
#include "mem.h"
#include "profile.h"
 
#include "utils.h"

#if PROF68k

L prof_low = 0;
L prof_high;
L prof_buf;
W prof_res;

void prof_api(UL param)
{
  /* read parameters */
  /* prof_start is called from within the ST by calling:
     struct param {
       L low;
       L high;
       L buf;
       W res;
     } p;
     lea.l p,a0
     move.l a0,-(sp)
     dc.w $a0ff
     dc.l 12
  */
  ec_stderr("prof_api(%08lx)\n", (unsigned long)param);
  if(param == 0L) {
    prof_low = 0;
    prof_high = 0;
    prof_buf = 0;
    prof_res = 0;
  } else {
    prof_low = LM_L(ADDR(param));
    prof_high = LM_L(ADDR(param+4));
    prof_buf = LM_L(ADDR(param+8));
    prof_res = LM_W(ADDR(param+12));
  }
}

#endif
