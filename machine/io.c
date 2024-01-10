/* 
 * io.c - miscellaneous hardware devices
 *
 * Taken from STonX (C) 1994-1997 Marinos Yannikos & Martin D. Griffiths
 * Modified for STonC (C) 1998-2003 Laurent Vogel
 * Covered by the GPL version 2 or later; see COPYING for details
 */

#include "defs.h"
#include "cpu.h"
#include "mem.h"
#include "main.h"
#include "ikbd.h"
#include "midi.h"
#include "io.h"
#include "ocr.h"
 
#include "utils.h"
#include "vtime.h"
 
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DEBUG_MIDI 0
#define FDC_VERBOSE 0


/* serial stuff moved to usart.c */


/*--------- Information copied from hardware regs at regular intervals: ------*/
volatile UL vbase;
UL old_vbase=0;

extern void mfp_init(void) ;
extern void mfp_set_gpip_bit(unsigned char mask, unsigned char value) ;

/* This is where all hardware emulation takes place
 */
 
void vbl_alarm(void * dummy)
{
  (void)dummy;
  
  flags |= F_VBL;
  
  /* update some variables according to hw regs */
  if (old_vbase != vbase) {
#if 0
    ec_stderr("New screen address is %lx\n", vbase);
#endif
    old_vbase = vbase;
  }
  /* Do not call the shifter emulation, 
   * for it was moved to cpu.c 
   */

  set_alarm(0.02, vbl_alarm, 0) ;       /* again, 50 Hz */
}


#include "acia.h"

void init_hardware (void)
{       
        set_alarm(0.02, vbl_alarm, 0);        
        mfp_init() ;
        acias_init();
}

void kill_hardware (void)
{

}



/*
 *      Parallel Port Related stuff.    
 *      Martin GRIFFiths, 1995.
 *
 *      Last Updated : November 5th 1995. 
 */

static FILE *Parallel;
static int para_open = 0;
char *parallel_dev=NULL;

int init_parallel(void)
{       if ((Parallel=fopen(parallel_dev,"wb")) == NULL)        
                return 0;
        para_open = 1;
        return 1;
}

void write_parallel(unsigned char c)
{       if (para_open)  
        {       fwrite(&c,1,1,Parallel);
                fflush(Parallel);
#if 1
                /* minix requires this... */
                mfp_set_gpip_bit(1, 1);
                mfp_set_gpip_bit(1, 0);
#endif
        }
}

void done_parallel(void)
{       if (para_open)  
        {       fclose(Parallel);
        
        }
}

int parallel_stat(void)
{
        return Parallel != NULL;
}

/* MFP stuff moved to mfp.c and usart.c */


extern int dma_mode, dma_scr, dma_car, fdc_command, fdc_track, fdc_sector,
        fdc_data, fdc_int, fdc_status, dma_sr;
extern void fdc_exec_command(void);

#define IGNORE_S(_addr) void STORE_B_ ## _addr (B v) { UNUSED(v); }
#define UNDEF_L(_addr) B LOAD_B_ ## _addr (void) { return (B) 0xff; }
#define ZERO(_addr) B LOAD_B_ ## _addr (void) { return 0; }


/* This file contains the definitions of some of the 'special' LOAD_* 
 * and STORE_* functions for I/O-registers. 
 * 
 * For multi-byte accesses, the order will be lowest->highest byte, so e.g.
 * when writing to MWDATA (not implemented), STORE_B_ff8923 should trigger
 * the desired action.
 */


/****************************************************
 *
 * DMA 
 *
 ****************************************************/


B LOAD_B_ff8604(void)
{
  B result ;
  /* nothing in ff8604 */
  return 0 ;

        if (dma_mode & 0x10)
        {
                result = dma_scr>>8;
        }
        else
        {
                if (dma_mode & 8)
                {
                        result = dma_car>>8;
                }
                else
                {
                  switch(dma_mode & 6)
                    {
                    case 0:
                      if (!fdc_int)
                        {
                          SM_UB(MEM(0xfffa01),LM_UB(MEM(0xfffa01))|0x20);
                        }
#if FDC_DEBUG
        ec_stderr("LOAD_B_ff8604  -> 0x%02x\n",fdc_status>>8,d);
#endif
                                        result =  fdc_status>>8;
                                        break ;
                                case 2:
                                        result =  fdc_track>>8;
                                        break ;
                                case 4:
                                        result =  fdc_sector>>8;
                                        break ;
                                case 6:
                                        result =  fdc_data>>8;
                                        break ;
                                default:
                                        result =  0;
                        }
                }
        }
#if FDC_DEBUG
        ec_stderr("LOAD_B_ff8604 (dma_mode %02x) -> 0x%02x\n",
                dma_mode, result);
#endif
        return result ;
}

extern int fdc_busy ;
extern int hdc_busy, hdc_status ;

B LOAD_B_ff8605(void)
{
  B result ;
        
  if (dma_mode & 0x10) {
    result = dma_scr&0xff;
  } else {
    if (dma_mode & 8) {
      result = dma_car&0xff;
#if 0
      if(hdc_busy) {
        ec_stderr( "reading hdc status while busy\n") ;
      }
#endif  
      if(!hdc_busy) {
        mfp_set_gpip_bit(0x20, 0x20) ;
      }
      result = hdc_status ;
    } else {
      switch(dma_mode & 6) {
      case 0:
#if 1   
        if(fdc_busy) {
          ec_stderr( "reading fdc status while busy\n") ;
        }
#endif
        if(!fdc_busy) {
          mfp_set_gpip_bit(0x20, 0x20) ;
        }
        result = fdc_status&0xff;
        break ;
      case 2:
        result = fdc_track&0xff;
        break ;
      case 4:
        result = fdc_sector&0xff;
        break ;
      case 6:
        result = fdc_data&0xff;
        break ;
      default:
        result = 0;
      }
    }
  }
#if FDC_DEBUG 
  ec_stderr( "LOAD_B_ff8605 (dma_mode %02x) -> 0x%02x\n",
             dma_mode, result);
#endif
  return result ;
}

B LOAD_B_ff8606(void)
{
  return dma_sr>>8;
}

B LOAD_B_ff8607(void)
{
  return dma_sr&0xff;
#if 0
  return /* TODO */ 0x04;
#endif
}


void STORE_B_ff8604(B v)
{
        UB vv=v;
#if FDC_VERBOSE
        ec_stderr("DMA car/scr hi <- %x (mode=%x)\n",vv,dma_mode);
#endif
        if (dma_mode&0x10)
        {
                dma_scr &= 0xff;
                dma_scr |= vv<<8;
        }
        else
        {
                if (dma_mode&8)
                {
                        dma_car &= 0xff;
                        dma_car |= vv<<8;
                        
                }
                else
                {
                        switch (dma_mode&6)
                        {
                                case 0:
                                        fdc_command &= 0xff;
                                        fdc_command |= vv<<8;
                                        break;
                                case 2:
                                        fdc_track &= 0xff;
                                        fdc_track |= vv<<8;
                                        break;
                                case 4:
                                        fdc_sector &= 0xff;
                                        fdc_sector |= vv<<8;
                                        break;
                                case 6:
                                        fdc_data &= 0xff;
                                        fdc_data |= vv<<8;
                                        break;
                        }
                }
        }
}

#define mfp_set_gpip(b) (STORE_B_fffa01(b))

#define mfp_gpip (LOAD_B_fffa01())

extern void hdc_send(B v) ;

void STORE_B_ff8605(B v)
{
        UB vv=v;
#if FDC_VERBOSE
        ec_stderr("DMA car/scr lo <- %x (mode=%x)\n",vv,dma_mode);
#endif
        
        if (dma_mode&0x10)
        {
                dma_scr &= 0xff00;
                dma_scr |= vv;
        }
        else
        {
                if (dma_mode&8)
                {
                  mfp_set_gpip_bit(0x20, 0x20) ;

                        dma_car &= 0xff00;
                        dma_car |= vv;
                        hdc_send(vv) ;
                        
                }
                else
                {
                        switch (dma_mode&6)
                        {
                                case 0:
                                        fdc_command &= 0xff00;
                                        fdc_command |= vv;
                                        fdc_exec_command();
                                        break;
                                case 2:
                                        fdc_track &= 0xff00;
                                        fdc_track |= vv;
                                        break;
                                case 4:
                                        fdc_sector &= 0xff00;
                                        fdc_sector |= vv;
                                        break;
                                case 6:
                                        fdc_data &= 0xff00;
                                        fdc_data |= vv;
                                        break;
                        }
                }
        }
}

void STORE_B_ff8606(B v)
{
        UB vv=v;
        dma_mode &= 0xff;
        dma_mode |= vv<<8;
#if FDC_VERBOSE
        ec_stderr("DMA mode <- %04x\n",dma_mode);
#endif
}

void STORE_B_ff8607(B v)
{
        UB vv=v;
        dma_mode &= 0xff00;
        dma_mode |= vv;
#if 0
        ec_stderr("DMA mode <- 0x%02x\n",dma_mode);
#endif
        if(dma_mode & 0x8) {
          if(fdc_busy) {
            fdc_busy = 0 ;
            ec_stderr( "changing dma mode while fdc busy\n") ;
          }
        } else {
          if(hdc_busy) {
            /*
            hdc_busy = 0 ;
            */      
            /*
              ec_stderr( 
              "changing dma mode while hdc busy, dma=0x%02x\n",
              dma_mode) ;
            */
          }
        }

#if FDC_VERBOSE
        ec_stderr("DMA mode <- %04x\n",dma_mode);
#endif
}



/****************************************************
 *
 * shifter 
 *
 ****************************************************/


extern volatile UL vbase;
int shiftmod = 3;

/* generate a random Video Adress Counter value */
static UL gen_fake_vcount (void)
{
        return vbase + (rand() % 32000);
}

ZERO(ff8204)
ZERO(ff8206)
ZERO(ff8208)


B LOAD_B_ff8205(void)
{
        return (gen_fake_vcount() >> 16) & 0xff;
}

B LOAD_B_ff8207(void)
{
        return (gen_fake_vcount() >> 8) & 0xff;
}

B LOAD_B_ff8209(void)
{
        return gen_fake_vcount() & 0xff;
}


UNDEF_L(ff8200)
IGNORE_S(ff8200)
IGNORE_S(ff8261)
IGNORE_S(ff8262)
IGNORE_S(ff8263)


extern void mfp_set_gpip_bit(unsigned char mask, unsigned char value) ;

void STORE_B_ff8260(B v)
{
  /* added effect on bit 7 of gpip */

/* TODO: understand how this works */
  if(v == 2) {
    if(gr_mode != MODE_MONO) {
      mfp_set_gpip_bit(0x80, 0x80);
    } else {
      mfp_set_gpip_bit(0x80, 0x00);
    }
  } else {
    if(gr_mode != MODE_MONO) {
      mfp_set_gpip_bit(0x80, 0x80);
    } else {
      mfp_set_gpip_bit(0x80, 0x00);
    }
  }

  shiftmod = v;
  SM_B(MEM(0xff8260),v);
#if 1
  ec_stderr( "Shiftmod set (pc=%lx, mode=%d)\n",(long)pc, v);
#endif
  ocr_screen_shifter();
}

void set_vbase (UL n)
{
  SM_B(MEM(0xff8201),(n>>16)&0xff);
  SM_B(MEM(0xff8203),(n>>8)&0xff);
#if STE
  SM_B(MEM(0xff820d),n&0xff);
#endif
  vbase = n;
}

void STORE_B_ff8201(B v)
{
  SM_B(MEM(0xff8201),v);
  vbase &= 0xff00ffff;
  vbase |= (v & 0xff)<<16;
#if 0
  ec_stderr("vbase modified from pc %lx (->%lx)\n",pc,vbase);
#endif
}

UNDEF_L(ff8202)
IGNORE_S(ff8202)

void STORE_B_ff8203(B v)
{
  SM_B(MEM(0xff8203),v);
  vbase &= 0xffff00ff;
  vbase |= (v & 0xff)<<8;
#if 0
  ec_stderr( "vbase modified from pc %lx (->%lx)\n",pc,vbase);
#endif
}

void STORE_B_ff820d(B v)
{
#if STE
  SM_B(MEM(0xff820d),v);
  vbase &= 0xffffff00;
  vbase |= (v & 0xff);
#else
  UNUSED(v);
#endif
}

B LOAD_B_ff820d(void)
{
  return (B) 0xff;
}

void STORE_B_ff820a(B v)
{
#if 0
        char *n;
        /* just for fun... */
        switch (v & 3)
        {
        case 0: n = "STemu, 60Hz, internal sync."; break;
        case 1: n = "STemu, 60Hz, external sync."; break;
        case 2: n = "STemu, 50Hz, internal sync."; break;
        case 3: n = "STemu, 50Hz, external sync."; break;
        }
        set_window_name (n);
#else
        UNUSED(v);
#endif
}





/****************************************************
 *
 * ???
 *
 ****************************************************/


B LOAD_B_ff8920(void) {return 0;}
B LOAD_B_ff8910(void) {return 0;}
B LOAD_B_ff8900(void) {return 0;}
B LOAD_B_ff8921(void) {return 0;}
B LOAD_B_ff8911(void) {return 0;}
B LOAD_B_ff8901(void) {return 0;}
B LOAD_B_ff8922(void) {return 0;}
B LOAD_B_ff8912(void) {return 0;}
B LOAD_B_ff8902(void) {return 0;}
B LOAD_B_ff8923(void) {return 0;}
B LOAD_B_ff8913(void) {return 0;}
B LOAD_B_ff8903(void) {return 0;}
B LOAD_B_ff8924(void) {return 0;}
B LOAD_B_ff8904(void) {return 0;}
B LOAD_B_ff8925(void) {return 0;}
B LOAD_B_ff8905(void) {return 0;}
B LOAD_B_ff8906(void) {return 0;}
B LOAD_B_ff8907(void) {return 0;}
B LOAD_B_ff8908(void) {return 0;}
B LOAD_B_ff8909(void) {return 0;}
B LOAD_B_ff890a(void) {return 0;}
B LOAD_B_ff890b(void) {return 0;}
B LOAD_B_ff890c(void) {return 0;}
B LOAD_B_ff890d(void) {return 0;}
B LOAD_B_ff890e(void) {return 0;}
B LOAD_B_ff890f(void) {return 0;}



/****************************************************
 *
 * ??? 
 *
 ****************************************************/


IGNORE_S(fffc20)
IGNORE_S(fffc22)
IGNORE_S(fffc24)
IGNORE_S(fffc26)
IGNORE_S(fffc28)
IGNORE_S(fffc2a)
IGNORE_S(fffc2c)
IGNORE_S(fffc2e)
IGNORE_S(fffc30)
IGNORE_S(fffc32)
IGNORE_S(fffc34)
IGNORE_S(fffc36)
IGNORE_S(fffc38)
IGNORE_S(fffc3a)
IGNORE_S(fffc3c)
IGNORE_S(fffc3e)
UNDEF_L(fffc20)
UNDEF_L(fffc22)
UNDEF_L(fffc24)
UNDEF_L(fffc26)
UNDEF_L(fffc28)
UNDEF_L(fffc2a)
UNDEF_L(fffc2c)
UNDEF_L(fffc2e)
UNDEF_L(fffc30)
UNDEF_L(fffc32)
UNDEF_L(fffc34)
UNDEF_L(fffc36)
UNDEF_L(fffc38)
UNDEF_L(fffc3a)
UNDEF_L(fffc3c)
UNDEF_L(fffc3e)

/****************************************************
 *
 * electronic watch (Mega ST)
 *
 ****************************************************/
 
static int bank=0;      /* STONCDEBUG */

/* Normally, we would set the clock according to what's written to these
 * addresses. But since we use the Unix system clock, we don't want (and,
 * often, we can't) change it. 
 */

IGNORE_S(fffc21)
IGNORE_S(fffc23)
/* c25, c27 below */
IGNORE_S(fffc29)
IGNORE_S(fffc2b)
IGNORE_S(fffc2d)
IGNORE_S(fffc2f)
IGNORE_S(fffc31)
IGNORE_S(fffc33)
IGNORE_S(fffc37)
IGNORE_S(fffc39)
/* c3b below */
IGNORE_S(fffc3d)
IGNORE_S(fffc3f)

#define NIB(_x) ((B)(((_x) & 0x0f)|0xf0))
#define TG if (bank==1) return (B)0xff; time_gen();

/* save the time and date for later use */
static struct tm *tm;

static void time_gen (void)
{
        time_t tmp;
#if 0
        struct timeval tv;
        gettimeofday (&tv, NULL);
        tmp=tv.tv_sec;
#else
        tmp = time(NULL);
#endif
        tm = localtime (&tmp);
}

static int mode24=1;

void STORE_B_fffc35 (B v)
{
        if (bank == 1) mode24 = v & 1;
}

static B fake_am, fake_amz;

void STORE_B_fffc25 (B v)
{
        /* TOS uses this... */
        if (bank == 1) fake_am = NIB(v);
        /* else ignore */
}
void STORE_B_fffc27 (B v)
{
        if (bank == 1) fake_amz = NIB(v);
}


static B c3b;
void STORE_B_fffc3b (B v)
{
        bank = v & 1;   /* the other 2 bits are ignored */      
        c3b = NIB(v);
}

#define TFUNC(_addr,_ret) B LOAD_B_ ## _addr (void) {TG return NIB(_ret);}
TFUNC(fffc21,tm->tm_sec % 10)
TFUNC(fffc23,tm->tm_sec / 10)
TFUNC(fffc29,tm->tm_hour % 10)
TFUNC(fffc2d,tm->tm_wday)
TFUNC(fffc2f,tm->tm_mday % 10)
TFUNC(fffc31,tm->tm_mday / 10)
TFUNC(fffc33,(tm->tm_mon+1) % 10)
TFUNC(fffc35,(tm->tm_mon+1) / 10)
TFUNC(fffc37,tm->tm_year % 10)
TFUNC(fffc39,(tm->tm_year-80) / 10)     

B LOAD_B_fffc3b (void)
{
        return c3b;
}

B LOAD_B_fffc2b(void)
{
        TG 
        if (mode24) return tm->tm_hour / 10;
        else
        {
                return (1<<(tm->tm_hour == 0 || tm->tm_hour >= 13))
                                |((tm->tm_hour % 12)==0) || ((tm->tm_hour % 12)>=10);
        }
}

B LOAD_B_fffc25(void)
{
        if (bank == 1) return fake_am;
        time_gen();
        return NIB(tm->tm_min % 10);
}
B LOAD_B_fffc27(void)
{
        if (bank == 1) return fake_amz;
        time_gen();
        return NIB(tm->tm_min / 10);
}

B LOAD_B_fffc3d(void)
{
        return NIB(0);
}

UNDEF_L(fffc3f)


/* end of file */

