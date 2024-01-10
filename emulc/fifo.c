/*
 * fifo.c : a simple buffer for serial line connection between
 * a sender and a receiver.
 *
 * Copyright (C) 2000-2001 Laurent Vogel 
 * This file is part of EmulC, the Emulator on Curses library.
 *
 * This is free software covered by the GPL version 2 or later, and
 * comes with NO WARRANTY - read the file COPYING for details.  
 */
 
/*

  principle:   (first, the sender sends chars)
  __________             ______               ____________
            |   sends   |      |  notifies   |
    sender  |---------->| fifo |------------>|  receiver
  __________|           |______|             |____________  
  
                 (later, from the receiver)
                         ______               ____________
                        |      |  get char   |
                        | fifo |<------------|  receiver
                        |______|             |____________  
  
  get_char() returns the oldest char, or -1 indicating that the fifo 
  is empty. The fifo will notify the receiver when a new char is sent
  and the fifo knows that the receiver knows that the fifo was empty
  (that is, when get_char() returned -1 the last time it was called).

  usage : 
  well, This is a stupid code really, simply I didn't want to 
  duplicate this stupid code everywhere.
  Use it between : 
  - a terminal and usart;
  - ikbd and acia,
  - the midi port and acia
  ...
  
  Note : (actually the chars are ints. Any int is allowed except -1).

*/

#include <stdio.h>
#include <stdlib.h>
#include "emulc.h"   /* for assert() */
#include "fifo.h"

#define MAX_FIFO_BUF 100

struct fifo {
  int buf[MAX_FIFO_BUF] ;
  int first, last, nr ;
  void *receiver;
  void (*notify_func)(void *);
  int known_empty;
};


Fifo fifo_new(void *receiver, void (*notify_func)(void *))
{
  Fifo f = malloc(sizeof(*f));
  if(f == NULL) {
    ec_fatal("no memory fo fifo_new()");
  }
  f->first = f->last = f->nr = 0;
  f->receiver = receiver;
  f->notify_func = notify_func;
  f->known_empty = 1;
  return f;
}

void fifo_send(Fifo f, int c)
{
  assert(c != -1);
  if(f->nr >= MAX_FIFO_BUF) {
    return;
  }
  if(f->last >= MAX_FIFO_BUF) {
    f->last = 0;
  }
  f->buf[f->last++] = c;
  f->nr ++;
  if(f->known_empty) {
    /* the receiver knew we were empty, I must tell it that it is 
     * not the case any more.
     */
    f->notify_func(f->receiver);
    f->known_empty = 0;
  }
}

void fifo_send_void(void *Fifo_f, int c)
{
  fifo_send((Fifo) Fifo_f, c);
}
  
int fifo_get_char(Fifo f)
{
  int c;
  if(f->nr <= 0) {
    f->known_empty = 1;
    return -1;
  }
  if(f->first >= MAX_FIFO_BUF) {
    f->first = 0;
  }
  c = f->buf[f->first ++];
  f->nr --;
  f->known_empty = 0;
  return c;
}

int fifo_get_char_void(void *Fifo_f)
{
  return fifo_get_char((Fifo) Fifo_f);
}

