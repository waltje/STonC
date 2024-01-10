/*
 * vars.h - variables for STonC
 *
 * Part of STonC (C) 1998-2002 Laurent Vogel
 * Covered by the GPL version 2 or later; see COPYING for details
 */

#ifndef VARS_H
#define VARS_H
 
void var_init(void);
void declare_int_var(char *name, int *var, void (*notify)(int *));
void declare_var(char *name, char **var, void (*notify)(char **));

void set_var(char *name, char *value);
char *get_var(char *name);
int defined_var(char *name);
void unset_var(char *name);

#endif /* VARS_H */
