/* 
 * cpu.c - the C part of the 68000 cpu emulation
 *
 * Taken from STonX (C) 1994-1997 Marinos Yannikos & Martin D. Griffiths
 * Modified for STonC (C) 1998-2002 Laurent Vogel
 * Covered by the GPL version 2 or later; see COPYING for details
 */

/* DEBUG - define this to trace all pc in a file called pclog */
#define PCLOG 0

/* DEBUG - define this to report jumps */
#define JMPLOG 0

/* records the last instruction word in case of exception */
#define LAST_PC_IW 1

/* EXPERIMENTAL - flags are only tested every four instructions */
#define LAZY_FLAG 0

/* When the bug in gcc 2.6.0-2.6.3 is fixed, define as 'static' ... */
#define STATIC static

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "defs.h"
#include "iofuncs.h"
#include "io.h"
#include "mem.h"
#include "cpu.h"
#include "am.h"
#include "main.h"
#include "syscalls.h"
#include "blitter.h"
#include "native.h"
#include "utils.h"
#include "boss.h"

#include "vtime.h"

#include "iotab.h"


#if __cplusplus
#else
jmp_buf cpu_jmp_buf;
#endif


#define EXCEPTION(n) exception(n, LM_UL(EXCEPTION_VECTOR(n)))
#define NOTREACHED assert(0);

#define CHECK_TRACE() do{if (sr&SR_T) {flags &= ~F_TRACE1; flags |= F_TRACE0;}}while(0)
#define CHECK_NOTRACE() do{if ((sr&SR_T)==0) flags &= ~(F_TRACE0|F_TRACE1);}while (0)
#define SBITS(_l,_h,_x) ((int) ((((_x)>>(_l))^(1<<((_h)-(_l))))&\
                                                ((1<<((_h)-(_l)+1))-1)) - (1<<((_h)-(_l))))
#define UBITS(_l,_h,_x) ((((unsigned int)(_x))>>(_l))&((1<<((_h)-(_l)+1))-1))
#define BIT(_n,_x)      (((_x)>>(_n))&1)

/* UL dummy0[100]; */
L dreg[17];

#if !defined(PCREG) || !defined(__GNUC__)
UL pc;
#endif

#if !defined(SRREG) || !defined(__GNUC__)
UW sr;  /* includes CCR */
#endif

#if !defined(NZREG) || !defined(__GNUC__)
L nz_save;
#endif

UL flags=0;
UW last_iw;
UL last_pc;

/* these should be global register variables... */
UL vaddr;
void *addr;
/* tables for handling special addresses */



static INLINE void STORE_TABLE(UL d, B v)
{
        UB x = IOTAB_flags_STORE[d - TRIM(0xFF0000)];
        if (x == 0) BUS_ERROR(d, 0);
        else if (x == 1) SM_B(ADDR(d), v);
        else IOTAB_funcs_STORE[x-2](v);
}

static INLINE B LOAD_TABLE(UL s)
{
        UB x = IOTAB_flags_LOAD[s - TRIM(0xFF0000)];
        if (x == 0) BUS_ERROR(s, 1);
        else if (x == 1) return LM_B(ADDR(s));
        else return IOTAB_funcs_LOAD[x-2]();
        NOTREACHED return 0;
}


/* the following functions handle special access */

B LS_B (UL s)
{
  if (!SUPERVISOR_MODE) BUS_ERROR (s, 1);
  if(tos_1) {
    if (s >= 0x802 && s < TRIM(0xFA0000)) {
      BUS_ERROR(s, 1);
    } else if (s < TRIM(0xFF0000)) {
      return LM_B(ADDR(s));
    } else if (s >= TRIM(0xFF0000) && s <= TRIM(0xFFFFFF)) {
      return LOAD_TABLE(s);
    } else BUS_ERROR (s, 1);
  } else {
    if (s >= 0x802 && s < TRIM(0xE00000)) {
      BUS_ERROR(s, 1);
    } else if (s >= TRIM(0xF00000) && s < TRIM(0xFA0000)) {
      BUS_ERROR(s, 1);
    } else if (s >= TRIM(0xFC0000) && s < TRIM(0xFF0000)) {
      BUS_ERROR(s, 1);
    } else if (s < TRIM(0xFF0000)) {
      return LM_B(ADDR(s));
    } else if (s >= TRIM(0xFF0000) && s <= TRIM(0xFFFFFF)) {
      return LOAD_TABLE(s);
    } else BUS_ERROR (s, 1);
  }
  ec_stderr( "NOTREACHED LS_B\n") ;
  NOTREACHED return 0;
}

/* I'm lazy ... */

W LS_W (UL s)
{
  if (s & 1) ADDRESS_ERROR (s, 1);
  else return (LS_B(s)<<8)|(LS_B(s+1) & 0xFF);
  ec_stderr( "NOTREACHED LS_W\n") ;
  NOTREACHED return 0;
}

L LS_L (UL s)
{
  if (s & 1) ADDRESS_ERROR (s, 1);
  else return (LS_W(s)<<16)|(LS_W(s+2)&0xFFFF);
  ec_stderr( "NOTREACHED LS_L\n") ;
  NOTREACHED return 0;
}


void SS_B (UL d, B v)
{

        if (!SUPERVISOR_MODE) BUS_ERROR (d, 0);
        if (d < 0x800) {
          SM_B(ADDR(d), v);
        } else if( d < TRIM(0xFF0000)) { 
                BUS_ERROR (d, 0);
  } else if (d >= TRIM(0xFF0000) && d <= TRIM(0xFFFFFF)) {
          STORE_TABLE(d, v);
  } else {
    BUS_ERROR (d, 0);
  }
}

void SS_W (UL d, W v)
{
        if (d & 1) {
          ADDRESS_ERROR (d, 0);
        } else if (d < 0x800 && SUPERVISOR_MODE) {
          SM_W(ADDR(d), v);
        } else {
          SS_B(d, v>>8);
                SS_B(d+1,v&0xFF);
        }
}

void SS_L (UL d, L v)
{
        SS_W(d, v>>16);
        SS_W(d+2, v&0xffff);
}


/*------------------*/


B BCD_ADD(B a, B b)
{
  int q;
  sr &= ~MASK_CC|MASK_CC_X;
        
  q = (a & 0xF) + (b & 0xF) + GET_X_BIT();
  if(q >= 0xA) q += 0x6;
  
  q += (a & 0xF0) + (b & 0xF0) ;
  if(q >= 0xA0) q += 0x60;

  if(q & 0xFF00) {
    sr |= MASK_CC_X|MASK_CC_C;
  }
  q &= 0xFF;
  if(q != 0) UNSET_Z();
  return q;
}

B BCD_SUB(B a, B b)
{
  int q,w;
  sr &= ~MASK_CC|MASK_CC_X;
        
  q = (b & 0xF) - (a & 0xF) - GET_X_BIT();
  w = (b & 0xF0) - (a & 0xF0);
  if(q < 0) { 
    q += 10; 
    w -= 0x10; 
  } 
  if(w < 0) {
    w -= 0x60;
  }
  q += w;

  if(q & 0xFF00) {
    sr |= MASK_CC_X|MASK_CC_C;
  }
  q &= 0xFF;
  if(q != 0) UNSET_Z();
  return q;
}


/* -------------------- SPECIAL EVENTS DISPATCHER --------------------------- */

#if PCLOG
FILE *pclogfile = NULL;
#endif /* PCLOG */

#if JMPLOG
UL jmplogpc = NULL;
#endif

extern int mfp_do_interrupt(void);

extern void exception (int n, UL nw);

static void process_flags (void)
{  
          if ( ( flags & F_MFP) ) {
#if 0
                ec_stderr( "MFP interrupt ? sr = 0x%04x \n", sr);
#endif
            
            if(IPL_OK(6)) {
              int vector_number = mfp_do_interrupt() ;
              if(vector_number) {
#if 0
                ec_stderr( "MFP interrupt vector %d\n", vector_number);
#endif
                
                  EXCEPTION(vector_number);
                
                  SET_IPL(7);  
              } else {
                flags &= ~F_MFP ;
              }
            }
          }             

        if (flags & F_BLIT)
        {
                Do_Blit();
                flags &= ~F_BLIT;
        }
        else
        if ((flags & F_ACIA) && IPL_OK(6)) {
                EXCEPTION(T_ACIA);
                SET_IPL(7);
                flags &= ~F_ACIA;
        }
        else
        if ((flags & F_RCV_FULL) && IPL_OK(6))
        {
                EXCEPTION(T_RCV_FULL);
                SET_IPL(7);
                flags &= ~F_RCV_FULL;
        }
        if (flags & F_TRACE0)
        {
                flags &= ~F_TRACE0;
                flags |= F_TRACE1;
        }
        else if (flags & F_TRACE1)
        {
                EXCEPTION(T_TRACE);
        }
        if ((flags & F_VBL) && IPL_OK(4))
        {
#if 0
    ec_stderr( "VBL\n") ;
/*              machine.screen_shifter(); */
#endif
                EXCEPTION(T_VBL);
                SET_IPL(5);
                flags &= ~F_VBL;
        
        }
}


#ifdef GEN_FUNCTAB
void Nullfunc (unsigned int iw)
{
  UNUSED(iw);
  ILLEGAL();
}

# ifdef DECOMPILER
#  define CODE_FUNC static inline
# else
#  define CODE_FUNC
# endif

# ifdef HALF_TABLES
/* the other table will reside in another file */
#  define FIRST_TABLE
#  include "gendefs.h"
extern GENFUNC_PROTO((*jumptab1[]));
extern GENFUNC_PROTO((*jumptab2[]));
# endif
# include "code.c"
#endif



#ifdef GEN_SWITCH
# include "gendefs.h"
#endif

#if PROFILE 
# include "profile.h"
#endif

#ifdef FUNC_NUMBERS
# include "functab.c"
# define FUNC_NUM_TAB 1
# if FUNC_NUM_TAB
GENFUNC_PROTO((*jumptab[65536]));
# endif
extern GENFUNC_PROTO((*funclist[]));
#endif

int count=0;
UL ex_addr;
int ex_rw;

#ifndef DECOMPILER

void execute (UL new_pc)
{
# ifdef GEN_LABELTAB
#  define CODE_LABEL_TABLE
#  include "code.c"
# endif
        pc = new_pc;
        
# if __cplusplus
// exceptions
restart:
try{
# else
  switch(setjmp(cpu_jmp_buf)) {
  case 0: break;
  case 2: 
    EX_BUS_ERROR(ex_addr,ex_rw);
    pc = LM_UL(ADDR(8));
    /* TODO, check */
    break;
  case 3:
    EX_ADDRESS_ERROR(ex_addr,ex_rw);
    pc = LM_UL(ADDR(12));
    /* TODO, check */
    break;
  case 4:
    ILLEGAL();
  default:
    ec_fatal("wrong value received from longjmp(cpu_jmp_buf)\n");
  }
# endif /* __cplusplus */
  
        for (;;)
        {
                unsigned int iw;
                if (flags) {
                        process_flags();
                        if(flags & F_UI)
                                return;
                }
                iw=LM_UW(MEM(pc));
                
# if PROF68K
                prof_check();
# endif

# if PCLOG
                {
                  long mypc = pc;
                  if(mypc >= 0 && mypc <= 0x100000)
                    fwrite(&mypc, sizeof(long), 1, pclogfile);
                  if(mypc == 0xe0154a) {
                    fclose(pclogfile);
                    exit(0);
                  }
                }
# endif  
                
# if JMPLOG
                {
                  L d = (L)pc - (L)jmplogpc;
                  if (d > 10 || d < -2) {
                    ec_stderr("%08lx-->%08lx\n", jmplogpc, pc);
                  }
                  jmplogpc = pc;
                }
# endif

# if LAST_PC_IW
    last_pc = pc;
    last_iw = iw;
# endif

                pc+=2;
                /* we assume that every instruction spends 2 cycles */
                spent_cycles(2) ;
                 
# if defined(GEN_FUNCTAB)
#  ifdef HALF_TABLES
                if(iw < 32768) {
                        jumptab1[iw](iw);
                } else {
                        jumptab2[iw - 32768](iw);
                }
#  else /* HALF_TABLES */
#   ifdef FUNC_NUMBERS
#    if FUNC_NUM_TAB
                jumptab[iw](iw);
#     if LAZY_FLAG /* multiple instructions between flag test */
                iw=LM_UW(MEM(pc));
#      if LAST_PC_IW
                last_pc = pc;
                last_iw = iw;
#      endif
                pc += 2;
                jumptab[iw](iw);
                iw=LM_UW(MEM(pc));
#      if LAST_PC_IW
                last_pc = pc;
                last_iw = iw;
#      endif
                pc += 2;
                jumptab[iw](iw);
                iw=LM_UW(MEM(pc));
#      if LAST_PC_IW
                last_pc = pc;
                last_iw = iw;
#      endif
                pc += 2;
                jumptab[iw](iw);
#     endif /* LAZY_FLAG */
#    else /* FUNC_NUM_TAB */
                {
                        int i = jumptabnum[iw];
                        if(i < 0) {
                                Nullfunc(iw);
                        } else {
                                funclist[i](iw);
                        }
                }
#    endif /* FUNC_NUM_TAB */
#   else /* FUNC_NUMBERS */
                jumptab[iw](iw);
#    if LAZY_FLAG /* multiple instructions between flag test */
                iw=LM_UW(MEM(pc));
#     if LAST_PC_IW
                last_pc = pc;
                last_iw = iw;
#     endif
                pc += 2;
                jumptab[iw](iw);
                iw=LM_UW(MEM(pc));
#     if LAST_PC_IW
                last_pc = pc;
                last_iw = iw;
#     endif
                pc += 2;
                jumptab[iw](iw);
                iw=LM_UW(MEM(pc));
                pc += 2;
#     if LAST_PC_IW
                last_pc = pc;
                last_iw = iw;
#     endif
                jumptab[iw](iw);
#    endif /* LAZY_FLAG */
#   endif /* FUNC_NUMBERS */
#  endif /* HALF_TABLES */
# elif defined(GEN_SWITCH)
#  include "code.c"
# elif defined(GEN_LABELTAB)
#  undef CODE_LABEL_TABLE
#  include "code.c"
# endif

}
# if __cplusplus
}
catch(int i)
{
        UL newpc;
#  if 0 
        ec_stderr( "Exception at pc=%lx!\n",pc);
#  endif
        if (i==2)
        {
                newpc=LM_UL(ADDR(8));
                EX_BUS_ERROR(ex_addr,ex_rw);
                ec_stderr( "Returned from exception\n");
                pc=newpc;
        }
        else if (i==3)
        {
                newpc=LM_UL(ADDR(12));
                EX_ADDRESS_ERROR(ex_addr,ex_rw);
                pc=newpc;
        }
        else
        {
                ILLEGAL();
        }
        ec_stderr( "restarting at pc=%lx\n",(long)pc);
        goto restart;
}
# endif /* __cplusplus */
        exit(0); /* tell GCC that we won't ever come back */
}
#endif /* DECOMPILER */

void execute_start (UL new_pc)
{
  switch(cpu_status) {
  case CPU_STATUS_UNINITIALIZED:
    ec_fatal("cpu launched but not inited\n");
    return;
  case CPU_STATUS_DEAD:
    boss_stop();
    return;
  case CPU_STATUS_STOPPED:
    boss_stop();
    return;
  case CPU_STATUS_HALTED:
  case CPU_STATUS_RUNNING:
    cpu_status = CPU_STATUS_RUNNING;
    execute (new_pc);
    return;
  default:
   ec_fatal("wrong cpu status %d\n", cpu_status);
  }
}

void init_cpu (void)
{      
  init_iotab();
        
#if PCLOG
  pclogfile = fopen("pclog", "wb");
#endif

#ifdef FUNC_NUMBERS
# if FUNC_NUM_TAB
   { 
     int i;
     for (i = 0 ; i < 65536 ; i++) {
       if (jumptabnum[i] < 0) {
         jumptab[i] = Nullfunc;
       } else {
         jumptab[i] = funclist[jumptabnum[i]];
       }
     }
   }
# endif
#endif

  memset((char *)dreg, 1, 17*4);
  cpu_reset();
}

void cpu_reset(void)
{
  /* these adress are ROM but since I don't check, better 
   * put back the correct values.
   * adress zero = the new stack pointer
   * address four = the new program counter
   * they are copied from the ROM (ROM mirrored in a real st)
   */
  UL rom_addr = tos_1 ? 0xFC0000 : 0xE00000;
  SM_UL(ADDR(0), LM_UL(MEM(rom_addr))); 
  SM_UL(ADDR(4), LM_UL(MEM(rom_addr+4)));
  
  set_cpu_status(CPU_STATUS_RUNNING);
  
  /* the reset signal to the CPU also resets the other peripherals,
   * exactly the same way as during the reset instruction 
   */
  ex_reset();

  if (!SUPERVISOR_MODE) {
    enter_supervisor_mode();
  }
  
  sr = 0x2700;
  SP = LM_UL(ADDR(0));
  pc = LM_UL(ADDR(4));
}




