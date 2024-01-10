/* 
 * config.h - a configuration file
 *
 * Taken from STonX (C) 1994-1997 Marinos Yannikos & Martin D. Griffiths
 * Modified for STonC (C) 1998-2002 Laurent Vogel
 * Covered by the GPL version 2 or later; see COPYING for details
 */

#ifndef CONFIG_H
#define CONFIG_H


#if 1

/* Generic configuration file - a starting point for porting */

/* do we have a register to keep the status register in? */
#undef SRREG

/* do we have a register for the PC? */
#undef PCREG

/* ... one for the NZ flag value? */
#undef NZREG

/* do we need a small "memory model"? */
#define SMALL 0

/* Make sure we know about the endianness of this system */
#ifndef IS_BIG_ENDIAN
#error Please set IS_BIG_ENDIAN to 0 or 1 in the Makefile!
#endif

#else

/* allow gcc -ansi compilation if wanted: */
#ifndef __STRICT_ANSI__
#define NZREG "%ebx"
#ifndef __cplusplus
/* g++ seems to dislike using the frame pointer register for a register
 * variable...
 */
#define PCREG "%ebp"
#endif /* __cplusplus */
#endif /* __STRICT_ANSI__ */
#undef SRREG
#define IS_BIG_ENDIAN 0
#endif

#endif /* CONFIG_H */
