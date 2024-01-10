/*
 * hdc.h - emulation of hard disk and other devices on the DMA bus.
 *
 * Part of STonC (C) 1998-2002 Laurent Vogel
 * Covered by the GPL version 2 or later; see COPYING for details
 */

#ifndef HDC_H
#define HDC_H
 
#include "defs.h"
 
/*
 * read-only variables 
 */
 
/* the status returned through the DMA bus */ 
extern B hdc_status;

/* a flag indicating that hdc is busy */
extern int hdc_busy; 

/*
 *public prototypes
 */

/* called from hdc_init() */
void hdc_reset(void);

/* called by the boss */
void hdc_init(void);

/* called by io.c when a byte is sent to the DMA bus */
void hdc_send(B v);

/* interface to add and remove clients */

#define HDC_TYPE_HD 1
#define HDC_TYPE_TAPE 2

int hdc_add_drive(int type, int contr, int dev, char *fname);
int hdc_remove_client(int contr, int dev);

/* 
 * commands
 */

int hdc_cmd_hd(int argc, char **argv);
int hdc_cmd_tape(int argc, char **argv);

#endif /* HDC_H */

