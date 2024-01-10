/*
 * keytest.c - a simple debug tool
 *
 * Copyright (C) 2000-2001 Laurent Vogel 
 * This file is part of EmulC, the Emulator on Curses library.
 *
 * This is free software covered by the GPL version 2 or later, and
 * comes with NO WARRANTY - read the file COPYING for details.  
 */

#ifdef PDCURSES
# define PDC_DLL_BUILD
#endif
#include <curses.h>

#include "ec_keys.h"

/* extern struct {
**   int key;
**   char *name;
** } keys[];
*/
 
int main(int argc, char **argv) 
{
  int c;
  int i;

  (void)argc;
  (void)argv;

  initscr();
  keypad(stdscr, TRUE);
  meta(stdscr, TRUE);
  scrollok(stdscr, TRUE);
  noecho();
  nonl();
  
  printw("keytest : a simple program to show key names as seen using curses\n");

  do {
    printw("key [Q to quit]> ");
    c = getch();
    if(c < 0) c = (c & 0x7F) + 128;
    if(((c >= ' ') && (c <= 126)) || ((c >= 128) && (c <= 255))) {
      addch(c);
      if(c == 'q' || c == 'Q') break;
      addch('\n');
      continue;
    }   
    printw("\n0x%x: ", c);
    if(c != 0) {
      for(i = 0 ; i < NR_KEYS ; i++) {
        if(keys[i].key == c) {
                printw("%s ",keys[i].name);     
        }
      }
    }
    addch('\n');
  } while(c != 'q');
  
  endwin();
  exit(0);
}
