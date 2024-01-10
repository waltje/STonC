

#include "defs.h"
#include "cpu.h"
#include "gendefs.h"
#include "mem.h"
#include "native.h"
#include "nf.h"
























































































































































































































































































































































































































































GENFUNC_PROTO(Func600){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_AN_R_WORD((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_WORD(V_ABS_L_WORD(),x);;
THREAD
; }
GENFUNC_PROTO(Func601){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_ABS_W_WORD());;
SET_NZ(x);
CS_WORD(V_ABS_L_WORD(),x);;
THREAD
; }
GENFUNC_PROTO(Func602){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_ABS_L_WORD());;
SET_NZ(x);
CS_WORD(V_ABS_L_WORD(),x);;
THREAD
; }
GENFUNC_PROTO(Func603){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_PC_D_WORD());;
SET_NZ(x);
CS_WORD(V_ABS_L_WORD(),x);;
THREAD
; }
GENFUNC_PROTO(Func604){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_PC_R_WORD());;
SET_NZ(x);
CS_WORD(V_ABS_L_WORD(),x);;
THREAD
; }
GENFUNC_PROTO(Func605){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LM_WORD(MEM(V_IMM_WORD()));;
SET_NZ(x);
CS_WORD(V_ABS_L_WORD(),x);;
THREAD
; }
GENFUNC_PROTO(Func606){ 
BYTE r,x;
{B *v_x=DREG_BYTE((UBITS(0,5,iw)&7)); x=LR_BYTE(v_x);;
r = -x;
if (sr & MASK_CC_X) r--;
sr &= ~MASK_CC;
if (r) SET_NZ(r);
else UNSET_N();
if ((r&x) < 0) sr |= MASK_CC_V;
if ((r|x) < 0) sr |= MASK_CC_C|MASK_CC_X;
x=r;
SR_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func607){ 
BYTE r,x;
{UL v_x=V_AN_I_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
r = -x;
if (sr & MASK_CC_X) r--;
sr &= ~MASK_CC;
if (r) SET_NZ(r);
else UNSET_N();
if ((r&x) < 0) sr |= MASK_CC_V;
if ((r|x) < 0) sr |= MASK_CC_C|MASK_CC_X;
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func608){ 
BYTE r,x;
{UL v_x=V_AN_PI_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
r = -x;
if (sr & MASK_CC_X) r--;
sr &= ~MASK_CC;
if (r) SET_NZ(r);
else UNSET_N();
if ((r&x) < 0) sr |= MASK_CC_V;
if ((r|x) < 0) sr |= MASK_CC_C|MASK_CC_X;
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func609){ 
BYTE r,x;
{UL v_x=V_AN_PI_BYTE_All(7); x=CL_BYTE(v_x);;
r = -x;
if (sr & MASK_CC_X) r--;
sr &= ~MASK_CC;
if (r) SET_NZ(r);
else UNSET_N();
if ((r&x) < 0) sr |= MASK_CC_V;
if ((r|x) < 0) sr |= MASK_CC_C|MASK_CC_X;
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func610){ 
BYTE r,x;
{UL v_x=V_AN_PD_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
r = -x;
if (sr & MASK_CC_X) r--;
sr &= ~MASK_CC;
if (r) SET_NZ(r);
else UNSET_N();
if ((r&x) < 0) sr |= MASK_CC_V;
if ((r|x) < 0) sr |= MASK_CC_C|MASK_CC_X;
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func611){ 
BYTE r,x;
{UL v_x=V_AN_PD_BYTE_All(7); x=CL_BYTE(v_x);;
r = -x;
if (sr & MASK_CC_X) r--;
sr &= ~MASK_CC;
if (r) SET_NZ(r);
else UNSET_N();
if ((r&x) < 0) sr |= MASK_CC_V;
if ((r|x) < 0) sr |= MASK_CC_C|MASK_CC_X;
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func612){ 
BYTE r,x;
{UL v_x=V_AN_D_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
r = -x;
if (sr & MASK_CC_X) r--;
sr &= ~MASK_CC;
if (r) SET_NZ(r);
else UNSET_N();
if ((r&x) < 0) sr |= MASK_CC_V;
if ((r|x) < 0) sr |= MASK_CC_C|MASK_CC_X;
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func613){ 
BYTE r,x;
{UL v_x=V_AN_R_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
r = -x;
if (sr & MASK_CC_X) r--;
sr &= ~MASK_CC;
if (r) SET_NZ(r);
else UNSET_N();
if ((r&x) < 0) sr |= MASK_CC_V;
if ((r|x) < 0) sr |= MASK_CC_C|MASK_CC_X;
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func614){ 
BYTE r,x;
{UL v_x=V_ABS_W_BYTE(); x=CL_BYTE(v_x);;
r = -x;
if (sr & MASK_CC_X) r--;
sr &= ~MASK_CC;
if (r) SET_NZ(r);
else UNSET_N();
if ((r&x) < 0) sr |= MASK_CC_V;
if ((r|x) < 0) sr |= MASK_CC_C|MASK_CC_X;
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func615){ 
BYTE r,x;
{UL v_x=V_ABS_L_BYTE(); x=CL_BYTE(v_x);;
r = -x;
if (sr & MASK_CC_X) r--;
sr &= ~MASK_CC;
if (r) SET_NZ(r);
else UNSET_N();
if ((r&x) < 0) sr |= MASK_CC_V;
if ((r|x) < 0) sr |= MASK_CC_C|MASK_CC_X;
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func616){ 
WORD r,x;
{W *v_x=DREG_WORD((UBITS(0,5,iw)&7)); x=LR_WORD(v_x);;
r = -x;
if (sr & MASK_CC_X) r--;
sr &= ~MASK_CC;
if (r) SET_NZ(r);
else UNSET_N();
if ((r&x) < 0) sr |= MASK_CC_V;
if ((r|x) < 0) sr |= MASK_CC_C|MASK_CC_X;
x=r;
SR_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func617){ 
WORD r,x;
{UL v_x=V_AN_I_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
r = -x;
if (sr & MASK_CC_X) r--;
sr &= ~MASK_CC;
if (r) SET_NZ(r);
else UNSET_N();
if ((r&x) < 0) sr |= MASK_CC_V;
if ((r|x) < 0) sr |= MASK_CC_C|MASK_CC_X;
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func618){ 
WORD r,x;
{UL v_x=V_AN_PI_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
r = -x;
if (sr & MASK_CC_X) r--;
sr &= ~MASK_CC;
if (r) SET_NZ(r);
else UNSET_N();
if ((r&x) < 0) sr |= MASK_CC_V;
if ((r|x) < 0) sr |= MASK_CC_C|MASK_CC_X;
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func619){ 
WORD r,x;
{UL v_x=V_AN_PD_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
r = -x;
if (sr & MASK_CC_X) r--;
sr &= ~MASK_CC;
if (r) SET_NZ(r);
else UNSET_N();
if ((r&x) < 0) sr |= MASK_CC_V;
if ((r|x) < 0) sr |= MASK_CC_C|MASK_CC_X;
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func620){ 
WORD r,x;
{UL v_x=V_AN_D_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
r = -x;
if (sr & MASK_CC_X) r--;
sr &= ~MASK_CC;
if (r) SET_NZ(r);
else UNSET_N();
if ((r&x) < 0) sr |= MASK_CC_V;
if ((r|x) < 0) sr |= MASK_CC_C|MASK_CC_X;
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func621){ 
WORD r,x;
{UL v_x=V_AN_R_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
r = -x;
if (sr & MASK_CC_X) r--;
sr &= ~MASK_CC;
if (r) SET_NZ(r);
else UNSET_N();
if ((r&x) < 0) sr |= MASK_CC_V;
if ((r|x) < 0) sr |= MASK_CC_C|MASK_CC_X;
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func622){ 
WORD r,x;
{UL v_x=V_ABS_W_WORD(); x=CL_WORD(v_x);;
r = -x;
if (sr & MASK_CC_X) r--;
sr &= ~MASK_CC;
if (r) SET_NZ(r);
else UNSET_N();
if ((r&x) < 0) sr |= MASK_CC_V;
if ((r|x) < 0) sr |= MASK_CC_C|MASK_CC_X;
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func623){ 
WORD r,x;
{UL v_x=V_ABS_L_WORD(); x=CL_WORD(v_x);;
r = -x;
if (sr & MASK_CC_X) r--;
sr &= ~MASK_CC;
if (r) SET_NZ(r);
else UNSET_N();
if ((r&x) < 0) sr |= MASK_CC_V;
if ((r|x) < 0) sr |= MASK_CC_C|MASK_CC_X;
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func624){ 
LONG r,x;
{L *v_x=DREG_LONG((UBITS(0,5,iw)&7)); x=LR_LONG(v_x);;
r = -x;
if (sr & MASK_CC_X) r--;
sr &= ~MASK_CC;
if (r) SET_NZ(r);
else UNSET_N();
if ((r&x) < 0) sr |= MASK_CC_V;
if ((r|x) < 0) sr |= MASK_CC_C|MASK_CC_X;
x=r;
SR_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func625){ 
LONG r,x;
{UL v_x=V_AN_I_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
r = -x;
if (sr & MASK_CC_X) r--;
sr &= ~MASK_CC;
if (r) SET_NZ(r);
else UNSET_N();
if ((r&x) < 0) sr |= MASK_CC_V;
if ((r|x) < 0) sr |= MASK_CC_C|MASK_CC_X;
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func626){ 
LONG r,x;
{UL v_x=V_AN_PI_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
r = -x;
if (sr & MASK_CC_X) r--;
sr &= ~MASK_CC;
if (r) SET_NZ(r);
else UNSET_N();
if ((r&x) < 0) sr |= MASK_CC_V;
if ((r|x) < 0) sr |= MASK_CC_C|MASK_CC_X;
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func627){ 
LONG r,x;
{UL v_x=V_AN_PD_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
r = -x;
if (sr & MASK_CC_X) r--;
sr &= ~MASK_CC;
if (r) SET_NZ(r);
else UNSET_N();
if ((r&x) < 0) sr |= MASK_CC_V;
if ((r|x) < 0) sr |= MASK_CC_C|MASK_CC_X;
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func628){ 
LONG r,x;
{UL v_x=V_AN_D_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
r = -x;
if (sr & MASK_CC_X) r--;
sr &= ~MASK_CC;
if (r) SET_NZ(r);
else UNSET_N();
if ((r&x) < 0) sr |= MASK_CC_V;
if ((r|x) < 0) sr |= MASK_CC_C|MASK_CC_X;
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func629){ 
LONG r,x;
{UL v_x=V_AN_R_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
r = -x;
if (sr & MASK_CC_X) r--;
sr &= ~MASK_CC;
if (r) SET_NZ(r);
else UNSET_N();
if ((r&x) < 0) sr |= MASK_CC_V;
if ((r|x) < 0) sr |= MASK_CC_C|MASK_CC_X;
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func630){ 
LONG r,x;
{UL v_x=V_ABS_W_LONG(); x=CL_LONG(v_x);;
r = -x;
if (sr & MASK_CC_X) r--;
sr &= ~MASK_CC;
if (r) SET_NZ(r);
else UNSET_N();
if ((r&x) < 0) sr |= MASK_CC_V;
if ((r|x) < 0) sr |= MASK_CC_C|MASK_CC_X;
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func631){ 
LONG r,x;
{UL v_x=V_ABS_L_LONG(); x=CL_LONG(v_x);;
r = -x;
if (sr & MASK_CC_X) r--;
sr &= ~MASK_CC;
if (r) SET_NZ(r);
else UNSET_N();
if ((r&x) < 0) sr |= MASK_CC_V;
if ((r|x) < 0) sr |= MASK_CC_C|MASK_CC_X;
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func632){ 
if (!SUPERVISOR_MODE) 
{
#if 0
  ex_privileged()
#else
#if 1
  FIX_CCR();
  SDREG_WORD((UBITS(0,5,iw)&7),sr);;
#else
  FIX_CCR();
  SDREG_WORD((UBITS(0,5,iw)&7),sr&MASK_CC);;
#endif
#endif
}
else
{
  FIX_CCR();
  SDREG_WORD((UBITS(0,5,iw)&7),sr);;
}
THREAD
; }
GENFUNC_PROTO(Func633){ 
if (!SUPERVISOR_MODE) 
{
#if 0
  ex_privileged()
#else
#if 1
  FIX_CCR();
  CS_WORD(V_AN_I_WORD((UBITS(0,5,iw)&7)),sr);;
#else
  FIX_CCR();
  CS_WORD(V_AN_I_WORD((UBITS(0,5,iw)&7)),sr&MASK_CC);;
#endif
#endif
}
else
{
  FIX_CCR();
  CS_WORD(V_AN_I_WORD((UBITS(0,5,iw)&7)),sr);;
}
THREAD
; }
GENFUNC_PROTO(Func634){ 
if (!SUPERVISOR_MODE) 
{
#if 0
  ex_privileged()
#else
#if 1
  FIX_CCR();
  CS_WORD(V_AN_PI_WORD((UBITS(0,5,iw)&7)),sr);;
#else
  FIX_CCR();
  CS_WORD(V_AN_PI_WORD((UBITS(0,5,iw)&7)),sr&MASK_CC);;
#endif
#endif
}
else
{
  FIX_CCR();
  CS_WORD(V_AN_PI_WORD((UBITS(0,5,iw)&7)),sr);;
}
THREAD
; }
GENFUNC_PROTO(Func635){ 
if (!SUPERVISOR_MODE) 
{
#if 0
  ex_privileged()
#else
#if 1
  FIX_CCR();
  CS_WORD(V_AN_PD_WORD((UBITS(0,5,iw)&7)),sr);;
#else
  FIX_CCR();
  CS_WORD(V_AN_PD_WORD((UBITS(0,5,iw)&7)),sr&MASK_CC);;
#endif
#endif
}
else
{
  FIX_CCR();
  CS_WORD(V_AN_PD_WORD((UBITS(0,5,iw)&7)),sr);;
}
THREAD
; }
GENFUNC_PROTO(Func636){ 
if (!SUPERVISOR_MODE) 
{
#if 0
  ex_privileged()
#else
#if 1
  FIX_CCR();
  CS_WORD(V_AN_D_WORD((UBITS(0,5,iw)&7)),sr);;
#else
  FIX_CCR();
  CS_WORD(V_AN_D_WORD((UBITS(0,5,iw)&7)),sr&MASK_CC);;
#endif
#endif
}
else
{
  FIX_CCR();
  CS_WORD(V_AN_D_WORD((UBITS(0,5,iw)&7)),sr);;
}
THREAD
; }
GENFUNC_PROTO(Func637){ 
if (!SUPERVISOR_MODE) 
{
#if 0
  ex_privileged()
#else
#if 1
  FIX_CCR();
  CS_WORD(V_AN_R_WORD((UBITS(0,5,iw)&7)),sr);;
#else
  FIX_CCR();
  CS_WORD(V_AN_R_WORD((UBITS(0,5,iw)&7)),sr&MASK_CC);;
#endif
#endif
}
else
{
  FIX_CCR();
  CS_WORD(V_AN_R_WORD((UBITS(0,5,iw)&7)),sr);;
}
THREAD
; }
GENFUNC_PROTO(Func638){ 
if (!SUPERVISOR_MODE) 
{
#if 0
  ex_privileged()
#else
#if 1
  FIX_CCR();
  CS_WORD(V_ABS_W_WORD(),sr);;
#else
  FIX_CCR();
  CS_WORD(V_ABS_W_WORD(),sr&MASK_CC);;
#endif
#endif
}
else
{
  FIX_CCR();
  CS_WORD(V_ABS_W_WORD(),sr);;
}
THREAD
; }
GENFUNC_PROTO(Func639){ 
if (!SUPERVISOR_MODE) 
{
#if 0
  ex_privileged()
#else
#if 1
  FIX_CCR();
  CS_WORD(V_ABS_L_WORD(),sr);;
#else
  FIX_CCR();
  CS_WORD(V_ABS_L_WORD(),sr&MASK_CC);;
#endif
#endif
}
else
{
  FIX_CCR();
  CS_WORD(V_ABS_L_WORD(),sr);;
}
THREAD
; }
GENFUNC_PROTO(Func640){ 
int s,u;
s=LDREG_W(UBITS(9,11,iw));
u=LDREG_WORD((UBITS(0,5,iw)&7));;
if (s>u) UNSET_N();
else if (s<0) SET_N();
if (s<0||s>u) ex_chk();
THREAD
; }
GENFUNC_PROTO(Func641){ 
int s,u;
s=LDREG_W(UBITS(9,11,iw));
u=CL_WORD(V_AN_I_WORD((UBITS(0,5,iw)&7)));;
if (s>u) UNSET_N();
else if (s<0) SET_N();
if (s<0||s>u) ex_chk();
THREAD
; }
GENFUNC_PROTO(Func642){ 
int s,u;
s=LDREG_W(UBITS(9,11,iw));
u=CL_WORD(V_AN_PI_WORD((UBITS(0,5,iw)&7)));;
if (s>u) UNSET_N();
else if (s<0) SET_N();
if (s<0||s>u) ex_chk();
THREAD
; }
GENFUNC_PROTO(Func643){ 
int s,u;
s=LDREG_W(UBITS(9,11,iw));
u=CL_WORD(V_AN_PD_WORD((UBITS(0,5,iw)&7)));;
if (s>u) UNSET_N();
else if (s<0) SET_N();
if (s<0||s>u) ex_chk();
THREAD
; }
GENFUNC_PROTO(Func644){ 
int s,u;
s=LDREG_W(UBITS(9,11,iw));
u=CL_WORD(V_AN_D_WORD((UBITS(0,5,iw)&7)));;
if (s>u) UNSET_N();
else if (s<0) SET_N();
if (s<0||s>u) ex_chk();
THREAD
; }
GENFUNC_PROTO(Func645){ 
int s,u;
s=LDREG_W(UBITS(9,11,iw));
u=CL_WORD(V_AN_R_WORD((UBITS(0,5,iw)&7)));;
if (s>u) UNSET_N();
else if (s<0) SET_N();
if (s<0||s>u) ex_chk();
THREAD
; }
GENFUNC_PROTO(Func646){ 
int s,u;
s=LDREG_W(UBITS(9,11,iw));
u=CL_WORD(V_ABS_W_WORD());;
if (s>u) UNSET_N();
else if (s<0) SET_N();
if (s<0||s>u) ex_chk();
THREAD
; }
GENFUNC_PROTO(Func647){ 
int s,u;
s=LDREG_W(UBITS(9,11,iw));
u=CL_WORD(V_ABS_L_WORD());;
if (s>u) UNSET_N();
else if (s<0) SET_N();
if (s<0||s>u) ex_chk();
THREAD
; }
GENFUNC_PROTO(Func648){ 
int s,u;
s=LDREG_W(UBITS(9,11,iw));
u=CL_WORD(V_PC_D_WORD());;
if (s>u) UNSET_N();
else if (s<0) SET_N();
if (s<0||s>u) ex_chk();
THREAD
; }
GENFUNC_PROTO(Func649){ 
int s,u;
s=LDREG_W(UBITS(9,11,iw));
u=CL_WORD(V_PC_R_WORD());;
if (s>u) UNSET_N();
else if (s<0) SET_N();
if (s<0||s>u) ex_chk();
THREAD
; }
GENFUNC_PROTO(Func650){ 
int s,u;
s=LDREG_W(UBITS(9,11,iw));
u=LM_WORD(MEM(V_IMM_WORD()));;
if (s>u) UNSET_N();
else if (s<0) SET_N();
if (s<0||s>u) ex_chk();
THREAD
; }
GENFUNC_PROTO(Func651){ 
UL t=V_AN_I_LONG((UBITS(0,5,iw)&7));
AREG(UBITS(9,11,iw))=t;
THREAD
; }
GENFUNC_PROTO(Func652){ 
UL t=V_AN_D_LONG((UBITS(0,5,iw)&7));
AREG(UBITS(9,11,iw))=t;
THREAD
; }
GENFUNC_PROTO(Func653){ 
UL t=V_AN_R_LONG((UBITS(0,5,iw)&7));
AREG(UBITS(9,11,iw))=t;
THREAD
; }
GENFUNC_PROTO(Func654){ 
UL t=V_ABS_W_LONG();
AREG(UBITS(9,11,iw))=t;
THREAD
; }
GENFUNC_PROTO(Func655){ 
UL t=V_ABS_L_LONG();
AREG(UBITS(9,11,iw))=t;
THREAD
; }
GENFUNC_PROTO(Func656){ 
UL t=V_PC_D_LONG();
AREG(UBITS(9,11,iw))=t;
THREAD
; }
GENFUNC_PROTO(Func657){ 
UL t=V_PC_R_LONG();
AREG(UBITS(9,11,iw))=t;
THREAD
; }
GENFUNC_PROTO(Func658){ 
UNSET_N();
sr &= ~(MASK_CC_V|MASK_CC_C);
SET_Z();
SDREG_BYTE((UBITS(0,5,iw)&7),0);;
THREAD
; }
GENFUNC_PROTO(Func659){ 
UNSET_N();
sr &= ~(MASK_CC_V|MASK_CC_C);
SET_Z();
CS_BYTE(V_AN_I_BYTE((UBITS(0,5,iw)&7)),0);;
THREAD
; }
GENFUNC_PROTO(Func660){ 
UNSET_N();
sr &= ~(MASK_CC_V|MASK_CC_C);
SET_Z();
CS_BYTE(V_AN_PI_BYTE((UBITS(0,5,iw)&7)),0);;
THREAD
; }
GENFUNC_PROTO(Func661){ 
UNSET_N();
sr &= ~(MASK_CC_V|MASK_CC_C);
SET_Z();
CS_BYTE(V_AN_PI_BYTE_All(7),0);;
THREAD
; }
GENFUNC_PROTO(Func662){ 
UNSET_N();
sr &= ~(MASK_CC_V|MASK_CC_C);
SET_Z();
CS_BYTE(V_AN_PD_BYTE((UBITS(0,5,iw)&7)),0);;
THREAD
; }
GENFUNC_PROTO(Func663){ 
UNSET_N();
sr &= ~(MASK_CC_V|MASK_CC_C);
SET_Z();
CS_BYTE(V_AN_PD_BYTE_All(7),0);;
THREAD
; }
GENFUNC_PROTO(Func664){ 
UNSET_N();
sr &= ~(MASK_CC_V|MASK_CC_C);
SET_Z();
CS_BYTE(V_AN_D_BYTE((UBITS(0,5,iw)&7)),0);;
THREAD
; }
GENFUNC_PROTO(Func665){ 
UNSET_N();
sr &= ~(MASK_CC_V|MASK_CC_C);
SET_Z();
CS_BYTE(V_AN_R_BYTE((UBITS(0,5,iw)&7)),0);;
THREAD
; }
GENFUNC_PROTO(Func666){ 
UNSET_N();
sr &= ~(MASK_CC_V|MASK_CC_C);
SET_Z();
CS_BYTE(V_ABS_W_BYTE(),0);;
THREAD
; }
GENFUNC_PROTO(Func667){ 
UNSET_N();
sr &= ~(MASK_CC_V|MASK_CC_C);
SET_Z();
CS_BYTE(V_ABS_L_BYTE(),0);;
THREAD
; }
GENFUNC_PROTO(Func668){ 
UNSET_N();
sr &= ~(MASK_CC_V|MASK_CC_C);
SET_Z();
SDREG_WORD((UBITS(0,5,iw)&7),0);;
THREAD
; }
GENFUNC_PROTO(Func669){ 
UNSET_N();
sr &= ~(MASK_CC_V|MASK_CC_C);
SET_Z();
CS_WORD(V_AN_I_WORD((UBITS(0,5,iw)&7)),0);;
THREAD
; }
GENFUNC_PROTO(Func670){ 
UNSET_N();
sr &= ~(MASK_CC_V|MASK_CC_C);
SET_Z();
CS_WORD(V_AN_PI_WORD((UBITS(0,5,iw)&7)),0);;
THREAD
; }
GENFUNC_PROTO(Func671){ 
UNSET_N();
sr &= ~(MASK_CC_V|MASK_CC_C);
SET_Z();
CS_WORD(V_AN_PD_WORD((UBITS(0,5,iw)&7)),0);;
THREAD
; }
GENFUNC_PROTO(Func672){ 
UNSET_N();
sr &= ~(MASK_CC_V|MASK_CC_C);
SET_Z();
CS_WORD(V_AN_D_WORD((UBITS(0,5,iw)&7)),0);;
THREAD
; }
GENFUNC_PROTO(Func673){ 
UNSET_N();
sr &= ~(MASK_CC_V|MASK_CC_C);
SET_Z();
CS_WORD(V_AN_R_WORD((UBITS(0,5,iw)&7)),0);;
THREAD
; }
GENFUNC_PROTO(Func674){ 
UNSET_N();
sr &= ~(MASK_CC_V|MASK_CC_C);
SET_Z();
CS_WORD(V_ABS_W_WORD(),0);;
THREAD
; }
GENFUNC_PROTO(Func675){ 
UNSET_N();
sr &= ~(MASK_CC_V|MASK_CC_C);
SET_Z();
CS_WORD(V_ABS_L_WORD(),0);;
THREAD
; }
GENFUNC_PROTO(Func676){ 
UNSET_N();
sr &= ~(MASK_CC_V|MASK_CC_C);
SET_Z();
SDREG_LONG((UBITS(0,5,iw)&7),0);;
THREAD
; }
GENFUNC_PROTO(Func677){ 
UNSET_N();
sr &= ~(MASK_CC_V|MASK_CC_C);
SET_Z();
CS_LONG(V_AN_I_LONG((UBITS(0,5,iw)&7)),0);;
THREAD
; }
GENFUNC_PROTO(Func678){ 
UNSET_N();
sr &= ~(MASK_CC_V|MASK_CC_C);
SET_Z();
CS_LONG(V_AN_PI_LONG((UBITS(0,5,iw)&7)),0);;
THREAD
; }
GENFUNC_PROTO(Func679){ 
UNSET_N();
sr &= ~(MASK_CC_V|MASK_CC_C);
SET_Z();
CS_LONG(V_AN_PD_LONG((UBITS(0,5,iw)&7)),0);;
THREAD
; }
GENFUNC_PROTO(Func680){ 
UNSET_N();
sr &= ~(MASK_CC_V|MASK_CC_C);
SET_Z();
CS_LONG(V_AN_D_LONG((UBITS(0,5,iw)&7)),0);;
THREAD
; }
GENFUNC_PROTO(Func681){ 
UNSET_N();
sr &= ~(MASK_CC_V|MASK_CC_C);
SET_Z();
CS_LONG(V_AN_R_LONG((UBITS(0,5,iw)&7)),0);;
THREAD
; }
GENFUNC_PROTO(Func682){ 
UNSET_N();
sr &= ~(MASK_CC_V|MASK_CC_C);
SET_Z();
CS_LONG(V_ABS_W_LONG(),0);;
THREAD
; }
GENFUNC_PROTO(Func683){ 
UNSET_N();
sr &= ~(MASK_CC_V|MASK_CC_C);
SET_Z();
CS_LONG(V_ABS_L_LONG(),0);;
THREAD
; }
GENFUNC_PROTO(Func684){ 
BYTE r,x;
{B *v_x=DREG_BYTE((UBITS(0,5,iw)&7)); x=LR_BYTE(v_x);;
sr &= ~MASK_CC;
r = -x;
SET_NZ(r);
if ((r|x)<0) sr |= MASK_CC_C|MASK_CC_X; /* Manual is not clear about this */
if ((r&x)<0) sr |= MASK_CC_V;
x=r;
SR_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func685){ 
BYTE r,x;
{UL v_x=V_AN_I_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = -x;
SET_NZ(r);
if ((r|x)<0) sr |= MASK_CC_C|MASK_CC_X; /* Manual is not clear about this */
if ((r&x)<0) sr |= MASK_CC_V;
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func686){ 
BYTE r,x;
{UL v_x=V_AN_PI_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = -x;
SET_NZ(r);
if ((r|x)<0) sr |= MASK_CC_C|MASK_CC_X; /* Manual is not clear about this */
if ((r&x)<0) sr |= MASK_CC_V;
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func687){ 
BYTE r,x;
{UL v_x=V_AN_PI_BYTE_All(7); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = -x;
SET_NZ(r);
if ((r|x)<0) sr |= MASK_CC_C|MASK_CC_X; /* Manual is not clear about this */
if ((r&x)<0) sr |= MASK_CC_V;
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func688){ 
BYTE r,x;
{UL v_x=V_AN_PD_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = -x;
SET_NZ(r);
if ((r|x)<0) sr |= MASK_CC_C|MASK_CC_X; /* Manual is not clear about this */
if ((r&x)<0) sr |= MASK_CC_V;
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func689){ 
BYTE r,x;
{UL v_x=V_AN_PD_BYTE_All(7); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = -x;
SET_NZ(r);
if ((r|x)<0) sr |= MASK_CC_C|MASK_CC_X; /* Manual is not clear about this */
if ((r&x)<0) sr |= MASK_CC_V;
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func690){ 
BYTE r,x;
{UL v_x=V_AN_D_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = -x;
SET_NZ(r);
if ((r|x)<0) sr |= MASK_CC_C|MASK_CC_X; /* Manual is not clear about this */
if ((r&x)<0) sr |= MASK_CC_V;
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func691){ 
BYTE r,x;
{UL v_x=V_AN_R_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = -x;
SET_NZ(r);
if ((r|x)<0) sr |= MASK_CC_C|MASK_CC_X; /* Manual is not clear about this */
if ((r&x)<0) sr |= MASK_CC_V;
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func692){ 
BYTE r,x;
{UL v_x=V_ABS_W_BYTE(); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = -x;
SET_NZ(r);
if ((r|x)<0) sr |= MASK_CC_C|MASK_CC_X; /* Manual is not clear about this */
if ((r&x)<0) sr |= MASK_CC_V;
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func693){ 
BYTE r,x;
{UL v_x=V_ABS_L_BYTE(); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = -x;
SET_NZ(r);
if ((r|x)<0) sr |= MASK_CC_C|MASK_CC_X; /* Manual is not clear about this */
if ((r&x)<0) sr |= MASK_CC_V;
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func694){ 
WORD r,x;
{W *v_x=DREG_WORD((UBITS(0,5,iw)&7)); x=LR_WORD(v_x);;
sr &= ~MASK_CC;
r = -x;
SET_NZ(r);
if ((r|x)<0) sr |= MASK_CC_C|MASK_CC_X; /* Manual is not clear about this */
if ((r&x)<0) sr |= MASK_CC_V;
x=r;
SR_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func695){ 
WORD r,x;
{UL v_x=V_AN_I_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = -x;
SET_NZ(r);
if ((r|x)<0) sr |= MASK_CC_C|MASK_CC_X; /* Manual is not clear about this */
if ((r&x)<0) sr |= MASK_CC_V;
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func696){ 
WORD r,x;
{UL v_x=V_AN_PI_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = -x;
SET_NZ(r);
if ((r|x)<0) sr |= MASK_CC_C|MASK_CC_X; /* Manual is not clear about this */
if ((r&x)<0) sr |= MASK_CC_V;
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func697){ 
WORD r,x;
{UL v_x=V_AN_PD_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = -x;
SET_NZ(r);
if ((r|x)<0) sr |= MASK_CC_C|MASK_CC_X; /* Manual is not clear about this */
if ((r&x)<0) sr |= MASK_CC_V;
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func698){ 
WORD r,x;
{UL v_x=V_AN_D_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = -x;
SET_NZ(r);
if ((r|x)<0) sr |= MASK_CC_C|MASK_CC_X; /* Manual is not clear about this */
if ((r&x)<0) sr |= MASK_CC_V;
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func699){ 
WORD r,x;
{UL v_x=V_AN_R_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = -x;
SET_NZ(r);
if ((r|x)<0) sr |= MASK_CC_C|MASK_CC_X; /* Manual is not clear about this */
if ((r&x)<0) sr |= MASK_CC_V;
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func700){ 
WORD r,x;
{UL v_x=V_ABS_W_WORD(); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = -x;
SET_NZ(r);
if ((r|x)<0) sr |= MASK_CC_C|MASK_CC_X; /* Manual is not clear about this */
if ((r&x)<0) sr |= MASK_CC_V;
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func701){ 
WORD r,x;
{UL v_x=V_ABS_L_WORD(); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = -x;
SET_NZ(r);
if ((r|x)<0) sr |= MASK_CC_C|MASK_CC_X; /* Manual is not clear about this */
if ((r&x)<0) sr |= MASK_CC_V;
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func702){ 
LONG r,x;
{L *v_x=DREG_LONG((UBITS(0,5,iw)&7)); x=LR_LONG(v_x);;
sr &= ~MASK_CC;
r = -x;
SET_NZ(r);
if ((r|x)<0) sr |= MASK_CC_C|MASK_CC_X; /* Manual is not clear about this */
if ((r&x)<0) sr |= MASK_CC_V;
x=r;
SR_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func703){ 
LONG r,x;
{UL v_x=V_AN_I_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = -x;
SET_NZ(r);
if ((r|x)<0) sr |= MASK_CC_C|MASK_CC_X; /* Manual is not clear about this */
if ((r&x)<0) sr |= MASK_CC_V;
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func704){ 
LONG r,x;
{UL v_x=V_AN_PI_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = -x;
SET_NZ(r);
if ((r|x)<0) sr |= MASK_CC_C|MASK_CC_X; /* Manual is not clear about this */
if ((r&x)<0) sr |= MASK_CC_V;
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func705){ 
LONG r,x;
{UL v_x=V_AN_PD_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = -x;
SET_NZ(r);
if ((r|x)<0) sr |= MASK_CC_C|MASK_CC_X; /* Manual is not clear about this */
if ((r&x)<0) sr |= MASK_CC_V;
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func706){ 
LONG r,x;
{UL v_x=V_AN_D_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = -x;
SET_NZ(r);
if ((r|x)<0) sr |= MASK_CC_C|MASK_CC_X; /* Manual is not clear about this */
if ((r&x)<0) sr |= MASK_CC_V;
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func707){ 
LONG r,x;
{UL v_x=V_AN_R_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = -x;
SET_NZ(r);
if ((r|x)<0) sr |= MASK_CC_C|MASK_CC_X; /* Manual is not clear about this */
if ((r&x)<0) sr |= MASK_CC_V;
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func708){ 
LONG r,x;
{UL v_x=V_ABS_W_LONG(); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = -x;
SET_NZ(r);
if ((r|x)<0) sr |= MASK_CC_C|MASK_CC_X; /* Manual is not clear about this */
if ((r&x)<0) sr |= MASK_CC_V;
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func709){ 
LONG r,x;
{UL v_x=V_ABS_L_LONG(); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = -x;
SET_NZ(r);
if ((r|x)<0) sr |= MASK_CC_C|MASK_CC_X; /* Manual is not clear about this */
if ((r&x)<0) sr |= MASK_CC_V;
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func710){ 
W d;
d=LDREG_WORD((UBITS(0,5,iw)&7));;
sr &= ~MASK_CC;
sr |= d & MASK_CC;
CHECK_CCR();
THREAD
;; }
GENFUNC_PROTO(Func711){ 
W d;
d=CL_WORD(V_AN_I_WORD((UBITS(0,5,iw)&7)));;
sr &= ~MASK_CC;
sr |= d & MASK_CC;
CHECK_CCR();
THREAD
;; }
GENFUNC_PROTO(Func712){ 
W d;
d=CL_WORD(V_AN_PI_WORD((UBITS(0,5,iw)&7)));;
sr &= ~MASK_CC;
sr |= d & MASK_CC;
CHECK_CCR();
THREAD
;; }
GENFUNC_PROTO(Func713){ 
W d;
d=CL_WORD(V_AN_PD_WORD((UBITS(0,5,iw)&7)));;
sr &= ~MASK_CC;
sr |= d & MASK_CC;
CHECK_CCR();
THREAD
;; }
GENFUNC_PROTO(Func714){ 
W d;
d=CL_WORD(V_AN_D_WORD((UBITS(0,5,iw)&7)));;
sr &= ~MASK_CC;
sr |= d & MASK_CC;
CHECK_CCR();
THREAD
;; }
GENFUNC_PROTO(Func715){ 
W d;
d=CL_WORD(V_AN_R_WORD((UBITS(0,5,iw)&7)));;
sr &= ~MASK_CC;
sr |= d & MASK_CC;
CHECK_CCR();
THREAD
;; }
GENFUNC_PROTO(Func716){ 
W d;
d=CL_WORD(V_ABS_W_WORD());;
sr &= ~MASK_CC;
sr |= d & MASK_CC;
CHECK_CCR();
THREAD
;; }
GENFUNC_PROTO(Func717){ 
W d;
d=CL_WORD(V_ABS_L_WORD());;
sr &= ~MASK_CC;
sr |= d & MASK_CC;
CHECK_CCR();
THREAD
;; }
GENFUNC_PROTO(Func718){ 
W d;
d=CL_WORD(V_PC_D_WORD());;
sr &= ~MASK_CC;
sr |= d & MASK_CC;
CHECK_CCR();
THREAD
;; }
GENFUNC_PROTO(Func719){ 
W d;
d=CL_WORD(V_PC_R_WORD());;
sr &= ~MASK_CC;
sr |= d & MASK_CC;
CHECK_CCR();
THREAD
;; }
GENFUNC_PROTO(Func720){ 
W d;
d=LM_WORD(MEM(V_IMM_WORD()));;
sr &= ~MASK_CC;
sr |= d & MASK_CC;
CHECK_CCR();
THREAD
;; }
GENFUNC_PROTO(Func721){ 
BYTE x;
{B *v_x=DREG_BYTE((UBITS(0,5,iw)&7)); x=LR_BYTE(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
x = ~x;
SET_NZ(x);
SR_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func722){ 
BYTE x;
{UL v_x=V_AN_I_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
x = ~x;
SET_NZ(x);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func723){ 
BYTE x;
{UL v_x=V_AN_PI_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
x = ~x;
SET_NZ(x);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func724){ 
BYTE x;
{UL v_x=V_AN_PI_BYTE_All(7); x=CL_BYTE(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
x = ~x;
SET_NZ(x);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func725){ 
BYTE x;
{UL v_x=V_AN_PD_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
x = ~x;
SET_NZ(x);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func726){ 
BYTE x;
{UL v_x=V_AN_PD_BYTE_All(7); x=CL_BYTE(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
x = ~x;
SET_NZ(x);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func727){ 
BYTE x;
{UL v_x=V_AN_D_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
x = ~x;
SET_NZ(x);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func728){ 
BYTE x;
{UL v_x=V_AN_R_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
x = ~x;
SET_NZ(x);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func729){ 
BYTE x;
{UL v_x=V_ABS_W_BYTE(); x=CL_BYTE(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
x = ~x;
SET_NZ(x);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func730){ 
BYTE x;
{UL v_x=V_ABS_L_BYTE(); x=CL_BYTE(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
x = ~x;
SET_NZ(x);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func731){ 
WORD x;
{W *v_x=DREG_WORD((UBITS(0,5,iw)&7)); x=LR_WORD(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
x = ~x;
SET_NZ(x);
SR_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func732){ 
WORD x;
{UL v_x=V_AN_I_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
x = ~x;
SET_NZ(x);
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func733){ 
WORD x;
{UL v_x=V_AN_PI_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
x = ~x;
SET_NZ(x);
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func734){ 
WORD x;
{UL v_x=V_AN_PD_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
x = ~x;
SET_NZ(x);
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func735){ 
WORD x;
{UL v_x=V_AN_D_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
x = ~x;
SET_NZ(x);
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func736){ 
WORD x;
{UL v_x=V_AN_R_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
x = ~x;
SET_NZ(x);
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func737){ 
WORD x;
{UL v_x=V_ABS_W_WORD(); x=CL_WORD(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
x = ~x;
SET_NZ(x);
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func738){ 
WORD x;
{UL v_x=V_ABS_L_WORD(); x=CL_WORD(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
x = ~x;
SET_NZ(x);
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func739){ 
LONG x;
{L *v_x=DREG_LONG((UBITS(0,5,iw)&7)); x=LR_LONG(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
x = ~x;
SET_NZ(x);
SR_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func740){ 
LONG x;
{UL v_x=V_AN_I_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
x = ~x;
SET_NZ(x);
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func741){ 
LONG x;
{UL v_x=V_AN_PI_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
x = ~x;
SET_NZ(x);
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func742){ 
LONG x;
{UL v_x=V_AN_PD_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
x = ~x;
SET_NZ(x);
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func743){ 
LONG x;
{UL v_x=V_AN_D_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
x = ~x;
SET_NZ(x);
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func744){ 
LONG x;
{UL v_x=V_AN_R_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
x = ~x;
SET_NZ(x);
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func745){ 
LONG x;
{UL v_x=V_ABS_W_LONG(); x=CL_LONG(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
x = ~x;
SET_NZ(x);
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func746){ 
LONG x;
{UL v_x=V_ABS_L_LONG(); x=CL_LONG(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
x = ~x;
SET_NZ(x);
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func747){ 
W d;
if (!SUPERVISOR_MODE) ex_privileged();
else
{
	d=LDREG_WORD((UBITS(0,5,iw)&7));;
	sr = d & MASK_SR;
  if (!SUPERVISOR_MODE) enter_user_mode();
	CHECK_CCR();
	CHECK_TRACE();
	CHECK_NOTRACE();
	CHECK_IPL();
}
THREAD
; }
GENFUNC_PROTO(Func748){ 
W d;
if (!SUPERVISOR_MODE) ex_privileged();
else
{
	d=CL_WORD(V_AN_I_WORD((UBITS(0,5,iw)&7)));;
	sr = d & MASK_SR;
  if (!SUPERVISOR_MODE) enter_user_mode();
	CHECK_CCR();
	CHECK_TRACE();
	CHECK_NOTRACE();
	CHECK_IPL();
}
THREAD
; }
GENFUNC_PROTO(Func749){ 
W d;
if (!SUPERVISOR_MODE) ex_privileged();
else
{
	d=CL_WORD(V_AN_PI_WORD((UBITS(0,5,iw)&7)));;
	sr = d & MASK_SR;
  if (!SUPERVISOR_MODE) enter_user_mode();
	CHECK_CCR();
	CHECK_TRACE();
	CHECK_NOTRACE();
	CHECK_IPL();
}
THREAD
; }
GENFUNC_PROTO(Func750){ 
W d;
if (!SUPERVISOR_MODE) ex_privileged();
else
{
	d=CL_WORD(V_AN_PD_WORD((UBITS(0,5,iw)&7)));;
	sr = d & MASK_SR;
  if (!SUPERVISOR_MODE) enter_user_mode();
	CHECK_CCR();
	CHECK_TRACE();
	CHECK_NOTRACE();
	CHECK_IPL();
}
THREAD
; }
GENFUNC_PROTO(Func751){ 
W d;
if (!SUPERVISOR_MODE) ex_privileged();
else
{
	d=CL_WORD(V_AN_D_WORD((UBITS(0,5,iw)&7)));;
	sr = d & MASK_SR;
  if (!SUPERVISOR_MODE) enter_user_mode();
	CHECK_CCR();
	CHECK_TRACE();
	CHECK_NOTRACE();
	CHECK_IPL();
}
THREAD
; }
GENFUNC_PROTO(Func752){ 
W d;
if (!SUPERVISOR_MODE) ex_privileged();
else
{
	d=CL_WORD(V_AN_R_WORD((UBITS(0,5,iw)&7)));;
	sr = d & MASK_SR;
  if (!SUPERVISOR_MODE) enter_user_mode();
	CHECK_CCR();
	CHECK_TRACE();
	CHECK_NOTRACE();
	CHECK_IPL();
}
THREAD
; }
GENFUNC_PROTO(Func753){ 
W d;
if (!SUPERVISOR_MODE) ex_privileged();
else
{
	d=CL_WORD(V_ABS_W_WORD());;
	sr = d & MASK_SR;
  if (!SUPERVISOR_MODE) enter_user_mode();
	CHECK_CCR();
	CHECK_TRACE();
	CHECK_NOTRACE();
	CHECK_IPL();
}
THREAD
; }
GENFUNC_PROTO(Func754){ 
W d;
if (!SUPERVISOR_MODE) ex_privileged();
else
{
	d=CL_WORD(V_ABS_L_WORD());;
	sr = d & MASK_SR;
  if (!SUPERVISOR_MODE) enter_user_mode();
	CHECK_CCR();
	CHECK_TRACE();
	CHECK_NOTRACE();
	CHECK_IPL();
}
THREAD
; }
GENFUNC_PROTO(Func755){ 
W d;
if (!SUPERVISOR_MODE) ex_privileged();
else
{
	d=CL_WORD(V_PC_D_WORD());;
	sr = d & MASK_SR;
  if (!SUPERVISOR_MODE) enter_user_mode();
	CHECK_CCR();
	CHECK_TRACE();
	CHECK_NOTRACE();
	CHECK_IPL();
}
THREAD
; }
GENFUNC_PROTO(Func756){ 
W d;
if (!SUPERVISOR_MODE) ex_privileged();
else
{
	d=CL_WORD(V_PC_R_WORD());;
	sr = d & MASK_SR;
  if (!SUPERVISOR_MODE) enter_user_mode();
	CHECK_CCR();
	CHECK_TRACE();
	CHECK_NOTRACE();
	CHECK_IPL();
}
THREAD
; }
GENFUNC_PROTO(Func757){ 
W d;
if (!SUPERVISOR_MODE) ex_privileged();
else
{
	d=LM_WORD(MEM(V_IMM_WORD()));;
	sr = d & MASK_SR;
  if (!SUPERVISOR_MODE) enter_user_mode();
	CHECK_CCR();
	CHECK_TRACE();
	CHECK_NOTRACE();
	CHECK_IPL();
}
THREAD
; }
GENFUNC_PROTO(Func758){ 
BYTE x;
{B *v_x=DREG_BYTE((UBITS(0,5,iw)&7)); x=LR_BYTE(v_x);;
x=BCD_SUB(x,0);
SR_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func759){ 
BYTE x;
{UL v_x=V_AN_I_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
x=BCD_SUB(x,0);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func760){ 
BYTE x;
{UL v_x=V_AN_PI_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
x=BCD_SUB(x,0);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func761){ 
BYTE x;
{UL v_x=V_AN_PI_BYTE_All(7); x=CL_BYTE(v_x);;
x=BCD_SUB(x,0);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func762){ 
BYTE x;
{UL v_x=V_AN_PD_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
x=BCD_SUB(x,0);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func763){ 
BYTE x;
{UL v_x=V_AN_PD_BYTE_All(7); x=CL_BYTE(v_x);;
x=BCD_SUB(x,0);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func764){ 
BYTE x;
{UL v_x=V_AN_D_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
x=BCD_SUB(x,0);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func765){ 
BYTE x;
{UL v_x=V_AN_R_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
x=BCD_SUB(x,0);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func766){ 
BYTE x;
{UL v_x=V_ABS_W_BYTE(); x=CL_BYTE(v_x);;
x=BCD_SUB(x,0);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func767){ 
BYTE x;
{UL v_x=V_ABS_L_BYTE(); x=CL_BYTE(v_x);;
x=BCD_SUB(x,0);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func768){ 
int tmp,reg=UBITS(0,2,iw);
sr &= ~MASK_CC|MASK_CC_X;
tmp = (DREG(reg)>>16)&0xffff;
DREG(reg)<<=16;
DREG(reg)|=tmp;
SET_NZ(DREG(reg));
THREAD
; }
GENFUNC_PROTO(Func769){ 
UL t=V_AN_I_LONG((UBITS(0,5,iw)&7));
PUSH_UL(t);
THREAD
; }
GENFUNC_PROTO(Func770){ 
UL t=V_AN_D_LONG((UBITS(0,5,iw)&7));
PUSH_UL(t);
THREAD
; }
GENFUNC_PROTO(Func771){ 
UL t=V_AN_R_LONG((UBITS(0,5,iw)&7));
PUSH_UL(t);
THREAD
; }
GENFUNC_PROTO(Func772){ 
UL t=V_ABS_W_LONG();
PUSH_UL(t);
THREAD
; }
GENFUNC_PROTO(Func773){ 
UL t=V_ABS_L_LONG();
PUSH_UL(t);
THREAD
; }
GENFUNC_PROTO(Func774){ 
UL t=V_PC_D_LONG();
PUSH_UL(t);
THREAD
; }
GENFUNC_PROTO(Func775){ 
UL t=V_PC_R_LONG();
PUSH_UL(t);
THREAD
; }
GENFUNC_PROTO(Func776){ 
WORD x,reg=UBITS(0,2,iw);
sr &= ~MASK_CC|MASK_CC_X;
x=LDREG_B(reg);SDREG_W(reg,x);
SET_NZ(x);
THREAD
; }
GENFUNC_PROTO(Func777){ 
int mask,i;
UL x;
mask=GET_SI16;
x=V_AN_I_WORD((UBITS(0,5,iw)&7));
for (i=0;i<16;i++)
{
	if (mask&(1<<i))
	{
		CS_WORD(x,LDREG_WORD(i));
		x += SIZEWORD;
	}
}
THREAD
; }
GENFUNC_PROTO(Func778){ 
int mask,an,s,i;
mask=GET_SI16;
an=UBITS(0,2,iw);
s=LDREG_WORD(an+8);
for(i=0;i<16;i++)

if (mask&(1<<i))
{
	AREG(an) -= SIZEWORD;
	if (7-i == an) CS_WORD(V_AN_I_WORD(an),s);
	else CS_WORD(V_AN_I_WORD(an), LDREG_WORD(15-i));
}
THREAD
;
THREAD
; }
GENFUNC_PROTO(Func779){ 
int mask,i;
UL x;
mask=GET_SI16;
x=V_AN_D_WORD((UBITS(0,5,iw)&7));
for (i=0;i<16;i++)
{
	if (mask&(1<<i))
	{
		CS_WORD(x,LDREG_WORD(i));
		x += SIZEWORD;
	}
}
THREAD
; }
GENFUNC_PROTO(Func780){ 
int mask,i;
UL x;
mask=GET_SI16;
x=V_AN_R_WORD((UBITS(0,5,iw)&7));
for (i=0;i<16;i++)
{
	if (mask&(1<<i))
	{
		CS_WORD(x,LDREG_WORD(i));
		x += SIZEWORD;
	}
}
THREAD
; }
GENFUNC_PROTO(Func781){ 
int mask,i;
UL x;
mask=GET_SI16;
x=V_ABS_W_WORD();
for (i=0;i<16;i++)
{
	if (mask&(1<<i))
	{
		CS_WORD(x,LDREG_WORD(i));
		x += SIZEWORD;
	}
}
THREAD
; }
GENFUNC_PROTO(Func782){ 
int mask,i;
UL x;
mask=GET_SI16;
x=V_ABS_L_WORD();
for (i=0;i<16;i++)
{
	if (mask&(1<<i))
	{
		CS_WORD(x,LDREG_WORD(i));
		x += SIZEWORD;
	}
}
THREAD
; }
GENFUNC_PROTO(Func783){ 
LONG x,reg=UBITS(0,2,iw);
sr &= ~MASK_CC|MASK_CC_X;
x=DREG(reg)=LDREG_W(reg);
SET_NZ(x);
THREAD
; }
GENFUNC_PROTO(Func784){ 
int mask,i;
UL x;
mask=GET_SI16;
x=V_AN_I_LONG((UBITS(0,5,iw)&7));
for (i=0;i<16;i++)
{
	if (mask&(1<<i))
	{
		CS_LONG(x,LDREG_LONG(i));
		x += SIZELONG;
	}
}
THREAD
; }
GENFUNC_PROTO(Func785){ 
int mask,an,s,i;
mask=GET_SI16;
an=UBITS(0,2,iw);
s=LDREG_LONG(an+8);
for(i=0;i<16;i++)

if (mask&(1<<i))
{
	AREG(an) -= SIZELONG;
	if (7-i == an) CS_LONG(V_AN_I_LONG(an),s);
	else CS_LONG(V_AN_I_LONG(an), LDREG_LONG(15-i));
}
THREAD
;
THREAD
; }
GENFUNC_PROTO(Func786){ 
int mask,i;
UL x;
mask=GET_SI16;
x=V_AN_D_LONG((UBITS(0,5,iw)&7));
for (i=0;i<16;i++)
{
	if (mask&(1<<i))
	{
		CS_LONG(x,LDREG_LONG(i));
		x += SIZELONG;
	}
}
THREAD
; }
GENFUNC_PROTO(Func787){ 
int mask,i;
UL x;
mask=GET_SI16;
x=V_AN_R_LONG((UBITS(0,5,iw)&7));
for (i=0;i<16;i++)
{
	if (mask&(1<<i))
	{
		CS_LONG(x,LDREG_LONG(i));
		x += SIZELONG;
	}
}
THREAD
; }
GENFUNC_PROTO(Func788){ 
int mask,i;
UL x;
mask=GET_SI16;
x=V_ABS_W_LONG();
for (i=0;i<16;i++)
{
	if (mask&(1<<i))
	{
		CS_LONG(x,LDREG_LONG(i));
		x += SIZELONG;
	}
}
THREAD
; }
GENFUNC_PROTO(Func789){ 
int mask,i;
UL x;
mask=GET_SI16;
x=V_ABS_L_LONG();
for (i=0;i<16;i++)
{
	if (mask&(1<<i))
	{
		CS_LONG(x,LDREG_LONG(i));
		x += SIZELONG;
	}
}
THREAD
; }
GENFUNC_PROTO(Func790){ 
BYTE x;
sr &= ~MASK_CC|MASK_CC_X;
x=LDREG_BYTE((UBITS(0,5,iw)&7));;
SET_NZ(x);
THREAD
; }
GENFUNC_PROTO(Func791){ 
BYTE x;
sr &= ~MASK_CC|MASK_CC_X;
x=CL_BYTE(V_AN_I_BYTE((UBITS(0,5,iw)&7)));;
SET_NZ(x);
THREAD
; }
GENFUNC_PROTO(Func792){ 
BYTE x;
sr &= ~MASK_CC|MASK_CC_X;
x=CL_BYTE(V_AN_PI_BYTE((UBITS(0,5,iw)&7)));;
SET_NZ(x);
THREAD
; }
GENFUNC_PROTO(Func793){ 
BYTE x;
sr &= ~MASK_CC|MASK_CC_X;
x=CL_BYTE(V_AN_PI_BYTE_All(7));;
SET_NZ(x);
THREAD
; }
GENFUNC_PROTO(Func794){ 
BYTE x;
sr &= ~MASK_CC|MASK_CC_X;
x=CL_BYTE(V_AN_PD_BYTE((UBITS(0,5,iw)&7)));;
SET_NZ(x);
THREAD
; }
GENFUNC_PROTO(Func795){ 
BYTE x;
sr &= ~MASK_CC|MASK_CC_X;
x=CL_BYTE(V_AN_PD_BYTE_All(7));;
SET_NZ(x);
THREAD
; }
GENFUNC_PROTO(Func796){ 
BYTE x;
sr &= ~MASK_CC|MASK_CC_X;
x=CL_BYTE(V_AN_D_BYTE((UBITS(0,5,iw)&7)));;
SET_NZ(x);
THREAD
; }
GENFUNC_PROTO(Func797){ 
BYTE x;
sr &= ~MASK_CC|MASK_CC_X;
x=CL_BYTE(V_AN_R_BYTE((UBITS(0,5,iw)&7)));;
SET_NZ(x);
THREAD
; }
GENFUNC_PROTO(Func798){ 
BYTE x;
sr &= ~MASK_CC|MASK_CC_X;
x=CL_BYTE(V_ABS_W_BYTE());;
SET_NZ(x);
THREAD
; }
GENFUNC_PROTO(Func799){ 
BYTE x;
sr &= ~MASK_CC|MASK_CC_X;
x=CL_BYTE(V_ABS_L_BYTE());;
SET_NZ(x);
THREAD
; }
GENFUNC_PROTO(Func800){ 
BYTE x;
sr &= ~MASK_CC|MASK_CC_X;
x=CL_BYTE(V_PC_D_BYTE());;
SET_NZ(x);
THREAD
; }
GENFUNC_PROTO(Func801){ 
BYTE x;
sr &= ~MASK_CC|MASK_CC_X;
x=CL_BYTE(V_PC_R_BYTE());;
SET_NZ(x);
THREAD
; }
GENFUNC_PROTO(Func802){ 
WORD x;
sr &= ~MASK_CC|MASK_CC_X;
x=LDREG_WORD((UBITS(0,5,iw)&7));;
SET_NZ(x);
THREAD
; }
GENFUNC_PROTO(Func803){ 
WORD x;
sr &= ~MASK_CC|MASK_CC_X;
x=CL_WORD(V_AN_I_WORD((UBITS(0,5,iw)&7)));;
SET_NZ(x);
THREAD
; }
GENFUNC_PROTO(Func804){ 
WORD x;
sr &= ~MASK_CC|MASK_CC_X;
x=CL_WORD(V_AN_PI_WORD((UBITS(0,5,iw)&7)));;
SET_NZ(x);
THREAD
; }
GENFUNC_PROTO(Func805){ 
WORD x;
sr &= ~MASK_CC|MASK_CC_X;
x=CL_WORD(V_AN_PD_WORD((UBITS(0,5,iw)&7)));;
SET_NZ(x);
THREAD
; }
GENFUNC_PROTO(Func806){ 
WORD x;
sr &= ~MASK_CC|MASK_CC_X;
x=CL_WORD(V_AN_D_WORD((UBITS(0,5,iw)&7)));;
SET_NZ(x);
THREAD
; }
GENFUNC_PROTO(Func807){ 
WORD x;
sr &= ~MASK_CC|MASK_CC_X;
x=CL_WORD(V_AN_R_WORD((UBITS(0,5,iw)&7)));;
SET_NZ(x);
THREAD
; }
GENFUNC_PROTO(Func808){ 
WORD x;
sr &= ~MASK_CC|MASK_CC_X;
x=CL_WORD(V_ABS_W_WORD());;
SET_NZ(x);
THREAD
; }
GENFUNC_PROTO(Func809){ 
WORD x;
sr &= ~MASK_CC|MASK_CC_X;
x=CL_WORD(V_ABS_L_WORD());;
SET_NZ(x);
THREAD
; }
GENFUNC_PROTO(Func810){ 
WORD x;
sr &= ~MASK_CC|MASK_CC_X;
x=CL_WORD(V_PC_D_WORD());;
SET_NZ(x);
THREAD
; }
GENFUNC_PROTO(Func811){ 
WORD x;
sr &= ~MASK_CC|MASK_CC_X;
x=CL_WORD(V_PC_R_WORD());;
SET_NZ(x);
THREAD
; }
GENFUNC_PROTO(Func812){ 
LONG x;
sr &= ~MASK_CC|MASK_CC_X;
x=LDREG_LONG((UBITS(0,5,iw)&7));;
SET_NZ(x);
THREAD
; }
GENFUNC_PROTO(Func813){ 
LONG x;
sr &= ~MASK_CC|MASK_CC_X;
x=CL_LONG(V_AN_I_LONG((UBITS(0,5,iw)&7)));;
SET_NZ(x);
THREAD
; }
GENFUNC_PROTO(Func814){ 
LONG x;
sr &= ~MASK_CC|MASK_CC_X;
x=CL_LONG(V_AN_PI_LONG((UBITS(0,5,iw)&7)));;
SET_NZ(x);
THREAD
; }
GENFUNC_PROTO(Func815){ 
LONG x;
sr &= ~MASK_CC|MASK_CC_X;
x=CL_LONG(V_AN_PD_LONG((UBITS(0,5,iw)&7)));;
SET_NZ(x);
THREAD
; }
GENFUNC_PROTO(Func816){ 
LONG x;
sr &= ~MASK_CC|MASK_CC_X;
x=CL_LONG(V_AN_D_LONG((UBITS(0,5,iw)&7)));;
SET_NZ(x);
THREAD
; }
GENFUNC_PROTO(Func817){ 
LONG x;
sr &= ~MASK_CC|MASK_CC_X;
x=CL_LONG(V_AN_R_LONG((UBITS(0,5,iw)&7)));;
SET_NZ(x);
THREAD
; }
GENFUNC_PROTO(Func818){ 
LONG x;
sr &= ~MASK_CC|MASK_CC_X;
x=CL_LONG(V_ABS_W_LONG());;
SET_NZ(x);
THREAD
; }
GENFUNC_PROTO(Func819){ 
LONG x;
sr &= ~MASK_CC|MASK_CC_X;
x=CL_LONG(V_ABS_L_LONG());;
SET_NZ(x);
THREAD
; }
GENFUNC_PROTO(Func820){ 
LONG x;
sr &= ~MASK_CC|MASK_CC_X;
x=CL_LONG(V_PC_D_LONG());;
SET_NZ(x);
THREAD
; }
GENFUNC_PROTO(Func821){ 
LONG x;
sr &= ~MASK_CC|MASK_CC_X;
x=CL_LONG(V_PC_R_LONG());;
SET_NZ(x);
THREAD
; }
GENFUNC_PROTO(Func822){ 
BYTE x;
{B *v_x=DREG_BYTE((UBITS(0,5,iw)&7)); x=LR_BYTE(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
SET_NZ(x);
x |= 0x80;
SR_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func823){ 
BYTE x;
{UL v_x=V_AN_I_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
SET_NZ(x);
x |= 0x80;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func824){ 
BYTE x;
{UL v_x=V_AN_PI_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
SET_NZ(x);
x |= 0x80;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func825){ 
BYTE x;
{UL v_x=V_AN_PI_BYTE_All(7); x=CL_BYTE(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
SET_NZ(x);
x |= 0x80;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func826){ 
BYTE x;
{UL v_x=V_AN_PD_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
SET_NZ(x);
x |= 0x80;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func827){ 
BYTE x;
{UL v_x=V_AN_PD_BYTE_All(7); x=CL_BYTE(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
SET_NZ(x);
x |= 0x80;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func828){ 
BYTE x;
{UL v_x=V_AN_D_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
SET_NZ(x);
x |= 0x80;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func829){ 
BYTE x;
{UL v_x=V_AN_R_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
SET_NZ(x);
x |= 0x80;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func830){ 
BYTE x;
{UL v_x=V_ABS_W_BYTE(); x=CL_BYTE(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
SET_NZ(x);
x |= 0x80;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func831){ 
BYTE x;
{UL v_x=V_ABS_L_BYTE(); x=CL_BYTE(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
SET_NZ(x);
x |= 0x80;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func832){ ILLEGAL();; }
GENFUNC_PROTO(Func833){ 
int mask,i;
UL x;
mask=GET_SI16;
x=V_AN_I_WORD((UBITS(0,5,iw)&7));
for (i=0;i<16;i++)
{
	if (mask&(1<<i))
	{
		DREG(i) = (LONG)CL_WORD(x);
		x += SIZEWORD;
	}
}
THREAD
; }
GENFUNC_PROTO(Func834){ 
int mask,an,i;
UL x;
mask=GET_SI16;
an=UBITS(0,2,iw);
for (i=0;i<16;i++)

if (mask&(1<<i))
{
	if (i-8 != an) DREG(i)=(LONG)CL_WORD(V_AN_I_WORD(an));
	AREG(an) += SIZEWORD;
}
THREAD
;
THREAD
; }
GENFUNC_PROTO(Func835){ 
int mask,i;
UL x;
mask=GET_SI16;
x=V_AN_D_WORD((UBITS(0,5,iw)&7));
for (i=0;i<16;i++)
{
	if (mask&(1<<i))
	{
		DREG(i) = (LONG)CL_WORD(x);
		x += SIZEWORD;
	}
}
THREAD
; }
GENFUNC_PROTO(Func836){ 
int mask,i;
UL x;
mask=GET_SI16;
x=V_AN_R_WORD((UBITS(0,5,iw)&7));
for (i=0;i<16;i++)
{
	if (mask&(1<<i))
	{
		DREG(i) = (LONG)CL_WORD(x);
		x += SIZEWORD;
	}
}
THREAD
; }
GENFUNC_PROTO(Func837){ 
int mask,i;
UL x;
mask=GET_SI16;
x=V_ABS_W_WORD();
for (i=0;i<16;i++)
{
	if (mask&(1<<i))
	{
		DREG(i) = (LONG)CL_WORD(x);
		x += SIZEWORD;
	}
}
THREAD
; }
GENFUNC_PROTO(Func838){ 
int mask,i;
UL x;
mask=GET_SI16;
x=V_ABS_L_WORD();
for (i=0;i<16;i++)
{
	if (mask&(1<<i))
	{
		DREG(i) = (LONG)CL_WORD(x);
		x += SIZEWORD;
	}
}
THREAD
; }
GENFUNC_PROTO(Func839){ 
int mask,i;
UL x;
mask=GET_SI16;
x=V_PC_D_WORD();
for (i=0;i<16;i++)
{
	if (mask&(1<<i))
	{
		DREG(i) = (LONG)CL_WORD(x);
		x += SIZEWORD;
	}
}
THREAD
; }
GENFUNC_PROTO(Func840){ 
int mask,i;
UL x;
mask=GET_SI16;
x=V_PC_R_WORD();
for (i=0;i<16;i++)
{
	if (mask&(1<<i))
	{
		DREG(i) = (LONG)CL_WORD(x);
		x += SIZEWORD;
	}
}
THREAD
; }
GENFUNC_PROTO(Func841){ 
int mask,i;
UL x;
mask=GET_SI16;
x=V_AN_I_LONG((UBITS(0,5,iw)&7));
for (i=0;i<16;i++)
{
	if (mask&(1<<i))
	{
		DREG(i) = (LONG)CL_LONG(x);
		x += SIZELONG;
	}
}
THREAD
; }
GENFUNC_PROTO(Func842){ 
int mask,an,i;
UL x;
mask=GET_SI16;
an=UBITS(0,2,iw);
for (i=0;i<16;i++)

if (mask&(1<<i))
{
	if (i-8 != an) DREG(i)=(LONG)CL_LONG(V_AN_I_LONG(an));
	AREG(an) += SIZELONG;
}
THREAD
;
THREAD
; }
GENFUNC_PROTO(Func843){ 
int mask,i;
UL x;
mask=GET_SI16;
x=V_AN_D_LONG((UBITS(0,5,iw)&7));
for (i=0;i<16;i++)
{
	if (mask&(1<<i))
	{
		DREG(i) = (LONG)CL_LONG(x);
		x += SIZELONG;
	}
}
THREAD
; }
GENFUNC_PROTO(Func844){ 
int mask,i;
UL x;
mask=GET_SI16;
x=V_AN_R_LONG((UBITS(0,5,iw)&7));
for (i=0;i<16;i++)
{
	if (mask&(1<<i))
	{
		DREG(i) = (LONG)CL_LONG(x);
		x += SIZELONG;
	}
}
THREAD
; }
GENFUNC_PROTO(Func845){ 
int mask,i;
UL x;
mask=GET_SI16;
x=V_ABS_W_LONG();
for (i=0;i<16;i++)
{
	if (mask&(1<<i))
	{
		DREG(i) = (LONG)CL_LONG(x);
		x += SIZELONG;
	}
}
THREAD
; }
GENFUNC_PROTO(Func846){ 
int mask,i;
UL x;
mask=GET_SI16;
x=V_ABS_L_LONG();
for (i=0;i<16;i++)
{
	if (mask&(1<<i))
	{
		DREG(i) = (LONG)CL_LONG(x);
		x += SIZELONG;
	}
}
THREAD
; }
GENFUNC_PROTO(Func847){ 
int mask,i;
UL x;
mask=GET_SI16;
x=V_PC_D_LONG();
for (i=0;i<16;i++)
{
	if (mask&(1<<i))
	{
		DREG(i) = (LONG)CL_LONG(x);
		x += SIZELONG;
	}
}
THREAD
; }
GENFUNC_PROTO(Func848){ 
int mask,i;
UL x;
mask=GET_SI16;
x=V_PC_R_LONG();
for (i=0;i<16;i++)
{
	if (mask&(1<<i))
	{
		DREG(i) = (LONG)CL_LONG(x);
		x += SIZELONG;
	}
}
THREAD
; }
GENFUNC_PROTO(Func849){ 
int n=UBITS(0,3,iw);
ex_trap(T_TRAP_0+n);
; }
GENFUNC_PROTO(Func850){ 
WORD displ;
LONG r;
int reg;
displ=GET_SI16;
reg=UBITS(0,2,iw);
r=AREG(reg);
PUSH_L(r);
AREG(reg)=SP;
SP+=displ;
THREAD
; }
GENFUNC_PROTO(Func851){ 
int reg=UBITS(0,2,iw);
SP=AREG(reg);
AREG(reg)=POP_L();
THREAD
; }
GENFUNC_PROTO(Func852){ 
if (!SUPERVISOR_MODE) ex_privileged();
else AREG(8)=AREG(UBITS(0,2,iw));
THREAD
; }
GENFUNC_PROTO(Func853){ 
if (!SUPERVISOR_MODE) ex_privileged();
else AREG(UBITS(0,2,iw))=AREG(8);
THREAD
; }
GENFUNC_PROTO(Func854){ 
if (!SUPERVISOR_MODE) ex_privileged();
else ex_reset();
THREAD
; }
GENFUNC_PROTO(Func855){ THREAD; }
GENFUNC_PROTO(Func856){ 
if (!SUPERVISOR_MODE) ex_privileged();
else
{
	sr = GET_SI16;
	sr &= MASK_SR;
	CHECK_CCR();
	/* FIXME TRACE ?? */
	CHECK_IPL();
	ex_stop();
}
THREAD
; }
GENFUNC_PROTO(Func857){ 
if (!SUPERVISOR_MODE)  ex_privileged();
else
{
        sr = POP_UW() & MASK_SR;
        CHECK_CCR();
        pc = POP_UL();
        if (!SUPERVISOR_MODE) enter_user_mode();
        /* not sure about the order */
        CHECK_PC();
        CHECK_TRACE();
        CHECK_NOTRACE();
        CHECK_IPL();
}
THREAD
; }
GENFUNC_PROTO(Func858){ 
pc = POP_UL();
CHECK_PC();
THREAD
; }
GENFUNC_PROTO(Func859){ 
if (sr & MASK_CC_V) ex_overflow();
THREAD
; }
GENFUNC_PROTO(Func860){ 
UW ccr;
ccr = POP_UW() & MASK_CC;
sr &= ~MASK_CC;
sr |= ccr;
CHECK_CCR();
pc = POP_UL();
CHECK_PC();
THREAD
; }
GENFUNC_PROTO(Func861){ 
ULONG t=V_AN_I_WORD((UBITS(0,5,iw)&7));
PUSH_UL(pc); pc=t; CHECK_PC();
THREAD_CHECK
; }
GENFUNC_PROTO(Func862){ 
ULONG t=V_AN_D_WORD((UBITS(0,5,iw)&7));
PUSH_UL(pc); pc=t; CHECK_PC();
THREAD_CHECK
; }
GENFUNC_PROTO(Func863){ 
ULONG t=V_AN_R_WORD((UBITS(0,5,iw)&7));
PUSH_UL(pc); pc=t; CHECK_PC();
THREAD_CHECK
; }
GENFUNC_PROTO(Func864){ 
ULONG t=V_ABS_W_WORD();
PUSH_UL(pc); pc=t; CHECK_PC();
THREAD_CHECK
; }
GENFUNC_PROTO(Func865){ 
ULONG t=V_ABS_L_WORD();
PUSH_UL(pc); pc=t; CHECK_PC();
THREAD_CHECK
; }
GENFUNC_PROTO(Func866){ 
ULONG t=V_PC_D_WORD();
PUSH_UL(pc); pc=t; CHECK_PC();
THREAD_CHECK
; }
GENFUNC_PROTO(Func867){ 
ULONG t=V_PC_R_WORD();
PUSH_UL(pc); pc=t; CHECK_PC();
THREAD_CHECK
; }
GENFUNC_PROTO(Func868){ 
pc=V_AN_I_WORD((UBITS(0,5,iw)&7));
CHECK_PC();
THREAD_CHECK
; }
GENFUNC_PROTO(Func869){ 
pc=V_AN_D_WORD((UBITS(0,5,iw)&7));
CHECK_PC();
THREAD_CHECK
; }
GENFUNC_PROTO(Func870){ 
pc=V_AN_R_WORD((UBITS(0,5,iw)&7));
CHECK_PC();
THREAD_CHECK
; }
GENFUNC_PROTO(Func871){ 
pc=V_ABS_W_WORD();
CHECK_PC();
THREAD_CHECK
; }
GENFUNC_PROTO(Func872){ 
pc=V_ABS_L_WORD();
CHECK_PC();
THREAD_CHECK
; }
GENFUNC_PROTO(Func873){ 
pc=V_PC_D_WORD();
CHECK_PC();
THREAD_CHECK
; }
GENFUNC_PROTO(Func874){ 
pc=V_PC_R_WORD();
CHECK_PC();
THREAD_CHECK
; }
GENFUNC_PROTO(Func875){ 
BYTE r,x,s;
s=8;
{B *v_x=DREG_BYTE((UBITS(0,5,iw)&7)); x=LR_BYTE(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
SR_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func876){ ILLEGAL();; }
GENFUNC_PROTO(Func877){ 
BYTE r,x,s;
s=8;
{UL v_x=V_AN_I_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func878){ 
BYTE r,x,s;
s=8;
{UL v_x=V_AN_PI_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func879){ 
BYTE r,x,s;
s=8;
{UL v_x=V_AN_PI_BYTE_All(7); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func880){ 
BYTE r,x,s;
s=8;
{UL v_x=V_AN_PD_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func881){ 
BYTE r,x,s;
s=8;
{UL v_x=V_AN_PD_BYTE_All(7); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func882){ 
BYTE r,x,s;
s=8;
{UL v_x=V_AN_D_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func883){ 
BYTE r,x,s;
s=8;
{UL v_x=V_AN_R_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func884){ 
BYTE r,x,s;
s=8;
{UL v_x=V_ABS_W_BYTE(); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func885){ 
BYTE r,x,s;
s=8;
{UL v_x=V_ABS_L_BYTE(); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func886){ 
WORD r,x,s;
s=8;
{W *v_x=DREG_WORD((UBITS(0,5,iw)&7)); x=LR_WORD(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
SR_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func887){ 
AREG(UBITS(0,2,iw))+=8;
THREAD
; }
GENFUNC_PROTO(Func888){ 
WORD r,x,s;
s=8;
{UL v_x=V_AN_I_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func889){ 
WORD r,x,s;
s=8;
{UL v_x=V_AN_PI_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func890){ 
WORD r,x,s;
s=8;
{UL v_x=V_AN_PD_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func891){ 
WORD r,x,s;
s=8;
{UL v_x=V_AN_D_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func892){ 
WORD r,x,s;
s=8;
{UL v_x=V_AN_R_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func893){ 
WORD r,x,s;
s=8;
{UL v_x=V_ABS_W_WORD(); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func894){ 
WORD r,x,s;
s=8;
{UL v_x=V_ABS_L_WORD(); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func895){ 
LONG r,x,s;
s=8;
{L *v_x=DREG_LONG((UBITS(0,5,iw)&7)); x=LR_LONG(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
SR_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func896){ 
AREG(UBITS(0,2,iw))+=8;
THREAD
; }
GENFUNC_PROTO(Func897){ 
LONG r,x,s;
s=8;
{UL v_x=V_AN_I_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func898){ 
LONG r,x,s;
s=8;
{UL v_x=V_AN_PI_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func899){ 
LONG r,x,s;
s=8;
{UL v_x=V_AN_PD_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
