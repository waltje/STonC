#include <stdlib.h>
#include <stdio.h>


#define VT_TRACE_INIT 0
#define VT_TRACE_RESUMING 1
#define VT_TRACE_SYNCING 2
#define VT_TRACE_RESUME 3
#define VT_TRACE_HALT 4
#define VT_TRACE_HALVING 5
#define VT_TRACE_TRIGGER 6

#define VT_TRACE_MAX 6

char *where[] = {"init", "resuming", "syncing", "resume", "halt", "halving",
   "trigger"};

static void show_trace()
{
  FILE *f = fopen("vttrace", "rb");

  struct {
    int where;
    double real_time;
    long nb_cycles;
    double f2;
    double et1;
  } a;
  
  int wh;
  char whc[10], *whp;

  if(f == NULL) {
    printf("sorry, no trace.\n");
    return;
  }

  while(fread(&a, sizeof(a), 1, f) == 1) {
    wh = a.where ;
    if(wh >= 0 && wh <= VT_TRACE_MAX) {
      whp = where[wh]; 
    } else {
      sprintf(whc, "%d", wh);
      whp = whc;
    }
    printf("%s: rt = %f, nb_cycles = %ld, f2 = %f, et1 = %f\n",
        whp, a.real_time, a.nb_cycles, a.f2, a.et1);
  }

  fclose(f);
}

int main(int argc, char **argv) 
{
  (void)argc;
  (void)argv;

  show_trace();

  exit(0);
}


