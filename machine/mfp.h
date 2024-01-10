/*
 * mfp.h - Atari ST Multi-Function Peripheral MFP 68901
 *
 * Limited implementation of interrupt handling and timers
 * (The RS232 part is done independently in usart.c) 
 *
 * Part of STonC (C) 1998-2002 Laurent Vogel
 * Covered by the GPL version 2 or later; see COPYING for details
 */

/* called by peripherals to emulate the various INTR* junction between
 * peripherals and MFP 
 */
extern void mfp_set_gpip_bit(unsigned char mask, unsigned char value);

/* called by the cpu (reset interuction) */
void mfp_reset(void);

/* initialize the mfp. Will also initialize the usart.*/
void mfp_init(void);


#define MFP_TIMER_STOP     0x0
#define MFP_TIMER_DIV4     0x1
#define MFP_TIMER_DIV10    0x2
#define MFP_TIMER_DIV16    0x3
#define MFP_TIMER_DIV50    0x4
#define MFP_TIMER_DIV64    0x5
#define MFP_TIMER_DIV100   0x6
#define MFP_TIMER_DIV200   0x7
#define MFP_TIMER_COUNT    0x8
#define MFP_TIMER_PULSE    0x8

#define MFP_TIMERS_FREQ    2457600.0    /* hertz */
#define TIMER_A_PERIOD  (1.0 / MFP_TIMERS_FREQ)
#define TIMER_B_PERIOD  (1.0 / MFP_TIMERS_FREQ)
#define TIMER_C_PERIOD  (1.0 / MFP_TIMERS_FREQ)
#define TIMER_D_PERIOD  (1.0 / MFP_TIMERS_FREQ)


#define MFP_GPIP_MONO       0x80        /* monochrome monitor detect */
#define MFP_GPIP_RS232_RING 0x40        /* RS232 Ring indicator */
#define MFP_GPIP_FDC_DMA    0x20        /* FDC/DMA interrupt */
#define MFP_GPIP_KBD_MIDI   0x10        /* keyboard/MIDI interrupt */
#define MFP_GPIP_BLITTER    0x08        /* blitter ? */
#define MFP_GPIP_RS232_CTS  0x04        /* RS232 Clear To Send */
#define MFP_GPIP_RS232_CR   0x02        /* RS232 Carrier Detect */
#define MFP_GPIP_CENTRONICS 0x01        /* Centronics busy */

#define MFP_IERA_MONO       0x80        /* monochrome monitor detect */
#define MFP_IERA_RS232_RING 0x40        /* RS232 Ring indicator */
#define MFP_IERA_TIMERA     0x20        /* Timer A (STe/TT sound) */
#define MFP_IERA_REC_FULL   0x10        /* Receive buffer full */
#define MFP_IERA_REC_EMPTY  0x08        /* Receive buffer empty */
#define MFP_IERA_SEND_EMPTY 0x04        /* Sender buffer empty */
#define MFP_IERA_SEND_ERROR 0x02        /* Sender error */
#define MFP_IERA_TIMERB     0x01        /* Timer B (HBL ?) */

#define MFP_IERB_FDC_DMA    0x80        /* FDC/DMA interrupt */
#define MFP_IERB_KBD_MIDI   0x40        /* keyboard/MIDI interrupt */
#define MFP_IERB_TIMERC     0x20        /* Timer C (200 Hz clock) */
#define MFP_IERB_TIMERD     0x10        /* Timer D (USART) */
#define MFP_IERB_BLITTER    0x08        /* blitter */
#define MFP_IERB_RS232_CTS  0x04        /* RS232 Clear To Send */
#define MFP_IERB_RS232_CR   0x02        /* RS232 Carrier Detect */
#define MFP_IERB_CENTRONICS 0x01        /* Centronics busy */

/* mfp interrupt levels */

#define MFP_INT_MONO        15  /* monochrome monitor detect */
#define MFP_INT_RS232_RING  14  /* RS232 Ring indicator */
#define MFP_INT_TIMERA      13  /* Timer A (STe/TT sound) */
#define MFP_INT_REC_FULL    12  /* Receive buffer full */
#define MFP_INT_REC_ERROR   11  /* Receive error */
#define MFP_INT_SEND_EMPTY  10  /* Sender buffer empty */
#define MFP_INT_SEND_ERROR   9  /* Sender error */
#define MFP_INT_TIMERB       8  /* Timer B */
#define MFP_INT_FDC_DMA      7  /* FDC/DMA interrupt */
#define MFP_INT_KBD_MIDI     6  /* keyboard/MIDI interrupt */
#define MFP_INT_TIMERC       5  /* Timer C (200 Hz clock) */
#define MFP_INT_TIMERD       4  /* Timer D (USART) */
#define MFP_INT_BLITTER      3  /* blitter */
#define MFP_INT_RS232_CTS    2  /* RS232 Clear To Send */
#define MFP_INT_RS232_CR     1  /* RS232 Carrier Detect */
#define MFP_INT_CENTRONICS   0  /* Centronics busy */   


/* called by MFP's clients to request an interrupt */
void mfp_ask_interrupt(int int_level);

/* called by the cpu when flags & F_MFP */
int mfp_do_interrupt(void);

