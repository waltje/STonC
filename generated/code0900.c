

#include "defs.h"
#include "cpu.h"
#include "gendefs.h"
#include "mem.h"
#include "native.h"
#include "nf.h"
























































































































































































































































































































































































































































GENFUNC_PROTO(Func900){ 
LONG r,x,s;
s=8;
{UL v_x=V_AN_D_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func901){ 
LONG r,x,s;
s=8;
{UL v_x=V_AN_R_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func902){ 
LONG r,x,s;
s=8;
{UL v_x=V_ABS_W_LONG(); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func903){ 
LONG r,x,s;
s=8;
{UL v_x=V_ABS_L_LONG(); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func904){ 
SDREG_BYTE((UBITS(0,5,iw)&7),TEST_T ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func905){ 
int r;
WORD x,displ=GET_SI16;
if (!TEST_T)
{
	r=UBITS(0,2,iw);
	x=LDREG_WORD(r)-1;
	SDREG_WORD(r,x);
	if (x != -1)
	{
		pc += displ-2;
		CHECK_PC();
	}
}
THREAD_CHECK
; }
GENFUNC_PROTO(Func906){ 
CS_BYTE(V_AN_I_BYTE((UBITS(0,5,iw)&7)),TEST_T ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func907){ 
CS_BYTE(V_AN_PI_BYTE((UBITS(0,5,iw)&7)),TEST_T ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func908){ 
CS_BYTE(V_AN_PI_BYTE_All(7),TEST_T ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func909){ 
CS_BYTE(V_AN_PD_BYTE((UBITS(0,5,iw)&7)),TEST_T ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func910){ 
CS_BYTE(V_AN_PD_BYTE_All(7),TEST_T ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func911){ 
CS_BYTE(V_AN_D_BYTE((UBITS(0,5,iw)&7)),TEST_T ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func912){ 
CS_BYTE(V_AN_R_BYTE((UBITS(0,5,iw)&7)),TEST_T ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func913){ 
CS_BYTE(V_ABS_W_BYTE(),TEST_T ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func914){ 
CS_BYTE(V_ABS_L_BYTE(),TEST_T ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func915){ 
BYTE r,x,s;
s=8;
{B *v_x=DREG_BYTE((UBITS(0,5,iw)&7)); x=LR_BYTE(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
SR_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func916){ ILLEGAL();; }
GENFUNC_PROTO(Func917){ 
BYTE r,x,s;
s=8;
{UL v_x=V_AN_I_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func918){ 
BYTE r,x,s;
s=8;
{UL v_x=V_AN_PI_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func919){ 
BYTE r,x,s;
s=8;
{UL v_x=V_AN_PI_BYTE_All(7); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func920){ 
BYTE r,x,s;
s=8;
{UL v_x=V_AN_PD_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func921){ 
BYTE r,x,s;
s=8;
{UL v_x=V_AN_PD_BYTE_All(7); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func922){ 
BYTE r,x,s;
s=8;
{UL v_x=V_AN_D_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func923){ 
BYTE r,x,s;
s=8;
{UL v_x=V_AN_R_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func924){ 
BYTE r,x,s;
s=8;
{UL v_x=V_ABS_W_BYTE(); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func925){ 
BYTE r,x,s;
s=8;
{UL v_x=V_ABS_L_BYTE(); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func926){ 
WORD r,x,s;
s=8;
{W *v_x=DREG_WORD((UBITS(0,5,iw)&7)); x=LR_WORD(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
SR_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func927){ 
AREG(UBITS(0,2,iw))-=8;
THREAD
; }
GENFUNC_PROTO(Func928){ 
WORD r,x,s;
s=8;
{UL v_x=V_AN_I_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func929){ 
WORD r,x,s;
s=8;
{UL v_x=V_AN_PI_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func930){ 
WORD r,x,s;
s=8;
{UL v_x=V_AN_PD_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func931){ 
WORD r,x,s;
s=8;
{UL v_x=V_AN_D_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func932){ 
WORD r,x,s;
s=8;
{UL v_x=V_AN_R_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func933){ 
WORD r,x,s;
s=8;
{UL v_x=V_ABS_W_WORD(); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func934){ 
WORD r,x,s;
s=8;
{UL v_x=V_ABS_L_WORD(); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func935){ 
LONG r,x,s;
s=8;
{L *v_x=DREG_LONG((UBITS(0,5,iw)&7)); x=LR_LONG(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
SR_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func936){ 
AREG(UBITS(0,2,iw))-=8;
THREAD
; }
GENFUNC_PROTO(Func937){ 
LONG r,x,s;
s=8;
{UL v_x=V_AN_I_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func938){ 
LONG r,x,s;
s=8;
{UL v_x=V_AN_PI_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func939){ 
LONG r,x,s;
s=8;
{UL v_x=V_AN_PD_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func940){ 
LONG r,x,s;
s=8;
{UL v_x=V_AN_D_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func941){ 
LONG r,x,s;
s=8;
{UL v_x=V_AN_R_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func942){ 
LONG r,x,s;
s=8;
{UL v_x=V_ABS_W_LONG(); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func943){ 
LONG r,x,s;
s=8;
{UL v_x=V_ABS_L_LONG(); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func944){ 
SDREG_BYTE((UBITS(0,5,iw)&7),TEST_F ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func945){ 
int r;
WORD x,displ=GET_SI16;
if (!TEST_F)
{
	r=UBITS(0,2,iw);
	x=LDREG_WORD(r)-1;
	SDREG_WORD(r,x);
	if (x != -1)
	{
		pc += displ-2;
		CHECK_PC();
	}
}
THREAD_CHECK
; }
GENFUNC_PROTO(Func946){ 
CS_BYTE(V_AN_I_BYTE((UBITS(0,5,iw)&7)),TEST_F ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func947){ 
CS_BYTE(V_AN_PI_BYTE((UBITS(0,5,iw)&7)),TEST_F ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func948){ 
CS_BYTE(V_AN_PI_BYTE_All(7),TEST_F ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func949){ 
CS_BYTE(V_AN_PD_BYTE((UBITS(0,5,iw)&7)),TEST_F ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func950){ 
CS_BYTE(V_AN_PD_BYTE_All(7),TEST_F ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func951){ 
CS_BYTE(V_AN_D_BYTE((UBITS(0,5,iw)&7)),TEST_F ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func952){ 
CS_BYTE(V_AN_R_BYTE((UBITS(0,5,iw)&7)),TEST_F ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func953){ 
CS_BYTE(V_ABS_W_BYTE(),TEST_F ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func954){ 
CS_BYTE(V_ABS_L_BYTE(),TEST_F ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func955){ 
BYTE r,x,s;
s=QBITS(9,11,iw);
{B *v_x=DREG_BYTE((UBITS(0,5,iw)&7)); x=LR_BYTE(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
SR_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func956){ 
BYTE r,x,s;
s=QBITS(9,11,iw);
{UL v_x=V_AN_I_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func957){ 
BYTE r,x,s;
s=QBITS(9,11,iw);
{UL v_x=V_AN_PI_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func958){ 
BYTE r,x,s;
s=QBITS(9,11,iw);
{UL v_x=V_AN_PI_BYTE_All(7); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func959){ 
BYTE r,x,s;
s=QBITS(9,11,iw);
{UL v_x=V_AN_PD_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func960){ 
BYTE r,x,s;
s=QBITS(9,11,iw);
{UL v_x=V_AN_PD_BYTE_All(7); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func961){ 
BYTE r,x,s;
s=QBITS(9,11,iw);
{UL v_x=V_AN_D_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func962){ 
BYTE r,x,s;
s=QBITS(9,11,iw);
{UL v_x=V_AN_R_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func963){ 
BYTE r,x,s;
s=QBITS(9,11,iw);
{UL v_x=V_ABS_W_BYTE(); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func964){ 
BYTE r,x,s;
s=QBITS(9,11,iw);
{UL v_x=V_ABS_L_BYTE(); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func965){ 
WORD r,x,s;
s=QBITS(9,11,iw);
{W *v_x=DREG_WORD((UBITS(0,5,iw)&7)); x=LR_WORD(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
SR_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func966){ 
AREG(UBITS(0,2,iw))+=QBITS(9,11,iw);
THREAD
; }
GENFUNC_PROTO(Func967){ 
WORD r,x,s;
s=QBITS(9,11,iw);
{UL v_x=V_AN_I_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func968){ 
WORD r,x,s;
s=QBITS(9,11,iw);
{UL v_x=V_AN_PI_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func969){ 
WORD r,x,s;
s=QBITS(9,11,iw);
{UL v_x=V_AN_PD_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func970){ 
WORD r,x,s;
s=QBITS(9,11,iw);
{UL v_x=V_AN_D_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func971){ 
WORD r,x,s;
s=QBITS(9,11,iw);
{UL v_x=V_AN_R_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func972){ 
WORD r,x,s;
s=QBITS(9,11,iw);
{UL v_x=V_ABS_W_WORD(); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func973){ 
WORD r,x,s;
s=QBITS(9,11,iw);
{UL v_x=V_ABS_L_WORD(); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func974){ 
LONG r,x,s;
s=QBITS(9,11,iw);
{L *v_x=DREG_LONG((UBITS(0,5,iw)&7)); x=LR_LONG(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
SR_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func975){ 
AREG(UBITS(0,2,iw))+=QBITS(9,11,iw);
THREAD
; }
GENFUNC_PROTO(Func976){ 
LONG r,x,s;
s=QBITS(9,11,iw);
{UL v_x=V_AN_I_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func977){ 
LONG r,x,s;
s=QBITS(9,11,iw);
{UL v_x=V_AN_PI_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func978){ 
LONG r,x,s;
s=QBITS(9,11,iw);
{UL v_x=V_AN_PD_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func979){ 
LONG r,x,s;
s=QBITS(9,11,iw);
{UL v_x=V_AN_D_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func980){ 
LONG r,x,s;
s=QBITS(9,11,iw);
{UL v_x=V_AN_R_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func981){ 
LONG r,x,s;
s=QBITS(9,11,iw);
{UL v_x=V_ABS_W_LONG(); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func982){ 
LONG r,x,s;
s=QBITS(9,11,iw);
{UL v_x=V_ABS_L_LONG(); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = x+s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func983){ 
SDREG_BYTE((UBITS(0,5,iw)&7),TEST_HI ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func984){ 
int r;
WORD x,displ=GET_SI16;
if (!TEST_HI)
{
	r=UBITS(0,2,iw);
	x=LDREG_WORD(r)-1;
	SDREG_WORD(r,x);
	if (x != -1)
	{
		pc += displ-2;
		CHECK_PC();
	}
}
THREAD_CHECK
; }
GENFUNC_PROTO(Func985){ 
CS_BYTE(V_AN_I_BYTE((UBITS(0,5,iw)&7)),TEST_HI ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func986){ 
CS_BYTE(V_AN_PI_BYTE((UBITS(0,5,iw)&7)),TEST_HI ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func987){ 
CS_BYTE(V_AN_PI_BYTE_All(7),TEST_HI ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func988){ 
CS_BYTE(V_AN_PD_BYTE((UBITS(0,5,iw)&7)),TEST_HI ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func989){ 
CS_BYTE(V_AN_PD_BYTE_All(7),TEST_HI ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func990){ 
CS_BYTE(V_AN_D_BYTE((UBITS(0,5,iw)&7)),TEST_HI ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func991){ 
CS_BYTE(V_AN_R_BYTE((UBITS(0,5,iw)&7)),TEST_HI ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func992){ 
CS_BYTE(V_ABS_W_BYTE(),TEST_HI ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func993){ 
CS_BYTE(V_ABS_L_BYTE(),TEST_HI ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func994){ 
BYTE r,x,s;
s=QBITS(9,11,iw);
{B *v_x=DREG_BYTE((UBITS(0,5,iw)&7)); x=LR_BYTE(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
SR_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func995){ 
BYTE r,x,s;
s=QBITS(9,11,iw);
{UL v_x=V_AN_I_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func996){ 
BYTE r,x,s;
s=QBITS(9,11,iw);
{UL v_x=V_AN_PI_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func997){ 
BYTE r,x,s;
s=QBITS(9,11,iw);
{UL v_x=V_AN_PI_BYTE_All(7); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func998){ 
BYTE r,x,s;
s=QBITS(9,11,iw);
{UL v_x=V_AN_PD_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func999){ 
BYTE r,x,s;
s=QBITS(9,11,iw);
{UL v_x=V_AN_PD_BYTE_All(7); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1000){ 
BYTE r,x,s;
s=QBITS(9,11,iw);
{UL v_x=V_AN_D_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1001){ 
BYTE r,x,s;
s=QBITS(9,11,iw);
{UL v_x=V_AN_R_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1002){ 
BYTE r,x,s;
s=QBITS(9,11,iw);
{UL v_x=V_ABS_W_BYTE(); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1003){ 
BYTE r,x,s;
s=QBITS(9,11,iw);
{UL v_x=V_ABS_L_BYTE(); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1004){ 
WORD r,x,s;
s=QBITS(9,11,iw);
{W *v_x=DREG_WORD((UBITS(0,5,iw)&7)); x=LR_WORD(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
SR_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1005){ 
AREG(UBITS(0,2,iw))-=QBITS(9,11,iw);
THREAD
; }
GENFUNC_PROTO(Func1006){ 
WORD r,x,s;
s=QBITS(9,11,iw);
{UL v_x=V_AN_I_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1007){ 
WORD r,x,s;
s=QBITS(9,11,iw);
{UL v_x=V_AN_PI_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1008){ 
WORD r,x,s;
s=QBITS(9,11,iw);
{UL v_x=V_AN_PD_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1009){ 
WORD r,x,s;
s=QBITS(9,11,iw);
{UL v_x=V_AN_D_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1010){ 
WORD r,x,s;
s=QBITS(9,11,iw);
{UL v_x=V_AN_R_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1011){ 
WORD r,x,s;
s=QBITS(9,11,iw);
{UL v_x=V_ABS_W_WORD(); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1012){ 
WORD r,x,s;
s=QBITS(9,11,iw);
{UL v_x=V_ABS_L_WORD(); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1013){ 
LONG r,x,s;
s=QBITS(9,11,iw);
{L *v_x=DREG_LONG((UBITS(0,5,iw)&7)); x=LR_LONG(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
SR_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1014){ 
AREG(UBITS(0,2,iw))-=QBITS(9,11,iw);
THREAD
; }
GENFUNC_PROTO(Func1015){ 
LONG r,x,s;
s=QBITS(9,11,iw);
{UL v_x=V_AN_I_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1016){ 
LONG r,x,s;
s=QBITS(9,11,iw);
{UL v_x=V_AN_PI_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1017){ 
LONG r,x,s;
s=QBITS(9,11,iw);
{UL v_x=V_AN_PD_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1018){ 
LONG r,x,s;
s=QBITS(9,11,iw);
{UL v_x=V_AN_D_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1019){ 
LONG r,x,s;
s=QBITS(9,11,iw);
{UL v_x=V_AN_R_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1020){ 
LONG r,x,s;
s=QBITS(9,11,iw);
{UL v_x=V_ABS_W_LONG(); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1021){ 
LONG r,x,s;
s=QBITS(9,11,iw);
{UL v_x=V_ABS_L_LONG(); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = x-s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1022){ 
SDREG_BYTE((UBITS(0,5,iw)&7),TEST_LS ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1023){ 
int r;
WORD x,displ=GET_SI16;
if (!TEST_LS)
{
	r=UBITS(0,2,iw);
	x=LDREG_WORD(r)-1;
	SDREG_WORD(r,x);
	if (x != -1)
	{
		pc += displ-2;
		CHECK_PC();
	}
}
THREAD_CHECK
; }
GENFUNC_PROTO(Func1024){ 
CS_BYTE(V_AN_I_BYTE((UBITS(0,5,iw)&7)),TEST_LS ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1025){ 
CS_BYTE(V_AN_PI_BYTE((UBITS(0,5,iw)&7)),TEST_LS ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1026){ 
CS_BYTE(V_AN_PI_BYTE_All(7),TEST_LS ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1027){ 
CS_BYTE(V_AN_PD_BYTE((UBITS(0,5,iw)&7)),TEST_LS ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1028){ 
CS_BYTE(V_AN_PD_BYTE_All(7),TEST_LS ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1029){ 
CS_BYTE(V_AN_D_BYTE((UBITS(0,5,iw)&7)),TEST_LS ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1030){ 
CS_BYTE(V_AN_R_BYTE((UBITS(0,5,iw)&7)),TEST_LS ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1031){ 
CS_BYTE(V_ABS_W_BYTE(),TEST_LS ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1032){ 
CS_BYTE(V_ABS_L_BYTE(),TEST_LS ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1033){ 
SDREG_BYTE((UBITS(0,5,iw)&7),TEST_CC ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1034){ 
int r;
WORD x,displ=GET_SI16;
if (!TEST_CC)
{
	r=UBITS(0,2,iw);
	x=LDREG_WORD(r)-1;
	SDREG_WORD(r,x);
	if (x != -1)
	{
		pc += displ-2;
		CHECK_PC();
	}
}
THREAD_CHECK
; }
GENFUNC_PROTO(Func1035){ 
CS_BYTE(V_AN_I_BYTE((UBITS(0,5,iw)&7)),TEST_CC ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1036){ 
CS_BYTE(V_AN_PI_BYTE((UBITS(0,5,iw)&7)),TEST_CC ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1037){ 
CS_BYTE(V_AN_PI_BYTE_All(7),TEST_CC ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1038){ 
CS_BYTE(V_AN_PD_BYTE((UBITS(0,5,iw)&7)),TEST_CC ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1039){ 
CS_BYTE(V_AN_PD_BYTE_All(7),TEST_CC ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1040){ 
CS_BYTE(V_AN_D_BYTE((UBITS(0,5,iw)&7)),TEST_CC ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1041){ 
CS_BYTE(V_AN_R_BYTE((UBITS(0,5,iw)&7)),TEST_CC ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1042){ 
CS_BYTE(V_ABS_W_BYTE(),TEST_CC ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1043){ 
CS_BYTE(V_ABS_L_BYTE(),TEST_CC ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1044){ 
SDREG_BYTE((UBITS(0,5,iw)&7),TEST_CS ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1045){ 
int r;
WORD x,displ=GET_SI16;
if (!TEST_CS)
{
	r=UBITS(0,2,iw);
	x=LDREG_WORD(r)-1;
	SDREG_WORD(r,x);
	if (x != -1)
	{
		pc += displ-2;
		CHECK_PC();
	}
}
THREAD_CHECK
; }
GENFUNC_PROTO(Func1046){ 
CS_BYTE(V_AN_I_BYTE((UBITS(0,5,iw)&7)),TEST_CS ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1047){ 
CS_BYTE(V_AN_PI_BYTE((UBITS(0,5,iw)&7)),TEST_CS ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1048){ 
CS_BYTE(V_AN_PI_BYTE_All(7),TEST_CS ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1049){ 
CS_BYTE(V_AN_PD_BYTE((UBITS(0,5,iw)&7)),TEST_CS ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1050){ 
CS_BYTE(V_AN_PD_BYTE_All(7),TEST_CS ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1051){ 
CS_BYTE(V_AN_D_BYTE((UBITS(0,5,iw)&7)),TEST_CS ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1052){ 
CS_BYTE(V_AN_R_BYTE((UBITS(0,5,iw)&7)),TEST_CS ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1053){ 
CS_BYTE(V_ABS_W_BYTE(),TEST_CS ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1054){ 
CS_BYTE(V_ABS_L_BYTE(),TEST_CS ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1055){ 
SDREG_BYTE((UBITS(0,5,iw)&7),TEST_NE ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1056){ 
int r;
WORD x,displ=GET_SI16;
if (!TEST_NE)
{
	r=UBITS(0,2,iw);
	x=LDREG_WORD(r)-1;
	SDREG_WORD(r,x);
	if (x != -1)
	{
		pc += displ-2;
		CHECK_PC();
	}
}
THREAD_CHECK
; }
GENFUNC_PROTO(Func1057){ 
CS_BYTE(V_AN_I_BYTE((UBITS(0,5,iw)&7)),TEST_NE ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1058){ 
CS_BYTE(V_AN_PI_BYTE((UBITS(0,5,iw)&7)),TEST_NE ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1059){ 
CS_BYTE(V_AN_PI_BYTE_All(7),TEST_NE ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1060){ 
CS_BYTE(V_AN_PD_BYTE((UBITS(0,5,iw)&7)),TEST_NE ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1061){ 
CS_BYTE(V_AN_PD_BYTE_All(7),TEST_NE ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1062){ 
CS_BYTE(V_AN_D_BYTE((UBITS(0,5,iw)&7)),TEST_NE ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1063){ 
CS_BYTE(V_AN_R_BYTE((UBITS(0,5,iw)&7)),TEST_NE ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1064){ 
CS_BYTE(V_ABS_W_BYTE(),TEST_NE ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1065){ 
CS_BYTE(V_ABS_L_BYTE(),TEST_NE ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1066){ 
SDREG_BYTE((UBITS(0,5,iw)&7),TEST_EQ ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1067){ 
int r;
WORD x,displ=GET_SI16;
if (!TEST_EQ)
{
	r=UBITS(0,2,iw);
	x=LDREG_WORD(r)-1;
	SDREG_WORD(r,x);
	if (x != -1)
	{
		pc += displ-2;
		CHECK_PC();
	}
}
THREAD_CHECK
; }
GENFUNC_PROTO(Func1068){ 
CS_BYTE(V_AN_I_BYTE((UBITS(0,5,iw)&7)),TEST_EQ ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1069){ 
CS_BYTE(V_AN_PI_BYTE((UBITS(0,5,iw)&7)),TEST_EQ ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1070){ 
CS_BYTE(V_AN_PI_BYTE_All(7),TEST_EQ ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1071){ 
CS_BYTE(V_AN_PD_BYTE((UBITS(0,5,iw)&7)),TEST_EQ ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1072){ 
CS_BYTE(V_AN_PD_BYTE_All(7),TEST_EQ ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1073){ 
CS_BYTE(V_AN_D_BYTE((UBITS(0,5,iw)&7)),TEST_EQ ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1074){ 
CS_BYTE(V_AN_R_BYTE((UBITS(0,5,iw)&7)),TEST_EQ ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1075){ 
CS_BYTE(V_ABS_W_BYTE(),TEST_EQ ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1076){ 
CS_BYTE(V_ABS_L_BYTE(),TEST_EQ ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1077){ 
SDREG_BYTE((UBITS(0,5,iw)&7),TEST_VC ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1078){ 
int r;
WORD x,displ=GET_SI16;
if (!TEST_VC)
{
	r=UBITS(0,2,iw);
	x=LDREG_WORD(r)-1;
	SDREG_WORD(r,x);
	if (x != -1)
	{
		pc += displ-2;
		CHECK_PC();
	}
}
THREAD_CHECK
; }
GENFUNC_PROTO(Func1079){ 
CS_BYTE(V_AN_I_BYTE((UBITS(0,5,iw)&7)),TEST_VC ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1080){ 
CS_BYTE(V_AN_PI_BYTE((UBITS(0,5,iw)&7)),TEST_VC ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1081){ 
CS_BYTE(V_AN_PI_BYTE_All(7),TEST_VC ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1082){ 
CS_BYTE(V_AN_PD_BYTE((UBITS(0,5,iw)&7)),TEST_VC ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1083){ 
CS_BYTE(V_AN_PD_BYTE_All(7),TEST_VC ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1084){ 
CS_BYTE(V_AN_D_BYTE((UBITS(0,5,iw)&7)),TEST_VC ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1085){ 
CS_BYTE(V_AN_R_BYTE((UBITS(0,5,iw)&7)),TEST_VC ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1086){ 
CS_BYTE(V_ABS_W_BYTE(),TEST_VC ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1087){ 
CS_BYTE(V_ABS_L_BYTE(),TEST_VC ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1088){ 
SDREG_BYTE((UBITS(0,5,iw)&7),TEST_VS ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1089){ 
int r;
WORD x,displ=GET_SI16;
if (!TEST_VS)
{
	r=UBITS(0,2,iw);
	x=LDREG_WORD(r)-1;
	SDREG_WORD(r,x);
	if (x != -1)
	{
		pc += displ-2;
		CHECK_PC();
	}
}
THREAD_CHECK
; }
GENFUNC_PROTO(Func1090){ 
CS_BYTE(V_AN_I_BYTE((UBITS(0,5,iw)&7)),TEST_VS ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1091){ 
CS_BYTE(V_AN_PI_BYTE((UBITS(0,5,iw)&7)),TEST_VS ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1092){ 
CS_BYTE(V_AN_PI_BYTE_All(7),TEST_VS ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1093){ 
CS_BYTE(V_AN_PD_BYTE((UBITS(0,5,iw)&7)),TEST_VS ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1094){ 
CS_BYTE(V_AN_PD_BYTE_All(7),TEST_VS ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1095){ 
CS_BYTE(V_AN_D_BYTE((UBITS(0,5,iw)&7)),TEST_VS ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1096){ 
CS_BYTE(V_AN_R_BYTE((UBITS(0,5,iw)&7)),TEST_VS ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1097){ 
CS_BYTE(V_ABS_W_BYTE(),TEST_VS ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1098){ 
CS_BYTE(V_ABS_L_BYTE(),TEST_VS ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1099){ 
SDREG_BYTE((UBITS(0,5,iw)&7),TEST_PL ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1100){ 
int r;
WORD x,displ=GET_SI16;
if (!TEST_PL)
{
	r=UBITS(0,2,iw);
	x=LDREG_WORD(r)-1;
	SDREG_WORD(r,x);
	if (x != -1)
	{
		pc += displ-2;
		CHECK_PC();
	}
}
THREAD_CHECK
; }
GENFUNC_PROTO(Func1101){ 
CS_BYTE(V_AN_I_BYTE((UBITS(0,5,iw)&7)),TEST_PL ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1102){ 
CS_BYTE(V_AN_PI_BYTE((UBITS(0,5,iw)&7)),TEST_PL ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1103){ 
CS_BYTE(V_AN_PI_BYTE_All(7),TEST_PL ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1104){ 
CS_BYTE(V_AN_PD_BYTE((UBITS(0,5,iw)&7)),TEST_PL ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1105){ 
CS_BYTE(V_AN_PD_BYTE_All(7),TEST_PL ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1106){ 
CS_BYTE(V_AN_D_BYTE((UBITS(0,5,iw)&7)),TEST_PL ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1107){ 
CS_BYTE(V_AN_R_BYTE((UBITS(0,5,iw)&7)),TEST_PL ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1108){ 
CS_BYTE(V_ABS_W_BYTE(),TEST_PL ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1109){ 
CS_BYTE(V_ABS_L_BYTE(),TEST_PL ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1110){ 
SDREG_BYTE((UBITS(0,5,iw)&7),TEST_MI ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1111){ 
int r;
WORD x,displ=GET_SI16;
if (!TEST_MI)
{
	r=UBITS(0,2,iw);
	x=LDREG_WORD(r)-1;
	SDREG_WORD(r,x);
	if (x != -1)
	{
		pc += displ-2;
		CHECK_PC();
	}
}
THREAD_CHECK
; }
GENFUNC_PROTO(Func1112){ 
CS_BYTE(V_AN_I_BYTE((UBITS(0,5,iw)&7)),TEST_MI ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1113){ 
CS_BYTE(V_AN_PI_BYTE((UBITS(0,5,iw)&7)),TEST_MI ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1114){ 
CS_BYTE(V_AN_PI_BYTE_All(7),TEST_MI ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1115){ 
CS_BYTE(V_AN_PD_BYTE((UBITS(0,5,iw)&7)),TEST_MI ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1116){ 
CS_BYTE(V_AN_PD_BYTE_All(7),TEST_MI ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1117){ 
CS_BYTE(V_AN_D_BYTE((UBITS(0,5,iw)&7)),TEST_MI ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1118){ 
CS_BYTE(V_AN_R_BYTE((UBITS(0,5,iw)&7)),TEST_MI ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1119){ 
CS_BYTE(V_ABS_W_BYTE(),TEST_MI ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1120){ 
CS_BYTE(V_ABS_L_BYTE(),TEST_MI ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1121){ 
SDREG_BYTE((UBITS(0,5,iw)&7),TEST_GE ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1122){ 
int r;
WORD x,displ=GET_SI16;
if (!TEST_GE)
{
	r=UBITS(0,2,iw);
	x=LDREG_WORD(r)-1;
	SDREG_WORD(r,x);
	if (x != -1)
	{
		pc += displ-2;
		CHECK_PC();
	}
}
THREAD_CHECK
; }
GENFUNC_PROTO(Func1123){ 
CS_BYTE(V_AN_I_BYTE((UBITS(0,5,iw)&7)),TEST_GE ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1124){ 
CS_BYTE(V_AN_PI_BYTE((UBITS(0,5,iw)&7)),TEST_GE ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1125){ 
CS_BYTE(V_AN_PI_BYTE_All(7),TEST_GE ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1126){ 
CS_BYTE(V_AN_PD_BYTE((UBITS(0,5,iw)&7)),TEST_GE ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1127){ 
CS_BYTE(V_AN_PD_BYTE_All(7),TEST_GE ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1128){ 
CS_BYTE(V_AN_D_BYTE((UBITS(0,5,iw)&7)),TEST_GE ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1129){ 
CS_BYTE(V_AN_R_BYTE((UBITS(0,5,iw)&7)),TEST_GE ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1130){ 
CS_BYTE(V_ABS_W_BYTE(),TEST_GE ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1131){ 
CS_BYTE(V_ABS_L_BYTE(),TEST_GE ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1132){ 
SDREG_BYTE((UBITS(0,5,iw)&7),TEST_LT ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1133){ 
int r;
WORD x,displ=GET_SI16;
if (!TEST_LT)
{
	r=UBITS(0,2,iw);
	x=LDREG_WORD(r)-1;
	SDREG_WORD(r,x);
	if (x != -1)
	{
		pc += displ-2;
		CHECK_PC();
	}
}
THREAD_CHECK
; }
GENFUNC_PROTO(Func1134){ 
CS_BYTE(V_AN_I_BYTE((UBITS(0,5,iw)&7)),TEST_LT ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1135){ 
CS_BYTE(V_AN_PI_BYTE((UBITS(0,5,iw)&7)),TEST_LT ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1136){ 
CS_BYTE(V_AN_PI_BYTE_All(7),TEST_LT ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1137){ 
CS_BYTE(V_AN_PD_BYTE((UBITS(0,5,iw)&7)),TEST_LT ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1138){ 
CS_BYTE(V_AN_PD_BYTE_All(7),TEST_LT ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1139){ 
CS_BYTE(V_AN_D_BYTE((UBITS(0,5,iw)&7)),TEST_LT ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1140){ 
CS_BYTE(V_AN_R_BYTE((UBITS(0,5,iw)&7)),TEST_LT ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1141){ 
CS_BYTE(V_ABS_W_BYTE(),TEST_LT ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1142){ 
CS_BYTE(V_ABS_L_BYTE(),TEST_LT ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1143){ 
SDREG_BYTE((UBITS(0,5,iw)&7),TEST_GT ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1144){ 
int r;
WORD x,displ=GET_SI16;
if (!TEST_GT)
{
	r=UBITS(0,2,iw);
	x=LDREG_WORD(r)-1;
	SDREG_WORD(r,x);
	if (x != -1)
	{
		pc += displ-2;
		CHECK_PC();
	}
}
THREAD_CHECK
; }
GENFUNC_PROTO(Func1145){ 
CS_BYTE(V_AN_I_BYTE((UBITS(0,5,iw)&7)),TEST_GT ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1146){ 
CS_BYTE(V_AN_PI_BYTE((UBITS(0,5,iw)&7)),TEST_GT ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1147){ 
CS_BYTE(V_AN_PI_BYTE_All(7),TEST_GT ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1148){ 
CS_BYTE(V_AN_PD_BYTE((UBITS(0,5,iw)&7)),TEST_GT ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1149){ 
CS_BYTE(V_AN_PD_BYTE_All(7),TEST_GT ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1150){ 
CS_BYTE(V_AN_D_BYTE((UBITS(0,5,iw)&7)),TEST_GT ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1151){ 
CS_BYTE(V_AN_R_BYTE((UBITS(0,5,iw)&7)),TEST_GT ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1152){ 
CS_BYTE(V_ABS_W_BYTE(),TEST_GT ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1153){ 
CS_BYTE(V_ABS_L_BYTE(),TEST_GT ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1154){ 
SDREG_BYTE((UBITS(0,5,iw)&7),TEST_LE ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1155){ 
int r;
WORD x,displ=GET_SI16;
if (!TEST_LE)
{
	r=UBITS(0,2,iw);
	x=LDREG_WORD(r)-1;
	SDREG_WORD(r,x);
	if (x != -1)
	{
		pc += displ-2;
		CHECK_PC();
	}
}
THREAD_CHECK
; }
GENFUNC_PROTO(Func1156){ 
CS_BYTE(V_AN_I_BYTE((UBITS(0,5,iw)&7)),TEST_LE ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1157){ 
CS_BYTE(V_AN_PI_BYTE((UBITS(0,5,iw)&7)),TEST_LE ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1158){ 
CS_BYTE(V_AN_PI_BYTE_All(7),TEST_LE ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1159){ 
CS_BYTE(V_AN_PD_BYTE((UBITS(0,5,iw)&7)),TEST_LE ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1160){ 
CS_BYTE(V_AN_PD_BYTE_All(7),TEST_LE ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1161){ 
CS_BYTE(V_AN_D_BYTE((UBITS(0,5,iw)&7)),TEST_LE ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1162){ 
CS_BYTE(V_AN_R_BYTE((UBITS(0,5,iw)&7)),TEST_LE ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1163){ 
CS_BYTE(V_ABS_W_BYTE(),TEST_LE ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1164){ 
CS_BYTE(V_ABS_L_BYTE(),TEST_LE ? -1:0);;
THREAD
; }
GENFUNC_PROTO(Func1165){ 
int displ=GET_SI16;
pc += displ-2;
CHECK_PC();
THREAD_CHECK
; }
GENFUNC_PROTO(Func1166){ 
pc += SBITS(0,7,iw);
CHECK_PC();
THREAD_CHECK
; }
GENFUNC_PROTO(Func1167){ 
int displ=GET_SI16;
PUSH_UL(pc);
pc += displ-2;
CHECK_PC();
THREAD_CHECK
; }
GENFUNC_PROTO(Func1168){ 
PUSH_UL(pc);
pc += SBITS(0,7,iw);
CHECK_PC();
THREAD_CHECK
; }
GENFUNC_PROTO(Func1169){ 
int displ=GET_SI16;
if (TEST_HI) {pc+=displ-2; CHECK_PC();}
THREAD_CHECK
; }
GENFUNC_PROTO(Func1170){ 
if (TEST_HI) {pc+=SBITS(0,7,iw); CHECK_PC();}
THREAD_CHECK
; }
GENFUNC_PROTO(Func1171){ 
int displ=GET_SI16;
if (TEST_LS) {pc+=displ-2; CHECK_PC();}
THREAD_CHECK
; }
GENFUNC_PROTO(Func1172){ 
if (TEST_LS) {pc+=SBITS(0,7,iw); CHECK_PC();}
THREAD_CHECK
; }
GENFUNC_PROTO(Func1173){ 
int displ=GET_SI16;
if (TEST_CC) {pc+=displ-2; CHECK_PC();}
THREAD_CHECK
; }
GENFUNC_PROTO(Func1174){ 
if (TEST_CC) {pc+=SBITS(0,7,iw); CHECK_PC();}
THREAD_CHECK
; }
GENFUNC_PROTO(Func1175){ 
int displ=GET_SI16;
if (TEST_CS) {pc+=displ-2; CHECK_PC();}
THREAD_CHECK
; }
GENFUNC_PROTO(Func1176){ 
if (TEST_CS) {pc+=SBITS(0,7,iw); CHECK_PC();}
THREAD_CHECK
; }
GENFUNC_PROTO(Func1177){ 
int displ=GET_SI16;
if (TEST_NE) {pc+=displ-2; CHECK_PC();}
THREAD_CHECK
; }
GENFUNC_PROTO(Func1178){ 
if (TEST_NE) {pc+=SBITS(0,7,iw); CHECK_PC();}
THREAD_CHECK
; }
GENFUNC_PROTO(Func1179){ 
int displ=GET_SI16;
if (TEST_EQ) {pc+=displ-2; CHECK_PC();}
THREAD_CHECK
; }
GENFUNC_PROTO(Func1180){ 
if (TEST_EQ) {pc+=SBITS(0,7,iw); CHECK_PC();}
THREAD_CHECK
; }
GENFUNC_PROTO(Func1181){ 
int displ=GET_SI16;
if (TEST_VC) {pc+=displ-2; CHECK_PC();}
THREAD_CHECK
; }
GENFUNC_PROTO(Func1182){ 
if (TEST_VC) {pc+=SBITS(0,7,iw); CHECK_PC();}
THREAD_CHECK
; }
GENFUNC_PROTO(Func1183){ 
int displ=GET_SI16;
if (TEST_VS) {pc+=displ-2; CHECK_PC();}
THREAD_CHECK
; }
GENFUNC_PROTO(Func1184){ 
if (TEST_VS) {pc+=SBITS(0,7,iw); CHECK_PC();}
THREAD_CHECK
; }
GENFUNC_PROTO(Func1185){ 
int displ=GET_SI16;
if (TEST_PL) {pc+=displ-2; CHECK_PC();}
THREAD_CHECK
; }
GENFUNC_PROTO(Func1186){ 
if (TEST_PL) {pc+=SBITS(0,7,iw); CHECK_PC();}
THREAD_CHECK
; }
GENFUNC_PROTO(Func1187){ 
int displ=GET_SI16;
if (TEST_MI) {pc+=displ-2; CHECK_PC();}
THREAD_CHECK
; }
GENFUNC_PROTO(Func1188){ 
if (TEST_MI) {pc+=SBITS(0,7,iw); CHECK_PC();}
THREAD_CHECK
; }
GENFUNC_PROTO(Func1189){ 
int displ=GET_SI16;
if (TEST_GE) {pc+=displ-2; CHECK_PC();}
THREAD_CHECK
; }
GENFUNC_PROTO(Func1190){ 
if (TEST_GE) {pc+=SBITS(0,7,iw); CHECK_PC();}
THREAD_CHECK
; }
GENFUNC_PROTO(Func1191){ 
int displ=GET_SI16;
if (TEST_LT) {pc+=displ-2; CHECK_PC();}
THREAD_CHECK
; }
GENFUNC_PROTO(Func1192){ 
if (TEST_LT) {pc+=SBITS(0,7,iw); CHECK_PC();}
THREAD_CHECK
; }
GENFUNC_PROTO(Func1193){ 
int displ=GET_SI16;
if (TEST_GT) {pc+=displ-2; CHECK_PC();}
THREAD_CHECK
; }
GENFUNC_PROTO(Func1194){ 
if (TEST_GT) {pc+=SBITS(0,7,iw); CHECK_PC();}
THREAD_CHECK
; }
GENFUNC_PROTO(Func1195){ 
int displ=GET_SI16;
if (TEST_LE) {pc+=displ-2; CHECK_PC();}
THREAD_CHECK
; }
GENFUNC_PROTO(Func1196){ 
if (TEST_LE) {pc+=SBITS(0,7,iw); CHECK_PC();}
THREAD_CHECK
; }
GENFUNC_PROTO(Func1197){ 
LONG x=SBITS(0,7,iw);
sr &= ~MASK_CC|MASK_CC_X;
SET_NZ(x);
DREG(UBITS(9,11,iw))=x;
THREAD
; }
GENFUNC_PROTO(Func1198){ 
SDREG_UL(0, nf_get_id(SP));
THREAD
; }
GENFUNC_PROTO(Func1199){ 
if(SUPERVISOR_MODE){
  SDREG_UL(0, nf_call(SP, 0));
} else {
  SDREG_UL(0, nf_call(SP, 1));
}
THREAD
; }
