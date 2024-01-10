/* 
 * iotab.h - specification of IO port memory mapping
 *
 * Part of STonC (C) 2002 Laurent Vogel
 * Covered by the GPL version 2 or later; see COPYING for details
 */

#ifndef IOTAB_H
#define IOTAB_H

#include "defs.h"
#include "iofuncs.h"

extern B (* IOTAB_funcs_LOAD[])(void);
extern void (* IOTAB_funcs_STORE[])(B);
extern UB IOTAB_flags_LOAD[0x10000];
extern UB IOTAB_flags_STORE[0x10000];

extern void init_iotab(void);

#endif /* IOTAB_H */

