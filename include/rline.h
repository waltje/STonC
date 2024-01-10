/*
 * rline.h - a small event-driven editline clone 
 *
 * Part of STonC (C) 1998-2002 Laurent Vogel
 * Covered by the GPL version 2 or later; see COPYING for details
 */

#ifndef RLINE_H
#define RLINE_H

#include "emulc.h"

struct rlhist_info;
typedef struct rlhist_info *Rlhist;

struct rline_info;
typedef struct rline_info *Rline;

struct rlcmpl_info;
typedef struct rlcmpl_info *Rlcmpl;

/* constructor */
Rline rline_init(Term t, void (*handler)(void*,char*), void* obj, Rlhist h);
void rline_set_prompt(Rline r, char *prompt);
/* called by the terminals */
void rline_got_key(void * Rline_r, int key);
/* activate the rline, begin to write on the term */
void rline_prompt(Rline r);

Rlhist rlhist_init(void);
/* add will always be below the bottom */
void rlhist_add(Rlhist h, char *p);
/* these three function return a line number like nth */
int rlhist_up(Rlhist h, int pos);
int rlhist_down(Rlhist h, int pos);
int rlhist_bottom(Rlhist h);
/* get the text for a line number */
char *rlhist_get_nth_line(Rlhist h, int pos);


Rlcmpl rlcmpl_init(Rline r);

/* returns 1 if done, 0 if still in dialog */
int rlcmpl_got_key(Rlcmpl h, int key);

/* returns 1 if done, 0 if still in dialog */
int rlcmpl_do_tab(Rlcmpl h);

void rlcmpl_list_names(Rlcmpl h);


#endif /* RLINE_H */

