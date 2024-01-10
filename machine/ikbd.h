/* 
 * ikbd.h - device-independant implementation of the IKBD protocol
 *
 * Taken from STonX (C) 1994-1997 Marinos Yannikos & Martin D. Griffiths
 * Modified for STonC (C) 1998-2002 Laurent Vogel
 * Covered by the GPL version 2 or later; see COPYING for details
 */

#ifndef IKBD_H
#define IKBD_H

/* TODO document meaning of these */

void ikbd_send(int value);
void ikbd_send_byte(char v);
void init_ikbd(void);
 
#endif /* IKBD_H */
