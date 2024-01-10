/*
 * nf.h - Implementation interface for Native features
 *
 * Copyright (c) 2002 Laurent Vogel
 *
 * TODO - determine what license should apply (LGPL?)
 */

#ifndef NF_H
#define NF_H

/*========================== basic types ===================================*/

#include "nfglue.h"

/* the type of the native function */
typedef nf_long_t (*nf_func_t)(nf_long_t, nf_addr_t);

/*========================== basic emulator glue ===========================*/

/* read the specified type at the 68k address addr; if bus error occurs,
 * then either the function does not return, or an unspecified value is
 * returned
 */
nf_byte_t  nf_get_b (nf_addr_t addr);
nf_ubyte_t nf_get_ub(nf_addr_t addr);
nf_word_t  nf_get_w (nf_addr_t addr);
nf_uword_t nf_get_uw(nf_addr_t addr);
nf_long_t  nf_get_l (nf_addr_t addr);
nf_ulong_t nf_get_ul(nf_addr_t addr);
nf_addr_t  nf_get_a (nf_addr_t addr);

/* write the value in 68k memory; may not return if bus error occurs */
void nf_set_b (nf_addr_t addr, nf_byte_t  value);
void nf_set_ub(nf_addr_t addr, nf_ubyte_t value);
void nf_set_w (nf_addr_t addr, nf_word_t  value);
void nf_set_uw(nf_addr_t addr, nf_uword_t value);
void nf_set_l (nf_addr_t addr, nf_long_t  value);
void nf_set_ul(nf_addr_t addr, nf_ulong_t value);
void nf_set_a (nf_addr_t addr, nf_addr_t  value);

/*========================== context handling ===========================*/

/* functions providing a means to encapsulate native addresses into 
 * a 'token' that can be represented in an int32_t regardless of the
 * native bus address size.
 */

/* returns a token usable to later retrieve the passed ptr */
nf_long_t nf_to_token(void * ptr);

/* returns the ptr that was earlier associated with this token.
 * the token is not destroyed and the ptr can be retrieved any number of
 * times.
 * TODO: what happens if the token is not a token created by nf_to_token?
 */
void * nf_from_token(nf_long_t token);

/* frees the token. It is unspecified what happens if further calls to 
 * nf_from_token() on this same token happen.
 */ 
void * nf_free_token(nf_long_t token);


/*========================== utility functions ===========================*/

/* these can be implemented using the other above, or using more direct
 * access to the emulator internals.
 */

/* copy size bytes */
void nf_get_mem(void *buf, nf_addr_t addr, nf_long_t size);
void nf_set_mem(nf_addr_t addr, void *buf, nf_long_t size);

/* return the length of the null-ended string (null excluded) in 68k memory */
nf_long_t nf_strlen(nf_addr_t addr);

/* copy in 68k memory the supplied string. */
void nf_set_str(nf_addr_t addr, char *s);

/* same as nf_get_mem and nf_set_mem but the copy halts after the first
 * null byte, or the last byte, if reached, is copied as a null byte.
 * size must be >= 1.
 */
void nf_get_nstr(char *buf, nf_addr_t addr, nf_long_t size);
void nf_set_nstr(nf_addr_t addr, char *s, nf_long_t size);

/*========================== management functions ========================*/

#include <stdarg.h>

/* called either by the nf manager or by implementations to report errors */
void nf_error(const char *fmt, ...);
void nf_verror(const char *fmt, va_list ap);

/* called by the emulator to initialise the nf manager; non-zero means error.*/
int nf_init(void);

/* called by a native implementation module to register native functions
 * returns the id by which the native function will be callable from 68k side.
 * a zero id is returned in case of error (no memory, or duplicate name).
 */
nf_long_t nf_register_func(const char *name, nf_func_t func, int user_allowed);

/* called by the CPU core */
nf_long_t nf_get_id(nf_addr_t sp);
nf_long_t nf_call(nf_addr_t sp, int user_mode);

#endif /* NF_H */
