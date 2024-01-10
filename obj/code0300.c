

#include "defs.h"
#include "cpu.h"
#include "gendefs.h"
#include "mem.h"
#include "native.h"
#include "nf.h"
























































































































































































































































































































































































































































GENFUNC_PROTO(Func300){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_I_BYTE((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_BYTE(V_AN_PD_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func301){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_PI_BYTE((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_BYTE(V_AN_PD_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func302){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_PI_BYTE_All(7));;
SET_NZ(x);
CS_BYTE(V_AN_PD_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func303){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_PD_BYTE((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_BYTE(V_AN_PD_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func304){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_PD_BYTE_All(7));;
SET_NZ(x);
CS_BYTE(V_AN_PD_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func305){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_D_BYTE((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_BYTE(V_AN_PD_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func306){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_R_BYTE((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_BYTE(V_AN_PD_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func307){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_ABS_W_BYTE());;
SET_NZ(x);
CS_BYTE(V_AN_PD_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func308){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_ABS_L_BYTE());;
SET_NZ(x);
CS_BYTE(V_AN_PD_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func309){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_PC_D_BYTE());;
SET_NZ(x);
CS_BYTE(V_AN_PD_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func310){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_PC_R_BYTE());;
SET_NZ(x);
CS_BYTE(V_AN_PD_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func311){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LM_BYTE(MEM(V_IMM_BYTE()));;
SET_NZ(x);
CS_BYTE(V_AN_PD_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func312){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LDREG_BYTE((UBITS(0,5,iw)&7));;
SET_NZ(x);
CS_BYTE(V_AN_D_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func313){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_I_BYTE((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_BYTE(V_AN_D_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func314){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_PI_BYTE((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_BYTE(V_AN_D_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func315){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_PI_BYTE_All(7));;
SET_NZ(x);
CS_BYTE(V_AN_D_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func316){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_PD_BYTE((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_BYTE(V_AN_D_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func317){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_PD_BYTE_All(7));;
SET_NZ(x);
CS_BYTE(V_AN_D_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func318){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_D_BYTE((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_BYTE(V_AN_D_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func319){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_R_BYTE((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_BYTE(V_AN_D_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func320){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_ABS_W_BYTE());;
SET_NZ(x);
CS_BYTE(V_AN_D_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func321){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_ABS_L_BYTE());;
SET_NZ(x);
CS_BYTE(V_AN_D_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func322){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_PC_D_BYTE());;
SET_NZ(x);
CS_BYTE(V_AN_D_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func323){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_PC_R_BYTE());;
SET_NZ(x);
CS_BYTE(V_AN_D_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func324){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LM_BYTE(MEM(V_IMM_BYTE()));;
SET_NZ(x);
CS_BYTE(V_AN_D_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func325){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LDREG_BYTE((UBITS(0,5,iw)&7));;
SET_NZ(x);
CS_BYTE(V_AN_R_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func326){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_I_BYTE((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_BYTE(V_AN_R_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func327){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_PI_BYTE((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_BYTE(V_AN_R_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func328){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_PI_BYTE_All(7));;
SET_NZ(x);
CS_BYTE(V_AN_R_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func329){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_PD_BYTE((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_BYTE(V_AN_R_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func330){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_PD_BYTE_All(7));;
SET_NZ(x);
CS_BYTE(V_AN_R_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func331){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_D_BYTE((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_BYTE(V_AN_R_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func332){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_R_BYTE((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_BYTE(V_AN_R_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func333){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_ABS_W_BYTE());;
SET_NZ(x);
CS_BYTE(V_AN_R_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func334){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_ABS_L_BYTE());;
SET_NZ(x);
CS_BYTE(V_AN_R_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func335){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_PC_D_BYTE());;
SET_NZ(x);
CS_BYTE(V_AN_R_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func336){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_PC_R_BYTE());;
SET_NZ(x);
CS_BYTE(V_AN_R_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func337){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LM_BYTE(MEM(V_IMM_BYTE()));;
SET_NZ(x);
CS_BYTE(V_AN_R_BYTE((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func338){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LDREG_BYTE((UBITS(0,5,iw)&7));;
SET_NZ(x);
CS_BYTE(V_ABS_W_BYTE(),x);;
THREAD
; }
GENFUNC_PROTO(Func339){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_I_BYTE((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_BYTE(V_ABS_W_BYTE(),x);;
THREAD
; }
GENFUNC_PROTO(Func340){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_PI_BYTE((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_BYTE(V_ABS_W_BYTE(),x);;
THREAD
; }
GENFUNC_PROTO(Func341){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_PI_BYTE_All(7));;
SET_NZ(x);
CS_BYTE(V_ABS_W_BYTE(),x);;
THREAD
; }
GENFUNC_PROTO(Func342){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_PD_BYTE((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_BYTE(V_ABS_W_BYTE(),x);;
THREAD
; }
GENFUNC_PROTO(Func343){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_PD_BYTE_All(7));;
SET_NZ(x);
CS_BYTE(V_ABS_W_BYTE(),x);;
THREAD
; }
GENFUNC_PROTO(Func344){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_D_BYTE((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_BYTE(V_ABS_W_BYTE(),x);;
THREAD
; }
GENFUNC_PROTO(Func345){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_R_BYTE((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_BYTE(V_ABS_W_BYTE(),x);;
THREAD
; }
GENFUNC_PROTO(Func346){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_ABS_W_BYTE());;
SET_NZ(x);
CS_BYTE(V_ABS_W_BYTE(),x);;
THREAD
; }
GENFUNC_PROTO(Func347){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_ABS_L_BYTE());;
SET_NZ(x);
CS_BYTE(V_ABS_W_BYTE(),x);;
THREAD
; }
GENFUNC_PROTO(Func348){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_PC_D_BYTE());;
SET_NZ(x);
CS_BYTE(V_ABS_W_BYTE(),x);;
THREAD
; }
GENFUNC_PROTO(Func349){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_PC_R_BYTE());;
SET_NZ(x);
CS_BYTE(V_ABS_W_BYTE(),x);;
THREAD
; }
GENFUNC_PROTO(Func350){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LM_BYTE(MEM(V_IMM_BYTE()));;
SET_NZ(x);
CS_BYTE(V_ABS_W_BYTE(),x);;
THREAD
; }
GENFUNC_PROTO(Func351){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LDREG_BYTE((UBITS(0,5,iw)&7));;
SET_NZ(x);
CS_BYTE(V_ABS_L_BYTE(),x);;
THREAD
; }
GENFUNC_PROTO(Func352){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_I_BYTE((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_BYTE(V_ABS_L_BYTE(),x);;
THREAD
; }
GENFUNC_PROTO(Func353){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_PI_BYTE((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_BYTE(V_ABS_L_BYTE(),x);;
THREAD
; }
GENFUNC_PROTO(Func354){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_PI_BYTE_All(7));;
SET_NZ(x);
CS_BYTE(V_ABS_L_BYTE(),x);;
THREAD
; }
GENFUNC_PROTO(Func355){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_PD_BYTE((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_BYTE(V_ABS_L_BYTE(),x);;
THREAD
; }
GENFUNC_PROTO(Func356){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_PD_BYTE_All(7));;
SET_NZ(x);
CS_BYTE(V_ABS_L_BYTE(),x);;
THREAD
; }
GENFUNC_PROTO(Func357){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_D_BYTE((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_BYTE(V_ABS_L_BYTE(),x);;
THREAD
; }
GENFUNC_PROTO(Func358){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_R_BYTE((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_BYTE(V_ABS_L_BYTE(),x);;
THREAD
; }
GENFUNC_PROTO(Func359){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_ABS_W_BYTE());;
SET_NZ(x);
CS_BYTE(V_ABS_L_BYTE(),x);;
THREAD
; }
GENFUNC_PROTO(Func360){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_ABS_L_BYTE());;
SET_NZ(x);
CS_BYTE(V_ABS_L_BYTE(),x);;
THREAD
; }
GENFUNC_PROTO(Func361){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_PC_D_BYTE());;
SET_NZ(x);
CS_BYTE(V_ABS_L_BYTE(),x);;
THREAD
; }
GENFUNC_PROTO(Func362){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_PC_R_BYTE());;
SET_NZ(x);
CS_BYTE(V_ABS_L_BYTE(),x);;
THREAD
; }
GENFUNC_PROTO(Func363){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LM_BYTE(MEM(V_IMM_BYTE()));;
SET_NZ(x);
CS_BYTE(V_ABS_L_BYTE(),x);;
THREAD
; }
GENFUNC_PROTO(Func364){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LDREG_BYTE((UBITS(0,5,iw)&7));;
SET_NZ(x);
CS_BYTE(V_AN_PI_BYTE_All(7),x);;
THREAD
; }
GENFUNC_PROTO(Func365){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_I_BYTE((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_BYTE(V_AN_PI_BYTE_All(7),x);;
THREAD
; }
GENFUNC_PROTO(Func366){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_PI_BYTE((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_BYTE(V_AN_PI_BYTE_All(7),x);;
THREAD
; }
GENFUNC_PROTO(Func367){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_PI_BYTE_All(7));;
SET_NZ(x);
CS_BYTE(V_AN_PI_BYTE_All(7),x);;
THREAD
; }
GENFUNC_PROTO(Func368){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_PD_BYTE((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_BYTE(V_AN_PI_BYTE_All(7),x);;
THREAD
; }
GENFUNC_PROTO(Func369){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_PD_BYTE_All(7));;
SET_NZ(x);
CS_BYTE(V_AN_PI_BYTE_All(7),x);;
THREAD
; }
GENFUNC_PROTO(Func370){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_D_BYTE((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_BYTE(V_AN_PI_BYTE_All(7),x);;
THREAD
; }
GENFUNC_PROTO(Func371){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_R_BYTE((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_BYTE(V_AN_PI_BYTE_All(7),x);;
THREAD
; }
GENFUNC_PROTO(Func372){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_ABS_W_BYTE());;
SET_NZ(x);
CS_BYTE(V_AN_PI_BYTE_All(7),x);;
THREAD
; }
GENFUNC_PROTO(Func373){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_ABS_L_BYTE());;
SET_NZ(x);
CS_BYTE(V_AN_PI_BYTE_All(7),x);;
THREAD
; }
GENFUNC_PROTO(Func374){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_PC_D_BYTE());;
SET_NZ(x);
CS_BYTE(V_AN_PI_BYTE_All(7),x);;
THREAD
; }
GENFUNC_PROTO(Func375){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_PC_R_BYTE());;
SET_NZ(x);
CS_BYTE(V_AN_PI_BYTE_All(7),x);;
THREAD
; }
GENFUNC_PROTO(Func376){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LM_BYTE(MEM(V_IMM_BYTE()));;
SET_NZ(x);
CS_BYTE(V_AN_PI_BYTE_All(7),x);;
THREAD
; }
GENFUNC_PROTO(Func377){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LDREG_BYTE((UBITS(0,5,iw)&7));;
SET_NZ(x);
CS_BYTE(V_AN_PD_BYTE_All(7),x);;
THREAD
; }
GENFUNC_PROTO(Func378){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_I_BYTE((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_BYTE(V_AN_PD_BYTE_All(7),x);;
THREAD
; }
GENFUNC_PROTO(Func379){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_PI_BYTE((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_BYTE(V_AN_PD_BYTE_All(7),x);;
THREAD
; }
GENFUNC_PROTO(Func380){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_PI_BYTE_All(7));;
SET_NZ(x);
CS_BYTE(V_AN_PD_BYTE_All(7),x);;
THREAD
; }
GENFUNC_PROTO(Func381){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_PD_BYTE((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_BYTE(V_AN_PD_BYTE_All(7),x);;
THREAD
; }
GENFUNC_PROTO(Func382){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_PD_BYTE_All(7));;
SET_NZ(x);
CS_BYTE(V_AN_PD_BYTE_All(7),x);;
THREAD
; }
GENFUNC_PROTO(Func383){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_D_BYTE((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_BYTE(V_AN_PD_BYTE_All(7),x);;
THREAD
; }
GENFUNC_PROTO(Func384){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_AN_R_BYTE((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_BYTE(V_AN_PD_BYTE_All(7),x);;
THREAD
; }
GENFUNC_PROTO(Func385){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_ABS_W_BYTE());;
SET_NZ(x);
CS_BYTE(V_AN_PD_BYTE_All(7),x);;
THREAD
; }
GENFUNC_PROTO(Func386){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_ABS_L_BYTE());;
SET_NZ(x);
CS_BYTE(V_AN_PD_BYTE_All(7),x);;
THREAD
; }
GENFUNC_PROTO(Func387){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_PC_D_BYTE());;
SET_NZ(x);
CS_BYTE(V_AN_PD_BYTE_All(7),x);;
THREAD
; }
GENFUNC_PROTO(Func388){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_BYTE(V_PC_R_BYTE());;
SET_NZ(x);
CS_BYTE(V_AN_PD_BYTE_All(7),x);;
THREAD
; }
GENFUNC_PROTO(Func389){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LM_BYTE(MEM(V_IMM_BYTE()));;
SET_NZ(x);
CS_BYTE(V_AN_PD_BYTE_All(7),x);;
THREAD
; }
GENFUNC_PROTO(Func390){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LDREG_LONG((UBITS(0,5,iw)&7));;
SET_NZ(x);
SDREG_LONG((UBITS(6,11,iw)>>3),x);;
THREAD
; }
GENFUNC_PROTO(Func391){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LDREG_LONG((UBITS(0,5,iw)&7)+8);;
SET_NZ(x);
SDREG_LONG((UBITS(6,11,iw)>>3),x);;
THREAD
; }
GENFUNC_PROTO(Func392){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_AN_I_LONG((UBITS(0,5,iw)&7)));;
SET_NZ(x);
SDREG_LONG((UBITS(6,11,iw)>>3),x);;
THREAD
; }
GENFUNC_PROTO(Func393){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_AN_PI_LONG((UBITS(0,5,iw)&7)));;
SET_NZ(x);
SDREG_LONG((UBITS(6,11,iw)>>3),x);;
THREAD
; }
GENFUNC_PROTO(Func394){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_AN_PD_LONG((UBITS(0,5,iw)&7)));;
SET_NZ(x);
SDREG_LONG((UBITS(6,11,iw)>>3),x);;
THREAD
; }
GENFUNC_PROTO(Func395){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_AN_D_LONG((UBITS(0,5,iw)&7)));;
SET_NZ(x);
SDREG_LONG((UBITS(6,11,iw)>>3),x);;
THREAD
; }
GENFUNC_PROTO(Func396){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_AN_R_LONG((UBITS(0,5,iw)&7)));;
SET_NZ(x);
SDREG_LONG((UBITS(6,11,iw)>>3),x);;
THREAD
; }
GENFUNC_PROTO(Func397){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_ABS_W_LONG());;
SET_NZ(x);
SDREG_LONG((UBITS(6,11,iw)>>3),x);;
THREAD
; }
GENFUNC_PROTO(Func398){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_ABS_L_LONG());;
SET_NZ(x);
SDREG_LONG((UBITS(6,11,iw)>>3),x);;
THREAD
; }
GENFUNC_PROTO(Func399){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_PC_D_LONG());;
SET_NZ(x);
SDREG_LONG((UBITS(6,11,iw)>>3),x);;
THREAD
; }
GENFUNC_PROTO(Func400){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_PC_R_LONG());;
SET_NZ(x);
SDREG_LONG((UBITS(6,11,iw)>>3),x);;
THREAD
; }
GENFUNC_PROTO(Func401){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LM_LONG(MEM(V_IMM_LONG()));;
SET_NZ(x);
SDREG_LONG((UBITS(6,11,iw)>>3),x);;
THREAD
; }
GENFUNC_PROTO(Func402){ 
LONG x;
x=LDREG_LONG((UBITS(0,5,iw)&7));;
SDREG_LONG(UBITS(9,11,iw)+8,x);
THREAD
;; }
GENFUNC_PROTO(Func403){ 
LONG x;
x=LDREG_LONG((UBITS(0,5,iw)&7)+8);;
SDREG_LONG(UBITS(9,11,iw)+8,x);
THREAD
;; }
GENFUNC_PROTO(Func404){ 
LONG x;
x=CL_LONG(V_AN_I_LONG((UBITS(0,5,iw)&7)));;
SDREG_LONG(UBITS(9,11,iw)+8,x);
THREAD
;; }
GENFUNC_PROTO(Func405){ 
LONG x;
x=CL_LONG(V_AN_PI_LONG((UBITS(0,5,iw)&7)));;
SDREG_LONG(UBITS(9,11,iw)+8,x);
THREAD
;; }
GENFUNC_PROTO(Func406){ 
LONG x;
x=CL_LONG(V_AN_PD_LONG((UBITS(0,5,iw)&7)));;
SDREG_LONG(UBITS(9,11,iw)+8,x);
THREAD
;; }
GENFUNC_PROTO(Func407){ 
LONG x;
x=CL_LONG(V_AN_D_LONG((UBITS(0,5,iw)&7)));;
SDREG_LONG(UBITS(9,11,iw)+8,x);
THREAD
;; }
GENFUNC_PROTO(Func408){ 
LONG x;
x=CL_LONG(V_AN_R_LONG((UBITS(0,5,iw)&7)));;
SDREG_LONG(UBITS(9,11,iw)+8,x);
THREAD
;; }
GENFUNC_PROTO(Func409){ 
LONG x;
x=CL_LONG(V_ABS_W_LONG());;
SDREG_LONG(UBITS(9,11,iw)+8,x);
THREAD
;; }
GENFUNC_PROTO(Func410){ 
LONG x;
x=CL_LONG(V_ABS_L_LONG());;
SDREG_LONG(UBITS(9,11,iw)+8,x);
THREAD
;; }
GENFUNC_PROTO(Func411){ 
LONG x;
x=CL_LONG(V_PC_D_LONG());;
SDREG_LONG(UBITS(9,11,iw)+8,x);
THREAD
;; }
GENFUNC_PROTO(Func412){ 
LONG x;
x=CL_LONG(V_PC_R_LONG());;
SDREG_LONG(UBITS(9,11,iw)+8,x);
THREAD
;; }
GENFUNC_PROTO(Func413){ 
LONG x;
x=LM_LONG(MEM(V_IMM_LONG()));;
SDREG_LONG(UBITS(9,11,iw)+8,x);
THREAD
;; }
GENFUNC_PROTO(Func414){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LDREG_LONG((UBITS(0,5,iw)&7));;
SET_NZ(x);
CS_LONG(V_AN_I_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func415){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LDREG_LONG((UBITS(0,5,iw)&7)+8);;
SET_NZ(x);
CS_LONG(V_AN_I_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func416){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_AN_I_LONG((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_LONG(V_AN_I_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func417){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_AN_PI_LONG((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_LONG(V_AN_I_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func418){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_AN_PD_LONG((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_LONG(V_AN_I_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func419){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_AN_D_LONG((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_LONG(V_AN_I_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func420){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_AN_R_LONG((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_LONG(V_AN_I_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func421){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_ABS_W_LONG());;
SET_NZ(x);
CS_LONG(V_AN_I_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func422){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_ABS_L_LONG());;
SET_NZ(x);
CS_LONG(V_AN_I_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func423){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_PC_D_LONG());;
SET_NZ(x);
CS_LONG(V_AN_I_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func424){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_PC_R_LONG());;
SET_NZ(x);
CS_LONG(V_AN_I_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func425){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LM_LONG(MEM(V_IMM_LONG()));;
SET_NZ(x);
CS_LONG(V_AN_I_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func426){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LDREG_LONG((UBITS(0,5,iw)&7));;
SET_NZ(x);
CS_LONG(V_AN_PI_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func427){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LDREG_LONG((UBITS(0,5,iw)&7)+8);;
SET_NZ(x);
CS_LONG(V_AN_PI_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func428){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_AN_I_LONG((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_LONG(V_AN_PI_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func429){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_AN_PI_LONG((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_LONG(V_AN_PI_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func430){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_AN_PD_LONG((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_LONG(V_AN_PI_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func431){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_AN_D_LONG((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_LONG(V_AN_PI_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func432){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_AN_R_LONG((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_LONG(V_AN_PI_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func433){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_ABS_W_LONG());;
SET_NZ(x);
CS_LONG(V_AN_PI_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func434){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_ABS_L_LONG());;
SET_NZ(x);
CS_LONG(V_AN_PI_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func435){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_PC_D_LONG());;
SET_NZ(x);
CS_LONG(V_AN_PI_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func436){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_PC_R_LONG());;
SET_NZ(x);
CS_LONG(V_AN_PI_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func437){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LM_LONG(MEM(V_IMM_LONG()));;
SET_NZ(x);
CS_LONG(V_AN_PI_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func438){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LDREG_LONG((UBITS(0,5,iw)&7));;
SET_NZ(x);
CS_LONG(V_AN_PD_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func439){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LDREG_LONG((UBITS(0,5,iw)&7)+8);;
SET_NZ(x);
CS_LONG(V_AN_PD_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func440){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_AN_I_LONG((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_LONG(V_AN_PD_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func441){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_AN_PI_LONG((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_LONG(V_AN_PD_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func442){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_AN_PD_LONG((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_LONG(V_AN_PD_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func443){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_AN_D_LONG((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_LONG(V_AN_PD_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func444){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_AN_R_LONG((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_LONG(V_AN_PD_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func445){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_ABS_W_LONG());;
SET_NZ(x);
CS_LONG(V_AN_PD_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func446){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_ABS_L_LONG());;
SET_NZ(x);
CS_LONG(V_AN_PD_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func447){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_PC_D_LONG());;
SET_NZ(x);
CS_LONG(V_AN_PD_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func448){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_PC_R_LONG());;
SET_NZ(x);
CS_LONG(V_AN_PD_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func449){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LM_LONG(MEM(V_IMM_LONG()));;
SET_NZ(x);
CS_LONG(V_AN_PD_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func450){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LDREG_LONG((UBITS(0,5,iw)&7));;
SET_NZ(x);
CS_LONG(V_AN_D_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func451){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LDREG_LONG((UBITS(0,5,iw)&7)+8);;
SET_NZ(x);
CS_LONG(V_AN_D_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func452){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_AN_I_LONG((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_LONG(V_AN_D_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func453){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_AN_PI_LONG((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_LONG(V_AN_D_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func454){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_AN_PD_LONG((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_LONG(V_AN_D_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func455){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_AN_D_LONG((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_LONG(V_AN_D_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func456){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_AN_R_LONG((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_LONG(V_AN_D_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func457){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_ABS_W_LONG());;
SET_NZ(x);
CS_LONG(V_AN_D_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func458){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_ABS_L_LONG());;
SET_NZ(x);
CS_LONG(V_AN_D_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func459){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_PC_D_LONG());;
SET_NZ(x);
CS_LONG(V_AN_D_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func460){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_PC_R_LONG());;
SET_NZ(x);
CS_LONG(V_AN_D_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func461){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LM_LONG(MEM(V_IMM_LONG()));;
SET_NZ(x);
CS_LONG(V_AN_D_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func462){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LDREG_LONG((UBITS(0,5,iw)&7));;
SET_NZ(x);
CS_LONG(V_AN_R_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func463){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LDREG_LONG((UBITS(0,5,iw)&7)+8);;
SET_NZ(x);
CS_LONG(V_AN_R_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func464){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_AN_I_LONG((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_LONG(V_AN_R_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func465){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_AN_PI_LONG((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_LONG(V_AN_R_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func466){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_AN_PD_LONG((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_LONG(V_AN_R_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func467){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_AN_D_LONG((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_LONG(V_AN_R_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func468){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_AN_R_LONG((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_LONG(V_AN_R_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func469){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_ABS_W_LONG());;
SET_NZ(x);
CS_LONG(V_AN_R_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func470){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_ABS_L_LONG());;
SET_NZ(x);
CS_LONG(V_AN_R_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func471){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_PC_D_LONG());;
SET_NZ(x);
CS_LONG(V_AN_R_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func472){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_PC_R_LONG());;
SET_NZ(x);
CS_LONG(V_AN_R_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func473){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LM_LONG(MEM(V_IMM_LONG()));;
SET_NZ(x);
CS_LONG(V_AN_R_LONG((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func474){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LDREG_LONG((UBITS(0,5,iw)&7));;
SET_NZ(x);
CS_LONG(V_ABS_W_LONG(),x);;
THREAD
; }
GENFUNC_PROTO(Func475){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LDREG_LONG((UBITS(0,5,iw)&7)+8);;
SET_NZ(x);
CS_LONG(V_ABS_W_LONG(),x);;
THREAD
; }
GENFUNC_PROTO(Func476){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_AN_I_LONG((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_LONG(V_ABS_W_LONG(),x);;
THREAD
; }
GENFUNC_PROTO(Func477){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_AN_PI_LONG((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_LONG(V_ABS_W_LONG(),x);;
THREAD
; }
GENFUNC_PROTO(Func478){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_AN_PD_LONG((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_LONG(V_ABS_W_LONG(),x);;
THREAD
; }
GENFUNC_PROTO(Func479){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_AN_D_LONG((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_LONG(V_ABS_W_LONG(),x);;
THREAD
; }
GENFUNC_PROTO(Func480){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_AN_R_LONG((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_LONG(V_ABS_W_LONG(),x);;
THREAD
; }
GENFUNC_PROTO(Func481){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_ABS_W_LONG());;
SET_NZ(x);
CS_LONG(V_ABS_W_LONG(),x);;
THREAD
; }
GENFUNC_PROTO(Func482){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_ABS_L_LONG());;
SET_NZ(x);
CS_LONG(V_ABS_W_LONG(),x);;
THREAD
; }
GENFUNC_PROTO(Func483){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_PC_D_LONG());;
SET_NZ(x);
CS_LONG(V_ABS_W_LONG(),x);;
THREAD
; }
GENFUNC_PROTO(Func484){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_PC_R_LONG());;
SET_NZ(x);
CS_LONG(V_ABS_W_LONG(),x);;
THREAD
; }
GENFUNC_PROTO(Func485){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LM_LONG(MEM(V_IMM_LONG()));;
SET_NZ(x);
CS_LONG(V_ABS_W_LONG(),x);;
THREAD
; }
GENFUNC_PROTO(Func486){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LDREG_LONG((UBITS(0,5,iw)&7));;
SET_NZ(x);
CS_LONG(V_ABS_L_LONG(),x);;
THREAD
; }
GENFUNC_PROTO(Func487){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LDREG_LONG((UBITS(0,5,iw)&7)+8);;
SET_NZ(x);
CS_LONG(V_ABS_L_LONG(),x);;
THREAD
; }
GENFUNC_PROTO(Func488){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_AN_I_LONG((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_LONG(V_ABS_L_LONG(),x);;
THREAD
; }
GENFUNC_PROTO(Func489){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_AN_PI_LONG((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_LONG(V_ABS_L_LONG(),x);;
THREAD
; }
GENFUNC_PROTO(Func490){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_AN_PD_LONG((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_LONG(V_ABS_L_LONG(),x);;
THREAD
; }
GENFUNC_PROTO(Func491){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_AN_D_LONG((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_LONG(V_ABS_L_LONG(),x);;
THREAD
; }
GENFUNC_PROTO(Func492){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_AN_R_LONG((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_LONG(V_ABS_L_LONG(),x);;
THREAD
; }
GENFUNC_PROTO(Func493){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_ABS_W_LONG());;
SET_NZ(x);
CS_LONG(V_ABS_L_LONG(),x);;
THREAD
; }
GENFUNC_PROTO(Func494){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_ABS_L_LONG());;
SET_NZ(x);
CS_LONG(V_ABS_L_LONG(),x);;
THREAD
; }
GENFUNC_PROTO(Func495){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_PC_D_LONG());;
SET_NZ(x);
CS_LONG(V_ABS_L_LONG(),x);;
THREAD
; }
GENFUNC_PROTO(Func496){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_LONG(V_PC_R_LONG());;
SET_NZ(x);
CS_LONG(V_ABS_L_LONG(),x);;
THREAD
; }
GENFUNC_PROTO(Func497){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LM_LONG(MEM(V_IMM_LONG()));;
SET_NZ(x);
CS_LONG(V_ABS_L_LONG(),x);;
THREAD
; }
GENFUNC_PROTO(Func498){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LDREG_WORD((UBITS(0,5,iw)&7));;
SET_NZ(x);
SDREG_WORD((UBITS(6,11,iw)>>3),x);;
THREAD
; }
GENFUNC_PROTO(Func499){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LDREG_WORD((UBITS(0,5,iw)&7)+8);;
SET_NZ(x);
SDREG_WORD((UBITS(6,11,iw)>>3),x);;
THREAD
; }
GENFUNC_PROTO(Func500){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_AN_I_WORD((UBITS(0,5,iw)&7)));;
SET_NZ(x);
SDREG_WORD((UBITS(6,11,iw)>>3),x);;
THREAD
; }
GENFUNC_PROTO(Func501){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_AN_PI_WORD((UBITS(0,5,iw)&7)));;
SET_NZ(x);
SDREG_WORD((UBITS(6,11,iw)>>3),x);;
THREAD
; }
GENFUNC_PROTO(Func502){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_AN_PD_WORD((UBITS(0,5,iw)&7)));;
SET_NZ(x);
SDREG_WORD((UBITS(6,11,iw)>>3),x);;
THREAD
; }
GENFUNC_PROTO(Func503){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_AN_D_WORD((UBITS(0,5,iw)&7)));;
SET_NZ(x);
SDREG_WORD((UBITS(6,11,iw)>>3),x);;
THREAD
; }
GENFUNC_PROTO(Func504){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_AN_R_WORD((UBITS(0,5,iw)&7)));;
SET_NZ(x);
SDREG_WORD((UBITS(6,11,iw)>>3),x);;
THREAD
; }
GENFUNC_PROTO(Func505){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_ABS_W_WORD());;
SET_NZ(x);
SDREG_WORD((UBITS(6,11,iw)>>3),x);;
THREAD
; }
GENFUNC_PROTO(Func506){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_ABS_L_WORD());;
SET_NZ(x);
SDREG_WORD((UBITS(6,11,iw)>>3),x);;
THREAD
; }
GENFUNC_PROTO(Func507){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_PC_D_WORD());;
SET_NZ(x);
SDREG_WORD((UBITS(6,11,iw)>>3),x);;
THREAD
; }
GENFUNC_PROTO(Func508){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_PC_R_WORD());;
SET_NZ(x);
SDREG_WORD((UBITS(6,11,iw)>>3),x);;
THREAD
; }
GENFUNC_PROTO(Func509){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LM_WORD(MEM(V_IMM_WORD()));;
SET_NZ(x);
SDREG_WORD((UBITS(6,11,iw)>>3),x);;
THREAD
; }
GENFUNC_PROTO(Func510){ 
LONG x;
x=LDREG_WORD((UBITS(0,5,iw)&7));;
SDREG_LONG(UBITS(9,11,iw)+8,x);
THREAD
;; }
GENFUNC_PROTO(Func511){ 
LONG x;
x=LDREG_WORD((UBITS(0,5,iw)&7)+8);;
SDREG_LONG(UBITS(9,11,iw)+8,x);
THREAD
;; }
GENFUNC_PROTO(Func512){ 
LONG x;
x=CL_WORD(V_AN_I_WORD((UBITS(0,5,iw)&7)));;
SDREG_LONG(UBITS(9,11,iw)+8,x);
THREAD
;; }
GENFUNC_PROTO(Func513){ 
LONG x;
x=CL_WORD(V_AN_PI_WORD((UBITS(0,5,iw)&7)));;
SDREG_LONG(UBITS(9,11,iw)+8,x);
THREAD
;; }
GENFUNC_PROTO(Func514){ 
LONG x;
x=CL_WORD(V_AN_PD_WORD((UBITS(0,5,iw)&7)));;
SDREG_LONG(UBITS(9,11,iw)+8,x);
THREAD
;; }
GENFUNC_PROTO(Func515){ 
LONG x;
x=CL_WORD(V_AN_D_WORD((UBITS(0,5,iw)&7)));;
SDREG_LONG(UBITS(9,11,iw)+8,x);
THREAD
;; }
GENFUNC_PROTO(Func516){ 
LONG x;
x=CL_WORD(V_AN_R_WORD((UBITS(0,5,iw)&7)));;
SDREG_LONG(UBITS(9,11,iw)+8,x);
THREAD
;; }
GENFUNC_PROTO(Func517){ 
LONG x;
x=CL_WORD(V_ABS_W_WORD());;
SDREG_LONG(UBITS(9,11,iw)+8,x);
THREAD
;; }
GENFUNC_PROTO(Func518){ 
LONG x;
x=CL_WORD(V_ABS_L_WORD());;
SDREG_LONG(UBITS(9,11,iw)+8,x);
THREAD
;; }
GENFUNC_PROTO(Func519){ 
LONG x;
x=CL_WORD(V_PC_D_WORD());;
SDREG_LONG(UBITS(9,11,iw)+8,x);
THREAD
;; }
GENFUNC_PROTO(Func520){ 
LONG x;
x=CL_WORD(V_PC_R_WORD());;
SDREG_LONG(UBITS(9,11,iw)+8,x);
THREAD
;; }
GENFUNC_PROTO(Func521){ 
LONG x;
x=LM_WORD(MEM(V_IMM_WORD()));;
SDREG_LONG(UBITS(9,11,iw)+8,x);
THREAD
;; }
GENFUNC_PROTO(Func522){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LDREG_WORD((UBITS(0,5,iw)&7));;
SET_NZ(x);
CS_WORD(V_AN_I_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func523){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LDREG_WORD((UBITS(0,5,iw)&7)+8);;
SET_NZ(x);
CS_WORD(V_AN_I_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func524){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_AN_I_WORD((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_WORD(V_AN_I_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func525){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_AN_PI_WORD((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_WORD(V_AN_I_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func526){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_AN_PD_WORD((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_WORD(V_AN_I_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func527){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_AN_D_WORD((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_WORD(V_AN_I_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func528){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_AN_R_WORD((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_WORD(V_AN_I_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func529){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_ABS_W_WORD());;
SET_NZ(x);
CS_WORD(V_AN_I_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func530){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_ABS_L_WORD());;
SET_NZ(x);
CS_WORD(V_AN_I_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func531){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_PC_D_WORD());;
SET_NZ(x);
CS_WORD(V_AN_I_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func532){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_PC_R_WORD());;
SET_NZ(x);
CS_WORD(V_AN_I_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func533){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LM_WORD(MEM(V_IMM_WORD()));;
SET_NZ(x);
CS_WORD(V_AN_I_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func534){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LDREG_WORD((UBITS(0,5,iw)&7));;
SET_NZ(x);
CS_WORD(V_AN_PI_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func535){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LDREG_WORD((UBITS(0,5,iw)&7)+8);;
SET_NZ(x);
CS_WORD(V_AN_PI_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func536){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_AN_I_WORD((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_WORD(V_AN_PI_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func537){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_AN_PI_WORD((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_WORD(V_AN_PI_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func538){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_AN_PD_WORD((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_WORD(V_AN_PI_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func539){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_AN_D_WORD((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_WORD(V_AN_PI_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func540){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_AN_R_WORD((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_WORD(V_AN_PI_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func541){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_ABS_W_WORD());;
SET_NZ(x);
CS_WORD(V_AN_PI_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func542){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_ABS_L_WORD());;
SET_NZ(x);
CS_WORD(V_AN_PI_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func543){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_PC_D_WORD());;
SET_NZ(x);
CS_WORD(V_AN_PI_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func544){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_PC_R_WORD());;
SET_NZ(x);
CS_WORD(V_AN_PI_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func545){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LM_WORD(MEM(V_IMM_WORD()));;
SET_NZ(x);
CS_WORD(V_AN_PI_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func546){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LDREG_WORD((UBITS(0,5,iw)&7));;
SET_NZ(x);
CS_WORD(V_AN_PD_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func547){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LDREG_WORD((UBITS(0,5,iw)&7)+8);;
SET_NZ(x);
CS_WORD(V_AN_PD_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func548){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_AN_I_WORD((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_WORD(V_AN_PD_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func549){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_AN_PI_WORD((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_WORD(V_AN_PD_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func550){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_AN_PD_WORD((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_WORD(V_AN_PD_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func551){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_AN_D_WORD((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_WORD(V_AN_PD_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func552){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_AN_R_WORD((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_WORD(V_AN_PD_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func553){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_ABS_W_WORD());;
SET_NZ(x);
CS_WORD(V_AN_PD_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func554){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_ABS_L_WORD());;
SET_NZ(x);
CS_WORD(V_AN_PD_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func555){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_PC_D_WORD());;
SET_NZ(x);
CS_WORD(V_AN_PD_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func556){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_PC_R_WORD());;
SET_NZ(x);
CS_WORD(V_AN_PD_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func557){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LM_WORD(MEM(V_IMM_WORD()));;
SET_NZ(x);
CS_WORD(V_AN_PD_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func558){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LDREG_WORD((UBITS(0,5,iw)&7));;
SET_NZ(x);
CS_WORD(V_AN_D_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func559){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LDREG_WORD((UBITS(0,5,iw)&7)+8);;
SET_NZ(x);
CS_WORD(V_AN_D_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func560){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_AN_I_WORD((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_WORD(V_AN_D_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func561){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_AN_PI_WORD((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_WORD(V_AN_D_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func562){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_AN_PD_WORD((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_WORD(V_AN_D_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func563){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_AN_D_WORD((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_WORD(V_AN_D_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func564){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_AN_R_WORD((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_WORD(V_AN_D_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func565){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_ABS_W_WORD());;
SET_NZ(x);
CS_WORD(V_AN_D_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func566){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_ABS_L_WORD());;
SET_NZ(x);
CS_WORD(V_AN_D_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func567){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_PC_D_WORD());;
SET_NZ(x);
CS_WORD(V_AN_D_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func568){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_PC_R_WORD());;
SET_NZ(x);
CS_WORD(V_AN_D_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func569){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LM_WORD(MEM(V_IMM_WORD()));;
SET_NZ(x);
CS_WORD(V_AN_D_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func570){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LDREG_WORD((UBITS(0,5,iw)&7));;
SET_NZ(x);
CS_WORD(V_AN_R_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func571){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LDREG_WORD((UBITS(0,5,iw)&7)+8);;
SET_NZ(x);
CS_WORD(V_AN_R_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func572){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_AN_I_WORD((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_WORD(V_AN_R_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func573){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_AN_PI_WORD((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_WORD(V_AN_R_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func574){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_AN_PD_WORD((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_WORD(V_AN_R_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func575){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_AN_D_WORD((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_WORD(V_AN_R_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func576){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_AN_R_WORD((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_WORD(V_AN_R_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func577){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_ABS_W_WORD());;
SET_NZ(x);
CS_WORD(V_AN_R_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func578){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_ABS_L_WORD());;
SET_NZ(x);
CS_WORD(V_AN_R_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func579){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_PC_D_WORD());;
SET_NZ(x);
CS_WORD(V_AN_R_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func580){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_PC_R_WORD());;
SET_NZ(x);
CS_WORD(V_AN_R_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func581){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LM_WORD(MEM(V_IMM_WORD()));;
SET_NZ(x);
CS_WORD(V_AN_R_WORD((UBITS(6,11,iw)>>3)),x);;
THREAD
; }
GENFUNC_PROTO(Func582){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LDREG_WORD((UBITS(0,5,iw)&7));;
SET_NZ(x);
CS_WORD(V_ABS_W_WORD(),x);;
THREAD
; }
GENFUNC_PROTO(Func583){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LDREG_WORD((UBITS(0,5,iw)&7)+8);;
SET_NZ(x);
CS_WORD(V_ABS_W_WORD(),x);;
THREAD
; }
GENFUNC_PROTO(Func584){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_AN_I_WORD((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_WORD(V_ABS_W_WORD(),x);;
THREAD
; }
GENFUNC_PROTO(Func585){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_AN_PI_WORD((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_WORD(V_ABS_W_WORD(),x);;
THREAD
; }
GENFUNC_PROTO(Func586){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_AN_PD_WORD((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_WORD(V_ABS_W_WORD(),x);;
THREAD
; }
GENFUNC_PROTO(Func587){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_AN_D_WORD((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_WORD(V_ABS_W_WORD(),x);;
THREAD
; }
GENFUNC_PROTO(Func588){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_AN_R_WORD((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_WORD(V_ABS_W_WORD(),x);;
THREAD
; }
GENFUNC_PROTO(Func589){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_ABS_W_WORD());;
SET_NZ(x);
CS_WORD(V_ABS_W_WORD(),x);;
THREAD
; }
GENFUNC_PROTO(Func590){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_ABS_L_WORD());;
SET_NZ(x);
CS_WORD(V_ABS_W_WORD(),x);;
THREAD
; }
GENFUNC_PROTO(Func591){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_PC_D_WORD());;
SET_NZ(x);
CS_WORD(V_ABS_W_WORD(),x);;
THREAD
; }
GENFUNC_PROTO(Func592){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_PC_R_WORD());;
SET_NZ(x);
CS_WORD(V_ABS_W_WORD(),x);;
THREAD
; }
GENFUNC_PROTO(Func593){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LM_WORD(MEM(V_IMM_WORD()));;
SET_NZ(x);
CS_WORD(V_ABS_W_WORD(),x);;
THREAD
; }
GENFUNC_PROTO(Func594){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LDREG_WORD((UBITS(0,5,iw)&7));;
SET_NZ(x);
CS_WORD(V_ABS_L_WORD(),x);;
THREAD
; }
GENFUNC_PROTO(Func595){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=LDREG_WORD((UBITS(0,5,iw)&7)+8);;
SET_NZ(x);
CS_WORD(V_ABS_L_WORD(),x);;
THREAD
; }
GENFUNC_PROTO(Func596){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_AN_I_WORD((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_WORD(V_ABS_L_WORD(),x);;
THREAD
; }
GENFUNC_PROTO(Func597){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_AN_PI_WORD((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_WORD(V_ABS_L_WORD(),x);;
THREAD
; }
GENFUNC_PROTO(Func598){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_AN_PD_WORD((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_WORD(V_ABS_L_WORD(),x);;
THREAD
; }
GENFUNC_PROTO(Func599){ 
int x;
sr&= ~MASK_CC | MASK_CC_X;
x=CL_WORD(V_AN_D_WORD((UBITS(0,5,iw)&7)));;
SET_NZ(x);
CS_WORD(V_ABS_L_WORD(),x);;
THREAD
; }
