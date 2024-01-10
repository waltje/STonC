/* 
 * biosdisk.c - native bios replacement for hard disk partition images
 *
 * Taken from STonX (C) 1994-1997 Marinos Yannikos & Martin D. Griffiths
 * Modified for STonC (C) 1998-2004 Laurent Vogel
 * Covered by the GPL version 2 or later; see COPYING for details
 */
 
/*
 * most part were taken from native.c.
 * the code for reading and writing is duplicated from fdc, though 
 * almost identical, to allow fdc later to handle other floppy image formats
 * such as compressed ones (.msa) or formats allowing weird formatting.
 */

#define BIOS_USE_STDIO 1

#include "defs.h"
#include "mem.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <string.h>

#if BIOS_USE_STDIO
# include <sys/types.h>
#else
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
#endif

#include "utils.h"
#include "cartridge.h"


#if ! BIOS_USE_STDIO
# ifndef O_BINARY
# define O_BINARY 0
# endif
#endif


#define FUNC_OPCODE 0xa0ff
#define BPB_OFF CART_FAKE_BPB

#define FLG_RDONLY      1
#define FLG_SPECIAL     2

/* drive_bits : the OR of fdc_drive_bits, bios_drive_bits, 
  gemdos_drive_bits, ... fdc, bios and gemdos may only add bits in
  their map if not already in drive_bits. they may remove only drives
  that are in their map. This way e.g. fdc does not have to know of bios
  or gemdos.
  As an exception, only the biosdisk.c clears drivebits when inited.
*/
  
int drive_bits;
int bios_drive_bits;

extern int boot_dev;

#define MAXDRIVES 16

#if BIOS_USE_STDIO
FILE *bios_drive_fp[MAXDRIVES];
#else
int bios_drive_fd[MAXDRIVES];
#endif
static int bios_drive_flags[MAXDRIVES];

void biosdisk_init(void)
{
  int i;
  for(i = 0 ; i < MAXDRIVES ; i++) {
#if BIOS_USE_STDIO
    bios_drive_fp[i] = NULL;
#else
    bios_drive_fp[i] = -1;
#endif
    bios_drive_flags[i] = 0;
  }
  bios_drive_bits = 0;
  drive_bits = 0;
}

static UL old_rw, old_bpb, old_init, old_boot, old_mediach;

/* Add a drive to the system; this must happen before TOS is booted */
int bios_add_drive(int d, char *fname)
{
#if BIOS_USE_STDIO
  FILE *fp;
#else
  int fd;
  struct stat st;
  int r;
#endif

        if (d < 0 || d >= MAXDRIVES)
        {
                ec_stderr( "bios_add_drive: invalid drive %d\n", d);
                return FALSE;
        }
        if (drive_bits & (1 << d))
        {
                ec_stderr( "bios_add_drive: drive %c already specified\n", d+'A');
                return FALSE;
        }

#if BIOS_USE_STDIO
  
  fp = fopen(fname, "rb+");
  if(fp == NULL) {
    /* don't be very smart: try to open it read-only */
    fp = fopen(fname, "rb");
    if(fp == NULL) {
      ec_stderr( "can't open file %s (%s)\n", fname, strerror(errno));
    } else {
      ec_stderr( "Warning: file %s is read-only\n", fname);
      bios_drive_flags[d] |= FLG_RDONLY;
    } 
  }
  bios_drive_fp[d] = fp;

#else  /* not BIOS_USE_STDIO */ 

        fd = open(fname, O_RDWR|O_BINARY);

        if (fd < 0)
        {
                if (errno == EROFS)
                {
                        fd = open(fname, O_RDONLY);
                } else if (errno == ENXIO)
                {
                        /* maybe floppy without disk inserted */
                        ec_stderr( "can't open file %s (%s), ignored\n", fname, strerror(errno));
                        return TRUE;
                }
                if (fd > 0)
                {
                        ec_stderr( "Warning: file %s is read-only\n", fname);
                        bios_drive_flags[d] |= FLG_RDONLY;
                } else
                {
                        error("can't open file %s (%s)\n", fname, strerror(errno));
                }
        }
        r = fstat(fd, &st);
        if (r < 0)
        {
                ec_stderr( "Warning: can't stat file %s: %s\n", fname, strerror(errno));
        } else
        {
                if (!S_ISREG(st.st_mode))
                {
                        ec_stderr( "Note: %s is a special file - it may or may not work as desired...\n", fname);
                        bios_drive_flags[d] |= FLG_SPECIAL;
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
        bios_drive_fd[d] = fd;
        
#endif /* not BIOS_USE_STDIO */
        
        bios_drive_bits |= 1 << d;
        drive_bits |= 1 << d;
        return 1;
}

int bios_disk_rw(char *as)
{
        W rwflag;
        UL buf;
        unsigned int count;
        int dev;
        unsigned long recno;
        
        rwflag = LM_W(as);
        buf = LM_UL(as + 2);
        count = LM_UW(as + 6);
        recno = LM_UW(as + 8);
        dev = LM_UW(as + 10);
        if (recno == 0xffff)
                recno = LM_UL(as+12);
#if 0
        ec_stderr("Rwabs(%d,$%lx,%d,%ld,%d), %x, %d: ", rwflag, (long)buf, count, recno, dev, drive_bits, boot_dev);
#endif
        if (dev < 0 || dev >= MAXDRIVES || !(bios_drive_bits & (1 << dev)))
        {
                pc = old_rw;
                return FALSE;
        }
#if BIOS_USE_STDIO
        if(bios_drive_fp[dev] == NULL) 
#else
        if(bios_drive_fd[dev] < 0) 
#endif
        {
          ec_stderr("bios drive %c has null file descriptor!!!\n", dev+'A');
          bios_drive_bits &= ~(1<<dev);
          drive_bits &= ~(1<<dev);
          pc = old_rw;
                return FALSE;
        }

        if ((bios_drive_flags[dev] & FLG_RDONLY) && (rwflag & 1))
        {
                DREG(0) = -13;
                return TRUE;
        }
        rwflag &= 1;                                            /* media change not yet implemented... */
#if BIOS_USE_STDIO
        if (fseek(bios_drive_fp[dev], recno * 512, SEEK_SET) < 0)
#else
        if (lseek(bios_drive_fd[dev], recno * 512, SEEK_SET) < 0)
#endif
        {
                ec_stderr( "lseek() on drive %d failed: %s\n", dev, strerror(errno));
                DREG(0) = -6;                                   /* E_SEEK is probably inappropriate */
                return TRUE;
        }
        if (rwflag == 0)
        {
#if BIOS_USE_STDIO
                if (fread(MEM(buf), 512, count, bios_drive_fp[dev]) != count)
                {
                        ec_stderr("read error on drive %d: %s\n", dev, strerror(errno));
                        DREG(0) = -11;
                        return TRUE;
                }
#else
                if (read(bios_drive_fd[dev], MEM(buf), count * 512) < 0)
                {
                        ec_stderr("read error on drive %d\n", dev);
                        DREG(0) = -11;
                        return TRUE;
                }
#endif
        } else
        {
                /* we should not lseek() if the following is true... */
                if (bios_drive_flags[dev] & FLG_RDONLY)
                {
                        DREG(0) = -13;
                        return TRUE;
                }
#if BIOS_USE_STDIO
                if (fwrite(MEM(buf), 512, count, bios_drive_fp[dev]) != count)
                {
                        ec_stderr("write error on drive %d: %s\n", dev, strerror(errno));
                        DREG(0) = -10;
                        return TRUE;
                }
#else
                if (write(bios_drive_fd[dev], MEM(buf), count * 512) < 0)
                {
                        ec_stderr("write error on drive %d\n", dev, strerror(errno));
                        DREG(0) = -10;
                        return TRUE;
                }
#endif
        }
        DREG(0) = 0;
        return TRUE;
}

/* Is it illegal to return a BPB address which is read-only???
 */
 
/* 
  getbpb : returns : 
  struct {
    int recsiz    sector size in bytes
    int clsiz     cluster size in sectors
    int clsizb    cluster size in bytes
    int rdlen     DIR size in sectors
    int fsiz      FAT size in sects
    int fatrec    first sector of second FAT
    int datrec    sector number of first data cluster
    int numcl     nomber of data clusters
    int bflags    bit 0 = 0 if FAT12, 1 if FAT16
  } bios_param_bloc;
*/  

int bios_disk_bpb(int dev)
{
        UB bootsec[512], *d;
        UB *x = (UB *)MEM(BPB_OFF);
        UW *wx = (UW *) x;
        off_t old;

  UW recsiz ;   /* sector size in bytes */
  UW clsiz  ;   /* cluster size in sectors */
  UW clsizb ;   /* cluster size in bytes */
  UW rdlen  ;   /* DIR size in sectors */
  UW fsiz   ;   /* FAT size in sectors */
  UW fatrec ;   /* first sector of second FAT */
  UW datrec ;   /* sector number of first data cluster */
  UW numcl  ;   /* number of data clusters */
  UW bflags ;   /* 0 if FAT12, 1 if FAT16 */

        if (dev < 0 || dev >= MAXDRIVES || !(bios_drive_bits & (1 << dev))) {
          pc = old_bpb;
          return FALSE;
        }
        
#if BIOS_USE_STDIO
        if (bios_drive_fp[dev] == NULL)
#else
        if (bios_drive_fd[dev] < 0)
#endif
        {
                ec_stderr("bios drive %c has null file descriptor!!!\n", dev+'A');
          bios_drive_bits &= ~(1<<dev);
          drive_bits &= ~(1<<dev);
          pc = old_bpb;
                return FALSE;
        }
#if BIOS_USE_STDIO
        old = fseek(bios_drive_fp[dev], 0, SEEK_CUR);
        /* TODO: check return values... :-( */
        fseek(bios_drive_fp[dev], 0, SEEK_SET);
        fread(bootsec, 1, 512, bios_drive_fp[dev]);
        fseek(bios_drive_fp[dev], old, SEEK_SET);
#else
        old = lseek(bios_drive_fd[dev], 0, SEEK_CUR);
        /* TODO: check return values... :-( */
        lseek(bios_drive_fd[dev], 0, SEEK_SET);
        read(bios_drive_fd[dev], bootsec, 512);
        lseek(bios_drive_fd[dev], old, SEEK_SET);
#endif
        d = bootsec;
        
        /* give names to those funny fields */
        
        recsiz = (d[0xc]<<8) + d[0xb];
        clsiz = d[0xd];
        clsizb = clsiz * recsiz;
        rdlen = ((d[0x12]<<8) + d[0x11]) / 16;
        fsiz = (d[0x17]<<8) + d[0x16];
        fatrec = (d[0xf]<<8) + d[0xe] + fsiz ;    /* nb of reserved sectors + fsiz */
        datrec = fatrec + fsiz + rdlen ;
        numcl = (((d[0x14]<<8) + d[0x13]) - datrec ) / clsiz; 
        if(dev >= 2) {
        bflags = 1;  /* FAT 16 for hard disks */
        } else {
          bflags = 0;
        }
        
        SM_W(wx, recsiz);
        SM_W(wx+1, clsiz);
        SM_W(wx+2, clsizb);
        SM_W(wx+3, rdlen);
        SM_W(wx+4, fsiz);
        SM_W(wx+5, fatrec);
        SM_W(wx+6, datrec);
        SM_W(wx+7, numcl);
        SM_W(wx+8, bflags); 

#if 0   /* WRONG, original implementation */
        x[0] = d[0xc];
        x[1] = d[0xb];
        x[2] = 0;                                                       
        x[3] = d[0xd];
        SM_W(&wx[2], LM_W(&wx[1]) * LM_W(&wx[0]));
        SM_W(&wx[3], (d[0x11] + d[0x12] * 256) / 16);
        x[8] = d[0x17];
        x[9] = d[0x16];
        SM_W(&wx[5], LM_W(&wx[4]) + 1);
        SM_W(&wx[6], LM_W(&wx[5]) + LM_W(&wx[4]) + LM_W(&wx[3]));
        SM_W(&wx[7], ((d[0x13] + d[0x14] * 256) - LM_W(&wx[6])) / LM_W(&wx[1]));
        SM_W(&wx[8], (LM_W(&wx[7]) > 0xfef));   /* WRONG!? */
#endif

#if 0
        ec_stderr(
"secsize=%d, sectors/cluster=%d, bytes/cluster=%d, root dir len=%d,\n"
"  fatsize=%d, fat2=%d, data=%d, clusters=%d, bflags=%x ",
                LM_W(wx), LM_W(wx+1), LM_W(wx+2), LM_W(wx+3), LM_W(wx+4), LM_W(wx+5), 
                LM_W(wx+6), LM_W(wx+7), LM_W(wx+8));
#endif
        DREG(0) = BPB_OFF;
#if 0
        ec_stderr("= $%lx\n", DREG(0));
#endif
        return TRUE;
}

void bios_Initialize(void)
{
/*      gemdos_initialized = 0; */
        old_rw = LM_UL(ADDR(0x476));
        old_bpb = LM_UL(ADDR(0x472));
        old_init = LM_UL(ADDR(0x46a));
        old_boot = LM_UL(ADDR(0x47a));
        old_mediach = LM_UL(ADDR(0x47e));
}

void bios_disk_init(void)
{
        int b = boot_dev;
#if 1
        while (b < 32 && !(drive_bits & (1l << b)))
                b++;
        if (b >= 32)
        {
                b = 0;
                while (b < 32 && !(drive_bits & (1l << b)))
                        b++;
        }
        boot_dev = b;
        SM_W(ADDR(0x446), boot_dev);
        SM_W(ADDR(0x4a6), (((drive_bits & 1)!=0))+((drive_bits & 2)!=0));
#if 0
        if ((drive_bits & 1))
                drive_bits |= 2;
#endif
        SM_L(ADDR(0x4c2), drive_bits);
        ec_stderr("drivebits = 0x%08lx\n", (UL) drive_bits);
        /* XXX set in init_mem() too??? */
        ec_stderr("Will boot from drive %c\n", boot_dev+'A');
#endif
}


