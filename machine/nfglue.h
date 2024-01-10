/*
 * nfglue.h - NatFeat glue for the XXX emulator
 * 
 * Copyright (c) 2002 Laurent Vogel
 *
 * This file is distributed under the GPL, version 2 or at your
 * option any later version.  See doc/copying.txt for details.
 */

#ifndef NFGLUE_H
#define NFGLUE_H

/* types */
#include "defs.h"

typedef B nf_byte_t;
typedef UB nf_ubyte_t;

typedef W nf_word_t;
typedef UW nf_uword_t;

typedef L nf_long_t;
typedef UL nf_ulong_t;

typedef nf_long_t nf_addr_t;
#define nf_get_a(a) nf_get_l(a)
#define nf_set_a(a,v) nf_set_l(a,v)

#endif /* NFGLUE_H */
