/*
        
        mkhdboot.c  -  make a bootsector for a hard disk image.

        Disclaimer: current HDC emulation is based on possibly very inacurate 
        and incomplete information. I had no opportunity to compare with any 
        real Atari harware.

        changed to STDIO functions.
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>


typedef struct {
        unsigned char flag ;    /* 0x80 if active? */
        unsigned char id[3] ;   /* three char id ('GEM') */
        unsigned char start[4] ;        /* first sector */
        unsigned char size[4] ; /* total number of sectors */
} partition_info ;

#define NPARTS  4

/* flags for partitions */
#define PI_BOOTABLE 0x80        
#define PI_VALID 0x01   

typedef struct {
        unsigned char gap1 [0x1B6] ;    /* reserved */
        unsigned char cylinders_h ;
        unsigned char cylinders_l ;
        unsigned char heads ;
        unsigned char gap2 [1] ;                /* reserved */
        unsigned char reduced_h ;
        unsigned char reduced_l ;
        unsigned char precomp_h ;
        unsigned char precomp_l ;
        unsigned char landing_zone ;
        unsigned char seekrate_code ;
        unsigned char interleave_factor ;
        unsigned char sectors ;                 /* sectors par track */
        unsigned char size[4] ;                 /* size of disk in sectors */
        partition_info pi[NPARTS] ;             /* 4 partition descriptors */
        unsigned char bsl_start[4] ;    /* start of bad sector table */
        unsigned char bsl_count[4] ;    /* number of bad sectors */
        unsigned char magic[2] ;
} bootsector_info ;

/* in this bootsector, the sector size is assumed to be 512 bytes */


typedef struct {
  unsigned char heads ;
  unsigned char sectors ;                       /* sectors par track */
  int bootable;
  struct {
    char *name ;
    unsigned long start ;
    unsigned long size ;
    int flag;
    char id[3];
  } part[4] ;
} param ;
                
/* align : 1 if align on cylinder */
/* returns total number of sectors, or zero */

unsigned long mk_boot_sector(param *di, char *b, int align) ;

unsigned long mk_boot_sector(param *di, char *b, int align) 
{
  unsigned long size, start ;   /* all sizes are in sectors */
  unsigned long cylinder_size ;
  unsigned int cylinders ;
  int i ;
  unsigned short check ;
  bootsector_info *bs = (bootsector_info *) b ;
  
  cylinder_size = di->sectors * di->heads ;
  
  
  for(i = 0, start = 2 ; i < NPARTS; i++, start += size) {
    if(align) { /* align partitions on cylinder */
      start += cylinder_size-1 ;
      start /= cylinder_size ;
      start *= cylinder_size ;
    }
    di->part[i].start = start ;
    size = di->part[i].size ;
    if(!size) {
      bs->pi[i].flag = 0x00 ;
      bs->pi[i].start[0] = 0 ;
      bs->pi[i].start[1] = 0 ;
      bs->pi[i].start[2] = 0 ;
      bs->pi[i].start[3] = 0 ;
      bs->pi[i].size[0] = 0 ;
      bs->pi[i].size[1] = 0 ;
      bs->pi[i].size[2] = 0 ;
      bs->pi[i].size[3] = 0 ;
    }
    else {
      bs->pi[i].flag = di->part[i].flag;
      bs->pi[i].id[0] = di->part[i].id[0] ;
      bs->pi[i].id[1] = di->part[i].id[1] ;
      bs->pi[i].id[2] = di->part[i].id[2] ;
      bs->pi[i].start[0] = start >>24 ;
      bs->pi[i].start[1] = start >>16 ;
      bs->pi[i].start[2] = start >>8 ;
      bs->pi[i].start[3] = start ;
      bs->pi[i].size[0] = size >>24 ;
      bs->pi[i].size[1] = size >>16 ;
      bs->pi[i].size[2] = size >>8 ;
      bs->pi[i].size[3] = size ;
    }
  }
  
  /* just enough cylinders to hold all partitions */
  cylinders = (start + cylinder_size-1)/cylinder_size;
  
  bs->cylinders_h = cylinders >> 8 ;
  bs->cylinders_l = cylinders & 0xFF ;
  bs->heads = di->heads ;
  bs->sectors = di->sectors ;
  size = cylinders * di->heads * di->sectors ;
  bs->size[0] = size >> 24 ;
  bs->size[1] = size >> 16 ;
  bs->size[2] = size >> 8 ;
  bs->size[3] = size ;
  
  /*
    Calculate checksum
    */
  check = 0 ;
  for(i = 0 ; i < 512 ; i+= 2) {
    check += (b[i] << 8) | ( b[i+1] & 0xFF) ;
  }
  if( di->bootable ){
    check -= (b[510] << 8) | ( b[511] & 0xFF);
    check = 0x1234 - check;
    b[510] = check >> 8;
    b[511] = check & 0xFF;
  } else {
    if((check & 0xFFFF) == 0x1234) {
      b[511] ++ ;
    }
  }
  
  return size ;
}


static char buf[512] ;

int main(int argc, char **argv)
{
  /* usage : mkhddisk -o rez [-a] [-h heads] [-s sectors] [-b boot] part +  
   * part(i) is size or name of partition image (in last case, beware
   * of nsects && nheads ! )
   */
  
  param di ;
  int i, j, k, align=0 ;
  long val ;
  char *bootfile = NULL;
  char *outfile = NULL;
  FILE *f, *g;

  if(argc < 4)  goto usage ;

  /* default values : same as an ordinary floppy ! */
  
  di.heads = 2 ;
  di.sectors = 9 ;
  di.bootable = 0;
  for(j = 0 ; j < NPARTS ; j++) {
    di.part[j].size = 0 ;
    di.part[j].name = NULL;
  }
  
  i = 1 ;
  while( (i < argc) && (argv[i][0] == '-') ) {
    if(argv[i][1] && !argv[i][2]) {
      switch(argv[i][1]) {
      case 'h':
        if(i+1 == argc) goto usage;
        sscanf(argv[i+1], "%ld", &val) ;
        if(val <= 0) goto usage ;
        di.heads = val ;
        i += 2 ;
        break ;
      case 's':
        if(i+1 == argc) goto usage;
        sscanf(argv[i+1], "%ld", &val) ;
        if(val <= 0) goto usage ;
        di.sectors = val ;
        i += 2 ;
        break ;
      case 'a':
        align = 1 ;
        i++ ;
        break ;
      case 'b':
        if(i+1 == argc) goto usage;
        bootfile = argv[i+1];
        i += 2;
        break;
      case 'o':
        if(i+1 == argc) goto usage;
        outfile = argv[i+1];
        i += 2;
        break;
      default:
        goto usage ;
      }
    } else goto usage ;
  }
  if(outfile == NULL) goto usage;

  if(i+NPARTS < argc) {
    fprintf(stderr, "too many partitions\n") ; 
    exit(1) ;
  }
  for(j = 0 ; i < argc ; j++, i++) {
    if(!strcmp("0", argv[i]))
      continue ;
    val = 0 ;
    sscanf(argv[i], "%ld",&val) ;
    if(val == 0) {
      /* assume it's an image file */
      f = fopen(argv[i], "rb");
      if(f == NULL) goto fail;
      di.part[j].name = argv[i] ;
         /* get image size */
      if(fseek(f, 0, SEEK_END) == -1) goto fail;
      val = ftell(f);
      if(val == -1) goto fail;
      val = (val + 511)/512 ;
      fclose(f) ;
    }   
    di.part[j].size = val ;  
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
    for(i = 0 ; i < 512 ; i++)
      buf[i] = 0 ;
  }

  val = mk_boot_sector(&di, buf, align) ;
  if(val == 0) exit(1) ;
  
  g = fopen(outfile, "wb");
  if(g == NULL) {
    fprintf(stderr, "could not open %s\n", outfile);
    goto fail; 
  }
  
  if(512 != fwrite(buf, 1, 512, g)) goto fail;
  
  i = 1 ;
  for(j = 0 ; j < NPARTS ; j++) {
    for(k = 0 ; k < 512 ; k++) {
      buf[k] = 0 ;
    }
    fprintf(stderr, "di.part[%d].start = %ld\n", j,  di.part[j].start) ;
    fprintf(stderr, "di.part[%d].size = %ld\n", j,  di.part[j].size) ;
    for(; i < di.part[j].start ; i++) {
      if(512 != fwrite(buf, 1, 512, g)) goto fail ;
    }
    if(di.part[j].size != 0) {
      if(di.part[j].name) {
        f = fopen(di.part[j].name, "rb") ;
        if(f == NULL) goto fail;
        for(; i < di.part[j].start + di.part[j].size ; i++) {
          if(512 != fread(buf, 1, 512, f)) goto fail ;
          if(512 != fwrite(buf, 1, 512, g)) goto fail ;
        }
        fclose(f) ;
      } else {
        for(; i < di.part[j].start + di.part[j].size ; i++) {
          if(512 != fwrite(buf, 1, 512, g)) goto fail ;
        }
      }
    }
  }
  /* last sectors : */
  for(k = 0 ; k < 512 ; k++)
    buf[k] = 0 ;
  for(; i < val ; i++) {
    if(512 != fwrite(buf, 1, 512, g)) goto fail ;
  }
  fclose(g) ;
  exit(0) ;
fail:  
  perror(argv[0]);
  exit(1);
usage:
  fprintf(stderr, 
          "%s -o <file> [-a] [-h <heads>] [-s <sects>] [-b <boot>] <part> ... \n",
          argv[0] ) ;

  fprintf(stderr, "\t<boot> is the name of a master bootsector image file\n") ;
  fprintf(stderr, "\t<part> is size or name of partition image\n") ;
  fprintf(stderr,"\t(in last case, beware of nsects && nheads!)\n") ;
  exit(1) ;
}




        
        
        
        
        
        
                        
                        
                        
                
         









                
                
                





