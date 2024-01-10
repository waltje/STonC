/* 
 * ikbd.c - device-independant implementation of the IKBD protocol
 *
 * Taken from STonX (C) 1994-1997 Marinos Yannikos & Martin D. Griffiths
 * Modified for STonC (C) 1998-2004 Laurent Vogel
 * Covered by the GPL version 2 or later; see COPYING for details
 */

#include "defs.h"
#include "mem.h"
#include "ikbd.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#include "fifo.h"

extern Fifo ikbd_acia_fifo;

#define KB_DEBUG 0

/* special codes sent by the IKBD: */
#define IKBD_STATUS             0xf6
#define IKBD_ABS_MOUSE  0xf7
#define IKBD_REL_MOUSE  0xf8
#define IKBD_TIMEOFDAY  0xfc
#define IKBD_BOTH_JOY   0xfd
#define IKBD_JOY0               0xfe
#define IKBD_JOY1               0xff

/* IKBD modes/state */
struct 
{
        unsigned
        int mouse_mode:2,
                btn_mode:1,
                btn_rep:2,
                joy_mode:3,
                data_on:1,
                y_at_top:1,
                mode:3;
} ikbd;

#define MODE_MOUSE_KEYCODE      0x0002
#define MODE_DATA_ON            0x0001
#define MODE_FIRE_BUTTON        3

#define JOY_OFF         0
#define JOY_FIRE        1
#define JOY_EVENT       2
#define JOY_INTERR      3
#define JOY_MONITOR     4

#define MOUSE_OFF       0
#define MOUSE_REL       1
#define MOUSE_ABS       2
#define MOUSE_KEY       3

#define BTN_DEFAULT     0
#define BTN_KEYS        1

#define STATUS_VALID (ikbd.joy_mode != JOY_FIRE && ikbd.joy_mode != JOY_MONITOR)
#define MAXARGS         8
#define MAXBUF          16383
static int mode, mousemode;
static int needed, argnum=0;
static int y_at_top = 1;
static int mktx, mkty;          /* mouse key threshold */
static int thresx, thresy;      /* mouse motion threshold */
static int ascalex, ascaley;/* absolute mode scale */
static int command;
static int args[MAXARGS];
#define GETW(_x) ((args[_x]<<8)+args[(_x)+1])
static int buffer[MAXBUF];
int ikbd_inbuf=0;
static int ikbd_bufpos=0;

int mouse_freeze=0;


void ikbd_send(int value)
{
#if KB_DEBUG
  ec_stderr("ikbd_send (0x%02x)\n", value & 0xff); 
#endif
  fifo_send(ikbd_acia_fifo, value & 0xFF);
}

static int btn[3];

static int ox=0, oy=0, px=0,py=0;

void ikbd_send_relmouse (void)
{
        ikbd_send (0xf8 | (btn[0]<<1) | btn[1]);
        ikbd_send (px-ox);
        ikbd_send (py-oy);
        ox = px;
        oy = py;
}

void ikbd_adjust (int dx, int dy)
{
        int tx=dx,ty=dy;

        while (dx < -128 || dx > 127 || dy < -128 || dx > 127)
        {
                if (dx < -128) tx=-128;
                else if (dx > 127) tx=127;
                if (dy < -128) ty=-128;
                else if (dy > 127) ty=127;

                if (ikbd.mouse_mode != MOUSE_OFF) {
                  ikbd_send (0xf8 | (btn[0]<<1) | btn[1]);
                  ikbd_send (tx);
                  ikbd_send (ty);
                }
                dx -= tx;
                dy -= ty;
        }
        if (dy != 0 || dx != 0)
        {
                if (ikbd.mouse_mode != MOUSE_OFF) {
                  ikbd_send (0xf8 | (btn[0]<<1) | btn[1]);
                  ikbd_send (dx);
                  ikbd_send (dy);
                }
        }
        ox=px;
        oy=py;
}

void ikbd_force(void)
{
        px = ox;
        py = ox;
        if (mouse_freeze) return;
        if (ikbd.mouse_mode == MOUSE_OFF) return;
        ikbd_send_relmouse();
}
void ikbd_button (int button, int pressed)
{
        btn[button-1] = pressed;
#if 0
        if (btn[0] == btn[1] && btn[1] == btn[2] && btn[2] == 1) exit(0);
#else
        if (btn[2]) exit(0);
#endif
        if (btn[2])
        {
                mouse_freeze = !mouse_freeze;
                if (!mouse_freeze)
                {
                        ox=px;
                        oy=py;
                }
                return;
        }
        if (mouse_freeze) return;
#if KB_DEBUG
        ec_stderr("IKBD sends button %d press (%d)\n",button,pressed);
#endif
        if (ikbd.mouse_mode == MOUSE_OFF) return;
        ikbd_send_relmouse();
}

void ikbd_pointer (int x, int y, int max_x, int max_y)
{
        px = x;
        py = y;
        if (mouse_freeze) return;
#if !NO_FLOODING
        if (ikbd.mouse_mode == MOUSE_OFF) return;
        ikbd_send_relmouse();
#endif
}

static void set_mouse_button_action (int action_mode)
{
        if (action_mode & 4)
                ikbd.btn_mode = BTN_KEYS;
        else
        {
                ikbd.btn_mode = BTN_DEFAULT;
                ikbd.btn_rep = action_mode & 3;
        }
}

static void set_abs_mouse (int xmax, int ymax)
{
}

static void set_mouse_keycode (int dx, int dy)
{
        ikbd.mouse_mode = MOUSE_KEY;
        mktx = dx;
        mkty = dy;
}

static void set_mouse_threshold (int x, int y)
{
        thresx = x;
        thresy = y;
}

static void set_mouse_scale (int x, int y)
{
        if (ikbd.mouse_mode != MOUSE_ABS) return;
        ascalex = x;
        ascaley = y;
}

static void load_mouse_pos (int sx, int sy)
{
}

static void set_joy_monitor (int rate)
{
}

static void set_joy_keycode (int rx, int ry, int tx, int ty, int vx, int vy)
{
}

static void clock_set (int YY, int MM, int DD, int hh, int mm, int ss)
{
        /* ignored */
}

static void memory_load (int address, int num, int *data)
{
}

static void memory_read (int address)
{
}

static void reset (void)
{
}

static void controller_execute (int address)
{
}

static void report_mouse_mode (void)
{
}

static void report_mouse_threshold (void)
{
}

static void report_mouse_scale (void)
{
}

static void report_mouse_y_at_top (void)
{
}

static void report_mouse_enable (void)
{
}

static void report_joystick_mode (void)
{
}

static void report_joystick_enable (void)
{
}

static void interrogate_mouse (void)
{
}

static void interrogate_joy (void)
{
}

static unsigned char int2bcd(int a)
{
  return (a % 10) + ((a / 10) << 4);
}

#include "time.h"
static void interrogate_clock (void)
{
  struct tm *tm;
  time_t tmp;

  tmp = time(NULL);
  tm = localtime (&tmp);

  ikbd_send( 0xfc);
  ikbd_send( int2bcd( tm->tm_year - 80 ) );
  ikbd_send( int2bcd( tm->tm_mon ));
  ikbd_send( int2bcd( tm->tm_mday ));
  ikbd_send( int2bcd( tm->tm_hour ));
  ikbd_send( int2bcd( tm->tm_min ));
  ikbd_send( int2bcd( tm->tm_sec ));

}

void ikbd_execute (int data)
{
        if (needed)     /* need more */
        {
          args[argnum++] = data;
          if (--needed == 0)
            {
              switch (command)
                {
                case 0x80:      if (args[0] == 1) reset(); break;
                case 0x07:      set_mouse_button_action (args[0]); break;
                case 0x09:      set_abs_mouse (GETW(0), GETW(2)); break;
                case 0x0a:      set_mouse_keycode (args[0], args[1]); break;
                case 0x0b:      set_mouse_threshold (args[0], args[1]); break;
                case 0x0c:      set_mouse_scale (args[0], args[1]); break;
                case 0x0e:      load_mouse_pos (GETW(1), GETW(3)); break;
                case 0x17:      set_joy_monitor (args[0]); break;
                case 0x19:      set_joy_keycode (args[0], args[1], args[2],
                                                 args[3], args[4], args[5]); break;
                case 0x1b:      clock_set (args[0], args[1], args[2], args[3],
                                           args[4], args[5]); break;
                case 0x20:      if (argnum < args[2]) needed += args[2];
                else memory_load (GETW(0), args[2], &(args[3]));
                break;
                case 0x21:      memory_read (GETW(0)); break;
                case 0x22:      controller_execute (GETW(0)); break;
                }
            }
          argnum = 0;
        }
        else /* a command starts */
        switch (command = data)
        {
                case 0x80:      needed = 1; break;
        
                /* set mouse button action */
                case 0x07:      needed = 1; break;

                /* set relative mouse positioning */
                case 0x08:      ikbd.mouse_mode = MOUSE_REL; break;

                /* set absolute mouse positioning */
                case 0x09:      needed = 4; break;

                /* set mouse keycode mode */
                case 0x0a:      needed = 2; break;

                /* status inquiry for the above */
                case 0x88:      
                case 0x89:
                case 0x8a:      if (STATUS_VALID) report_mouse_mode(); break;

                /* set mouse threshold */
                case 0x0b:      needed = 2; break;
                case 0x8b:      if (STATUS_VALID) report_mouse_threshold(); break;

                /* set mouse scale */
                case 0x0c:      needed = 2; break;
                case 0x8c:      if (STATUS_VALID) report_mouse_scale(); break;

                /* interrogate mouse position */
                case 0x0d:      interrogate_mouse (); break;

                /* load mouse position */
                case 0x0e:      needed = 5; break;

                /* set y=0 at bottom */
                case 0x0f:      ikbd.y_at_top = 0; break;

                /* set y=0 at top */
                case 0x10:      ikbd.y_at_top = 1; break;
                case 0x8f:      
                case 0x90:      if (STATUS_VALID) report_mouse_y_at_top (); break;

                /* resume */
                case 0x11:      ikbd.data_on = 1; break;

                /* disable mouse */
                case 0x12:      ikbd.mouse_mode = MOUSE_OFF; break;
                case 0x92:      if (STATUS_VALID) report_mouse_enable(); break;

                /* pause output */
                case 0x13:      ikbd.data_on = 0; break;

                /* set joystick event reporting */
                case 0x14:      ikbd.joy_mode = JOY_EVENT; break;

                /* set joystick interrogation mode */
                case 0x15:      ikbd.joy_mode = JOY_INTERR; break;

                /* joystick interrogation */
                case 0x16:      interrogate_joy(); break;

                /* set joystick monitoring */
                case 0x17:      needed = 1; break;

                /* set fire button monitoring */
                case 0x18:      ikbd.joy_mode = JOY_FIRE; break;

                /* set joystick keycode mode */
                case 0x19:      needed = 6; break;

                case 0x94:
                case 0x95:
                case 0x99: if (STATUS_VALID) report_joystick_mode(); break;

                /* disable joysticks */
                case 0x1a:      ikbd.joy_mode = JOY_OFF; break;
                case 0x9a:      if (STATUS_VALID) report_joystick_enable(); break;

                /* time-of-day clock set (ignored) */
                case 0x1b:      needed = 6; break;

                /* interrogate time-of-day clock */
                case 0x1c:      interrogate_clock(); break;

                /* memory load (will increase `needed' later) */
                case 0x20:      needed = 3; break; 

                /* memory read */
                case 0x21:      needed = 2; break;

                /* controller execute */
                case 0x22:      needed = 2; break;
        }
}

void init_ikbd(void)
{       
        SM_UB(MEM(0xfffc00),0x0e);
}

/* called when a byte is sent to the IKBD */
void ikbd_send_byte (char v)
{
#if KB_DEBUG
        ec_stderr("Sending 0x%x to the IKBD\n",(int)v&0xff);
#endif
        if (v == 22) {
                ikbd_send(0xfe);
                ikbd_send(0);
        }
        ikbd_execute((B)v);
}
