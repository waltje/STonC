/*
 * nf.c - a simple Native function services implementation 
 *
 * Copyright (c) 2002 Laurent Vogel
 *
 * TODO - determine what license should apply (LGPL?)
 */

#include <string.h>
#include "nf.h"

#define SUB_ID_SHIFT 20
#define SUB_ID_MASK ((1 << SUB_ID_SHIFT) - 1)

/*
 * A simple table for native functions.
 */

#define MAXFUNCS 100
#define MAXNAME 40
static struct item {
  nf_func_t func;
  char name[MAXNAME];
  int user_allowed;
} table[MAXFUNCS];
static int numfuncs;

static int find(const char *name)
{
  int i;
  for(i = 0 ; i < numfuncs ; i++) {
    if(!strncmp(name, table[i].name, MAXNAME)) 
      return i+1;
  }
  return 0;
}

/* called by a native implementation module to register native functions */
nf_long_t nf_register_func(const char * name, nf_func_t func, int user_allowed)
{
  struct item *p;

  if(find(name)) {
    nf_error("native function '%s' already registered\n", name);
    return 0;
  }
  if(numfuncs >= MAXFUNCS) {
    nf_error("too many native functions registered\n");
    return 0;
  }
  p = &table[numfuncs++];
  strncpy(p->name, name, MAXNAME);
  p->func = func;
  p->user_allowed = user_allowed;
  return numfuncs;
}

/* called by the CPU core */
nf_long_t nf_get_id(nf_addr_t sp)
{
  char name[MAXNAME];

  nf_get_nstr(name, nf_get_a(sp+4), MAXNAME);
  return find(name) << SUB_ID_SHIFT;
}

nf_long_t nf_call(nf_addr_t sp, int user_mode)
{
  nf_long_t id = nf_get_l(sp + 4);
  int upper_part = id >> SUB_ID_SHIFT;
  struct item *p;

  if(upper_part <= 0 || upper_part > numfuncs) {
    nf_error("nf_call: unknown ID %08lx at %08lx\n", id, nf_get_ul(sp));
    return 0;
  }
  p = &table[upper_part-1];
  if(user_mode && ! p->user_allowed) {
    nf_error("NatFeat %s not allowed in user mode\n", p->name);
    return 0;
  }
  return p->func(id & SUB_ID_MASK, sp + 8);
}


/*
 * Native feature basic set.
 *
 */

/*
 * "NF_NAME" :
 *  void getName(char *buffer, unsigned long size)
 *     subID = 0
 *     fills 'buffer' with a null-terminated string representing the
 *     emulator name. At most 'size' bytes will be written in the
 *     buffer (which means that the string will be truncated if it
 *     contains more than size - 1 characters).
 *     the string should contain only printable ASCII characters
 *     (ASCII 32 to 126 inclusive).
 *
 *  void getFullName(char *buffer, unsigned long size)
 *     subID = 1
 *     similar to getName, but the string is the emulator name plus 
 *     its version (and anything else that might be printed together 
 *     with the emulator name)
 */

#include "version.h"

nf_long_t nf_name(nf_long_t sub_id, nf_addr_t sp)
{
  nf_addr_t addr = nf_get_a(sp);
  nf_ulong_t size = nf_get_ul(sp+4);
  switch(sub_id) {
  case 0:
    nf_set_nstr(addr, "STonC", size);
    return 5;
  case 1:
    nf_set_nstr(addr, "STonC " VERSION, size);
    return sizeof( "STonC " VERSION - 1);
  default:
    nf_error("NF_NAME unknown sub-id %d\n", sub_id);
  } 
  return 0;
}

/*
 * "NF_VERSION"
 *   long getVersion(void)
 *     returns the version of the native feature framework, hex encoded
 *     (upper word = major number, lower word = minor number). This document
 *     describes native features version 1.0 (hex encoding 0x00010000).
 */

nf_long_t nf_version(nf_long_t sub_id, nf_addr_t sp)
{
  (void)sub_id;
  (void)sp;
  return 0x00010000;
}

nf_long_t nf_stderr(nf_long_t sub_id, nf_addr_t sp)
{
  char buf[100];
  unsigned int i = 0;
  nf_addr_t addr = nf_get_a(sp);
  char c;
  
  (void)sub_id;
  while( (c = nf_get_b(addr++)) != 0) {
    if(c == 10 || c == 13) c = '\n';
    buf[i++] = c;
    if(i >= sizeof(buf)-1) {
      buf[i] = 0;
      ec_stderr("%s", buf);
      i = 0;
    }
  }
  if(i) {
    buf[i] = 0;
    ec_stderr("%s", buf);
  }
  return 0;
}


/* called by the emulator to initialise the nf manager; non-zero means error.*/
int nf_init(void)
{
  numfuncs = 0;
  nf_register_func( "NF_VERSION", nf_version, 1);
  nf_register_func( "NF_NAME", nf_name, 1);
  nf_register_func( "NF_STDERR", nf_stderr, 1);
  return 0;
}
