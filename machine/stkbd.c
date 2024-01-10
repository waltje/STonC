/* 
 * stkbd.c - convert curses keys to atari st scancodes
 *
 * Part of STonC (C) 2000-2002 Laurent Vogel
 * Covered by the GPL version 2 or later; see COPYING for details
 */

#include <stdio.h>
#include <stdlib.h>

#include "utils.h"


/* this file converts ec_keys (coming froom curses typically) into 
 * scancodes. 
 * ec_keys have a name and an integer value that is returned by:
 * int ec_key_from_name(char *name)
 * This conversion is declared via functions do_modifier(), do_scancode()
 * do_reset() and do_bind().
 * Then the keyboard, when it receives keys from the terminal, converts 
 * them and gives them to ikbd.c
 */

#include "stkbd.h"
#include "emulc.h"
#include "hash.h"
#include "ikbd.h"   /* for ikbd_send() */


/* number of modifiers */
static int modif_number ;
/* if this capital letter is a modifier, give its number (0-9), else -1 */
static int is_modifier[26] ;
/* the scancode of the modifier */
static int modif_scan[10];
/* the key combinations, that is the modifiers in bits 16 to 25, and the key 
   itself in the lower bits */
static int *key_comb;

static Hash key_names;

static int key_number = 0;

static int inited = 0;

int kbd_init(void)
{
  /* ec_stderr("kbd_init()\n"); */
  key_number = ec_get_key_max();
  if(key_number <= 0) {
    ec_stderr("kbd_init(): key_number %d <= 0\n", key_number);
    return 1;
  }
  key_comb = malloc(key_number * sizeof(int));
  if(key_comb == NULL) {
    ec_fatal("kbd_init(): could not allocate key_comb.\n");
    return 1;
  }
  key_names = HashNew(30);
  if(key_names == NULL){
    ec_fatal("kbd_init(): could not allocate key_names.\n");
    return 1;
  } 
  inited = 1;
  do_ikbdreset(0,0);

  ui_register_command("modifier", do_modifier, 
"modifier <UCLetter> 0x<hex code>\n"
"defines a modifier key such as (S)hift, (C)ontrol, (A)lt, with its scancode\n"
"This modifier can the be used in the <key combination>s of the commands\n"
"scancode and bind for fully defining a keyboard layout. see also:\n"
"scancode, ikbdreset, bind\n");
  ui_register_command("ikbdreset", do_ikbdreset, 
"Clears the entire definition of the keyboard layout, preferrably prior\n"
"to redefining a new one using the following commands. see also:\n"
"scancode, modifier, bind\n");
  ui_register_command("scancode", do_scancode,
"scancode <char or st key name> <key combination>\n"
"Defines for a char or an 'st' key name, defines the combination of\n"
"scancodes that will be sent by the emulated intelligent keyboard ikbd.\n"
"The st key name here is any name having more than one char.\n"
"See the file uskbd.txt for an example. see also:\n"
"ikbdreset, modifier, bind\n");
  ui_register_command("bind", do_bind,
"bind <char or Curses key name> <key combination>\n"
"similar to scancode but maps the real keyboard events to emulated key\n"
"combinations. See the file uskbd.txt for an example. see also:\n"
"ikbdreset, modifier, scancode\n");

  return 0;
}

int do_ikbdreset(int argc, char **argv)
{
  int i;  
  (void)argc;
  (void)argv;

  if(!inited) {
    ec_stderr("ikbd not inited\n");
    return 1;
  }
  for(i = 0 ; i < key_number ; i++) {
    key_comb[i] = 0;
  }
  for(i = 0 ; i < 26 ; i++) {
    is_modifier[i] = -1;
  }
  modif_number = 0;
  /* TODO, reset the hash */
  return 0;
}


int do_modifier(int argc, char **argv)
{
  /* syntax: modifier S 0x43 */
  unsigned int i,j;

  if(argc != 3) goto usage;
  if(argv[1][1] != 0) goto usage;
  i = argv[1][0];
  if(i < 'A' || i > 'Z') goto usage;
  i -= 'A';
  if(is_modifier[i] != -1) {
    ec_stderr("modifier '%c' already declared\n", i+'A');
    return 1;
  }
  if(modif_number >= 10) {
    ec_stderr("to many modifiers\n");
    return 1;
  }
  if(argv[2][0] != '0' && argv[2][1] != 'x') goto usage;
  j = 0;
  sscanf(argv[2]+2,"%x",&j);
  if(j == 0) goto usage;

  modif_scan[modif_number] = j;
  is_modifier[i] = modif_number;
  modif_number++;  
  return 0;

usage:
  ec_stderr("usage: modifier <capital letter> 0x<hex number>\n");
  return 1;
}

static int parse_key_comb(char *spec, int *pcomb)
{
  unsigned int j;
  int comb = 0;
  char *a = spec;
  while(*a >= 'A' && *a <= 'Z') {
    if((is_modifier[*a - 'A'] >= 0) && (a[1] == '-')) {
      comb = 0x10000 << is_modifier[*a - 'A'];
      a += 2;
    } else {
      ec_stderr("char '%c' i not a dclared modifier\n", *a);
      return 1;
    }
  }
  if(*a == '0' && a[1] == 'x') {
    j = 0;
    sscanf(a+2,"%x",&j);
    if(j <= 0 || j >= 127) {
      ec_stderr("value \"%s\" is not a valid hex number scancode\n", a);
      return 1;
    }
    comb += j;
  } else if(a[1] == 0) {
    j = *a;
    if(j <= 0 || j >= 127) {
      ec_stderr("key combination '%c' out of bounds\n", j);
      return 1;
    }
    j = key_comb[j];
    if(j == 0) {
      ec_stderr("key combination: key '%c' is not defined\n", *a);
      return 1;
    }
    if(j > 127) {
      ec_stderr("key combination: key '%c' uses modifier\n", *a);
      return 1;
    }
    comb += j;
  } else {
    j = (int) HashLookup(key_names, a);
    if(j == 0) {
      ec_stderr("key \"%s\" is not a valid key combination\n", a);
      return 1;
    }
    comb += j;
  }
  *pcomb = comb;
  return 0;
}

int do_scancode(int argc, char **argv)
{
  int i;
  int comb = 0;
  char *a;
  if(argc != 3) goto usage;

  a = argv[1];
  i = 0;
  if(a[1] == 0) {
    i = *a;
    /* the char is the name of the key, and is bound to it */
    if(parse_key_comb(argv[2],&comb)) return 1;
    key_comb[i] = comb;
  } else {
    /* this is a key name */
    i = (int) HashLookup(key_names, a);
    if(i != 0) {
      ec_stderr("scancode: key name '%s' already defined\n", a);
      return 1;
    }
    if(parse_key_comb(argv[2],&comb)) return 1;
    HashInsert(key_names, a, (void*)comb);
  }
  return 0;
usage:
  ec_stderr("usage: scancode <char or st key name> <key combination>\n");
  return 1;
}



int do_bind(int argc, char **argv)
{
  unsigned int i;
  int comb;
  char *a;
  if(argc != 3) goto usage;
  a = argv[1];
  i = 0;
  if(*a == '0') {
    if(a[1] == 'x') {
      sscanf(a+2,"%x",&i);
    } else {
      sscanf(a+1,"%o",&i);
    }
  } else if(*a >= '1' && *a <= '9') {
    sscanf(a,"%d",&i);
  } else {
    i = ec_key_from_name(a);
    if(i == 0) return 1;
  }
  if(i <= 0 || i >= key_number) {
    ec_stderr("bind: bad key specification \"%s\"\n", a);
    return 1;
  }
  if(parse_key_comb(argv[2],&comb)) return 1;
  key_comb[i] = comb;

  return 0;
usage:
  ec_stderr("usage: bind <number or ec key name> <key combination>");
  return 1;
}

static void my_ikbd_send(unsigned char b)
{
  /*  ec_stderr("ikbd_send(0x%02x)\n", b); */
  ikbd_send(b);
}

void kbd_key_handler(void *object, int key)
{
  int i;
  int comb;
  (void)object;

  /* ec_stderr("kbd_key_handler(key %d)\n", key); */

  if(key <= 0 || key >= key_number) {
        ec_stderr("kbd_key_handler: key %d <= 0 or >= key_number %d\n",
              key, key_number);
    return;
  }
  comb = key_comb[key];
  if(comb == 0) return;
  for(i = 0 ; i < 10 ; i++) {
    if(comb & (0x10000<<i)) {
      my_ikbd_send((unsigned char)(modif_scan[i]));
    }
  }
  my_ikbd_send((unsigned char)(comb & 0x7F));
  my_ikbd_send((unsigned char)((comb & 0x7F)|0x80));
  for(i = 0 ; i < 10 ; i++) {
    if(comb & (0x10000<<i)) {
      my_ikbd_send((unsigned char)(modif_scan[i]|0x80));
    }
  }
}
