#
# Makefile for MinGW-w64, 64bit
#
# Taken from STonX (C) 1994-1997 Marinos Yannikos & Martin D. Griffiths
# Modified for STonC (C) 1998-2003 Laurent Vogel
# Covered by the GPL version 2 or later; see COPYING for details

prefix	= C:/STonC
bindir	= $(prefix)/bin
STONC	= $(prefix)/share

CURSES	= P:/Libraries/PDCurses
CURLIB	= -L$(CURSES)/lib/x86 -lpdcurses
CURDEFS	= -I$(CURSES)/include -DPDCURSES -DNCURSES_STATIC

#DEF	= -DIS_BIG_ENDIAN=0 -DSTATFS_USE_VFS -DSTONCDIR=\"$(STONC)\"
DEF	= -DIS_BIG_ENDIAN=0 -DSTONCDIR=\"$(STONC)\" $(CURDEFS)


# Compiler
CC	= tcc $(ARCH) -Wall
CPUCC	= tcc $(ARCH) -Wall
SCC	= tcc $(ARCH)
EXE	= .exe
CORE	=

CFLAGS	= $(DEF) $(OPT) -Iinclude -I$(CURSES)#/include
LIBS	= $(CURLIB)

# Preprocessor
CPP	= tcc $(ARCH) -E

# Optimization and debugging options
# OPT=-Wall -Wno-unused -O3 -funroll-loops
# unused: -malign-jumps=2 -malign-functions=4
# OPT = -O3 -march=i586 -mcpu=i586 -funroll-loops -fomit-frame-pointer
OPT	= -O3 -funroll-loops -fomit-frame-pointer

# Utilities.
#SED	= C:\MSYS2\usr\bin\sed.exe
SED	= sed.exe

#
# TOCLEAN will accumulate over this Makefile the names of files to remove 
# when doing make clean; this Makefile may use temporary files named *.tmp
#
TOCLEAN := *~ */*~ $(CORE) *.tmp


.SUFFIXES: 	.m4 


#
# source code in util/
#
UTILSRC	= utils.c hash.c bhash.c

#
# source code in shell/
#
SHELLSRC = ui.c vars.c

#
# source code in emulc/
#
EMULCSRC = ecterm.c emulc.c vtime.c ec_keys.c ec_util.c \
	   fifo.c rline.c

#
# source code in machine/
#
MACHSRC = acia.c boss.c mem.c audio.c hdc.c mfp.c ocr.c syscalls.c \
	  biosdisk.c fdc.c ikbd.c main.c midi.c profile.c \
	  blitter.c gemdos.c io.c memarray.c native.c stkbd.c usart.c \
	  nf.c nfglue.c

#
# source code in stonxcpu/
#
STONXSRC = cpu.c cpubis.c iotab.c

#
# generated source code
#
GENSRC = code0000.c code0300.c code0600.c code0900.c code1200.c code1500.c


DEPSRC=$(CSRC) gen.c

DATAFILES = data/stoncrc data/uskbd.txt data/stoncfnt.txt data/cartridge.img \
	data/nulltos.img

#
# everything should work fine below.
# P for PATH

PUTILSRC	= $(UTILSRC:%=util/%)
PSHELLSRC	= $(SHELLSRC:%=shell/%)
PMACHSRC	= $(MACHSRC:%=machine/%)
PSTONXSRC	= $(STONXSRC:%=stonxcpu/%)
PEMULCSRC	= $(EMULCSRC:%=emulc/%)
SRC		= $(PUTILSRC) $(PSHELLSRC) $(PMACHSRC) $(PSTONXSRC) $(PEMULCSRC)

UTILOBJ		= $(UTILSRC:%.c=obj/%.o)
SHELLOBJ	= $(SHELLSRC:%.c=obj/%.o)
MACHOBJ		= $(MACHSRC:%.c=obj/%.o)
STONXOBJ	= $(STONXSRC:%.c=obj/%.o)
EMULCOBJ	= $(EMULCSRC:%.c=obj/%.o)
GENOBJ		= $(GENSRC:%.c=obj/%.o)
OBJ		= $(UTILOBJ) $(SHELLOBJ) $(MACHOBJ) $(STONXOBJ) $(EMULCOBJ) $(GENOBJ)


#
# production targets 
# 
all:	stonc$(EXE)

TOCLEAN += stonc$(EXE)

help:
	@echo "target   meaning"
	@echo "------   -------"
	@echo "help     this help message"
	@echo "all      stonc"$(EXE)", the executable"
	@echo "install" 
	@echo "clean"
	@echo "dist     create a tgz named after the version in version.h"
	@echo "tgz      bundles all into a tgz named after the date"

install: stonc$(EXE) $(DATAFILES)
	install -d $(STONCDIR)
	cp $(DATAFILES) $(STONCDIR)
	cp stonc$(EXE) $(bindir)

stonc$(EXE): $(OBJ) 
	$(SCC)  -o $@ $(OBJ) $(LIBS) 

#
# automatic rules
#

TOCLEAN += obj/*.o

obj/%.o: util/%.c
	 $(CC) $(CFLAGS) -o $@ -Iutil -c $<

obj/%.o: shell/%.c
	 $(CC) $(CFLAGS) -o $@ -Ishell -c $<

obj/%.o: stonxcpu/%.c
	 $(CC) $(CFLAGS) -o $@ -Istonxcpu -Imachine -Iobj -c $<

obj/%.o: emulc/%.c
	 $(CC) $(CFLAGS) -o $@ -Iemulc -c $<

obj/%.o: machine/%.c
	 $(CC) $(CFLAGS) -o $@ -Imachine -c $<

obj/%.o: obj/%.c
	 $(CPUCC) $(CFLAGS) -o $@ -Istonxcpu -Imachine -c $<


#
# version
#
TOCLEAN += include/version.h

obj/main.o obj/nf.o: include/version.h

include/version.h: changelog.txt tools/version.sed
	$(SED) -f tools/version.sed changelog.txt > $@

#
# special STonX CPU stuff
#
TOCLEAN += obj/*.c obj/gen$(EXE) obj/*.m4

obj/%.c: obj/%.m4
	m4 < $< > $@

obj/gen$(EXE): stonxcpu/gen.c stonxcpu/amdefs.h include/options.h include/config.h
	$(CC) -O -Iinclude -o $@ stonxcpu/gen.c

obj/code0000.m4 obj/code0300.m4 obj/code0600.m4 \
obj/code0900.m4 obj/code1200.m4 obj/code1500.m4 \
obj/code.m4: obj/gen$(EXE) stonxcpu/68000.def stonxcpu/genhead.m4
	cat stonxcpu/genhead.m4  >obj/code.m4
	cd obj; ./gen$(EXE) <../stonxcpu/68000.def >>code.m4

obj/code.c obj/code0000.c obj/code0300.c obj/code0600.c obj/code0900.c obj/code1200.c obj/code1500.c: obj/code.m4 obj/code0000.m4 obj/code0300.m4 obj/code0600.m4 obj/code0900.m4 obj/code1200.m4 obj/code1500.m4 obj/gendefs.m4
	@cd obj; for i in code*.m4; \
	do \
		t=`echo $$i|$(SED) s/\.m4/.c/`; \
		echo "Translating: $$i -> $$t"; \
		m4 < $$i >$$t; \
	done

obj/gendefs.m4: stonxcpu/gendefs.m4
	cp $< $@

obj/cpu.o:  obj/code.c

#
# 
#

expand:
	@for i in `grep -l '	' */*.[chS]` ; do \
	  echo expanding $$i; \
	  expand <$$i >expand.tmp; \
	  mv expand.tmp $$i; \
	done

#
#
#

INDENTFILES = */*.[ch]
INDENT = indent -kr -i2
	
indent:
	@err=0; \
	for i in $(INDENTFILES); do \
		$(INDENT) <$$i 2>err.tmp | expand >indent.tmp; \
		if ! test -s err.tmp; then \
			if ! cmp -s indent.tmp $$i; then \
				echo indenting $$i; \
				mv $$i $$i~; \
				mv indent.tmp $$i; \
			fi \
		else \
			err=`expr $$err + 1`; \
			echo in $$i:; \
			cat err.tmp; \
		fi \
	done; \
	rm -f err.tmp indent.tmp; \
	if [ $$err -ne 0 ]; then \
		echo $$err 'file(s)' untouched because of warnings; \
		false; \
	fi

#
# create a tgz archive named project-version.tgz,
# where project is derived from the current directory name,
# and version is the first date or version in the changelog.
#

tgz:	distclean
	@v=`$(SED) -f tools/version.sed changelog.txt`; \
	here=`basename \`pwd\``; h2=`echo $$here | tr A-Z a-z`; \
	v2=`echo $$v | $(SED) -e 's/[^"]*"//' -e 's/^20//' -e 's/["-]//g'`; \
	echo cd ..\; tar cf - $$here \| gzip -c -9 \> $$h2-$$v2.tgz; \
	cd ..; tar cf - $$here | gzip -c -9 > $$h2-$$v2.tgz

clean:
	rm -f $(TOCLEAN) mon.out gmon.out log proftabs.c functab.c

distclean: clean
	rm -f ? a.out a.exe

