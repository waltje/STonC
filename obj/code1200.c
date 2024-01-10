

#include "defs.h"
#include "cpu.h"
#include "gendefs.h"
#include "mem.h"
#include "native.h"
#include "nf.h"
























































































































































































































































































































































































































































GENFUNC_PROTO(Func1200){ 
BYTE r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=LDREG_BYTE((UBITS(0,5,iw)&7));;
x=LDREG_BYTE(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
SDREG_BYTE(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1201){ 
BYTE r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_BYTE(V_AN_I_BYTE((UBITS(0,5,iw)&7)));;
x=LDREG_BYTE(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
SDREG_BYTE(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1202){ 
BYTE r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_BYTE(V_AN_PI_BYTE((UBITS(0,5,iw)&7)));;
x=LDREG_BYTE(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
SDREG_BYTE(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1203){ 
BYTE r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_BYTE(V_AN_PI_BYTE_All(7));;
x=LDREG_BYTE(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
SDREG_BYTE(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1204){ 
BYTE r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_BYTE(V_AN_PD_BYTE((UBITS(0,5,iw)&7)));;
x=LDREG_BYTE(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
SDREG_BYTE(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1205){ 
BYTE r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_BYTE(V_AN_PD_BYTE_All(7));;
x=LDREG_BYTE(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
SDREG_BYTE(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1206){ 
BYTE r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_BYTE(V_AN_D_BYTE((UBITS(0,5,iw)&7)));;
x=LDREG_BYTE(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
SDREG_BYTE(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1207){ 
BYTE r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_BYTE(V_AN_R_BYTE((UBITS(0,5,iw)&7)));;
x=LDREG_BYTE(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
SDREG_BYTE(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1208){ 
BYTE r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_BYTE(V_ABS_W_BYTE());;
x=LDREG_BYTE(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
SDREG_BYTE(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1209){ 
BYTE r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_BYTE(V_ABS_L_BYTE());;
x=LDREG_BYTE(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
SDREG_BYTE(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1210){ 
BYTE r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_BYTE(V_PC_D_BYTE());;
x=LDREG_BYTE(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
SDREG_BYTE(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1211){ 
BYTE r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_BYTE(V_PC_R_BYTE());;
x=LDREG_BYTE(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
SDREG_BYTE(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1212){ 
BYTE r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=LM_BYTE(MEM(V_IMM_BYTE()));;
x=LDREG_BYTE(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
SDREG_BYTE(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1213){ 
WORD r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=LDREG_WORD((UBITS(0,5,iw)&7));;
x=LDREG_WORD(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
SDREG_WORD(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1214){ 
WORD r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_WORD(V_AN_I_WORD((UBITS(0,5,iw)&7)));;
x=LDREG_WORD(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
SDREG_WORD(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1215){ 
WORD r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_WORD(V_AN_PI_WORD((UBITS(0,5,iw)&7)));;
x=LDREG_WORD(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
SDREG_WORD(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1216){ 
WORD r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_WORD(V_AN_PD_WORD((UBITS(0,5,iw)&7)));;
x=LDREG_WORD(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
SDREG_WORD(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1217){ 
WORD r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_WORD(V_AN_D_WORD((UBITS(0,5,iw)&7)));;
x=LDREG_WORD(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
SDREG_WORD(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1218){ 
WORD r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_WORD(V_AN_R_WORD((UBITS(0,5,iw)&7)));;
x=LDREG_WORD(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
SDREG_WORD(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1219){ 
WORD r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_WORD(V_ABS_W_WORD());;
x=LDREG_WORD(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
SDREG_WORD(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1220){ 
WORD r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_WORD(V_ABS_L_WORD());;
x=LDREG_WORD(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
SDREG_WORD(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1221){ 
WORD r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_WORD(V_PC_D_WORD());;
x=LDREG_WORD(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
SDREG_WORD(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1222){ 
WORD r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_WORD(V_PC_R_WORD());;
x=LDREG_WORD(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
SDREG_WORD(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1223){ 
WORD r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=LM_WORD(MEM(V_IMM_WORD()));;
x=LDREG_WORD(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
SDREG_WORD(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1224){ 
LONG r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=LDREG_LONG((UBITS(0,5,iw)&7));;
x=LDREG_LONG(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
SDREG_LONG(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1225){ 
LONG r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_LONG(V_AN_I_LONG((UBITS(0,5,iw)&7)));;
x=LDREG_LONG(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
SDREG_LONG(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1226){ 
LONG r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_LONG(V_AN_PI_LONG((UBITS(0,5,iw)&7)));;
x=LDREG_LONG(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
SDREG_LONG(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1227){ 
LONG r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_LONG(V_AN_PD_LONG((UBITS(0,5,iw)&7)));;
x=LDREG_LONG(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
SDREG_LONG(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1228){ 
LONG r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_LONG(V_AN_D_LONG((UBITS(0,5,iw)&7)));;
x=LDREG_LONG(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
SDREG_LONG(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1229){ 
LONG r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_LONG(V_AN_R_LONG((UBITS(0,5,iw)&7)));;
x=LDREG_LONG(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
SDREG_LONG(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1230){ 
LONG r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_LONG(V_ABS_W_LONG());;
x=LDREG_LONG(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
SDREG_LONG(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1231){ 
LONG r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_LONG(V_ABS_L_LONG());;
x=LDREG_LONG(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
SDREG_LONG(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1232){ 
LONG r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_LONG(V_PC_D_LONG());;
x=LDREG_LONG(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
SDREG_LONG(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1233){ 
LONG r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_LONG(V_PC_R_LONG());;
x=LDREG_LONG(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
SDREG_LONG(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1234){ 
LONG r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=LM_LONG(MEM(V_IMM_LONG()));;
x=LDREG_LONG(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
SDREG_LONG(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1235){ 
UWORD d;
ULONG r,x;
int reg;
reg=UBITS(9,11,iw);
d=LDREG_WORD((UBITS(0,5,iw)&7));;
x=LDREG_UL(reg);
if (d==0) ex_div0();
else
{
	sr &= ~MASK_CC|MASK_CC_X;
	r = x / d;
	if (((UWORD) r) != r) sr |= MASK_CC_V;
	else
	{
		SET_NZ((LONG)((WORD) r));
		r &= 0xffff;
		r |= (x % d) << 16;
		DREG(reg) = r;
	}
#if 0
	fprintf(stderr,"divu: %d / %d = <%d,%d> = %0x sr=%04x nz=%d\n",
		x, d, (x/d), (x%d), r,sr,nz_save);
#endif
}
THREAD
; }
GENFUNC_PROTO(Func1236){ 
UWORD d;
ULONG r,x;
int reg;
reg=UBITS(9,11,iw);
d=CL_WORD(V_AN_I_WORD((UBITS(0,5,iw)&7)));;
x=LDREG_UL(reg);
if (d==0) ex_div0();
else
{
	sr &= ~MASK_CC|MASK_CC_X;
	r = x / d;
	if (((UWORD) r) != r) sr |= MASK_CC_V;
	else
	{
		SET_NZ((LONG)((WORD) r));
		r &= 0xffff;
		r |= (x % d) << 16;
		DREG(reg) = r;
	}
#if 0
	fprintf(stderr,"divu: %d / %d = <%d,%d> = %0x sr=%04x nz=%d\n",
		x, d, (x/d), (x%d), r,sr,nz_save);
#endif
}
THREAD
; }
GENFUNC_PROTO(Func1237){ 
UWORD d;
ULONG r,x;
int reg;
reg=UBITS(9,11,iw);
d=CL_WORD(V_AN_PI_WORD((UBITS(0,5,iw)&7)));;
x=LDREG_UL(reg);
if (d==0) ex_div0();
else
{
	sr &= ~MASK_CC|MASK_CC_X;
	r = x / d;
	if (((UWORD) r) != r) sr |= MASK_CC_V;
	else
	{
		SET_NZ((LONG)((WORD) r));
		r &= 0xffff;
		r |= (x % d) << 16;
		DREG(reg) = r;
	}
#if 0
	fprintf(stderr,"divu: %d / %d = <%d,%d> = %0x sr=%04x nz=%d\n",
		x, d, (x/d), (x%d), r,sr,nz_save);
#endif
}
THREAD
; }
GENFUNC_PROTO(Func1238){ 
UWORD d;
ULONG r,x;
int reg;
reg=UBITS(9,11,iw);
d=CL_WORD(V_AN_PD_WORD((UBITS(0,5,iw)&7)));;
x=LDREG_UL(reg);
if (d==0) ex_div0();
else
{
	sr &= ~MASK_CC|MASK_CC_X;
	r = x / d;
	if (((UWORD) r) != r) sr |= MASK_CC_V;
	else
	{
		SET_NZ((LONG)((WORD) r));
		r &= 0xffff;
		r |= (x % d) << 16;
		DREG(reg) = r;
	}
#if 0
	fprintf(stderr,"divu: %d / %d = <%d,%d> = %0x sr=%04x nz=%d\n",
		x, d, (x/d), (x%d), r,sr,nz_save);
#endif
}
THREAD
; }
GENFUNC_PROTO(Func1239){ 
UWORD d;
ULONG r,x;
int reg;
reg=UBITS(9,11,iw);
d=CL_WORD(V_AN_D_WORD((UBITS(0,5,iw)&7)));;
x=LDREG_UL(reg);
if (d==0) ex_div0();
else
{
	sr &= ~MASK_CC|MASK_CC_X;
	r = x / d;
	if (((UWORD) r) != r) sr |= MASK_CC_V;
	else
	{
		SET_NZ((LONG)((WORD) r));
		r &= 0xffff;
		r |= (x % d) << 16;
		DREG(reg) = r;
	}
#if 0
	fprintf(stderr,"divu: %d / %d = <%d,%d> = %0x sr=%04x nz=%d\n",
		x, d, (x/d), (x%d), r,sr,nz_save);
#endif
}
THREAD
; }
GENFUNC_PROTO(Func1240){ 
UWORD d;
ULONG r,x;
int reg;
reg=UBITS(9,11,iw);
d=CL_WORD(V_AN_R_WORD((UBITS(0,5,iw)&7)));;
x=LDREG_UL(reg);
if (d==0) ex_div0();
else
{
	sr &= ~MASK_CC|MASK_CC_X;
	r = x / d;
	if (((UWORD) r) != r) sr |= MASK_CC_V;
	else
	{
		SET_NZ((LONG)((WORD) r));
		r &= 0xffff;
		r |= (x % d) << 16;
		DREG(reg) = r;
	}
#if 0
	fprintf(stderr,"divu: %d / %d = <%d,%d> = %0x sr=%04x nz=%d\n",
		x, d, (x/d), (x%d), r,sr,nz_save);
#endif
}
THREAD
; }
GENFUNC_PROTO(Func1241){ 
UWORD d;
ULONG r,x;
int reg;
reg=UBITS(9,11,iw);
d=CL_WORD(V_ABS_W_WORD());;
x=LDREG_UL(reg);
if (d==0) ex_div0();
else
{
	sr &= ~MASK_CC|MASK_CC_X;
	r = x / d;
	if (((UWORD) r) != r) sr |= MASK_CC_V;
	else
	{
		SET_NZ((LONG)((WORD) r));
		r &= 0xffff;
		r |= (x % d) << 16;
		DREG(reg) = r;
	}
#if 0
	fprintf(stderr,"divu: %d / %d = <%d,%d> = %0x sr=%04x nz=%d\n",
		x, d, (x/d), (x%d), r,sr,nz_save);
#endif
}
THREAD
; }
GENFUNC_PROTO(Func1242){ 
UWORD d;
ULONG r,x;
int reg;
reg=UBITS(9,11,iw);
d=CL_WORD(V_ABS_L_WORD());;
x=LDREG_UL(reg);
if (d==0) ex_div0();
else
{
	sr &= ~MASK_CC|MASK_CC_X;
	r = x / d;
	if (((UWORD) r) != r) sr |= MASK_CC_V;
	else
	{
		SET_NZ((LONG)((WORD) r));
		r &= 0xffff;
		r |= (x % d) << 16;
		DREG(reg) = r;
	}
#if 0
	fprintf(stderr,"divu: %d / %d = <%d,%d> = %0x sr=%04x nz=%d\n",
		x, d, (x/d), (x%d), r,sr,nz_save);
#endif
}
THREAD
; }
GENFUNC_PROTO(Func1243){ 
UWORD d;
ULONG r,x;
int reg;
reg=UBITS(9,11,iw);
d=CL_WORD(V_PC_D_WORD());;
x=LDREG_UL(reg);
if (d==0) ex_div0();
else
{
	sr &= ~MASK_CC|MASK_CC_X;
	r = x / d;
	if (((UWORD) r) != r) sr |= MASK_CC_V;
	else
	{
		SET_NZ((LONG)((WORD) r));
		r &= 0xffff;
		r |= (x % d) << 16;
		DREG(reg) = r;
	}
#if 0
	fprintf(stderr,"divu: %d / %d = <%d,%d> = %0x sr=%04x nz=%d\n",
		x, d, (x/d), (x%d), r,sr,nz_save);
#endif
}
THREAD
; }
GENFUNC_PROTO(Func1244){ 
UWORD d;
ULONG r,x;
int reg;
reg=UBITS(9,11,iw);
d=CL_WORD(V_PC_R_WORD());;
x=LDREG_UL(reg);
if (d==0) ex_div0();
else
{
	sr &= ~MASK_CC|MASK_CC_X;
	r = x / d;
	if (((UWORD) r) != r) sr |= MASK_CC_V;
	else
	{
		SET_NZ((LONG)((WORD) r));
		r &= 0xffff;
		r |= (x % d) << 16;
		DREG(reg) = r;
	}
#if 0
	fprintf(stderr,"divu: %d / %d = <%d,%d> = %0x sr=%04x nz=%d\n",
		x, d, (x/d), (x%d), r,sr,nz_save);
#endif
}
THREAD
; }
GENFUNC_PROTO(Func1245){ 
UWORD d;
ULONG r,x;
int reg;
reg=UBITS(9,11,iw);
d=LM_WORD(MEM(V_IMM_WORD()));;
x=LDREG_UL(reg);
if (d==0) ex_div0();
else
{
	sr &= ~MASK_CC|MASK_CC_X;
	r = x / d;
	if (((UWORD) r) != r) sr |= MASK_CC_V;
	else
	{
		SET_NZ((LONG)((WORD) r));
		r &= 0xffff;
		r |= (x % d) << 16;
		DREG(reg) = r;
	}
#if 0
	fprintf(stderr,"divu: %d / %d = <%d,%d> = %0x sr=%04x nz=%d\n",
		x, d, (x/d), (x%d), r,sr,nz_save);
#endif
}
THREAD
; }
GENFUNC_PROTO(Func1246){ 
BYTE s,x,*d;
s = LDREG_BYTE(UBITS(9,11,iw));
d = DREG_B(UBITS(0,2,iw));
x = BCD_SUB(s,LR_B(d));
SR_B(d,x);
THREAD
; }
GENFUNC_PROTO(Func1247){ 
BYTE s,x;
UL d;
s = CL_B(V_AN_PD_BYTE_All(UBITS(9,11,iw)));
d = V_AN_PD_BYTE_All(UBITS(0,2,iw));
x = BCD_SUB(s,CL_B(d));
CS_B(d,x);
THREAD
; }
GENFUNC_PROTO(Func1248){ 
BYTE r,x,s;
s=LDREG_BYTE(UBITS(9,11,iw));
{UL v_x=V_AN_I_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1249){ 
BYTE r,x,s;
s=LDREG_BYTE(UBITS(9,11,iw));
{UL v_x=V_AN_PI_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1250){ 
BYTE r,x,s;
s=LDREG_BYTE(UBITS(9,11,iw));
{UL v_x=V_AN_PI_BYTE_All(7); x=CL_BYTE(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1251){ 
BYTE r,x,s;
s=LDREG_BYTE(UBITS(9,11,iw));
{UL v_x=V_AN_PD_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1252){ 
BYTE r,x,s;
s=LDREG_BYTE(UBITS(9,11,iw));
{UL v_x=V_AN_PD_BYTE_All(7); x=CL_BYTE(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1253){ 
BYTE r,x,s;
s=LDREG_BYTE(UBITS(9,11,iw));
{UL v_x=V_AN_D_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1254){ 
BYTE r,x,s;
s=LDREG_BYTE(UBITS(9,11,iw));
{UL v_x=V_AN_R_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1255){ 
BYTE r,x,s;
s=LDREG_BYTE(UBITS(9,11,iw));
{UL v_x=V_ABS_W_BYTE(); x=CL_BYTE(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1256){ 
BYTE r,x,s;
s=LDREG_BYTE(UBITS(9,11,iw));
{UL v_x=V_ABS_L_BYTE(); x=CL_BYTE(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1257){ 
WORD r,x,s;
s=LDREG_WORD(UBITS(9,11,iw));
{UL v_x=V_AN_I_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1258){ 
WORD r,x,s;
s=LDREG_WORD(UBITS(9,11,iw));
{UL v_x=V_AN_PI_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1259){ 
WORD r,x,s;
s=LDREG_WORD(UBITS(9,11,iw));
{UL v_x=V_AN_PD_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1260){ 
WORD r,x,s;
s=LDREG_WORD(UBITS(9,11,iw));
{UL v_x=V_AN_D_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1261){ 
WORD r,x,s;
s=LDREG_WORD(UBITS(9,11,iw));
{UL v_x=V_AN_R_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1262){ 
WORD r,x,s;
s=LDREG_WORD(UBITS(9,11,iw));
{UL v_x=V_ABS_W_WORD(); x=CL_WORD(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1263){ 
WORD r,x,s;
s=LDREG_WORD(UBITS(9,11,iw));
{UL v_x=V_ABS_L_WORD(); x=CL_WORD(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1264){ 
LONG r,x,s;
s=LDREG_LONG(UBITS(9,11,iw));
{UL v_x=V_AN_I_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1265){ 
LONG r,x,s;
s=LDREG_LONG(UBITS(9,11,iw));
{UL v_x=V_AN_PI_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1266){ 
LONG r,x,s;
s=LDREG_LONG(UBITS(9,11,iw));
{UL v_x=V_AN_PD_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1267){ 
LONG r,x,s;
s=LDREG_LONG(UBITS(9,11,iw));
{UL v_x=V_AN_D_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1268){ 
LONG r,x,s;
s=LDREG_LONG(UBITS(9,11,iw));
{UL v_x=V_AN_R_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1269){ 
LONG r,x,s;
s=LDREG_LONG(UBITS(9,11,iw));
{UL v_x=V_ABS_W_LONG(); x=CL_LONG(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1270){ 
LONG r,x,s;
s=LDREG_LONG(UBITS(9,11,iw));
{UL v_x=V_ABS_L_LONG(); x=CL_LONG(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s | x;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1271){ 
WORD d;
LONG r;
int x,reg=UBITS(9,11,iw);
x=DREG(reg);
d=LDREG_WORD((UBITS(0,5,iw)&7));;
if (d==0) ex_div0();
else
{
	sr &= ~MASK_CC|MASK_CC_X;
	r = x/d;
	if (((WORD)r)!=r) sr |= MASK_CC_V;
	else
	{
		SET_NZ(((WORD)r));
		r &= 0xffff;
		r |= (x%d) << 16;
		DREG(reg) = r;
	}
#if 0
	fprintf(stderr,"* divs: %d / %d = <%d,%d> = %0x sr=%04x nz=%d\n",
		x, d, (x/d), (x%d), r, sr, nz_save);
#endif
}
THREAD
; }
GENFUNC_PROTO(Func1272){ 
WORD d;
LONG r;
int x,reg=UBITS(9,11,iw);
x=DREG(reg);
d=CL_WORD(V_AN_I_WORD((UBITS(0,5,iw)&7)));;
if (d==0) ex_div0();
else
{
	sr &= ~MASK_CC|MASK_CC_X;
	r = x/d;
	if (((WORD)r)!=r) sr |= MASK_CC_V;
	else
	{
		SET_NZ(((WORD)r));
		r &= 0xffff;
		r |= (x%d) << 16;
		DREG(reg) = r;
	}
#if 0
	fprintf(stderr,"* divs: %d / %d = <%d,%d> = %0x sr=%04x nz=%d\n",
		x, d, (x/d), (x%d), r, sr, nz_save);
#endif
}
THREAD
; }
GENFUNC_PROTO(Func1273){ 
WORD d;
LONG r;
int x,reg=UBITS(9,11,iw);
x=DREG(reg);
d=CL_WORD(V_AN_PI_WORD((UBITS(0,5,iw)&7)));;
if (d==0) ex_div0();
else
{
	sr &= ~MASK_CC|MASK_CC_X;
	r = x/d;
	if (((WORD)r)!=r) sr |= MASK_CC_V;
	else
	{
		SET_NZ(((WORD)r));
		r &= 0xffff;
		r |= (x%d) << 16;
		DREG(reg) = r;
	}
#if 0
	fprintf(stderr,"* divs: %d / %d = <%d,%d> = %0x sr=%04x nz=%d\n",
		x, d, (x/d), (x%d), r, sr, nz_save);
#endif
}
THREAD
; }
GENFUNC_PROTO(Func1274){ 
WORD d;
LONG r;
int x,reg=UBITS(9,11,iw);
x=DREG(reg);
d=CL_WORD(V_AN_PD_WORD((UBITS(0,5,iw)&7)));;
if (d==0) ex_div0();
else
{
	sr &= ~MASK_CC|MASK_CC_X;
	r = x/d;
	if (((WORD)r)!=r) sr |= MASK_CC_V;
	else
	{
		SET_NZ(((WORD)r));
		r &= 0xffff;
		r |= (x%d) << 16;
		DREG(reg) = r;
	}
#if 0
	fprintf(stderr,"* divs: %d / %d = <%d,%d> = %0x sr=%04x nz=%d\n",
		x, d, (x/d), (x%d), r, sr, nz_save);
#endif
}
THREAD
; }
GENFUNC_PROTO(Func1275){ 
WORD d;
LONG r;
int x,reg=UBITS(9,11,iw);
x=DREG(reg);
d=CL_WORD(V_AN_D_WORD((UBITS(0,5,iw)&7)));;
if (d==0) ex_div0();
else
{
	sr &= ~MASK_CC|MASK_CC_X;
	r = x/d;
	if (((WORD)r)!=r) sr |= MASK_CC_V;
	else
	{
		SET_NZ(((WORD)r));
		r &= 0xffff;
		r |= (x%d) << 16;
		DREG(reg) = r;
	}
#if 0
	fprintf(stderr,"* divs: %d / %d = <%d,%d> = %0x sr=%04x nz=%d\n",
		x, d, (x/d), (x%d), r, sr, nz_save);
#endif
}
THREAD
; }
GENFUNC_PROTO(Func1276){ 
WORD d;
LONG r;
int x,reg=UBITS(9,11,iw);
x=DREG(reg);
d=CL_WORD(V_AN_R_WORD((UBITS(0,5,iw)&7)));;
if (d==0) ex_div0();
else
{
	sr &= ~MASK_CC|MASK_CC_X;
	r = x/d;
	if (((WORD)r)!=r) sr |= MASK_CC_V;
	else
	{
		SET_NZ(((WORD)r));
		r &= 0xffff;
		r |= (x%d) << 16;
		DREG(reg) = r;
	}
#if 0
	fprintf(stderr,"* divs: %d / %d = <%d,%d> = %0x sr=%04x nz=%d\n",
		x, d, (x/d), (x%d), r, sr, nz_save);
#endif
}
THREAD
; }
GENFUNC_PROTO(Func1277){ 
WORD d;
LONG r;
int x,reg=UBITS(9,11,iw);
x=DREG(reg);
d=CL_WORD(V_ABS_W_WORD());;
if (d==0) ex_div0();
else
{
	sr &= ~MASK_CC|MASK_CC_X;
	r = x/d;
	if (((WORD)r)!=r) sr |= MASK_CC_V;
	else
	{
		SET_NZ(((WORD)r));
		r &= 0xffff;
		r |= (x%d) << 16;
		DREG(reg) = r;
	}
#if 0
	fprintf(stderr,"* divs: %d / %d = <%d,%d> = %0x sr=%04x nz=%d\n",
		x, d, (x/d), (x%d), r, sr, nz_save);
#endif
}
THREAD
; }
GENFUNC_PROTO(Func1278){ 
WORD d;
LONG r;
int x,reg=UBITS(9,11,iw);
x=DREG(reg);
d=CL_WORD(V_ABS_L_WORD());;
if (d==0) ex_div0();
else
{
	sr &= ~MASK_CC|MASK_CC_X;
	r = x/d;
	if (((WORD)r)!=r) sr |= MASK_CC_V;
	else
	{
		SET_NZ(((WORD)r));
		r &= 0xffff;
		r |= (x%d) << 16;
		DREG(reg) = r;
	}
#if 0
	fprintf(stderr,"* divs: %d / %d = <%d,%d> = %0x sr=%04x nz=%d\n",
		x, d, (x/d), (x%d), r, sr, nz_save);
#endif
}
THREAD
; }
GENFUNC_PROTO(Func1279){ 
WORD d;
LONG r;
int x,reg=UBITS(9,11,iw);
x=DREG(reg);
d=CL_WORD(V_PC_D_WORD());;
if (d==0) ex_div0();
else
{
	sr &= ~MASK_CC|MASK_CC_X;
	r = x/d;
	if (((WORD)r)!=r) sr |= MASK_CC_V;
	else
	{
		SET_NZ(((WORD)r));
		r &= 0xffff;
		r |= (x%d) << 16;
		DREG(reg) = r;
	}
#if 0
	fprintf(stderr,"* divs: %d / %d = <%d,%d> = %0x sr=%04x nz=%d\n",
		x, d, (x/d), (x%d), r, sr, nz_save);
#endif
}
THREAD
; }
GENFUNC_PROTO(Func1280){ 
WORD d;
LONG r;
int x,reg=UBITS(9,11,iw);
x=DREG(reg);
d=CL_WORD(V_PC_R_WORD());;
if (d==0) ex_div0();
else
{
	sr &= ~MASK_CC|MASK_CC_X;
	r = x/d;
	if (((WORD)r)!=r) sr |= MASK_CC_V;
	else
	{
		SET_NZ(((WORD)r));
		r &= 0xffff;
		r |= (x%d) << 16;
		DREG(reg) = r;
	}
#if 0
	fprintf(stderr,"* divs: %d / %d = <%d,%d> = %0x sr=%04x nz=%d\n",
		x, d, (x/d), (x%d), r, sr, nz_save);
#endif
}
THREAD
; }
GENFUNC_PROTO(Func1281){ 
WORD d;
LONG r;
int x,reg=UBITS(9,11,iw);
x=DREG(reg);
d=LM_WORD(MEM(V_IMM_WORD()));;
if (d==0) ex_div0();
else
{
	sr &= ~MASK_CC|MASK_CC_X;
	r = x/d;
	if (((WORD)r)!=r) sr |= MASK_CC_V;
	else
	{
		SET_NZ(((WORD)r));
		r &= 0xffff;
		r |= (x%d) << 16;
		DREG(reg) = r;
	}
#if 0
	fprintf(stderr,"* divs: %d / %d = <%d,%d> = %0x sr=%04x nz=%d\n",
		x, d, (x/d), (x%d), r, sr, nz_save);
#endif
}
THREAD
; }
GENFUNC_PROTO(Func1282){ 
BYTE r,x,s;
int n=UBITS(9,11,iw);
s=LDREG_BYTE((UBITS(0,5,iw)&7));;
x=LDREG_BYTE(n);
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
SDREG_BYTE(n,r);
THREAD
; }
GENFUNC_PROTO(Func1283){ 
BYTE r,x,s;
int n=UBITS(9,11,iw);
s=CL_BYTE(V_AN_I_BYTE((UBITS(0,5,iw)&7)));;
x=LDREG_BYTE(n);
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
SDREG_BYTE(n,r);
THREAD
; }
GENFUNC_PROTO(Func1284){ 
BYTE r,x,s;
int n=UBITS(9,11,iw);
s=CL_BYTE(V_AN_PI_BYTE((UBITS(0,5,iw)&7)));;
x=LDREG_BYTE(n);
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
SDREG_BYTE(n,r);
THREAD
; }
GENFUNC_PROTO(Func1285){ 
BYTE r,x,s;
int n=UBITS(9,11,iw);
s=CL_BYTE(V_AN_PI_BYTE_All(7));;
x=LDREG_BYTE(n);
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
SDREG_BYTE(n,r);
THREAD
; }
GENFUNC_PROTO(Func1286){ 
BYTE r,x,s;
int n=UBITS(9,11,iw);
s=CL_BYTE(V_AN_PD_BYTE((UBITS(0,5,iw)&7)));;
x=LDREG_BYTE(n);
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
SDREG_BYTE(n,r);
THREAD
; }
GENFUNC_PROTO(Func1287){ 
BYTE r,x,s;
int n=UBITS(9,11,iw);
s=CL_BYTE(V_AN_PD_BYTE_All(7));;
x=LDREG_BYTE(n);
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
SDREG_BYTE(n,r);
THREAD
; }
GENFUNC_PROTO(Func1288){ 
BYTE r,x,s;
int n=UBITS(9,11,iw);
s=CL_BYTE(V_AN_D_BYTE((UBITS(0,5,iw)&7)));;
x=LDREG_BYTE(n);
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
SDREG_BYTE(n,r);
THREAD
; }
GENFUNC_PROTO(Func1289){ 
BYTE r,x,s;
int n=UBITS(9,11,iw);
s=CL_BYTE(V_AN_R_BYTE((UBITS(0,5,iw)&7)));;
x=LDREG_BYTE(n);
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
SDREG_BYTE(n,r);
THREAD
; }
GENFUNC_PROTO(Func1290){ 
BYTE r,x,s;
int n=UBITS(9,11,iw);
s=CL_BYTE(V_ABS_W_BYTE());;
x=LDREG_BYTE(n);
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
SDREG_BYTE(n,r);
THREAD
; }
GENFUNC_PROTO(Func1291){ 
BYTE r,x,s;
int n=UBITS(9,11,iw);
s=CL_BYTE(V_ABS_L_BYTE());;
x=LDREG_BYTE(n);
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
SDREG_BYTE(n,r);
THREAD
; }
GENFUNC_PROTO(Func1292){ 
BYTE r,x,s;
int n=UBITS(9,11,iw);
s=CL_BYTE(V_PC_D_BYTE());;
x=LDREG_BYTE(n);
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
SDREG_BYTE(n,r);
THREAD
; }
GENFUNC_PROTO(Func1293){ 
BYTE r,x,s;
int n=UBITS(9,11,iw);
s=CL_BYTE(V_PC_R_BYTE());;
x=LDREG_BYTE(n);
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
SDREG_BYTE(n,r);
THREAD
; }
GENFUNC_PROTO(Func1294){ 
BYTE r,x,s;
int n=UBITS(9,11,iw);
s=LM_BYTE(MEM(V_IMM_BYTE()));;
x=LDREG_BYTE(n);
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
SDREG_BYTE(n,r);
THREAD
; }
GENFUNC_PROTO(Func1295){ 
WORD r,x,s;
int n=UBITS(9,11,iw);
s=LDREG_WORD((UBITS(0,5,iw)&7));;
x=LDREG_WORD(n);
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
SDREG_WORD(n,r);
THREAD
; }
GENFUNC_PROTO(Func1296){ 
WORD r,x,s;
int n=UBITS(9,11,iw);
s=LDREG_WORD((UBITS(0,5,iw)&7)+8);;
x=LDREG_WORD(n);
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
SDREG_WORD(n,r);
THREAD
; }
GENFUNC_PROTO(Func1297){ 
WORD r,x,s;
int n=UBITS(9,11,iw);
s=CL_WORD(V_AN_I_WORD((UBITS(0,5,iw)&7)));;
x=LDREG_WORD(n);
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
SDREG_WORD(n,r);
THREAD
; }
GENFUNC_PROTO(Func1298){ 
WORD r,x,s;
int n=UBITS(9,11,iw);
s=CL_WORD(V_AN_PI_WORD((UBITS(0,5,iw)&7)));;
x=LDREG_WORD(n);
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
SDREG_WORD(n,r);
THREAD
; }
GENFUNC_PROTO(Func1299){ 
WORD r,x,s;
int n=UBITS(9,11,iw);
s=CL_WORD(V_AN_PD_WORD((UBITS(0,5,iw)&7)));;
x=LDREG_WORD(n);
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
SDREG_WORD(n,r);
THREAD
; }
GENFUNC_PROTO(Func1300){ 
WORD r,x,s;
int n=UBITS(9,11,iw);
s=CL_WORD(V_AN_D_WORD((UBITS(0,5,iw)&7)));;
x=LDREG_WORD(n);
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
SDREG_WORD(n,r);
THREAD
; }
GENFUNC_PROTO(Func1301){ 
WORD r,x,s;
int n=UBITS(9,11,iw);
s=CL_WORD(V_AN_R_WORD((UBITS(0,5,iw)&7)));;
x=LDREG_WORD(n);
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
SDREG_WORD(n,r);
THREAD
; }
GENFUNC_PROTO(Func1302){ 
WORD r,x,s;
int n=UBITS(9,11,iw);
s=CL_WORD(V_ABS_W_WORD());;
x=LDREG_WORD(n);
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
SDREG_WORD(n,r);
THREAD
; }
GENFUNC_PROTO(Func1303){ 
WORD r,x,s;
int n=UBITS(9,11,iw);
s=CL_WORD(V_ABS_L_WORD());;
x=LDREG_WORD(n);
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
SDREG_WORD(n,r);
THREAD
; }
GENFUNC_PROTO(Func1304){ 
WORD r,x,s;
int n=UBITS(9,11,iw);
s=CL_WORD(V_PC_D_WORD());;
x=LDREG_WORD(n);
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
SDREG_WORD(n,r);
THREAD
; }
GENFUNC_PROTO(Func1305){ 
WORD r,x,s;
int n=UBITS(9,11,iw);
s=CL_WORD(V_PC_R_WORD());;
x=LDREG_WORD(n);
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
SDREG_WORD(n,r);
THREAD
; }
GENFUNC_PROTO(Func1306){ 
WORD r,x,s;
int n=UBITS(9,11,iw);
s=LM_WORD(MEM(V_IMM_WORD()));;
x=LDREG_WORD(n);
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
SDREG_WORD(n,r);
THREAD
; }
GENFUNC_PROTO(Func1307){ 
LONG r,x,s;
int n=UBITS(9,11,iw);
s=LDREG_LONG((UBITS(0,5,iw)&7));;
x=LDREG_LONG(n);
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
SDREG_LONG(n,r);
THREAD
; }
GENFUNC_PROTO(Func1308){ 
LONG r,x,s;
int n=UBITS(9,11,iw);
s=LDREG_LONG((UBITS(0,5,iw)&7)+8);;
x=LDREG_LONG(n);
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
SDREG_LONG(n,r);
THREAD
; }
GENFUNC_PROTO(Func1309){ 
LONG r,x,s;
int n=UBITS(9,11,iw);
s=CL_LONG(V_AN_I_LONG((UBITS(0,5,iw)&7)));;
x=LDREG_LONG(n);
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
SDREG_LONG(n,r);
THREAD
; }
GENFUNC_PROTO(Func1310){ 
LONG r,x,s;
int n=UBITS(9,11,iw);
s=CL_LONG(V_AN_PI_LONG((UBITS(0,5,iw)&7)));;
x=LDREG_LONG(n);
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
SDREG_LONG(n,r);
THREAD
; }
GENFUNC_PROTO(Func1311){ 
LONG r,x,s;
int n=UBITS(9,11,iw);
s=CL_LONG(V_AN_PD_LONG((UBITS(0,5,iw)&7)));;
x=LDREG_LONG(n);
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
SDREG_LONG(n,r);
THREAD
; }
GENFUNC_PROTO(Func1312){ 
LONG r,x,s;
int n=UBITS(9,11,iw);
s=CL_LONG(V_AN_D_LONG((UBITS(0,5,iw)&7)));;
x=LDREG_LONG(n);
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
SDREG_LONG(n,r);
THREAD
; }
GENFUNC_PROTO(Func1313){ 
LONG r,x,s;
int n=UBITS(9,11,iw);
s=CL_LONG(V_AN_R_LONG((UBITS(0,5,iw)&7)));;
x=LDREG_LONG(n);
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
SDREG_LONG(n,r);
THREAD
; }
GENFUNC_PROTO(Func1314){ 
LONG r,x,s;
int n=UBITS(9,11,iw);
s=CL_LONG(V_ABS_W_LONG());;
x=LDREG_LONG(n);
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
SDREG_LONG(n,r);
THREAD
; }
GENFUNC_PROTO(Func1315){ 
LONG r,x,s;
int n=UBITS(9,11,iw);
s=CL_LONG(V_ABS_L_LONG());;
x=LDREG_LONG(n);
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
SDREG_LONG(n,r);
THREAD
; }
GENFUNC_PROTO(Func1316){ 
LONG r,x,s;
int n=UBITS(9,11,iw);
s=CL_LONG(V_PC_D_LONG());;
x=LDREG_LONG(n);
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
SDREG_LONG(n,r);
THREAD
; }
GENFUNC_PROTO(Func1317){ 
LONG r,x,s;
int n=UBITS(9,11,iw);
s=CL_LONG(V_PC_R_LONG());;
x=LDREG_LONG(n);
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
SDREG_LONG(n,r);
THREAD
; }
GENFUNC_PROTO(Func1318){ 
LONG r,x,s;
int n=UBITS(9,11,iw);
s=LM_LONG(MEM(V_IMM_LONG()));;
x=LDREG_LONG(n);
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
SDREG_LONG(n,r);
THREAD
; }
GENFUNC_PROTO(Func1319){ 
LONG x;
x=LDREG_WORD((UBITS(0,5,iw)&7));;
AREG(UBITS(9,11,iw)) -= x;
THREAD
; }
GENFUNC_PROTO(Func1320){ 
LONG x;
x=LDREG_WORD((UBITS(0,5,iw)&7)+8);;
AREG(UBITS(9,11,iw)) -= x;
THREAD
; }
GENFUNC_PROTO(Func1321){ 
LONG x;
x=CL_WORD(V_AN_I_WORD((UBITS(0,5,iw)&7)));;
AREG(UBITS(9,11,iw)) -= x;
THREAD
; }
GENFUNC_PROTO(Func1322){ 
LONG x;
x=CL_WORD(V_AN_PI_WORD((UBITS(0,5,iw)&7)));;
AREG(UBITS(9,11,iw)) -= x;
THREAD
; }
GENFUNC_PROTO(Func1323){ 
LONG x;
x=CL_WORD(V_AN_PD_WORD((UBITS(0,5,iw)&7)));;
AREG(UBITS(9,11,iw)) -= x;
THREAD
; }
GENFUNC_PROTO(Func1324){ 
LONG x;
x=CL_WORD(V_AN_D_WORD((UBITS(0,5,iw)&7)));;
AREG(UBITS(9,11,iw)) -= x;
THREAD
; }
GENFUNC_PROTO(Func1325){ 
LONG x;
x=CL_WORD(V_AN_R_WORD((UBITS(0,5,iw)&7)));;
AREG(UBITS(9,11,iw)) -= x;
THREAD
; }
GENFUNC_PROTO(Func1326){ 
LONG x;
x=CL_WORD(V_ABS_W_WORD());;
AREG(UBITS(9,11,iw)) -= x;
THREAD
; }
GENFUNC_PROTO(Func1327){ 
LONG x;
x=CL_WORD(V_ABS_L_WORD());;
AREG(UBITS(9,11,iw)) -= x;
THREAD
; }
GENFUNC_PROTO(Func1328){ 
LONG x;
x=CL_WORD(V_PC_D_WORD());;
AREG(UBITS(9,11,iw)) -= x;
THREAD
; }
GENFUNC_PROTO(Func1329){ 
LONG x;
x=CL_WORD(V_PC_R_WORD());;
AREG(UBITS(9,11,iw)) -= x;
THREAD
; }
GENFUNC_PROTO(Func1330){ 
LONG x;
x=LM_WORD(MEM(V_IMM_WORD()));;
AREG(UBITS(9,11,iw)) -= x;
THREAD
; }
GENFUNC_PROTO(Func1331){ 
BYTE s,x,r,t;
int n=UBITS(9,11,iw);
t=GET_X_BIT();
sr &= ~MASK_CC | MASK_CC_Z; /* FIXME? */
s=LDREG_BYTE(UBITS(0,2,iw));
x=LDREG_BYTE(n);
r=x-s-t;
SET_VCX_SUB;
if (r) SET_NZ(r);
else UNSET_N();
SDREG_BYTE(n,r);
THREAD
; }
GENFUNC_PROTO(Func1332){ 
BYTE s,x,r,t;
int n=UBITS(9,11,iw);
t=GET_X_BIT();
sr &= ~MASK_CC | MASK_CC_Z;

s=CL_BYTE(V_AN_PD_BYTE_All(UBITS(0,2,iw)));;
{UL v_x=V_AN_PD_BYTE_All(n); x=CL_BYTE(v_x);;
r=x-s-t;
SET_VCX_SUB;
UNSET_Z();
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1333){ 
BYTE s,r,x;
s=LDREG_BYTE(UBITS(9,11,iw));
{UL v_x=V_AN_I_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1334){ 
BYTE s,r,x;
s=LDREG_BYTE(UBITS(9,11,iw));
{UL v_x=V_AN_PI_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1335){ 
BYTE s,r,x;
s=LDREG_BYTE(UBITS(9,11,iw));
{UL v_x=V_AN_PI_BYTE_All(7); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1336){ 
BYTE s,r,x;
s=LDREG_BYTE(UBITS(9,11,iw));
{UL v_x=V_AN_PD_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1337){ 
BYTE s,r,x;
s=LDREG_BYTE(UBITS(9,11,iw));
{UL v_x=V_AN_PD_BYTE_All(7); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1338){ 
BYTE s,r,x;
s=LDREG_BYTE(UBITS(9,11,iw));
{UL v_x=V_AN_D_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1339){ 
BYTE s,r,x;
s=LDREG_BYTE(UBITS(9,11,iw));
{UL v_x=V_AN_R_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1340){ 
BYTE s,r,x;
s=LDREG_BYTE(UBITS(9,11,iw));
{UL v_x=V_ABS_W_BYTE(); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1341){ 
BYTE s,r,x;
s=LDREG_BYTE(UBITS(9,11,iw));
{UL v_x=V_ABS_L_BYTE(); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1342){ 
WORD s,x,r,t;
int n=UBITS(9,11,iw);
t=GET_X_BIT();
sr &= ~MASK_CC | MASK_CC_Z; /* FIXME? */
s=LDREG_WORD(UBITS(0,2,iw));
x=LDREG_WORD(n);
r=x-s-t;
SET_VCX_SUB;
if (r) SET_NZ(r);
else UNSET_N();
SDREG_WORD(n,r);
THREAD
; }
GENFUNC_PROTO(Func1343){ 
WORD s,x,r,t;
int n=UBITS(9,11,iw);
t=GET_X_BIT();
sr &= ~MASK_CC | MASK_CC_Z;

s=CL_WORD(V_AN_PD_WORD(UBITS(0,2,iw)));;
{UL v_x=V_AN_PD_WORD(n); x=CL_WORD(v_x);;
r=x-s-t;
SET_VCX_SUB;
UNSET_Z();
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1344){ 
WORD s,r,x;
s=LDREG_WORD(UBITS(9,11,iw));
{UL v_x=V_AN_I_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1345){ 
WORD s,r,x;
s=LDREG_WORD(UBITS(9,11,iw));
{UL v_x=V_AN_PI_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1346){ 
WORD s,r,x;
s=LDREG_WORD(UBITS(9,11,iw));
{UL v_x=V_AN_PD_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1347){ 
WORD s,r,x;
s=LDREG_WORD(UBITS(9,11,iw));
{UL v_x=V_AN_D_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1348){ 
WORD s,r,x;
s=LDREG_WORD(UBITS(9,11,iw));
{UL v_x=V_AN_R_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1349){ 
WORD s,r,x;
s=LDREG_WORD(UBITS(9,11,iw));
{UL v_x=V_ABS_W_WORD(); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1350){ 
WORD s,r,x;
s=LDREG_WORD(UBITS(9,11,iw));
{UL v_x=V_ABS_L_WORD(); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1351){ 
LONG s,x,r,t;
int n=UBITS(9,11,iw);
t=GET_X_BIT();
sr &= ~MASK_CC | MASK_CC_Z; /* FIXME? */
s=LDREG_LONG(UBITS(0,2,iw));
x=LDREG_LONG(n);
r=x-s-t;
SET_VCX_SUB;
if (r) SET_NZ(r);
else UNSET_N();
SDREG_LONG(n,r);
THREAD
; }
GENFUNC_PROTO(Func1352){ 
LONG s,x,r,t;
int n=UBITS(9,11,iw);
t=GET_X_BIT();
sr &= ~MASK_CC | MASK_CC_Z;

s=CL_LONG(V_AN_PD_LONG(UBITS(0,2,iw)));;
{UL v_x=V_AN_PD_LONG(n); x=CL_LONG(v_x);;
r=x-s-t;
SET_VCX_SUB;
UNSET_Z();
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1353){ 
LONG s,r,x;
s=LDREG_LONG(UBITS(9,11,iw));
{UL v_x=V_AN_I_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1354){ 
LONG s,r,x;
s=LDREG_LONG(UBITS(9,11,iw));
{UL v_x=V_AN_PI_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1355){ 
LONG s,r,x;
s=LDREG_LONG(UBITS(9,11,iw));
{UL v_x=V_AN_PD_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1356){ 
LONG s,r,x;
s=LDREG_LONG(UBITS(9,11,iw));
{UL v_x=V_AN_D_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1357){ 
LONG s,r,x;
s=LDREG_LONG(UBITS(9,11,iw));
{UL v_x=V_AN_R_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1358){ 
LONG s,r,x;
s=LDREG_LONG(UBITS(9,11,iw));
{UL v_x=V_ABS_W_LONG(); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1359){ 
LONG s,r,x;
s=LDREG_LONG(UBITS(9,11,iw));
{UL v_x=V_ABS_L_LONG(); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = x - s;
SET_VCX_SUB;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1360){ 
LONG x;
x=LDREG_LONG((UBITS(0,5,iw)&7));;
AREG(UBITS(9,11,iw)) -= x;
THREAD
; }
GENFUNC_PROTO(Func1361){ 
LONG x;
x=LDREG_LONG((UBITS(0,5,iw)&7)+8);;
AREG(UBITS(9,11,iw)) -= x;
THREAD
; }
GENFUNC_PROTO(Func1362){ 
LONG x;
x=CL_LONG(V_AN_I_LONG((UBITS(0,5,iw)&7)));;
AREG(UBITS(9,11,iw)) -= x;
THREAD
; }
GENFUNC_PROTO(Func1363){ 
LONG x;
x=CL_LONG(V_AN_PI_LONG((UBITS(0,5,iw)&7)));;
AREG(UBITS(9,11,iw)) -= x;
THREAD
; }
GENFUNC_PROTO(Func1364){ 
LONG x;
x=CL_LONG(V_AN_PD_LONG((UBITS(0,5,iw)&7)));;
AREG(UBITS(9,11,iw)) -= x;
THREAD
; }
GENFUNC_PROTO(Func1365){ 
LONG x;
x=CL_LONG(V_AN_D_LONG((UBITS(0,5,iw)&7)));;
AREG(UBITS(9,11,iw)) -= x;
THREAD
; }
GENFUNC_PROTO(Func1366){ 
LONG x;
x=CL_LONG(V_AN_R_LONG((UBITS(0,5,iw)&7)));;
AREG(UBITS(9,11,iw)) -= x;
THREAD
; }
GENFUNC_PROTO(Func1367){ 
LONG x;
x=CL_LONG(V_ABS_W_LONG());;
AREG(UBITS(9,11,iw)) -= x;
THREAD
; }
GENFUNC_PROTO(Func1368){ 
LONG x;
x=CL_LONG(V_ABS_L_LONG());;
AREG(UBITS(9,11,iw)) -= x;
THREAD
; }
GENFUNC_PROTO(Func1369){ 
LONG x;
x=CL_LONG(V_PC_D_LONG());;
AREG(UBITS(9,11,iw)) -= x;
THREAD
; }
GENFUNC_PROTO(Func1370){ 
LONG x;
x=CL_LONG(V_PC_R_LONG());;
AREG(UBITS(9,11,iw)) -= x;
THREAD
; }
GENFUNC_PROTO(Func1371){ 
LONG x;
x=LM_LONG(MEM(V_IMM_LONG()));;
AREG(UBITS(9,11,iw)) -= x;
THREAD
; }
GENFUNC_PROTO(Func1372){ 
pc -= 2; ex_linea();
THREAD
; }
GENFUNC_PROTO(Func1373){ 
ULONG f=GET_SI32;
call_native(SP+4,f);
THREAD
; }
GENFUNC_PROTO(Func1374){ 
BYTE xx,yy;
xx=LDREG_BYTE((UBITS(0,5,iw)&7));;
yy=LDREG_BYTE(UBITS(9,11,iw));

{
BYTE r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1375){ 
BYTE xx,yy;
xx=CL_BYTE(V_AN_I_BYTE((UBITS(0,5,iw)&7)));;
yy=LDREG_BYTE(UBITS(9,11,iw));

{
BYTE r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1376){ 
BYTE xx,yy;
xx=CL_BYTE(V_AN_PI_BYTE((UBITS(0,5,iw)&7)));;
yy=LDREG_BYTE(UBITS(9,11,iw));

{
BYTE r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1377){ 
BYTE xx,yy;
xx=CL_BYTE(V_AN_PI_BYTE_All(7));;
yy=LDREG_BYTE(UBITS(9,11,iw));

{
BYTE r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1378){ 
BYTE xx,yy;
xx=CL_BYTE(V_AN_PD_BYTE((UBITS(0,5,iw)&7)));;
yy=LDREG_BYTE(UBITS(9,11,iw));

{
BYTE r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1379){ 
BYTE xx,yy;
xx=CL_BYTE(V_AN_PD_BYTE_All(7));;
yy=LDREG_BYTE(UBITS(9,11,iw));

{
BYTE r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1380){ 
BYTE xx,yy;
xx=CL_BYTE(V_AN_D_BYTE((UBITS(0,5,iw)&7)));;
yy=LDREG_BYTE(UBITS(9,11,iw));

{
BYTE r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1381){ 
BYTE xx,yy;
xx=CL_BYTE(V_AN_R_BYTE((UBITS(0,5,iw)&7)));;
yy=LDREG_BYTE(UBITS(9,11,iw));

{
BYTE r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1382){ 
BYTE xx,yy;
xx=CL_BYTE(V_ABS_W_BYTE());;
yy=LDREG_BYTE(UBITS(9,11,iw));

{
BYTE r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1383){ 
BYTE xx,yy;
xx=CL_BYTE(V_ABS_L_BYTE());;
yy=LDREG_BYTE(UBITS(9,11,iw));

{
BYTE r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1384){ 
BYTE xx,yy;
xx=CL_BYTE(V_PC_D_BYTE());;
yy=LDREG_BYTE(UBITS(9,11,iw));

{
BYTE r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1385){ 
BYTE xx,yy;
xx=CL_BYTE(V_PC_R_BYTE());;
yy=LDREG_BYTE(UBITS(9,11,iw));

{
BYTE r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1386){ 
BYTE xx,yy;
xx=LM_BYTE(MEM(V_IMM_BYTE()));;
yy=LDREG_BYTE(UBITS(9,11,iw));

{
BYTE r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1387){ 
WORD xx,yy;
xx=LDREG_WORD((UBITS(0,5,iw)&7));;
yy=LDREG_WORD(UBITS(9,11,iw));

{
WORD r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1388){ 
WORD xx,yy;
xx=LDREG_WORD((UBITS(0,5,iw)&7)+8);;
yy=LDREG_WORD(UBITS(9,11,iw));

{
WORD r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1389){ 
WORD xx,yy;
xx=CL_WORD(V_AN_I_WORD((UBITS(0,5,iw)&7)));;
yy=LDREG_WORD(UBITS(9,11,iw));

{
WORD r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1390){ 
WORD xx,yy;
xx=CL_WORD(V_AN_PI_WORD((UBITS(0,5,iw)&7)));;
yy=LDREG_WORD(UBITS(9,11,iw));

{
WORD r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1391){ 
WORD xx,yy;
xx=CL_WORD(V_AN_PD_WORD((UBITS(0,5,iw)&7)));;
yy=LDREG_WORD(UBITS(9,11,iw));

{
WORD r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1392){ 
WORD xx,yy;
xx=CL_WORD(V_AN_D_WORD((UBITS(0,5,iw)&7)));;
yy=LDREG_WORD(UBITS(9,11,iw));

{
WORD r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1393){ 
WORD xx,yy;
xx=CL_WORD(V_AN_R_WORD((UBITS(0,5,iw)&7)));;
yy=LDREG_WORD(UBITS(9,11,iw));

{
WORD r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1394){ 
WORD xx,yy;
xx=CL_WORD(V_ABS_W_WORD());;
yy=LDREG_WORD(UBITS(9,11,iw));

{
WORD r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1395){ 
WORD xx,yy;
xx=CL_WORD(V_ABS_L_WORD());;
yy=LDREG_WORD(UBITS(9,11,iw));

{
WORD r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1396){ 
WORD xx,yy;
xx=CL_WORD(V_PC_D_WORD());;
yy=LDREG_WORD(UBITS(9,11,iw));

{
WORD r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1397){ 
WORD xx,yy;
xx=CL_WORD(V_PC_R_WORD());;
yy=LDREG_WORD(UBITS(9,11,iw));

{
WORD r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1398){ 
WORD xx,yy;
xx=LM_WORD(MEM(V_IMM_WORD()));;
yy=LDREG_WORD(UBITS(9,11,iw));

{
WORD r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1399){ 
LONG xx,yy;
xx=LDREG_LONG((UBITS(0,5,iw)&7));;
yy=LDREG_LONG(UBITS(9,11,iw));

{
LONG r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1400){ 
LONG xx,yy;
xx=LDREG_LONG((UBITS(0,5,iw)&7)+8);;
yy=LDREG_LONG(UBITS(9,11,iw));

{
LONG r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1401){ 
LONG xx,yy;
xx=CL_LONG(V_AN_I_LONG((UBITS(0,5,iw)&7)));;
yy=LDREG_LONG(UBITS(9,11,iw));

{
LONG r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1402){ 
LONG xx,yy;
xx=CL_LONG(V_AN_PI_LONG((UBITS(0,5,iw)&7)));;
yy=LDREG_LONG(UBITS(9,11,iw));

{
LONG r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1403){ 
LONG xx,yy;
xx=CL_LONG(V_AN_PD_LONG((UBITS(0,5,iw)&7)));;
yy=LDREG_LONG(UBITS(9,11,iw));

{
LONG r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1404){ 
LONG xx,yy;
xx=CL_LONG(V_AN_D_LONG((UBITS(0,5,iw)&7)));;
yy=LDREG_LONG(UBITS(9,11,iw));

{
LONG r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1405){ 
LONG xx,yy;
xx=CL_LONG(V_AN_R_LONG((UBITS(0,5,iw)&7)));;
yy=LDREG_LONG(UBITS(9,11,iw));

{
LONG r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1406){ 
LONG xx,yy;
xx=CL_LONG(V_ABS_W_LONG());;
yy=LDREG_LONG(UBITS(9,11,iw));

{
LONG r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1407){ 
LONG xx,yy;
xx=CL_LONG(V_ABS_L_LONG());;
yy=LDREG_LONG(UBITS(9,11,iw));

{
LONG r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1408){ 
LONG xx,yy;
xx=CL_LONG(V_PC_D_LONG());;
yy=LDREG_LONG(UBITS(9,11,iw));

{
LONG r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1409){ 
LONG xx,yy;
xx=CL_LONG(V_PC_R_LONG());;
yy=LDREG_LONG(UBITS(9,11,iw));

{
LONG r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1410){ 
LONG xx,yy;
xx=LM_LONG(MEM(V_IMM_LONG()));;
yy=LDREG_LONG(UBITS(9,11,iw));

{
LONG r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1411){ 
LONG xx,yy;
xx=LDREG_WORD((UBITS(0,5,iw)&7));;
yy=AREG(UBITS(9,11,iw));

{
LONG r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1412){ 
LONG xx,yy;
xx=LDREG_WORD((UBITS(0,5,iw)&7)+8);;
yy=AREG(UBITS(9,11,iw));

{
LONG r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1413){ 
LONG xx,yy;
xx=CL_WORD(V_AN_I_WORD((UBITS(0,5,iw)&7)));;
yy=AREG(UBITS(9,11,iw));

{
LONG r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1414){ 
LONG xx,yy;
xx=CL_WORD(V_AN_PI_WORD((UBITS(0,5,iw)&7)));;
yy=AREG(UBITS(9,11,iw));

{
LONG r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1415){ 
LONG xx,yy;
xx=CL_WORD(V_AN_PD_WORD((UBITS(0,5,iw)&7)));;
yy=AREG(UBITS(9,11,iw));

{
LONG r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1416){ 
LONG xx,yy;
xx=CL_WORD(V_AN_D_WORD((UBITS(0,5,iw)&7)));;
yy=AREG(UBITS(9,11,iw));

{
LONG r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1417){ 
LONG xx,yy;
xx=CL_WORD(V_AN_R_WORD((UBITS(0,5,iw)&7)));;
yy=AREG(UBITS(9,11,iw));

{
LONG r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1418){ 
LONG xx,yy;
xx=CL_WORD(V_ABS_W_WORD());;
yy=AREG(UBITS(9,11,iw));

{
LONG r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1419){ 
LONG xx,yy;
xx=CL_WORD(V_ABS_L_WORD());;
yy=AREG(UBITS(9,11,iw));

{
LONG r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1420){ 
LONG xx,yy;
xx=CL_WORD(V_PC_D_WORD());;
yy=AREG(UBITS(9,11,iw));

{
LONG r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1421){ 
LONG xx,yy;
xx=CL_WORD(V_PC_R_WORD());;
yy=AREG(UBITS(9,11,iw));

{
LONG r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1422){ 
LONG xx,yy;
xx=LM_WORD(MEM(V_IMM_WORD()));;
yy=AREG(UBITS(9,11,iw));

{
LONG r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1423){ 
BYTE r,x,s;
s=LDREG_BYTE(UBITS(9,11,iw));
{B *v_x=DREG_BYTE((UBITS(0,5,iw)&7)); x=LR_BYTE(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s^x;
SET_NZ(r);
x=r;
SR_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1424){ 
BYTE a,b;

a=CL_BYTE(V_AN_PI_BYTE_All(UBITS(0,2,iw)));;
b=CL_BYTE(V_AN_PI_BYTE_All(UBITS(9,11,iw)));;


{
BYTE r,s,x;
s=a; x=b;
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
GENFUNC_PROTO(Func1425){ 
BYTE r,x,s;
s=LDREG_BYTE(UBITS(9,11,iw));
{UL v_x=V_AN_I_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s^x;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1426){ 
BYTE r,x,s;
s=LDREG_BYTE(UBITS(9,11,iw));
{UL v_x=V_AN_PI_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s^x;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1427){ 
BYTE r,x,s;
s=LDREG_BYTE(UBITS(9,11,iw));
{UL v_x=V_AN_PI_BYTE_All(7); x=CL_BYTE(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s^x;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1428){ 
BYTE r,x,s;
s=LDREG_BYTE(UBITS(9,11,iw));
{UL v_x=V_AN_PD_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s^x;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1429){ 
BYTE r,x,s;
s=LDREG_BYTE(UBITS(9,11,iw));
{UL v_x=V_AN_PD_BYTE_All(7); x=CL_BYTE(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s^x;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1430){ 
BYTE r,x,s;
s=LDREG_BYTE(UBITS(9,11,iw));
{UL v_x=V_AN_D_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s^x;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1431){ 
BYTE r,x,s;
s=LDREG_BYTE(UBITS(9,11,iw));
{UL v_x=V_AN_R_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s^x;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1432){ 
BYTE r,x,s;
s=LDREG_BYTE(UBITS(9,11,iw));
{UL v_x=V_ABS_W_BYTE(); x=CL_BYTE(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s^x;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1433){ 
BYTE r,x,s;
s=LDREG_BYTE(UBITS(9,11,iw));
{UL v_x=V_ABS_L_BYTE(); x=CL_BYTE(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s^x;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1434){ 
WORD r,x,s;
s=LDREG_WORD(UBITS(9,11,iw));
{W *v_x=DREG_WORD((UBITS(0,5,iw)&7)); x=LR_WORD(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s^x;
SET_NZ(r);
x=r;
SR_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1435){ 
WORD a,b;

a=CL_WORD(V_AN_PI_WORD(UBITS(0,2,iw)));;
b=CL_WORD(V_AN_PI_WORD(UBITS(9,11,iw)));;


{
WORD r,s,x;
s=a; x=b;
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
GENFUNC_PROTO(Func1436){ 
WORD r,x,s;
s=LDREG_WORD(UBITS(9,11,iw));
{UL v_x=V_AN_I_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s^x;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1437){ 
WORD r,x,s;
s=LDREG_WORD(UBITS(9,11,iw));
{UL v_x=V_AN_PI_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s^x;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1438){ 
WORD r,x,s;
s=LDREG_WORD(UBITS(9,11,iw));
{UL v_x=V_AN_PD_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s^x;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1439){ 
WORD r,x,s;
s=LDREG_WORD(UBITS(9,11,iw));
{UL v_x=V_AN_D_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s^x;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1440){ 
WORD r,x,s;
s=LDREG_WORD(UBITS(9,11,iw));
{UL v_x=V_AN_R_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s^x;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1441){ 
WORD r,x,s;
s=LDREG_WORD(UBITS(9,11,iw));
{UL v_x=V_ABS_W_WORD(); x=CL_WORD(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s^x;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1442){ 
WORD r,x,s;
s=LDREG_WORD(UBITS(9,11,iw));
{UL v_x=V_ABS_L_WORD(); x=CL_WORD(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s^x;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1443){ 
LONG r,x,s;
s=LDREG_LONG(UBITS(9,11,iw));
{L *v_x=DREG_LONG((UBITS(0,5,iw)&7)); x=LR_LONG(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s^x;
SET_NZ(r);
x=r;
SR_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1444){ 
LONG a,b;

a=CL_LONG(V_AN_PI_LONG(UBITS(0,2,iw)));;
b=CL_LONG(V_AN_PI_LONG(UBITS(9,11,iw)));;


{
LONG r,s,x;
s=a; x=b;
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
GENFUNC_PROTO(Func1445){ 
LONG r,x,s;
s=LDREG_LONG(UBITS(9,11,iw));
{UL v_x=V_AN_I_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s^x;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1446){ 
LONG r,x,s;
s=LDREG_LONG(UBITS(9,11,iw));
{UL v_x=V_AN_PI_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s^x;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1447){ 
LONG r,x,s;
s=LDREG_LONG(UBITS(9,11,iw));
{UL v_x=V_AN_PD_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s^x;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1448){ 
LONG r,x,s;
s=LDREG_LONG(UBITS(9,11,iw));
{UL v_x=V_AN_D_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s^x;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1449){ 
LONG r,x,s;
s=LDREG_LONG(UBITS(9,11,iw));
{UL v_x=V_AN_R_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s^x;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1450){ 
LONG r,x,s;
s=LDREG_LONG(UBITS(9,11,iw));
{UL v_x=V_ABS_W_LONG(); x=CL_LONG(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s^x;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1451){ 
LONG r,x,s;
s=LDREG_LONG(UBITS(9,11,iw));
{UL v_x=V_ABS_L_LONG(); x=CL_LONG(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s^x;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1452){ 
LONG xx,yy;
xx=LDREG_LONG((UBITS(0,5,iw)&7));;
yy=AREG(UBITS(9,11,iw));

{
LONG r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1453){ 
LONG xx,yy;
xx=LDREG_LONG((UBITS(0,5,iw)&7)+8);;
yy=AREG(UBITS(9,11,iw));

{
LONG r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1454){ 
LONG xx,yy;
xx=CL_LONG(V_AN_I_LONG((UBITS(0,5,iw)&7)));;
yy=AREG(UBITS(9,11,iw));

{
LONG r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1455){ 
LONG xx,yy;
xx=CL_LONG(V_AN_PI_LONG((UBITS(0,5,iw)&7)));;
yy=AREG(UBITS(9,11,iw));

{
LONG r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1456){ 
LONG xx,yy;
xx=CL_LONG(V_AN_PD_LONG((UBITS(0,5,iw)&7)));;
yy=AREG(UBITS(9,11,iw));

{
LONG r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1457){ 
LONG xx,yy;
xx=CL_LONG(V_AN_D_LONG((UBITS(0,5,iw)&7)));;
yy=AREG(UBITS(9,11,iw));

{
LONG r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1458){ 
LONG xx,yy;
xx=CL_LONG(V_AN_R_LONG((UBITS(0,5,iw)&7)));;
yy=AREG(UBITS(9,11,iw));

{
LONG r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1459){ 
LONG xx,yy;
xx=CL_LONG(V_ABS_W_LONG());;
yy=AREG(UBITS(9,11,iw));

{
LONG r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1460){ 
LONG xx,yy;
xx=CL_LONG(V_ABS_L_LONG());;
yy=AREG(UBITS(9,11,iw));

{
LONG r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1461){ 
LONG xx,yy;
xx=CL_LONG(V_PC_D_LONG());;
yy=AREG(UBITS(9,11,iw));

{
LONG r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1462){ 
LONG xx,yy;
xx=CL_LONG(V_PC_R_LONG());;
yy=AREG(UBITS(9,11,iw));

{
LONG r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1463){ 
LONG xx,yy;
xx=LM_LONG(MEM(V_IMM_LONG()));;
yy=AREG(UBITS(9,11,iw));

{
LONG r,s,x;
s=xx; x=yy;
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
GENFUNC_PROTO(Func1464){ 
BYTE r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=LDREG_BYTE((UBITS(0,5,iw)&7));;
x=LDREG_BYTE(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
SDREG_BYTE(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1465){ 
BYTE r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_BYTE(V_AN_I_BYTE((UBITS(0,5,iw)&7)));;
x=LDREG_BYTE(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
SDREG_BYTE(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1466){ 
BYTE r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_BYTE(V_AN_PI_BYTE((UBITS(0,5,iw)&7)));;
x=LDREG_BYTE(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
SDREG_BYTE(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1467){ 
BYTE r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_BYTE(V_AN_PI_BYTE_All(7));;
x=LDREG_BYTE(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
SDREG_BYTE(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1468){ 
BYTE r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_BYTE(V_AN_PD_BYTE((UBITS(0,5,iw)&7)));;
x=LDREG_BYTE(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
SDREG_BYTE(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1469){ 
BYTE r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_BYTE(V_AN_PD_BYTE_All(7));;
x=LDREG_BYTE(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
SDREG_BYTE(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1470){ 
BYTE r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_BYTE(V_AN_D_BYTE((UBITS(0,5,iw)&7)));;
x=LDREG_BYTE(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
SDREG_BYTE(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1471){ 
BYTE r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_BYTE(V_AN_R_BYTE((UBITS(0,5,iw)&7)));;
x=LDREG_BYTE(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
SDREG_BYTE(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1472){ 
BYTE r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_BYTE(V_ABS_W_BYTE());;
x=LDREG_BYTE(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
SDREG_BYTE(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1473){ 
BYTE r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_BYTE(V_ABS_L_BYTE());;
x=LDREG_BYTE(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
SDREG_BYTE(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1474){ 
BYTE r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_BYTE(V_PC_D_BYTE());;
x=LDREG_BYTE(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
SDREG_BYTE(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1475){ 
BYTE r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_BYTE(V_PC_R_BYTE());;
x=LDREG_BYTE(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
SDREG_BYTE(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1476){ 
BYTE r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=LM_BYTE(MEM(V_IMM_BYTE()));;
x=LDREG_BYTE(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
SDREG_BYTE(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1477){ 
WORD r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=LDREG_WORD((UBITS(0,5,iw)&7));;
x=LDREG_WORD(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
SDREG_WORD(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1478){ 
WORD r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_WORD(V_AN_I_WORD((UBITS(0,5,iw)&7)));;
x=LDREG_WORD(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
SDREG_WORD(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1479){ 
WORD r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_WORD(V_AN_PI_WORD((UBITS(0,5,iw)&7)));;
x=LDREG_WORD(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
SDREG_WORD(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1480){ 
WORD r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_WORD(V_AN_PD_WORD((UBITS(0,5,iw)&7)));;
x=LDREG_WORD(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
SDREG_WORD(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1481){ 
WORD r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_WORD(V_AN_D_WORD((UBITS(0,5,iw)&7)));;
x=LDREG_WORD(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
SDREG_WORD(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1482){ 
WORD r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_WORD(V_AN_R_WORD((UBITS(0,5,iw)&7)));;
x=LDREG_WORD(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
SDREG_WORD(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1483){ 
WORD r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_WORD(V_ABS_W_WORD());;
x=LDREG_WORD(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
SDREG_WORD(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1484){ 
WORD r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_WORD(V_ABS_L_WORD());;
x=LDREG_WORD(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
SDREG_WORD(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1485){ 
WORD r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_WORD(V_PC_D_WORD());;
x=LDREG_WORD(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
SDREG_WORD(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1486){ 
WORD r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_WORD(V_PC_R_WORD());;
x=LDREG_WORD(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
SDREG_WORD(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1487){ 
WORD r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=LM_WORD(MEM(V_IMM_WORD()));;
x=LDREG_WORD(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
SDREG_WORD(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1488){ 
LONG r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=LDREG_LONG((UBITS(0,5,iw)&7));;
x=LDREG_LONG(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
SDREG_LONG(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1489){ 
LONG r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_LONG(V_AN_I_LONG((UBITS(0,5,iw)&7)));;
x=LDREG_LONG(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
SDREG_LONG(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1490){ 
LONG r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_LONG(V_AN_PI_LONG((UBITS(0,5,iw)&7)));;
x=LDREG_LONG(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
SDREG_LONG(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1491){ 
LONG r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_LONG(V_AN_PD_LONG((UBITS(0,5,iw)&7)));;
x=LDREG_LONG(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
SDREG_LONG(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1492){ 
LONG r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_LONG(V_AN_D_LONG((UBITS(0,5,iw)&7)));;
x=LDREG_LONG(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
SDREG_LONG(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1493){ 
LONG r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_LONG(V_AN_R_LONG((UBITS(0,5,iw)&7)));;
x=LDREG_LONG(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
SDREG_LONG(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1494){ 
LONG r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_LONG(V_ABS_W_LONG());;
x=LDREG_LONG(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
SDREG_LONG(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1495){ 
LONG r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_LONG(V_ABS_L_LONG());;
x=LDREG_LONG(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
SDREG_LONG(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1496){ 
LONG r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_LONG(V_PC_D_LONG());;
x=LDREG_LONG(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
SDREG_LONG(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1497){ 
LONG r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=CL_LONG(V_PC_R_LONG());;
x=LDREG_LONG(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
SDREG_LONG(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1498){ 
LONG r,x,s;
int reg;
reg=UBITS(9,11,iw);
s=LM_LONG(MEM(V_IMM_LONG()));;
x=LDREG_LONG(reg);
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
SDREG_LONG(reg,r);
THREAD
; }
GENFUNC_PROTO(Func1499){ 
UWORD d,m;
ULONG r;
int n=UBITS(9,11,iw);
d=LDREG_WORD((UBITS(0,5,iw)&7));;
m=LDREG_UWORD(n);
sr &= ~MASK_CC|MASK_CC_X;
r = d * m;
SET_NZ((LONG)r);
DREG(n) = (LONG)r;
THREAD
; }
