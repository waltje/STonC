/* 
 * gemdos.c - native gemdos drives
 *
 * Taken from STonX (C) 1994-1997 Marinos Yannikos & Martin D. Griffiths
 * Modified for STonC (C) 1998-2002 Laurent Vogel
 * Covered by the GPL version 2 or later; see COPYING for details
 */
 
/*
 * Modified for STonC, 
 * - removed drive_fd[], biosdisk and fdc must know themselves whether they
 *   own their disks.
 * - added commands.
 * - used ec_stderr().
 */

#include "defs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#ifndef _WIN32
# include <unistd.h>
#endif
#include <ctype.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#ifndef _WIN32
#if defined(STATFS_USE_STATVFS)
#include <sys/statvfs.h>
#elif defined(STATFS_USE_VFS)
#include <sys/vfs.h>
#elif defined(STATFS_USE_MOUNT)
#include <sys/param.h>
#include <sys/mount.h>
#elif defined(STATFS_USE_STATFS_VMOUNT)
#include <sys/statfs.h>
#include <sys/vmount.h>
#endif
#include <fcntl.h>
#include <dirent.h>
#endif
#include "main.h"
#include "utils.h"
#include "mem.h"
#include "native.h"
#include "gemdos.h"
#include "utils.h"

#ifndef _WIN32

#if 1
#define STATFUNC stat
#else
#define STATFUNC lstat
#endif

#define DEBUG_GEMDOS 1
#define perror(a) ec_stderr("%s: %s\n", (a), strerror(errno))
#define DEFAULT_MODE 0644
#define DEFAULT_DIRMODE 0755

#define FSNEXT_JUSTSTAT 0x8000

/* some of this code is was stolen&modified from JET */
#define TOS_NAMELEN 13

typedef struct
{
        char index[2];  /* FIXME - should use seekdir() instead of DIR * array */
        char magic[4];
#define SVALID 0x1234fedc
#define EVALID 0x5678ba90
        char dta_pat[TOS_NAMELEN+1];
        char dta_sattrib;
        char dta_attrib;
        char dta_time[2];
        char dta_date[2];
        char dta_size[4];
        char dta_name[TOS_NAMELEN];
} DTA;

typedef struct
{
        UL bp;
        int f;
} FINFO;

#define GEMDOS_EDRIVE -46
#define GEMDOS_EFILNF -33
#define GEMDOS_EPTHNF -34
#define GEMDOS_ENMFIL -49
#define GEMDOS_EIHNDL -37
#define GEMDOS_EACCDN -36

#define MAXDRIVES 26

extern int drive_bits;
extern int redirect_cconws;
int gemdos_ok=0;
UL gemdos_drives = 0;
UW curdrv=0;
char curpath[MAXDRIVES][500];
#define MAXFILES 100
#define H_OFFSET 100
static FINFO file[MAXFILES];
void *act_pd;
#define MAXDIRS 40

DIR *fsdir[MAXDIRS];
char curspath[MAXDIRS][500];
static char *root[MAXDRIVES];
int cursdrv;

extern int nocart;

int add_gemdos_drive (char d, char *path)
{
        int drv=toupper(d&0xff)-'A';
        if (drv<0||drv>MAXDRIVES)
        {
                ec_stderr("Invalid drive: `%c'\n",d);
                return 0;
        }
        else if (drive_bits & (1<<drv))
        {
                ec_stderr( "Drive `%c' is already used as a BIOS drive or floppy image\n",d);
                return 0;
        }
        else if (gemdos_drives & (1<<drv))
        {
                ec_stderr( "Drive `%c' already specified as a GEMDOS drive\n",d);
                return 0;
        }
        gemdos_drives |= 1<<drv;
        drive_bits |= 1<<drv;
        root[drv] = xstrdup (path);
        return 1;
}

/* GEMDOS functions : 
 * Gemdos() is called from cartridge.S.
 * Gemdos() always returns. if Z is set, then it means that the 
 * native Gemdos() has done the job, and if so cartridge returns.
 * if V is set, it means that cartridge must do something special 
 * for pexec(), else, the cartrige jumps to the location of the 
 * gemdos handler that was set before gemdos_first_time() was 
 * called (the first gemdos call, namely a dummy Sversion() from 
 * the cartridge).
 */
 

int redirect_cconws = 0;

void Cconws (char *str)
{
        if (!redirect_cconws) return;
        fputs(str,stdout);
        SET_Z();
}

void Dsetdrv (UW drv)
{
#if DEBUG_GEMDOS
        ec_stderr( "Dsetdrv(%c)\n",'A'+drv);
#endif
        curdrv = drv;
#if 0
        if (BIT(drv,drive_bits) == 0)
        {
                DREG(0) = GEMDOS_EDRIVE;
                SET_Z();
        }
        else
        {
                curdrv = drv;
                DREG(0) = drive_bits;
                SET_Z();
        }
#endif
}

void Dgetdrv (void)
{
        DREG(0) = curdrv;
#if DEBUG_GEMDOS
        ec_stderr( "Dgetdrv() = %d\n",curdrv);
#endif
        SET_Z();
}

void Fsetdta (UL dtaptr)
{
        UL bp = LM_UL(act_pd);
#if DEBUG_GEMDOS
        ec_stderr( "Process %lx DTA=%lx\n", (long)bp, (long)dtaptr);
#endif
#if 0
        SM_UL(MEM(bp+32),dtaptr);
        SET_Z();
#endif
}

void Fgetdta (void)
{
        UL bp = LM_UL(act_pd);
        DREG(0) = LM_UL(MEM(bp+32));
        SET_Z();
}

void fname2unix (char *stpath, char *unixpath)
{
        char *a,*b;
        char *n;
        a=stpath; b=unixpath;
        if (stpath[1]==':') n = stpath+2;
        else n=stpath;
        while(*n&&*n!=' ')
        {
                *unixpath++ = (*n == '\\' ? '/' : tolower(*n));
                n++;
        }
        *unixpath=0;
#if DEBUG_GEMDOS
        ec_stderr( "Converted %s to %s\n", a,b);
#endif
}

static char lastpath[500];

int st2unixpath (char *stpath, char *unixpath)
{
        int drv;
        char path[500];
        drv = (stpath[1] == ':' ? toupper(stpath[0])-'A' : curdrv);
        if (((gemdos_drives>>drv)&1) == 0)
        {
#if DEBUG_GEMDOS
                ec_stderr( "ERROR in pathname conversion (wrong drive)\n");
#endif
                *unixpath=0;
                return 0;
        }
        if (stpath[1] == ':') {
          if (stpath[2] == '\\') {
                strcpy(lastpath,stpath);
          } else {
            sprintf(lastpath, "%c:%s\\%s", stpath[0], curpath[drv], stpath+2);
          }
        }
        else if (stpath[0] == '\\')
        {
                sprintf (lastpath, "%c:%s", curdrv+'A',stpath);
        }
        else
        {
                sprintf (lastpath,"%c:%s\\%s",curdrv+'A',curpath[drv],stpath);
        }
        fname2unix(lastpath,path);
        sprintf(unixpath,"%s%s",root[drv],path);
#if DEBUG_GEMDOS
        ec_stderr( "st2unixpath(%s,%s)\n",stpath,unixpath);
#endif
        return 1;
}

int unix2fname (char *unixname, char *stname)
{
        /* FIXME */
        char *p=unixname;
        char *q=stname;
        if (strlen(unixname)>12) return 0;
        while (*p)
        {
                if (*p == '.')
                {
#if 0
                        if (dot) return 0;
                        else dot=1;
#endif
                        *stname++='.';
                }
                else *stname++ = toupper(*p);
                p++;
        }
        *stname=0;
#if DEBUG_GEMDOS
        ec_stderr( "Unix name: %s, ST name: %s\n", unixname, q);
#endif
        return 1;
}

#include <ctype.h>
static int my_strcasecmp(char *a, char *b)
{
  for(;;) {
    int aa = *a++;
    int bb = *b++;
    if(aa == 0) {
      if(bb == 0) {
        return 0;
      } else {
        return -1;
      }
    } else if(bb == 0) {
      return 1;
    } else {
      if(islower(aa)) aa = toupper(aa);
      if(islower(bb)) bb = toupper(bb);
      if(aa > bb) {
        return 1;
      } else if(aa < bb) {
        return -1;
      }
    }
  }
}
    

static int match (char *pat, char *name)
{
#if DEBUG_GEMDOS
  ec_stderr("Match(%s,%s)\n",pat,name);
#endif
  if (strcmp(pat,"*.*")==0) {
    return 1;
  } else if (my_strcasecmp(pat,name)==0) {
    return 1;
  } else {
    char *p=pat,*n=name;
    for( ; *n ; ) {
      if (*p=='*') {
        while (*n && *n != '.') n++;
        p++;
      } else if (*p=='?' && *n) {
        n++; p++; 
      } else if (*p++ != *n++) {
        return 0;
      }
    }
    if (*p==0) {
#if DEBUG_GEMDOS
      ec_stderr("(%s) matched (%s)\n",name,pat);
#endif
      return 1;
    }
  }
  return 0;
}

void compress_path (char *path)
{
  char *d, *p=path;
#if DEBUG_GEMDOS
  ec_stderr( "Before path compression: %s\n", p);
#endif
  d = path;
  while (*p) {
    if (*p == '\\') {
      if (strncmp(p,"\\..\\",4) == 0) {
        while (--d>=path && *d != '\\')
          ;
        if (d<path) {
          ec_stderr("FATAL error in compress_path: \\..\\\n");
          exit(1);
        }
        p += 3;
      } else if (strncmp(p,"\\.\\",3) == 0) {
        p += 2;
      } else {
        while (*++p == '\\')
          ;
        *d++ = '\\';
      }
    } else {
      *d++=*p++;
    }
  }
  if (d != path && *(d-1) == '\\') {
    d--;
  }
  *d=0;
#if DEBUG_GEMDOS
  ec_stderr( "Result of path compression: %s\n", path);
#endif
}


int xopendir (char *p, int doopen)
{
  int i;
  DIR *d;
  for (i=0; i<MAXDIRS && fsdir[i]; i++);
  if (i==MAXDIRS) {
#if DEBUG_GEMDOS
    ec_stderr( "FATAL error in xopendir - out of dirs\n");
#endif
    exit(1);
  }
  if (!doopen) {
    fsdir[i] = (DIR *)-1;
    return i | FSNEXT_JUSTSTAT;
  }
  d = opendir(p);
  if (d==NULL) {
#if DEBUG_GEMDOS
    ec_stderr("opendir(%s)  - no files\n",p);
#endif
    return -1;
  }
  fsdir[i] = d;
  return i;
}

void xclosedir (int i)
{
  if (i >= 0)
    closedir(fsdir[i]);
  fsdir[i&(FSNEXT_JUSTSTAT-1)] = NULL;
}

struct dirent *xreaddir (int i)
{
  if (i >= 0)
    return readdir (fsdir[i]);
  return NULL;
}


UW time2dos (time_t t)
{
  struct tm *x;
  x = localtime (&t);
  return (x->tm_sec>>1)|(x->tm_min<<5)|(x->tm_hour<<11);
}

UW date2dos (time_t t)
{
  struct tm *x;
  x = localtime (&t);
  return x->tm_mday|((x->tm_mon+1)<<5)|(MAX(x->tm_year-80,0)<<9);
}

void Fsnext (void)
{
  UL bp;
  struct stat s;
  struct dirent *e, etmp;
  char stname[TOS_NAMELEN+1];
  char uname[500];
  UB attribs;
  DTA *dta;
  UW da = 0;
  int rr = -1;
  if (((gemdos_drives >> cursdrv)&1)==0) return;
  bp = LM_UL(act_pd);
  dta = (DTA *)MEM(LM_UL(MEM(bp+32)));
  attribs = LM_UB(&(dta->dta_sattrib));
#if DEBUG_GEMDOS
  ec_stderr("Fsnext(%s)\n",dta->dta_pat);
#endif
repeat:
  SM_UL((UL *)&(dta -> magic),EVALID);
  do {
    rr = (LM_W((W *)&(dta->index)));
    if (rr < 0) {
      if (rr == -1) {
#if DEBUG_GEMDOS
        ec_stderr( "(no more files)\n");
#endif
        DREG(0) = GEMDOS_ENMFIL;
        SET_Z();
        return;
      } else {
        SM_W((W *)&(dta->index),-1);
        xclosedir(rr);
        rr &= (FSNEXT_JUSTSTAT-1);
        e = &etmp;
        strncpy (e->d_name,dta->dta_pat,TOS_NAMELEN);
        e->d_name[TOS_NAMELEN] = '\0';
        unix2fname(e->d_name,stname);
        fname2unix(stname,e->d_name);
        break;
      }
    } else {
      e = xreaddir (rr);
      if (e == NULL) {  
#if DEBUG_GEMDOS
        ec_stderr( "(no more files)\n");
#endif
        DREG(0) = GEMDOS_ENMFIL;
        SET_Z();
        xclosedir(LM_UW((UW *)&(dta->index)));
        return;
      }
    }
  } while ( !unix2fname(e->d_name,stname) 
            || !match((char *)&(dta->dta_pat),stname));
  SM_UL((UL *)&(dta->magic),SVALID);
  strcpy(dta->dta_name, stname);
  sprintf (uname, "%s/%s", curspath[rr], e->d_name);
#if DEBUG_GEMDOS
  ec_stderr( "stat(%s)\n",uname);
#endif
  if (STATFUNC (uname, &s) < 0)
    goto repeat;
#if 0
  da = (s.st_mode & S_IFDIR)?0x10:0;    /* FIXME */
#else
  da = S_ISDIR(s.st_mode) ? 0x10 : 0;
#endif
  if (!(da == 0 ||
        ((da != 0) && (attribs != 8)) || ((attribs | 0x21) & da)))
    goto repeat;
  SM_UB(&(dta->dta_attrib),da);
  SM_UW((UW *)&(dta->dta_time),time2dos(s.st_mtime));
  SM_UW((UW *)&(dta->dta_date),date2dos(s.st_mtime));
  SM_UL((UL *)&(dta->dta_size),0);
  if (LM_UB(&(dta->dta_attrib)) & 0x10) {
    DREG(0)=0;
    SET_Z();
    return;
  }
  SM_UL((UL *)&(dta->dta_size),s.st_size);
  DREG(0)=0;
  SET_Z();
  return;
}

void Dsetpath (char *pname)
{
  char upath[500];
  struct stat s;
  int drv;
  if (pname[1] == ':') drv=toupper(pname[0])-'A';
  else drv=curdrv;
  if (!st2unixpath(pname,upath)) {
#if DEBUG_GEMDOS
    ec_stderr( "Dsetpath(%s) not done\n",pname);
#endif
    return;
  }
  if (STATFUNC(upath,&s) < 0 && !S_ISDIR(s.st_mode)) {
    DREG(0) = GEMDOS_EPTHNF;
    SET_Z();
    return;
  }
  if (pname[1] == ':') { 
    strcpy(pname,&pname[2]); /* for Dsetdrv(C:\FOO) */
  }
  if (pname[0] == '\\') {
    strcpy(curpath[drv],pname);
  } else {
    strcat(curpath[drv],"\\");
    strcat(curpath[drv],pname);
  }
#if 1
  compress_path(curpath[drv]);
#endif
#if DEBUG_GEMDOS
  ec_stderr( "Dsetpath(%s) -> %s on drive %d (%s)\n", 
             pname, curpath[drv], curdrv, upath);
#endif
  /* FIXME */
  DREG(0)=0;
  SET_Z();
}

void Fsfirst (char *fspec, UW attribs)
{
  int r;
  UL bp;
  DTA *dta;
  char *p, upath[500];
  if (!st2unixpath(fspec,upath)) {
#if DEBUG_GEMDOS
    ec_stderr("Fsfirst(%s,%x) drive %d not done\n",fspec,attribs,curdrv);
#endif
    cursdrv=999;
    return;
  }
#if DEBUG_GEMDOS
  ec_stderr( "Fsfirst(%s,%x) on drive %d\n",fspec,attribs,curdrv);
#endif
  if (fspec[1]==':') {
    cursdrv=toupper(fspec[0])-'A';
  } else {
    cursdrv=curdrv;
  }
  bp = LM_UL(act_pd);
  dta = (DTA *)MEM(LM_UL(MEM(bp+32)));
  SM_UL((UL *)&(dta -> magic),EVALID);
  p = strrchr (lastpath, '\\');
  if(p == NULL) {
    ec_stderr("lastpath = \"%s\"\n", lastpath);
    ec_fatal("no '\\' in lastpath");
  } else {
    p += 1;
  }
  strcpy (dta -> dta_pat, p);
  *p=0;
#if 0
  strcpy(tpath,lastpath);
  Dsetpath(tpath);
#endif
  SM_UB(&(dta -> dta_sattrib),attribs);
#ifndef FA_LABEL
#define FA_LABEL 0x08
#endif
  if (attribs == FA_LABEL) {
    DREG(0) = GEMDOS_EFILNF;
    SET_Z();
    return;
  }
  st2unixpath (lastpath, upath);
#if 1
  /* kill trailing /es */
  while (upath && *upath && *(p=upath+strlen(upath)-1) == '/') {
    *p = '\0';
  }
#endif
  if (!strchr (dta -> dta_pat, '?') &&
      !strchr (dta -> dta_pat, '*')) {
    r = xopendir (upath, 0);
  } else {
#if DEBUG_GEMDOS
    ec_stderr( "Opendir(%s)\n", upath);
#endif
    r = xopendir (upath, 1);
    if (r < 0) {
      DREG(0) = GEMDOS_EFILNF;
      SET_Z();
      return;
    }
  }
  SM_UW((UW *)&(dta->index),r);
  strcpy (curspath[r&(FSNEXT_JUSTSTAT-1)], upath);
  Fsnext ();
  if (DREG(0) == GEMDOS_ENMFIL) {
    DREG(0) = GEMDOS_EFILNF;
  }
  SET_Z();
}

int st2unixmode(UW mode)
{
  switch(mode) {
  case 0: return O_RDONLY;
  case 1: return O_WRONLY;      /* kludge to avoid files being created */
  case 2: return O_RDWR;
  }
  return 0;
}

void Fopen (char *fname, UW mode)
{
  int i;
  UL bp;
  int f;
  char upath[500];
  if (!st2unixpath(fname, upath)) {
#if DEBUG_GEMDOS
    ec_stderr("Fopen(%s,%x) drive %d not done\n",fname,mode,curdrv);
#endif
    return;
  }
  bp = LM_UL(act_pd);
#if DEBUG_GEMDOS
  ec_stderr( "Fopen(%s,%x) on drive %d -> %s\n",fname,mode,curdrv,upath);
#endif
  for (i=0; i<MAXFILES && file[i].bp != 0; i++) {
    if (i >= MAXFILES) {
      DREG(0) = GEMDOS_ENMFIL;
      SET_Z();
      return;
    }
  }
  f = open(upath,st2unixmode(mode));
  if (f < 0) {
#if DEBUG_GEMDOS
    perror("open()");
#endif
    if (errno == ENOENT) {
      DREG(0) = GEMDOS_EPTHNF;
    } else {
      DREG(0) = GEMDOS_EFILNF;
    }
    SET_Z();
    return;
  }
  file[i].bp = bp;
  file[i].f = f;
  DREG(0) = i+H_OFFSET;
  SET_Z();
}

/* Problem: if we pass a large `count', some systems give "Bad Address"
 * errors, because buf+count would be outside the process' address space (?)
 */
void Fread (UW handle, UL count, char *buf)
{
#define FREAD_CHUNK 4096
  int r,i=handle-H_OFFSET,total=0;
  size_t rd;
  if (handle<H_OFFSET) return;
#if DEBUG_GEMDOS
  ec_stderr( "Fread(%d,%ld,%lx)",handle,count,(long)buf);
#endif
  if (file[i].bp != LM_UL(act_pd) || file[i].f < 0) {
    DREG(0) = GEMDOS_EIHNDL;
    SET_Z();
    return;
  }
  if (count > 0x1fffffff) count = 0x1fffffff;
  rd = FREAD_CHUNK;
  for(;count > 0;) {
    if (count < rd) rd = count;
    r = read (file[i].f, buf+total, rd);
    if (r < 0) {
#if DEBUG_GEMDOS
      perror ("read()");
#endif
      DREG(0) = -1;
      SET_Z();
      return;
    }
    count -= r;
    total += r;
    if (((size_t)r) < rd) break;
  }
#if DEBUG_GEMDOS
  ec_stderr( "=%d\n",total);
#endif
  DREG(0) = total;
  SET_Z();
}

void Fclose (UW handle)
{
        int i=handle-H_OFFSET;
        if (handle<H_OFFSET) return;
        if (file[i].bp != LM_UL(act_pd) || file[i].f < 0)
        {
                DREG(0) = GEMDOS_EIHNDL;
                SET_Z();
                return;
        }
        close(file[i].f);
        file[i].bp = 0;
        file[i].f = -1;
        DREG(0) = 0;
        SET_Z();
}

void Fcreate (char *fname, UW attribs)
{
        int i;
        UL bp;
        int f;
        char upath[500];
        if (!st2unixpath(fname, upath))
        {
#if DEBUG_GEMDOS
                ec_stderr("Fcreate(%s,%x) drive %d not done\n",fname,attribs,curdrv);
#endif
                return;
        }
        bp = LM_UL(act_pd);
#if DEBUG_GEMDOS
        ec_stderr( "Fcreate(%s,%x) on drive %d -> %s\n",fname,attribs,curdrv,upath);
#endif
        if (attribs == FA_LABEL) {
                DREG(0) = GEMDOS_EFILNF;
                SET_Z();
                return;
        }
        for (i=0; i<MAXFILES && file[i].bp != 0; i++)
        if (i >= MAXFILES)
        {
                DREG(0) = GEMDOS_ENMFIL;
                SET_Z();
                return;
        }

        f = creat(upath,DEFAULT_MODE);
        if (f < 0)
        {
#if DEBUG_GEMDOS
                perror("Fcreate!!");
#endif
                /* it would be nice if checking for ENOENT would work... */
                DREG(0) = GEMDOS_EPTHNF;
                SET_Z();
                return;
        }
        file[i].bp = bp;
        file[i].f = f;
        DREG(0) = i+H_OFFSET;
        SET_Z();
}

void Fwrite (UW handle, UL count, char *buf)
{
        int r,i=handle-H_OFFSET;
        if (handle<H_OFFSET) return;
        if (file[i].bp != LM_UL(act_pd) || file[i].f < 0)
        {
                DREG(0) = GEMDOS_EIHNDL;
                SET_Z();
                return;
        }
        r = write (file[i].f, buf, (size_t) count);
#if DEBUG_GEMDOS
        ec_stderr( "Fwrite(%d,%ld,%lx)=%d\n",handle,count,(long)buf,r);
#endif
        DREG(0) = r;
        SET_Z();
}

void Fdelete (char *fname)
{
        char upath[500];
        if (!st2unixpath(fname,upath)) return;
#if DEBUG_GEMDOS
        ec_stderr( "Fdelete(%s) on drive %d -> %s\n",fname,curdrv,upath);
#endif
        if (unlink(upath) < 0)
        {
                DREG(0) = GEMDOS_EACCDN;
                SET_Z();
                return;
        }
        DREG(0)=0;
        SET_Z();
        return;
}

void Dcreate (char *pname)
{
        char upath[500];
        if (!st2unixpath(pname,upath)) return;
#if DEBUG_GEMDOS
        ec_stderr( "Dcreate(%s) on drive %d -> %s\n",pname,curdrv,upath);
#endif
        if (mkdir(upath,DEFAULT_DIRMODE) < 0)
        {
                DREG(0) = GEMDOS_EACCDN;
                SET_Z();
                return;
        }
        DREG(0)=0;
        SET_Z();
}

void Ddelete (char *pname)
{
        char upath[500];
        if (!st2unixpath(pname,upath)) return;
#if DEBUG_GEMDOS
        ec_stderr( "Ddelete(%s) on drive %d -> %s\n",pname,curdrv,upath);
#endif
        if (rmdir(upath) < 0)
        {
                DREG(0) = GEMDOS_EACCDN;
                SET_Z();
                return;
        }
        DREG(0)=0;
        SET_Z();
}

void Dgetpath (char *buf, UW drv)
{
        /* FIXME */
#if DEBUG_GEMDOS
        ec_stderr("Dgetpath(%d)=",drv);
#endif
        if (drv == 0)
                drv=curdrv;
        else
                --drv;
        if (!((gemdos_drives >> drv)&1))
        {
#if DEBUG_GEMDOS
                ec_stderr("(tos)\n");
#endif
                return;
        }
        DREG(0) = 0;
        sprintf(buf,"%s",curpath[drv]);
        SET_Z();
#if DEBUG_GEMDOS
        ec_stderr("%s\n",curpath[drv]);
#endif
}

void Pexec (UW mode, char *file, char *cmdlin, char *env)
{
        char x[500];
#if DEBUG_GEMDOS
        ec_stderr( "Pexec(%x,%s,%s,%s)\n",
                mode, file?file:"NULL", cmdlin?cmdlin:"NULL", env?env:"NULL");
#endif
        if ((mode != 0 && mode != 3) || !st2unixpath(file,x))
        {       
#if DEBUG_GEMDOS
                ec_stderr("Not on unix filesystem\n");
#endif
        }
#if 1
        else
#endif
        sr |= MASK_CC_V;        /* Quick Pexec detection hack -> cartridge.S */
}

void Malloc (UL amount)
{
        UL bp = LM_UL(act_pd);
#if DEBUG_GEMDOS
        ec_stderr( "Malloc(%ld) by BP %lx\n", (long)amount, (long)bp);
#endif
}

void Mfree (UL addr)
{
        UL bp = LM_UL(act_pd);
#if DEBUG_GEMDOS
        ec_stderr( "Mfree(%lx) by BP %lx\n", (long)addr, (long)bp);
#endif
}

void Mshrink (UL addr, UL amount)
{
        UL bp = LM_UL(act_pd);
#if DEBUG_GEMDOS
        ec_stderr( "Mshrink(%lx,%ld) by BP %lx\n", (long)addr, (long)amount,    
                        (long)bp);
#endif
}

void Fseek (L offset, UW handle, UW mode)
{
        int i=handle-H_OFFSET;
        long dlen,dpos;
        if (handle<H_OFFSET) return;
        if (file[i].bp != LM_UL(act_pd) || file[i].f < 0)
        {
                DREG(0) = GEMDOS_EIHNDL;
                SET_Z();
                return;
        }
        dpos=lseek(file[i].f,0,SEEK_CUR);
        dlen=lseek(file[i].f,0,SEEK_END);
#if DEBUG_GEMDOS
        ec_stderr("Fseek: file length is %ld\n",dlen);
#endif
        (void)lseek(file[i].f,dpos,SEEK_SET);
        dpos=lseek(file[i].f,offset,mode);
        if (dpos > dlen) DREG(0)=-64;   /* ERANGE */
        else DREG(0)=dpos;
#if DEBUG_GEMDOS
        ec_stderr( "Fseek(%ld,%d,%d) = %ld\n", offset, handle, mode, DREG(0));
#endif
        SET_Z();
        return;
}

void Frename (char *old, char *nw)
{
        char o[500],n[500];
        int r;
        if (!st2unixpath(old,o) || !st2unixpath(nw,n)) return;
        r = rename(o,n);
#if DEBUG_GEMDOS
        if (r<0) perror("rename");      /* FIXME */
#endif
        DREG(0)=0;
        SET_Z();
}

void Fdatime (UW *t, UW *d, UW handle, UW wflag)
{
        struct stat s;
        int i=handle-H_OFFSET;
        if (i<0) return;
        if (file[i].bp != LM_UL(act_pd) || file[i].f < 0)
        {
                DREG(0) = GEMDOS_EIHNDL;
                SET_Z();
                return;
        }
        if (wflag == 0)
        {
                fstat (file[i].f, &s);
                SM_UW(t,s.st_mtime);
                SM_UW(d,s.st_mtime);
                DREG(0) = 0;
                SET_Z();
                return;
        }
        else if (wflag == 1)
        {
                DREG(0) = 0;
                SET_Z();
                return;
        }
        SET_Z();
        return;
}

void Dfree (UL *buf, UW drv)
{
#ifdef STATFS_USE_STATVFS
        struct statvfs s;
#else
        struct statfs s;
#endif
        struct stat st;
        if (drv == 0)
                drv=curdrv;
        else
                --drv;
        if (!((gemdos_drives >> drv)&1)) return;
#ifdef STATFS_USE_STATVFS
        statvfs (root[drv], &s);
#else
        statfs (root[drv], &s);
#endif
#ifdef STATFS_USE_MOUNT /* XXX 512b blocks */
        SM_UL(buf,s.f_bavail);
        SM_UL(buf+1,s.f_blocks-(s.f_bfree-s.f_bavail));
        SM_UL(buf+2,s.f_bsize);
        SM_UL(buf+3,1);
#else
        stat (root[drv], &st);
#if DEBUG_GEMDOS
        ec_stderr( "Dfree(%d) = %ld/%ld/%ld/%ld\n",drv,s.f_bavail,s.f_blocks,
        st.st_blksize/2,2);
#endif
        SM_UL(buf,s.f_bavail);
        SM_UL(buf+1,s.f_blocks);
        SM_UL(buf+2,st.st_blksize/2);
        SM_UL(buf+3,2);
#endif
        DREG(0)=0;
        SET_Z();
}

void Fattrib (char *name, UW mode, UW attrib)
{
  char u[500];
  struct stat s;
  UNUSED(attrib);

  if (!st2unixpath(name,u)) return;
  DREG(0)=0;
  if (mode == 0) {
      if (STATFUNC (u, &s) < 0) {
        DREG(0)=-33;
        SET_Z();
        return;
      }
#if 0
      DREG(0) = (s.st_mode & S_IFDIR)?0x10:0;   /* FIXME */
#else
      DREG(0) = S_ISDIR(s.st_mode) ? 0x10 : 0;
#endif
  }
  SET_Z();
}
#endif	/*!_WIN32*/


/* as = SP+4 here. 
  as the gemdos call was called using a direct trap, then :
  - as-4 = saved sr,
  - as-2 = saved PC, 
  - as+2 = begining of args.
  if the saved sr indicated that the caller was in user mode, then
  the args are at addresses starting from USP.
*/
void Gemdos (UL as)
{
#ifndef _WIN32
        W n;
        UW ssr;
        UL args;

        if(nocart) return;
        sr &= ~MASK_CC_V;
        ssr = LM_UW(MEM(as-4));
        if (BIT(13,ssr) == 0) args = AREG(8);
        else args = as+2;
        n = LM_W(MEM(args));
#if DEBUG_GEMDOS
        ec_stderr( "Gemdos 0x%02x\n", n);
#endif
        SET_N();
        switch (n)
        {
                case 9:
                        Cconws ((char *)MEM(LM_UL(MEM(args+2))));
                        return;
                case 14:
                        Dsetdrv (LM_UW(MEM(args+2)));
                        return;
                case 25:
                        Dgetdrv ();
                        return;
                case 26:
                        Fsetdta (LM_UL(MEM(args+2)));
                        return;
                case 47:
                        Fgetdta ();
                        return;
                case 78:
                        Fsfirst ((char *)MEM(LM_UL(MEM(args+2))),LM_UW(MEM(args+6)));
                        return;
                case 79:
                        Fsnext ();
                        return;
                case 61:
                        Fopen ((char *)MEM(LM_UL(MEM(args+2))),LM_UW(MEM(args+6)));
                        return;
                case 63:
                        Fread (LM_UW(MEM(args+2)), LM_UL(MEM(args+4)),
                                (char *)MEM(LM_UL(MEM(args+8))));
                        return;
                case 64:
                        Fwrite (LM_UW(MEM(args+2)), LM_UL(MEM(args+4)),
                                (char *)MEM(LM_UL(MEM(args+8))));
                        return;
                case 62:
                        Fclose (LM_UW(MEM(args+2)));
                        return;
                case 60:
                        Fcreate ((char *)MEM(LM_UL(MEM(args+2))),LM_UW(MEM(args+6)));
                        return;
                case 65:
                        Fdelete ((char *)MEM(LM_UL(MEM(args+2))));
                        return;
                case 57:
                        Dcreate ((char *)MEM(LM_UL(MEM(args+2))));
                        return;
                case 58:
                        Ddelete ((char *)MEM(LM_UL(MEM(args+2))));
                        return;
                case 71:
                        Dgetpath ((char *)MEM(LM_UL(MEM(args+2))), LM_UW(MEM(args+6)));
                        return;
                case 59:
                        Dsetpath ((char *)MEM(LM_UL(MEM(args+2))));
                        return;
                case 75:
                        Pexec (LM_UW(MEM(args+2)),
                                (char *)MEM(LM_UL(MEM(args+4))),
                                (char *)MEM(LM_UL(MEM(args+8))),
                                (char *)MEM(LM_UL(MEM(args+12))));
                        return;
                case 72:
                        Malloc (LM_UL(MEM(args+2)));
                        return;
                case 73:
                        Mfree (LM_UL(MEM(args+2)));
                        return;
                case 74:
                        Mshrink (LM_UL(MEM(args+4)), LM_UL(MEM(args+8)));
                        return;
                case 66:
                        Fseek (LM_L(MEM(args+2)), LM_UW(MEM(args+6)), LM_UW(MEM(args+8)));
                        return;
                case 86:
                        Frename ((char*)MEM(LM_UL(MEM(args+4))),
                                        (char*)MEM(LM_UL(MEM(args+8))));
                        return;
                case 87:
                        Fdatime ((UW*)MEM(LM_UL(MEM(args+2))),
                                        (UW*)MEM(LM_UL(MEM(args+2))+2),
                                        LM_UW(MEM(args+6)),LM_UW(MEM(args+8)));
                        return;
                case 54:
                        Dfree ((UL *)MEM(LM_UL(MEM(args+2))), LM_UW(MEM(args+6)));
                        return;
                case 67:
                        Fattrib ((char *)MEM(LM_UL(MEM(args+2))), LM_UW(MEM(args+6)),
                                LM_UW(MEM(args+8)));
                        return;
                default:
                        break;
        }
#endif	/*!_WIN32*/
}


#ifndef _WIN32
int gemdos_cmd_fs(int argc, char **argv)
{
  char *w;
  if(argc != 3) goto usage;
  w = argv[1];
  if((w[2] != 0) || (w[1] != ':') || (w[0] < 'a') || (w[0] > 'z')) {
    goto usage;
  }     
  if(add_gemdos_drive (w[0], argv[2])) {
    ec_stderr("added drive %c: %s\n", w[0], argv[2]);
    return 0;
  } else {
    /* it failed */
    return 1;
  }
usage:
  ec_stderr("usage: fs <drive>: <directory>\n");
  return 1;
}

/* this is not set when gemdos gets initialized,
  but when the gemdos routines have been patched, at the
  first gemdos call.
  (The first gemdos call, when the cartridge is loaded, happens
  to be call to SVersion() for the sole purpose of going here. )
*/
static int gemdos_initialized = 0;

#endif	/*!_WIN32*/

void init_gemdos(void)
{
#ifndef _WIN32
        ui_register_command("fs", gemdos_cmd_fs, 
          "usage: fs <drive>: <directory>\n"
          "This lets a Unix directory appear as a GEMDOS drive.\n"
#if 0
          "Every file name will be seen from the Atari as 8 + 3 MSDOS uppercase.\n"
#else
          "In the current version the behaviour is *unspecified* for filenames not\n"
          "conforming to the MSDOS 8 + 3 case insensitive convention. DON'T DO THIS.\n"
#endif
          "This command needs the STonX cartrige to work. The command must be run\n"
          "before the tos is booted. see also : loadcart, disk");
  
        gemdos_drives = 0;
        gemdos_initialized = 0;
#endif	/*!_WIN32*/
}

void gemdos_first_time (void)
{
#ifndef _WIN32
        UL o;
        int i;
        
        if(nocart) return;
        if (gemdos_initialized) return;
        gemdos_initialized=1;
        
        ec_stderr("Setting up native GEMDOS routines\n");
        for (i=0; i<MAXFILES; i++) 
        {
                file[i].bp = 0;
                file[i].f = -1;
        }
        for(i = 0 ; i < MAXDRIVES ; i++) {
          curpath[i][0] = 0;
        }
        SM_L(MEM(0xfa0400),LM_L(MEM(0x84)));
        SM_L(MEM(0x84),0xfa0404);
        o = LM_UL(MEM(8+LM_UL(MEM(0x4f2))));
        if (LM_UW(MEM(o+2)) < 0x102)
        {
                if ((LM_UW(MEM(o+0x1c)) >> 1) == 4) act_pd = MEM(0x873c);
                else act_pd = MEM(0x602c);
        }
        else act_pd = MEM(LM_UL(MEM(o+0x28)));
        bios_disk_init();
  ec_stderr( "nflops=%d; boot_dev=%d cmdload=%d\n",LM_W(ADDR(0x4a6)),boot_dev, LM_W(ADDR(0x482)));
#endif	/*!_WIN32*/
}

