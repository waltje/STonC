/*
 * usart.c : Universal Serial Asynchronous Receiver & Transmitter
 *
 * Emulation of RS232 part of Atari ST MFP 68901
 *
 * (C) 1998,2001 Laurent Vogel - covered by the GPL (see file COPYING)
 */


/* set to 1 if using a real serial device file descriptor (like /dev/tty) */

#define USART_SERIAL_FD 0

/* 
 * Notes
 * -----
 *
 * The USART is modelled into two independant components, the Transmitter (tr) 
 * and the Receiver (rc). Both depend on mfp Timer D to be active. Characters 
 * are emitted or received one after another every bits_per_byte timer D 
 * periods. The bits_per_byte number counts every bit supposedly transmitted 
 * on the line, including start, parity and stop bits.
 *
 * Synchronous mode is not implemented.
 *
 * The loopback feature (transmitted bytes are immediately received) is not 
 * implemented.
 *
 * Transmitter
 * -----------
 *
 * Model : 
 *                +------+       +--------+
 * set udr  -->   | data |  -->  | buffer |  -->  transmitted to output file.
 *                +------+       +--------+
 *
 * Setting udr sets tr_data register. Bits in the buffer are supposed to be 
 * sent one after another every timer D event. This is modelled by saying
 * a byte in tr_buffer needs bits_per_byte events to be sent. We wait
 * for a delay of bits_per_byte times the timer D period. (waiting means
 * setting an alarm, and setting tr_alarm_on = 1.) When the alarm is 
 * triggered, the byte in tr_buffer is output, and then the transmitter 
 * considers whether there is any other byte to send.
 *
 * If no data was set during last byte transmission (indicated by 
 * tr_new_data == 0), tr_alarm_on is set to zero and no further
 * tr_alarm() is set, cancelling any further transmission. Otherwise, 
 * the next byte is transferred from tr_data to tr_buffer and another
 * tr_alarm() is set to happen after the delay bits_per_byte 
 * times the timer D period. 
 *
 * When the tr is being disabled, the transfer of the last byte completes 
 * before tr actually shutting down. This is indicated by flag tr_disabling.
 * 
 * If the timer D is stopped during a transfer, then the whole transmitter
 * is disabled.
 *
 * Receiver
 * --------
 *
 * Model :
 *                +------+       +---------------------+
 * get udr  <--   | data |  <--  | intermediate buffer |  <--  input file.
 *                +------+       +---------------------+
 *
 * An intermediate buffer holds input data not yet read by the USART. When
 * this buffer becomes empty, and there is no ready data in input file, the
 * receiver goes into an idle state, merely checking regularly the input 
 * file until more input data causes it to re-awake.
 *
 * When input data is present it gets copied into the rc_data register byte 
 * per byte every bits_per_byte timer D events. The current byte in rc_data 
 * is read via reading UDR. Exceptions occur when a byte is transferred from 
 * buffer to register, indicating that fresh data has arrived, or failure to
 * read previous data in time (overrunning).
 *
 * Unlike the transmitter which waits before outputting bytes, input bytes 
 * are read before waiting. This means that the receiver must wait one byte 
 * time period before checking input bytes as it becomes enabled.
 * 
 *
 * Remarks
 * -------
 *
 * - Bytes are ANDed with byte_mask to cast them to the specified number
 *   of meaningful bits (between 5 and 8). There are no frame or parity 
 *   errors. 
 *
 * - the individual Timer D event are not accounted one by one. When the 
 *   timer D is set, this notified to the usart along with the current 
 *   timer D period. Then the transmitter and receiver set their own alarms 
 *   to wait for bits_per_byte number of timer D periods.
 * 
 * - I don't know what normally happens when modifying timer D when 
 *   the usart is on. What I implement here is:
 *   If the timer D period changes during transfer, nothing happens until
 *   the next byte to send or receive.
 *   If the timer D stops during transfer, then the receiver and transmitter
 *   are disabled.
 *
 * Todo
 * ----
 * 
 * Better interface with a real serial device. propagate configuration,
 * and send breaks. What do we do with DCD/RTS/CTS ?
 * check this.
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#if USART_SERIAL_FD
# include <sys/types.h>
# include <fcntl.h>
# include <termios.h>
# include <unistd.h>
#endif

#include "emulc.h"
#include "vtime.h"
#include "mfp.h"
#include "usart.h"
#include "utils.h"

/* 
 * usart internal variables 
 */

/* general stuff */
static int bits_per_byte;
static unsigned char byte_mask;
static int loopback_flag;
static int sync_mode_flag;
static unsigned char usart_scr;
static unsigned char usart_ucr;

#if USART_SERIAL_FD
static int serial_fd = -1;
extern char *serial_dev;
char *serial_dev=NULL;
static struct termios tios_save;
#endif

/* 0 if timer D off */
static double timer_d_period;

/* transmitter stuff */
static unsigned char tr_buffer;
static unsigned char tr_data;
static int tr_new_data;
static int tr_enabled;
static int tr_disabling;
static unsigned char usart_tsr;
static int tr_alarm_on;

/* receiver stuff */
static unsigned char rc_data;
static int rc_enabled;
static int rc_idle;
static int rc_data_full;
static unsigned char usart_rsr;
static int rc_alarm_on;
static double rc_idle_delay = 0.05;

#include "emulc.h"

extern Term serial_term;

/* 
 * rc_buffer: simple-minded intermediate input buffer 
 */

#define RC_BUF_SIZE 256 

static char rc_buffer[RC_BUF_SIZE];
static int rc_buf_index = 0, rc_buf_size = 0;

static int rc_data_present(void)
{
  if(rc_buf_index < rc_buf_size) {
    return 1;
  } else {
    /* attempt to read next bytes from file */
    rc_buf_index = 0;

#if USART_SERIAL_FD
    if(serial_fd == -1)
      return 0;
    rc_buf_size = read(serial_fd, rc_buffer, RC_BUF_SIZE);

    if( rc_buf_size > 0 ) {
      return 1;
    } else {
      return 0;
    }
#else
    {
      int c;
      c = te_get_char(serial_term);
      if(c == -1) {
        rc_buf_size = 0;
        return 0;
      } else {
        rc_buffer[0] = c;
        rc_buf_size = 1;
        return 1;
      }
    }
#endif
  }
}

static char rc_get_new_data(void)
{
  char c;
  assert(rc_buf_index < rc_buf_size);
  c = rc_buffer[rc_buf_index++];
  /*
   * if(c == 1) { 
   *   tcsetattr(serial_fd, TCSANOW, &tios_save);
   *   exit(0);
   * }
   */

#if 0
  ec_stderr, "rc_get_new_data -> 0x%02x (%c)\n", c, c<32?' ':c);
#endif

  return c;
}


/*
 * link with memory registers 
 */

#if 0
#define D_MEM_LINK(adr,reg) \
  unsigned char usart_get_ ## reg (void); \
  unsigned char LOAD_B_ ## adr (void) { \
    unsigned char v = usart_get_ ## reg(); \
    ec_stderr( "0x%08lx -> 0x%02x\n", (long)0x ## adr, v); \
    return v; \
  } \
  void usart_set_ ## reg (unsigned char v); \
  void STORE_B_ ## adr (unsigned char v) { \
    ec_stderr( "0x%08lx <- 0x%02x\n", (long)0x ## adr, v); \
    usart_set_ ## reg(v); \
  }
#else
#define D_MEM_LINK(_adr,_reg) \
  unsigned char usart_get_ ## _reg(void); \
  unsigned char LOAD_B_ ## _adr (void) { \
    unsigned char v = usart_get_ ## _reg(); \
    ec_stderr( "usart_" #_reg " -> 0x%02x\n", v); \
    return v; \
  } \
  void usart_set_ ## _reg (unsigned char v); \
  void STORE_B_ ## _adr (unsigned char v) { \
    ec_stderr( "usart_" #_reg " <- 0x%02x\n", v); \
    usart_set_ ## _reg(v); \
  }
#endif


#define MEM_LINK(adr,reg) \
  unsigned char usart_get_ ## reg (void); \
  unsigned char LOAD_B_ ## adr (void) { \
    return usart_get_ ## reg(); \
  } \
  void usart_set_ ## reg (unsigned char v); \
  void STORE_B_ ## adr (unsigned char v) { \
    usart_set_ ## reg(v); \
  }


MEM_LINK (fffa27, scr)
MEM_LINK (fffa29, ucr)
MEM_LINK (fffa2b, rsr)
MEM_LINK (fffa2d, tsr)
MEM_LINK (fffa2f, udr)

/* 
 * anything in fffa31 ??? 
 */

void STORE_B_fffa31(unsigned char val) {
  UNUSED(val);
}

unsigned char LOAD_B_fffa31(void) {
  return 0;
}


/* 
 * prototypes
 */

void usart_init(void);
void usart_reset(void);

/* called by the mfp to notify the state of the timer D */
void usart_start_timer_d(double period);
void usart_stop_timer_d(void);

unsigned char usart_get_scr(void);
unsigned char usart_get_ucr(void);
unsigned char usart_get_tsr(void);
unsigned char usart_get_rsr(void);
unsigned char usart_get_udr(void);

void usart_set_scr(unsigned char v);
void usart_set_ucr(unsigned char v);
void usart_set_tsr(unsigned char v);
void usart_set_rsr(unsigned char v);
void usart_set_udr(unsigned char v);

static void rc_alarm(void *dummy);
static void rc_idle_alarm(void *dummy);
static void enable_rc(void);
static void disable_rc(void);

static void tr_alarm(void *dummy);
static void enable_tr(void);
static void disable_tr(void);
static void write_serial(unsigned char c);


/*
 * general usart control
 */

void usart_start_timer_d(double period)
{
  if(period != timer_d_period) {
    if(timer_d_period != 0) {
      /* changing the period in the middle of a transfer */
      if(rc_alarm_on || tr_alarm_on) {
        /* should cause errors ?*/
        ec_stderr("changing timer D period while USART active\n");
      }
    } 
    timer_d_period = period;
  }
}

void usart_stop_timer_d(void)
{
  if(timer_d_period) {
    if(rc_alarm_on) {
      clear_alarm_by_func(rc_alarm);
      rc_alarm_on = 0;
    }
    if(tr_alarm_on) {
      clear_alarm_by_func(tr_alarm);
      tr_alarm_on = 0;
    }
  }
  timer_d_period = 0;
}


static void init_serial (void)
{
#if USART_SERIAL_FD
  if(serial_dev == NULL) {
    serial_fd = -1;
    return;
  }
  serial_fd = open (serial_dev, O_RDWR|O_NDELAY);
  if (serial_fd < 0) {
    char s[100];
    sprintf (s, "open %s", serial_dev);
    perror (s);
    exit(1);
  }
  {
    struct termios p;

    tcgetattr(serial_fd, &p);
    tcgetattr(serial_fd, &tios_save);
#if 0   /* TODO */
    cfmakeraw(&p);
#endif
    tcsetattr(serial_fd, TCSANOW, &p);
  }
#endif /* USART_SERIAL_FD */
}
 

void usart_init(void)
{
  /* initialise usart */
  timer_d_period = 0;
  init_serial();
  /* empty buffers */
  rc_buf_index = 0;
  rc_buf_size = 0;
  
  usart_reset();
}

void usart_reset(void)
{
  /* stop everything */
  rc_enabled = 0;
  tr_enabled = 0;
  tr_disabling = 0;
  rc_alarm_on = 0;
  tr_alarm_on = 0;
  clear_alarm(rc_idle_alarm, 0);
  clear_alarm_by_func(rc_alarm);
  clear_alarm_by_func(tr_alarm);
  /* default internal register values */
  rc_data = 0;
  rc_data_full = 0;
  tr_data = 0;
  tr_new_data = 0;
  tr_buffer = 0;
  /* default flags values */
  loopback_flag = 0;
  sync_mode_flag = 1;
  byte_mask = 0xFF;
  /* sync mode : the sync byte + the actual byte => twice the number of bits */
  bits_per_byte = 16;
  /* default register values */
  usart_scr = 0;
  usart_ucr = 0;
  usart_tsr = 0;
  usart_rsr = 0;
}


unsigned char usart_get_scr(void)
{
  return usart_scr;
}

void usart_set_scr(unsigned char v)
{
  usart_scr = v;
}

unsigned char usart_get_ucr(void)
{
  return usart_ucr;
}

void usart_set_ucr(unsigned char val)
{
  switch(val & USART_BITS_MASK) {
  case USART_8BITS:
    byte_mask = 0xFF;
    bits_per_byte = 8;
    break;
  case USART_7BITS:
    byte_mask = 0x7F;
    bits_per_byte = 7;
    break;
  case USART_6BITS:
    byte_mask = 0x3F;
    bits_per_byte = 6;
    break;
  case USART_5BITS:
    byte_mask = 0x1F;
    bits_per_byte = 5;
    break;
  }
  sync_mode_flag = 0;
  switch(val & USART_SYNC_MASK) {
  case USART_SYNCRO:
    /* funny mode where the bits are compared to the 'sync' 
       register to determine that the next byte is valid */
    sync_mode_flag = 1;
    break;
  case USART_11:
    bits_per_byte += 2;
    break;
  case USART_11H:
    /* treated like next case */
  case USART_12:
    bits_per_byte += 3;
    break;
  }
  if(! (val & USART_NO_PARITY)) {
    /* count the parity bit too */
    bits_per_byte += 1;
  } 

  if(sync_mode_flag) {
    /* the sync byte + the actual byte => twice the number of bits */
    bits_per_byte *= 2;
  }
  
  /* USART_DIV_MASK ignored */

  usart_ucr = val;
}


/* 
 * usart transmitter
 */

unsigned char usart_get_tsr(void)
{
  unsigned char result = usart_tsr;
  /* remove some informative flags ? */
  usart_tsr &= ~(TSR_UNDERRUN | TSR_END_TRAN | TSR_BUF_EMPT);
  return result;
}

void usart_set_tsr(unsigned char val)
{
  if((val & TSR_HIGH_BIT) && (val & TSR_LOW_BIT)) {
    loopback_flag = 1;
  } else {
    loopback_flag = 0;
  }

  val &= TSR_SET_MASK;

  if(val & TSR_TRANS_EN) {
    if(! tr_enabled ) {
      /* launch it in a clean state */
      usart_tsr = val;
      enable_tr();
    } else {
      usart_tsr &= ~TSR_SET_MASK;
      usart_tsr |= val;
      return;
    }
  } else {
    if( tr_enabled ) {
      /* terminate everything */
      usart_tsr &= ~TSR_SET_MASK;
      usart_tsr |= val;
      /* caution : we must still send the last byte. */
      disable_tr();
      return;
    } else {
      usart_tsr = val;
    }
  }
  /* here tr is enabled */
  if(usart_tsr & (TSR_HIGH_BIT | TSR_LOW_BIT)) {
    /* set immediately the value of tx pin => tr not available */
    if( tr_alarm_on ) {
      /* raise error ? */
      tr_alarm_on = 0;
      clear_alarm_by_func(tr_alarm);
    }
    if(tr_enabled)
      disable_tr();
  }

  if( (val & TSR_BREAK) && !sync_mode_flag) {
    /* stop current transfer if any */
    if(tr_alarm_on) {
      /* raise exception ?? */
      tr_alarm_on = 0;
      clear_alarm_by_func(tr_alarm);
    }
    /* watch carefully : we're sending a break ! */
    /* do nothing ?*/
    return;
  }
          
}

static void enable_tr(void)
{
  assert(!tr_enabled);
  /* self test ? */
  
  /* suppose no new data */
  tr_new_data = 0;
  tr_disabling = 0;
  tr_enabled = 1;
  usart_tsr |= TSR_TRANS_EN;
  tr_alarm_on = 0;
  clear_alarm_by_func(tr_alarm);
}

static void disable_tr(void)
{
  assert(tr_enabled);
  /* idle ? */
  if(tr_alarm_on == 0) {
    /* just stop */
    tr_enabled = 0;
    tr_disabling = 0;
    usart_tsr |= TSR_END_TRAN;
    usart_tsr &= ~TSR_TRANS_EN;
    if(usart_tsr & TSR_AUTO_TRN) {
      /* "auto-turnaround" : enable receiver */
      usart_set_rsr(usart_get_rsr() & RSR_REC_ENAB);
    }
  } else {
    tr_disabling = 1;
    /* tr_alarm() will check this, and call disable_tr again when
       current transfer is done. */
  }
}

static void write_serial(unsigned char c)
{
#if 0
 /* ec_stderr( "mfp write_serial(0x%02x)\n", c); */
  ec_stderr( "%c", c);
#endif

#if USART_SERIAL_FD
  if (serial_fd >= 0 && write (serial_fd, &c, 1) < 0) {
    char s[100];
    sprintf (s, "write %s", serial_dev);
    perror (s);
    return;
  }
#else
  te_output_char(serial_term, c);
#endif
}

void tr_alarm(void *dummy)
{
  UNUSED(dummy);
  assert(tr_alarm_on);
  assert(tr_enabled);
  if(tr_disabling) {
    /* tr was waiting for last transfer to be done. */
    disable_tr();
    return;
  }

  if(loopback_flag) {
    /* not implemented */
    return;
  }
  /* send previous byte */
  write_serial(tr_buffer);
  
  if(! tr_new_data) {
    /* underrun */
    usart_tsr |= TSR_UNDERRUN;
    /*  mfp_ask_interrupt(MFP_INT_SEND_ERROR); */
    tr_alarm_on = 0;
  } else {
    tr_new_data = 0;
    usart_tsr |= TSR_BUF_EMPT;
    mfp_ask_interrupt(MFP_INT_SEND_EMPTY); 
    tr_buffer = tr_data & byte_mask;
    set_alarm(bits_per_byte*timer_d_period, tr_alarm, NULL);
  }
}


void usart_set_udr(unsigned char val)
{
  if((! tr_enabled) || (tr_disabling)) {
    tr_new_data = 0;
  } else {
    if(tr_new_data) {
      tr_data = val;
      /* error ? */
    } else {
      if(tr_alarm_on) {
        tr_data = val;
              tr_new_data = 1;
      } else {
        tr_new_data = 0;
        tr_buffer = val & byte_mask;
        usart_tsr |= TSR_BUF_EMPT;
        mfp_ask_interrupt(MFP_INT_SEND_EMPTY); 
        tr_alarm_on = 1;
        set_alarm(bits_per_byte*timer_d_period, tr_alarm, NULL);
      }
    }
  }
}


/*
  usart receiver
*/

unsigned char usart_get_rsr(void) 
{
  unsigned char result = usart_rsr;
  usart_rsr &= (RSR_REC_ENAB | RSR_SYNC_STR);
  return result;
}

void usart_set_rsr(unsigned char val)
{
  if( val & RSR_REC_ENAB) {
    if(!rc_enabled) {
      usart_rsr = val & (RSR_REC_ENAB | RSR_SYNC_STR);
      enable_rc();
    } else {
      usart_rsr &= ~(RSR_REC_ENAB | RSR_SYNC_STR);
      usart_rsr |= val & (RSR_REC_ENAB | RSR_SYNC_STR);
    }
  } else {
    if(rc_enabled) {
      disable_rc();
    }
    usart_rsr = val & (RSR_REC_ENAB | RSR_SYNC_STR);
  }
}
        
unsigned char usart_get_udr(void) 
{
  rc_data_full = 0;
  return rc_data;
}

void rc_alarm(void *dummy) 
{
  UNUSED(dummy);
  assert(rc_enabled);
  assert(!rc_idle);
  assert(rc_alarm_on);
#if 0
ec_stderr( "usart_rc_alarm\n");
#endif
  if(! rc_data_present() ) {
    /* become idle */
#if 0
ec_stderr( "becoming idle\n");
#endif
    rc_idle = 1;
    set_alarm(rc_idle_delay, rc_idle_alarm, NULL);
    rc_alarm_on = 0;
  } else {
    if( rc_data_full) {
      /* instead of overrunning, retry later ? */
      set_alarm(bits_per_byte * timer_d_period, rc_alarm, NULL);
      return;

      /* overrun */
      usart_rsr &= ~RSR_BUF_FULL;
      usart_rsr |= RSR_OVERRUN;
#if 0
      ec_stderr( "mfp_ask_interrupt(MFP_INT_REC_ERROR);\n");
#endif    
      mfp_ask_interrupt(MFP_INT_REC_ERROR);
    } else {
      /* buffer full */
      usart_rsr |= RSR_BUF_FULL;
#if 0
      ec_stderr( "mfp_ask_interrupt(MFP_INT_REC_FULL);\n");
#endif
      mfp_ask_interrupt(MFP_INT_REC_FULL);
    }
    rc_data = rc_get_new_data() & byte_mask;
    rc_data_full = 1;
    /* new cycle again */
    set_alarm(bits_per_byte * timer_d_period, rc_alarm, NULL);
  }
}

static void rc_idle_alarm(void *dummy)
{
  UNUSED(dummy);
  
  assert(rc_enabled);
  assert(rc_idle);
  assert(!rc_alarm_on);
  
  if(rc_data_present()) {
    rc_idle = 0;
    rc_alarm_on = 1;
    rc_alarm(NULL);
  } else {
    set_alarm(rc_idle_delay, rc_idle_alarm, 0);
  }
}

/* functions called internally when rc status/control register set */
static void enable_rc(void)
{
  assert(!rc_enabled);
  /* self test ? */
  
  rc_enabled = 1;
  rc_data_full = 0;
  rc_idle = 0;
  rc_alarm_on = 1;
  set_alarm(bits_per_byte * timer_d_period, rc_alarm, NULL);
}

static void disable_rc(void)
{
  assert(rc_enabled);
  if(rc_idle) {
    clear_alarm(rc_idle_alarm, 0);
    rc_idle = 0;
  }
  rc_alarm_on = 0;
  rc_enabled = 0;
  /* ... */

}


