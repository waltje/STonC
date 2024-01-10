/* 
 * cpubis.h - second part of the CPU emulation
 *
 * Taken from STonX (C) 1994-1997 Marinos Yannikos & Martin D. Griffiths
 * Modified for STonC (C) 1998-2002 Laurent Vogel
 * Covered by the GPL version 2 or later; see COPYING for details
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "utils.h"
#include "defs.h"
#include "iofuncs.h"
#include "io.h"
#include "mem.h"
#include "cpu.h"
#include "syscalls.h"
#include "boss.h"
#include "gemdos.h"
#include "nfglue.h"

#define EXCEPTION(n) exception(n, LM_UL(EXCEPTION_VECTOR(n)))
#define NOTREACHED assert(0);


/*
 * ex_reset : reset every peripheral.
 */

extern void hdc_reset(void) ;
extern void mfp_reset(void) ;


void ex_reset(void) {

  hdc_reset();
  mfp_reset();

  /* shifter : ? */

  /* TODO : fdc reset */

  /* DMA ? */
} 


void ex_stop(void) {
  /* stop should wait until an external event occurs (manual reset, 
   * or exception). This is not implemented right now. We only halt 
   * the emulation and go back to the ui.
   */
  ec_stderr( "STOP opcode at pc = 0x%08lx\n", (UL)pc);
  set_cpu_status(CPU_STATUS_STOPPED);
  
}



void enter_user_mode (void)
{
        L tmp;
        sr &= ~SR_S;
        tmp = AREG(7);
        AREG(7) = AREG(8);
        AREG(8) = tmp;
}

void enter_supervisor_mode (void)
{
        L tmp;
        sr |= SR_S;
        tmp = AREG(7);
        AREG(7) = AREG(8);
        AREG(8) = tmp;
}

int cpu_status = CPU_STATUS_UNINITIALIZED;

void set_cpu_status(int s)
{
  cpu_status = s;
  switch(s) {
  case CPU_STATUS_UNINITIALIZED:
    break;
  case CPU_STATUS_STOPPED:
    boss_stop();
    break;
  case CPU_STATUS_HALTED:
    boss_stop();
    break;
  case CPU_STATUS_DEAD:
    ec_stderr("CPU halted. The only thing you can do is reset.\n");
    boss_stop();
    break;
  case CPU_STATUS_RUNNING:
    break;
  default:
    ec_fatal("wrong cpu status %d\n", s);
  }
}

static void V_EX (UL addr, int rw)
{
        UW tsr = sr;
  static int in_v_ex = 0;
  UW z;

  if(in_v_ex) {
    /* double bus error, halt the CPU */
    in_v_ex = 0;
    ec_stderr("\"Double bus error\" condition.\n");    
    set_cpu_status(CPU_STATUS_DEAD);
    return;
  } 
  in_v_ex = 1;
        FIX_CCR();
        if (!SUPERVISOR_MODE)
                enter_supervisor_mode();
        flags &= ~(F_TRACE0|F_TRACE1); /* no Tracing during exceptions */
        sr &= ~SR_T;
        PUSH_UL(pc);
        PUSH_UW(tsr);
        PUSH_UW(last_iw);       
        PUSH_UL(addr);
        if(rw) {
          z = 0x10;
        } else {
          z = 0;
        }
        if((TRIM(addr) >= TRIM(last_pc)) && (TRIM(addr) <= TRIM(pc))) {
          /* I bet the error occurred during instruction fetch */
    if(tsr & SR_S) {
      /* Super program I=0; FC2-0 = 110 */
      z |= 0x6;
    } else {
      /* user program I=0; FC2-0 = 010 */
      z |= 2;
    }
        } else {
          if(tsr & SR_S) {
      /* Super data I=0; FC2-0 = 100 */
      z |= 0x4;
    } else {
      /* user program I=0; FC2-0 = 000 */
    }
        }
        PUSH_UW(z); 
#if 0
        sr &= 0xf8ff;
        sr |= 0x0700;   /* BUG */
#endif
        in_v_ex = 0;
        
}




void EX_BUS_ERROR (UL addr, int rw)
{
#if 1
        ec_stderr("Bus error at %08lx, sp=%08lx, sr=%04x addr=%08lx %s -> %08lx\n",
                last_pc,(long)SP,(UW)sr,addr,rw?"read":"write", LM_UL(ADDR(8)));
#endif
        V_EX (addr, rw);
}

void EX_ADDRESS_ERROR (UL addr, int rw)
{
#if 1
        ec_stderr("Address error at %08lx, sp=%08lx, sr=%04x addr=%08lx %s -> %08lx\n",
                last_pc,(long)SP,(UW)sr,addr,rw?"read":"write", LM_UL(ADDR(12)));
#endif
        V_EX (addr, rw);
}

void exception (int n, UL nw)
{
        UW tsr;
        L new_pc;
        
        FIX_CCR();
        tsr = sr;
#if 1
        if (n != T_VBL  && n != T_200Hz && n != T_TRAP_BIOS && n != T_ACIA 
            && n != T_LINEA && n != T_LINEF && n != 32 /* Minix task switch */ 
            && n != 71 /* DMA */  && n != 76 && n != 74  /* USART */
            && n != T_TRAP_XBIOS && n != T_TRAP_GEMDOS && n != T_TRAP_GEM)
        {
                ec_stderr( "Exception %d at pc=%08lx, sp=%08lx (iw=%04x) -> %08lx\n", 
                  n, last_pc, SP, last_iw, nw);
        }
#endif
        
#if 0
        if(n == T_LINEA) {
          ec_stderr("pc=0x%08lx, linea 0x%04x\n", pc, LM_UW(MEM(pc)));
        }
#endif
#if 0
        if(n == T_LINEF) {
          ec_stderr("pc=0x%08lx, linef 0x%04x\n", pc, LM_UW(MEM(pc)));
        }
#endif
#if 0
        if(n == T_TRAP_BIOS) {
          if((LM_UW(MEM(SP)) != 1) && (LM_UW(MEM(SP)) != 3)) { 
            ec_stderr("pc=0x%08lx, bios(0x%04x)\n", pc, LM_UW(MEM(SP)));
          }
        }
#endif
#if 0
        if(n == T_TRAP_XBIOS) {
          ec_stderr("pc=0x%08lx, xbios(0x%04x)\n", pc, LM_UW(MEM(SP)));
        }
#endif
#if 0
        if(n == T_TRAP_GEM) {
          if(DREG(0) == 0xc8) {
            ec_stderr("pc=0x%08lx, aes contrl[0] = 0x%04lx\n", pc, 
              LM_UW(MEM( LM_UL(MEM( DREG(1) )) )));
          } else {
            ec_stderr("pc=0x%08lx, gem d0 = 0x%08lx\n", pc, DREG(0));
          }
        }
#endif
        
        if (n < T_TRAP_0 || n > T_TRAP_15)
        {
                flags &= ~(F_TRACE0|F_TRACE1); /* no Tracing during exceptions */
                sr &= ~SR_T;
        }

#if 0
        ec_stderr("Switching to supervisor mode\n");
#endif
        if (!SUPERVISOR_MODE)
                enter_supervisor_mode();
#if 0
        if (cputype >= 68010)
                PUSH_UW(0); 
#endif
        PUSH_UL(pc);
        PUSH_UW(tsr);
#if 0
        /* do NOT trim pc : some applications rely on interrupt vectors
         * having attributes set in 8 high-order bits */
        new_pc=TRIM(nw);
#else
        new_pc=nw ;
#endif  
        pc=new_pc; /* CHECK_PC! */
        CHECK_PC();
}

void ex_breakpt (void)
{
        pc -= 2;
#if MONITOR
        if (!enter_monitor())
#endif
                EXCEPTION(T_ILLEGAL);
}

void ex_privileged(void)
{
        EXCEPTION(T_PRIVILEGED);
}

void ex_chk(void)
{
        EXCEPTION(T_CHK);
}

void ex_overflow(void)
{
        EXCEPTION(T_OVERFLOW);
}

void ex_div0(void)
{
        EXCEPTION(T_DIV0);
}

void ex_linea(void)
{
        EXCEPTION(T_LINEA);
}

void ex_linef(void)
{
#if 0
        if (cputype >= 68030)
        {
                UW opcode2;
                
                switch (LM_UW(PC_MEM(pc)) & 0x0f80)
                {
                case 0x0000:
                        pc+=2;
                        opcode2=LM_UW(PC_MEM(pc));
                        pc+=2;
                        switch (opcode2 & 0xe000)
                        {
                        case 0x0000:
                        case 0x4000:
                        case 0x5000:
                        case 0x6000: /* pmove */
                                pc+=4;
                                return;
                        case 0x2000: /* pflush and friends */
                                pc -= 4;
                                ex_illegal();
                                break;
                        }
                case 0x0300: /* fsave/frestore */
                        pc += 6;
                        return;
                }
        } else
#endif

#if 1
        EXCEPTION(T_LINEF);
#else 
        ec_stderr("pc = 0x%08lx, line F 0x%03x\n", pc, 
          LM_UW(MEM(pc)) & 0x0FFF);
        pc += 2;
#endif
}

void ex_trap(int n)
{
        UL nw;

#if DEBUG_TRAPS
#  define DT(x) (ec_stderr("at %08lx: ", pc),ec_stderr x)
#else
#  define DT(x)
#endif

#if TRACE_SYSCALLS   
        trace_syscall(n);
#endif

        switch (n)
        {
        case T_TRAP_GEMDOS:
#if 1
                gemdos_first_time();
#endif
#if 0
                nw = LM_UW(MEM(SP));
                ec_stderr("GEMDOS(%02x)\n", nw);
#endif
                nw = LM_UL(EXCEPTION_VECTOR(n));
                DT(("GEMDOS(%02x) -> %lx\n", nw));
                break;
        case T_TRAP_GEM:

#if NOTYET
                if (DREG(0) == 200)     /* AES */
                {
                        nw = LM_UL(EXCEPTION_VECTOR(n));
                        DT(("AES(%08x) -> %lx\n", DREG(1), nw));
#if REDRAW && 0
                        if (redraw_flag)
                        {
                                /* window must be updated, pretend form_dial(FMD_FINISH,...) */
                                nw = CART_AES_REDRAW;
                                redraw_flag = 0; /* important! */
                        }
#endif
                        if (Aes())
                                return;
                } else
#endif
                if (DREG(0) == 115)
                {
                        nw = LM_UL(EXCEPTION_VECTOR(n));
                        DT(("VDI(%02x,%08x) -> %lx\n", DREG(1), nw));
#if 0
                        if (Vdi())
                                return;
                        PUSH_UL(DREG(1));
                        PUSH_UL(pc);
                        PUSH_UL(6);
                        PUSH_UW(0xa0ff);
                        pc = SP;
#endif
                } else
                {
                        nw = LM_UL(EXCEPTION_VECTOR(n));
                        DT(("AES/VDI(%02x,%08x) -> %lx\n", DREG(0), DREG(1), nw));
                }
                break;
        case T_TRAP_BIOS:
                nw = LM_UL(EXCEPTION_VECTOR(n));
#if 0
                ec_stderr("BIOS(%02x) -> %lx\n", LM_W(MEM(SP)), nw);
                if (Bios())
                {
                        ec_stderr("Bios %d done as native\n",LM_W(MEM(SP)));
                        return;
                }
#endif
                break;
        case T_TRAP_XBIOS:
                nw = LM_UL(EXCEPTION_VECTOR(n));
                DT(("XBIOS(%02x) -> %lx\n", LM_W(MEM(SP)), nw));
                break;

        default:
                nw = LM_UL(EXCEPTION_VECTOR(n));
                DT(("Trap #%d -> %lx\n", n-T_TRAP_0, nw));
                break;
        }
        exception(n, nw);
}

#if 0
void EXCEPTION (int n)
{
        UW tsr;
        UL newpc;
        FIX_CCR();
        tsr = sr;
        newpc = LM_UL(ADDR(n*4));

#if TRACE_SYSCALLS   
        trace_syscall(n);
#endif

#if 0
        if (n!=28 && n!=69)
        ec_stderr("Exception %d at pc=%08lx\n",n,pc);
#endif

        if (n < 32 || n >= 48)
        {
                flags &= ~(F_TRACE0|F_TRACE1); /* no Tracing during exceptions */
                sr &= ~SR_T;
        }
#if DEBUG_EXCEPT
#if DEBUG_TRAPS
        if (n >= 32 && n < 48) switch (n-32)
        {
                case 1: 
                  ec_stderr("GEMDOS(%02x) -> %lx\n", LM_W(MEM(SP)), newpc); 
                  break;
                case 2: 
                  ec_stderr("AES/VDI(%02x,%08x) -> %lx\n", DREG(0), DREG(1),newpc); 
                  break;
                case 13: 
                  ec_stderr("BIOS(%02x) -> %lx\n", LM_W(MEM(SP)), newpc); 
                  break;
                case 14: 
                  ec_stderr("XBIOS(%02x) -> %lx\n", LM_W(MEM(SP)) ,newpc); 
                  break;
                default: 
                  ec_stderr("Trap #%d -> %lx\n", n-32, newpc); 
                  break;
        }
#endif  
#endif
#if 0
        if (n == 34 && vdi_mode)
        {
#if REDRAW
                if (DREG(0) == 200 && redraw_flag)      /* AES */
                {
                        /* window must be updated, pretend form_dial(FMD_FINISH,...) */
                        newpc = 0xfa0100;
                        redraw_flag = 0; /* important! */
                }
                else
#endif
                if (DREG(0) == 115)
                {
                        if (Vdi()) return;
                        PUSH_UL(DREG(1));
                        PUSH_UL(pc);
                        PUSH_UL(6);
                        PUSH_UW(0xa0ff);
                        pc=SP;
                }
        }
#endif
        if (!SUPERVISOR_MODE)
                enter_supervisor_mode();
        PUSH_UL(pc);
        PUSH_UW(tsr);
        pc = newpc;     /* should CHECK_PC() here? */
}
#endif

void TRAP (int n)
{
        EXCEPTION(32+n);
}

extern void show_func_name(void);

#include <sys/time.h>
#include <time.h>

extern void boss_halt(void);

void ILLEGAL (void)
{
  UW iw;
  pc -= 2; 
        
  iw = LM_UW(MEM(pc));
  
        show_func_name();
        
        ec_stderr("Illegal Exception at %08lx: opcode %04x\n", (long)pc, iw);
        EXCEPTION (T_ILLEGAL);
}



UB testcond[] = {
1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,
1,0,0,1,0,1,1,0,1,0,1,0,1,0,1,0,
1,0,1,0,1,0,1,0,0,1,1,0,0,1,0,1,
1,0,0,1,0,1,1,0,0,1,1,0,0,1,0,1,
1,0,0,1,1,0,0,1,1,0,1,0,1,0,0,1,
1,0,0,1,0,1,0,1,1,0,1,0,1,0,0,1,
1,0,0,1,1,0,0,1,0,1,1,0,0,1,0,1,
1,0,0,1,0,1,0,1,0,1,1,0,0,1,0,1,
1,0,1,0,1,0,1,0,1,0,0,1,0,1,0,1,
1,0,0,1,0,1,1,0,1,0,0,1,0,1,0,1,
1,0,1,0,1,0,1,0,0,1,0,1,1,0,1,0,
1,0,0,1,0,1,1,0,0,1,0,1,1,0,1,0,
1,0,0,1,1,0,0,1,1,0,0,1,0,1,0,1,
1,0,0,1,0,1,0,1,1,0,0,1,0,1,0,1,
1,0,0,1,1,0,0,1,0,1,0,1,1,0,0,1,
1,0,0,1,0,1,0,1,0,1,0,1,1,0,0,1,
1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,
1,0,0,1,0,1,1,0,1,0,1,0,1,0,1,0,
1,0,1,0,1,0,1,0,0,1,1,0,0,1,0,1,
1,0,0,1,0,1,1,0,0,1,1,0,0,1,0,1,
1,0,0,1,1,0,0,1,1,0,1,0,1,0,0,1,
1,0,0,1,0,1,0,1,1,0,1,0,1,0,0,1,
1,0,0,1,1,0,0,1,0,1,1,0,0,1,0,1,
1,0,0,1,0,1,0,1,0,1,1,0,0,1,0,1,
1,0,1,0,1,0,1,0,1,0,0,1,0,1,0,1,
1,0,0,1,0,1,1,0,1,0,0,1,0,1,0,1,
1,0,1,0,1,0,1,0,0,1,0,1,1,0,1,0,
1,0,0,1,0,1,1,0,0,1,0,1,1,0,1,0,
1,0,0,1,1,0,0,1,1,0,0,1,0,1,0,1,
1,0,0,1,0,1,0,1,1,0,0,1,0,1,0,1,
1,0,0,1,1,0,0,1,0,1,0,1,1,0,0,1,
1,0,0,1,0,1,0,1,0,1,0,1,1,0,0,1,
};

#ifdef HALF_TABLES
#undef FIRST_TABLE

void Nullfunc (unsigned int iw);
extern GENFUNC_PROTO((*jumptab1[]));
extern GENFUNC_PROTO((*jumptab2[]));

#include "code.c"
#endif

#include "gendefs.h"


void show_func_name(void)
{
#ifdef HALF_TABLES
        int i;
        int found = 0;
        unsigned int iw;
        void (*func)(unsigned int);
        
        iw = LM_UW(MEM(pc));
        ec_stderr( "func name for 0x%04x (%d): ", iw, iw);
        if(iw < 32768) {
                func = jumptab1[iw];
        } else {
                func = jumptab2[iw & 0x7FFF];
        }
        for(i = 0; i < NUMBER_OF_FUNCS ; i++) {
                if(funclist[i] == func) {
                        ec_stderr( "Func%d !\n", i);
                        found = 1;
                } 
        }
        if(!found) {
                if(Nullfunc == func) {
                        ec_stderr( "Nullfunc !\n");
                } else {
                        ec_stderr( "function name not found !\n");
                }
        }
#endif
}

