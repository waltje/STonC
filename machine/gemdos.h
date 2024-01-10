/* 
 * gemdos.h - native gemdos drives
 *
 * Taken from STonX (C) 1994-1997 Marinos Yannikos & Martin D. Griffiths
 * Modified for STonC (C) 1998-2002 Laurent Vogel
 * Covered by the GPL version 2 or later; see COPYING for details
 */

#ifndef GEMDOS_H
#define GEMDOS_H

#include "defs.h"
#include <limits.h>

#ifndef PATH_MAX
#define PATH_MAX 1024
#endif

#define MAXDRIVES 26

extern int redirect_cconws;
extern int drive_bits;

#define SYSBASE() LM_UL(MEM(0x4f2))
#define OS_BEG()  LM_UL(MEM(8+SYSBASE()))
#define TOS_VERSION(os_beg) LM_UW(MEM((os_beg)+2))

extern void Gemdos(UL as);
extern int Bios(void);
extern int disk_bpb(int dev);
extern int disk_rw(char *args);
extern void gemdos_post(void);
extern void init_gemdos(void);
extern void bios_disk_init(void);
extern void gemdos_first_time(void);
extern int add_gemdos_drive (char d, char *path);
extern int add_drive (char drive, char *fname);
extern UL get_bp(void);

#endif /* GEMDOS_H */

