/*
 * nfglue.c - NatFeat glue for STonC
 */

#include <string.h>
#include "defs.h"
#include "mem.h"
#include "nf.h"
#include "nfglue.h"
#include "emulc.h"

/* get/set for individual types */
nf_byte_t  nf_get_b (nf_addr_t addr)
{ 
  return LM_B(MEM(addr));
}
nf_ubyte_t nf_get_ub(nf_addr_t addr)
{ 
  return LM_UB(MEM(addr));
}
nf_word_t  nf_get_w (nf_addr_t addr)
{ 
  return LM_W(MEM(addr));
}
nf_uword_t nf_get_uw(nf_addr_t addr)
{ 
  return LM_UW(MEM(addr));
}
nf_long_t  nf_get_l (nf_addr_t addr)
{ 
  return LM_L(MEM(addr));
}
nf_ulong_t nf_get_ul(nf_addr_t addr)
{ 
  return LM_UL(MEM(addr));
}

/* write the value in 68k memory; may not return if bus error occurs */
void nf_set_b (nf_addr_t addr, nf_byte_t  value)
{ 
  SM_B(MEM(addr),value);
}
void nf_set_ub(nf_addr_t addr, nf_ubyte_t value)
{ 
  SM_UB(MEM(addr),value);
}
void nf_set_w (nf_addr_t addr, nf_word_t  value)
{ 
  SM_W(MEM(addr),value);
}
void nf_set_uw(nf_addr_t addr, nf_uword_t value)
{ 
  SM_UW(MEM(addr),value);
}
void nf_set_l (nf_addr_t addr, nf_long_t  value)
{ 
  SM_L(MEM(addr),value);
}
void nf_set_ul(nf_addr_t addr, nf_ulong_t value)
{ 
  SM_UL(MEM(addr),value);
}


/* these can be implemented using the other above, or using more direct
 * access to the emulator internals.
 */

void nf_get_mem(void *buf, nf_addr_t addr, nf_long_t size)
{
#if 0
  char *b = buf;
  while(--size >= 0) 
    *b++ = nf_get_b(addr++);
#else
  memcpy(buf, MEM(addr), size); 
#endif
}

void nf_set_mem(nf_addr_t addr, void *buf, nf_long_t size)
{
#if 0
  char *b = buf;
  while(--size >= 0) 
    nf_set_b(addr++, *b++);
#else
  memcpy(MEM(addr), buf, size);
#endif
}

/* returns the length of the string in 68k memory */
nf_long_t nf_strlen(nf_addr_t addr)
{
#if 0
  nf_long_t n = 0;
  while(nf_get_b(addr++)) n++;
  return n;
#else
  return strlen(MEM(addr));
#endif
}

/* copies in 68k memory the supplied string. */
void nf_set_str(nf_addr_t addr, char *s)
{
#if 0
  while(*s) nf_set_b(addr++, *s++);
  nf_set_b(addr, 0);
#else
  strcpy(MEM(addr), s);
#endif
}

/* same as nf_get_str or nf_set_str but the string is truncated to fit 
 * in size bytes (ending null included) 
 */
void nf_get_nstr(char *buf, nf_addr_t addr, int size)
{
#if 0
  while(--size > 0) {
    if((*buf++ = nf_get_b(addr++)) == 0) return;    
  }
  *buf = 0;
#else
  int n = strlen(MEM(addr));
  if(n > size - 1) {
    n = size - 1;
  }
  memcpy(buf, MEM(addr), n);
  buf[n] = 0;
#endif
}
  
void nf_set_nstr(nf_addr_t addr, char *s, int size)
{
#if 0
  while(--size > 0 && *buf) {
    nf_set_b(addr++, *buf++);
  }
  nf_set_b(addr, 0);
#else
  int n = strlen(s);
  if(n > size - 1) {
    n = size - 1;
  }
  memcpy(MEM(addr), s, n);
  SM_B(MEM(addr)+n, 0);
#endif
}


/* error messages */
void nf_verror(const char *fmt, va_list ap)
{
  ec_vstderr(fmt, ap);
}

void nf_error(const char *fmt, ...)
{
  va_list ap;
  va_start(ap, fmt);
  nf_verror(fmt, ap);
  va_end(ap);
}
