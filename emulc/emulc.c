/*
 * emulc.c : utilites for Console mode machine emulators 
 *
 * Copyright (C) 2000-2001 Laurent Vogel 
 * This file is part of EmulC, the Emulator on Curses library.
 *
 * This is free software covered by the GPL version 2 or later, and
 * comes with NO WARRANTY - read the file COPYING for details.  
 */


#include <stdio.h>
#include <stdlib.h>
#include "emulc.h"
#include "ecpriv.h"

int ec_emul_mode = 0;

#define EC_MAX_MAGIC_HANDLERS 0777

static void (*ec_magic_handlers[EC_MAX_MAGIC_HANDLERS] )(int);

void ec_init(void)
{
  int i;
  /* initialize the console driver */
  ts_init();
  te_init();
  /* initialize the magic key bindings */
  for(i = 0 ; i < EC_MAX_MAGIC_HANDLERS ; i++) {
    ec_magic_handlers[i] = NULL;
  }
}

void ec_end(void)
{
  ts_end();
}

#define EC_BLOCK_MODE 1
#define EC_NON_BLOCK_MODE 2


void ec_block_mode(void)
{
  ec_emul_mode = EC_BLOCK_MODE;
  ts_block_mode();
}

void ec_non_block_mode(void)
{
  ec_emul_mode = EC_NON_BLOCK_MODE;
  ts_non_block_mode();
}

void ec_periodic_tasks(void)
{
  ec_check_kbd();
}

void ec_set_magic_handler(int key, void (*magic_handler)(int)) 
{
  if((key < 0) || (key >= EC_MAX_MAGIC_HANDLERS))
    return;
  ec_magic_handlers[key] = magic_handler;
}
  

#define MAGIC_KEY1 (((int)'�') & 0xFF)
#define MAGIC_KEY2 (((int)'\x1d') & 0xFF) /* ^] HO */

/*
 * key are sent through as curses gave them to us. If EmulC is ported to an
 * environment with no proper curses implementation,
 * then we will have to supply our own KEY_xxx definitions.
 */
#include <curses.h>

static int ec_pending_magic = 0;

void ec_check_kbd(void) 
{
  int c ;
  c = getch();
  
  if(c == ERR)
    return;

  if(c < 0) {
    c = (c & 127) + 128;
  }

  if(ec_pending_magic) {
    ec_pending_magic = 0;
    if((c >= 0) && (c < EC_MAX_MAGIC_HANDLERS) && (ec_magic_handlers[c])) {
      ec_magic_handlers[c](c);
      return;
    }
  }

  if((c == MAGIC_KEY1) || (c == MAGIC_KEY2)) {
    ec_pending_magic = 1;
    return;
  }
      
  te_key_received(c);
}
