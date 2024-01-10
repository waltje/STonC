/*
  D2S : double to single (silly program to convert DISK01 and DISK02 
  to single-sided floppy images)

  Laurent Vogel, Public domain.
*/

#include <stdio.h>
#include <stdlib.h>

void convert(char *filename);
int main(int argc, char **argv);

void convert(char *filename)
{
  FILE *in, *out ;
  int c ;
  long i, j ;
  char tmp[300] ;
  long length = 9 * 512 ;
  int done = 0 ;

  if(strlen(filename) > 200) {
    printf("filename too long");
    return;
  }
  in = fopen(filename, "rb") ;
  if(in == 0) {
    printf("cannot open \"%s\"\n", filename) ;
    return ;
  }
  sprintf(tmp, "%s.out", filename) ;
  out = fopen(tmp, "wb") ;
  if(out == 0) {
    printf("cannot open \"%s\"\n", tmp) ;
    fclose(in) ;
    return ;
  }
  while(!done) {    
    for(j = 0 ; (j < length) && (!done) ; j++) {
      c = fgetc(in) ;
      if(c < 0) {
        done = 1 ;
      }
      else
        fputc(c, out) ;
    }
    for(j = 0 ; (j < length) && (!done) ; j++) {
      c = fgetc(in) ;
      if(c < 0)
        done = 1 ;
    }
  }
  fclose(in) ;
  fclose(out) ;
}


int main(int argc, char **argv)
{
  int i ;

  if(argc <= 1) {
    fprintf(stderr, "usage : d2s <files>\n") ;
    exit(1) ;
  }
  for(i = 1 ; i < argc ; i++) {
    convert(argv[i]) ;
  }
  exit(0) ;
}
