/*
 * hdc.c - emulation of hard disk and other devices on the DMA bus.
 *
 * Part of STonC (C) 1998-2002 Laurent Vogel
 * Covered by the GPL version 2 or later; see COPYING for details
 */

/*
 * Apart from the FDC and the Blitter, a number of external peripherals can 
 * be plugged to the DMA bus. DMA commands allow to address up to 8 
 * controllers, with up to 8 devices per controller.
 * 
 * A combination of a controller number and a device number is here called a 
 * Client. It is possible to maintain up to 64 clients. We treat each client 
 * as an independant entity that can receive instructions from the DMA bus. 
 * 
 * Emulated instructions are : read or write a number of sectors to or from
 * a device; seek to a given position to the device.
 * Other instructions are ignored or return errors.
 * 
 * Client types: 
 * - Hard disk : a disk image file of fixed length which
 *   is an integral multiple of 512 sectors. Details of the content,
 *   such as bootsectors or partition table are not handled by this
 *   client. 
 *   (hard disks begin at sector 0. Sector 0 contains the partition
 *   table. The partitions themselves begin at sector 1.) 
 * 
 * - Tape : a tape archive image. Writing at the beginning of the tape 
 *   causes the file to be reopened empty, then written to. The file is not 
 *   altered when reading.
 *   (Tapes begin at sector 1.)
 *
 * - other types : not for now. ideas include virtual disks created from 
 *   a directory structure, or virtual tapes, or hard disks aware of 
 *   partitions, or even ethernet cards...
 *   
 * Since only one peripheral can use the DMA bus at a time, we decide that
 * only one client can be active at a time. The active client is the client 
 * number hdc_client, and it is active when hdc_busy is not zero. There is
 * always a client busy when hdc_busy is not zero.
 * 
 * Instructions are sent to the DMA bus as six bytes. Only after the six 
 * bytes have been received can a given client execute the instruction and 
 * possibly become busy for a certain time doing the job. It is not 
 * possible for now to interrupt a busy client and report a failure.
 * 
 */

#include "defs.h"
#include "mem.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "vtime.h"


#include "hdc.h"

static int hdc_inited = 0;

#define HDC_DEBUG 0

static UB hdc_command[6] ;
static int hdc_comm_index ;     /* index of next command byte to receive */

B hdc_status ;

struct hdc_client_info {
  int type;
  int contr;
  int dev;
  char *fname;
  FILE *fp;
  long sectors;
  void *more_info;
};

typedef struct hdc_client_info *Client ;

#define NR_OF_CONTR 8
#define NR_OF_DEV   8
#define CLIENT_NR(contr,dev) ((contr << 3) | dev)
#define MAX_CLIENTS  64

static Client hdc_client_info[MAX_CLIENTS];


/*
 * private prototypes   
 */

static int hdc_hd_init(Client h);
static int hdc_tape_init(Client h);
static void hdc_do_command(Client h);
static void hdc_go_busy(int client_nr);
static void hdc_finish_command(void * dummy);


int hdc_cmd_hd(int argc, char **argv)
{
  assert(hdc_inited);
  if((argc != 4) || (argv[1][0] < '0') 
     || (argv[1][0] > '7') || (argv[1][1] != 0)
     || (argv[2][0] < '0') || (argv[2][0] > '7') 
     || (argv[2][1] != 0)) {
    ec_stderr("usage: hd <contr> <dev> <file>\n");
    return 1;
  }
  return hdc_add_drive (HDC_TYPE_HD, argv[1][0]-'0', 
                 argv[2][0]-'0', argv[3]);
}

int hdc_cmd_tape(int argc, char **argv)
{
  assert(hdc_inited);
  if((argc != 4) || (argv[1][0] < '0') 
     || (argv[1][0] > '7') || (argv[1][1] != 0)
     || (argv[2][0] < '0') || (argv[2][0] > '7') 
     || (argv[2][1] != 0)) {
    ec_stderr("usage: tape <contr> <dev> <file>\n");
    return 1;
  }
  return hdc_add_drive (HDC_TYPE_TAPE, argv[1][0]-'0', 
                 argv[2][0]-'0', argv[3]);
}



#define HDC_BUSY_COUNT 100 ;
int hdc_busy ;    /* a flag indicating that hdc is busy */
int hdc_client ;  /* the current busy client */

int hdc_nr_of_clients = 0;

void hdc_reset(void) 
{
  assert(hdc_inited);
  hdc_comm_index = 0 ;
  hdc_status = 0 ;
  hdc_busy = 0 ;
}

/* return 0 if success */

int hdc_add_drive(int type, int contr, int dev, char *fname)
{
  int client_nr;
  Client h;
  int r;

  assert(hdc_inited);
  if((contr < 0) || (contr > 7) || (dev < 0) || (dev > 7)) {
    ec_stderr("HDC: bad device number [%d:%d]\n", contr, dev);
    return 1;
  }
  client_nr = CLIENT_NR(contr, dev);
  if(hdc_client_info[client_nr] != NULL) {
    if(hdc_busy && (hdc_client == client_nr)) {
      ec_stderr("HDC: the device [%d:%d] is busy\n", contr, dev);
      return 1;
    }
    if(hdc_remove_client(contr, dev)) {
      return 1;
    }
  }
  hdc_client_info[client_nr] = malloc(sizeof(struct hdc_client_info));
  if(hdc_client_info[client_nr] == NULL) {
    ec_stderr("HDC: cannot allocate client info\n");
    return 1;
  }
  h = hdc_client_info[client_nr];
  h->type = type;
  h->contr = contr;
  h->dev = dev;
  h->fname = xstrdup(fname);

  switch(h->type) {
  case HDC_TYPE_HD:
    r = hdc_hd_init(h);
    if(r) {
      free(h);
      hdc_client_info[client_nr] = NULL;
      return r;
    }
    break;
  case HDC_TYPE_TAPE:
    r = hdc_tape_init(h);
    if(r) {
      free(h);
      hdc_client_info[client_nr] = NULL;
      return r;
    }
    break;
  default:
    ec_stderr("HDC: wrong device type %d\n", type);
    free(h);
    hdc_client_info[client_nr] = NULL;
    return 1;
  }
  ec_stderr("HDC : added device [%d:%d] (file '%s')\n",
    h->contr, h->dev, h->fname);
  hdc_nr_of_clients ++;
  return 0;
}

int hdc_remove_client(int contr, int dev)
{
  int client_nr = CLIENT_NR(contr, dev);
  Client h = hdc_client_info[client_nr];

  assert(hdc_inited);

  if(hdc_busy && (hdc_client == client_nr)) {
    ec_stderr("HDC: removing a busy drive [%d:%d]\n", contr, dev);
    return 1;
  }
  switch(h->type) {
  case HDC_TYPE_HD:
    fclose(h->fp);
    break;
  case HDC_TYPE_TAPE:
    fclose(h->fp);
    break;
  default:
    break;
  }
  hdc_client_info[client_nr] = NULL;
  free(h->fname);
  free(h);
  hdc_nr_of_clients --;
  return 0;
}

static int hdc_hd_init(Client h)
{
  long count;
  int err;
  h->fp = fopen(h->fname, "rb+") ;
  if(h->fp == NULL) {
    /* TODO: allow to open it read-only */
    ec_stderr( "HDC: could not open file '%s'\n", h->fname) ;
    return 1;
  }
  /* get the disk size now and prevent later expanding it */
  count = 0;
  err = fseek(h->fp, 0L, SEEK_END);
  if(err != 0) {
    ec_stderr("HDC : cannot fseek() on file '%s'\n", h->fname);
    fclose(h->fp);
    return 1;
  }
  count = ftell(h->fp);
  if(count <= 0) {
    ec_stderr("HDC : cannot ftell() on file '%s'\n", h->fname);
    fclose(h->fp);
    return 1;
  }     
  if(count & 511L) {
    ec_stderr("HDC: warning: file '%s' has an incomplete sector\n", h->fname);
  }
  h->sectors = count / 512L;
  if(h->sectors <= 10) {
    ec_stderr("HDC: warning: hard disk image has only %ld sectors\n", h->sectors);
  }
  /* TODO : check that the disk has a decent bootsector ? */
  return 0;
}

static int hdc_tape_init(Client h)
{
  h->fp = fopen(h->fname, "ab+");
  if(h->fp == NULL) {
    ec_stderr("HDC: could not open file '%s'\n", h->fname);
    return 1;
  }
  /* no other checks for tapes */
  return 0;
}


void hdc_init(void)
{
  int i;
  if(!hdc_inited) {
    for(i = 0 ; i < MAX_CLIENTS ; i++) {
      hdc_client_info[i] = NULL;
    }
    hdc_nr_of_clients = 0;
    hdc_inited = 1;
  }
  hdc_reset() ;

  ui_register_command("hd", hdc_cmd_hd,
"usage: hd <contr> <dev> <file>\n"
"TODO");

  ui_register_command("tape", hdc_cmd_tape,
"usage: tape <contr> <dev> <file>\n"
"TODO");

}

#define HDC_A0 ( (LM_UB(MEM(0xFF8607)) >> 1) & 1 )
#define HDC_A1 ( (LM_UB(MEM(0xFF8607)) >> 2) & 1 ) 
 
extern void mfp_set_gpip_bit(unsigned char mask, unsigned char value) ;

static int hdc_driver, hdc_opcode, hdc_device, hdc_count, hdc_cntrl ;
static long hdc_offset ;



void hdc_send(B v) 
{
  int client_nr;
  Client h;
  /*
    TODO : check the corect values of A0 and A1...
  */
#if HDC_DEBUG > 2
  ec_stderr( "hdc_send(0x%02x)\n", v) ;
#endif   

  if(hdc_nr_of_clients == 0) {
    ec_stderr("HDC: talking but no client\n");
    return;
  }

  if(hdc_busy) {
    ec_stderr( "HDC: sending command while busy\n") ;
    return ;
  }
 
#if 0
  if(hdc_comm_index == 0) {
    /* start a new command */
    if(HDC_A1) {
      ec_stderr( "HDC: received command with A1 high\n") ;
    }           
  } else {
    if(!HDC_A1) {
      ec_stderr( "HDC: in a command with A1 low\n") ;
    }
  }
#endif
  
  hdc_command[hdc_comm_index++] = v ;
  
  if(hdc_comm_index < 6) {
    /* 
       command bytes handshaking with IRQ* 
       apparently, the fdc-dma interrupt is set back to its high 
       level (no interrupt) when sending another byte from dma.
    */
    mfp_set_gpip_bit(0x20, 0) ;   
    return ;
  }
  
  hdc_comm_index = 0 ;
        
  /* got complete command */

  hdc_driver = (hdc_command[0] >> 5) & 7 ;
  hdc_opcode = hdc_command[0] & 0x1F ;
  hdc_device = (hdc_command[1] >>5) & 7 ;
  hdc_offset = ( ( (unsigned long) (hdc_command[1]) & 7uL) << 16uL) 
    | ( (unsigned long) (hdc_command[2])  << 8uL) 
    | ( (unsigned long) hdc_command[3] ) ;
  hdc_count = hdc_command[4]  ;
  hdc_cntrl = hdc_command[5]  ;
  
#if HDC_DEBUG
  ec_stderr( "HDC command(%d, 0x%02x, %d, 0x%06lx, %d, %d)\n",
          hdc_driver, hdc_opcode, hdc_device, hdc_offset, hdc_count, 
          hdc_cntrl) ;
#endif
          
  client_nr = CLIENT_NR(hdc_driver, hdc_device);
  h = hdc_client_info[client_nr];
  if(h == NULL) {
    ec_stderr("HDC: talking to uninitialised client [%d:%d]\n", 
              hdc_driver, hdc_device);

#if 0
    hdc_status = 0x30 ; /* controller self test failed ? */
#endif
    hdc_status = 0x25 ; /* invalid drive number */
    mfp_set_gpip_bit(0x20, 0) ;
    return;
  }
  hdc_do_command(h);
  if(!hdc_busy) {
    hdc_go_busy(-1);
  }
}
  

static void hdc_go_busy(int client_nr)
{
  /*
    when we've got a complete command, wait some time before 
    acknowledging by setting hdc_busy. 
  */
  hdc_busy = 1 ;
  hdc_client = client_nr;

  set_alarm(0.0001, hdc_finish_command, 0) ;
}

extern int fdc_int ;

static void hdc_finish_command(void *dummy)
{
  (void)dummy;
  
  /* called when hdc_busy reaches 0, to finish the job */
  hdc_busy = 0 ;

#if HDC_DEBUG
  ec_stderr( "hdc_finish_command\n") ;
  ec_stderr("HDC_status = %d\n", hdc_status);
#endif
  /* publish the status : */
  /* done already */
  
  /* signal interrupt */
  mfp_set_gpip_bit(0x20, 0) ;
}


#define READ 0
#define WRITE 1

static int hdc_do_seek(Client h) ;
static void hdc_do_read_write(Client h, int rw) ;


void hdc_do_command(Client h) 
{
  if(hdc_cntrl != 0) {
    ec_stderr( "HDC: non null cntrl value 0x%02x\n", hdc_cntrl) ;
    hdc_status = 0x24 ; /* invalid argument */
    return ;
  }
  
#if HDC_DEBUG
#  define HDC_TRACE_CMD(name) ec_stderr( "HDC command : %s\n",name)
#else
#  define HDC_TRACE_CMD(name) /**/
#endif

  switch(hdc_opcode) {
  case 0x00:            /* test unit ready */
    HDC_TRACE_CMD( "test unit ready" ) ;
    hdc_status = 0 ;
    return ;
  case 0x01:            /* restore */
    HDC_TRACE_CMD( "restore" ) ;
    hdc_reset() ;
    hdc_status = 0 ;
    return ;
  case 0x03:            /* request sense */
    HDC_TRACE_CMD( "request sense" ) ;
    hdc_status = 0 ;
    return ;
  case 0x04:            /* format drive */
    HDC_TRACE_CMD( "format drive" ) ;
    hdc_status = 0x20 ;         /* invalid opcode */
    return ;
  case 0x08:            /* read */
    HDC_TRACE_CMD( "read" ) ;
    hdc_do_read_write(h, READ) ;
    return ;
  case 0x0a:            /* write */
    HDC_TRACE_CMD( "write" ) ;
    hdc_do_read_write(h, WRITE) ;
    return ;
  case 0x0b:            /* seek */
    HDC_TRACE_CMD( "seek" ) ;
    hdc_do_seek(h) ;
    return ;
  case 0x12:            /* inquiery command */
    HDC_TRACE_CMD( "inquiery" ) ;
    hdc_status = 0x20 ;
    return ;
  case 0x15:            /* mode select */
    HDC_TRACE_CMD( "mode select" ) ;
    hdc_status = 0x20 ;
    return ;
  case 0x1b:            /* seek to shipping position */
    HDC_TRACE_CMD( "seek to shipping" ) ;
    hdc_status = 0 ;
    return ;
  default:
    ec_stderr( "HDC : unknown opcode 0x%02x\n", hdc_opcode) ;
    hdc_status = 0x20 ;
    return ;
  }
}


static void hdc_do_read_write(Client h, int rw) 
{
  unsigned long addr ;
  long count ;

  if(h->type == HDC_TYPE_TAPE) {
    hdc_offset --;
    if(hdc_offset <0) {
/* ec_stderr("HDC: tape access at sector 0\n"); */
      hdc_status = 0x11 ;       /* uncorrectable data error ? */
      return;
    }
  }

  if(hdc_do_seek(h) == -1)
    return  ;
  
  addr = (LM_UB(MEM(0xff8609))<<16)|(LM_UB(MEM(0xff860b))<<8)
                        |LM_UB(MEM(0xff860d));

#if 0
  ec_stderr, "HDC: DMA addr =0x%08lx\n", addr) ;  
#endif

  if(!NORMAL_ADDRESS_W_B(addr)) {
    ec_stderr( "HDC: wrong dma address 0x%08lx\n", addr) ;
    hdc_status = 0x11 ; /* uncorrectable data error ? */
    return ;
  }
  if(!NORMAL_ADDRESS_W_B(addr+512*hdc_count-1)) {
    ec_stderr( "HDC: wrong dma address 0x%08lx\n", addr) ;
    hdc_status = 0x11 ; /* uncorrectable data error ? */
    return ;
  }

  if(rw == READ) {
    count = fread(MEM(addr), 512, hdc_count, h->fp) ;
  } else {
    if(h->type == HDC_TYPE_TAPE) {
      if(hdc_offset == 0) {
        /* writing ot the beginning of the tape means reopen the file */
        h->fp = freopen(h->fname, "wb+", h->fp);
        if(h->fp == NULL) {
          ec_stderr("HDC: freopen failed on client [%d:%d]\n", h->contr, 
                        h->dev);
                      ec_stderr("errno = %d: %s\n", errno, strerror(errno));
          hdc_remove_client(h->contr, h->dev);
          hdc_status = 0x25 ;   /* invalid drive number */
          return;
        }
        
        h->sectors = hdc_count;
      } 
    } else {
      /* truncate to the end of file */
      if(hdc_offset + hdc_count > h->sectors) {
        ec_stderr("HDC: truncating \n");
        hdc_count = h->sectors - hdc_offset;
      }
    }
    if(hdc_count < 0) {
      hdc_status = 0x11 ; /* uncorrectable data error ? */
      return;
    }
    count = fwrite(MEM(addr), 512, hdc_count, h->fp) ;
  }
  if(count != hdc_count) {
    hdc_status = 0x11 ; /* uncorrectable data error ? */
  } else {
    hdc_status = 0 ;
  }
      
  addr += count;
  SM_UB(MEM(0xfff8609),addr>>16);
  SM_UB(MEM(0xfff860b),addr>>8);
  SM_UB(MEM(0xfff860d),addr);

  hdc_go_busy(CLIENT_NR(h->contr, h->dev));
}

static int hdc_do_seek(Client h)
{
  long offset = hdc_offset * 512 ;
  return fseek(h->fp, offset, SEEK_SET) ;
}






