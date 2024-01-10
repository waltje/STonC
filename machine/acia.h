/*
 * acia.h - emulation of ATARI ST ACIA 6850
 *
 * Part of STonC (C) 1998-2002 Laurent Vogel
 * Covered by the GPL version 2 or later; see COPYING for details
 */


#ifndef ACIA_H
#define ACIA_H

struct acia;

typedef struct acia *Acia;

extern Acia ikbd_acia, midi_acia;

void acia_set_input(Acia a, int (*input_func)(void *), void *input_obj);
void acia_set_output(Acia a, void (*output_func)(void *, char), 
        void *output_obj);
int acia_null_input(void *dummy);
void acia_null_output(void *dummy, char c);
Acia acia_new(void);

unsigned char acia_get_sr(Acia a);
void acia_set_cr(Acia a, unsigned char val);
unsigned char acia_get_rdr(Acia a);
void acia_set_tdr(Acia a, unsigned char val);

void acia_notify_input(void * Acia_a);

void acias_init(void);

#endif /* ACIA_H */

