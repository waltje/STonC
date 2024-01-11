

#include "defs.h"
#include "cpu.h"
#include "gendefs.h"
#include "mem.h"
#include "native.h"
#include "nf.h"
























































































































































































































































































































































































































































GENFUNC_PROTO(Func0){ 
BYTE x;
BYTE imm=GET_SI8;
{B *v_x=DREG_BYTE((UBITS(0,5,iw)&7)); x=LR_BYTE(v_x);
sr &= ~MASK_CC|MASK_CC_X;
x |= imm;
SET_NZ(x);
SR_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1){ 
BYTE x;
BYTE imm=GET_SI8;
{UL v_x=V_AN_I_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);
sr &= ~MASK_CC|MASK_CC_X;
x |= imm;
SET_NZ(x);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func2){ 
BYTE x;
BYTE imm=GET_SI8;
{UL v_x=V_AN_PI_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);
sr &= ~MASK_CC|MASK_CC_X;
x |= imm;
SET_NZ(x);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func3){ 
BYTE x;
BYTE imm=GET_SI8;
{UL v_x=V_AN_PI_BYTE_All(7); x=CL_BYTE(v_x);
sr &= ~MASK_CC|MASK_CC_X;
x |= imm;
SET_NZ(x);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func4){ 
BYTE x;
BYTE imm=GET_SI8;
{UL v_x=V_AN_PD_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);
sr &= ~MASK_CC|MASK_CC_X;
x |= imm;
SET_NZ(x);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func5){ 
BYTE x;
BYTE imm=GET_SI8;
{UL v_x=V_AN_PD_BYTE_All(7); x=CL_BYTE(v_x);
sr &= ~MASK_CC|MASK_CC_X;
x |= imm;
SET_NZ(x);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func6){ 
BYTE x;
BYTE imm=GET_SI8;
{UL v_x=V_AN_D_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);
sr &= ~MASK_CC|MASK_CC_X;
x |= imm;
SET_NZ(x);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func7){ 
BYTE x;
BYTE imm=GET_SI8;
{UL v_x=V_AN_R_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);
sr &= ~MASK_CC|MASK_CC_X;
x |= imm;
SET_NZ(x);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func8){ 
BYTE x;
BYTE imm=GET_SI8;
{UL v_x=V_ABS_W_BYTE(); x=CL_BYTE(v_x);
sr &= ~MASK_CC|MASK_CC_X;
x |= imm;
SET_NZ(x);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func9){ 
BYTE x;
BYTE imm=GET_SI8;
{UL v_x=V_ABS_L_BYTE(); x=CL_BYTE(v_x);
sr &= ~MASK_CC|MASK_CC_X;
x |= imm;
SET_NZ(x);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func10){ 
BYTE imm=GET_SI8;
FIX_CCR(); sr &= ~MASK_CC; sr |= imm & MASK_CC; CHECK_CCR();
THREAD
; }
GENFUNC_PROTO(Func11){ 
WORD x;
WORD imm=GET_SI16;
{W *v_x=DREG_WORD((UBITS(0,5,iw)&7)); x=LR_WORD(v_x);
sr &= ~MASK_CC|MASK_CC_X;
x |= imm;
SET_NZ(x);
SR_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func12){ 
WORD x;
WORD imm=GET_SI16;
{UL v_x=V_AN_I_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);
sr &= ~MASK_CC|MASK_CC_X;
x |= imm;
SET_NZ(x);
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func13){ 
WORD x;
WORD imm=GET_SI16;
{UL v_x=V_AN_PI_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);
sr &= ~MASK_CC|MASK_CC_X;
x |= imm;
SET_NZ(x);
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func14){ 
WORD x;
WORD imm=GET_SI16;
{UL v_x=V_AN_PD_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);
sr &= ~MASK_CC|MASK_CC_X;
x |= imm;
SET_NZ(x);
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func15){ 
WORD x;
WORD imm=GET_SI16;
{UL v_x=V_AN_D_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);
sr &= ~MASK_CC|MASK_CC_X;
x |= imm;
SET_NZ(x);
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func16){ 
WORD x;
WORD imm=GET_SI16;
{UL v_x=V_AN_R_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);
sr &= ~MASK_CC|MASK_CC_X;
x |= imm;
SET_NZ(x);
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func17){ 
WORD x;
WORD imm=GET_SI16;
{UL v_x=V_ABS_W_WORD(); x=CL_WORD(v_x);
sr &= ~MASK_CC|MASK_CC_X;
x |= imm;
SET_NZ(x);
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func18){ 
WORD x;
WORD imm=GET_SI16;
{UL v_x=V_ABS_L_WORD(); x=CL_WORD(v_x);
sr &= ~MASK_CC|MASK_CC_X;
x |= imm;
SET_NZ(x);
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func19){ 
WORD imm=GET_SI16;
FIX_CCR();
if (!SUPERVISOR_MODE) ex_privileged();
else sr |= imm & MASK_SR;
CHECK_CCR();
CHECK_TRACE();
CHECK_IPL();
THREAD;
; }
GENFUNC_PROTO(Func20){ 
LONG x;
LONG imm=GET_SI32;
{L *v_x=DREG_LONG((UBITS(0,5,iw)&7)); x=LR_LONG(v_x);
sr &= ~MASK_CC|MASK_CC_X;
x |= imm;
SET_NZ(x);
SR_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func21){ 
LONG x;
LONG imm=GET_SI32;
{UL v_x=V_AN_I_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);
sr &= ~MASK_CC|MASK_CC_X;
x |= imm;
SET_NZ(x);
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func22){ 
LONG x;
LONG imm=GET_SI32;
{UL v_x=V_AN_PI_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);
sr &= ~MASK_CC|MASK_CC_X;
x |= imm;
SET_NZ(x);
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func23){ 
LONG x;
LONG imm=GET_SI32;
{UL v_x=V_AN_PD_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);
sr &= ~MASK_CC|MASK_CC_X;
x |= imm;
SET_NZ(x);
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func24){ 
LONG x;
LONG imm=GET_SI32;
{UL v_x=V_AN_D_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);
sr &= ~MASK_CC|MASK_CC_X;
x |= imm;
SET_NZ(x);
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func25){ 
LONG x;
LONG imm=GET_SI32;
{UL v_x=V_AN_R_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);
sr &= ~MASK_CC|MASK_CC_X;
x |= imm;
SET_NZ(x);
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func26){ 
LONG x;
LONG imm=GET_SI32;
{UL v_x=V_ABS_W_LONG(); x=CL_LONG(v_x);
sr &= ~MASK_CC|MASK_CC_X;
x |= imm;
SET_NZ(x);
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func27){ 
LONG x;
LONG imm=GET_SI32;
{UL v_x=V_ABS_L_LONG(); x=CL_LONG(v_x);
sr &= ~MASK_CC|MASK_CC_X;
x |= imm;
SET_NZ(x);
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func28){ 
UNSET_Z(); if (!(((DREG(UBITS(0,2,iw)))>>(DREG(UBITS(9,11,iw))&31))&1)) SET_Z();
; THREAD; }
GENFUNC_PROTO(Func29){ 
ULONG d=AREG(UBITS(0,2,iw))+GET_SI16;
SDREG_W(UBITS(9,11,iw),(CL_B(d)<<8)|(CL_B(d+2)&0xff));
THREAD;
; }
GENFUNC_PROTO(Func30){ 
int x;
x=CL_BYTE(V_AN_I_BYTE((UBITS(0,5,iw)&7)));;

UNSET_Z(); if (!(((x)>>(DREG(UBITS(9,11,iw))&7))&1)) SET_Z();
;
THREAD
; }
GENFUNC_PROTO(Func31){ 
int x;
x=CL_BYTE(V_AN_PI_BYTE((UBITS(0,5,iw)&7)));;

UNSET_Z(); if (!(((x)>>(DREG(UBITS(9,11,iw))&7))&1)) SET_Z();
;
THREAD
; }
GENFUNC_PROTO(Func32){ 
int x;
x=CL_BYTE(V_AN_PI_BYTE_All(7));;

UNSET_Z(); if (!(((x)>>(DREG(UBITS(9,11,iw))&7))&1)) SET_Z();
;
THREAD
; }
GENFUNC_PROTO(Func33){ 
int x;
x=CL_BYTE(V_AN_PD_BYTE((UBITS(0,5,iw)&7)));;

UNSET_Z(); if (!(((x)>>(DREG(UBITS(9,11,iw))&7))&1)) SET_Z();
;
THREAD
; }
GENFUNC_PROTO(Func34){ 
int x;
x=CL_BYTE(V_AN_PD_BYTE_All(7));;

UNSET_Z(); if (!(((x)>>(DREG(UBITS(9,11,iw))&7))&1)) SET_Z();
;
THREAD
; }
GENFUNC_PROTO(Func35){ 
int x;
x=CL_BYTE(V_AN_D_BYTE((UBITS(0,5,iw)&7)));;

UNSET_Z(); if (!(((x)>>(DREG(UBITS(9,11,iw))&7))&1)) SET_Z();
;
THREAD
; }
GENFUNC_PROTO(Func36){ 
int x;
x=CL_BYTE(V_AN_R_BYTE((UBITS(0,5,iw)&7)));;

UNSET_Z(); if (!(((x)>>(DREG(UBITS(9,11,iw))&7))&1)) SET_Z();
;
THREAD
; }
GENFUNC_PROTO(Func37){ 
int x;
x=CL_BYTE(V_ABS_W_BYTE());;

UNSET_Z(); if (!(((x)>>(DREG(UBITS(9,11,iw))&7))&1)) SET_Z();
;
THREAD
; }
GENFUNC_PROTO(Func38){ 
int x;
x=CL_BYTE(V_ABS_L_BYTE());;

UNSET_Z(); if (!(((x)>>(DREG(UBITS(9,11,iw))&7))&1)) SET_Z();
;
THREAD
; }
GENFUNC_PROTO(Func39){ 
int x;
x=CL_BYTE(V_PC_D_BYTE());;

UNSET_Z(); if (!(((x)>>(DREG(UBITS(9,11,iw))&7))&1)) SET_Z();
;
THREAD
; }
GENFUNC_PROTO(Func40){ 
int x;
x=CL_BYTE(V_PC_R_BYTE());;

UNSET_Z(); if (!(((x)>>(DREG(UBITS(9,11,iw))&7))&1)) SET_Z();
;
THREAD
; }
GENFUNC_PROTO(Func41){ 
int x;
x=LM_BYTE(MEM(V_IMM_BYTE()));;

UNSET_Z(); if (!(((x)>>(DREG(UBITS(9,11,iw))&7))&1)) SET_Z();
;
THREAD
; }
GENFUNC_PROTO(Func42){ 
UNSET_Z();
if (!(((DREG(UBITS(0,2,iw)))>>(DREG(UBITS(9,11,iw))&31))&1)) SET_Z();
DREG(UBITS(0,2,iw)) ^= 1<<(DREG(UBITS(9,11,iw))&31);
THREAD
; THREAD; }
GENFUNC_PROTO(Func43){ 
ULONG d=AREG(UBITS(0,2,iw))+GET_SI16;
SDREG_L(UBITS(9,11,iw),(CL_B(d)<<24)|((CL_B(d+2)&0xff)<<16)
	|((CL_B(d+4)&0xff)<<8)|(CL_B(d+6)&0xff));
THREAD;
; }
GENFUNC_PROTO(Func44){ 
int x;
int n;
{UL v_x=V_AN_I_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
n=DREG(UBITS(9,11,iw))&7;

UNSET_Z();
if (!(((x)>>(n))&1)) SET_Z();
x ^= 1<<(n);
THREAD

CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func45){ 
int x;
int n;
{UL v_x=V_AN_PI_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
n=DREG(UBITS(9,11,iw))&7;

UNSET_Z();
if (!(((x)>>(n))&1)) SET_Z();
x ^= 1<<(n);
THREAD

CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func46){ 
int x;
int n;
{UL v_x=V_AN_PI_BYTE_All(7); x=CL_BYTE(v_x);;
n=DREG(UBITS(9,11,iw))&7;

UNSET_Z();
if (!(((x)>>(n))&1)) SET_Z();
x ^= 1<<(n);
THREAD

CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func47){ 
int x;
int n;
{UL v_x=V_AN_PD_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
n=DREG(UBITS(9,11,iw))&7;

UNSET_Z();
if (!(((x)>>(n))&1)) SET_Z();
x ^= 1<<(n);
THREAD

CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func48){ 
int x;
int n;
{UL v_x=V_AN_PD_BYTE_All(7); x=CL_BYTE(v_x);;
n=DREG(UBITS(9,11,iw))&7;

UNSET_Z();
if (!(((x)>>(n))&1)) SET_Z();
x ^= 1<<(n);
THREAD

CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func49){ 
int x;
int n;
{UL v_x=V_AN_D_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
n=DREG(UBITS(9,11,iw))&7;

UNSET_Z();
if (!(((x)>>(n))&1)) SET_Z();
x ^= 1<<(n);
THREAD

CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func50){ 
int x;
int n;
{UL v_x=V_AN_R_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
n=DREG(UBITS(9,11,iw))&7;

UNSET_Z();
if (!(((x)>>(n))&1)) SET_Z();
x ^= 1<<(n);
THREAD

CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func51){ 
int x;
int n;
{UL v_x=V_ABS_W_BYTE(); x=CL_BYTE(v_x);;
n=DREG(UBITS(9,11,iw))&7;

UNSET_Z();
if (!(((x)>>(n))&1)) SET_Z();
x ^= 1<<(n);
THREAD

CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func52){ 
int x;
int n;
{UL v_x=V_ABS_L_BYTE(); x=CL_BYTE(v_x);;
n=DREG(UBITS(9,11,iw))&7;

UNSET_Z();
if (!(((x)>>(n))&1)) SET_Z();
x ^= 1<<(n);
THREAD

CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func53){ 
UNSET_Z();
if (!(((DREG(UBITS(0,2,iw)))>>(DREG(UBITS(9,11,iw))&31))&1)) SET_Z();
else DREG(UBITS(0,2,iw)) ^= 1<<(DREG(UBITS(9,11,iw))&31);
THREAD;
; THREAD; }
GENFUNC_PROTO(Func54){ 
UWORD x;
ULONG d=AREG(UBITS(0,2,iw))+GET_SI16;
x=LDREG_UWORD(UBITS(9,11,iw));
CS_B(d,x>>8);CS_B(d+2,x&0xff);
THREAD;
; }
GENFUNC_PROTO(Func55){ 
int x,n;
{UL v_x=V_AN_I_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
n=DREG(UBITS(9,11,iw))&7;

UNSET_Z();
if (!(((x)>>(n))&1)) SET_Z();
else x ^= 1<<(n);
THREAD;

CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func56){ 
int x,n;
{UL v_x=V_AN_PI_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
n=DREG(UBITS(9,11,iw))&7;

UNSET_Z();
if (!(((x)>>(n))&1)) SET_Z();
else x ^= 1<<(n);
THREAD;

CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func57){ 
int x,n;
{UL v_x=V_AN_PI_BYTE_All(7); x=CL_BYTE(v_x);;
n=DREG(UBITS(9,11,iw))&7;

UNSET_Z();
if (!(((x)>>(n))&1)) SET_Z();
else x ^= 1<<(n);
THREAD;

CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func58){ 
int x,n;
{UL v_x=V_AN_PD_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
n=DREG(UBITS(9,11,iw))&7;

UNSET_Z();
if (!(((x)>>(n))&1)) SET_Z();
else x ^= 1<<(n);
THREAD;

CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func59){ 
int x,n;
{UL v_x=V_AN_PD_BYTE_All(7); x=CL_BYTE(v_x);;
n=DREG(UBITS(9,11,iw))&7;

UNSET_Z();
if (!(((x)>>(n))&1)) SET_Z();
else x ^= 1<<(n);
THREAD;

CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func60){ 
int x,n;
{UL v_x=V_AN_D_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
n=DREG(UBITS(9,11,iw))&7;

UNSET_Z();
if (!(((x)>>(n))&1)) SET_Z();
else x ^= 1<<(n);
THREAD;

CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func61){ 
int x,n;
{UL v_x=V_AN_R_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
n=DREG(UBITS(9,11,iw))&7;

UNSET_Z();
if (!(((x)>>(n))&1)) SET_Z();
else x ^= 1<<(n);
THREAD;

CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func62){ 
int x,n;
{UL v_x=V_ABS_W_BYTE(); x=CL_BYTE(v_x);;
n=DREG(UBITS(9,11,iw))&7;

UNSET_Z();
if (!(((x)>>(n))&1)) SET_Z();
else x ^= 1<<(n);
THREAD;

CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func63){ 
int x,n;
{UL v_x=V_ABS_L_BYTE(); x=CL_BYTE(v_x);;
n=DREG(UBITS(9,11,iw))&7;

UNSET_Z();
if (!(((x)>>(n))&1)) SET_Z();
else x ^= 1<<(n);
THREAD;

CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func64){ 
UNSET_Z();
if (!(((DREG(UBITS(0,2,iw)))>>(DREG(UBITS(9,11,iw))&31))&1))
{
	SET_Z();
	DREG(UBITS(0,2,iw)) |= 1<<(DREG(UBITS(9,11,iw))&31);
}
THREAD
; THREAD; }
GENFUNC_PROTO(Func65){ 
ULONG x;
ULONG d=AREG(UBITS(0,2,iw))+GET_SI16;
x=LDREG_ULONG(UBITS(9,11,iw));
CS_B(d,x>>24);
 CS_B(d+2,(x>>16)&0xff);CS_B(d+4,(x>>8)&0xff);CS_B(d+6,x&0xff);
THREAD;
; }
GENFUNC_PROTO(Func66){ 
int x,n;
{UL v_x=V_AN_I_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
n=DREG(UBITS(9,11,iw))&7;

UNSET_Z();
if (!(((x)>>(n))&1))
{
	SET_Z();
	x |= 1<<(n);
}
THREAD

CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func67){ 
int x,n;
{UL v_x=V_AN_PI_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
n=DREG(UBITS(9,11,iw))&7;

UNSET_Z();
if (!(((x)>>(n))&1))
{
	SET_Z();
	x |= 1<<(n);
}
THREAD

CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func68){ 
int x,n;
{UL v_x=V_AN_PI_BYTE_All(7); x=CL_BYTE(v_x);;
n=DREG(UBITS(9,11,iw))&7;

UNSET_Z();
if (!(((x)>>(n))&1))
{
	SET_Z();
	x |= 1<<(n);
}
THREAD

CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func69){ 
int x,n;
{UL v_x=V_AN_PD_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
n=DREG(UBITS(9,11,iw))&7;

UNSET_Z();
if (!(((x)>>(n))&1))
{
	SET_Z();
	x |= 1<<(n);
}
THREAD

CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func70){ 
int x,n;
{UL v_x=V_AN_PD_BYTE_All(7); x=CL_BYTE(v_x);;
n=DREG(UBITS(9,11,iw))&7;

UNSET_Z();
if (!(((x)>>(n))&1))
{
	SET_Z();
	x |= 1<<(n);
}
THREAD

CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func71){ 
int x,n;
{UL v_x=V_AN_D_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
n=DREG(UBITS(9,11,iw))&7;

UNSET_Z();
if (!(((x)>>(n))&1))
{
	SET_Z();
	x |= 1<<(n);
}
THREAD

CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func72){ 
int x,n;
{UL v_x=V_AN_R_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
n=DREG(UBITS(9,11,iw))&7;

UNSET_Z();
if (!(((x)>>(n))&1))
{
	SET_Z();
	x |= 1<<(n);
}
THREAD

CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func73){ 
int x,n;
{UL v_x=V_ABS_W_BYTE(); x=CL_BYTE(v_x);;
n=DREG(UBITS(9,11,iw))&7;

UNSET_Z();
if (!(((x)>>(n))&1))
{
	SET_Z();
	x |= 1<<(n);
}
THREAD

CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func74){ 
int x,n;
{UL v_x=V_ABS_L_BYTE(); x=CL_BYTE(v_x);;
n=DREG(UBITS(9,11,iw))&7;

UNSET_Z();
if (!(((x)>>(n))&1))
{
	SET_Z();
	x |= 1<<(n);
}
THREAD

CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func75){ 
BYTE x,imm=GET_SI8;
{B *v_x=DREG_BYTE((UBITS(0,5,iw)&7)); x=LR_BYTE(v_x);;
sr &= ~MASK_CC | MASK_CC_X;
x &= imm;
SET_NZ(x);
SR_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func76){ 
BYTE x,imm=GET_SI8;
{UL v_x=V_AN_I_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC | MASK_CC_X;
x &= imm;
SET_NZ(x);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func77){ 
BYTE x,imm=GET_SI8;
{UL v_x=V_AN_PI_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC | MASK_CC_X;
x &= imm;
SET_NZ(x);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func78){ 
BYTE x,imm=GET_SI8;
{UL v_x=V_AN_PI_BYTE_All(7); x=CL_BYTE(v_x);;
sr &= ~MASK_CC | MASK_CC_X;
x &= imm;
SET_NZ(x);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func79){ 
BYTE x,imm=GET_SI8;
{UL v_x=V_AN_PD_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC | MASK_CC_X;
x &= imm;
SET_NZ(x);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func80){ 
BYTE x,imm=GET_SI8;
{UL v_x=V_AN_PD_BYTE_All(7); x=CL_BYTE(v_x);;
sr &= ~MASK_CC | MASK_CC_X;
x &= imm;
SET_NZ(x);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func81){ 
BYTE x,imm=GET_SI8;
{UL v_x=V_AN_D_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC | MASK_CC_X;
x &= imm;
SET_NZ(x);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func82){ 
BYTE x,imm=GET_SI8;
{UL v_x=V_AN_R_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC | MASK_CC_X;
x &= imm;
SET_NZ(x);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func83){ 
BYTE x,imm=GET_SI8;
{UL v_x=V_ABS_W_BYTE(); x=CL_BYTE(v_x);;
sr &= ~MASK_CC | MASK_CC_X;
x &= imm;
SET_NZ(x);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func84){ 
BYTE x,imm=GET_SI8;
{UL v_x=V_ABS_L_BYTE(); x=CL_BYTE(v_x);;
sr &= ~MASK_CC | MASK_CC_X;
x &= imm;
SET_NZ(x);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func85){ 
UBYTE imm=GET_SI8;
FIX_CCR();
sr &= ~MASK_CC | (imm & MASK_CC);
CHECK_CCR();
THREAD
; }
GENFUNC_PROTO(Func86){ 
WORD x,imm=GET_SI16;
{W *v_x=DREG_WORD((UBITS(0,5,iw)&7)); x=LR_WORD(v_x);;
sr &= ~MASK_CC | MASK_CC_X;
x &= imm;
SET_NZ(x);
SR_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func87){ 
WORD x,imm=GET_SI16;
{UL v_x=V_AN_I_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC | MASK_CC_X;
x &= imm;
SET_NZ(x);
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func88){ 
WORD x,imm=GET_SI16;
{UL v_x=V_AN_PI_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC | MASK_CC_X;
x &= imm;
SET_NZ(x);
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func89){ 
WORD x,imm=GET_SI16;
{UL v_x=V_AN_PD_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC | MASK_CC_X;
x &= imm;
SET_NZ(x);
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func90){ 
WORD x,imm=GET_SI16;
{UL v_x=V_AN_D_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC | MASK_CC_X;
x &= imm;
SET_NZ(x);
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func91){ 
WORD x,imm=GET_SI16;
{UL v_x=V_AN_R_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC | MASK_CC_X;
x &= imm;
SET_NZ(x);
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func92){ 
WORD x,imm=GET_SI16;
{UL v_x=V_ABS_W_WORD(); x=CL_WORD(v_x);;
sr &= ~MASK_CC | MASK_CC_X;
x &= imm;
SET_NZ(x);
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func93){ 
WORD x,imm=GET_SI16;
{UL v_x=V_ABS_L_WORD(); x=CL_WORD(v_x);;
sr &= ~MASK_CC | MASK_CC_X;
x &= imm;
SET_NZ(x);
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func94){ 
UWORD imm=GET_SI16;
if (!SUPERVISOR_MODE) ex_privileged();
else
{
	FIX_CCR();
	sr &= imm; 
	CHECK_CCR();
	if ((imm & SR_S) == 0)  /* going to user-mode */
		enter_user_mode();
	CHECK_NOTRACE();
	CHECK_IPL();
}
THREAD
; }
GENFUNC_PROTO(Func95){ 
LONG x,imm=GET_SI32;
{L *v_x=DREG_LONG((UBITS(0,5,iw)&7)); x=LR_LONG(v_x);;
sr &= ~MASK_CC | MASK_CC_X;
x &= imm;
SET_NZ(x);
SR_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func96){ 
LONG x,imm=GET_SI32;
{UL v_x=V_AN_I_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC | MASK_CC_X;
x &= imm;
SET_NZ(x);
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func97){ 
LONG x,imm=GET_SI32;
{UL v_x=V_AN_PI_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC | MASK_CC_X;
x &= imm;
SET_NZ(x);
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func98){ 
LONG x,imm=GET_SI32;
{UL v_x=V_AN_PD_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC | MASK_CC_X;
x &= imm;
SET_NZ(x);
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func99){ 
LONG x,imm=GET_SI32;
{UL v_x=V_AN_D_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC | MASK_CC_X;
x &= imm;
SET_NZ(x);
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func100){ 
LONG x,imm=GET_SI32;
{UL v_x=V_AN_R_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC | MASK_CC_X;
x &= imm;
SET_NZ(x);
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func101){ 
LONG x,imm=GET_SI32;
{UL v_x=V_ABS_W_LONG(); x=CL_LONG(v_x);;
sr &= ~MASK_CC | MASK_CC_X;
x &= imm;
SET_NZ(x);
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func102){ 
LONG x,imm=GET_SI32;
{UL v_x=V_ABS_L_LONG(); x=CL_LONG(v_x);;
sr &= ~MASK_CC | MASK_CC_X;
x &= imm;
SET_NZ(x);
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func103){ 
BYTE r,x,s;
s=GET_SI8;
{B *v_x=DREG_BYTE((UBITS(0,5,iw)&7)); x=LR_BYTE(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
x=r;
SET_NZ(x);
SR_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func104){ 
BYTE r,x,s;
s=GET_SI8;
{UL v_x=V_AN_I_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
x=r;
SET_NZ(x);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func105){ 
BYTE r,x,s;
s=GET_SI8;
{UL v_x=V_AN_PI_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
x=r;
SET_NZ(x);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func106){ 
BYTE r,x,s;
s=GET_SI8;
{UL v_x=V_AN_PI_BYTE_All(7); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
x=r;
SET_NZ(x);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func107){ 
BYTE r,x,s;
s=GET_SI8;
{UL v_x=V_AN_PD_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
x=r;
SET_NZ(x);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func108){ 
BYTE r,x,s;
s=GET_SI8;
{UL v_x=V_AN_PD_BYTE_All(7); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
x=r;
SET_NZ(x);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func109){ 
BYTE r,x,s;
s=GET_SI8;
{UL v_x=V_AN_D_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
x=r;
SET_NZ(x);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func110){ 
BYTE r,x,s;
s=GET_SI8;
{UL v_x=V_AN_R_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
x=r;
SET_NZ(x);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func111){ 
BYTE r,x,s;
s=GET_SI8;
{UL v_x=V_ABS_W_BYTE(); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
x=r;
SET_NZ(x);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func112){ 
BYTE r,x,s;
s=GET_SI8;
{UL v_x=V_ABS_L_BYTE(); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
x=r;
SET_NZ(x);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func113){ 
WORD r,x,s;
s=GET_SI16;
{W *v_x=DREG_WORD((UBITS(0,5,iw)&7)); x=LR_WORD(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
x=r;
SET_NZ(x);
SR_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func114){ 
WORD r,x,s;
s=GET_SI16;
{UL v_x=V_AN_I_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
x=r;
SET_NZ(x);
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func115){ 
WORD r,x,s;
s=GET_SI16;
{UL v_x=V_AN_PI_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
x=r;
SET_NZ(x);
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func116){ 
WORD r,x,s;
s=GET_SI16;
{UL v_x=V_AN_PD_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
x=r;
SET_NZ(x);
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func117){ 
WORD r,x,s;
s=GET_SI16;
{UL v_x=V_AN_D_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
x=r;
SET_NZ(x);
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func118){ 
WORD r,x,s;
s=GET_SI16;
{UL v_x=V_AN_R_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
x=r;
SET_NZ(x);
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func119){ 
WORD r,x,s;
s=GET_SI16;
{UL v_x=V_ABS_W_WORD(); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
x=r;
SET_NZ(x);
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func120){ 
WORD r,x,s;
s=GET_SI16;
{UL v_x=V_ABS_L_WORD(); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
x=r;
SET_NZ(x);
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func121){ 
LONG r,x,s;
s=GET_SI32;
{L *v_x=DREG_LONG((UBITS(0,5,iw)&7)); x=LR_LONG(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
x=r;
SET_NZ(x);
SR_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func122){ 
LONG r,x,s;
s=GET_SI32;
{UL v_x=V_AN_I_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
x=r;
SET_NZ(x);
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func123){ 
LONG r,x,s;
s=GET_SI32;
{UL v_x=V_AN_PI_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
x=r;
SET_NZ(x);
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func124){ 
LONG r,x,s;
s=GET_SI32;
{UL v_x=V_AN_PD_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
x=r;
SET_NZ(x);
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func125){ 
LONG r,x,s;
s=GET_SI32;
{UL v_x=V_AN_D_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
x=r;
SET_NZ(x);
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func126){ 
LONG r,x,s;
s=GET_SI32;
{UL v_x=V_AN_R_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
x=r;
SET_NZ(x);
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func127){ 
LONG r,x,s;
s=GET_SI32;
{UL v_x=V_ABS_W_LONG(); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
x=r;
SET_NZ(x);
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func128){ 
LONG r,x,s;
s=GET_SI32;
{UL v_x=V_ABS_L_LONG(); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
x=r;
SET_NZ(x);
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func129){ 
BYTE r,x,s;
s=GET_SI8;
{B *v_x=DREG_BYTE((UBITS(0,5,iw)&7)); x=LR_BYTE(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
x=r;
SET_NZ(x);
SR_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func130){ 
BYTE r,x,s;
s=GET_SI8;
{UL v_x=V_AN_I_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
x=r;
SET_NZ(x);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func131){ 
BYTE r,x,s;
s=GET_SI8;
{UL v_x=V_AN_PI_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
x=r;
SET_NZ(x);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func132){ 
BYTE r,x,s;
s=GET_SI8;
{UL v_x=V_AN_PI_BYTE_All(7); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
x=r;
SET_NZ(x);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func133){ 
BYTE r,x,s;
s=GET_SI8;
{UL v_x=V_AN_PD_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
x=r;
SET_NZ(x);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func134){ 
BYTE r,x,s;
s=GET_SI8;
{UL v_x=V_AN_PD_BYTE_All(7); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
x=r;
SET_NZ(x);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func135){ 
BYTE r,x,s;
s=GET_SI8;
{UL v_x=V_AN_D_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
x=r;
SET_NZ(x);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func136){ 
BYTE r,x,s;
s=GET_SI8;
{UL v_x=V_AN_R_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
x=r;
SET_NZ(x);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func137){ 
BYTE r,x,s;
s=GET_SI8;
{UL v_x=V_ABS_W_BYTE(); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
x=r;
SET_NZ(x);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func138){ 
BYTE r,x,s;
s=GET_SI8;
{UL v_x=V_ABS_L_BYTE(); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
x=r;
SET_NZ(x);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func139){ 
WORD r,x,s;
s=GET_SI16;
{W *v_x=DREG_WORD((UBITS(0,5,iw)&7)); x=LR_WORD(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
x=r;
SET_NZ(x);
SR_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func140){ 
WORD r,x,s;
s=GET_SI16;
{UL v_x=V_AN_I_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
x=r;
SET_NZ(x);
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func141){ 
WORD r,x,s;
s=GET_SI16;
{UL v_x=V_AN_PI_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
x=r;
SET_NZ(x);
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func142){ 
WORD r,x,s;
s=GET_SI16;
{UL v_x=V_AN_PD_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
x=r;
SET_NZ(x);
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func143){ 
WORD r,x,s;
s=GET_SI16;
{UL v_x=V_AN_D_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
x=r;
SET_NZ(x);
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func144){ 
WORD r,x,s;
s=GET_SI16;
{UL v_x=V_AN_R_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
x=r;
SET_NZ(x);
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func145){ 
WORD r,x,s;
s=GET_SI16;
{UL v_x=V_ABS_W_WORD(); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
x=r;
SET_NZ(x);
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func146){ 
WORD r,x,s;
s=GET_SI16;
{UL v_x=V_ABS_L_WORD(); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
x=r;
SET_NZ(x);
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func147){ 
LONG r,x,s;
s=GET_SI32;
{L *v_x=DREG_LONG((UBITS(0,5,iw)&7)); x=LR_LONG(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
x=r;
SET_NZ(x);
SR_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func148){ 
LONG r,x,s;
s=GET_SI32;
{UL v_x=V_AN_I_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
x=r;
SET_NZ(x);
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func149){ 
LONG r,x,s;
s=GET_SI32;
{UL v_x=V_AN_PI_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
x=r;
SET_NZ(x);
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func150){ 
LONG r,x,s;
s=GET_SI32;
{UL v_x=V_AN_PD_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
x=r;
SET_NZ(x);
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func151){ 
LONG r,x,s;
s=GET_SI32;
{UL v_x=V_AN_D_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
x=r;
SET_NZ(x);
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func152){ 
LONG r,x,s;
s=GET_SI32;
{UL v_x=V_AN_R_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
x=r;
SET_NZ(x);
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func153){ 
LONG r,x,s;
s=GET_SI32;
{UL v_x=V_ABS_W_LONG(); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
x=r;
SET_NZ(x);
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func154){ 
LONG r,x,s;
s=GET_SI32;
{UL v_x=V_ABS_L_LONG(); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
x=r;
SET_NZ(x);
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func155){ 
int n=GET_SI8;

UNSET_Z(); if (!(((DREG(UBITS(0,2,iw)))>>(n&31))&1)) SET_Z();
;
THREAD
; }
GENFUNC_PROTO(Func156){ 
int x;
int n=GET_SI8;
x=CL_BYTE(V_AN_I_BYTE((UBITS(0,5,iw)&7)));;

UNSET_Z(); if (!(((x)>>(n&7))&1)) SET_Z();
;
THREAD
; }
GENFUNC_PROTO(Func157){ 
int x;
int n=GET_SI8;
x=CL_BYTE(V_AN_PI_BYTE((UBITS(0,5,iw)&7)));;

UNSET_Z(); if (!(((x)>>(n&7))&1)) SET_Z();
;
THREAD
; }
GENFUNC_PROTO(Func158){ 
int x;
int n=GET_SI8;
x=CL_BYTE(V_AN_PI_BYTE_All(7));;

UNSET_Z(); if (!(((x)>>(n&7))&1)) SET_Z();
;
THREAD
; }
GENFUNC_PROTO(Func159){ 
int x;
int n=GET_SI8;
x=CL_BYTE(V_AN_PD_BYTE((UBITS(0,5,iw)&7)));;

UNSET_Z(); if (!(((x)>>(n&7))&1)) SET_Z();
;
THREAD
; }
GENFUNC_PROTO(Func160){ 
int x;
int n=GET_SI8;
x=CL_BYTE(V_AN_PD_BYTE_All(7));;

UNSET_Z(); if (!(((x)>>(n&7))&1)) SET_Z();
;
THREAD
; }
GENFUNC_PROTO(Func161){ 
int x;
int n=GET_SI8;
x=CL_BYTE(V_AN_D_BYTE((UBITS(0,5,iw)&7)));;

UNSET_Z(); if (!(((x)>>(n&7))&1)) SET_Z();
;
THREAD
; }
GENFUNC_PROTO(Func162){ 
int x;
int n=GET_SI8;
x=CL_BYTE(V_AN_R_BYTE((UBITS(0,5,iw)&7)));;

UNSET_Z(); if (!(((x)>>(n&7))&1)) SET_Z();
;
THREAD
; }
GENFUNC_PROTO(Func163){ 
int x;
int n=GET_SI8;
x=CL_BYTE(V_ABS_W_BYTE());;

UNSET_Z(); if (!(((x)>>(n&7))&1)) SET_Z();
;
THREAD
; }
GENFUNC_PROTO(Func164){ 
int x;
int n=GET_SI8;
x=CL_BYTE(V_ABS_L_BYTE());;

UNSET_Z(); if (!(((x)>>(n&7))&1)) SET_Z();
;
THREAD
; }
GENFUNC_PROTO(Func165){ 
int x;
int n=GET_SI8;
x=CL_BYTE(V_PC_D_BYTE());;

UNSET_Z(); if (!(((x)>>(n&7))&1)) SET_Z();
;
THREAD
; }
GENFUNC_PROTO(Func166){ 
int x;
int n=GET_SI8;
x=CL_BYTE(V_PC_R_BYTE());;

UNSET_Z(); if (!(((x)>>(n&7))&1)) SET_Z();
;
THREAD
; }
GENFUNC_PROTO(Func167){ 
int n=GET_SI8;

UNSET_Z();
if (!(((DREG(UBITS(0,2,iw)))>>(n&31))&1)) SET_Z();
DREG(UBITS(0,2,iw)) ^= 1<<(n&31);
THREAD
;
THREAD
; }
GENFUNC_PROTO(Func168){ 
int x;
int n=GET_SI8;
{UL v_x=V_AN_I_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;

UNSET_Z();
if (!(((x)>>(n&7))&1)) SET_Z();
x ^= 1<<(n&7);
THREAD

CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func169){ 
int x;
int n=GET_SI8;
{UL v_x=V_AN_PI_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;

UNSET_Z();
if (!(((x)>>(n&7))&1)) SET_Z();
x ^= 1<<(n&7);
THREAD

CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func170){ 
int x;
int n=GET_SI8;
{UL v_x=V_AN_PI_BYTE_All(7); x=CL_BYTE(v_x);;

UNSET_Z();
if (!(((x)>>(n&7))&1)) SET_Z();
x ^= 1<<(n&7);
THREAD

CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func171){ 
int x;
int n=GET_SI8;
{UL v_x=V_AN_PD_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;

UNSET_Z();
if (!(((x)>>(n&7))&1)) SET_Z();
x ^= 1<<(n&7);
THREAD

CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func172){ 
int x;
int n=GET_SI8;
{UL v_x=V_AN_PD_BYTE_All(7); x=CL_BYTE(v_x);;

UNSET_Z();
if (!(((x)>>(n&7))&1)) SET_Z();
x ^= 1<<(n&7);
THREAD

CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func173){ 
int x;
int n=GET_SI8;
{UL v_x=V_AN_D_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;

UNSET_Z();
if (!(((x)>>(n&7))&1)) SET_Z();
x ^= 1<<(n&7);
THREAD

CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func174){ 
int x;
int n=GET_SI8;
{UL v_x=V_AN_R_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;

UNSET_Z();
if (!(((x)>>(n&7))&1)) SET_Z();
x ^= 1<<(n&7);
THREAD

CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func175){ 
int x;
int n=GET_SI8;
{UL v_x=V_ABS_W_BYTE(); x=CL_BYTE(v_x);;

UNSET_Z();
if (!(((x)>>(n&7))&1)) SET_Z();
x ^= 1<<(n&7);
THREAD

CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func176){ 
int x;
int n=GET_SI8;
{UL v_x=V_ABS_L_BYTE(); x=CL_BYTE(v_x);;

UNSET_Z();
if (!(((x)>>(n&7))&1)) SET_Z();
x ^= 1<<(n&7);
THREAD

CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func177){ 
int n=GET_SI8;

UNSET_Z();
if (!(((DREG(UBITS(0,2,iw)))>>(n&31))&1)) SET_Z();
else DREG(UBITS(0,2,iw)) ^= 1<<(n&31);
THREAD;
;
THREAD
; }
GENFUNC_PROTO(Func178){ 
int x;
int n=GET_SI8;
{UL v_x=V_AN_I_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;

UNSET_Z();
if (!(((x)>>(n&7))&1)) SET_Z();
else x ^= 1<<(n&7);
THREAD;

CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func179){ 
int x;
int n=GET_SI8;
{UL v_x=V_AN_PI_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;

UNSET_Z();
if (!(((x)>>(n&7))&1)) SET_Z();
else x ^= 1<<(n&7);
THREAD;

CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func180){ 
int x;
int n=GET_SI8;
{UL v_x=V_AN_PI_BYTE_All(7); x=CL_BYTE(v_x);;

UNSET_Z();
if (!(((x)>>(n&7))&1)) SET_Z();
else x ^= 1<<(n&7);
THREAD;

CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func181){ 
int x;
int n=GET_SI8;
{UL v_x=V_AN_PD_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;

UNSET_Z();
if (!(((x)>>(n&7))&1)) SET_Z();
else x ^= 1<<(n&7);
THREAD;

CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func182){ 
int x;
int n=GET_SI8;
{UL v_x=V_AN_PD_BYTE_All(7); x=CL_BYTE(v_x);;

UNSET_Z();
if (!(((x)>>(n&7))&1)) SET_Z();
else x ^= 1<<(n&7);
THREAD;

CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func183){ 
int x;
int n=GET_SI8;
{UL v_x=V_AN_D_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;

UNSET_Z();
if (!(((x)>>(n&7))&1)) SET_Z();
else x ^= 1<<(n&7);
THREAD;

CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func184){ 
int x;
int n=GET_SI8;
{UL v_x=V_AN_R_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;

UNSET_Z();
if (!(((x)>>(n&7))&1)) SET_Z();
else x ^= 1<<(n&7);
THREAD;

CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func185){ 
int x;
int n=GET_SI8;
{UL v_x=V_ABS_W_BYTE(); x=CL_BYTE(v_x);;

UNSET_Z();
if (!(((x)>>(n&7))&1)) SET_Z();
else x ^= 1<<(n&7);
THREAD;

CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func186){ 
int x;
int n=GET_SI8;
{UL v_x=V_ABS_L_BYTE(); x=CL_BYTE(v_x);;

UNSET_Z();
if (!(((x)>>(n&7))&1)) SET_Z();
else x ^= 1<<(n&7);
THREAD;

CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func187){ 
int n=GET_SI8;

UNSET_Z();
if (!(((DREG(UBITS(0,2,iw)))>>(n&31))&1))
{
	SET_Z();
	DREG(UBITS(0,2,iw)) |= 1<<(n&31);
}
THREAD
;
THREAD
; }
GENFUNC_PROTO(Func188){ 
int x;
int n=GET_SI8;
{UL v_x=V_AN_I_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;

UNSET_Z();
if (!(((x)>>(n&7))&1))
{
	SET_Z();
	x |= 1<<(n&7);
}
THREAD

CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func189){ 
int x;
int n=GET_SI8;
{UL v_x=V_AN_PI_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;

UNSET_Z();
if (!(((x)>>(n&7))&1))
{
	SET_Z();
	x |= 1<<(n&7);
}
THREAD

CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func190){ 
int x;
int n=GET_SI8;
{UL v_x=V_AN_PI_BYTE_All(7); x=CL_BYTE(v_x);;

UNSET_Z();
if (!(((x)>>(n&7))&1))
{
	SET_Z();
	x |= 1<<(n&7);
}
THREAD

CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func191){ 
int x;
int n=GET_SI8;
{UL v_x=V_AN_PD_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;

UNSET_Z();
if (!(((x)>>(n&7))&1))
{
	SET_Z();
	x |= 1<<(n&7);
}
THREAD

CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func192){ 
int x;
int n=GET_SI8;
{UL v_x=V_AN_PD_BYTE_All(7); x=CL_BYTE(v_x);;

UNSET_Z();
if (!(((x)>>(n&7))&1))
{
	SET_Z();
	x |= 1<<(n&7);
}
THREAD

CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func193){ 
int x;
int n=GET_SI8;
{UL v_x=V_AN_D_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;

UNSET_Z();
if (!(((x)>>(n&7))&1))
{
	SET_Z();
	x |= 1<<(n&7);
}
THREAD

CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func194){ 
int x;
int n=GET_SI8;
{UL v_x=V_AN_R_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;

UNSET_Z();
if (!(((x)>>(n&7))&1))
{
	SET_Z();
	x |= 1<<(n&7);
}
THREAD

CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func195){ 
int x;
int n=GET_SI8;
{UL v_x=V_ABS_W_BYTE(); x=CL_BYTE(v_x);;

UNSET_Z();
if (!(((x)>>(n&7))&1))
{
	SET_Z();
	x |= 1<<(n&7);
}
THREAD

CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func196){ 
int x;
int n=GET_SI8;
{UL v_x=V_ABS_L_BYTE(); x=CL_BYTE(v_x);;

UNSET_Z();
if (!(((x)>>(n&7))&1))
{
	SET_Z();
	x |= 1<<(n&7);
}
THREAD

CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func197){ 
BYTE x,imm=GET_SI8;
{B *v_x=DREG_BYTE((UBITS(0,5,iw)&7)); x=LR_BYTE(v_x);;
sr &= ~MASK_CC | MASK_CC_X;
x ^= imm;
SET_NZ(x);
SR_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func198){ 
BYTE x,imm=GET_SI8;
{UL v_x=V_AN_I_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC | MASK_CC_X;
x ^= imm;
SET_NZ(x);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func199){ 
BYTE x,imm=GET_SI8;
{UL v_x=V_AN_PI_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC | MASK_CC_X;
x ^= imm;
SET_NZ(x);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func200){ 
BYTE x,imm=GET_SI8;
{UL v_x=V_AN_PI_BYTE_All(7); x=CL_BYTE(v_x);;
sr &= ~MASK_CC | MASK_CC_X;
x ^= imm;
SET_NZ(x);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func201){ 
BYTE x,imm=GET_SI8;
{UL v_x=V_AN_PD_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC | MASK_CC_X;
x ^= imm;
SET_NZ(x);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func202){ 
BYTE x,imm=GET_SI8;
{UL v_x=V_AN_PD_BYTE_All(7); x=CL_BYTE(v_x);;
sr &= ~MASK_CC | MASK_CC_X;
x ^= imm;
SET_NZ(x);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func203){ 
BYTE x,imm=GET_SI8;
{UL v_x=V_AN_D_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC | MASK_CC_X;
x ^= imm;
SET_NZ(x);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func204){ 
BYTE x,imm=GET_SI8;
{UL v_x=V_AN_R_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC | MASK_CC_X;
x ^= imm;
SET_NZ(x);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func205){ 
BYTE x,imm=GET_SI8;
{UL v_x=V_ABS_W_BYTE(); x=CL_BYTE(v_x);;
sr &= ~MASK_CC | MASK_CC_X;
x ^= imm;
SET_NZ(x);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func206){ 
BYTE x,imm=GET_SI8;
{UL v_x=V_ABS_L_BYTE(); x=CL_BYTE(v_x);;
sr &= ~MASK_CC | MASK_CC_X;
x ^= imm;
SET_NZ(x);
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func207){ 
B imm=GET_SI8;
FIX_CCR();
sr ^= imm & MASK_CC;
CHECK_CCR();
THREAD
; }
GENFUNC_PROTO(Func208){ 
WORD x,imm=GET_SI16;
{W *v_x=DREG_WORD((UBITS(0,5,iw)&7)); x=LR_WORD(v_x);;
sr &= ~MASK_CC | MASK_CC_X;
x ^= imm;
SET_NZ(x);
SR_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func209){ 
WORD x,imm=GET_SI16;
{UL v_x=V_AN_I_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC | MASK_CC_X;
x ^= imm;
SET_NZ(x);
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func210){ 
WORD x,imm=GET_SI16;
{UL v_x=V_AN_PI_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC | MASK_CC_X;
x ^= imm;
SET_NZ(x);
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func211){ 
WORD x,imm=GET_SI16;
{UL v_x=V_AN_PD_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC | MASK_CC_X;
x ^= imm;
SET_NZ(x);
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func212){ 
WORD x,imm=GET_SI16;
{UL v_x=V_AN_D_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC | MASK_CC_X;
x ^= imm;
SET_NZ(x);
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func213){ 
WORD x,imm=GET_SI16;
{UL v_x=V_AN_R_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC | MASK_CC_X;
x ^= imm;
SET_NZ(x);
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func214){ 
WORD x,imm=GET_SI16;
{UL v_x=V_ABS_W_WORD(); x=CL_WORD(v_x);;
sr &= ~MASK_CC | MASK_CC_X;
x ^= imm;
SET_NZ(x);
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func215){ 
WORD x,imm=GET_SI16;
{UL v_x=V_ABS_L_WORD(); x=CL_WORD(v_x);;
sr &= ~MASK_CC | MASK_CC_X;
x ^= imm;
SET_NZ(x);
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func216){ 
W imm=GET_SI16;
if (!SUPERVISOR_MODE) ex_privileged();
else
{   /* TODO: correct so that only valid SR bits are affected */
	FIX_CCR();
	sr ^= imm & MASK_SR;
	CHECK_CCR();
	if (!SUPERVISOR_MODE) enter_user_mode();
	CHECK_TRACE();
	CHECK_NOTRACE();
	CHECK_IPL();
}
THREAD
; }
GENFUNC_PROTO(Func217){ 
LONG x,imm=GET_SI32;
{L *v_x=DREG_LONG((UBITS(0,5,iw)&7)); x=LR_LONG(v_x);;
sr &= ~MASK_CC | MASK_CC_X;
x ^= imm;
SET_NZ(x);
SR_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func218){ 
LONG x,imm=GET_SI32;
{UL v_x=V_AN_I_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC | MASK_CC_X;
x ^= imm;
SET_NZ(x);
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func219){ 
LONG x,imm=GET_SI32;
{UL v_x=V_AN_PI_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC | MASK_CC_X;
x ^= imm;
SET_NZ(x);
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func220){ 
LONG x,imm=GET_SI32;
{UL v_x=V_AN_PD_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC | MASK_CC_X;
x ^= imm;
SET_NZ(x);
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func221){ 
LONG x,imm=GET_SI32;
{UL v_x=V_AN_D_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC | MASK_CC_X;
x ^= imm;
SET_NZ(x);
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func222){ 
LONG x,imm=GET_SI32;
{UL v_x=V_AN_R_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC | MASK_CC_X;
x ^= imm;
SET_NZ(x);
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func223){ 
LONG x,imm=GET_SI32;
{UL v_x=V_ABS_W_LONG(); x=CL_LONG(v_x);;
sr &= ~MASK_CC | MASK_CC_X;
x ^= imm;
SET_NZ(x);
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func224){ 
LONG x,imm=GET_SI32;
{UL v_x=V_ABS_L_LONG(); x=CL_LONG(v_x);;
sr &= ~MASK_CC | MASK_CC_X;
x ^= imm;
SET_NZ(x);
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func225){ 
BYTE xx,imm; 
imm=GET_SI8;
xx=LDREG_BYTE((UBITS(0,5,iw)&7));;

{
BYTE r,s,x;
s=imm; x=xx;
UNSET_NZ();
sr &= ~MASK_CC|MASK_CC_X;
r = x - s;
if ((x^s) < 0 && (s^r) >= 0) sr |= MASK_CC_V;
if ((r&s) < 0 || (~x & (r|s)) < 0) sr |= MASK_CC_C;
SET_NZ(r);
}
THREAD
;
THREAD
; }
GENFUNC_PROTO(Func226){ 
BYTE xx,imm; 
imm=GET_SI8;
xx=CL_BYTE(V_AN_I_BYTE((UBITS(0,5,iw)&7)));;

{
BYTE r,s,x;
s=imm; x=xx;
UNSET_NZ();
sr &= ~MASK_CC|MASK_CC_X;
r = x - s;
if ((x^s) < 0 && (s^r) >= 0) sr |= MASK_CC_V;
if ((r&s) < 0 || (~x & (r|s)) < 0) sr |= MASK_CC_C;
SET_NZ(r);
}
THREAD
;
THREAD
; }
GENFUNC_PROTO(Func227){ 
BYTE xx,imm; 
imm=GET_SI8;
xx=CL_BYTE(V_AN_PI_BYTE((UBITS(0,5,iw)&7)));;

{
BYTE r,s,x;
s=imm; x=xx;
UNSET_NZ();
sr &= ~MASK_CC|MASK_CC_X;
r = x - s;
if ((x^s) < 0 && (s^r) >= 0) sr |= MASK_CC_V;
if ((r&s) < 0 || (~x & (r|s)) < 0) sr |= MASK_CC_C;
SET_NZ(r);
}
THREAD
;
THREAD
; }
GENFUNC_PROTO(Func228){ 
BYTE xx,imm; 
imm=GET_SI8;
xx=CL_BYTE(V_AN_PI_BYTE_All(7));;

{
BYTE r,s,x;
s=imm; x=xx;
UNSET_NZ();
sr &= ~MASK_CC|MASK_CC_X;
r = x - s;
if ((x^s) < 0 && (s^r) >= 0) sr |= MASK_CC_V;
if ((r&s) < 0 || (~x & (r|s)) < 0) sr |= MASK_CC_C;
SET_NZ(r);
}
THREAD
;
THREAD
; }
GENFUNC_PROTO(Func229){ 
BYTE xx,imm; 
imm=GET_SI8;
xx=CL_BYTE(V_AN_PD_BYTE((UBITS(0,5,iw)&7)));;

{
BYTE r,s,x;
s=imm; x=xx;
UNSET_NZ();
sr &= ~MASK_CC|MASK_CC_X;
r = x - s;
if ((x^s) < 0 && (s^r) >= 0) sr |= MASK_CC_V;
if ((r&s) < 0 || (~x & (r|s)) < 0) sr |= MASK_CC_C;
SET_NZ(r);
}
THREAD
;
THREAD
; }
GENFUNC_PROTO(Func230){ 
BYTE xx,imm; 
imm=GET_SI8;
xx=CL_BYTE(V_AN_PD_BYTE_All(7));;

{
BYTE r,s,x;
s=imm; x=xx;
UNSET_NZ();
sr &= ~MASK_CC|MASK_CC_X;
r = x - s;
if ((x^s) < 0 && (s^r) >= 0) sr |= MASK_CC_V;
if ((r&s) < 0 || (~x & (r|s)) < 0) sr |= MASK_CC_C;
SET_NZ(r);
}
THREAD
;
THREAD
; }
GENFUNC_PROTO(Func231){ 
BYTE xx,imm; 
imm=GET_SI8;
xx=CL_BYTE(V_AN_D_BYTE((UBITS(0,5,iw)&7)));;

{
BYTE r,s,x;
s=imm; x=xx;
UNSET_NZ();
sr &= ~MASK_CC|MASK_CC_X;
r = x - s;
if ((x^s) < 0 && (s^r) >= 0) sr |= MASK_CC_V;
if ((r&s) < 0 || (~x & (r|s)) < 0) sr |= MASK_CC_C;
SET_NZ(r);
}
THREAD
;
THREAD
; }
GENFUNC_PROTO(Func232){ 
BYTE xx,imm; 
imm=GET_SI8;
xx=CL_BYTE(V_AN_R_BYTE((UBITS(0,5,iw)&7)));;

{
BYTE r,s,x;
s=imm; x=xx;
UNSET_NZ();
sr &= ~MASK_CC|MASK_CC_X;
r = x - s;
if ((x^s) < 0 && (s^r) >= 0) sr |= MASK_CC_V;
if ((r&s) < 0 || (~x & (r|s)) < 0) sr |= MASK_CC_C;
SET_NZ(r);
}
THREAD
;
THREAD
; }
GENFUNC_PROTO(Func233){ 
BYTE xx,imm; 
imm=GET_SI8;
xx=CL_BYTE(V_ABS_W_BYTE());;

{
BYTE r,s,x;
s=imm; x=xx;
UNSET_NZ();
sr &= ~MASK_CC|MASK_CC_X;
r = x - s;
if ((x^s) < 0 && (s^r) >= 0) sr |= MASK_CC_V;
if ((r&s) < 0 || (~x & (r|s)) < 0) sr |= MASK_CC_C;
SET_NZ(r);
}
THREAD
;
THREAD
; }
GENFUNC_PROTO(Func234){ 
BYTE xx,imm; 
imm=GET_SI8;
xx=CL_BYTE(V_ABS_L_BYTE());;

{
BYTE r,s,x;
s=imm; x=xx;
UNSET_NZ();
sr &= ~MASK_CC|MASK_CC_X;
r = x - s;
if ((x^s) < 0 && (s^r) >= 0) sr |= MASK_CC_V;
if ((r&s) < 0 || (~x & (r|s)) < 0) sr |= MASK_CC_C;
SET_NZ(r);
}
THREAD
;
THREAD
; }
GENFUNC_PROTO(Func235){ 
BYTE xx,imm; 
imm=GET_SI8;
xx=CL_BYTE(V_PC_D_BYTE());;

{
BYTE r,s,x;
s=imm; x=xx;
UNSET_NZ();
sr &= ~MASK_CC|MASK_CC_X;
r = x - s;
if ((x^s) < 0 && (s^r) >= 0) sr |= MASK_CC_V;
if ((r&s) < 0 || (~x & (r|s)) < 0) sr |= MASK_CC_C;
SET_NZ(r);
}
THREAD
;
THREAD
; }
GENFUNC_PROTO(Func236){ 
BYTE xx,imm; 
imm=GET_SI8;
xx=CL_BYTE(V_PC_R_BYTE());;

{
BYTE r,s,x;
s=imm; x=xx;
UNSET_NZ();
sr &= ~MASK_CC|MASK_CC_X;
r = x - s;
if ((x^s) < 0 && (s^r) >= 0) sr |= MASK_CC_V;
if ((r&s) < 0 || (~x & (r|s)) < 0) sr |= MASK_CC_C;
SET_NZ(r);
}
THREAD
;
THREAD
; }
GENFUNC_PROTO(Func237){ 
BYTE xx,imm; 
imm=GET_SI8;
xx=LM_BYTE(MEM(V_IMM_BYTE()));;

{
BYTE r,s,x;
s=imm; x=xx;
UNSET_NZ();
sr &= ~MASK_CC|MASK_CC_X;
r = x - s;
if ((x^s) < 0 && (s^r) >= 0) sr |= MASK_CC_V;
if ((r&s) < 0 || (~x & (r|s)) < 0) sr |= MASK_CC_C;
SET_NZ(r);
}
THREAD
;
THREAD
; }
GENFUNC_PROTO(Func238){ 
WORD xx,imm; 
imm=GET_SI16;
xx=LDREG_WORD((UBITS(0,5,iw)&7));;

{
WORD r,s,x;
s=imm; x=xx;
UNSET_NZ();
sr &= ~MASK_CC|MASK_CC_X;
r = x - s;
if ((x^s) < 0 && (s^r) >= 0) sr |= MASK_CC_V;
if ((r&s) < 0 || (~x & (r|s)) < 0) sr |= MASK_CC_C;
SET_NZ(r);
}
THREAD
;
THREAD
; }
GENFUNC_PROTO(Func239){ 
WORD xx,imm; 
imm=GET_SI16;
xx=CL_WORD(V_AN_I_WORD((UBITS(0,5,iw)&7)));;

{
WORD r,s,x;
s=imm; x=xx;
UNSET_NZ();
sr &= ~MASK_CC|MASK_CC_X;
r = x - s;
if ((x^s) < 0 && (s^r) >= 0) sr |= MASK_CC_V;
if ((r&s) < 0 || (~x & (r|s)) < 0) sr |= MASK_CC_C;
SET_NZ(r);
}
THREAD
;
THREAD
; }
GENFUNC_PROTO(Func240){ 
WORD xx,imm; 
imm=GET_SI16;
xx=CL_WORD(V_AN_PI_WORD((UBITS(0,5,iw)&7)));;

{
WORD r,s,x;
s=imm; x=xx;
UNSET_NZ();
sr &= ~MASK_CC|MASK_CC_X;
r = x - s;
if ((x^s) < 0 && (s^r) >= 0) sr |= MASK_CC_V;
if ((r&s) < 0 || (~x & (r|s)) < 0) sr |= MASK_CC_C;
SET_NZ(r);
}
THREAD
;
THREAD
; }
GENFUNC_PROTO(Func241){ 
WORD xx,imm; 
imm=GET_SI16;
xx=CL_WORD(V_AN_PD_WORD((UBITS(0,5,iw)&7)));;

{
WORD r,s,x;
s=imm; x=xx;
UNSET_NZ();
sr &= ~MASK_CC|MASK_CC_X;
r = x - s;
if ((x^s) < 0 && (s^r) >= 0) sr |= MASK_CC_V;
if ((r&s) < 0 || (~x & (r|s)) < 0) sr |= MASK_CC_C;
SET_NZ(r);
}
THREAD
;
THREAD
; }
GENFUNC_PROTO(Func242){ 
WORD xx,imm; 
imm=GET_SI16;
xx=CL_WORD(V_AN_D_WORD((UBITS(0,5,iw)&7)));;

{
WORD r,s,x;
s=imm; x=xx;
UNSET_NZ();
sr &= ~MASK_CC|MASK_CC_X;
r = x - s;
if ((x^s) < 0 && (s^r) >= 0) sr |= MASK_CC_V;
if ((r&s) < 0 || (~x & (r|s)) < 0) sr |= MASK_CC_C;
SET_NZ(r);
}
THREAD
;
THREAD
; }
GENFUNC_PROTO(Func243){ 
WORD xx,imm; 
imm=GET_SI16;
xx=CL_WORD(V_AN_R_WORD((UBITS(0,5,iw)&7)));;

{
WORD r,s,x;
s=imm; x=xx;
UNSET_NZ();
sr &= ~MASK_CC|MASK_CC_X;
r = x - s;
if ((x^s) < 0 && (s^r) >= 0) sr |= MASK_CC_V;
if ((r&s) < 0 || (~x & (r|s)) < 0) sr |= MASK_CC_C;
SET_NZ(r);
}
THREAD
;
THREAD
; }
GENFUNC_PROTO(Func244){ 
WORD xx,imm; 
imm=GET_SI16;
xx=CL_WORD(V_ABS_W_WORD());;

{
WORD r,s,x;
s=imm; x=xx;
UNSET_NZ();
sr &= ~MASK_CC|MASK_CC_X;
r = x - s;
if ((x^s) < 0 && (s^r) >= 0) sr |= MASK_CC_V;
if ((r&s) < 0 || (~x & (r|s)) < 0) sr |= MASK_CC_C;
SET_NZ(r);
}
THREAD
;
THREAD
; }
GENFUNC_PROTO(Func245){ 
WORD xx,imm; 
imm=GET_SI16;
xx=CL_WORD(V_ABS_L_WORD());;

{
WORD r,s,x;
s=imm; x=xx;
UNSET_NZ();
sr &= ~MASK_CC|MASK_CC_X;
r = x - s;
if ((x^s) < 0 && (s^r) >= 0) sr |= MASK_CC_V;
if ((r&s) < 0 || (~x & (r|s)) < 0) sr |= MASK_CC_C;
SET_NZ(r);
}
THREAD
;
THREAD
; }
GENFUNC_PROTO(Func246){ 
WORD xx,imm; 
imm=GET_SI16;
xx=CL_WORD(V_PC_D_WORD());;

{
WORD r,s,x;
s=imm; x=xx;
UNSET_NZ();
sr &= ~MASK_CC|MASK_CC_X;
r = x - s;
if ((x^s) < 0 && (s^r) >= 0) sr |= MASK_CC_V;
if ((r&s) < 0 || (~x & (r|s)) < 0) sr |= MASK_CC_C;
SET_NZ(r);
}
THREAD
;
THREAD
; }
GENFUNC_PROTO(Func247){ 
WORD xx,imm; 
imm=GET_SI16;
xx=CL_WORD(V_PC_R_WORD());;

{
WORD r,s,x;
s=imm; x=xx;
UNSET_NZ();
sr &= ~MASK_CC|MASK_CC_X;
r = x - s;
if ((x^s) < 0 && (s^r) >= 0) sr |= MASK_CC_V;
if ((r&s) < 0 || (~x & (r|s)) < 0) sr |= MASK_CC_C;
SET_NZ(r);
}
THREAD
;
THREAD
; }
GENFUNC_PROTO(Func248){ 
WORD xx,imm; 
imm=GET_SI16;
xx=LM_WORD(MEM(V_IMM_WORD()));;

{
WORD r,s,x;
s=imm; x=xx;
UNSET_NZ();
sr &= ~MASK_CC|MASK_CC_X;
r = x - s;
if ((x^s) < 0 && (s^r) >= 0) sr |= MASK_CC_V;
if ((r&s) < 0 || (~x & (r|s)) < 0) sr |= MASK_CC_C;
SET_NZ(r);
}
THREAD
;
THREAD
; }
GENFUNC_PROTO(Func249){ 
LONG xx,imm; 
imm=GET_SI32;
xx=LDREG_LONG((UBITS(0,5,iw)&7));;

{
LONG r,s,x;
s=imm; x=xx;
UNSET_NZ();
sr &= ~MASK_CC|MASK_CC_X;
r = x - s;
if ((x^s) < 0 && (s^r) >= 0) sr |= MASK_CC_V;
if ((r&s) < 0 || (~x & (r|s)) < 0) sr |= MASK_CC_C;
SET_NZ(r);
}
THREAD
;
THREAD
; }
GENFUNC_PROTO(Func250){ 
LONG xx,imm; 
imm=GET_SI32;
xx=CL_LONG(V_AN_I_LONG((UBITS(0,5,iw)&7)));;

{
LONG r,s,x;
s=imm; x=xx;
UNSET_NZ();
sr &= ~MASK_CC|MASK_CC_X;
r = x - s;
if ((x^s) < 0 && (s^r) >= 0) sr |= MASK_CC_V;
if ((r&s) < 0 || (~x & (r|s)) < 0) sr |= MASK_CC_C;
SET_NZ(r);
}
THREAD
;
THREAD
; }
GENFUNC_PROTO(Func251){ 
LONG xx,imm; 
imm=GET_SI32;
xx=CL_LONG(V_AN_PI_LONG((UBITS(0,5,iw)&7)));;

{
LONG r,s,x;
s=imm; x=xx;
UNSET_NZ();
sr &= ~MASK_CC|MASK_CC_X;
r = x - s;
if ((x^s) < 0 && (s^r) >= 0) sr |= MASK_CC_V;
if ((r&s) < 0 || (~x & (r|s)) < 0) sr |= MASK_CC_C;
SET_NZ(r);
}
THREAD
;
THREAD
; }
GENFUNC_PROTO(Func252){ 
LONG xx,imm; 
imm=GET_SI32;
xx=CL_LONG(V_AN_PD_LONG((UBITS(0,5,iw)&7)));;

{
LONG r,s,x;
s=imm; x=xx;
UNSET_NZ();
sr &= ~MASK_CC|MASK_CC_X;
r = x - s;
if ((x^s) < 0 && (s^r) >= 0) sr |= MASK_CC_V;
if ((r&s) < 0 || (~x & (r|s)) < 0) sr |= MASK_CC_C;
SET_NZ(r);
}
THREAD
;
THREAD
; }
GENFUNC_PROTO(Func253){ 
LONG xx,imm; 
imm=GET_SI32;
xx=CL_LONG(V_AN_D_LONG((UBITS(0,5,iw)&7)));;

{
LONG r,s,x;
s=imm; x=xx;
UNSET_NZ();
sr &= ~MASK_CC|MASK_CC_X;
r = x - s;
if ((x^s) < 0 && (s^r) >= 0) sr |= MASK_CC_V;
if ((r&s) < 0 || (~x & (r|s)) < 0) sr |= MASK_CC_C;
SET_NZ(r);
}
THREAD
;
THREAD
; }
GENFUNC_PROTO(Func254){ 
LONG xx,imm; 
imm=GET_SI32;
xx=CL_LONG(V_AN_R_LONG((UBITS(0,5,iw)&7)));;

{
LONG r,s,x;
s=imm; x=xx;
UNSET_NZ();
sr &= ~MASK_CC|MASK_CC_X;
r = x - s;
if ((x^s) < 0 && (s^r) >= 0) sr |= MASK_CC_V;
if ((r&s) < 0 || (~x & (r|s)) < 0) sr |= MASK_CC_C;
SET_NZ(r);
}
THREAD
;
THREAD
; }
GENFUNC_PROTO(Func255){ 
LONG xx,imm; 
imm=GET_SI32;
xx=CL_LONG(V_ABS_W_LONG());;

{
LONG r,s,x;
s=imm; x=xx;
UNSET_NZ();
sr &= ~MASK_CC|MASK_CC_X;
r = x - s;
if ((x^s) < 0 && (s^r) >= 0) sr |= MASK_CC_V;
if ((r&s) < 0 || (~x & (r|s)) < 0) sr |= MASK_CC_C;
SET_NZ(r);
}
THREAD
;
THREAD
; }
GENFUNC_PROTO(Func256){ 
LONG xx,imm; 
imm=GET_SI32;
xx=CL_LONG(V_ABS_L_LONG());;

{
LONG r,s,x;
s=imm; x=xx;
UNSET_NZ();
sr &= ~MASK_CC|MASK_CC_X;
r = x - s;
if ((x^s) < 0 && (s^r) >= 0) sr |= MASK_CC_V;
if ((r&s) < 0 || (~x & (r|s)) < 0) sr |= MASK_CC_C;
SET_NZ(r);
}
THREAD
;
THREAD
; }
GENFUNC_PROTO(Func257){ 
LONG xx,imm; 
imm=GET_SI32;
xx=CL_LONG(V_PC_D_LONG());;

{
LONG r,s,x;
s=imm; x=xx;
UNSET_NZ();
sr &= ~MASK_CC|MASK_CC_X;
r = x - s;
if ((x^s) < 0 && (s^r) >= 0) sr |= MASK_CC_V;
if ((r&s) < 0 || (~x & (r|s)) < 0) sr |= MASK_CC_C;
SET_NZ(r);
}
THREAD
;
THREAD
; }
GENFUNC_PROTO(Func258){ 
LONG xx,imm; 
imm=GET_SI32;
xx=CL_LONG(V_PC_R_LONG());;

{
LONG r,s,x;
s=imm; x=xx;
UNSET_NZ();
sr &= ~MASK_CC|MASK_CC_X;
r = x - s;
if ((x^s) < 0 && (s^r) >= 0) sr |= MASK_CC_V;
if ((r&s) < 0 || (~x & (r|s)) < 0) sr |= MASK_CC_C;
SET_NZ(r);
}
THREAD
;
THREAD
; }
GENFUNC_PROTO(Func259){ 
LONG xx,imm; 
imm=GET_SI32;
xx=LM_LONG(MEM(V_IMM_LONG()));;

{
LONG r,s,x;
s=imm; x=xx;
UNSET_NZ();
sr &= ~MASK_CC|MASK_CC_X;
r = x - s;
if ((x^s) < 0 && (s^r) >= 0) sr |= MASK_CC_V;
if ((r&s) < 0 || (~x & (r|s)) < 0) sr |= MASK_CC_C;
SET_NZ(r);
}
THREAD
;
THREAD
; }
GENFUNC_PROTO(Func260){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LDREG_BYTE((UBITS(0,5,iw)&7));;
SET_NZ(x);
SDREG_BYTE((UBITS(6,11,iw)>>3),x);;
THREAD
; }
GENFUNC_PROTO(Func261){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_I_BYTE((UBITS(0,5,iw)&7)));;
SET_NZ(x);
SDREG_BYTE((UBITS(6,11,iw)>>3),x);;
THREAD
; }
GENFUNC_PROTO(Func262){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_PI_BYTE((UBITS(0,5,iw)&7)));;
SET_NZ(x);
SDREG_BYTE((UBITS(6,11,iw)>>3),x);;
THREAD
; }
GENFUNC_PROTO(Func263){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_PI_BYTE_All(7));;
SET_NZ(x);
SDREG_BYTE((UBITS(6,11,iw)>>3),x);;
THREAD
; }
GENFUNC_PROTO(Func264){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_PD_BYTE((UBITS(0,5,iw)&7)));;
SET_NZ(x);
SDREG_BYTE((UBITS(6,11,iw)>>3),x);;
THREAD
; }
GENFUNC_PROTO(Func265){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_PD_BYTE_All(7));;
SET_NZ(x);
SDREG_BYTE((UBITS(6,11,iw)>>3),x);;
THREAD
; }
GENFUNC_PROTO(Func266){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_D_BYTE((UBITS(0,5,iw)&7)));;
SET_NZ(x);
SDREG_BYTE((UBITS(6,11,iw)>>3),x);;
THREAD
; }
GENFUNC_PROTO(Func267){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_R_BYTE((UBITS(0,5,iw)&7)));;
SET_NZ(x);
SDREG_BYTE((UBITS(6,11,iw)>>3),x);;
THREAD
; }
GENFUNC_PROTO(Func268){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_ABS_W_BYTE());;
SET_NZ(x);
SDREG_BYTE((UBITS(6,11,iw)>>3),x);;
THREAD
; }
GENFUNC_PROTO(Func269){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_ABS_L_BYTE());;
SET_NZ(x);
SDREG_BYTE((UBITS(6,11,iw)>>3),x);;
THREAD
; }
GENFUNC_PROTO(Func270){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_PC_D_BYTE());;
SET_NZ(x);
SDREG_BYTE((UBITS(6,11,iw)>>3),x);;
THREAD
; }
GENFUNC_PROTO(Func271){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_PC_R_BYTE());;
SET_NZ(x);
SDREG_BYTE((UBITS(6,11,iw)>>3),x);;
THREAD
; }
GENFUNC_PROTO(Func272){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LM_BYTE(MEM(V_IMM_BYTE()));;
SET_NZ(x);
SDREG_BYTE((UBITS(6,11,iw)>>3),x);;
THREAD
; }
GENFUNC_PROTO(Func273){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LDREG_BYTE((UBITS(0,5,iw)&7));;
SET_NZ(x);
CS_BYTE(V_AN_I_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func274){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_I_BYTE((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_BYTE(V_AN_I_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func275){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_PI_BYTE((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_BYTE(V_AN_I_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func276){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_PI_BYTE_All(7));;
SET_NZ(x);
CS_BYTE(V_AN_I_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func277){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_PD_BYTE((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_BYTE(V_AN_I_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func278){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_PD_BYTE_All(7));;
SET_NZ(x);
CS_BYTE(V_AN_I_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func279){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_D_BYTE((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_BYTE(V_AN_I_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func280){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_R_BYTE((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_BYTE(V_AN_I_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func281){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_ABS_W_BYTE());;
SET_NZ(x);
CS_BYTE(V_AN_I_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func282){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_ABS_L_BYTE());;
SET_NZ(x);
CS_BYTE(V_AN_I_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func283){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_PC_D_BYTE());;
SET_NZ(x);
CS_BYTE(V_AN_I_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func284){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_PC_R_BYTE());;
SET_NZ(x);
CS_BYTE(V_AN_I_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func285){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LM_BYTE(MEM(V_IMM_BYTE()));;
SET_NZ(x);
CS_BYTE(V_AN_I_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func286){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LDREG_BYTE((UBITS(0,5,iw)&7));;
SET_NZ(x);
CS_BYTE(V_AN_PI_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func287){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_I_BYTE((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_BYTE(V_AN_PI_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func288){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_PI_BYTE((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_BYTE(V_AN_PI_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func289){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_PI_BYTE_All(7));;
SET_NZ(x);
CS_BYTE(V_AN_PI_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func290){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_PD_BYTE((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_BYTE(V_AN_PI_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func291){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_PD_BYTE_All(7));;
SET_NZ(x);
CS_BYTE(V_AN_PI_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func292){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_D_BYTE((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_BYTE(V_AN_PI_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func293){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_R_BYTE((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_BYTE(V_AN_PI_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func294){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_ABS_W_BYTE());;
SET_NZ(x);
CS_BYTE(V_AN_PI_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func295){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_ABS_L_BYTE());;
SET_NZ(x);
CS_BYTE(V_AN_PI_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func296){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_PC_D_BYTE());;
SET_NZ(x);
CS_BYTE(V_AN_PI_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func297){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_PC_R_BYTE());;
SET_NZ(x);
CS_BYTE(V_AN_PI_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func298){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LM_BYTE(MEM(V_IMM_BYTE()));;
SET_NZ(x);
CS_BYTE(V_AN_PI_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func299){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LDREG_BYTE((UBITS(0,5,iw)&7));;
SET_NZ(x);
CS_BYTE(V_AN_PD_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
