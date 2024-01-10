/* 
 * audio.c - extremely limited implementation
 *
 * Taken from STonX (C) 1994-1997 Marinos Yannikos & Martin D. Griffiths
 * Modified for STonC (C) 1998-2002 Laurent Vogel
 * Covered by the GPL version 2 or later; see COPYING for details
 */

#include "mem.h"
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "io.h"  /* write_parallel() */


#define DEBUG_SND 0


extern int snd_porta;   /* defined in fdc.c */

typedef struct 
{       unsigned int finetune;
        unsigned int crsetune;
        unsigned int amplitude;
} YM_Voice;

unsigned int YM_select;

struct Snd
{               
        YM_Voice YM_ChannelA; 
        YM_Voice YM_ChannelB; 
        YM_Voice YM_ChannelC; 
        unsigned int YM_NoiseControl;
        unsigned int YM_MixerControl;
        unsigned int YM_Envelope_fine_period;
        unsigned int YM_Envelope_crse_period;
        unsigned int YM_Envelope_shape;
        unsigned int IO_PortA;
        unsigned int IO_PortB;
        unsigned char YM_flag;
        unsigned char Server_Exit; 
} Snd;


/*
 * Hardware Register emulation functions 
 */ 
  
B LOAD_B_ff8800(void) 
{       
        switch (YM_select)
        {       case 0:  
                        return Snd.YM_ChannelA.finetune;
                case 1:
                        return Snd.YM_ChannelA.crsetune;
                case 2:  
                        return Snd.YM_ChannelB.finetune;
                case 3:
                        return Snd.YM_ChannelB.crsetune;
                case 4:  
                        return Snd.YM_ChannelC.finetune;
                case 5:
                        return Snd.YM_ChannelC.crsetune;
                case 6:
                        return Snd.YM_NoiseControl;
                case 7:
                        return Snd.YM_MixerControl;
                case 8:
                        return Snd.YM_ChannelA.amplitude;
                case 9:
                        return Snd.YM_ChannelB.amplitude;
                case 10:
                        return Snd.YM_ChannelC.amplitude;
                case 11:
                        return Snd.YM_Envelope_fine_period;
                case 12:
                        return Snd.YM_Envelope_crse_period;
                case 13:
                        return Snd.YM_Envelope_shape;
                case 14:
#if 0
        ec_stderr(" ->: 0x%02x\n",snd_porta & 0xf8);
#endif
                        return snd_porta & 0xf8;
                case 15:
                        return Snd.IO_PortB;
        }

        return 0;
}

B LOAD_B_ff8801(void)
{       return (B) 0xff;        /* checked : always returns 0xff */
}

B LOAD_B_ff8802(void)
{       return (B) 0;
}

B LOAD_B_ff8803(void)
{       return (B) 0xff;        /* checked : always returns 0xff */
}

void STORE_B_ff8800(B v)
{       
#if 0
        ec_stderr("Store $ff8800 : %d\n",v);
#endif  
        YM_select = v & 15;
}

void STORE_B_ff8801(B v)
{       
  UNUSED(v);
        /*ec_stderr("Store $ff8801 : %d\n",v);*/

        /* should this do what 8800 does??? on a Falcon it seems to!!! */
}

void STORE_B_ff8802(B v)
{       
#if 0
        ec_stderr("Store $ff8802 : 0x%02x\n",v);
#endif  
        switch (YM_select)
        {       case 0:  
                        Snd.YM_ChannelA.finetune=v & 0xff;
#if (DEBUG_SND)
                        ec_stderr("Channel A fine tune:%d\n",(UL) v);
#endif
                        break;  
                case 1:
                        Snd.YM_ChannelA.crsetune=v & 0x0f; 
#if (DEBUG_SND)
                        ec_stderr("Channel A course tune:%d\n",(UL)v);
#endif
                        break;                                  
                case 2:  
                        Snd.YM_ChannelB.finetune=v & 0xff;
                        break;  
                case 3:
                        Snd.YM_ChannelB.crsetune=v & 0x0f;
                        break;  
                case 4:  
                        Snd.YM_ChannelC.finetune=v & 0xff;
                        break;  
                case 5:
                        Snd.YM_ChannelC.crsetune=v & 0x0f;
                        break;  
                case 6:
                        Snd.YM_NoiseControl=v & 0x1f;
                        break;
                case 7:
                        Snd.YM_MixerControl=v & 0xff;
#if (DEBUG_SND)
                        ec_stderr("Mixer Control: 0x%02x\n",(UL) v);
#endif
                        break;
                case 8:
                        Snd.YM_ChannelA.amplitude=v & 0x1f;
#if (DEBUG_SND)
                        if (Snd.YM_ChannelA.amplitude & 0x10)
                                ec_stderr("Channel A Enveloping ON:%d\n",v);
#endif
                        break;
                case 9:
                        Snd.YM_ChannelB.amplitude=v & 0x1f;
#if (DEBUG_SND)
                        if (Snd.YM_ChannelB.amplitude & 0x10)
                                ec_stderr("Channel B Enveloping ON:%d\n",v);
#endif
                        break;
                case 10:
                        Snd.YM_ChannelC.amplitude=v & 0x1f;
#if (DEBUG_SND)
                        if (Snd.YM_ChannelC.amplitude & 0x10)
                                ec_stderr("Channel C Enveloping ON:\n");
#endif
                        break;
                case 11:
                        Snd.YM_Envelope_fine_period=v & 0xff;
#if (DEBUG_SND)
                        ec_stderr("Fine envelope:%d\n",(UL) v);
#endif
                        break;
                case 12:
                        Snd.YM_Envelope_crse_period=v & 0xff;
#if (DEBUG_SND)
                        ec_stderr("Course envelope:%d\n",(UL) v);
#endif
                        break;
                case 13:
                        Snd.YM_Envelope_shape=v & 0x0f;
#if (DEBUG_SND)
                        ec_stderr("Envelope shape set/trigger :%d\n",v);
#endif
                        Snd.YM_flag = 1;
                        break;
                case 14:
                        snd_porta = v;
                        break;
                case 15:
                        Snd.IO_PortB = v;
                        write_parallel(v);
                        break;
        }
}

void STORE_B_ff8803(B v)
{       
  UNUSED(v);
  /* ec_stderr("Store $ff8803: %d\n",v); */
}


