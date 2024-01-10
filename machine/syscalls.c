/* 
 * syscalls.c - trace BIOS calls
 *
 * Taken from STonX (C) 1994-1997 Marinos Yannikos & Martin D. Griffiths
 * Modified for STonC (C) 1998-2003 Laurent Vogel
 * Covered by the GPL version 2 or later; see COPYING for details
 */

#include "defs.h"
#include "mem.h"
#include "syscalls.h"
#include <stdio.h>

#include "utils.h"

#if TRACE_SYSCALLS

typedef struct 
{
  char *name;
  char *fmt;
  void (*morefunc)(void);
  char *desc[10];
} syscall_desc;

void print_mpb(void)
{
}

static syscall_desc bios_calls[] =
{
  /* 00 */ {"Getmpb","a",print_mpb,{"MPB",}},
  /* 01 */ {"Bconstat","w",NULL,{"dev",}},
  /* 02 */ {"Bconin","w",NULL,{"dev",}},
  /* 03 */ {"Bconout","ww",NULL,{"dev","c"}},
  /* 04 */ {"Rwabs","wawwwl",NULL,{"rwflag","buf","count","recno","dev","lrecno"}},
  /* 05 */ {"Setexc","wa",NULL,{"vecnum","vec"}},
  /* 06 */ {"Tickcal","",NULL,{NULL}},
  /* 07 */ {"Getbpb","w",NULL,{"dev"}},
  /* 08 */ {"Bcostat","w",NULL,{"dev"}},
  /* 09 */ {"Mediach","w",NULL,{"dev"}},
  /* 0a */ {"Drvmap","",NULL,{NULL}},
  /* 0b */ {"Kbshift","w",NULL,{"mode"}},
};

static syscall_desc gemdos_calls[] =
{
  /* 00 */ {"Pterm0","",NULL,{NULL}},
  /* 01 */ {"Cconin","",NULL,{NULL}},
  /* 02 */ {"Cconin","",NULL,{NULL}},
  /* 03 */ {"Cconout","w",NULL,{"c"}},
  /* 04 */ {"Cauxin","",NULL,{NULL}},
  /* 05 */ {"Cauxout","w",NULL,{"c"}},
  /* 06 */ {"Cprnout","w",NULL,{"c"}},
  /* 07 */ {"Crawio","w",NULL,{"wrd"}},
  /* 08 */ {"Crawcin","",NULL,{NULL}},
  /* 09 */ {"Cnecin","",NULL,{NULL}},
  /* 0a */ {"Cconws","s",NULL,{"str"}},
  /* 0b */ {"Cconrs","a",NULL,{"buf"}},
  /* 0c */ {"Cconis","",NULL,{NULL}},
  /* 0d */ {NULL,NULL,NULL,{NULL}},
  /* 0e */ {NULL,NULL,NULL,{NULL}},
  /* 0f */ {"Dsetdrv","w",NULL,{"drive"}},
  /* 10 */ {NULL,NULL,NULL,{NULL}},
  /* 11 */ {"Cconos","",NULL,{NULL}},
  /* 12 */ {"Cprnos","",NULL,{NULL}},
  /* 13 */ {"Cauxis","",NULL,{NULL}},
  /* 14 */ {NULL,NULL,NULL,{NULL}},
  /* 15 */ {NULL,NULL,NULL,{NULL}},
  /* 16 */ {NULL,NULL,NULL,{NULL}},
  /* 17 */ {NULL,NULL,NULL,{NULL}},
  /* 18 */ {NULL,NULL,NULL,{NULL}},
  /* 19 */ {NULL,NULL,NULL,{NULL}},
  /* 1a */ {"Dgetdrv","",NULL,{NULL}},
  /* 1b */ {"Fsetdta","a",NULL,{"buf"}},
  /* 1c */ {NULL,NULL,NULL,{NULL}},
  /* 1d */ {NULL,NULL,NULL,{NULL}},
  /* 1e */ {NULL,NULL,NULL,{NULL}},
  /* 1f */ {NULL,NULL,NULL,{NULL}},
  /* 20 */ {"Super","l",NULL,{"mode"}},
  /* 21 */ {NULL,NULL,NULL,{NULL}},
  /* 22 */ {NULL,NULL,NULL,{NULL}},
  /* 23 */ {NULL,NULL,NULL,{NULL}},
  /* 24 */ {NULL,NULL,NULL,{NULL}},
  /* 25 */ {NULL,NULL,NULL,{NULL}},
  /* 26 */ {NULL,NULL,NULL,{NULL}},
  /* 27 */ {NULL,NULL,NULL,{NULL}},
  /* 28 */ {NULL,NULL,NULL,{NULL}},
  /* 29 */ {NULL,NULL,NULL,{NULL}},
  /* 2a */ {"Tgetdate","",NULL,{NULL}},
  /* 2b */ {"Tsetdate","w",NULL,{"date"}},
  /* 2c */ {"Tgettime","",NULL,{NULL}},
  /* 2d */ {"Tsettime","w",NULL,{"time"}},
  /* 2e */ {NULL,NULL,NULL,{NULL}},
  /* 2f */ {"Fgetdta","",NULL,{NULL}},
  /* 30 */ {"Sversion","",NULL,{NULL}},
  /* 31 */ {"Ptermres","lw",NULL,{"keepcnt", "retcode"}},
  /* 32 */ {NULL,NULL,NULL,{NULL}},
  /* 33 */ {NULL,NULL,NULL,{NULL}},
  /* 34 */ {NULL,NULL,NULL,{NULL}},
  /* 35 */ {NULL,NULL,NULL,{NULL}},
  /* 36 */ {"Dfree","aw",NULL,{"buffer", "drive"}},
  /* 37 */ {NULL,NULL,NULL,{NULL}},
  /* 38 */ {NULL,NULL,NULL,{NULL}},
  /* 39 */ {"Dcreate","s",NULL,{"path"}},
  /* 3a */ {"Ddelete","s",NULL,{"path"}},
  /* 3b */ {"Dsetpath","s",NULL,{"path"}},
  /* 3c */ {"Fcreate","sw",NULL,{"fname", "mode"}},
  /* 3d */ {"Fopen","sw",NULL,{"fname", "mode"}},
  /* 3e */ {"Fclose","w",NULL,{"handle"}},
  /* 3f */ {"Fread","wla",NULL,{"handle", "count", "buffer"}},
  /* 40 */ {"Fwrite","wla",NULL,{"handle", "count", "buffer"}},
  /* 41 */ {"Fdelete","s",NULL,{"fname"}},
  /* 42 */ {"Fseek","lww",NULL,{"offset", "handle", "seekmode"}},
  /* 43 */ {"Fattrib","sww",NULL,{"fname", "flag", "attrib"}},
  /* 44 */ {NULL,NULL,NULL,{NULL}},
  /* 45 */ {"Fdup","w",NULL,{"handle"}},
  /* 46 */ {"Fforce","ww",NULL,{"handle", "nonstdh"}},
  /* 47 */ {"Dgetpath","aw",NULL,{"buf", "drive"}},
  /* 48 */ {"Malloc","l",NULL,{"count"}},
  /* 49 */ {"Mfree","a",NULL,{"addr"}},
  /* 4a */ {"Mshrink","wal",NULL,{"dummy", "addr", "count"}},
  /* 4b */ {"Pexec","wsss",NULL,{"mode", "path", "tail", "env"}},
  /* 4c */ {"Pterm","w",NULL,{"retcode"}},
  /* 4d */ {NULL,NULL,NULL,{NULL}},
  /* 4e */ {"Fsfirst","sw",NULL,{"fname", "attr"}},
  /* 4f */ {"Fsnext","",NULL,{NULL}},
  /* 50 */ {NULL,NULL,NULL,{NULL}},
  /* 51 */ {NULL,NULL,NULL,{NULL}},
  /* 52 */ {NULL,NULL,NULL,{NULL}},
  /* 53 */ {NULL,NULL,NULL,{NULL}},
  /* 54 */ {NULL,NULL,NULL,{NULL}},
  /* 55 */ {NULL,NULL,NULL,{NULL}},
  /* 56 */ {"Frename","wss",NULL,{"dummy", "oldname", "newname"}},
  /* 57 */ {"Fdatime","aww",NULL,{"timeptr", "handle", "flag"}},
};


static void parse_call(syscall_desc *s)
{
  UL off=2;
  char *x;
  int i;
  for (x = s->fmt, i = 0; *x; i++) {
    ec_stderr("%s=",s->desc[i]);
    switch(*x) {
    case 'a': ec_stderr("0x%08lx",(unsigned long)LM_UL(MEM(SP+off))); off+=4; break;
    case 'b': ec_stderr("0x%02x",0xff & LM_B(MEM(SP+off))); off+=2; break;
    case 'w': ec_stderr("0x%04x",0xffff & LM_W(MEM(SP+off))); off+=2; break;
    case 'l': ec_stderr("0x%08lx",(unsigned long)LM_L(MEM(SP+off))); off+=4; break;
    case 's': ec_stderr("%s",MEM(LM_L(MEM(SP+off)))); off+=4; break;
    default: ec_stderr("(invalid format)");
    }
    if (*++x) ec_stderr(", ");
  }
  ec_stderr(")\n");
}

extern int drive_bits;
          
static void sys_bios(void)
{
  int n=LM_W(MEM(SP));
  if (n < 0 || n >= (int)(sizeof(bios_calls)/sizeof(*bios_calls))) {
    ec_stderr("Invalid BIOS call (%d)\n",n);
    return;
  }

  switch(n) {
  case 0: /* getmpb */ break;
  case 1: /* Bconstat */ return;
  case 2: /* Bconin */ return;
  case 3: /* Bconout */ break;
  case 4: /* Rwabs */ break;
  case 5: /* Setexc */ break;
  case 6: /* Tickcal */ break;
  case 7: /* Getbpb */ break;
  case 8: /* Bcostat */ break;
  case 9: /* Mediach */ break;
  case 10: /* Drvmap */
    ec_stderr("drive_bits = 0x%x\n", drive_bits);
    ec_stderr("_boot_dev = %d, _nflops = %d, _drvbits = $%08lx\n", 
              LM_W(ADDR(0x446)), LM_W(ADDR(0x4a6)), LM_L(ADDR(0x4c2)));
    break;
  case 11: /* Kbshift */ break;
  }
  ec_stderr("at %08lx BIOS #%d: %s(", pc, n, bios_calls[n].name);
  parse_call(&bios_calls[n]);
}


static void sys_gemdos(void)
{
  int n=LM_W(MEM(SP));
  if(n < 0 || n >= (int)(sizeof(gemdos_calls)/sizeof(*gemdos_calls))
      || gemdos_calls[n].name == NULL) {
    ec_stderr("Invalid GEMDOS call (%x)\n",n);
    return;
  }
  ec_stderr("at %08lx GEMDOS #%x: %s(", pc, n, gemdos_calls[n].name);
  parse_call(&gemdos_calls[n]);
}

void trace_syscall(int nex)
{
  switch(nex) {
  case 45: sys_bios(); break;
  case 33: sys_gemdos(); break;
  }
}

#endif
