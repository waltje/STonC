/*
 * ec_keys.c - key names
 *
 * Copyright (C) 2000-2001 Laurent Vogel 
 * This file is part of EmulC, the Emulator on Curses library.
 *
 * This is free software covered by the GPL version 2 or later, and
 * comes with NO WARRANTY - read the file COPYING for details.  
 */


#include <string.h>
#include <curses.h>
#include "emulc.h"
#include "ec_keys.h"

/* extern struct {
**   int key;
**   char *name;
** } keys[];
*/

int ec_key_from_name(char *name) 
{
  int i;

  for(i = 0 ; i < NR_KEYS ; i++) {
    if(keys[i].key != 0) {
      if(!strcmp(keys[i].name, name)) {
        return keys[i].key;
      }
    }
  }
  return 0;
}

int ec_get_key_max(void)
{
  return KEY_MAX;
}


