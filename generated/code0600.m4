include(gendefs.m4)
GENFUNC_PROTO(Func600){ MOVE(AN_R_WORD,(UBITS(0,5,iw)&7),ABS_L_WORD,); }
GENFUNC_PROTO(Func601){ MOVE(ABS_W_WORD,,ABS_L_WORD,); }
GENFUNC_PROTO(Func602){ MOVE(ABS_L_WORD,,ABS_L_WORD,); }
GENFUNC_PROTO(Func603){ MOVE(PC_D_WORD,,ABS_L_WORD,); }
GENFUNC_PROTO(Func604){ MOVE(PC_R_WORD,,ABS_L_WORD,); }
GENFUNC_PROTO(Func605){ MOVE(IMM_WORD,,ABS_L_WORD,); }
GENFUNC_PROTO(Func606){ NEGX(BYTE,DREG_BYTE,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func607){ NEGX(BYTE,AN_I_BYTE,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func608){ NEGX(BYTE,AN_PI_BYTE,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func609){ NEGX(BYTE,AN_PI_BYTE_All,7); }
GENFUNC_PROTO(Func610){ NEGX(BYTE,AN_PD_BYTE,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func611){ NEGX(BYTE,AN_PD_BYTE_All,7); }
GENFUNC_PROTO(Func612){ NEGX(BYTE,AN_D_BYTE,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func613){ NEGX(BYTE,AN_R_BYTE,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func614){ NEGX(BYTE,ABS_W_BYTE,); }
GENFUNC_PROTO(Func615){ NEGX(BYTE,ABS_L_BYTE,); }
GENFUNC_PROTO(Func616){ NEGX(WORD,DREG_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func617){ NEGX(WORD,AN_I_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func618){ NEGX(WORD,AN_PI_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func619){ NEGX(WORD,AN_PD_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func620){ NEGX(WORD,AN_D_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func621){ NEGX(WORD,AN_R_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func622){ NEGX(WORD,ABS_W_WORD,); }
GENFUNC_PROTO(Func623){ NEGX(WORD,ABS_L_WORD,); }
GENFUNC_PROTO(Func624){ NEGX(LONG,DREG_LONG,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func625){ NEGX(LONG,AN_I_LONG,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func626){ NEGX(LONG,AN_PI_LONG,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func627){ NEGX(LONG,AN_PD_LONG,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func628){ NEGX(LONG,AN_D_LONG,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func629){ NEGX(LONG,AN_R_LONG,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func630){ NEGX(LONG,ABS_W_LONG,); }
GENFUNC_PROTO(Func631){ NEGX(LONG,ABS_L_LONG,); }
GENFUNC_PROTO(Func632){ MOVE_SR(DREG_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func633){ MOVE_SR(AN_I_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func634){ MOVE_SR(AN_PI_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func635){ MOVE_SR(AN_PD_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func636){ MOVE_SR(AN_D_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func637){ MOVE_SR(AN_R_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func638){ MOVE_SR(ABS_W_WORD,); }
GENFUNC_PROTO(Func639){ MOVE_SR(ABS_L_WORD,); }
GENFUNC_PROTO(Func640){ CHK(DREG_WORD,(UBITS(0,5,iw)&7),UBITS(9,11,iw)); }
GENFUNC_PROTO(Func641){ CHK(AN_I_WORD,(UBITS(0,5,iw)&7),UBITS(9,11,iw)); }
GENFUNC_PROTO(Func642){ CHK(AN_PI_WORD,(UBITS(0,5,iw)&7),UBITS(9,11,iw)); }
GENFUNC_PROTO(Func643){ CHK(AN_PD_WORD,(UBITS(0,5,iw)&7),UBITS(9,11,iw)); }
GENFUNC_PROTO(Func644){ CHK(AN_D_WORD,(UBITS(0,5,iw)&7),UBITS(9,11,iw)); }
GENFUNC_PROTO(Func645){ CHK(AN_R_WORD,(UBITS(0,5,iw)&7),UBITS(9,11,iw)); }
GENFUNC_PROTO(Func646){ CHK(ABS_W_WORD,,UBITS(9,11,iw)); }
GENFUNC_PROTO(Func647){ CHK(ABS_L_WORD,,UBITS(9,11,iw)); }
GENFUNC_PROTO(Func648){ CHK(PC_D_WORD,,UBITS(9,11,iw)); }
GENFUNC_PROTO(Func649){ CHK(PC_R_WORD,,UBITS(9,11,iw)); }
GENFUNC_PROTO(Func650){ CHK(IMM_WORD,,UBITS(9,11,iw)); }
GENFUNC_PROTO(Func651){ LEA(AN_I_LONG,(UBITS(0,5,iw)&7),UBITS(9,11,iw)); }
GENFUNC_PROTO(Func652){ LEA(AN_D_LONG,(UBITS(0,5,iw)&7),UBITS(9,11,iw)); }
GENFUNC_PROTO(Func653){ LEA(AN_R_LONG,(UBITS(0,5,iw)&7),UBITS(9,11,iw)); }
GENFUNC_PROTO(Func654){ LEA(ABS_W_LONG,,UBITS(9,11,iw)); }
GENFUNC_PROTO(Func655){ LEA(ABS_L_LONG,,UBITS(9,11,iw)); }
GENFUNC_PROTO(Func656){ LEA(PC_D_LONG,,UBITS(9,11,iw)); }
GENFUNC_PROTO(Func657){ LEA(PC_R_LONG,,UBITS(9,11,iw)); }
GENFUNC_PROTO(Func658){ CLR(BYTE,DREG_BYTE,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func659){ CLR(BYTE,AN_I_BYTE,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func660){ CLR(BYTE,AN_PI_BYTE,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func661){ CLR(BYTE,AN_PI_BYTE_All,7); }
GENFUNC_PROTO(Func662){ CLR(BYTE,AN_PD_BYTE,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func663){ CLR(BYTE,AN_PD_BYTE_All,7); }
GENFUNC_PROTO(Func664){ CLR(BYTE,AN_D_BYTE,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func665){ CLR(BYTE,AN_R_BYTE,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func666){ CLR(BYTE,ABS_W_BYTE,); }
GENFUNC_PROTO(Func667){ CLR(BYTE,ABS_L_BYTE,); }
GENFUNC_PROTO(Func668){ CLR(WORD,DREG_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func669){ CLR(WORD,AN_I_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func670){ CLR(WORD,AN_PI_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func671){ CLR(WORD,AN_PD_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func672){ CLR(WORD,AN_D_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func673){ CLR(WORD,AN_R_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func674){ CLR(WORD,ABS_W_WORD,); }
GENFUNC_PROTO(Func675){ CLR(WORD,ABS_L_WORD,); }
GENFUNC_PROTO(Func676){ CLR(LONG,DREG_LONG,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func677){ CLR(LONG,AN_I_LONG,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func678){ CLR(LONG,AN_PI_LONG,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func679){ CLR(LONG,AN_PD_LONG,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func680){ CLR(LONG,AN_D_LONG,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func681){ CLR(LONG,AN_R_LONG,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func682){ CLR(LONG,ABS_W_LONG,); }
GENFUNC_PROTO(Func683){ CLR(LONG,ABS_L_LONG,); }
GENFUNC_PROTO(Func684){ NEG(BYTE,DREG_BYTE,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func685){ NEG(BYTE,AN_I_BYTE,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func686){ NEG(BYTE,AN_PI_BYTE,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func687){ NEG(BYTE,AN_PI_BYTE_All,7); }
GENFUNC_PROTO(Func688){ NEG(BYTE,AN_PD_BYTE,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func689){ NEG(BYTE,AN_PD_BYTE_All,7); }
GENFUNC_PROTO(Func690){ NEG(BYTE,AN_D_BYTE,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func691){ NEG(BYTE,AN_R_BYTE,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func692){ NEG(BYTE,ABS_W_BYTE,); }
GENFUNC_PROTO(Func693){ NEG(BYTE,ABS_L_BYTE,); }
GENFUNC_PROTO(Func694){ NEG(WORD,DREG_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func695){ NEG(WORD,AN_I_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func696){ NEG(WORD,AN_PI_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func697){ NEG(WORD,AN_PD_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func698){ NEG(WORD,AN_D_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func699){ NEG(WORD,AN_R_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func700){ NEG(WORD,ABS_W_WORD,); }
GENFUNC_PROTO(Func701){ NEG(WORD,ABS_L_WORD,); }
GENFUNC_PROTO(Func702){ NEG(LONG,DREG_LONG,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func703){ NEG(LONG,AN_I_LONG,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func704){ NEG(LONG,AN_PI_LONG,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func705){ NEG(LONG,AN_PD_LONG,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func706){ NEG(LONG,AN_D_LONG,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func707){ NEG(LONG,AN_R_LONG,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func708){ NEG(LONG,ABS_W_LONG,); }
GENFUNC_PROTO(Func709){ NEG(LONG,ABS_L_LONG,); }
GENFUNC_PROTO(Func710){ MOVE_TO_CCR(DREG_WORD,(UBITS(0,5,iw)&7));; }
GENFUNC_PROTO(Func711){ MOVE_TO_CCR(AN_I_WORD,(UBITS(0,5,iw)&7));; }
GENFUNC_PROTO(Func712){ MOVE_TO_CCR(AN_PI_WORD,(UBITS(0,5,iw)&7));; }
GENFUNC_PROTO(Func713){ MOVE_TO_CCR(AN_PD_WORD,(UBITS(0,5,iw)&7));; }
GENFUNC_PROTO(Func714){ MOVE_TO_CCR(AN_D_WORD,(UBITS(0,5,iw)&7));; }
GENFUNC_PROTO(Func715){ MOVE_TO_CCR(AN_R_WORD,(UBITS(0,5,iw)&7));; }
GENFUNC_PROTO(Func716){ MOVE_TO_CCR(ABS_W_WORD,);; }
GENFUNC_PROTO(Func717){ MOVE_TO_CCR(ABS_L_WORD,);; }
GENFUNC_PROTO(Func718){ MOVE_TO_CCR(PC_D_WORD,);; }
GENFUNC_PROTO(Func719){ MOVE_TO_CCR(PC_R_WORD,);; }
GENFUNC_PROTO(Func720){ MOVE_TO_CCR(IMM_WORD,);; }
GENFUNC_PROTO(Func721){ NOT(BYTE,DREG_BYTE,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func722){ NOT(BYTE,AN_I_BYTE,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func723){ NOT(BYTE,AN_PI_BYTE,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func724){ NOT(BYTE,AN_PI_BYTE_All,7); }
GENFUNC_PROTO(Func725){ NOT(BYTE,AN_PD_BYTE,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func726){ NOT(BYTE,AN_PD_BYTE_All,7); }
GENFUNC_PROTO(Func727){ NOT(BYTE,AN_D_BYTE,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func728){ NOT(BYTE,AN_R_BYTE,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func729){ NOT(BYTE,ABS_W_BYTE,); }
GENFUNC_PROTO(Func730){ NOT(BYTE,ABS_L_BYTE,); }
GENFUNC_PROTO(Func731){ NOT(WORD,DREG_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func732){ NOT(WORD,AN_I_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func733){ NOT(WORD,AN_PI_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func734){ NOT(WORD,AN_PD_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func735){ NOT(WORD,AN_D_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func736){ NOT(WORD,AN_R_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func737){ NOT(WORD,ABS_W_WORD,); }
GENFUNC_PROTO(Func738){ NOT(WORD,ABS_L_WORD,); }
GENFUNC_PROTO(Func739){ NOT(LONG,DREG_LONG,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func740){ NOT(LONG,AN_I_LONG,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func741){ NOT(LONG,AN_PI_LONG,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func742){ NOT(LONG,AN_PD_LONG,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func743){ NOT(LONG,AN_D_LONG,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func744){ NOT(LONG,AN_R_LONG,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func745){ NOT(LONG,ABS_W_LONG,); }
GENFUNC_PROTO(Func746){ NOT(LONG,ABS_L_LONG,); }
GENFUNC_PROTO(Func747){ MOVE_TO_SR(DREG_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func748){ MOVE_TO_SR(AN_I_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func749){ MOVE_TO_SR(AN_PI_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func750){ MOVE_TO_SR(AN_PD_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func751){ MOVE_TO_SR(AN_D_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func752){ MOVE_TO_SR(AN_R_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func753){ MOVE_TO_SR(ABS_W_WORD,); }
GENFUNC_PROTO(Func754){ MOVE_TO_SR(ABS_L_WORD,); }
GENFUNC_PROTO(Func755){ MOVE_TO_SR(PC_D_WORD,); }
GENFUNC_PROTO(Func756){ MOVE_TO_SR(PC_R_WORD,); }
GENFUNC_PROTO(Func757){ MOVE_TO_SR(IMM_WORD,); }
GENFUNC_PROTO(Func758){ NBCD(DREG_BYTE,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func759){ NBCD(AN_I_BYTE,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func760){ NBCD(AN_PI_BYTE,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func761){ NBCD(AN_PI_BYTE_All,7); }
GENFUNC_PROTO(Func762){ NBCD(AN_PD_BYTE,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func763){ NBCD(AN_PD_BYTE_All,7); }
GENFUNC_PROTO(Func764){ NBCD(AN_D_BYTE,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func765){ NBCD(AN_R_BYTE,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func766){ NBCD(ABS_W_BYTE,); }
GENFUNC_PROTO(Func767){ NBCD(ABS_L_BYTE,); }
GENFUNC_PROTO(Func768){ SWAP(UBITS(0,2,iw)); }
GENFUNC_PROTO(Func769){ PEA(AN_I_LONG,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func770){ PEA(AN_D_LONG,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func771){ PEA(AN_R_LONG,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func772){ PEA(ABS_W_LONG,); }
GENFUNC_PROTO(Func773){ PEA(ABS_L_LONG,); }
GENFUNC_PROTO(Func774){ PEA(PC_D_LONG,); }
GENFUNC_PROTO(Func775){ PEA(PC_R_LONG,); }
GENFUNC_PROTO(Func776){ EXT(WORD,UBITS(0,2,iw)); }
GENFUNC_PROTO(Func777){ MOVEM_RM_CA(WORD,GET_SI16,AN_I_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func778){ MOVEM_RM_PD(WORD,GET_SI16,UBITS(0,2,iw)); }
GENFUNC_PROTO(Func779){ MOVEM_RM_CA(WORD,GET_SI16,AN_D_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func780){ MOVEM_RM_CA(WORD,GET_SI16,AN_R_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func781){ MOVEM_RM_CA(WORD,GET_SI16,ABS_W_WORD,); }
GENFUNC_PROTO(Func782){ MOVEM_RM_CA(WORD,GET_SI16,ABS_L_WORD,); }
GENFUNC_PROTO(Func783){ EXT(LONG,UBITS(0,2,iw)); }
GENFUNC_PROTO(Func784){ MOVEM_RM_CA(LONG,GET_SI16,AN_I_LONG,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func785){ MOVEM_RM_PD(LONG,GET_SI16,UBITS(0,2,iw)); }
GENFUNC_PROTO(Func786){ MOVEM_RM_CA(LONG,GET_SI16,AN_D_LONG,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func787){ MOVEM_RM_CA(LONG,GET_SI16,AN_R_LONG,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func788){ MOVEM_RM_CA(LONG,GET_SI16,ABS_W_LONG,); }
GENFUNC_PROTO(Func789){ MOVEM_RM_CA(LONG,GET_SI16,ABS_L_LONG,); }
GENFUNC_PROTO(Func790){ TST(BYTE,DREG_BYTE,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func791){ TST(BYTE,AN_I_BYTE,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func792){ TST(BYTE,AN_PI_BYTE,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func793){ TST(BYTE,AN_PI_BYTE_All,7); }
GENFUNC_PROTO(Func794){ TST(BYTE,AN_PD_BYTE,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func795){ TST(BYTE,AN_PD_BYTE_All,7); }
GENFUNC_PROTO(Func796){ TST(BYTE,AN_D_BYTE,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func797){ TST(BYTE,AN_R_BYTE,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func798){ TST(BYTE,ABS_W_BYTE,); }
GENFUNC_PROTO(Func799){ TST(BYTE,ABS_L_BYTE,); }
GENFUNC_PROTO(Func800){ TST(BYTE,PC_D_BYTE,); }
GENFUNC_PROTO(Func801){ TST(BYTE,PC_R_BYTE,); }
GENFUNC_PROTO(Func802){ TST(WORD,DREG_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func803){ TST(WORD,AN_I_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func804){ TST(WORD,AN_PI_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func805){ TST(WORD,AN_PD_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func806){ TST(WORD,AN_D_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func807){ TST(WORD,AN_R_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func808){ TST(WORD,ABS_W_WORD,); }
GENFUNC_PROTO(Func809){ TST(WORD,ABS_L_WORD,); }
GENFUNC_PROTO(Func810){ TST(WORD,PC_D_WORD,); }
GENFUNC_PROTO(Func811){ TST(WORD,PC_R_WORD,); }
GENFUNC_PROTO(Func812){ TST(LONG,DREG_LONG,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func813){ TST(LONG,AN_I_LONG,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func814){ TST(LONG,AN_PI_LONG,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func815){ TST(LONG,AN_PD_LONG,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func816){ TST(LONG,AN_D_LONG,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func817){ TST(LONG,AN_R_LONG,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func818){ TST(LONG,ABS_W_LONG,); }
GENFUNC_PROTO(Func819){ TST(LONG,ABS_L_LONG,); }
GENFUNC_PROTO(Func820){ TST(LONG,PC_D_LONG,); }
GENFUNC_PROTO(Func821){ TST(LONG,PC_R_LONG,); }
GENFUNC_PROTO(Func822){ TAS(DREG_BYTE,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func823){ TAS(AN_I_BYTE,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func824){ TAS(AN_PI_BYTE,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func825){ TAS(AN_PI_BYTE_All,7); }
GENFUNC_PROTO(Func826){ TAS(AN_PD_BYTE,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func827){ TAS(AN_PD_BYTE_All,7); }
GENFUNC_PROTO(Func828){ TAS(AN_D_BYTE,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func829){ TAS(AN_R_BYTE,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func830){ TAS(ABS_W_BYTE,); }
GENFUNC_PROTO(Func831){ TAS(ABS_L_BYTE,); }
GENFUNC_PROTO(Func832){ Illegal(); }
GENFUNC_PROTO(Func833){ MOVEM_MR_C(WORD,GET_SI16,AN_I_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func834){ MOVEM_MR_PI(WORD,GET_SI16,UBITS(0,2,iw)); }
GENFUNC_PROTO(Func835){ MOVEM_MR_C(WORD,GET_SI16,AN_D_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func836){ MOVEM_MR_C(WORD,GET_SI16,AN_R_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func837){ MOVEM_MR_C(WORD,GET_SI16,ABS_W_WORD,); }
GENFUNC_PROTO(Func838){ MOVEM_MR_C(WORD,GET_SI16,ABS_L_WORD,); }
GENFUNC_PROTO(Func839){ MOVEM_MR_C(WORD,GET_SI16,PC_D_WORD,); }
GENFUNC_PROTO(Func840){ MOVEM_MR_C(WORD,GET_SI16,PC_R_WORD,); }
GENFUNC_PROTO(Func841){ MOVEM_MR_C(LONG,GET_SI16,AN_I_LONG,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func842){ MOVEM_MR_PI(LONG,GET_SI16,UBITS(0,2,iw)); }
GENFUNC_PROTO(Func843){ MOVEM_MR_C(LONG,GET_SI16,AN_D_LONG,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func844){ MOVEM_MR_C(LONG,GET_SI16,AN_R_LONG,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func845){ MOVEM_MR_C(LONG,GET_SI16,ABS_W_LONG,); }
GENFUNC_PROTO(Func846){ MOVEM_MR_C(LONG,GET_SI16,ABS_L_LONG,); }
GENFUNC_PROTO(Func847){ MOVEM_MR_C(LONG,GET_SI16,PC_D_LONG,); }
GENFUNC_PROTO(Func848){ MOVEM_MR_C(LONG,GET_SI16,PC_R_LONG,); }
GENFUNC_PROTO(Func849){ TRAP(UBITS(0,3,iw)); }
GENFUNC_PROTO(Func850){ LINK(GET_SI16,UBITS(0,2,iw)); }
GENFUNC_PROTO(Func851){ UNLK(UBITS(0,2,iw)); }
GENFUNC_PROTO(Func852){ MOVE_TO_USP(UBITS(0,2,iw)); }
GENFUNC_PROTO(Func853){ MOVE_USP(UBITS(0,2,iw)); }
GENFUNC_PROTO(Func854){ RESET(); }
GENFUNC_PROTO(Func855){ NOP(); }
GENFUNC_PROTO(Func856){ STOP(GET_SI16); }
GENFUNC_PROTO(Func857){ RTE(); }
GENFUNC_PROTO(Func858){ RTS(); }
GENFUNC_PROTO(Func859){ TRAPV(); }
GENFUNC_PROTO(Func860){ RTR(); }
GENFUNC_PROTO(Func861){ JSR(AN_I_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func862){ JSR(AN_D_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func863){ JSR(AN_R_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func864){ JSR(ABS_W_WORD,); }
GENFUNC_PROTO(Func865){ JSR(ABS_L_WORD,); }
GENFUNC_PROTO(Func866){ JSR(PC_D_WORD,); }
GENFUNC_PROTO(Func867){ JSR(PC_R_WORD,); }
GENFUNC_PROTO(Func868){ JMP(AN_I_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func869){ JMP(AN_D_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func870){ JMP(AN_R_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func871){ JMP(ABS_W_WORD,); }
GENFUNC_PROTO(Func872){ JMP(ABS_L_WORD,); }
GENFUNC_PROTO(Func873){ JMP(PC_D_WORD,); }
GENFUNC_PROTO(Func874){ JMP(PC_R_WORD,); }
GENFUNC_PROTO(Func875){ ADDQ(BYTE,8,DREG_BYTE,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func876){ Illegal(); }
GENFUNC_PROTO(Func877){ ADDQ(BYTE,8,AN_I_BYTE,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func878){ ADDQ(BYTE,8,AN_PI_BYTE,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func879){ ADDQ(BYTE,8,AN_PI_BYTE_All,7); }
GENFUNC_PROTO(Func880){ ADDQ(BYTE,8,AN_PD_BYTE,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func881){ ADDQ(BYTE,8,AN_PD_BYTE_All,7); }
GENFUNC_PROTO(Func882){ ADDQ(BYTE,8,AN_D_BYTE,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func883){ ADDQ(BYTE,8,AN_R_BYTE,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func884){ ADDQ(BYTE,8,ABS_W_BYTE,); }
GENFUNC_PROTO(Func885){ ADDQ(BYTE,8,ABS_L_BYTE,); }
GENFUNC_PROTO(Func886){ ADDQ(WORD,8,DREG_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func887){ ADDQ_AREG(WORD,8,UBITS(0,2,iw)); }
GENFUNC_PROTO(Func888){ ADDQ(WORD,8,AN_I_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func889){ ADDQ(WORD,8,AN_PI_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func890){ ADDQ(WORD,8,AN_PD_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func891){ ADDQ(WORD,8,AN_D_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func892){ ADDQ(WORD,8,AN_R_WORD,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func893){ ADDQ(WORD,8,ABS_W_WORD,); }
GENFUNC_PROTO(Func894){ ADDQ(WORD,8,ABS_L_WORD,); }
GENFUNC_PROTO(Func895){ ADDQ(LONG,8,DREG_LONG,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func896){ ADDQ_AREG(LONG,8,UBITS(0,2,iw)); }
GENFUNC_PROTO(Func897){ ADDQ(LONG,8,AN_I_LONG,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func898){ ADDQ(LONG,8,AN_PI_LONG,(UBITS(0,5,iw)&7)); }
GENFUNC_PROTO(Func899){ ADDQ(LONG,8,AN_PD_LONG,(UBITS(0,5,iw)&7)); }
