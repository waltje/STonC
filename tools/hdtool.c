/*
 * hdtool.c - manage Atari ST hard disk images
 *
 * (C) 2000-2002 Laurent Vogel
 * Covered by the GPL version 2 or later (http://www.gnu.org/copyleft/)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

typedef unsigned char uchar;
typedef unsigned long ulong;

typedef struct {
	uchar flag;	    /* 0x80 if active */
	uchar id[3];	  /* three char id ('GEM') */
	uchar start[4];	/* first sector */
	uchar size[4];	/* total number of sectors */
} partition_info;

#define NPARTS 4

/* flags for partitions */
#define PI_BOOTABLE 0x80	
#define PI_VALID 0x01	

typedef struct {
	uchar gap1[0x1B6];	/* reserved */
	uchar cylinders_h;
	uchar cylinders_l;
	uchar heads;
	uchar gap2[1];		/* reserved */
	uchar reduced_h;
	uchar reduced_l;
	uchar precomp_h;
	uchar precomp_l;
	uchar landing_zone;
	uchar seekrate_code;
	uchar interleave_factor;
	uchar sectors;			/* sectors par track */
	uchar size[4];			/* size of disk in sectors */
	partition_info pi[NPARTS];		/* 4 partition descriptors */
	uchar bsl_start[4];	/* start of bad sector table */
	uchar bsl_count[4];	/* number of bad sectors */
	uchar magic[2];
} bootsector_info;

/* in this bootsector, the sector size is assumed to be 512 bytes */

//if sizeof(bootsector_info) != 512

typedef struct {
  uchar heads;
  uchar sectors;			/* sectors par track */
  int bootable;
  struct part {
    char *name;
    ulong start;
    ulong size;
    ulong seek;
    int flag;
    char id[3];
  } part[4];
} param;

/*
 * macros to manipulate words and longs in motorola format
 */

#define SET_LONG(a,b) \
  ((a)[0] = ((ulong)(b)) >> 24, \
   (a)[1] = ((ulong)(b)) >> 16, \
   (a)[2] = ((ulong)(b)) >> 8, \
   (a)[3] = (ulong)(b))
#define GET_LONG(a) \
  ((((ulong)(a)[0]) << 24) | ((a)[1] << 16) | ((a)[2] << 8) | (a)[3])

#define SET_WORD(a,b) \
  ((a)[0] = ((unsigned int)(b)) >> 8, \
   (a)[1] = (unsigned int)(b))
#define GET_WORD(a) ((((unsigned int)(a)[0]) << 8) | (a)[1])

/* align : 1 if align on cylinder */
/* returns total number of sectors, or zero */

ulong mk_boot_sector(param *di, uchar *b, int align);

ulong mk_boot_sector(param *di, uchar *b, int align) 
{
  ulong size, start;	/* all sizes are in sectors */
  ulong cylinder_size;
  unsigned int cylinders;
  int i;
  bootsector_info *bs = (bootsector_info *) b;
  
  cylinder_size = di->sectors * di->heads;
  
  for(i = 0, start = 2; i < NPARTS; i++, start += size) {
    if(align) {	/* align partitions on cylinder */
      start += cylinder_size-1;
      start /= cylinder_size;
      start *= cylinder_size;
    }
    di->part[i].start = start;
    size = di->part[i].size;
    if(!size) {
      bs->pi[i].flag = 0x00;
      SET_LONG(bs->pi[i].start, 0)
      SET_LONG(bs->pi[i].size, 0)
    } else {
      bs->pi[i].flag = di->part[i].flag;
      memcpy(bs->pi[i].id, di->part[i].id, 3);
      SET_LONG(bs->pi[i].start, start);
      SET_LONG(bs->pi[i].size, size);
    }
  }
  
  /* just enough cylinders to hold all partitions */
  cylinders = (start + cylinder_size - 1) / cylinder_size;
  
  bs->cylinders_h = cylinders >> 8;
  bs->cylinders_l = cylinders & 0xFF;
  bs->heads = di->heads;
  bs->sectors = di->sectors;
  size = cylinders * di->heads * di->sectors;
  SET_LONG(bs->size, size);
  
  /*
   * Calculate checksum
   */
  { 
    unsigned int sum = 0;
    for(i = 0; i < 512; i += 2) {
      sum += GET_WORD(b + i);
    }
    if(di->bootable){
      /* make it bootable */
      sum -= GET_WORD(b + 510);
      sum = 0x1234 - sum;
      SET_WORD(b + 510, sum);
    } else {
      /* make sure it is not bootable */
      if((sum & 0xFFFF) == 0x1234) {
        b[511] ++;
      }
    }
  }
  return size;
}

static char buf[512];

int try_part(char *arg, struct part *p)
{
  char *s; 
  int n;
  ulong seek, size;
  FILE *f;
  bootsector_info *bs = (bootsector_info *) buf;
  
  n = strlen(arg);
  if(n < 2 || arg[n-2] != ':' || arg[n-1] < '0' || arg[n-1] > '3')
    return 0;
  
  s = xstrdup(arg);
  if(s == NULL) return 0;
  s[n-2] = 0;
  n = arg[n-1] - '0';
  f = fopen(s, "rb");
  if(NULL == f) {
    fprintf(stderr, "could not open %s\n", s);
    return 0;
  }
  if( 512 != fread(buf, 1, 512, f)) {
    fprintf(stderr, "%s: could not read bootsector\n", s);
    fclose(f);
    return 0;
  }
  seek = GET_LONG(bs->pi[n].start);
  size = GET_LONG(bs->pi[n].size);
  if(fseek(f, (size + seek) * 512 -1, SEEK_SET) != 0) {
    fprintf(stderr, "%s: could not seek at end of partition\n", s);
    fclose(f);
    return 0;
  }
  p->seek = seek * 512;
  p->size = size;
  p->name = s;
  p->flag = bs->pi[n].flag;
  memcpy(p->id, bs->pi[n].id, 3);
  fclose(f);
  return 1;
}

int usage(int fatal)
{
  fprintf(stderr, 
"hdtool [ <option> ... ] <action> [ <option> ... ]\n\n"
"one and only one action must be given:\n"
"  -h, --help     display this help\n"
"  --version      display the version\n"
"  -i <img>       display the partition table of disk image <img>\n"
"  -x <img>:<n>   extract partition <n> from disk image <img>\n"
"  -c <part> ...  create a disk image from up to 4 partition specifiers.\n"
"<part> is a number of sectors, or a size in kbytes (e.g. 512k or 2M)\n"
"or a file name or <img>:<n> (partition <n> of disk image <img>)\n\n"
  );
  fprintf(stderr, 
"other options:\n"
"  -o <file>      result goes in file <file>\n"
"  -v             print verbose messages\n"
"  -a             align partitions on track boundaries\n"
"  -h <heads>     number of heads when creating a disk\n"
"  -s <sects>     number of sectors per track when creating a disk\n"
"  -b <boot>      get the bootsector from file <boot>\n"
  );
  if(fatal) {
    exit(EXIT_FAILURE);
  }
}


int main(int argc, char **argv)
{
  param di;
  int i, j, k, align=0;
  long val;
  char *imgfile = NULL;
  char *bootfile = NULL;
  char *outfile = NULL;
  FILE *f, *g;
  enum {
    none = 0,
    help,
    version,
    info,
    extract,
    create
  } action = none;

  /* default values : same as an ordinary floppy ! */
  
  di.heads = 2;
  di.sectors = 9;
  di.bootable = 0;
  for(j = 0; j < NPARTS; j++) {
    di.part[j].size = 0;
    di.part[j].seek = 0;
    di.part[j].name = NULL;
  }
  
  while (--argc > 0) {
    char *a = *++argv;
    if (a[0] != '-') usage(1);
    switch (a[1]) {
    case 'i': 
      if (action != none || --argc <= 0) usage(1);
      action = info;
      imgfile = *++argv;
      break;
    case 'x': 
      if (action != none || --argc <= 0) usage(1);
      action = extract;
      imgfile = a = xstrdup(*++argv);
      i = strlen(a);
      if (i < 3 || a[i-2] != ':' || a[i-1] > '4' || a[i-1] < '1') usage(1);
      partnum = a[i-1]-'0';
      break;
    case 'c': 
      if (action != none || argc <= 1) usage(1);
      action = create;
      for(j = 0; j < NPARTS && --argc > 0; j++) {
        a = *++argv;
        if (a[0] == '-') break;
        di.part[j].size = 0;
        di.part[j].seek = 0;
        di.part[j].name = NULL;
      }
  
     
  
  i = 1;
  while( (i < argc) && (argv[i][0] == '-') ) {
    if(argv[i][1] && !argv[i][2]) {
      switch(argv[i][1]) {
      case 'h':
        if(++i >= argc) usage(1);
        sscanf(argv[i], "%ld", &val);
        if(val <= 0) usage(1);
        di.heads = val;
        break;
      case 's':
        if(++i >= argc) usage(1);
        sscanf(argv[i], "%ld", &val);
        if(val <= 0) usage(1);
        di.sectors = val;
        break;
      case 'a':
        align = 1;
        break;
      case 'b':
        if(++i >= argc) usage(1);
        bootfile = argv[i];
        break;
      case 'o':
        if(++i >= argc) usage(1);
        outfile = argv[i];
        break;
      default:
        usage(1);
      }
    } else usage(1);
  }
  if(outfile == NULL) usage(1);

  if(i+NPARTS < argc) {
    fprintf(stderr, "too many partitions\n"); 
    exit(1);
  }
  for(j = 0; i < argc; j++, i++) {
    if(!strcmp("0", argv[i]))
      continue;
    if(try_part(argv[i], &di.part[j])) {
      continue;
    }
    val = 0;
    sscanf(argv[i], "%ld",&val);
    if(val == 0) {
      /* assume it's an image file */
      f = fopen(argv[i], "rb");
      if(f == NULL) goto fail;
      di.part[j].name = argv[i];
         /* get image size */
      if(fseek(f, 0, SEEK_END) == -1) goto fail;
      val = ftell(f);
      if(val == -1) goto fail;
      val = (val + 511)/512;
      fclose(f);
    }   
    di.part[j].size = val;  
    di.part[j].flag = 0x81;
    di.part[j].id[0] = 'G';
    di.part[j].id[1] = 'E';
    di.part[j].id[2] = 'M';

  }

  if(bootfile) {
    f = fopen(bootfile, "rb");
    if(f == NULL) {
      fprintf(stderr, "could not open %s\n", bootfile);
      goto fail;
    }
    if(512 != fread(buf, 1, 512, f)) {
      fprintf(stderr, "could not read boot sector\n");
      goto fail;
    }
    fclose(f);
    di.bootable = 1;
  } else {
    /* when in doubt, zero it */
    for(i = 0; i < 512; i++)
      buf[i] = 0;
  }

  val = mk_boot_sector(&di, buf, align);
  if(val == 0) exit(1);
  
  g = fopen(outfile, "wb");
  if(g == NULL) {
    fprintf(stderr, "could not open %s\n", outfile);
    goto fail; 
  }
  
  if(512 != fwrite(buf, 1, 512, g)) goto fail;
  
  i = 1;
  for(j = 0; j < NPARTS; j++) {
    if(verbose) {
      fprintf(stderr, "di.part[%d].start = %ld\n", j,  di.part[j].start);
      fprintf(stderr, "di.part[%d].size = %ld\n", j,  di.part[j].size);
    }
    if(i < di.part[j].start) {
      memset(buf, 0, 512);
      for(; i < di.part[j].start; i++) {
        if(512 != fwrite(buf, 1, 512, g)) goto fail;
      }
    }
    if(di.part[j].size != 0) {
      if(di.part[j].name) {
        f = fopen(di.part[j].name, "rb");
        if(f == NULL) goto fail;
        if(di.part[j].seek != 0) {
          if(0 != fseek(f, di.part[j].seek, SEEK_SET)) goto fail;
        }
        for(; i < di.part[j].start + di.part[j].size; i++) {
          if(512 != fread(buf, 1, 512, f)) goto fail;
          if(512 != fwrite(buf, 1, 512, g)) goto fail;
        }
        fclose(f);
      } else {
        for(; i < di.part[j].start + di.part[j].size; i++) {
          if(512 != fwrite(buf, 1, 512, g)) goto fail;
        }
      }
    }
  }
  /* last sectors : */
  memset(buf, 0, 512);
  for(; i < val; i++) {
    if(512 != fwrite(buf, 1, 512, g)) goto fail;
  }
  fclose(g);
  exit(0);
fail:  
  perror(argv[0]);
  exit(1);
}




        
        
        
        
        
        
                        
                        
                        
                
         









                
                
                





