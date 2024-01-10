/* 
 * fdc.h - FDC emulation
 *
 * Taken from STonX (C) 1994-1997 Marinos Yannikos & Martin D. Griffiths
 * Modified for STonC (C) 1998-2002 Laurent Vogel
 * Covered by the GPL version 2 or later; see COPYING for details
 */

#ifndef FDC_H
#define FDC_H

extern void init_fdc(void);
extern int fdc_add_drive(int d, char *fname);
extern void fdc_eject_drive(int d);

extern int drive_bits;

extern int fdc_cmd_disk(int argc, char **argv);
extern int fdc_cmd_eject(int argc, char **argv);

#endif /* FDC_H */
