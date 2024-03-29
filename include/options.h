/* This file is part of STonX, the Atari ST Emulator for Unix/X
 * ============================================================
 * STonX is free software and comes with NO WARRANTY - read the file
 * COPYING for details
 */
#ifndef OPTIONS_H
#define OPTIONS_H

/* Some systems can't handle large BSS segments (e.g. Linux), so this may be set
 * in config.h
 */
#ifndef SMALL
#define SMALL 1
//#error "this should not happen"
#endif

/* profile 68k ? */
#define PROF68k 0

/* Blitter emulation */
#define BLITTER 0


/* Generator options */
/*
 *  default is GEN_FUNCTAB
 *  GEN_LABELTAB is gcc-only
 *  THREADING doesn't work
#define GEN_LABELTAB
#define THREADING
#define GEN_SWITCH
 */
#define GEN_FUNCTAB
/*
 * HALF_TABLES is when the assembler does not handle too much
 * reloc info at the same time.
 */
/*#define HALF_TABLES*/
#define FUNC_NUMBERS

/* make sure we can handle the generated code */
#if defined(GEN_LABELTAB) && !defined(__GNUC__)
#undef GEN_LABELTAB
#define GEN_SWITCH
#endif

/* the following are mostly obsolete, please ignore... */
#define STE 0
#define DEBUG 1 
#define NO_FLOODING 0
#define PROTECT_ROM 1
#define SAFE 0
#define PROFILE 1

#endif /* OPTIONS_H */

