/* 
 * profile.h - used to profile 68k code
 *
 * Part of STonC (C) 1998-2002 Laurent Vogel
 * Covered by the GPL version 2 or later; see COPYING for details
 */

#include "defs.h"

#if PROF68K
 
extern volatile L prof_low;
extern volatile L prof_high;
extern volatile L prof_buf;
extern volatile W prof_res;

extern void prof_api(UL param);

#define prof_check()                                                 \
  if(prof_low != 0L)                                                 \
    if((pc > prof_low) && (pc < prof_high)) {                        \
      long addr = prof_buf + (((pc - prof_low) >> prof_res) << 2) ;  \
      SM_L(ADDR(addr), LM_L(ADDR(addr))+1);                          \
    }                                                                \

#else
    
#define prof_check()
    
#endif

