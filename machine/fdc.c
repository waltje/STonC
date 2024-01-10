/* 
 * fdc.c - FDC emulation
 *
 * Taken from STonX (C) 1994-1997 Marinos Yannikos & Martin D. Griffiths
 * Modified for STonC (C) 1998-2002 Laurent Vogel
 * Covered by the GPL version 2 or later; see COPYING for details
 */

/* The simple FDC emulation was derived from FAST's FDC code. FAST is
 * an Atari ST emulator written by Joachim Hoenig
 * (hoenig@informatik.uni-erlangen.de). Bugs are probably implemented by
 * me (nino@complang.tuwien.ac.at), so don't bother him with questions
 * regarding this code!
 */
 
/*
 * Replaced unistd fonctions by stdio ones. Did this to ease porting to
 * non Unix environments. In doing so, lost ability to access special 
 * files. Please use then plain disk image files and the appropriate utility 
 * (eg, dd) to transfer to/from actual devices.
 * (the unistd interface is kept if FDC_USE_STDIO is zero.) 
 */

#define FDC_USE_STDIO 1

#include "defs.h"
#include "mem.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>

#if FDC_USE_STDIO
#else
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
#endif

#include "utils.h"
#include "vtime.h"
#include "fdc.h"

extern void mfp_set_gpip_bit(unsigned char mask, unsigned char value) ;


#if ! FDC_USE_STDIO
# ifndef O_BINARY
# define O_BINARY 0
# endif
#endif

#define FDC_DEBUG 0

struct disk_geom
{
        int head, sides, tracks, sectors, secsize;
} disk[2];

/* in biosdisk.c */
extern int drive_bits;
extern int bios_add_drive(int d, char *fname);



int dma_mode,dma_scr,dma_car,dma_sr;
int fdc_command,fdc_track,fdc_sector,fdc_data,fdc_int,fdc_status,fdc_busy;
int snd_porta;

#define MAXDRIVES 2

#define FLG_RDONLY      1
#define FLG_SPECIAL     2

static int drive_flags[MAXDRIVES];

#if FDC_USE_STDIO
static FILE *drive_fp[MAXDRIVES];
#else
static int drive_fd[MAXDRIVES];
#endif

static void fdc_get_geometry(int d);

#define RW_READ 1
#define RW_WRITE 2
static int fdc_do_rw(int d, char *buffer, long count, long offset, int rw);

int fdc_drive_bits = 0;

int fdc_cmd_disk(int argc, char **argv)
{
  char *w;
/* TODO , insert disk read-only */
  if(argc != 3) {
    ec_stderr("usage: disk [a-p]: <file>\n");
    return 1;
  }
  w = argv[1];
  if((w[2] != 0) || (w[1] != ':') || (w[0] < 'a') || (w[0] > 'p')) {
    ec_stderr("usage: disk [a-p]: <file>\n");
    return 1;
  }     
  if(w[0] >= 'c') {
    if(!bios_add_drive (w[0]-'a', argv[2])) {
      return 1;
    }
  } else {
    if(!fdc_add_drive (w[0]-'a', argv[2])) {
      return 1;
    }
  }
  /* no error */
  return 0;
}

int fdc_cmd_eject(int argc, char **argv)
{
  char *w;
  if(argc != 2) {
    ec_stderr("usage: eject [ab]:\n");
    return 1;
  }
  w = argv[1];
  if((w[2] != 0) || (w[1] != ':') || (w[0] < 'a') || (w[0] > 'b')) {
    ec_stderr("usage: eject [ab]:\n");
    return 1;
  }     
  fdc_eject_drive (w[0]-'a');  /* cannot fail */
  return 0;
}


/* Add a drive to the system; this must happen before TOS is booted */
int fdc_add_drive(int d, char *fname)
{
#if FDC_USE_STDIO
  FILE *fp;
#else
  int fd;
  struct stat st;
  int r;
#endif

  if (d < 0 || d >= MAXDRIVES) {
    (void) ec_stderr( "invalid drive %d\n", d);
    return FALSE;
  }
  if (drive_bits & (1 << d)) {
    if (fdc_drive_bits & (1<<d)) {
      /* the bios needs time to realize that the media has changed,
        it is better to ask the user to eject the disk. 
      */
      ec_stderr("Please eject the current floppy first\n");
      return FALSE;
    } else {
      ec_stderr("Drive %c is already a GEMDOS or a BIOS disk\n", d+'A');
      return FALSE;
    }
  }
        
#if FDC_USE_STDIO
  
  fp = fopen(fname, "rb+");
  if(fp == NULL) {
    /* don't be very smart: try to open it read-only */
    fp = fopen(fname, "rb");
    if(fp == NULL) {
      ec_stderr( "can't open file %s (%s)\n", fname, strerror(errno));
    } else {
      ec_stderr( "Warning: file %s is read-only\n", fname);
      drive_flags[d] |= FLG_RDONLY;
    } 
  }
  drive_fp[d] = fp;

#else  /* not FDC_USE_STDIO */
  
  fd = open(fname, O_RDWR|O_BINARY);

  if (fd < 0) {
    if (errno == EROFS) {
      fd = open(fname, O_RDONLY|O_BINARY);
    } else if (errno == ENXIO) {
      /* maybe floppy without disk inserted */
      ec_stderr( "can't open file %s (%s), ignored\n", fname, strerror(errno));
      return TRUE;
    }
    if (fd > 0) {
      ec_stderr( "Warning: file %s is read-only\n", fname);
      drive_flags[d] |= FLG_RDONLY;
    } else {
      ec_stderr( "can't open file %s (%s)\n", fname, strerror(errno));
    }
  }
  r = fstat(fd, &st);
  if (r < 0) {
    ec_stderr( "Warning: can't stat file %s: %s\n", fname, strerror(errno));
  } else {
    if (!S_ISREG(st.st_mode))
    {
      ec_stderr( "Note: %s is a special file - it may or may not work as desired...\n", fname);
      drive_flags[d] |= FLG_SPECIAL;
#ifndef __linux__
      /* linux has no raw devices, so don't warn about that */
      if (S_ISBLK(st.st_mode))
      {
        ec_stderr( "Note: if you want to emulate a `real' floppy disk drive, you should use the\ncorresponding raw device instead!\n");
      }
#endif
    } else
    {
      if (st.st_size == 0)
      {
        ec_stderr( "Warning: file %s has size 0!\n", fname);
      }
    }
  }
  drive_fd[d] = fd;
  
#endif /* not FDC_USE_STDIO */

  fdc_drive_bits |= 1 << d;
  drive_bits |= 1 << d;
  
  fdc_get_geometry(d);
  return 1;
}


static void fdc_get_geometry(int i)
{
#if FDC_USE_STDIO
  FILE *fp;
#else
  int fd;
#endif
  
  unsigned char buf[512];
  if(! (fdc_drive_bits & (1<<i))) {
    ec_stderr("FDC get geometry of a non-floppy disk letter %c\n", i+'A');
    return;
  }

#if FDC_USE_STDIO
  fp = drive_fp[i];
  if (fp == NULL) {
    ec_stderr("FDC drive_fp and drive_bits contradict for drive %d\n", i);
    return;
  }
#else
  fd = drive_fd[i];
  if (fd <= 0) {
    ec_stderr("FDC drive_fd and drive_bits contradict for drive %d\n", i);
    return;
  }
#endif

  if(fdc_do_rw(i, (char *)buf, /* count */ 512, /* offset */ 0, RW_READ)) {
    ec_stderr("FDC can't read bootsector of drive %i\n", i);
    fdc_eject_drive(i);
    return;
  }

  disk[i].sides=(int)buf[26];
  disk[i].sectors=(int)buf[24];
  disk[i].secsize=(int)(buf[12]<<8)|buf[11];
  if(disk[i].sides*disk[i].sectors != 0)
    disk[i].tracks=((int)(buf[20]<<8)|buf[19])/(disk[i].sides*disk[i].sectors);

  if( (disk[i].sides <= 0) || (disk[i].sides > 2) || 
    (disk[i].sectors < 9) || (disk[i].sectors > 11) ||
    (disk[i].secsize != 512) || 
    (disk[i].tracks < 40) || (disk[i].tracks > 82)) {
      ec_stderr("FDC: WARNING: drive %c: has strange geometry\n", i+'A');
      ec_stderr("FDC %c: %d/%d/%d %d bytes/sector\n",
        'A'+i,disk[i].sides,disk[i].tracks,disk[i].sectors,
        disk[i].secsize);
  }
}


void fdc_eject_drive(int d)
{
  if(fdc_drive_bits & (1<<d)) {
#if FDC_USE_STDIO
    FILE *fp = drive_fp[d];
    drive_fp[d] = NULL;
    fclose(fp);
#else
    int fd = drive_fd[d];
    drive_fd[d] = -1;
    close(fd);
#endif
    fdc_drive_bits &= ~(1<<d) ;       
    drive_bits &= ~(1<<d) ; 
  } else {
    if(d >= 0 && d < 2) {
      ec_stderr("No floppy in drive %c\n", d+'A');
    } else {
      ec_stderr("Drive %d is not an ejectable floppy\n", d);
    }
  }
}   

void init_fdc(void)
{
  int i;
  
  fdc_drive_bits = 0;
  for (i=0; i<2; i++) {
    disk[i].head=0;
  }
  fdc_busy = 0 ;

  ui_register_command("disk", fdc_cmd_disk,
    "usage: disk <letter>: <file>\n"
    "emulates insertion of a floppy in the drive specified by <letter> (a or b).\n"
    "using the disk image given a <file>.\n"
    "The geometry is guessed based on the first 512 bytes of the file\n"
    "(corresponding to the floppy's bootsector using MSDOS conventions).\n"
    "see also eject.\n");

  ui_register_command("eject", fdc_cmd_eject,
    "usage: eject <letter>:\n"
    "ejects the floppy from the drive specified by <letter> (a or b).\n"
    "see also disk.\n");
}

static void fdc_finish_job(void *dummy) ;

void fdc_exec_command (void)
{
  static int dir=1,motor=1;
  int sides,d;
  UL address;
  long offset;
  long count;
  char *buffer;
  extern void linea_init(void);

  if(fdc_busy && ((fdc_command & 0xF0) != 0xd0)) {
    ec_stderr( "FCD command while busy \n") ;
    fdc_busy = 0 ;
    fdc_int = 0 ;
    clear_alarm_by_func(fdc_finish_job) ;
    flags &= ~F_FDC ;
    mfp_set_gpip_bit(0x20, 0) ;
  }

  address = (LM_UB(MEM(0xff8609))<<16)|(LM_UB(MEM(0xff860b))<<8)
      |LM_UB(MEM(0xff860d));
  buffer=(char *)MEM(address);
  sides=(~snd_porta)&1;
  d=(~snd_porta)&6;
  switch(d)
  {
    case 2:
      d=0;
      break;
    case 4:
      d=1;
      break;
    case 6:
    case 0:
      d=-1;
      break;
  }
  
  /* do not bother, if the disk wes ejected, then set d=-1 */
  if(!(fdc_drive_bits & (1<<d))) {
    d = -1;
  }

#if FDC_DEBUG
  ec_stderr("FDC command 0x%04x drive=%d\n",fdc_command,d);
#endif
  fdc_status=0;
  if (fdc_command < 0x80)
  {
    if (d>=0)
    {
      switch(fdc_command&0xf0)
      {
        case 0x00:
#if FDC_DEBUG
          ec_stderr("\tFDC RESTORE !\n");
#endif
          disk[d].head=0;
          fdc_track=0;
          break;
        case 0x10:
#if FDC_DEBUG
          ec_stderr("\tFDC SEEK to %d\n",fdc_data);
#endif
          disk[d].head += fdc_data-fdc_track;
          fdc_track=fdc_data;
          if (disk[d].head<0 || disk[d].head>=disk[d].tracks)
            disk[d].head=0;
          break;
        case 0x30:
          fdc_track+=dir;
        case 0x20:
          disk[d].head+=dir;
          break;
        case 0x50:
          fdc_track++;
        case 0x40:
          if (disk[d].head<disk[d].tracks)
            disk[d].head++;
          dir=1;
          break;
        case 0x70:
          fdc_track--;
        case 0x60:
          if (disk[d].head > 0)
            disk[d].head--;
          dir=-1;
          break;
      }
      if((fdc_command & 4) && !(fdc_drive_bits & (1<<d))) {
        /* if verifying that the track number is the same as what
           is written on the floppy, then generate an error if no floppy
        */
        fdc_status |= 0x10;
      }
      if (disk[d].head==0)
        fdc_status |= 4;
      if (disk[d].head != fdc_track && (fdc_command & 4))
        fdc_status |= 0x10;
      if (motor)
        fdc_status |= 0x20;
    }
    else fdc_status |= 0x10;
  }
  else if ((fdc_command & 0xf0) == 0xd0)
  {
#if 0
    if (fdc_command == 0xd8) fdc_int=1;
    else if (fdc_command == 0xd0) fdc_int=0;
#else
    if(fdc_command == 0xd8) {
      mfp_set_gpip_bit(0x20, 0x00) ;
    } else {
      mfp_set_gpip_bit(0x20, 0x20) ;
    }
#endif
  }
  else
  {
    if (d>=0)
    {
      offset=disk[d].secsize
        * (((disk[d].sectors*disk[d].sides*disk[d].head))
        + (disk[d].sectors * sides) + (fdc_sector-1));
      switch(fdc_command & 0xf0)
      {
        case 0x80:
#if FDC_DEBUG
          ec_stderr("\tFDC READ SECTOR %d to 0x%06lx\n",
            dma_scr,address);
#endif
          count=dma_scr*disk[d].secsize;
          if(fdc_do_rw(d, buffer, count, offset, RW_READ)) {
            fdc_status |= 0x10;
            dma_sr=1;
            break;
          }
          address += count;
          SM_UB(MEM(0xfff8609),address>>16);
          SM_UB(MEM(0xfff860b),address>>8);
          SM_UB(MEM(0xfff860d),address);
          dma_scr=0;
          dma_sr=1;
          break;

        case 0x90:
#if FDC_DEBUG
          ec_stderr("\tFDC READ SECTOR M. %d to 0x%06lx\n",
            dma_scr,address);
#endif
          count=dma_scr*disk[d].secsize;
          if(fdc_do_rw(d, buffer, count, offset, RW_READ)) {
            fdc_status |= 0x10;
            dma_sr=1;
            break;
          }
          address += count;
          SM_UB(MEM(0xfff8609),address>>16);
          SM_UB(MEM(0xfff860b),address>>8);
          SM_UB(MEM(0xfff860d),address);
          dma_scr=0;
          dma_sr=1;
          fdc_sector += dma_scr; /* *(512/disk[d].secsize);*/
          break;
        case 0xa0:
          count=dma_scr*disk[d].secsize;
          if(drive_flags[d]&FLG_RDONLY) {
            fdc_status |= 0x40;
            dma_sr = 1;
            break;
          }
          if(fdc_do_rw(d, buffer, count, offset, RW_WRITE)) {
            fdc_status |= 0x10;
            dma_sr=1;
            break;
          }
          address += count;
          SM_UB(MEM(0xfff8609),address>>16);
          SM_UB(MEM(0xfff860b),address>>8);
          SM_UB(MEM(0xfff860d),address);
          dma_scr=0;
          dma_sr=1;
          break;
      
        case 0xb0:
          count=dma_scr*disk[d].secsize;
          if(drive_flags[d]&FLG_RDONLY) {
            fdc_status |= 0x40;
            dma_sr = 1;
            break;
          }
          if(fdc_do_rw(d, buffer, count, offset, RW_WRITE)) {
            fdc_status |= 0x10;
            dma_sr=1;
            break;
          }
          address += count;
          SM_UB(MEM(0xfff8609),address>>16);
          SM_UB(MEM(0xfff860b),address>>8);
          SM_UB(MEM(0xfff860d),address);
          dma_scr=0;
          dma_sr=1;
          fdc_sector += dma_scr; /* *(512/disk[d].secsize);*/
          break;
        case 0xc0:
          fdc_status |= 0x10;
          break;
        case 0xe0:
          fdc_status |= 0x10;
          break;
        case 0xf0:
          if(drive_flags[d]&FLG_RDONLY) {
            fdc_status |= 0x40;
            break;
          }
          fdc_status |= 0x10;
          break;
      }
      if (disk[d].head != fdc_track) fdc_status |= 0x10;
    }
    else fdc_status |= 0x10;
  }
  if (motor)
    fdc_status |= 0x80;
#if FDC_DEBUG
  ec_stderr("FDC STATUS = 0x%04x drive=%d\n",fdc_status,d);
#endif

  if(fdc_command != 0xd0) {
    /* wake up some time later to finish job */
    fdc_busy = 1 ;
    mfp_set_gpip_bit(0x20, 0x20) ;
    set_alarm(0.001, fdc_finish_job, 0) ;
  }
}

static void fdc_finish_job(void *dummy) 
{
  UNUSED(dummy);

  if(! fdc_busy) {
    ec_stderr("fdc_finish_job called when not busy\n") ;
    return ;
  }
  fdc_busy = 0 ;
  mfp_set_gpip_bit(0x20, 0) ;
}


/*
 * returns : 0 if no error 
 *
 */

static int fdc_do_rw(int d, char *buffer, long count, long offset, int rw)
{
#if FDC_USE_STDIO
  long actual_count;
  FILE *fp = drive_fp[d];

  if((fdc_drive_bits & (1<<d)) == 0) {
    return 1;
  }
  if(fseek(fp, offset, SEEK_SET) < 0)
    return 1;
  if(rw == RW_READ) {
    actual_count = fread(buffer, 1, count, fp);
  } else {
    actual_count = fwrite(buffer, 1, count, fp);
  }
  if(actual_count != count)
    return 1;
  return 0;
#else
  int fd = drive_fd[d];
  long actual_count;
  
  if (lseek(fd, offset, SEEK_SET) < 0)
    return 1;
  if(rw == RW_READ) {
    actual_count = read(fd, buffer, count);
  } else {
    actual_count = write(fd, buffer, count);
  }
  if(actual_count != count)
    return 1;          
  return 0;
#endif 
}
  
