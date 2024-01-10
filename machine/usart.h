/*
 * usart.h : Universal Serial Asynchronous Receiver & Transmitter
 *
 * Emulation of RS232 part of Atari ST MFP 68901
 *
 * (C) 1998-2001 Laurent Vogel - covered by the GPL (see file COPYING)
 */

#define TSR_BUF_EMPT  0x80      /* buffer empty */
#define TSR_UNDERRUN  0x40      /* underrun error */
#define TSR_AUTO_TRN  0x20      /* auto turnaround */
#define TSR_END_TRAN  0x10      /* end of transmission */
#define TSR_BREAK     0x08      /* break */
#define TSR_HIGH_BIT  0x04      /* high bit */
#define TSR_LOW_BIT   0x02      /* low bit */
#define TSR_TRANS_EN  0x01      /* transmitter enable */

#define TSR_SET_MASK  0x27

#define RSR_BUF_FULL  0x80      /* buffer full */
#define RSR_OVERRUN   0x40      /* overrun error */
#define RSR_PARITY    0x20      /* parity error */
#define RSR_FRAME     0x10      /* frame error */
#define RSR_SRCH_BRK  0x08      /* search/break error */
#define RSR_MATCH     0x04      /* Match/chraracter in progress */
#define RSR_SYNC_STR  0x02      /* synchronous strip enable */
#define RSR_REC_ENAB  0x01      /* receiver enable bit */

#define RSR_SET_MASK  0x03

#define USART_DIV_MASK  0x80
#define USART_DIV64  0x80       ??
#define USART_DIV16  0x00       ??

#define USART_BITS_MASK 0x60
#define USART_8BITS  0x00
#define USART_7BITS  0x20
#define USART_6BITS  0x40
#define USART_5BITS  0x60

#define USART_SYNC_MASK 0x18
#define USART_SYNCRO 0x00               /* synchronous */
#define USART_11     0x08               /* 1 start, 1 stop */
#define USART_11H    0x10               /* 1 start, 1 & half stop */
#define USART_12     0x18               /* 1 start, 2 stop */

#define USART_PAR_MASK 0x04
#define USART_EVEN   0x00
#define USART_ODD    0x04
#define USART_NO_PARITY 0x02

/* initialise private variables */
void usart_init(void) ;

/* reset usart part of mfp (called when resetting mfp) */
void usart_reset(void) ;

/* called by the mfp to notify the state of the timer D */
void usart_start_timer_d(double period);
void usart_stop_timer_d(void);


