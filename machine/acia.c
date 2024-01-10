/*
 * acia.c - emulation of ATARI ST ACIA 6850
 *
 * Part of STonC (C) 1998-2003 Laurent Vogel
 * Covered by the GPL version 2 or later; see COPYING for details
 */

/*
 * ACIA 6850 documentation:
 *
 * Asynchronous Communications Interface Adapter
 *
 * registers
 * ---------
 *
 * rdr receiver data register
 * cr  control register
 *   CR7: rc_irq_enable, 1 when enabled
 *   CR6,5: RTS output, send break and tr_irq_enable
 *   CR4-2: word length, parity, number of stop bits
 *   CR1,0: frequency divisor and master reset.
 * tdr transmitter data register
 * sr  status register
 *   SR7: 1 when interrupt request
 *   SR6: 1 on parity error  (a)
 *   SR5: 1 on overrun error
 *   SR4: 1 on framing error (a)
 *   SR3: CTS input (b)
 *   SR2: DCD input: (b) 0 = carrier present, 1 = lost carrier
 *   SR1: TDR Enable (0 when tdr has not yet been copied into the 
 *            shift register, 1 when it is time to write TDR.)
 *   SR0: 1 when RDR Full ?
 *      
 * (a) : not emulated
 * (b) : not wired on the atari ST.
 *
 * implementation
 * -------------- 
 *
 * tr_data holds the character currently being sent, when tr_busy is 1.
 * rc_busy is 1 when spending time between opportunities for byte reception.
 *
 * on reception of a char, the char is immediately copied in RDR.
 * rc_busy is set to 1, disabling the receiver for a while.
 * The alarm rc_alarm is set to clear rc_busy after some delay. 
 * If rdr_full is 1, then the overrun condition is flagged. 
 * rdr_full is set to 1. reading rdr clears rdr_full (SR0) and overrun. 
 * 
 * rc_alarm is also set when resetting the ACIA. rc_alarm means :
 * "I can't receive chars too fast. This is why I must delay. 
 * However I delay after receiving chars because on the other hand 
 * I decided to delay before sending chars. If I keep this convention
 * I do not delay twice."
 * 
 * When writing a char in tdr, TDR is said full (TDRE = 0). If a char is
 * currently being transmitted (tr_busy == 1), then nothing happens.
 * otherwise, TDR is copied to tr_data, tr_busy is set to 1 and an
 * alarm is set to simulate bit-by-bit transmission. TDR enable is set to 
 * one and possibly an interrupt occurs.
 * 
 * When the tr_alarm is spent, tr_data is output and tr_busy cleared. 
 * If TDR is full, then the next tranfer occurs as above.
 * 
 * Interrupts are set by setting irq = 1, and calling acias_update_irq().
 * This function will modify the relevant input in the MFP.
 * 
 * communication
 * -------------
 *
 * the acia has an input and an output.
 * The acia calls the output directly to send bytes.
 * The acia must ask the input for the oldest char not received yet.
 * The input can return -1, meaning no current byte available.
 * In this case, the input will call later the acia using 
 * acia_notify_input() to tell acia that new input has arrived.
 * 
 * This interface makes it possible to connect acia to a fifo as input,
 * and a terminal as output.
 */

/* 
 * TODO:
 * - carefully check cstate changes and make sure that there is no dead end.
 * - check that overrun is correctly implemented
 * - allow the acia to be valid even if not master reset
 * - debug prints
 */

#include <stdio.h>
#include <stdlib.h>
#include "emulc.h"
#include "vtime.h"
#include "acia.h"
#include "defs.h"
#include "fifo.h"
#include "ikbd.h"

Acia ikbd_acia, midi_acia;

B LOAD_B_fffc00(void)
{
  return acia_get_sr(ikbd_acia);
}
B LOAD_B_fffc02(void)
{
  return acia_get_rdr(ikbd_acia);
}
B LOAD_B_fffc04(void)
{
  return acia_get_sr(midi_acia);
}
B LOAD_B_fffc06(void)
{
  return acia_get_rdr(midi_acia);
}

void STORE_B_fffc00(B v)
{
  acia_set_cr(ikbd_acia, v);
}
void STORE_B_fffc02(B v)
{
  acia_set_tdr(ikbd_acia, v);
}
void STORE_B_fffc04(B v)
{
  acia_set_cr(midi_acia, v);
}
void STORE_B_fffc06(B v)
{
  acia_set_tdr(midi_acia, v);
}

static void my_ikbd_send_byte(void *dummy, char v)
{
  (void)dummy;
  ikbd_send_byte(v);
}

Fifo ikbd_acia_fifo;

void acias_init(void)
{
  ikbd_acia = acia_new();
  if (ikbd_acia == NULL) ec_fatal("acias_init()");
  
  midi_acia = acia_new();
  if (midi_acia == NULL) ec_fatal("acias_init()");

  ikbd_acia_fifo = fifo_new((void *)ikbd_acia, acia_notify_input);
  if (ikbd_acia_fifo == NULL) ec_fatal("acias_init()");

  acia_set_output(ikbd_acia, my_ikbd_send_byte, NULL);
  acia_set_input(ikbd_acia, fifo_get_char_void, (void *) ikbd_acia_fifo);
}


struct acia {
  unsigned char rdr, tdr ;
  unsigned char tr_data ;
  int tie, rie ;        /* tr and rc interrupt enable, from CR */
  int tr_busy, rc_busy;   /* state of the alarms */
  int rdrf, tdre, overrun, irq ; /* meaningful parts of SR */
  int bits_per_byte ;         /* extracted from CR */  
  unsigned char byte_mask ;   /* extracted from CR */
  double period ;             /* extracted from CR */           
  int valid;          /* valid = 0 when never reset */
  int (*input_func)(void *);
  void *input_obj;
  void (*output_func)(void *, char);
  void *output_obj;
} ;

/* 
 * private prototypes
 */

static void acia_rc_alarm(void *Acia_a);
static void acia_tr_alarm(void *Acia_a);
static void acia_start_tr(Acia a);
static void acias_update_irq(void);
static void acia_reset(Acia a);
static void acia_check_irq(Acia a);



/* both acias irq lines are wired to the same input in the mfp */

extern void mfp_set_gpip_bit(unsigned char mask, unsigned char value);

static void acias_update_irq(void)
{
  static int old_irq = 2;
  int irq = ikbd_acia->irq | midi_acia->irq;

  /* TODO: this way or the other way (irq or irq*) ? */
  if (irq != old_irq) {
    if (irq) {
      /* ec_stderr("mfp_set_gpip_bit(0x10, 0x00)\n"); */
      mfp_set_gpip_bit(0x10, 0x00);
    } else {
      /* ec_stderr("mfp_set_gpip_bit(0x10, 0x10)\n"); */
      mfp_set_gpip_bit(0x10, 0x10);
    }
  }
  old_irq = irq;
}

          
void acia_set_input(Acia a, int (*input_func)(void *), void *input_obj)
{
  a->input_func = input_func;
  a->input_obj = input_obj;
  if(a->valid && ! a->rc_busy) {
    a->rc_busy = 1;
    set_alarm(a->bits_per_byte * a->period, acia_rc_alarm, (void *) a);
  }
}


void acia_set_output(Acia a, void (*output_func)(void *, char), 
        void *output_obj)
{
  a->output_func = output_func;
  a->output_obj = output_obj;
  if(a->tr_busy) {
    a->tr_data = 0;
  }
}

int acia_null_input(void *dummy) 
{
  (void) dummy;
  return -1;
}

void acia_null_output(void *dummy, char c)
{
  (void) dummy;
  (void) c;
}

Acia acia_new(void)
{
  Acia a = malloc(sizeof(*a));
  if(a == NULL) {
    ec_stderr("no memory for acia_new()\n");
    return NULL;
  }
  a->valid = 0;
  a->input_func = acia_null_input;
  a->input_obj = NULL;
  a->output_func = acia_null_output;
  a->output_obj = NULL;
  a->irq = 0;
  return a;
}

static void acia_reset(Acia a)
{
  a->irq = 0 ;
  clear_alarm(acia_rc_alarm, (void *) a);
  a->tie = 0;
  a->rie = 0;
  a->overrun = 0;
  a->rdrf = 0;
  a->tdre = 1;
  a->irq = 0;
  a->period = 0.000002 ;  /* 500 Mhz, divided by 1 */
  a->bits_per_byte = 11 ;  /* 7 bit, even parity, 2 stop bits */
  a->byte_mask = 0x7F ;
  a->rc_busy = 1;
  set_alarm(a->bits_per_byte * a->period, acia_rc_alarm, (void *) a);
  a->valid = 1;
  acias_update_irq();
}

/* update SR and possibly irq */
static void acia_check_irq(Acia a)
{
  if((a->rie && (a->rdrf || a->overrun)) || (a->tie && a->tdre)) {
    a->irq = 1;
    acias_update_irq();
  }
}

unsigned char acia_get_sr(Acia a) 
{
  unsigned char v ;
  if(!a->valid) {
    v = 0 ;
  } else {
    v = a->rdrf | (a->tdre<<1) | (a->overrun<<5) | (a->irq<<7) ;
  }
  /* ec_stderr("acia_get_sr() -> 0x%02x\n", v); */
  return v;
}
  
void acia_set_cr(Acia a, unsigned char val)
{

  /* ec_stderr("acia_set_cr(0x%02x)\n", val); */

  if( (val & 0x3) == 3) {
    /* master reset*/
    acia_reset(a) ;
    /* TODO: return ? */
  } else if(!a->valid) {
    /*
    return ;
    */
    acia_reset(a);
    /* TODO: null to to master reset the acia. */
  }
  switch(val & 3) {
  case 0:
    a->period = 0.000002 ;
    break ;
  case 1:
    a->period = 0.000002 * 16 ;
    break ;
  case 2:
    a->period = 0.000002 * 64 ;
    break ;
  }
  switch( (val & 0x1C)>>2) {
  case 0:       /* 7 bit, even parity, 2 stop bits */
  case 1:       /* 7 bit, odd parity, 2 stop bits */
    a->byte_mask = 0x7F ;
    a->bits_per_byte = 10 ;
    break ;
  case 2:       /* 7 bit, even parity, 1 stop bit */
  case 3:       /* 7 bit, odd parity, 1 stop bit */
    a->byte_mask = 0x7F ;
    a->bits_per_byte = 9 ;
    break ;
  case 4:       /* 8 bit, no parity, 2 stop bits */
  case 6:       /* 8 bit, even parity, 1 stop bits */
  case 7:       /* 8 bit, odd parity, 1 stop bits */
    a->byte_mask = 0xFF ;
    a->bits_per_byte = 10 ;
    break ;
  case 5:       /* 8 bit, no parity, 1 stop bit */
    a->byte_mask = 0xFF ;
    a->bits_per_byte = 9 ;
    break ;
  }
  if( (val & 0x60) == 0x20)  {
    a->tie = 1 ;
  } else {
    if( (val & 0x60) == 0x60) {
      /* TODO: send break ?? */
    }
    a->tie = 0 ;
  }
  if( val & 0x80) {
    a->rie = 1 ;
  } else {
    a->rie = 0 ;
  }
  /* I do not know precisely what happens when modifying CR when busy 
   * In doubt, go to a clean state :
   */
  clear_alarm(acia_rc_alarm, (void *)a);
  clear_alarm(acia_tr_alarm, (void *)a);
  a->rc_busy = 1;
  set_alarm(a->bits_per_byte * a->period, acia_rc_alarm, (void *)a);
  a->tr_busy = 0;
  a->tdre = 1;
  acia_check_irq(a);
}

void acia_set_tdr(Acia a, unsigned char val)
{
  if(!a->valid)
    return ;
  a->tdr = val;
  a->tdre = 0;
  if(!a->tr_busy) {
    acia_start_tr(a);
  }
  if(a->irq) {
    a->irq = 0;
    acias_update_irq();
  }
}

static void acia_start_tr(Acia a)
{
  assert(a->valid && !a->tr_busy);
  a->tr_busy = 1;
  a->tdre = 1;
  a->tr_data = a->tdr & a->byte_mask;
  set_alarm(a->bits_per_byte * a->period, acia_tr_alarm, (void *)a);
  /* TODO acia_check_irq(a); ? */
}

unsigned char acia_get_rdr(Acia a)
{
  if(!a->valid) {
    ec_stderr("acia_get_rdr while acia not valid\n");
    return 0;
  }
  a->rdrf = 0;

  /* check that this is how it works ? */
  a->overrun = 0;
  if(a->irq) {
    a->irq = 0;
    acias_update_irq();
  }
  /* ec_stderr("acia_get_rdr() -> 0x%02x\n", (unsigned) a->rdr); */
  return a->rdr ;
}

/* called from outside when input is available */
void acia_notify_input(void * Acia_a)
{
  Acia a = (Acia) Acia_a;
  if(a->rc_busy) {
    /* acia_rc_alarm will check */
    return;
  }
  /* else call acia_rc_alarm directly */
  a->rc_busy = 1;
  acia_rc_alarm(Acia_a);
}

static void acia_rc_alarm(void *Acia_a)
{
  Acia a = (Acia) Acia_a;
  int c;
  
  if(!a->rc_busy) {
    ec_stderr("acia_rc_alarm when rc not busy\n");
    return;
  }
  a->rc_busy = 0;
  
  c = a->input_func(a->input_obj);

  /* ec_stderr("acia_rc_alarm() input c=0x%02x\n",c); */
  if(c == -1) {
    /* no incoming char */
    return;
  }
  a->rdr = c & a->byte_mask;
  if(a->rdrf) {
    a->overrun = 1;
  }
  a->rdrf = 1;
  acia_check_irq(a);
  
  a->rc_busy = 1;
  set_alarm(a->bits_per_byte * a->period, acia_rc_alarm, (void *)a);
}

static void acia_tr_alarm(void *Acia_a)
{
  Acia a = (Acia) Acia_a;

  if(!a->tr_busy) {
    ec_stderr("acia_tr_alarm when tr not busy\n");
    return;
  }
  a->tr_busy = 0;
  
  a->output_func(a->output_obj, a->tr_data);
  
  if(a->tdre) {
    /* nothing else to send */
    return;
  }
  acia_start_tr(a);
}
        
