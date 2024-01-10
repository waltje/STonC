/*
 * utils.c - misc. utilities
 *
 * Part of STonC (C) 2003 Laurent Vogel
 * Covered by the GPL version 2 or later; see COPYING for details
 */

#include <stdlib.h>
#include <string.h>
#include "utils.h"
 
char * xstrdup(const char *s)
{
  int len = strlen(s) + 1;
  char *p = malloc(len);
  if (p == NULL) {
    ec_fatal("out of memory");
  }
  memmove(p, s, len);
  return p;
}

