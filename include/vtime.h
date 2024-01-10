/*
 * vtime.h - virtual time management
 * 
 * Part of STonC (C) 1998-2002 Laurent Vogel
 * Covered by the GPL version 2 or later; see COPYING for details
 */

#ifndef VTIME_H
#define VTIME_H

typedef void (*reminder_type)(void *); 

void vt_init(void);

/* temporarily halt the vtime engine when no virtual time elapses */
void vt_halt(void);
void vt_resume(void);

void vt_stats(double *rt, double *et);
double vt_get_etime(void);

void trigger_first_alarm(void);
void set_alarm(double delay, reminder_type func, void *arg);
void set_alarm_name(double delay, reminder_type func, void *arg, char *name);
void clear_alarm_by_func(reminder_type func);
void clear_alarm(reminder_type func, void *arg);

/* these should be static, but for the inline function spent_cycles() */
extern long first_alarm_cycle;
extern long nb_cycles;

#if 0
inline void spent_cycles(int num) {
  nb_cycles += num ;
  while(nb_cycles >= first_alarm_cycle)
    trigger_first_alarm() ;
}
#else
#define spent_cycles(num) {              \
  nb_cycles += (num) ;                   \
  while(nb_cycles >= first_alarm_cycle)  \
    trigger_first_alarm() ;              \
}
#endif 

#endif /* VTIME_H */

