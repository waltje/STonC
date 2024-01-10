/*
 * ecpriv.c : private header
 *
 * Copyright (C) 2000-2001 Laurent Vogel 
 * This file is part of EmulC, the Emulator on Curses library.
 *
 * This is free software covered by the GPL version 2 or later, and
 * comes with NO WARRANTY - read the file COPYING for details.  
 */

#ifndef _ECPRIV_H
#define _ECPRIV_H

#define KBD_BUF_SIZ 40

#include "emulc.h"
#include "ecterm.h"

struct ec_terminal {
  int row, col;
  ec_key_handler key_handler;
  void * key_handler_obj;
  te_wchar buffer[EC_ROWS * EC_COLS];
  int attr ;
  /* output buffer (optional), for serial and ikbd terminals */
  char kbd_buf[KBD_BUF_SIZ];
  int kbd_first, kbd_last, kbd_nr;
  /* escape sequence building. seq_next == 0 when not building any */
  char seq_buf[KBD_BUF_SIZ];
  int seq_index;
  int curs_visibility;
} ;

extern int ec_emul_mode;

int ts_attr_to_curses(int attr);
void ts_set_attr(Term t, int attr);
void ts_curs_set(int visibility);

void ts_move(Term t, int row, int col) ;
void ts_addchstr(Term t, void *l);
void ts_bell(Term t) ;
void ts_addch(Term t, char c) ; 
void ts_delch(Term t) ;
void ts_insch(Term t, char c) ;
void ts_deleteln(Term t) ;
void ts_insertln(Term t) ;
void ts_refresh(Term t) ;
void ts_clrtoeol(Term t) ;
void ts_redraw(Term t) ;
/* intended use = only to wait for any key pressed */
int ts_getch(void) ;

void ts_init(void);
void ts_end(void);
void ts_block_mode(void);
void ts_non_block_mode(void);

#endif /* _ECPRIV_H */
