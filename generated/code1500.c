

#include "defs.h"
#include "cpu.h"
#include "gendefs.h"
#include "mem.h"
#include "native.h"
#include "nf.h"
























































































































































































































































































































































































































































GENFUNC_PROTO(Func1500){ 
UWORD d,m;
ULONG r;
int n=UBITS(9,11,iw);
d=CL_WORD(V_AN_I_WORD((UBITS(0,5,iw)&7)));;
m=LDREG_UWORD(n);
sr &= ~MASK_CC|MASK_CC_X;
r = d * m;
SET_NZ((LONG)r);
DREG(n) = (LONG)r;
THREAD
; }
GENFUNC_PROTO(Func1501){ 
UWORD d,m;
ULONG r;
int n=UBITS(9,11,iw);
d=CL_WORD(V_AN_PI_WORD((UBITS(0,5,iw)&7)));;
m=LDREG_UWORD(n);
sr &= ~MASK_CC|MASK_CC_X;
r = d * m;
SET_NZ((LONG)r);
DREG(n) = (LONG)r;
THREAD
; }
GENFUNC_PROTO(Func1502){ 
UWORD d,m;
ULONG r;
int n=UBITS(9,11,iw);
d=CL_WORD(V_AN_PD_WORD((UBITS(0,5,iw)&7)));;
m=LDREG_UWORD(n);
sr &= ~MASK_CC|MASK_CC_X;
r = d * m;
SET_NZ((LONG)r);
DREG(n) = (LONG)r;
THREAD
; }
GENFUNC_PROTO(Func1503){ 
UWORD d,m;
ULONG r;
int n=UBITS(9,11,iw);
d=CL_WORD(V_AN_D_WORD((UBITS(0,5,iw)&7)));;
m=LDREG_UWORD(n);
sr &= ~MASK_CC|MASK_CC_X;
r = d * m;
SET_NZ((LONG)r);
DREG(n) = (LONG)r;
THREAD
; }
GENFUNC_PROTO(Func1504){ 
UWORD d,m;
ULONG r;
int n=UBITS(9,11,iw);
d=CL_WORD(V_AN_R_WORD((UBITS(0,5,iw)&7)));;
m=LDREG_UWORD(n);
sr &= ~MASK_CC|MASK_CC_X;
r = d * m;
SET_NZ((LONG)r);
DREG(n) = (LONG)r;
THREAD
; }
GENFUNC_PROTO(Func1505){ 
UWORD d,m;
ULONG r;
int n=UBITS(9,11,iw);
d=CL_WORD(V_ABS_W_WORD());;
m=LDREG_UWORD(n);
sr &= ~MASK_CC|MASK_CC_X;
r = d * m;
SET_NZ((LONG)r);
DREG(n) = (LONG)r;
THREAD
; }
GENFUNC_PROTO(Func1506){ 
UWORD d,m;
ULONG r;
int n=UBITS(9,11,iw);
d=CL_WORD(V_ABS_L_WORD());;
m=LDREG_UWORD(n);
sr &= ~MASK_CC|MASK_CC_X;
r = d * m;
SET_NZ((LONG)r);
DREG(n) = (LONG)r;
THREAD
; }
GENFUNC_PROTO(Func1507){ 
UWORD d,m;
ULONG r;
int n=UBITS(9,11,iw);
d=CL_WORD(V_PC_D_WORD());;
m=LDREG_UWORD(n);
sr &= ~MASK_CC|MASK_CC_X;
r = d * m;
SET_NZ((LONG)r);
DREG(n) = (LONG)r;
THREAD
; }
GENFUNC_PROTO(Func1508){ 
UWORD d,m;
ULONG r;
int n=UBITS(9,11,iw);
d=CL_WORD(V_PC_R_WORD());;
m=LDREG_UWORD(n);
sr &= ~MASK_CC|MASK_CC_X;
r = d * m;
SET_NZ((LONG)r);
DREG(n) = (LONG)r;
THREAD
; }
GENFUNC_PROTO(Func1509){ 
UWORD d,m;
ULONG r;
int n=UBITS(9,11,iw);
d=LM_WORD(MEM(V_IMM_WORD()));;
m=LDREG_UWORD(n);
sr &= ~MASK_CC|MASK_CC_X;
r = d * m;
SET_NZ((LONG)r);
DREG(n) = (LONG)r;
THREAD
; }
GENFUNC_PROTO(Func1510){ 
BYTE s,x,*d;
s = LDREG_BYTE(UBITS(0,2,iw));
d = DREG_B(UBITS(9,11,iw));
x = BCD_ADD(s,LR_B(d));
SR_B(d,x);
THREAD
; }
GENFUNC_PROTO(Func1511){ 
BYTE s,x;
UL d;
s = CL_B(V_AN_PD_BYTE_All(UBITS(0,2,iw)));
d = V_AN_PD_BYTE_All(UBITS(9,11,iw));
x = BCD_ADD(s,CL_B(d));
CS_B(d,x);
THREAD
; }
GENFUNC_PROTO(Func1512){ 
BYTE r,x,s;
s=LDREG_BYTE(UBITS(9,11,iw));
{UL v_x=V_AN_I_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1513){ 
BYTE r,x,s;
s=LDREG_BYTE(UBITS(9,11,iw));
{UL v_x=V_AN_PI_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1514){ 
BYTE r,x,s;
s=LDREG_BYTE(UBITS(9,11,iw));
{UL v_x=V_AN_PI_BYTE_All(7); x=CL_BYTE(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1515){ 
BYTE r,x,s;
s=LDREG_BYTE(UBITS(9,11,iw));
{UL v_x=V_AN_PD_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1516){ 
BYTE r,x,s;
s=LDREG_BYTE(UBITS(9,11,iw));
{UL v_x=V_AN_PD_BYTE_All(7); x=CL_BYTE(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1517){ 
BYTE r,x,s;
s=LDREG_BYTE(UBITS(9,11,iw));
{UL v_x=V_AN_D_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1518){ 
BYTE r,x,s;
s=LDREG_BYTE(UBITS(9,11,iw));
{UL v_x=V_AN_R_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1519){ 
BYTE r,x,s;
s=LDREG_BYTE(UBITS(9,11,iw));
{UL v_x=V_ABS_W_BYTE(); x=CL_BYTE(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1520){ 
BYTE r,x,s;
s=LDREG_BYTE(UBITS(9,11,iw));
{UL v_x=V_ABS_L_BYTE(); x=CL_BYTE(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1521){ 
L t;
t=DREG(UBITS(9,11,iw));
DREG(UBITS(9,11,iw))=DREG(UBITS(0,2,iw));
DREG(UBITS(0,2,iw))=t;
THREAD
; }
GENFUNC_PROTO(Func1522){ 
L t;
t=AREG(UBITS(9,11,iw));
AREG(UBITS(9,11,iw))=AREG(UBITS(0,2,iw));
AREG(UBITS(0,2,iw))=t;
THREAD
; }
GENFUNC_PROTO(Func1523){ 
WORD r,x,s;
s=LDREG_WORD(UBITS(9,11,iw));
{UL v_x=V_AN_I_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1524){ 
WORD r,x,s;
s=LDREG_WORD(UBITS(9,11,iw));
{UL v_x=V_AN_PI_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1525){ 
WORD r,x,s;
s=LDREG_WORD(UBITS(9,11,iw));
{UL v_x=V_AN_PD_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1526){ 
WORD r,x,s;
s=LDREG_WORD(UBITS(9,11,iw));
{UL v_x=V_AN_D_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1527){ 
WORD r,x,s;
s=LDREG_WORD(UBITS(9,11,iw));
{UL v_x=V_AN_R_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1528){ 
WORD r,x,s;
s=LDREG_WORD(UBITS(9,11,iw));
{UL v_x=V_ABS_W_WORD(); x=CL_WORD(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1529){ 
WORD r,x,s;
s=LDREG_WORD(UBITS(9,11,iw));
{UL v_x=V_ABS_L_WORD(); x=CL_WORD(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1530){ 
L t;
t=DREG(UBITS(9,11,iw));
DREG(UBITS(9,11,iw))=AREG(UBITS(0,2,iw));
AREG(UBITS(0,2,iw))=t;
THREAD
; }
GENFUNC_PROTO(Func1531){ 
LONG r,x,s;
s=LDREG_LONG(UBITS(9,11,iw));
{UL v_x=V_AN_I_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1532){ 
LONG r,x,s;
s=LDREG_LONG(UBITS(9,11,iw));
{UL v_x=V_AN_PI_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1533){ 
LONG r,x,s;
s=LDREG_LONG(UBITS(9,11,iw));
{UL v_x=V_AN_PD_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1534){ 
LONG r,x,s;
s=LDREG_LONG(UBITS(9,11,iw));
{UL v_x=V_AN_D_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1535){ 
LONG r,x,s;
s=LDREG_LONG(UBITS(9,11,iw));
{UL v_x=V_AN_R_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1536){ 
LONG r,x,s;
s=LDREG_LONG(UBITS(9,11,iw));
{UL v_x=V_ABS_W_LONG(); x=CL_LONG(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1537){ 
LONG r,x,s;
s=LDREG_LONG(UBITS(9,11,iw));
{UL v_x=V_ABS_L_LONG(); x=CL_LONG(v_x);;
sr &= ~MASK_CC|MASK_CC_X;
r = s & x;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1538){ 
WORD d,m;
LONG r;
int n=UBITS(9,11,iw);
d=LDREG_WORD((UBITS(0,5,iw)&7));;
m=LDREG_WORD(n);
sr &= ~MASK_CC|MASK_CC_X;
r = d * m;
SET_NZ(r);
DREG(n) = r;
THREAD
; }
GENFUNC_PROTO(Func1539){ 
WORD d,m;
LONG r;
int n=UBITS(9,11,iw);
d=CL_WORD(V_AN_I_WORD((UBITS(0,5,iw)&7)));;
m=LDREG_WORD(n);
sr &= ~MASK_CC|MASK_CC_X;
r = d * m;
SET_NZ(r);
DREG(n) = r;
THREAD
; }
GENFUNC_PROTO(Func1540){ 
WORD d,m;
LONG r;
int n=UBITS(9,11,iw);
d=CL_WORD(V_AN_PI_WORD((UBITS(0,5,iw)&7)));;
m=LDREG_WORD(n);
sr &= ~MASK_CC|MASK_CC_X;
r = d * m;
SET_NZ(r);
DREG(n) = r;
THREAD
; }
GENFUNC_PROTO(Func1541){ 
WORD d,m;
LONG r;
int n=UBITS(9,11,iw);
d=CL_WORD(V_AN_PD_WORD((UBITS(0,5,iw)&7)));;
m=LDREG_WORD(n);
sr &= ~MASK_CC|MASK_CC_X;
r = d * m;
SET_NZ(r);
DREG(n) = r;
THREAD
; }
GENFUNC_PROTO(Func1542){ 
WORD d,m;
LONG r;
int n=UBITS(9,11,iw);
d=CL_WORD(V_AN_D_WORD((UBITS(0,5,iw)&7)));;
m=LDREG_WORD(n);
sr &= ~MASK_CC|MASK_CC_X;
r = d * m;
SET_NZ(r);
DREG(n) = r;
THREAD
; }
GENFUNC_PROTO(Func1543){ 
WORD d,m;
LONG r;
int n=UBITS(9,11,iw);
d=CL_WORD(V_AN_R_WORD((UBITS(0,5,iw)&7)));;
m=LDREG_WORD(n);
sr &= ~MASK_CC|MASK_CC_X;
r = d * m;
SET_NZ(r);
DREG(n) = r;
THREAD
; }
GENFUNC_PROTO(Func1544){ 
WORD d,m;
LONG r;
int n=UBITS(9,11,iw);
d=CL_WORD(V_ABS_W_WORD());;
m=LDREG_WORD(n);
sr &= ~MASK_CC|MASK_CC_X;
r = d * m;
SET_NZ(r);
DREG(n) = r;
THREAD
; }
GENFUNC_PROTO(Func1545){ 
WORD d,m;
LONG r;
int n=UBITS(9,11,iw);
d=CL_WORD(V_ABS_L_WORD());;
m=LDREG_WORD(n);
sr &= ~MASK_CC|MASK_CC_X;
r = d * m;
SET_NZ(r);
DREG(n) = r;
THREAD
; }
GENFUNC_PROTO(Func1546){ 
WORD d,m;
LONG r;
int n=UBITS(9,11,iw);
d=CL_WORD(V_PC_D_WORD());;
m=LDREG_WORD(n);
sr &= ~MASK_CC|MASK_CC_X;
r = d * m;
SET_NZ(r);
DREG(n) = r;
THREAD
; }
GENFUNC_PROTO(Func1547){ 
WORD d,m;
LONG r;
int n=UBITS(9,11,iw);
d=CL_WORD(V_PC_R_WORD());;
m=LDREG_WORD(n);
sr &= ~MASK_CC|MASK_CC_X;
r = d * m;
SET_NZ(r);
DREG(n) = r;
THREAD
; }
GENFUNC_PROTO(Func1548){ 
WORD d,m;
LONG r;
int n=UBITS(9,11,iw);
d=LM_WORD(MEM(V_IMM_WORD()));;
m=LDREG_WORD(n);
sr &= ~MASK_CC|MASK_CC_X;
r = d * m;
SET_NZ(r);
DREG(n) = r;
THREAD
; }
GENFUNC_PROTO(Func1549){ 
BYTE r,x,s;
int n=UBITS(9,11,iw);
s=LDREG_BYTE((UBITS(0,5,iw)&7));;
x=LDREG_BYTE(n);
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
SDREG_BYTE(n,r);
THREAD
; }
GENFUNC_PROTO(Func1550){ 
BYTE r,x,s;
int n=UBITS(9,11,iw);
s=CL_BYTE(V_AN_I_BYTE((UBITS(0,5,iw)&7)));;
x=LDREG_BYTE(n);
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
SDREG_BYTE(n,r);
THREAD
; }
GENFUNC_PROTO(Func1551){ 
BYTE r,x,s;
int n=UBITS(9,11,iw);
s=CL_BYTE(V_AN_PI_BYTE((UBITS(0,5,iw)&7)));;
x=LDREG_BYTE(n);
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
SDREG_BYTE(n,r);
THREAD
; }
GENFUNC_PROTO(Func1552){ 
BYTE r,x,s;
int n=UBITS(9,11,iw);
s=CL_BYTE(V_AN_PI_BYTE_All(7));;
x=LDREG_BYTE(n);
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
SDREG_BYTE(n,r);
THREAD
; }
GENFUNC_PROTO(Func1553){ 
BYTE r,x,s;
int n=UBITS(9,11,iw);
s=CL_BYTE(V_AN_PD_BYTE((UBITS(0,5,iw)&7)));;
x=LDREG_BYTE(n);
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
SDREG_BYTE(n,r);
THREAD
; }
GENFUNC_PROTO(Func1554){ 
BYTE r,x,s;
int n=UBITS(9,11,iw);
s=CL_BYTE(V_AN_PD_BYTE_All(7));;
x=LDREG_BYTE(n);
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
SDREG_BYTE(n,r);
THREAD
; }
GENFUNC_PROTO(Func1555){ 
BYTE r,x,s;
int n=UBITS(9,11,iw);
s=CL_BYTE(V_AN_D_BYTE((UBITS(0,5,iw)&7)));;
x=LDREG_BYTE(n);
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
SDREG_BYTE(n,r);
THREAD
; }
GENFUNC_PROTO(Func1556){ 
BYTE r,x,s;
int n=UBITS(9,11,iw);
s=CL_BYTE(V_AN_R_BYTE((UBITS(0,5,iw)&7)));;
x=LDREG_BYTE(n);
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
SDREG_BYTE(n,r);
THREAD
; }
GENFUNC_PROTO(Func1557){ 
BYTE r,x,s;
int n=UBITS(9,11,iw);
s=CL_BYTE(V_ABS_W_BYTE());;
x=LDREG_BYTE(n);
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
SDREG_BYTE(n,r);
THREAD
; }
GENFUNC_PROTO(Func1558){ 
BYTE r,x,s;
int n=UBITS(9,11,iw);
s=CL_BYTE(V_ABS_L_BYTE());;
x=LDREG_BYTE(n);
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
SDREG_BYTE(n,r);
THREAD
; }
GENFUNC_PROTO(Func1559){ 
BYTE r,x,s;
int n=UBITS(9,11,iw);
s=CL_BYTE(V_PC_D_BYTE());;
x=LDREG_BYTE(n);
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
SDREG_BYTE(n,r);
THREAD
; }
GENFUNC_PROTO(Func1560){ 
BYTE r,x,s;
int n=UBITS(9,11,iw);
s=CL_BYTE(V_PC_R_BYTE());;
x=LDREG_BYTE(n);
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
SDREG_BYTE(n,r);
THREAD
; }
GENFUNC_PROTO(Func1561){ 
BYTE r,x,s;
int n=UBITS(9,11,iw);
s=LM_BYTE(MEM(V_IMM_BYTE()));;
x=LDREG_BYTE(n);
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
SDREG_BYTE(n,r);
THREAD
; }
GENFUNC_PROTO(Func1562){ 
WORD r,x,s;
int n=UBITS(9,11,iw);
s=LDREG_WORD((UBITS(0,5,iw)&7));;
x=LDREG_WORD(n);
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
SDREG_WORD(n,r);
THREAD
; }
GENFUNC_PROTO(Func1563){ 
WORD r,x,s;
int n=UBITS(9,11,iw);
s=LDREG_WORD((UBITS(0,5,iw)&7)+8);;
x=LDREG_WORD(n);
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
SDREG_WORD(n,r);
THREAD
; }
GENFUNC_PROTO(Func1564){ 
WORD r,x,s;
int n=UBITS(9,11,iw);
s=CL_WORD(V_AN_I_WORD((UBITS(0,5,iw)&7)));;
x=LDREG_WORD(n);
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
SDREG_WORD(n,r);
THREAD
; }
GENFUNC_PROTO(Func1565){ 
WORD r,x,s;
int n=UBITS(9,11,iw);
s=CL_WORD(V_AN_PI_WORD((UBITS(0,5,iw)&7)));;
x=LDREG_WORD(n);
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
SDREG_WORD(n,r);
THREAD
; }
GENFUNC_PROTO(Func1566){ 
WORD r,x,s;
int n=UBITS(9,11,iw);
s=CL_WORD(V_AN_PD_WORD((UBITS(0,5,iw)&7)));;
x=LDREG_WORD(n);
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
SDREG_WORD(n,r);
THREAD
; }
GENFUNC_PROTO(Func1567){ 
WORD r,x,s;
int n=UBITS(9,11,iw);
s=CL_WORD(V_AN_D_WORD((UBITS(0,5,iw)&7)));;
x=LDREG_WORD(n);
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
SDREG_WORD(n,r);
THREAD
; }
GENFUNC_PROTO(Func1568){ 
WORD r,x,s;
int n=UBITS(9,11,iw);
s=CL_WORD(V_AN_R_WORD((UBITS(0,5,iw)&7)));;
x=LDREG_WORD(n);
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
SDREG_WORD(n,r);
THREAD
; }
GENFUNC_PROTO(Func1569){ 
WORD r,x,s;
int n=UBITS(9,11,iw);
s=CL_WORD(V_ABS_W_WORD());;
x=LDREG_WORD(n);
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
SDREG_WORD(n,r);
THREAD
; }
GENFUNC_PROTO(Func1570){ 
WORD r,x,s;
int n=UBITS(9,11,iw);
s=CL_WORD(V_ABS_L_WORD());;
x=LDREG_WORD(n);
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
SDREG_WORD(n,r);
THREAD
; }
GENFUNC_PROTO(Func1571){ 
WORD r,x,s;
int n=UBITS(9,11,iw);
s=CL_WORD(V_PC_D_WORD());;
x=LDREG_WORD(n);
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
SDREG_WORD(n,r);
THREAD
; }
GENFUNC_PROTO(Func1572){ 
WORD r,x,s;
int n=UBITS(9,11,iw);
s=CL_WORD(V_PC_R_WORD());;
x=LDREG_WORD(n);
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
SDREG_WORD(n,r);
THREAD
; }
GENFUNC_PROTO(Func1573){ 
WORD r,x,s;
int n=UBITS(9,11,iw);
s=LM_WORD(MEM(V_IMM_WORD()));;
x=LDREG_WORD(n);
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
SDREG_WORD(n,r);
THREAD
; }
GENFUNC_PROTO(Func1574){ 
LONG r,x,s;
int n=UBITS(9,11,iw);
s=LDREG_LONG((UBITS(0,5,iw)&7));;
x=LDREG_LONG(n);
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
SDREG_LONG(n,r);
THREAD
; }
GENFUNC_PROTO(Func1575){ 
LONG r,x,s;
int n=UBITS(9,11,iw);
s=LDREG_LONG((UBITS(0,5,iw)&7)+8);;
x=LDREG_LONG(n);
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
SDREG_LONG(n,r);
THREAD
; }
GENFUNC_PROTO(Func1576){ 
LONG r,x,s;
int n=UBITS(9,11,iw);
s=CL_LONG(V_AN_I_LONG((UBITS(0,5,iw)&7)));;
x=LDREG_LONG(n);
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
SDREG_LONG(n,r);
THREAD
; }
GENFUNC_PROTO(Func1577){ 
LONG r,x,s;
int n=UBITS(9,11,iw);
s=CL_LONG(V_AN_PI_LONG((UBITS(0,5,iw)&7)));;
x=LDREG_LONG(n);
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
SDREG_LONG(n,r);
THREAD
; }
GENFUNC_PROTO(Func1578){ 
LONG r,x,s;
int n=UBITS(9,11,iw);
s=CL_LONG(V_AN_PD_LONG((UBITS(0,5,iw)&7)));;
x=LDREG_LONG(n);
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
SDREG_LONG(n,r);
THREAD
; }
GENFUNC_PROTO(Func1579){ 
LONG r,x,s;
int n=UBITS(9,11,iw);
s=CL_LONG(V_AN_D_LONG((UBITS(0,5,iw)&7)));;
x=LDREG_LONG(n);
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
SDREG_LONG(n,r);
THREAD
; }
GENFUNC_PROTO(Func1580){ 
LONG r,x,s;
int n=UBITS(9,11,iw);
s=CL_LONG(V_AN_R_LONG((UBITS(0,5,iw)&7)));;
x=LDREG_LONG(n);
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
SDREG_LONG(n,r);
THREAD
; }
GENFUNC_PROTO(Func1581){ 
LONG r,x,s;
int n=UBITS(9,11,iw);
s=CL_LONG(V_ABS_W_LONG());;
x=LDREG_LONG(n);
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
SDREG_LONG(n,r);
THREAD
; }
GENFUNC_PROTO(Func1582){ 
LONG r,x,s;
int n=UBITS(9,11,iw);
s=CL_LONG(V_ABS_L_LONG());;
x=LDREG_LONG(n);
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
SDREG_LONG(n,r);
THREAD
; }
GENFUNC_PROTO(Func1583){ 
LONG r,x,s;
int n=UBITS(9,11,iw);
s=CL_LONG(V_PC_D_LONG());;
x=LDREG_LONG(n);
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
SDREG_LONG(n,r);
THREAD
; }
GENFUNC_PROTO(Func1584){ 
LONG r,x,s;
int n=UBITS(9,11,iw);
s=CL_LONG(V_PC_R_LONG());;
x=LDREG_LONG(n);
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
SDREG_LONG(n,r);
THREAD
; }
GENFUNC_PROTO(Func1585){ 
LONG r,x,s;
int n=UBITS(9,11,iw);
s=LM_LONG(MEM(V_IMM_LONG()));;
x=LDREG_LONG(n);
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
SDREG_LONG(n,r);
THREAD
; }
GENFUNC_PROTO(Func1586){ 
LONG x;
x=LDREG_WORD((UBITS(0,5,iw)&7));;
AREG(UBITS(9,11,iw)) += x;
THREAD
; }
GENFUNC_PROTO(Func1587){ 
LONG x;
x=LDREG_WORD((UBITS(0,5,iw)&7)+8);;
AREG(UBITS(9,11,iw)) += x;
THREAD
; }
GENFUNC_PROTO(Func1588){ 
LONG x;
x=CL_WORD(V_AN_I_WORD((UBITS(0,5,iw)&7)));;
AREG(UBITS(9,11,iw)) += x;
THREAD
; }
GENFUNC_PROTO(Func1589){ 
LONG x;
x=CL_WORD(V_AN_PI_WORD((UBITS(0,5,iw)&7)));;
AREG(UBITS(9,11,iw)) += x;
THREAD
; }
GENFUNC_PROTO(Func1590){ 
LONG x;
x=CL_WORD(V_AN_PD_WORD((UBITS(0,5,iw)&7)));;
AREG(UBITS(9,11,iw)) += x;
THREAD
; }
GENFUNC_PROTO(Func1591){ 
LONG x;
x=CL_WORD(V_AN_D_WORD((UBITS(0,5,iw)&7)));;
AREG(UBITS(9,11,iw)) += x;
THREAD
; }
GENFUNC_PROTO(Func1592){ 
LONG x;
x=CL_WORD(V_AN_R_WORD((UBITS(0,5,iw)&7)));;
AREG(UBITS(9,11,iw)) += x;
THREAD
; }
GENFUNC_PROTO(Func1593){ 
LONG x;
x=CL_WORD(V_ABS_W_WORD());;
AREG(UBITS(9,11,iw)) += x;
THREAD
; }
GENFUNC_PROTO(Func1594){ 
LONG x;
x=CL_WORD(V_ABS_L_WORD());;
AREG(UBITS(9,11,iw)) += x;
THREAD
; }
GENFUNC_PROTO(Func1595){ 
LONG x;
x=CL_WORD(V_PC_D_WORD());;
AREG(UBITS(9,11,iw)) += x;
THREAD
; }
GENFUNC_PROTO(Func1596){ 
LONG x;
x=CL_WORD(V_PC_R_WORD());;
AREG(UBITS(9,11,iw)) += x;
THREAD
; }
GENFUNC_PROTO(Func1597){ 
LONG x;
x=LM_WORD(MEM(V_IMM_WORD()));;
AREG(UBITS(9,11,iw)) += x;
THREAD
; }
GENFUNC_PROTO(Func1598){ 
BYTE s,x,r,t;
int n=UBITS(9,11,iw);
t=GET_X_BIT();
sr &= ~MASK_CC | MASK_CC_Z; /* FIXME? */
s=LDREG_BYTE(UBITS(0,2,iw));
x=LDREG_BYTE(n);
r=x+s+t;
SET_VCX_ADD;
if (r) SET_NZ(r);
else UNSET_N();
SDREG_BYTE(n,r);
THREAD
; }
GENFUNC_PROTO(Func1599){ 
BYTE s,x,r,t;
int n=UBITS(9,11,iw);
t=GET_X_BIT();
sr &= ~MASK_CC | MASK_CC_Z;

s=CL_BYTE(V_AN_PD_BYTE_All(UBITS(0,2,iw)));;
{UL v_x=V_AN_PD_BYTE_All(n); x=CL_BYTE(v_x);;
r=x+s+t;
SET_VCX_ADD;
UNSET_Z();
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1600){ 
BYTE s,r,x;
s=LDREG_BYTE(UBITS(9,11,iw));
{UL v_x=V_AN_I_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1601){ 
BYTE s,r,x;
s=LDREG_BYTE(UBITS(9,11,iw));
{UL v_x=V_AN_PI_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1602){ 
BYTE s,r,x;
s=LDREG_BYTE(UBITS(9,11,iw));
{UL v_x=V_AN_PI_BYTE_All(7); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1603){ 
BYTE s,r,x;
s=LDREG_BYTE(UBITS(9,11,iw));
{UL v_x=V_AN_PD_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1604){ 
BYTE s,r,x;
s=LDREG_BYTE(UBITS(9,11,iw));
{UL v_x=V_AN_PD_BYTE_All(7); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1605){ 
BYTE s,r,x;
s=LDREG_BYTE(UBITS(9,11,iw));
{UL v_x=V_AN_D_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1606){ 
BYTE s,r,x;
s=LDREG_BYTE(UBITS(9,11,iw));
{UL v_x=V_AN_R_BYTE((UBITS(0,5,iw)&7)); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1607){ 
BYTE s,r,x;
s=LDREG_BYTE(UBITS(9,11,iw));
{UL v_x=V_ABS_W_BYTE(); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1608){ 
BYTE s,r,x;
s=LDREG_BYTE(UBITS(9,11,iw));
{UL v_x=V_ABS_L_BYTE(); x=CL_BYTE(v_x);;
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_BYTE(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1609){ 
WORD s,x,r,t;
int n=UBITS(9,11,iw);
t=GET_X_BIT();
sr &= ~MASK_CC | MASK_CC_Z; /* FIXME? */
s=LDREG_WORD(UBITS(0,2,iw));
x=LDREG_WORD(n);
r=x+s+t;
SET_VCX_ADD;
if (r) SET_NZ(r);
else UNSET_N();
SDREG_WORD(n,r);
THREAD
; }
GENFUNC_PROTO(Func1610){ 
WORD s,x,r,t;
int n=UBITS(9,11,iw);
t=GET_X_BIT();
sr &= ~MASK_CC | MASK_CC_Z;

s=CL_WORD(V_AN_PD_WORD(UBITS(0,2,iw)));;
{UL v_x=V_AN_PD_WORD(n); x=CL_WORD(v_x);;
r=x+s+t;
SET_VCX_ADD;
UNSET_Z();
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1611){ 
WORD s,r,x;
s=LDREG_WORD(UBITS(9,11,iw));
{UL v_x=V_AN_I_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1612){ 
WORD s,r,x;
s=LDREG_WORD(UBITS(9,11,iw));
{UL v_x=V_AN_PI_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1613){ 
WORD s,r,x;
s=LDREG_WORD(UBITS(9,11,iw));
{UL v_x=V_AN_PD_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1614){ 
WORD s,r,x;
s=LDREG_WORD(UBITS(9,11,iw));
{UL v_x=V_AN_D_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1615){ 
WORD s,r,x;
s=LDREG_WORD(UBITS(9,11,iw));
{UL v_x=V_AN_R_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1616){ 
WORD s,r,x;
s=LDREG_WORD(UBITS(9,11,iw));
{UL v_x=V_ABS_W_WORD(); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1617){ 
WORD s,r,x;
s=LDREG_WORD(UBITS(9,11,iw));
{UL v_x=V_ABS_L_WORD(); x=CL_WORD(v_x);;
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1618){ 
LONG s,x,r,t;
int n=UBITS(9,11,iw);
t=GET_X_BIT();
sr &= ~MASK_CC | MASK_CC_Z; /* FIXME? */
s=LDREG_LONG(UBITS(0,2,iw));
x=LDREG_LONG(n);
r=x+s+t;
SET_VCX_ADD;
if (r) SET_NZ(r);
else UNSET_N();
SDREG_LONG(n,r);
THREAD
; }
GENFUNC_PROTO(Func1619){ 
LONG s,x,r,t;
int n=UBITS(9,11,iw);
t=GET_X_BIT();
sr &= ~MASK_CC | MASK_CC_Z;

s=CL_LONG(V_AN_PD_LONG(UBITS(0,2,iw)));;
{UL v_x=V_AN_PD_LONG(n); x=CL_LONG(v_x);;
r=x+s+t;
SET_VCX_ADD;
UNSET_Z();
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1620){ 
LONG s,r,x;
s=LDREG_LONG(UBITS(9,11,iw));
{UL v_x=V_AN_I_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1621){ 
LONG s,r,x;
s=LDREG_LONG(UBITS(9,11,iw));
{UL v_x=V_AN_PI_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1622){ 
LONG s,r,x;
s=LDREG_LONG(UBITS(9,11,iw));
{UL v_x=V_AN_PD_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1623){ 
LONG s,r,x;
s=LDREG_LONG(UBITS(9,11,iw));
{UL v_x=V_AN_D_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1624){ 
LONG s,r,x;
s=LDREG_LONG(UBITS(9,11,iw));
{UL v_x=V_AN_R_LONG((UBITS(0,5,iw)&7)); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1625){ 
LONG s,r,x;
s=LDREG_LONG(UBITS(9,11,iw));
{UL v_x=V_ABS_W_LONG(); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1626){ 
LONG s,r,x;
s=LDREG_LONG(UBITS(9,11,iw));
{UL v_x=V_ABS_L_LONG(); x=CL_LONG(v_x);;
sr &= ~MASK_CC;
r = x + s;
SET_VCX_ADD;
SET_NZ(r);
x=r;
CS_LONG(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1627){ 
LONG x;
x=LDREG_LONG((UBITS(0,5,iw)&7));;
AREG(UBITS(9,11,iw)) += x;
THREAD
; }
GENFUNC_PROTO(Func1628){ 
LONG x;
x=LDREG_LONG((UBITS(0,5,iw)&7)+8);;
AREG(UBITS(9,11,iw)) += x;
THREAD
; }
GENFUNC_PROTO(Func1629){ 
LONG x;
x=CL_LONG(V_AN_I_LONG((UBITS(0,5,iw)&7)));;
AREG(UBITS(9,11,iw)) += x;
THREAD
; }
GENFUNC_PROTO(Func1630){ 
LONG x;
x=CL_LONG(V_AN_PI_LONG((UBITS(0,5,iw)&7)));;
AREG(UBITS(9,11,iw)) += x;
THREAD
; }
GENFUNC_PROTO(Func1631){ 
LONG x;
x=CL_LONG(V_AN_PD_LONG((UBITS(0,5,iw)&7)));;
AREG(UBITS(9,11,iw)) += x;
THREAD
; }
GENFUNC_PROTO(Func1632){ 
LONG x;
x=CL_LONG(V_AN_D_LONG((UBITS(0,5,iw)&7)));;
AREG(UBITS(9,11,iw)) += x;
THREAD
; }
GENFUNC_PROTO(Func1633){ 
LONG x;
x=CL_LONG(V_AN_R_LONG((UBITS(0,5,iw)&7)));;
AREG(UBITS(9,11,iw)) += x;
THREAD
; }
GENFUNC_PROTO(Func1634){ 
LONG x;
x=CL_LONG(V_ABS_W_LONG());;
AREG(UBITS(9,11,iw)) += x;
THREAD
; }
GENFUNC_PROTO(Func1635){ 
LONG x;
x=CL_LONG(V_ABS_L_LONG());;
AREG(UBITS(9,11,iw)) += x;
THREAD
; }
GENFUNC_PROTO(Func1636){ 
LONG x;
x=CL_LONG(V_PC_D_LONG());;
AREG(UBITS(9,11,iw)) += x;
THREAD
; }
GENFUNC_PROTO(Func1637){ 
LONG x;
x=CL_LONG(V_PC_R_LONG());;
AREG(UBITS(9,11,iw)) += x;
THREAD
; }
GENFUNC_PROTO(Func1638){ 
LONG x;
x=LM_LONG(MEM(V_IMM_LONG()));;
AREG(UBITS(9,11,iw)) += x;
THREAD
; }
GENFUNC_PROTO(Func1639){ 
int c=8,n=UBITS(0,2,iw);
BYTE x;
x=LDREG_BYTE(n);

sr &= ~MASK_CC|MASK_CC_X;
if (c>0)
{
	sr &= ~MASK_CC_X;
	if ((x>>(c-1))&1) sr |= (MASK_CC_X|MASK_CC_C);
	x>>=c;
}
SET_NZ((LONG)x);
;
SDREG_BYTE(n,x);
THREAD
; }
GENFUNC_PROTO(Func1640){ 
int c=8,n=UBITS(0,2,iw);
UBYTE x;
x=LDREG_UBYTE(n);

sr &= ~MASK_CC|MASK_CC_X;
if (c>0)
{
	sr &= ~MASK_CC_X;
	if ((x >> (c-1)) & 1) sr |= (MASK_CC_X|MASK_CC_C);
	x>>=c;
}
SET_NZ((LONG)x);
THREAD
;
SDREG_UBYTE(n,x);
THREAD
; }
GENFUNC_PROTO(Func1641){ 
int c=8,n=UBITS(0,2,iw);
UBYTE x;
x=LDREG_UBYTE(n);

{
BYTE y;
int t;
sr &= ~MASK_CC|MASK_CC_X;
t=GET_X_BIT();
if (c>0)
{
	unsigned int bot,tt;
#if 0
	tt = ((x<<1)|t)<<(8*SIZEBYTE-c);
	x >>= c-1;
	t = x&1;
	sr &= ~MASK_CC_X;
	sr |= t << 4;
	x >>= 1;
	x |= tt;
#else
    tt = (x >> (c-1)) & 1;
	bot = x << (8*SIZEBYTE-c);   /* bits that are rotated out */
	sr &= ~MASK_CC_X;
	x >>= c;
	x |= t << (8*SIZEBYTE-c);
	x |= bot << 1;
	t=tt;
	sr |= t << 4;
#endif
}
sr |= t; /* carry */
y=(BYTE)x;
SET_NZ(y);
}
;
SDREG_UBYTE(n,x);
THREAD
; }
GENFUNC_PROTO(Func1642){ 
int c=8,n=UBITS(0,2,iw);
UBYTE x;
x=LDREG_UBYTE(n);

{ BYTE y;
sr &= ~MASK_CC|MASK_CC_X;
if (c>0)
{
	int t=x<<((8*SIZEBYTE)-c);
	if ((x >> (c-1)) & 1) sr |= MASK_CC_C;
	x>>=c;
	x|=t;
}
y=(BYTE)x;
SET_NZ(y); /* FIXME */
}
;
SDREG_UBYTE(n,x);
THREAD
; }
GENFUNC_PROTO(Func1643){ 
int c,n;
BYTE x;
c=DREG(UBITS(9,11,iw))&63;
n=UBITS(0,2,iw);
x=LDREG_BYTE(n);
#if SHWRAP32
if (c>=32)
{
	sr &= ~(MASK_CC|MASK_CC_X);
	if (x<0)
	{
		sr |= (MASK_CC_X|MASK_CC_C);
		x=-1;
		SET_NZ(-1);
	}
	else
	{
		
		sr &= ~MASK_CC;
		SET_NZ(0);
		x=0;
	}
}
else
#endif

sr &= ~MASK_CC|MASK_CC_X;
if (c>0)
{
	sr &= ~MASK_CC_X;
	if ((x>>(c-1))&1) sr |= (MASK_CC_X|MASK_CC_C);
	x>>=c;
}
SET_NZ((LONG)x);
;
SDREG_BYTE(n,x);
THREAD
; }
GENFUNC_PROTO(Func1644){ 
int c,n;
UBYTE x;
c=DREG(UBITS(9,11,iw))&63;
n=UBITS(0,2,iw);
x=LDREG_UBYTE(n);
#if SHWRAP32
if (c>=32)
{
	sr &= ~MASK_CC;
	SET_NZ(0);
	x=0;
}
else
#endif

sr &= ~MASK_CC|MASK_CC_X;
if (c>0)
{
	sr &= ~MASK_CC_X;
	if ((x >> (c-1)) & 1) sr |= (MASK_CC_X|MASK_CC_C);
	x>>=c;
}
SET_NZ((LONG)x);
THREAD
;
SDREG_UBYTE(n,x);
THREAD
; }
GENFUNC_PROTO(Func1645){ 
int c,n;
UBYTE x;
c=DREG(UBITS(9,11,iw))&63;
n=UBITS(0,2,iw);
x=LDREG_UBYTE(n);

{
BYTE y;
int t;
sr &= ~MASK_CC|MASK_CC_X;
t=GET_X_BIT();
if (c>0)
{
	unsigned int bot,tt;
#if 0
	tt = ((x<<1)|t)<<(8*SIZEBYTE-c);
	x >>= c-1;
	t = x&1;
	sr &= ~MASK_CC_X;
	sr |= t << 4;
	x >>= 1;
	x |= tt;
#else
    tt = (x >> (c-1)) & 1;
	bot = x << (8*SIZEBYTE-c);   /* bits that are rotated out */
	sr &= ~MASK_CC_X;
	x >>= c;
	x |= t << (8*SIZEBYTE-c);
	x |= bot << 1;
	t=tt;
	sr |= t << 4;
#endif
}
sr |= t; /* carry */
y=(BYTE)x;
SET_NZ(y);
}
;
SDREG_UBYTE(n,x);
THREAD
; }
GENFUNC_PROTO(Func1646){ 
int c,n;
UBYTE x;
c=DREG(UBITS(9,11,iw))&(8*SIZEBYTE-1);
n=UBITS(0,2,iw);
x=LDREG_UBYTE(n);

{ BYTE y;
sr &= ~MASK_CC|MASK_CC_X;
if (c>0)
{
	int t=x<<((8*SIZEBYTE)-c);
	if ((x >> (c-1)) & 1) sr |= MASK_CC_C;
	x>>=c;
	x|=t;
}
y=(BYTE)x;
SET_NZ(y); /* FIXME */
}
;
SDREG_UBYTE(n,x);
THREAD
; }
GENFUNC_PROTO(Func1647){ 
int c=8,n=UBITS(0,2,iw);
WORD x;
x=LDREG_WORD(n);

sr &= ~MASK_CC|MASK_CC_X;
if (c>0)
{
	sr &= ~MASK_CC_X;
	if ((x>>(c-1))&1) sr |= (MASK_CC_X|MASK_CC_C);
	x>>=c;
}
SET_NZ((LONG)x);
;
SDREG_WORD(n,x);
THREAD
; }
GENFUNC_PROTO(Func1648){ 
int c=8,n=UBITS(0,2,iw);
UWORD x;
x=LDREG_UWORD(n);

sr &= ~MASK_CC|MASK_CC_X;
if (c>0)
{
	sr &= ~MASK_CC_X;
	if ((x >> (c-1)) & 1) sr |= (MASK_CC_X|MASK_CC_C);
	x>>=c;
}
SET_NZ((LONG)x);
THREAD
;
SDREG_UWORD(n,x);
THREAD
; }
GENFUNC_PROTO(Func1649){ 
int c=8,n=UBITS(0,2,iw);
UWORD x;
x=LDREG_UWORD(n);

{
WORD y;
int t;
sr &= ~MASK_CC|MASK_CC_X;
t=GET_X_BIT();
if (c>0)
{
	unsigned int bot,tt;
#if 0
	tt = ((x<<1)|t)<<(8*SIZEWORD-c);
	x >>= c-1;
	t = x&1;
	sr &= ~MASK_CC_X;
	sr |= t << 4;
	x >>= 1;
	x |= tt;
#else
    tt = (x >> (c-1)) & 1;
	bot = x << (8*SIZEWORD-c);   /* bits that are rotated out */
	sr &= ~MASK_CC_X;
	x >>= c;
	x |= t << (8*SIZEWORD-c);
	x |= bot << 1;
	t=tt;
	sr |= t << 4;
#endif
}
sr |= t; /* carry */
y=(WORD)x;
SET_NZ(y);
}
;
SDREG_UWORD(n,x);
THREAD
; }
GENFUNC_PROTO(Func1650){ 
int c=8,n=UBITS(0,2,iw);
UWORD x;
x=LDREG_UWORD(n);

{ WORD y;
sr &= ~MASK_CC|MASK_CC_X;
if (c>0)
{
	int t=x<<((8*SIZEWORD)-c);
	if ((x >> (c-1)) & 1) sr |= MASK_CC_C;
	x>>=c;
	x|=t;
}
y=(WORD)x;
SET_NZ(y); /* FIXME */
}
;
SDREG_UWORD(n,x);
THREAD
; }
GENFUNC_PROTO(Func1651){ 
int c,n;
WORD x;
c=DREG(UBITS(9,11,iw))&63;
n=UBITS(0,2,iw);
x=LDREG_WORD(n);
#if SHWRAP32
if (c>=32)
{
	sr &= ~(MASK_CC|MASK_CC_X);
	if (x<0)
	{
		sr |= (MASK_CC_X|MASK_CC_C);
		x=-1;
		SET_NZ(-1);
	}
	else
	{
		
		sr &= ~MASK_CC;
		SET_NZ(0);
		x=0;
	}
}
else
#endif

sr &= ~MASK_CC|MASK_CC_X;
if (c>0)
{
	sr &= ~MASK_CC_X;
	if ((x>>(c-1))&1) sr |= (MASK_CC_X|MASK_CC_C);
	x>>=c;
}
SET_NZ((LONG)x);
;
SDREG_WORD(n,x);
THREAD
; }
GENFUNC_PROTO(Func1652){ 
int c,n;
UWORD x;
c=DREG(UBITS(9,11,iw))&63;
n=UBITS(0,2,iw);
x=LDREG_UWORD(n);
#if SHWRAP32
if (c>=32)
{
	sr &= ~MASK_CC;
	SET_NZ(0);
	x=0;
}
else
#endif

sr &= ~MASK_CC|MASK_CC_X;
if (c>0)
{
	sr &= ~MASK_CC_X;
	if ((x >> (c-1)) & 1) sr |= (MASK_CC_X|MASK_CC_C);
	x>>=c;
}
SET_NZ((LONG)x);
THREAD
;
SDREG_UWORD(n,x);
THREAD
; }
GENFUNC_PROTO(Func1653){ 
int c,n;
UWORD x;
c=DREG(UBITS(9,11,iw))&63;
n=UBITS(0,2,iw);
x=LDREG_UWORD(n);

{
WORD y;
int t;
sr &= ~MASK_CC|MASK_CC_X;
t=GET_X_BIT();
if (c>0)
{
	unsigned int bot,tt;
#if 0
	tt = ((x<<1)|t)<<(8*SIZEWORD-c);
	x >>= c-1;
	t = x&1;
	sr &= ~MASK_CC_X;
	sr |= t << 4;
	x >>= 1;
	x |= tt;
#else
    tt = (x >> (c-1)) & 1;
	bot = x << (8*SIZEWORD-c);   /* bits that are rotated out */
	sr &= ~MASK_CC_X;
	x >>= c;
	x |= t << (8*SIZEWORD-c);
	x |= bot << 1;
	t=tt;
	sr |= t << 4;
#endif
}
sr |= t; /* carry */
y=(WORD)x;
SET_NZ(y);
}
;
SDREG_UWORD(n,x);
THREAD
; }
GENFUNC_PROTO(Func1654){ 
int c,n;
UWORD x;
c=DREG(UBITS(9,11,iw))&(8*SIZEWORD-1);
n=UBITS(0,2,iw);
x=LDREG_UWORD(n);

{ WORD y;
sr &= ~MASK_CC|MASK_CC_X;
if (c>0)
{
	int t=x<<((8*SIZEWORD)-c);
	if ((x >> (c-1)) & 1) sr |= MASK_CC_C;
	x>>=c;
	x|=t;
}
y=(WORD)x;
SET_NZ(y); /* FIXME */
}
;
SDREG_UWORD(n,x);
THREAD
; }
GENFUNC_PROTO(Func1655){ 
int c=8,n=UBITS(0,2,iw);
LONG x;
x=LDREG_LONG(n);

sr &= ~MASK_CC|MASK_CC_X;
if (c>0)
{
	sr &= ~MASK_CC_X;
	if ((x>>(c-1))&1) sr |= (MASK_CC_X|MASK_CC_C);
	x>>=c;
}
SET_NZ((LONG)x);
;
SDREG_LONG(n,x);
THREAD
; }
GENFUNC_PROTO(Func1656){ 
int c=8,n=UBITS(0,2,iw);
ULONG x;
x=LDREG_ULONG(n);

sr &= ~MASK_CC|MASK_CC_X;
if (c>0)
{
	sr &= ~MASK_CC_X;
	if ((x >> (c-1)) & 1) sr |= (MASK_CC_X|MASK_CC_C);
	x>>=c;
}
SET_NZ((LONG)x);
THREAD
;
SDREG_ULONG(n,x);
THREAD
; }
GENFUNC_PROTO(Func1657){ 
int c=8,n=UBITS(0,2,iw);
ULONG x;
x=LDREG_ULONG(n);

{
LONG y;
int t;
sr &= ~MASK_CC|MASK_CC_X;
t=GET_X_BIT();
if (c>0)
{
	unsigned int bot,tt;
#if 0
	tt = ((x<<1)|t)<<(8*SIZELONG-c);
	x >>= c-1;
	t = x&1;
	sr &= ~MASK_CC_X;
	sr |= t << 4;
	x >>= 1;
	x |= tt;
#else
    tt = (x >> (c-1)) & 1;
	bot = x << (8*SIZELONG-c);   /* bits that are rotated out */
	sr &= ~MASK_CC_X;
	x >>= c;
	x |= t << (8*SIZELONG-c);
	x |= bot << 1;
	t=tt;
	sr |= t << 4;
#endif
}
sr |= t; /* carry */
y=(LONG)x;
SET_NZ(y);
}
;
SDREG_ULONG(n,x);
THREAD
; }
GENFUNC_PROTO(Func1658){ 
int c=8,n=UBITS(0,2,iw);
ULONG x;
x=LDREG_ULONG(n);

{ LONG y;
sr &= ~MASK_CC|MASK_CC_X;
if (c>0)
{
	int t=x<<((8*SIZELONG)-c);
	if ((x >> (c-1)) & 1) sr |= MASK_CC_C;
	x>>=c;
	x|=t;
}
y=(LONG)x;
SET_NZ(y); /* FIXME */
}
;
SDREG_ULONG(n,x);
THREAD
; }
GENFUNC_PROTO(Func1659){ 
int c,n;
LONG x;
c=DREG(UBITS(9,11,iw))&63;
n=UBITS(0,2,iw);
x=LDREG_LONG(n);
#if SHWRAP32
if (c>=32)
{
	sr &= ~(MASK_CC|MASK_CC_X);
	if (x<0)
	{
		sr |= (MASK_CC_X|MASK_CC_C);
		x=-1;
		SET_NZ(-1);
	}
	else
	{
		
		sr &= ~MASK_CC;
		SET_NZ(0);
		x=0;
	}
}
else
#endif

sr &= ~MASK_CC|MASK_CC_X;
if (c>0)
{
	sr &= ~MASK_CC_X;
	if ((x>>(c-1))&1) sr |= (MASK_CC_X|MASK_CC_C);
	x>>=c;
}
SET_NZ((LONG)x);
;
SDREG_LONG(n,x);
THREAD
; }
GENFUNC_PROTO(Func1660){ 
int c,n;
ULONG x;
c=DREG(UBITS(9,11,iw))&63;
n=UBITS(0,2,iw);
x=LDREG_ULONG(n);
#if SHWRAP32
if (c>=32)
{
	sr &= ~MASK_CC;
	SET_NZ(0);
	x=0;
}
else
#endif

sr &= ~MASK_CC|MASK_CC_X;
if (c>0)
{
	sr &= ~MASK_CC_X;
	if ((x >> (c-1)) & 1) sr |= (MASK_CC_X|MASK_CC_C);
	x>>=c;
}
SET_NZ((LONG)x);
THREAD
;
SDREG_ULONG(n,x);
THREAD
; }
GENFUNC_PROTO(Func1661){ 
int c,n;
ULONG x;
c=DREG(UBITS(9,11,iw))&63;
n=UBITS(0,2,iw);
x=LDREG_ULONG(n);

{
LONG y;
int t;
sr &= ~MASK_CC|MASK_CC_X;
t=GET_X_BIT();
if (c>0)
{
	unsigned int bot,tt;
#if 0
	tt = ((x<<1)|t)<<(8*SIZELONG-c);
	x >>= c-1;
	t = x&1;
	sr &= ~MASK_CC_X;
	sr |= t << 4;
	x >>= 1;
	x |= tt;
#else
    tt = (x >> (c-1)) & 1;
	bot = x << (8*SIZELONG-c);   /* bits that are rotated out */
	sr &= ~MASK_CC_X;
	x >>= c;
	x |= t << (8*SIZELONG-c);
	x |= bot << 1;
	t=tt;
	sr |= t << 4;
#endif
}
sr |= t; /* carry */
y=(LONG)x;
SET_NZ(y);
}
;
SDREG_ULONG(n,x);
THREAD
; }
GENFUNC_PROTO(Func1662){ 
int c,n;
ULONG x;
c=DREG(UBITS(9,11,iw))&(8*SIZELONG-1);
n=UBITS(0,2,iw);
x=LDREG_ULONG(n);

{ LONG y;
sr &= ~MASK_CC|MASK_CC_X;
if (c>0)
{
	int t=x<<((8*SIZELONG)-c);
	if ((x >> (c-1)) & 1) sr |= MASK_CC_C;
	x>>=c;
	x|=t;
}
y=(LONG)x;
SET_NZ(y); /* FIXME */
}
;
SDREG_ULONG(n,x);
THREAD
; }
GENFUNC_PROTO(Func1663){ 
WORD x;
{UL v_x=V_AN_I_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;

sr &= ~MASK_CC|MASK_CC_X;
if (1>0)
{
	sr &= ~MASK_CC_X;
	if ((x>>(1-1))&1) sr |= (MASK_CC_X|MASK_CC_C);
	x>>=1;
}
SET_NZ((LONG)x);
;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1664){ 
WORD x;
{UL v_x=V_AN_PI_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;

sr &= ~MASK_CC|MASK_CC_X;
if (1>0)
{
	sr &= ~MASK_CC_X;
	if ((x>>(1-1))&1) sr |= (MASK_CC_X|MASK_CC_C);
	x>>=1;
}
SET_NZ((LONG)x);
;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1665){ 
WORD x;
{UL v_x=V_AN_PD_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;

sr &= ~MASK_CC|MASK_CC_X;
if (1>0)
{
	sr &= ~MASK_CC_X;
	if ((x>>(1-1))&1) sr |= (MASK_CC_X|MASK_CC_C);
	x>>=1;
}
SET_NZ((LONG)x);
;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1666){ 
WORD x;
{UL v_x=V_AN_D_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;

sr &= ~MASK_CC|MASK_CC_X;
if (1>0)
{
	sr &= ~MASK_CC_X;
	if ((x>>(1-1))&1) sr |= (MASK_CC_X|MASK_CC_C);
	x>>=1;
}
SET_NZ((LONG)x);
;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1667){ 
WORD x;
{UL v_x=V_AN_R_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;

sr &= ~MASK_CC|MASK_CC_X;
if (1>0)
{
	sr &= ~MASK_CC_X;
	if ((x>>(1-1))&1) sr |= (MASK_CC_X|MASK_CC_C);
	x>>=1;
}
SET_NZ((LONG)x);
;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1668){ 
WORD x;
{UL v_x=V_ABS_W_WORD(); x=CL_WORD(v_x);;

sr &= ~MASK_CC|MASK_CC_X;
if (1>0)
{
	sr &= ~MASK_CC_X;
	if ((x>>(1-1))&1) sr |= (MASK_CC_X|MASK_CC_C);
	x>>=1;
}
SET_NZ((LONG)x);
;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1669){ 
WORD x;
{UL v_x=V_ABS_L_WORD(); x=CL_WORD(v_x);;

sr &= ~MASK_CC|MASK_CC_X;
if (1>0)
{
	sr &= ~MASK_CC_X;
	if ((x>>(1-1))&1) sr |= (MASK_CC_X|MASK_CC_C);
	x>>=1;
}
SET_NZ((LONG)x);
;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1670){ 
int c=8,n=UBITS(0,2,iw);
BYTE x;
x=LDREG_BYTE(n);

sr &= ~MASK_CC|MASK_CC_X;
{
	if (c>0)
	{
		sr &= ~MASK_CC_X;
#if 0
		if ((x << (c-1))<0) sr |= (MASK_CC_X|MASK_CC_C); /* bug ? */
#else
		if ((x>>(8*SIZEBYTE-c))&1) sr |= (MASK_CC_C|MASK_CC_X);
#endif
		if ((x&(x+(1<<(c-1))))&~((1<<(8*SIZEBYTE-1-c))-1)) sr |= MASK_CC_V;
		x <<= c;
	}
}
SET_NZ((LONG)x);
;
SDREG_BYTE(n,x);
THREAD
; }
GENFUNC_PROTO(Func1671){ 
int c=8,n=UBITS(0,2,iw);
BYTE x;
x=LDREG_BYTE(n);

{ BYTE y;
sr &= ~MASK_CC|MASK_CC_X;
if (c>0)
{
	sr &= ~(MASK_CC_X);
#if 0
	if ((x << (c-1))<0) sr |= (MASK_CC_C|MASK_CC_X);
#else
	if ((x>>(8*SIZEBYTE-c))&1) sr |= (MASK_CC_C|MASK_CC_X);
#endif
	x <<= c;
}
y=(BYTE)x;
SET_NZ(y);
}
;
SDREG_BYTE(n,x);
THREAD
; }
GENFUNC_PROTO(Func1672){ 
int c=8,n=UBITS(0,2,iw);
UBYTE x;
x=LDREG_UBYTE(n);

{
BYTE y;
int t,tt;
sr &= ~MASK_CC|MASK_CC_X;
t=GET_X_BIT();
if (c>0)
{
	unsigned int top;
	top = x>>(8*SIZEBYTE-c);	/* bits that are rotated out */
	sr &= ~MASK_CC_X;
	x <<= c;
	x |= t << (c-1);
	x |= top >> 1;
	t = top & 1;
	sr |= t << 4;

}
sr |= t;
y=(BYTE)x;
SET_NZ(y);
}
;
SDREG_UBYTE(n,x);
THREAD
; }
GENFUNC_PROTO(Func1673){ 
int c=8,n=UBITS(0,2,iw);
BYTE x;
x=LDREG_BYTE(n);

{ BYTE y;
sr &= ~MASK_CC|MASK_CC_X;
if (c>0)
{
	unsigned long t;
	t = x&MASKBYTE;
	t >>= (8*SIZEBYTE-c);
	if (t&1) sr |= MASK_CC_C;
	x <<= c;
	x |= t;
}
y=(BYTE)x;
SET_NZ(y);
}
;
SDREG_BYTE(n,x);
THREAD
; }
GENFUNC_PROTO(Func1674){ 
int c,n;
BYTE x;
c=DREG(UBITS(9,11,iw))&63;
n=UBITS(0,2,iw);
x=LDREG_BYTE(n);
#if SHWRAP32
if (c>=32)
{
	sr &= ~(MASK_CC|MASK_CC_X);
	if (x&1) sr |= (MASK_CC_X|MASK_CC_C);
	if (x) sr |= MASK_CC_V;
	SET_NZ(0);
	x=0;
}
else
#endif
{ 
sr &= ~MASK_CC|MASK_CC_X;
{
	if (c>0)
	{
		sr &= ~MASK_CC_X;
#if 0
		if ((x << (c-1))<0) sr |= (MASK_CC_X|MASK_CC_C); /* bug ? */
#else
		if ((x>>(8*SIZEBYTE-c))&1) sr |= (MASK_CC_C|MASK_CC_X);
#endif
		if ((x&(x+(1<<(c-1))))&~((1<<(8*SIZEBYTE-1-c))-1)) sr |= MASK_CC_V;
		x <<= c;
	}
}
SET_NZ((LONG)x);
; }
SDREG_BYTE(n,x);
THREAD
; }
GENFUNC_PROTO(Func1675){ 
int c,n;
BYTE x;
c=DREG(UBITS(9,11,iw))&63;
n=UBITS(0,2,iw);
x=LDREG_BYTE(n);
#if SHWRAP32
if (c>=32)
{
	sr &= ~(MASK_CC|MASK_CC_X);
	if (x&1) sr |= (MASK_CC_C|MASK_CC_X);
	SET_NZ(0);
	x=0;
}
else
#endif
{ 
{ BYTE y;
sr &= ~MASK_CC|MASK_CC_X;
if (c>0)
{
	sr &= ~(MASK_CC_X);
#if 0
	if ((x << (c-1))<0) sr |= (MASK_CC_C|MASK_CC_X);
#else
	if ((x>>(8*SIZEBYTE-c))&1) sr |= (MASK_CC_C|MASK_CC_X);
#endif
	x <<= c;
}
y=(BYTE)x;
SET_NZ(y);
}
; }
SDREG_BYTE(n,x);
THREAD
; }
GENFUNC_PROTO(Func1676){ 
int c,n;
UBYTE x;
c=DREG(UBITS(9,11,iw))&63;
n=UBITS(0,2,iw);
x=LDREG_UBYTE(n);

{
BYTE y;
int t,tt;
sr &= ~MASK_CC|MASK_CC_X;
t=GET_X_BIT();
if (c>0)
{
	unsigned int top;
	top = x>>(8*SIZEBYTE-c);	/* bits that are rotated out */
	sr &= ~MASK_CC_X;
	x <<= c;
	x |= t << (c-1);
	x |= top >> 1;
	t = top & 1;
	sr |= t << 4;

}
sr |= t;
y=(BYTE)x;
SET_NZ(y);
}
;
SDREG_UBYTE(n,x);
THREAD
; }
GENFUNC_PROTO(Func1677){ 
int c,n;
BYTE x;
c=DREG(UBITS(9,11,iw))&(8*SIZEBYTE-1);
n=UBITS(0,2,iw);
x=LDREG_BYTE(n);

{ BYTE y;
sr &= ~MASK_CC|MASK_CC_X;
if (c>0)
{
	unsigned long t;
	t = x&MASKBYTE;
	t >>= (8*SIZEBYTE-c);
	if (t&1) sr |= MASK_CC_C;
	x <<= c;
	x |= t;
}
y=(BYTE)x;
SET_NZ(y);
}
;
SDREG_BYTE(n,x);
THREAD
; }
GENFUNC_PROTO(Func1678){ 
int c=8,n=UBITS(0,2,iw);
WORD x;
x=LDREG_WORD(n);

sr &= ~MASK_CC|MASK_CC_X;
{
	if (c>0)
	{
		sr &= ~MASK_CC_X;
#if 0
		if ((x << (c-1))<0) sr |= (MASK_CC_X|MASK_CC_C); /* bug ? */
#else
		if ((x>>(8*SIZEWORD-c))&1) sr |= (MASK_CC_C|MASK_CC_X);
#endif
		if ((x&(x+(1<<(c-1))))&~((1<<(8*SIZEWORD-1-c))-1)) sr |= MASK_CC_V;
		x <<= c;
	}
}
SET_NZ((LONG)x);
;
SDREG_WORD(n,x);
THREAD
; }
GENFUNC_PROTO(Func1679){ 
int c=8,n=UBITS(0,2,iw);
WORD x;
x=LDREG_WORD(n);

{ WORD y;
sr &= ~MASK_CC|MASK_CC_X;
if (c>0)
{
	sr &= ~(MASK_CC_X);
#if 0
	if ((x << (c-1))<0) sr |= (MASK_CC_C|MASK_CC_X);
#else
	if ((x>>(8*SIZEWORD-c))&1) sr |= (MASK_CC_C|MASK_CC_X);
#endif
	x <<= c;
}
y=(WORD)x;
SET_NZ(y);
}
;
SDREG_WORD(n,x);
THREAD
; }
GENFUNC_PROTO(Func1680){ 
int c=8,n=UBITS(0,2,iw);
UWORD x;
x=LDREG_UWORD(n);

{
WORD y;
int t,tt;
sr &= ~MASK_CC|MASK_CC_X;
t=GET_X_BIT();
if (c>0)
{
	unsigned int top;
	top = x>>(8*SIZEWORD-c);	/* bits that are rotated out */
	sr &= ~MASK_CC_X;
	x <<= c;
	x |= t << (c-1);
	x |= top >> 1;
	t = top & 1;
	sr |= t << 4;

}
sr |= t;
y=(WORD)x;
SET_NZ(y);
}
;
SDREG_UWORD(n,x);
THREAD
; }
GENFUNC_PROTO(Func1681){ 
int c=8,n=UBITS(0,2,iw);
WORD x;
x=LDREG_WORD(n);

{ WORD y;
sr &= ~MASK_CC|MASK_CC_X;
if (c>0)
{
	unsigned long t;
	t = x&MASKWORD;
	t >>= (8*SIZEWORD-c);
	if (t&1) sr |= MASK_CC_C;
	x <<= c;
	x |= t;
}
y=(WORD)x;
SET_NZ(y);
}
;
SDREG_WORD(n,x);
THREAD
; }
GENFUNC_PROTO(Func1682){ 
int c,n;
WORD x;
c=DREG(UBITS(9,11,iw))&63;
n=UBITS(0,2,iw);
x=LDREG_WORD(n);
#if SHWRAP32
if (c>=32)
{
	sr &= ~(MASK_CC|MASK_CC_X);
	if (x&1) sr |= (MASK_CC_X|MASK_CC_C);
	if (x) sr |= MASK_CC_V;
	SET_NZ(0);
	x=0;
}
else
#endif
{ 
sr &= ~MASK_CC|MASK_CC_X;
{
	if (c>0)
	{
		sr &= ~MASK_CC_X;
#if 0
		if ((x << (c-1))<0) sr |= (MASK_CC_X|MASK_CC_C); /* bug ? */
#else
		if ((x>>(8*SIZEWORD-c))&1) sr |= (MASK_CC_C|MASK_CC_X);
#endif
		if ((x&(x+(1<<(c-1))))&~((1<<(8*SIZEWORD-1-c))-1)) sr |= MASK_CC_V;
		x <<= c;
	}
}
SET_NZ((LONG)x);
; }
SDREG_WORD(n,x);
THREAD
; }
GENFUNC_PROTO(Func1683){ 
int c,n;
WORD x;
c=DREG(UBITS(9,11,iw))&63;
n=UBITS(0,2,iw);
x=LDREG_WORD(n);
#if SHWRAP32
if (c>=32)
{
	sr &= ~(MASK_CC|MASK_CC_X);
	if (x&1) sr |= (MASK_CC_C|MASK_CC_X);
	SET_NZ(0);
	x=0;
}
else
#endif
{ 
{ WORD y;
sr &= ~MASK_CC|MASK_CC_X;
if (c>0)
{
	sr &= ~(MASK_CC_X);
#if 0
	if ((x << (c-1))<0) sr |= (MASK_CC_C|MASK_CC_X);
#else
	if ((x>>(8*SIZEWORD-c))&1) sr |= (MASK_CC_C|MASK_CC_X);
#endif
	x <<= c;
}
y=(WORD)x;
SET_NZ(y);
}
; }
SDREG_WORD(n,x);
THREAD
; }
GENFUNC_PROTO(Func1684){ 
int c,n;
UWORD x;
c=DREG(UBITS(9,11,iw))&63;
n=UBITS(0,2,iw);
x=LDREG_UWORD(n);

{
WORD y;
int t,tt;
sr &= ~MASK_CC|MASK_CC_X;
t=GET_X_BIT();
if (c>0)
{
	unsigned int top;
	top = x>>(8*SIZEWORD-c);	/* bits that are rotated out */
	sr &= ~MASK_CC_X;
	x <<= c;
	x |= t << (c-1);
	x |= top >> 1;
	t = top & 1;
	sr |= t << 4;

}
sr |= t;
y=(WORD)x;
SET_NZ(y);
}
;
SDREG_UWORD(n,x);
THREAD
; }
GENFUNC_PROTO(Func1685){ 
int c,n;
WORD x;
c=DREG(UBITS(9,11,iw))&(8*SIZEWORD-1);
n=UBITS(0,2,iw);
x=LDREG_WORD(n);

{ WORD y;
sr &= ~MASK_CC|MASK_CC_X;
if (c>0)
{
	unsigned long t;
	t = x&MASKWORD;
	t >>= (8*SIZEWORD-c);
	if (t&1) sr |= MASK_CC_C;
	x <<= c;
	x |= t;
}
y=(WORD)x;
SET_NZ(y);
}
;
SDREG_WORD(n,x);
THREAD
; }
GENFUNC_PROTO(Func1686){ 
int c=8,n=UBITS(0,2,iw);
LONG x;
x=LDREG_LONG(n);

sr &= ~MASK_CC|MASK_CC_X;
{
	if (c>0)
	{
		sr &= ~MASK_CC_X;
#if 0
		if ((x << (c-1))<0) sr |= (MASK_CC_X|MASK_CC_C); /* bug ? */
#else
		if ((x>>(8*SIZELONG-c))&1) sr |= (MASK_CC_C|MASK_CC_X);
#endif
		if ((x&(x+(1<<(c-1))))&~((1<<(8*SIZELONG-1-c))-1)) sr |= MASK_CC_V;
		x <<= c;
	}
}
SET_NZ((LONG)x);
;
SDREG_LONG(n,x);
THREAD
; }
GENFUNC_PROTO(Func1687){ 
int c=8,n=UBITS(0,2,iw);
LONG x;
x=LDREG_LONG(n);

{ LONG y;
sr &= ~MASK_CC|MASK_CC_X;
if (c>0)
{
	sr &= ~(MASK_CC_X);
#if 0
	if ((x << (c-1))<0) sr |= (MASK_CC_C|MASK_CC_X);
#else
	if ((x>>(8*SIZELONG-c))&1) sr |= (MASK_CC_C|MASK_CC_X);
#endif
	x <<= c;
}
y=(LONG)x;
SET_NZ(y);
}
;
SDREG_LONG(n,x);
THREAD
; }
GENFUNC_PROTO(Func1688){ 
int c=8,n=UBITS(0,2,iw);
ULONG x;
x=LDREG_ULONG(n);

{
LONG y;
int t,tt;
sr &= ~MASK_CC|MASK_CC_X;
t=GET_X_BIT();
if (c>0)
{
	unsigned int top;
	top = x>>(8*SIZELONG-c);	/* bits that are rotated out */
	sr &= ~MASK_CC_X;
	x <<= c;
	x |= t << (c-1);
	x |= top >> 1;
	t = top & 1;
	sr |= t << 4;

}
sr |= t;
y=(LONG)x;
SET_NZ(y);
}
;
SDREG_ULONG(n,x);
THREAD
; }
GENFUNC_PROTO(Func1689){ 
int c=8,n=UBITS(0,2,iw);
LONG x;
x=LDREG_LONG(n);

{ LONG y;
sr &= ~MASK_CC|MASK_CC_X;
if (c>0)
{
	unsigned long t;
	t = x&MASKLONG;
	t >>= (8*SIZELONG-c);
	if (t&1) sr |= MASK_CC_C;
	x <<= c;
	x |= t;
}
y=(LONG)x;
SET_NZ(y);
}
;
SDREG_LONG(n,x);
THREAD
; }
GENFUNC_PROTO(Func1690){ 
int c,n;
LONG x;
c=DREG(UBITS(9,11,iw))&63;
n=UBITS(0,2,iw);
x=LDREG_LONG(n);
#if SHWRAP32
if (c>=32)
{
	sr &= ~(MASK_CC|MASK_CC_X);
	if (x&1) sr |= (MASK_CC_X|MASK_CC_C);
	if (x) sr |= MASK_CC_V;
	SET_NZ(0);
	x=0;
}
else
#endif
{ 
sr &= ~MASK_CC|MASK_CC_X;
{
	if (c>0)
	{
		sr &= ~MASK_CC_X;
#if 0
		if ((x << (c-1))<0) sr |= (MASK_CC_X|MASK_CC_C); /* bug ? */
#else
		if ((x>>(8*SIZELONG-c))&1) sr |= (MASK_CC_C|MASK_CC_X);
#endif
		if ((x&(x+(1<<(c-1))))&~((1<<(8*SIZELONG-1-c))-1)) sr |= MASK_CC_V;
		x <<= c;
	}
}
SET_NZ((LONG)x);
; }
SDREG_LONG(n,x);
THREAD
; }
GENFUNC_PROTO(Func1691){ 
int c,n;
LONG x;
c=DREG(UBITS(9,11,iw))&63;
n=UBITS(0,2,iw);
x=LDREG_LONG(n);
#if SHWRAP32
if (c>=32)
{
	sr &= ~(MASK_CC|MASK_CC_X);
	if (x&1) sr |= (MASK_CC_C|MASK_CC_X);
	SET_NZ(0);
	x=0;
}
else
#endif
{ 
{ LONG y;
sr &= ~MASK_CC|MASK_CC_X;
if (c>0)
{
	sr &= ~(MASK_CC_X);
#if 0
	if ((x << (c-1))<0) sr |= (MASK_CC_C|MASK_CC_X);
#else
	if ((x>>(8*SIZELONG-c))&1) sr |= (MASK_CC_C|MASK_CC_X);
#endif
	x <<= c;
}
y=(LONG)x;
SET_NZ(y);
}
; }
SDREG_LONG(n,x);
THREAD
; }
GENFUNC_PROTO(Func1692){ 
int c,n;
ULONG x;
c=DREG(UBITS(9,11,iw))&63;
n=UBITS(0,2,iw);
x=LDREG_ULONG(n);

{
LONG y;
int t,tt;
sr &= ~MASK_CC|MASK_CC_X;
t=GET_X_BIT();
if (c>0)
{
	unsigned int top;
	top = x>>(8*SIZELONG-c);	/* bits that are rotated out */
	sr &= ~MASK_CC_X;
	x <<= c;
	x |= t << (c-1);
	x |= top >> 1;
	t = top & 1;
	sr |= t << 4;

}
sr |= t;
y=(LONG)x;
SET_NZ(y);
}
;
SDREG_ULONG(n,x);
THREAD
; }
GENFUNC_PROTO(Func1693){ 
int c,n;
LONG x;
c=DREG(UBITS(9,11,iw))&(8*SIZELONG-1);
n=UBITS(0,2,iw);
x=LDREG_LONG(n);

{ LONG y;
sr &= ~MASK_CC|MASK_CC_X;
if (c>0)
{
	unsigned long t;
	t = x&MASKLONG;
	t >>= (8*SIZELONG-c);
	if (t&1) sr |= MASK_CC_C;
	x <<= c;
	x |= t;
}
y=(LONG)x;
SET_NZ(y);
}
;
SDREG_LONG(n,x);
THREAD
; }
GENFUNC_PROTO(Func1694){ 
WORD x;
{UL v_x=V_AN_I_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;

sr &= ~MASK_CC|MASK_CC_X;
{
	if (1>0)
	{
		sr &= ~MASK_CC_X;
#if 0
		if ((x << (1-1))<0) sr |= (MASK_CC_X|MASK_CC_C); /* bug ? */
#else
		if ((x>>(8*SIZEWORD-1))&1) sr |= (MASK_CC_C|MASK_CC_X);
#endif
		if ((x&(x+(1<<(1-1))))&~((1<<(8*SIZEWORD-1-1))-1)) sr |= MASK_CC_V;
		x <<= 1;
	}
}
SET_NZ((LONG)x);
;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1695){ 
WORD x;
{UL v_x=V_AN_PI_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;

sr &= ~MASK_CC|MASK_CC_X;
{
	if (1>0)
	{
		sr &= ~MASK_CC_X;
#if 0
		if ((x << (1-1))<0) sr |= (MASK_CC_X|MASK_CC_C); /* bug ? */
#else
		if ((x>>(8*SIZEWORD-1))&1) sr |= (MASK_CC_C|MASK_CC_X);
#endif
		if ((x&(x+(1<<(1-1))))&~((1<<(8*SIZEWORD-1-1))-1)) sr |= MASK_CC_V;
		x <<= 1;
	}
}
SET_NZ((LONG)x);
;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1696){ 
WORD x;
{UL v_x=V_AN_PD_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;

sr &= ~MASK_CC|MASK_CC_X;
{
	if (1>0)
	{
		sr &= ~MASK_CC_X;
#if 0
		if ((x << (1-1))<0) sr |= (MASK_CC_X|MASK_CC_C); /* bug ? */
#else
		if ((x>>(8*SIZEWORD-1))&1) sr |= (MASK_CC_C|MASK_CC_X);
#endif
		if ((x&(x+(1<<(1-1))))&~((1<<(8*SIZEWORD-1-1))-1)) sr |= MASK_CC_V;
		x <<= 1;
	}
}
SET_NZ((LONG)x);
;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1697){ 
WORD x;
{UL v_x=V_AN_D_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;

sr &= ~MASK_CC|MASK_CC_X;
{
	if (1>0)
	{
		sr &= ~MASK_CC_X;
#if 0
		if ((x << (1-1))<0) sr |= (MASK_CC_X|MASK_CC_C); /* bug ? */
#else
		if ((x>>(8*SIZEWORD-1))&1) sr |= (MASK_CC_C|MASK_CC_X);
#endif
		if ((x&(x+(1<<(1-1))))&~((1<<(8*SIZEWORD-1-1))-1)) sr |= MASK_CC_V;
		x <<= 1;
	}
}
SET_NZ((LONG)x);
;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1698){ 
WORD x;
{UL v_x=V_AN_R_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;

sr &= ~MASK_CC|MASK_CC_X;
{
	if (1>0)
	{
		sr &= ~MASK_CC_X;
#if 0
		if ((x << (1-1))<0) sr |= (MASK_CC_X|MASK_CC_C); /* bug ? */
#else
		if ((x>>(8*SIZEWORD-1))&1) sr |= (MASK_CC_C|MASK_CC_X);
#endif
		if ((x&(x+(1<<(1-1))))&~((1<<(8*SIZEWORD-1-1))-1)) sr |= MASK_CC_V;
		x <<= 1;
	}
}
SET_NZ((LONG)x);
;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1699){ 
WORD x;
{UL v_x=V_ABS_W_WORD(); x=CL_WORD(v_x);;

sr &= ~MASK_CC|MASK_CC_X;
{
	if (1>0)
	{
		sr &= ~MASK_CC_X;
#if 0
		if ((x << (1-1))<0) sr |= (MASK_CC_X|MASK_CC_C); /* bug ? */
#else
		if ((x>>(8*SIZEWORD-1))&1) sr |= (MASK_CC_C|MASK_CC_X);
#endif
		if ((x&(x+(1<<(1-1))))&~((1<<(8*SIZEWORD-1-1))-1)) sr |= MASK_CC_V;
		x <<= 1;
	}
}
SET_NZ((LONG)x);
;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1700){ 
WORD x;
{UL v_x=V_ABS_L_WORD(); x=CL_WORD(v_x);;

sr &= ~MASK_CC|MASK_CC_X;
{
	if (1>0)
	{
		sr &= ~MASK_CC_X;
#if 0
		if ((x << (1-1))<0) sr |= (MASK_CC_X|MASK_CC_C); /* bug ? */
#else
		if ((x>>(8*SIZEWORD-1))&1) sr |= (MASK_CC_C|MASK_CC_X);
#endif
		if ((x&(x+(1<<(1-1))))&~((1<<(8*SIZEWORD-1-1))-1)) sr |= MASK_CC_V;
		x <<= 1;
	}
}
SET_NZ((LONG)x);
;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1701){ 
int c=QBITS(9,11,iw),n=UBITS(0,2,iw);
BYTE x;
x=LDREG_BYTE(n);

sr &= ~MASK_CC|MASK_CC_X;
if (c>0)
{
	sr &= ~MASK_CC_X;
	if ((x>>(c-1))&1) sr |= (MASK_CC_X|MASK_CC_C);
	x>>=c;
}
SET_NZ((LONG)x);
;
SDREG_BYTE(n,x);
THREAD
; }
GENFUNC_PROTO(Func1702){ 
int c=QBITS(9,11,iw),n=UBITS(0,2,iw);
UBYTE x;
x=LDREG_UBYTE(n);

sr &= ~MASK_CC|MASK_CC_X;
if (c>0)
{
	sr &= ~MASK_CC_X;
	if ((x >> (c-1)) & 1) sr |= (MASK_CC_X|MASK_CC_C);
	x>>=c;
}
SET_NZ((LONG)x);
THREAD
;
SDREG_UBYTE(n,x);
THREAD
; }
GENFUNC_PROTO(Func1703){ 
int c=QBITS(9,11,iw),n=UBITS(0,2,iw);
UBYTE x;
x=LDREG_UBYTE(n);

{
BYTE y;
int t;
sr &= ~MASK_CC|MASK_CC_X;
t=GET_X_BIT();
if (c>0)
{
	unsigned int bot,tt;
#if 0
	tt = ((x<<1)|t)<<(8*SIZEBYTE-c);
	x >>= c-1;
	t = x&1;
	sr &= ~MASK_CC_X;
	sr |= t << 4;
	x >>= 1;
	x |= tt;
#else
    tt = (x >> (c-1)) & 1;
	bot = x << (8*SIZEBYTE-c);   /* bits that are rotated out */
	sr &= ~MASK_CC_X;
	x >>= c;
	x |= t << (8*SIZEBYTE-c);
	x |= bot << 1;
	t=tt;
	sr |= t << 4;
#endif
}
sr |= t; /* carry */
y=(BYTE)x;
SET_NZ(y);
}
;
SDREG_UBYTE(n,x);
THREAD
; }
GENFUNC_PROTO(Func1704){ 
int c=QBITS(9,11,iw),n=UBITS(0,2,iw);
UBYTE x;
x=LDREG_UBYTE(n);

{ BYTE y;
sr &= ~MASK_CC|MASK_CC_X;
if (c>0)
{
	int t=x<<((8*SIZEBYTE)-c);
	if ((x >> (c-1)) & 1) sr |= MASK_CC_C;
	x>>=c;
	x|=t;
}
y=(BYTE)x;
SET_NZ(y); /* FIXME */
}
;
SDREG_UBYTE(n,x);
THREAD
; }
GENFUNC_PROTO(Func1705){ 
int c=QBITS(9,11,iw),n=UBITS(0,2,iw);
WORD x;
x=LDREG_WORD(n);

sr &= ~MASK_CC|MASK_CC_X;
if (c>0)
{
	sr &= ~MASK_CC_X;
	if ((x>>(c-1))&1) sr |= (MASK_CC_X|MASK_CC_C);
	x>>=c;
}
SET_NZ((LONG)x);
;
SDREG_WORD(n,x);
THREAD
; }
GENFUNC_PROTO(Func1706){ 
int c=QBITS(9,11,iw),n=UBITS(0,2,iw);
UWORD x;
x=LDREG_UWORD(n);

sr &= ~MASK_CC|MASK_CC_X;
if (c>0)
{
	sr &= ~MASK_CC_X;
	if ((x >> (c-1)) & 1) sr |= (MASK_CC_X|MASK_CC_C);
	x>>=c;
}
SET_NZ((LONG)x);
THREAD
;
SDREG_UWORD(n,x);
THREAD
; }
GENFUNC_PROTO(Func1707){ 
int c=QBITS(9,11,iw),n=UBITS(0,2,iw);
UWORD x;
x=LDREG_UWORD(n);

{
WORD y;
int t;
sr &= ~MASK_CC|MASK_CC_X;
t=GET_X_BIT();
if (c>0)
{
	unsigned int bot,tt;
#if 0
	tt = ((x<<1)|t)<<(8*SIZEWORD-c);
	x >>= c-1;
	t = x&1;
	sr &= ~MASK_CC_X;
	sr |= t << 4;
	x >>= 1;
	x |= tt;
#else
    tt = (x >> (c-1)) & 1;
	bot = x << (8*SIZEWORD-c);   /* bits that are rotated out */
	sr &= ~MASK_CC_X;
	x >>= c;
	x |= t << (8*SIZEWORD-c);
	x |= bot << 1;
	t=tt;
	sr |= t << 4;
#endif
}
sr |= t; /* carry */
y=(WORD)x;
SET_NZ(y);
}
;
SDREG_UWORD(n,x);
THREAD
; }
GENFUNC_PROTO(Func1708){ 
int c=QBITS(9,11,iw),n=UBITS(0,2,iw);
UWORD x;
x=LDREG_UWORD(n);

{ WORD y;
sr &= ~MASK_CC|MASK_CC_X;
if (c>0)
{
	int t=x<<((8*SIZEWORD)-c);
	if ((x >> (c-1)) & 1) sr |= MASK_CC_C;
	x>>=c;
	x|=t;
}
y=(WORD)x;
SET_NZ(y); /* FIXME */
}
;
SDREG_UWORD(n,x);
THREAD
; }
GENFUNC_PROTO(Func1709){ 
int c=QBITS(9,11,iw),n=UBITS(0,2,iw);
LONG x;
x=LDREG_LONG(n);

sr &= ~MASK_CC|MASK_CC_X;
if (c>0)
{
	sr &= ~MASK_CC_X;
	if ((x>>(c-1))&1) sr |= (MASK_CC_X|MASK_CC_C);
	x>>=c;
}
SET_NZ((LONG)x);
;
SDREG_LONG(n,x);
THREAD
; }
GENFUNC_PROTO(Func1710){ 
int c=QBITS(9,11,iw),n=UBITS(0,2,iw);
ULONG x;
x=LDREG_ULONG(n);

sr &= ~MASK_CC|MASK_CC_X;
if (c>0)
{
	sr &= ~MASK_CC_X;
	if ((x >> (c-1)) & 1) sr |= (MASK_CC_X|MASK_CC_C);
	x>>=c;
}
SET_NZ((LONG)x);
THREAD
;
SDREG_ULONG(n,x);
THREAD
; }
GENFUNC_PROTO(Func1711){ 
int c=QBITS(9,11,iw),n=UBITS(0,2,iw);
ULONG x;
x=LDREG_ULONG(n);

{
LONG y;
int t;
sr &= ~MASK_CC|MASK_CC_X;
t=GET_X_BIT();
if (c>0)
{
	unsigned int bot,tt;
#if 0
	tt = ((x<<1)|t)<<(8*SIZELONG-c);
	x >>= c-1;
	t = x&1;
	sr &= ~MASK_CC_X;
	sr |= t << 4;
	x >>= 1;
	x |= tt;
#else
    tt = (x >> (c-1)) & 1;
	bot = x << (8*SIZELONG-c);   /* bits that are rotated out */
	sr &= ~MASK_CC_X;
	x >>= c;
	x |= t << (8*SIZELONG-c);
	x |= bot << 1;
	t=tt;
	sr |= t << 4;
#endif
}
sr |= t; /* carry */
y=(LONG)x;
SET_NZ(y);
}
;
SDREG_ULONG(n,x);
THREAD
; }
GENFUNC_PROTO(Func1712){ 
int c=QBITS(9,11,iw),n=UBITS(0,2,iw);
ULONG x;
x=LDREG_ULONG(n);

{ LONG y;
sr &= ~MASK_CC|MASK_CC_X;
if (c>0)
{
	int t=x<<((8*SIZELONG)-c);
	if ((x >> (c-1)) & 1) sr |= MASK_CC_C;
	x>>=c;
	x|=t;
}
y=(LONG)x;
SET_NZ(y); /* FIXME */
}
;
SDREG_ULONG(n,x);
THREAD
; }
GENFUNC_PROTO(Func1713){ 
UWORD x;
{UL v_x=V_AN_I_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;

sr &= ~MASK_CC|MASK_CC_X;
if (1>0)
{
	sr &= ~MASK_CC_X;
	if ((x >> (1-1)) & 1) sr |= (MASK_CC_X|MASK_CC_C);
	x>>=1;
}
SET_NZ((LONG)x);
THREAD
;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1714){ 
UWORD x;
{UL v_x=V_AN_PI_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;

sr &= ~MASK_CC|MASK_CC_X;
if (1>0)
{
	sr &= ~MASK_CC_X;
	if ((x >> (1-1)) & 1) sr |= (MASK_CC_X|MASK_CC_C);
	x>>=1;
}
SET_NZ((LONG)x);
THREAD
;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1715){ 
UWORD x;
{UL v_x=V_AN_PD_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;

sr &= ~MASK_CC|MASK_CC_X;
if (1>0)
{
	sr &= ~MASK_CC_X;
	if ((x >> (1-1)) & 1) sr |= (MASK_CC_X|MASK_CC_C);
	x>>=1;
}
SET_NZ((LONG)x);
THREAD
;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1716){ 
UWORD x;
{UL v_x=V_AN_D_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;

sr &= ~MASK_CC|MASK_CC_X;
if (1>0)
{
	sr &= ~MASK_CC_X;
	if ((x >> (1-1)) & 1) sr |= (MASK_CC_X|MASK_CC_C);
	x>>=1;
}
SET_NZ((LONG)x);
THREAD
;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1717){ 
UWORD x;
{UL v_x=V_AN_R_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;

sr &= ~MASK_CC|MASK_CC_X;
if (1>0)
{
	sr &= ~MASK_CC_X;
	if ((x >> (1-1)) & 1) sr |= (MASK_CC_X|MASK_CC_C);
	x>>=1;
}
SET_NZ((LONG)x);
THREAD
;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1718){ 
UWORD x;
{UL v_x=V_ABS_W_WORD(); x=CL_WORD(v_x);;

sr &= ~MASK_CC|MASK_CC_X;
if (1>0)
{
	sr &= ~MASK_CC_X;
	if ((x >> (1-1)) & 1) sr |= (MASK_CC_X|MASK_CC_C);
	x>>=1;
}
SET_NZ((LONG)x);
THREAD
;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1719){ 
UWORD x;
{UL v_x=V_ABS_L_WORD(); x=CL_WORD(v_x);;

sr &= ~MASK_CC|MASK_CC_X;
if (1>0)
{
	sr &= ~MASK_CC_X;
	if ((x >> (1-1)) & 1) sr |= (MASK_CC_X|MASK_CC_C);
	x>>=1;
}
SET_NZ((LONG)x);
THREAD
;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1720){ 
int c=QBITS(9,11,iw),n=UBITS(0,2,iw);
BYTE x;
x=LDREG_BYTE(n);

sr &= ~MASK_CC|MASK_CC_X;
{
	if (c>0)
	{
		sr &= ~MASK_CC_X;
#if 0
		if ((x << (c-1))<0) sr |= (MASK_CC_X|MASK_CC_C); /* bug ? */
#else
		if ((x>>(8*SIZEBYTE-c))&1) sr |= (MASK_CC_C|MASK_CC_X);
#endif
		if ((x&(x+(1<<(c-1))))&~((1<<(8*SIZEBYTE-1-c))-1)) sr |= MASK_CC_V;
		x <<= c;
	}
}
SET_NZ((LONG)x);
;
SDREG_BYTE(n,x);
THREAD
; }
GENFUNC_PROTO(Func1721){ 
int c=QBITS(9,11,iw),n=UBITS(0,2,iw);
BYTE x;
x=LDREG_BYTE(n);

{ BYTE y;
sr &= ~MASK_CC|MASK_CC_X;
if (c>0)
{
	sr &= ~(MASK_CC_X);
#if 0
	if ((x << (c-1))<0) sr |= (MASK_CC_C|MASK_CC_X);
#else
	if ((x>>(8*SIZEBYTE-c))&1) sr |= (MASK_CC_C|MASK_CC_X);
#endif
	x <<= c;
}
y=(BYTE)x;
SET_NZ(y);
}
;
SDREG_BYTE(n,x);
THREAD
; }
GENFUNC_PROTO(Func1722){ 
int c=QBITS(9,11,iw),n=UBITS(0,2,iw);
UBYTE x;
x=LDREG_UBYTE(n);

{
BYTE y;
int t,tt;
sr &= ~MASK_CC|MASK_CC_X;
t=GET_X_BIT();
if (c>0)
{
	unsigned int top;
	top = x>>(8*SIZEBYTE-c);	/* bits that are rotated out */
	sr &= ~MASK_CC_X;
	x <<= c;
	x |= t << (c-1);
	x |= top >> 1;
	t = top & 1;
	sr |= t << 4;

}
sr |= t;
y=(BYTE)x;
SET_NZ(y);
}
;
SDREG_UBYTE(n,x);
THREAD
; }
GENFUNC_PROTO(Func1723){ 
int c=QBITS(9,11,iw),n=UBITS(0,2,iw);
BYTE x;
x=LDREG_BYTE(n);

{ BYTE y;
sr &= ~MASK_CC|MASK_CC_X;
if (c>0)
{
	unsigned long t;
	t = x&MASKBYTE;
	t >>= (8*SIZEBYTE-c);
	if (t&1) sr |= MASK_CC_C;
	x <<= c;
	x |= t;
}
y=(BYTE)x;
SET_NZ(y);
}
;
SDREG_BYTE(n,x);
THREAD
; }
GENFUNC_PROTO(Func1724){ 
int c=QBITS(9,11,iw),n=UBITS(0,2,iw);
WORD x;
x=LDREG_WORD(n);

sr &= ~MASK_CC|MASK_CC_X;
{
	if (c>0)
	{
		sr &= ~MASK_CC_X;
#if 0
		if ((x << (c-1))<0) sr |= (MASK_CC_X|MASK_CC_C); /* bug ? */
#else
		if ((x>>(8*SIZEWORD-c))&1) sr |= (MASK_CC_C|MASK_CC_X);
#endif
		if ((x&(x+(1<<(c-1))))&~((1<<(8*SIZEWORD-1-c))-1)) sr |= MASK_CC_V;
		x <<= c;
	}
}
SET_NZ((LONG)x);
;
SDREG_WORD(n,x);
THREAD
; }
GENFUNC_PROTO(Func1725){ 
int c=QBITS(9,11,iw),n=UBITS(0,2,iw);
WORD x;
x=LDREG_WORD(n);

{ WORD y;
sr &= ~MASK_CC|MASK_CC_X;
if (c>0)
{
	sr &= ~(MASK_CC_X);
#if 0
	if ((x << (c-1))<0) sr |= (MASK_CC_C|MASK_CC_X);
#else
	if ((x>>(8*SIZEWORD-c))&1) sr |= (MASK_CC_C|MASK_CC_X);
#endif
	x <<= c;
}
y=(WORD)x;
SET_NZ(y);
}
;
SDREG_WORD(n,x);
THREAD
; }
GENFUNC_PROTO(Func1726){ 
int c=QBITS(9,11,iw),n=UBITS(0,2,iw);
UWORD x;
x=LDREG_UWORD(n);

{
WORD y;
int t,tt;
sr &= ~MASK_CC|MASK_CC_X;
t=GET_X_BIT();
if (c>0)
{
	unsigned int top;
	top = x>>(8*SIZEWORD-c);	/* bits that are rotated out */
	sr &= ~MASK_CC_X;
	x <<= c;
	x |= t << (c-1);
	x |= top >> 1;
	t = top & 1;
	sr |= t << 4;

}
sr |= t;
y=(WORD)x;
SET_NZ(y);
}
;
SDREG_UWORD(n,x);
THREAD
; }
GENFUNC_PROTO(Func1727){ 
int c=QBITS(9,11,iw),n=UBITS(0,2,iw);
WORD x;
x=LDREG_WORD(n);

{ WORD y;
sr &= ~MASK_CC|MASK_CC_X;
if (c>0)
{
	unsigned long t;
	t = x&MASKWORD;
	t >>= (8*SIZEWORD-c);
	if (t&1) sr |= MASK_CC_C;
	x <<= c;
	x |= t;
}
y=(WORD)x;
SET_NZ(y);
}
;
SDREG_WORD(n,x);
THREAD
; }
GENFUNC_PROTO(Func1728){ 
int c=QBITS(9,11,iw),n=UBITS(0,2,iw);
LONG x;
x=LDREG_LONG(n);

sr &= ~MASK_CC|MASK_CC_X;
{
	if (c>0)
	{
		sr &= ~MASK_CC_X;
#if 0
		if ((x << (c-1))<0) sr |= (MASK_CC_X|MASK_CC_C); /* bug ? */
#else
		if ((x>>(8*SIZELONG-c))&1) sr |= (MASK_CC_C|MASK_CC_X);
#endif
		if ((x&(x+(1<<(c-1))))&~((1<<(8*SIZELONG-1-c))-1)) sr |= MASK_CC_V;
		x <<= c;
	}
}
SET_NZ((LONG)x);
;
SDREG_LONG(n,x);
THREAD
; }
GENFUNC_PROTO(Func1729){ 
int c=QBITS(9,11,iw),n=UBITS(0,2,iw);
LONG x;
x=LDREG_LONG(n);

{ LONG y;
sr &= ~MASK_CC|MASK_CC_X;
if (c>0)
{
	sr &= ~(MASK_CC_X);
#if 0
	if ((x << (c-1))<0) sr |= (MASK_CC_C|MASK_CC_X);
#else
	if ((x>>(8*SIZELONG-c))&1) sr |= (MASK_CC_C|MASK_CC_X);
#endif
	x <<= c;
}
y=(LONG)x;
SET_NZ(y);
}
;
SDREG_LONG(n,x);
THREAD
; }
GENFUNC_PROTO(Func1730){ 
int c=QBITS(9,11,iw),n=UBITS(0,2,iw);
ULONG x;
x=LDREG_ULONG(n);

{
LONG y;
int t,tt;
sr &= ~MASK_CC|MASK_CC_X;
t=GET_X_BIT();
if (c>0)
{
	unsigned int top;
	top = x>>(8*SIZELONG-c);	/* bits that are rotated out */
	sr &= ~MASK_CC_X;
	x <<= c;
	x |= t << (c-1);
	x |= top >> 1;
	t = top & 1;
	sr |= t << 4;

}
sr |= t;
y=(LONG)x;
SET_NZ(y);
}
;
SDREG_ULONG(n,x);
THREAD
; }
GENFUNC_PROTO(Func1731){ 
int c=QBITS(9,11,iw),n=UBITS(0,2,iw);
LONG x;
x=LDREG_LONG(n);

{ LONG y;
sr &= ~MASK_CC|MASK_CC_X;
if (c>0)
{
	unsigned long t;
	t = x&MASKLONG;
	t >>= (8*SIZELONG-c);
	if (t&1) sr |= MASK_CC_C;
	x <<= c;
	x |= t;
}
y=(LONG)x;
SET_NZ(y);
}
;
SDREG_LONG(n,x);
THREAD
; }
GENFUNC_PROTO(Func1732){ 
WORD x;
{UL v_x=V_AN_I_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;

{ WORD y;
sr &= ~MASK_CC|MASK_CC_X;
if (1>0)
{
	sr &= ~(MASK_CC_X);
#if 0
	if ((x << (1-1))<0) sr |= (MASK_CC_C|MASK_CC_X);
#else
	if ((x>>(8*SIZEWORD-1))&1) sr |= (MASK_CC_C|MASK_CC_X);
#endif
	x <<= 1;
}
y=(WORD)x;
SET_NZ(y);
}
;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1733){ 
WORD x;
{UL v_x=V_AN_PI_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;

{ WORD y;
sr &= ~MASK_CC|MASK_CC_X;
if (1>0)
{
	sr &= ~(MASK_CC_X);
#if 0
	if ((x << (1-1))<0) sr |= (MASK_CC_C|MASK_CC_X);
#else
	if ((x>>(8*SIZEWORD-1))&1) sr |= (MASK_CC_C|MASK_CC_X);
#endif
	x <<= 1;
}
y=(WORD)x;
SET_NZ(y);
}
;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1734){ 
WORD x;
{UL v_x=V_AN_PD_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;

{ WORD y;
sr &= ~MASK_CC|MASK_CC_X;
if (1>0)
{
	sr &= ~(MASK_CC_X);
#if 0
	if ((x << (1-1))<0) sr |= (MASK_CC_C|MASK_CC_X);
#else
	if ((x>>(8*SIZEWORD-1))&1) sr |= (MASK_CC_C|MASK_CC_X);
#endif
	x <<= 1;
}
y=(WORD)x;
SET_NZ(y);
}
;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1735){ 
WORD x;
{UL v_x=V_AN_D_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;

{ WORD y;
sr &= ~MASK_CC|MASK_CC_X;
if (1>0)
{
	sr &= ~(MASK_CC_X);
#if 0
	if ((x << (1-1))<0) sr |= (MASK_CC_C|MASK_CC_X);
#else
	if ((x>>(8*SIZEWORD-1))&1) sr |= (MASK_CC_C|MASK_CC_X);
#endif
	x <<= 1;
}
y=(WORD)x;
SET_NZ(y);
}
;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1736){ 
WORD x;
{UL v_x=V_AN_R_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;

{ WORD y;
sr &= ~MASK_CC|MASK_CC_X;
if (1>0)
{
	sr &= ~(MASK_CC_X);
#if 0
	if ((x << (1-1))<0) sr |= (MASK_CC_C|MASK_CC_X);
#else
	if ((x>>(8*SIZEWORD-1))&1) sr |= (MASK_CC_C|MASK_CC_X);
#endif
	x <<= 1;
}
y=(WORD)x;
SET_NZ(y);
}
;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1737){ 
WORD x;
{UL v_x=V_ABS_W_WORD(); x=CL_WORD(v_x);;

{ WORD y;
sr &= ~MASK_CC|MASK_CC_X;
if (1>0)
{
	sr &= ~(MASK_CC_X);
#if 0
	if ((x << (1-1))<0) sr |= (MASK_CC_C|MASK_CC_X);
#else
	if ((x>>(8*SIZEWORD-1))&1) sr |= (MASK_CC_C|MASK_CC_X);
#endif
	x <<= 1;
}
y=(WORD)x;
SET_NZ(y);
}
;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1738){ 
WORD x;
{UL v_x=V_ABS_L_WORD(); x=CL_WORD(v_x);;

{ WORD y;
sr &= ~MASK_CC|MASK_CC_X;
if (1>0)
{
	sr &= ~(MASK_CC_X);
#if 0
	if ((x << (1-1))<0) sr |= (MASK_CC_C|MASK_CC_X);
#else
	if ((x>>(8*SIZEWORD-1))&1) sr |= (MASK_CC_C|MASK_CC_X);
#endif
	x <<= 1;
}
y=(WORD)x;
SET_NZ(y);
}
;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1739){ 
UWORD x;
{UL v_x=V_AN_I_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;

{
WORD y;
int t;
sr &= ~MASK_CC|MASK_CC_X;
t=GET_X_BIT();
if (1>0)
{
	unsigned int bot,tt;
#if 0
	tt = ((x<<1)|t)<<(8*SIZEWORD-1);
	x >>= 1-1;
	t = x&1;
	sr &= ~MASK_CC_X;
	sr |= t << 4;
	x >>= 1;
	x |= tt;
#else
    tt = (x >> (1-1)) & 1;
	bot = x << (8*SIZEWORD-1);   /* bits that are rotated out */
	sr &= ~MASK_CC_X;
	x >>= 1;
	x |= t << (8*SIZEWORD-1);
	x |= bot << 1;
	t=tt;
	sr |= t << 4;
#endif
}
sr |= t; /* carry */
y=(WORD)x;
SET_NZ(y);
}
;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1740){ 
UWORD x;
{UL v_x=V_AN_PI_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;

{
WORD y;
int t;
sr &= ~MASK_CC|MASK_CC_X;
t=GET_X_BIT();
if (1>0)
{
	unsigned int bot,tt;
#if 0
	tt = ((x<<1)|t)<<(8*SIZEWORD-1);
	x >>= 1-1;
	t = x&1;
	sr &= ~MASK_CC_X;
	sr |= t << 4;
	x >>= 1;
	x |= tt;
#else
    tt = (x >> (1-1)) & 1;
	bot = x << (8*SIZEWORD-1);   /* bits that are rotated out */
	sr &= ~MASK_CC_X;
	x >>= 1;
	x |= t << (8*SIZEWORD-1);
	x |= bot << 1;
	t=tt;
	sr |= t << 4;
#endif
}
sr |= t; /* carry */
y=(WORD)x;
SET_NZ(y);
}
;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1741){ 
UWORD x;
{UL v_x=V_AN_PD_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;

{
WORD y;
int t;
sr &= ~MASK_CC|MASK_CC_X;
t=GET_X_BIT();
if (1>0)
{
	unsigned int bot,tt;
#if 0
	tt = ((x<<1)|t)<<(8*SIZEWORD-1);
	x >>= 1-1;
	t = x&1;
	sr &= ~MASK_CC_X;
	sr |= t << 4;
	x >>= 1;
	x |= tt;
#else
    tt = (x >> (1-1)) & 1;
	bot = x << (8*SIZEWORD-1);   /* bits that are rotated out */
	sr &= ~MASK_CC_X;
	x >>= 1;
	x |= t << (8*SIZEWORD-1);
	x |= bot << 1;
	t=tt;
	sr |= t << 4;
#endif
}
sr |= t; /* carry */
y=(WORD)x;
SET_NZ(y);
}
;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1742){ 
UWORD x;
{UL v_x=V_AN_D_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;

{
WORD y;
int t;
sr &= ~MASK_CC|MASK_CC_X;
t=GET_X_BIT();
if (1>0)
{
	unsigned int bot,tt;
#if 0
	tt = ((x<<1)|t)<<(8*SIZEWORD-1);
	x >>= 1-1;
	t = x&1;
	sr &= ~MASK_CC_X;
	sr |= t << 4;
	x >>= 1;
	x |= tt;
#else
    tt = (x >> (1-1)) & 1;
	bot = x << (8*SIZEWORD-1);   /* bits that are rotated out */
	sr &= ~MASK_CC_X;
	x >>= 1;
	x |= t << (8*SIZEWORD-1);
	x |= bot << 1;
	t=tt;
	sr |= t << 4;
#endif
}
sr |= t; /* carry */
y=(WORD)x;
SET_NZ(y);
}
;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1743){ 
UWORD x;
{UL v_x=V_AN_R_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;

{
WORD y;
int t;
sr &= ~MASK_CC|MASK_CC_X;
t=GET_X_BIT();
if (1>0)
{
	unsigned int bot,tt;
#if 0
	tt = ((x<<1)|t)<<(8*SIZEWORD-1);
	x >>= 1-1;
	t = x&1;
	sr &= ~MASK_CC_X;
	sr |= t << 4;
	x >>= 1;
	x |= tt;
#else
    tt = (x >> (1-1)) & 1;
	bot = x << (8*SIZEWORD-1);   /* bits that are rotated out */
	sr &= ~MASK_CC_X;
	x >>= 1;
	x |= t << (8*SIZEWORD-1);
	x |= bot << 1;
	t=tt;
	sr |= t << 4;
#endif
}
sr |= t; /* carry */
y=(WORD)x;
SET_NZ(y);
}
;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1744){ 
UWORD x;
{UL v_x=V_ABS_W_WORD(); x=CL_WORD(v_x);;

{
WORD y;
int t;
sr &= ~MASK_CC|MASK_CC_X;
t=GET_X_BIT();
if (1>0)
{
	unsigned int bot,tt;
#if 0
	tt = ((x<<1)|t)<<(8*SIZEWORD-1);
	x >>= 1-1;
	t = x&1;
	sr &= ~MASK_CC_X;
	sr |= t << 4;
	x >>= 1;
	x |= tt;
#else
    tt = (x >> (1-1)) & 1;
	bot = x << (8*SIZEWORD-1);   /* bits that are rotated out */
	sr &= ~MASK_CC_X;
	x >>= 1;
	x |= t << (8*SIZEWORD-1);
	x |= bot << 1;
	t=tt;
	sr |= t << 4;
#endif
}
sr |= t; /* carry */
y=(WORD)x;
SET_NZ(y);
}
;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1745){ 
UWORD x;
{UL v_x=V_ABS_L_WORD(); x=CL_WORD(v_x);;

{
WORD y;
int t;
sr &= ~MASK_CC|MASK_CC_X;
t=GET_X_BIT();
if (1>0)
{
	unsigned int bot,tt;
#if 0
	tt = ((x<<1)|t)<<(8*SIZEWORD-1);
	x >>= 1-1;
	t = x&1;
	sr &= ~MASK_CC_X;
	sr |= t << 4;
	x >>= 1;
	x |= tt;
#else
    tt = (x >> (1-1)) & 1;
	bot = x << (8*SIZEWORD-1);   /* bits that are rotated out */
	sr &= ~MASK_CC_X;
	x >>= 1;
	x |= t << (8*SIZEWORD-1);
	x |= bot << 1;
	t=tt;
	sr |= t << 4;
#endif
}
sr |= t; /* carry */
y=(WORD)x;
SET_NZ(y);
}
;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1746){ 
UWORD x;
{UL v_x=V_AN_I_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;

{
WORD y;
int t,tt;
sr &= ~MASK_CC|MASK_CC_X;
t=GET_X_BIT();
if (1>0)
{
	unsigned int top;
	top = x>>(8*SIZEWORD-1);	/* bits that are rotated out */
	sr &= ~MASK_CC_X;
	x <<= 1;
	x |= t << (1-1);
	x |= top >> 1;
	t = top & 1;
	sr |= t << 4;

}
sr |= t;
y=(WORD)x;
SET_NZ(y);
}
;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1747){ 
UWORD x;
{UL v_x=V_AN_PI_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;

{
WORD y;
int t,tt;
sr &= ~MASK_CC|MASK_CC_X;
t=GET_X_BIT();
if (1>0)
{
	unsigned int top;
	top = x>>(8*SIZEWORD-1);	/* bits that are rotated out */
	sr &= ~MASK_CC_X;
	x <<= 1;
	x |= t << (1-1);
	x |= top >> 1;
	t = top & 1;
	sr |= t << 4;

}
sr |= t;
y=(WORD)x;
SET_NZ(y);
}
;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1748){ 
UWORD x;
{UL v_x=V_AN_PD_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;

{
WORD y;
int t,tt;
sr &= ~MASK_CC|MASK_CC_X;
t=GET_X_BIT();
if (1>0)
{
	unsigned int top;
	top = x>>(8*SIZEWORD-1);	/* bits that are rotated out */
	sr &= ~MASK_CC_X;
	x <<= 1;
	x |= t << (1-1);
	x |= top >> 1;
	t = top & 1;
	sr |= t << 4;

}
sr |= t;
y=(WORD)x;
SET_NZ(y);
}
;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1749){ 
UWORD x;
{UL v_x=V_AN_D_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;

{
WORD y;
int t,tt;
sr &= ~MASK_CC|MASK_CC_X;
t=GET_X_BIT();
if (1>0)
{
	unsigned int top;
	top = x>>(8*SIZEWORD-1);	/* bits that are rotated out */
	sr &= ~MASK_CC_X;
	x <<= 1;
	x |= t << (1-1);
	x |= top >> 1;
	t = top & 1;
	sr |= t << 4;

}
sr |= t;
y=(WORD)x;
SET_NZ(y);
}
;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1750){ 
UWORD x;
{UL v_x=V_AN_R_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;

{
WORD y;
int t,tt;
sr &= ~MASK_CC|MASK_CC_X;
t=GET_X_BIT();
if (1>0)
{
	unsigned int top;
	top = x>>(8*SIZEWORD-1);	/* bits that are rotated out */
	sr &= ~MASK_CC_X;
	x <<= 1;
	x |= t << (1-1);
	x |= top >> 1;
	t = top & 1;
	sr |= t << 4;

}
sr |= t;
y=(WORD)x;
SET_NZ(y);
}
;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1751){ 
UWORD x;
{UL v_x=V_ABS_W_WORD(); x=CL_WORD(v_x);;

{
WORD y;
int t,tt;
sr &= ~MASK_CC|MASK_CC_X;
t=GET_X_BIT();
if (1>0)
{
	unsigned int top;
	top = x>>(8*SIZEWORD-1);	/* bits that are rotated out */
	sr &= ~MASK_CC_X;
	x <<= 1;
	x |= t << (1-1);
	x |= top >> 1;
	t = top & 1;
	sr |= t << 4;

}
sr |= t;
y=(WORD)x;
SET_NZ(y);
}
;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1752){ 
UWORD x;
{UL v_x=V_ABS_L_WORD(); x=CL_WORD(v_x);;

{
WORD y;
int t,tt;
sr &= ~MASK_CC|MASK_CC_X;
t=GET_X_BIT();
if (1>0)
{
	unsigned int top;
	top = x>>(8*SIZEWORD-1);	/* bits that are rotated out */
	sr &= ~MASK_CC_X;
	x <<= 1;
	x |= t << (1-1);
	x |= top >> 1;
	t = top & 1;
	sr |= t << 4;

}
sr |= t;
y=(WORD)x;
SET_NZ(y);
}
;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1753){ 
UWORD x;
{UL v_x=V_AN_I_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
x&=0xffff;

{ WORD y;
sr &= ~MASK_CC|MASK_CC_X;
if (1>0)
{
	int t=x<<((8*SIZEWORD)-1);
	if ((x >> (1-1)) & 1) sr |= MASK_CC_C;
	x>>=1;
	x|=t;
}
y=(WORD)x;
SET_NZ(y); /* FIXME */
}
;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1754){ 
UWORD x;
{UL v_x=V_AN_PI_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
x&=0xffff;

{ WORD y;
sr &= ~MASK_CC|MASK_CC_X;
if (1>0)
{
	int t=x<<((8*SIZEWORD)-1);
	if ((x >> (1-1)) & 1) sr |= MASK_CC_C;
	x>>=1;
	x|=t;
}
y=(WORD)x;
SET_NZ(y); /* FIXME */
}
;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1755){ 
UWORD x;
{UL v_x=V_AN_PD_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
x&=0xffff;

{ WORD y;
sr &= ~MASK_CC|MASK_CC_X;
if (1>0)
{
	int t=x<<((8*SIZEWORD)-1);
	if ((x >> (1-1)) & 1) sr |= MASK_CC_C;
	x>>=1;
	x|=t;
}
y=(WORD)x;
SET_NZ(y); /* FIXME */
}
;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1756){ 
UWORD x;
{UL v_x=V_AN_D_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
x&=0xffff;

{ WORD y;
sr &= ~MASK_CC|MASK_CC_X;
if (1>0)
{
	int t=x<<((8*SIZEWORD)-1);
	if ((x >> (1-1)) & 1) sr |= MASK_CC_C;
	x>>=1;
	x|=t;
}
y=(WORD)x;
SET_NZ(y); /* FIXME */
}
;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1757){ 
UWORD x;
{UL v_x=V_AN_R_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;
x&=0xffff;

{ WORD y;
sr &= ~MASK_CC|MASK_CC_X;
if (1>0)
{
	int t=x<<((8*SIZEWORD)-1);
	if ((x >> (1-1)) & 1) sr |= MASK_CC_C;
	x>>=1;
	x|=t;
}
y=(WORD)x;
SET_NZ(y); /* FIXME */
}
;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1758){ 
UWORD x;
{UL v_x=V_ABS_W_WORD(); x=CL_WORD(v_x);;
x&=0xffff;

{ WORD y;
sr &= ~MASK_CC|MASK_CC_X;
if (1>0)
{
	int t=x<<((8*SIZEWORD)-1);
	if ((x >> (1-1)) & 1) sr |= MASK_CC_C;
	x>>=1;
	x|=t;
}
y=(WORD)x;
SET_NZ(y); /* FIXME */
}
;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1759){ 
UWORD x;
{UL v_x=V_ABS_L_WORD(); x=CL_WORD(v_x);;
x&=0xffff;

{ WORD y;
sr &= ~MASK_CC|MASK_CC_X;
if (1>0)
{
	int t=x<<((8*SIZEWORD)-1);
	if ((x >> (1-1)) & 1) sr |= MASK_CC_C;
	x>>=1;
	x|=t;
}
y=(WORD)x;
SET_NZ(y); /* FIXME */
}
;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1760){ 
WORD x;
{UL v_x=V_AN_I_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;

{ WORD y;
sr &= ~MASK_CC|MASK_CC_X;
if (1>0)
{
	unsigned long t;
	t = x&MASKWORD;
	t >>= (8*SIZEWORD-1);
	if (t&1) sr |= MASK_CC_C;
	x <<= 1;
	x |= t;
}
y=(WORD)x;
SET_NZ(y);
}
;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1761){ 
WORD x;
{UL v_x=V_AN_PI_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;

{ WORD y;
sr &= ~MASK_CC|MASK_CC_X;
if (1>0)
{
	unsigned long t;
	t = x&MASKWORD;
	t >>= (8*SIZEWORD-1);
	if (t&1) sr |= MASK_CC_C;
	x <<= 1;
	x |= t;
}
y=(WORD)x;
SET_NZ(y);
}
;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1762){ 
WORD x;
{UL v_x=V_AN_PD_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;

{ WORD y;
sr &= ~MASK_CC|MASK_CC_X;
if (1>0)
{
	unsigned long t;
	t = x&MASKWORD;
	t >>= (8*SIZEWORD-1);
	if (t&1) sr |= MASK_CC_C;
	x <<= 1;
	x |= t;
}
y=(WORD)x;
SET_NZ(y);
}
;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1763){ 
WORD x;
{UL v_x=V_AN_D_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;

{ WORD y;
sr &= ~MASK_CC|MASK_CC_X;
if (1>0)
{
	unsigned long t;
	t = x&MASKWORD;
	t >>= (8*SIZEWORD-1);
	if (t&1) sr |= MASK_CC_C;
	x <<= 1;
	x |= t;
}
y=(WORD)x;
SET_NZ(y);
}
;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1764){ 
WORD x;
{UL v_x=V_AN_R_WORD((UBITS(0,5,iw)&7)); x=CL_WORD(v_x);;

{ WORD y;
sr &= ~MASK_CC|MASK_CC_X;
if (1>0)
{
	unsigned long t;
	t = x&MASKWORD;
	t >>= (8*SIZEWORD-1);
	if (t&1) sr |= MASK_CC_C;
	x <<= 1;
	x |= t;
}
y=(WORD)x;
SET_NZ(y);
}
;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1765){ 
WORD x;
{UL v_x=V_ABS_W_WORD(); x=CL_WORD(v_x);;

{ WORD y;
sr &= ~MASK_CC|MASK_CC_X;
if (1>0)
{
	unsigned long t;
	t = x&MASKWORD;
	t >>= (8*SIZEWORD-1);
	if (t&1) sr |= MASK_CC_C;
	x <<= 1;
	x |= t;
}
y=(WORD)x;
SET_NZ(y);
}
;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1766){ 
WORD x;
{UL v_x=V_ABS_L_WORD(); x=CL_WORD(v_x);;

{ WORD y;
sr &= ~MASK_CC|MASK_CC_X;
if (1>0)
{
	unsigned long t;
	t = x&MASKWORD;
	t >>= (8*SIZEWORD-1);
	if (t&1) sr |= MASK_CC_C;
	x <<= 1;
	x |= t;
}
y=(WORD)x;
SET_NZ(y);
}
;
CS_WORD(v_x,x);};
THREAD
; }
GENFUNC_PROTO(Func1767){ 
pc -= 2;
ex_linef();
THREAD
; }
