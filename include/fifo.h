/*
 * fifo.h - a simple buffer for serial line connection between
 * a sender and a receiver
 *
 * Part of STonC (C) 1998-2002 Laurent Vogel
 * Covered by the GPL version 2 or later; see COPYING for details
 */

#ifndef FIFO_H
#define FIFO_H

struct fifo;

typedef struct fifo *Fifo;

Fifo fifo_new(void *receiver, void (*notify_func)(void *));
void fifo_send(Fifo f, int c);
void fifo_send_void(void *Fifo_f, int c);
int fifo_get_char(Fifo f);
int fifo_get_char_void(void *Fifo_f);

#endif /* FIFO_H */
