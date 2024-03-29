/*
 * vtime.c : time handling utilities
 *
 * Copyright (C) 1998-2001 Laurent Vogel 
 * This file is part of EmulC, the Emulator on Curses library.
 *
 * This is free software covered by the GPL version 2 or later, and
 * comes with NO WARRANTY - read the file COPYING for details.  
 */


/*
#define VT_TRACE
*/

/*

  Principle
  ---------

  Almost all emulated hardware needs to spend time before the
  requested tasks is done. FDC and HDC must be somewhat slow,
  because if they finish their job instantaneously some software
  won't have time to prepare to waiting for them, especially if 
  they rely on being interrupted when the hardware task finishes.
  
  The idea here is to maintain an "estimated time" which is the basis 
  for declaring alarms and scheduling tasks. the estimated time need not 
  necessarily be very accurate, but the resolution must allow to 
  trigger an alarm every tenth of millisecond (which corresponds to a 
  single bit transfer on a serial line at 9600 baud). The estimated time 
  is derived from a number of atomic events called "cycles".

  Interface
  ---------

  The time module is called regularly with spent_cycles(<number>),
  where number is the number of cycles spent since last invocation.
  The various hardware tasks emulate their spending time by having
  the time module call a function submitted by them after a certain 
  amount of time. This can only happen when the time module is given 
  hand (by spent_cycles()). The hardware tasks are not prioritized.
        
  example: to have the FDC spend 4 ms before finishing, do this:
        
  static int fdc_busy = 0; 
                
  void do_some_fdc_job() 
  {
    if(fdc_busy) return ;
    ...
    set_alarm(4.0E-3, fdc_remind, 0) ;
    fdc_busy = 1 ;
    return;
  }
        
  void fdc_remind(void *arg)
  {
    if (!fdc_busy) fdc_error(...) ;
    fdc_busy = 0 ;
    fdc_report_job_done(...);
  }
        
  
  Internals
  ---------

  Since the actual timers that may be available in an operating system 
  or programming library are not always usable or portable, we choose to
  maintain our own estimated time by counting individual events called
  cycles (for instance one cycle every instruction of the emulated 
  machine). Regularly we obtain the real time and adjust the factor of 
  conversion between cycles and time. The time during which we do not 
  change the factor of conversion (because the real time has not been 
  detected to change, for instance due to the resolution of the real 
  time clock) is called a period.

  The tricky part is to know
  - when to look at the real time,
  - what new factor to choose,
  - how to initiate this.

  When to look at the real time :
  
  Let us assume the function get_real_time() returns the real time 
  with a resolution of 1 second; assume that we only care of being 
  accurate to the tenth of second; assume that the estimated time 
  never goes more than twice slower at a given period than the period 
  before; then we need only to look at the real time every 1/20 second 
  estimated time.

  What new factor to choose :

  Assume we are at the end of period p1. The real time was rt1 at the 
  beginning of p1 and is now rt2. The estimated time was et1 at the 
  beginning of p1 and is now et2. The number of cycles was n1 at the 
  beginning of p1 and is now n2. We want to compute the factor f2 that 
  we are going to use to compute the estimated time during the next 
  period, p2 :
  
  (estimated time during p2)  et = et2 + f2 (n - n2)
  
  We want that at the end of p2 the estimated time equals the real time :
  
  (goal)  rt3 = et3 = et2 + f2 (n3 - n2)
  
  We can guess that during the next period p2, the time per cycle tpc will 
  be the same than during p1 :
  
  (tpc continuity)  tpc = (n3 - n2)/(rt3 - rt2) = (n2 - n1)/(rt2 - rt1)
  
  This gives us this ugly formula :
  
  (f2 formula)  f2 = (rt3 - et2)(rt2 - rt1) / (rt3 - rt2)(n2 - n1)
  
  This can only be negative if et2 is greater than rt3. This should not 
  happen often if the factor has been slowed when et went past rt2 during 
  period p1. One suggestion is, when et goes past rt2, then halve the 
  factor. When et still goes past rt3, halve the factor again. And never 
  use formula f2 if its result is negative.
  
  How to initiate this :
  
  Initially choose f1 = epsilon very small. The time will be very slow.
  We must look at the real clock every delta_t, dt. Choose initially 
  dt = epsilon. When initializing, if the real time has not changed,
  then double dt. Eventually the real time will change. Forget then the 
  initial value of dt, and set dt to the regular value. (alternatively,
  divide then dt by 10 and keep this value as the regular value.)
  
  
  Halting and resuming :
  
  Halting the emulation, and resuming a minute later causes the emulated
  time to differ from the real time. The virtual timing environment will 
  keep these times different, the emulator real time being the "real time 
  that flows only when the emulator runs", differing from the "outside 
  world real time". The emulator real time is defined to be the outside 
  world real time minus a delta. The delta changes only when the emulator 
  starts or resumes. Note that the origin of the emulator real time is 
  never seen from within the emulator.

  remaining issues :

  in fact this cannot work when the machine is too slow : it will happen
  than an alarm will set itelf again so fast than no other alarm have
  time to be triggered. This is a big unsolved issue. The only solution
  to this right now is to add a watch dog counter that forcefully syncs
  with the real time every 1000 alarms.
  
  
*/




/*
  Implementation :
  
  - all time units in double. An implementation with no floats could be
  written in the future if needed.
  
*/

/* choose one and only one way of obtaining time */
#define VT_TIME 0       /* time()           POSIX ? */
#define VT_TIMEOFDAY 1  /* gettimeofday()   BSD  */
#define VT_CLOCK 0      /* clock()          ANSI */

/* choose one and only one way of sleeping for a period */
#define VT_SLEEP 1  /* sleep()   unistd.h */
#define VT_USLEEP 0  /* usleep() */
#define VT_SELECT 0  /* select()  BSD? */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "emulc.h"   /* for ec_stderr() and assert() */
#include "vtime.h"

static long n2_n1 = 0;   /* (n2 - n1) */

static double rt1, rt2, rt3 ;
static double et1, et2 ;
static double f2;
static double dt;       
static double regular_dt;   /* check real time every dt estimated time */
static double epsilon;

static double period_time;  /* the length of a period, real time */


/*
        8 MHz clock => 1 cycle is 0.125 microsecond.
 */
#define TIME_PER_CYCLE 0.000000125



#define MAX_ALARMS 30

static struct my_alarm {
  double when ;
  reminder_type func ;
  void *arg ;
  char name[10] ;
} my_alarms[MAX_ALARMS] ;

static int nb_alarms ;
static double first_alarm_time ;

long first_alarm_cycle ;
long nb_cycles ;

static int sync_watch_dog ;

#define VT_NOT_INITIALIZED 0
#define VT_HALTED    1
#define VT_RESUMING  2
#define VT_RUNNING   3

static int vtime_status = VT_NOT_INITIALIZED ;

/* machine dependant */
static double owrt;
static void vt_init_periods(void);
static double get_real_time(void);
static void set_owrt_delta(void);
static double offset;
static void vt_sleep(double delay);

/* private */
static void vt_syncing_alarm(void * dummy);
static void vt_resuming_alarm(void * dummy);
static void vt_check_first_alarm(void);
static void empty_reminder(void * dummy);

/* public */
void vt_init(void);
void vt_halt(void);
void vt_resume(void);
void trigger_first_alarm(void);
void set_alarm_name(double delay, reminder_type func, void * arg, char *name);
void set_alarm(double delay, reminder_type func, void * arg);
void clear_alarm_by_func(reminder_type func);
void clear_alarm(reminder_type func, void * arg); 


/***************** machine dependant routines ****************/

#if VT_SLEEP

#ifdef _WIN32
# include <windows.h>
#else
# include <unistd.h>
#endif

static void vt_sleep(double delay)
{
  double now = get_real_time();
  double then = now + offset + delay;
  int n;
  delay += offset;
  n = delay;
  if(n >= 1) {
#ifdef _WIN32
    Sleep(n*1000);
#else
    sleep(n);
#endif
    now = get_real_time();
    /* TODO, what if now > then ? */
    offset = then - now;
  }
}
#endif





#if VT_TIMEOFDAY

#include <sys/time.h>

static void vt_init_periods(void) 
{
  period_time = 0.1;
  regular_dt = 0.005;
}

static void set_owrt_delta(void)
{
  struct timeval tv_owrt ;
  gettimeofday(&tv_owrt, NULL);
  owrt = tv_owrt.tv_usec ;
  owrt /= 1000000.0;
  owrt += tv_owrt.tv_sec;
  owrt -= et2;
}

static double get_real_time(void)
{
  struct timeval tv ;
  double rt ;
  gettimeofday(&tv, NULL);
  rt = tv.tv_usec ;
  rt /= 1000000.0;
  rt += tv.tv_sec;
  rt -= owrt ;
  return rt;
}

#endif

#if VT_TIME

#include <time.h>

static void vt_init_periods(void) 
{
  period_time = 1.0;
  regular_dt = 0.05;
}

static void set_owrt_delta(void)
{
  owrt = ((double) time(NULL)) - et2;
}

static double get_real_time(void)
{
  return ((double) time(NULL)) - owrt;
}

#endif

#if VT_CLOCK

#include <time.h>

static void vt_init_periods(void) 
{
  period_time = (2.0 / CLOCKS_PER_SEC);
  if(period_time < 0.05) {
    period_time = 0.05;
  }
  regular_dt = period_time / 20 ;
}

static void set_owrt_delta(void)
{
  owrt = ((double) clock()) / CLOCKS_PER_SEC - et2;
}

static double get_real_time(void)
{
  return ((double) clock()) / CLOCKS_PER_SEC - owrt;
}

#endif


/**************** end of machine dependant routines **************/

#ifdef VT_TRACE

FILE *vt_trace_file ;

static void vt_trace_init(void)
{
  vt_trace_file = fopen("vttrace","wb");
}

#define VT_TRACE_INIT 0
#define VT_TRACE_RESUMING 1
#define VT_TRACE_SYNCING 2
#define VT_TRACE_RESUME 3
#define VT_TRACE_HALT 4
#define VT_TRACE_HALVING 5
#define VT_TRACE_TRIGGER 6

static void vt_trace(int where, double real_time)
{
  struct {
    int where;
    double real_time;
    long nb_cycles;
    double f2;
    double et1;
  } a;
  a.where = where;
  a.real_time = real_time;
  a.nb_cycles = nb_cycles;
  a.f2 = f2;
  a.et1 = et1;

  fwrite(&a, sizeof(a), 1, vt_trace_file);
  fflush(vt_trace_file);
}
    
#endif

void vt_stats(double *rt, double *et)
{
  *rt = get_real_time();
  *et = et2 + f2*nb_cycles;
}

double vt_get_etime(void)
{
  return et2 + f2*nb_cycles;
}

void vt_init(void)
{
  nb_alarms = 0 ;
  first_alarm_time = -1 ;
  first_alarm_cycle = 999999999 ;
  vt_init_periods();
  epsilon = 1E-12;
  et2 = 0;
  vtime_status = VT_HALTED ;
#ifdef VT_TRACE
  vt_trace_init();
  vt_trace(VT_TRACE_INIT, get_real_time());
#endif
}


static void vt_resuming_alarm(void * dummy)
{
  (void) dummy;

  sync_watch_dog = 1000;
  rt2 = get_real_time();
#ifdef VT_TRACE
  vt_trace(VT_TRACE_RESUMING, rt2);
#endif
#if 0
  et2 = et1+f2*nb_cycles;
  ec_stderr("resuming: rt2 = %f, et2 = %f, dt = %f, n2-n1 = %ld\n", 
        rt2, et2, dt, (long)nb_cycles);
#endif
        
  if(rt2 > rt1 + period_time) {
    /* That is it, we can stop the resuming phase */
    dt = regular_dt ;
    vtime_status = VT_RUNNING;
    vt_syncing_alarm(0);    
  } else {
    /* still not at the right pace */
    dt = dt * 2.0 ;
    set_alarm(dt, vt_resuming_alarm, 0);
  }
}
    
static void vt_syncing_alarm(void * dummy)
{
  double factor;
  (void) dummy;

  sync_watch_dog = 1000;
  rt2 = get_real_time();
#ifdef VT_TRACE
  vt_trace(VT_TRACE_SYNCING, rt2);
#endif
 
  if(rt2 > rt1 + period_time) {
    /* the period is over, re-calculate the factor */
    n2_n1 = nb_cycles ;
#if 0
    if(n2_n1 <= 10) {
        ec_stderr("n2 - n1 = %ld\n", (long)n2_n1);
    }
#endif
    assert(n2_n1 >= 10);
    rt3 = rt2 + period_time;
    et2 = et1 + (n2_n1)*f2 ;
    
#if 0
    ec_stderr( "rt = %f, et = %f\n", rt2, et2);
#endif
    
    factor = ((rt3 - et2) * (rt2 - rt1)) / ((rt3 - rt2) * (n2_n1)) ;
    if(factor <= epsilon) {
      factor = f2 / 3 ;
      if(factor <= epsilon) {
        /* TODO */
        /* ec_stderr("TODO factor <= epsilon\n");  */
        factor = epsilon;
      }
    }
    f2 = factor;
    nb_cycles = 0;
    rt1 = rt2;
    rt2 = rt3;
    et1 = et2;
    vt_check_first_alarm();
  } else {
    int et2 = et1 + nb_cycles * f2;
    if(et2 > rt1 + period_time && f2 > 10*epsilon) {
      /* Hack : halve the factor, while keeping the formula
         et2 = et1 + nb_cycles * f2  valid ! 
      */
      et1 -= nb_cycles*f2;
      f2 /= 2.0 ;
#ifdef VT_TRACE
  vt_trace(VT_TRACE_HALVING, rt2);
#endif
    }
  }
  set_alarm(dt, vt_syncing_alarm, 0);
}

void vt_resume(void)
{
  assert(vtime_status == VT_HALTED);
  set_owrt_delta();
  rt1 = get_real_time();
#ifdef VT_TRACE
  vt_trace(VT_TRACE_RESUME, rt1);
#endif
  et2 = rt1;
  et1 = rt1;
  f2 = epsilon;
  dt = epsilon;
  nb_cycles = 0;
  vtime_status = VT_RESUMING;
  sync_watch_dog = 1000;   /* every 1000 alarms, sync */
  set_alarm(dt, vt_resuming_alarm, 0);
}

void vt_halt(void)
{
  assert((vtime_status == VT_RESUMING) || (vtime_status == VT_RUNNING));
  vtime_status = VT_HALTED;
#ifdef VT_TRACE
  vt_trace(VT_TRACE_HALT, get_real_time());
#endif
  et2 = et2 + nb_cycles*f2;
  /* nothing to do */
}


static void vt_check_first_alarm(void)
{
  double fat = first_alarm_time;
  long fac = 999999999;

  if( (fat > 0.0) && (fat < et2 + fac * f2)) {
    fac = (fat - et2) / f2 ;
  }

  first_alarm_cycle = fac ;
}


void trigger_first_alarm(void)
{       
  int i ;
  double now ;

  if(nb_alarms <= 0)
    return ;

  if(sync_watch_dog -- <= 0) {
    if(vtime_status == VT_RESUMING) {
      clear_alarm_by_func(vt_resuming_alarm);
      vt_resuming_alarm(0);
      vt_check_first_alarm();
    } else {
      clear_alarm_by_func(vt_syncing_alarm);
      vt_syncing_alarm(0);
      vt_check_first_alarm();
    } 
    return;
  }   

  now = et2 + nb_cycles * f2 ;
  if( my_alarms[0].name[0] ) {
    ec_stderr( "now : %f : trigger first alarm : '%s'\n",
             now, my_alarms[0].name ) ;
  }

#if 0
  ec_stderr( "now = %f\n", now) ;
#endif
  my_alarms[0].func(my_alarms[0].arg) ;
  /* remove first alarm */
  for(i = 1 ; i < nb_alarms ; i++) {
    my_alarms[i-1] = my_alarms[i] ;
  }
  nb_alarms -- ;
        
  if(nb_alarms > 0) {
    first_alarm_time = my_alarms[0].when ;
  } else {
    first_alarm_time = -1.0 ;
  }
  vt_check_first_alarm();
}

void set_alarm_name(double delay, reminder_type func, void * arg, char *name) ;

void set_alarm(double delay, reminder_type func, void * arg)
{
  set_alarm_name(delay, func, arg, "") ;
}

void set_alarm_name(double delay, reminder_type func, void * arg, char *name)
{
  int i, j ;

  double now = et1 + nb_cycles * f2 ;
  double when = now + delay ;
        
#if 0
  ec_stderr( "et1=%f, nb_cycles=%ld, f1=%f\n", 
          et1, nb_cycles, f2) ;
  ec_stderr( "now : %f ; set_alarm(%f, '%s')\n", now, delay, name) ; 
#endif


  if(nb_alarms >= MAX_ALARMS) {
    ec_fatal( "time.c: too many alarms\n") ;
    return ;
  }

  if(delay < 100 * f2) {
    when = now + 100 * f2;
  }

  for(i = 0 ; i < nb_alarms ; i++) {
    if(my_alarms[i].when > when)
      break ;
  }
  for(j = nb_alarms-1 ; j >= i ; j--) {
    my_alarms[j+1] = my_alarms[j] ;
  }
  my_alarms[i].when = when ;
  my_alarms[i].func = func ;
  my_alarms[i].arg = arg ;
  strncpy( my_alarms[i].name, name, sizeof(my_alarms[i].name) - 1) ;
  my_alarms[i].name[sizeof(my_alarms[i].name) - 1] = 0 ;
  nb_alarms ++ ;
        
  if(i == 0) {
    first_alarm_time = my_alarms[0].when ;
    vt_check_first_alarm() ;
  }
}

static void empty_reminder(void * dummy) 
{
  (void)dummy ;
  return ;
}

void clear_alarm_by_func(reminder_type func) 
{
  int i ;
  /* the lazy way */
  for(i = 0 ; i < nb_alarms ; i++) {
    if(my_alarms[i].func == func) {
      my_alarms[i].func = empty_reminder ;
      my_alarms[i].name[0] = 0 ;
    }
  }
}
        
void clear_alarm(reminder_type func, void * arg) 
{
  int i ;
  /* the lazy way */
  for(i = 0 ; i < nb_alarms ; i++) {
    if( (my_alarms[i].func == func) && (my_alarms[i].arg == arg) ) {
      my_alarms[i].func = empty_reminder ;
      my_alarms[i].name[0] = 0 ;
    }
  }
}



