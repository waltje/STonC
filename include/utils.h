/* 
 * utils.h - utilities used in every source files
 *
 * Taken from STonX (C) 1994-1997 Marinos Yannikos & Martin D. Griffiths
 * Modified for STonC (C) 1998-2003 Laurent Vogel
 * Covered by the GPL version 2 or later; see COPYING for details
 */

#ifndef UTILS_H
#define UTILS_H

extern char * xstrdup(const char *);

/*
 * error reporting - copied from emulc.h
 */

extern void ec_stderr(const char *, ...);
extern void ec_fatal(const char *, ...);

#ifndef assert
# ifdef NDEBUG
#  define assert(a) ((void)0)
# else
#  define assert(a) ((a)?((void)0):ec_assert(#a, __FILE__, __LINE__))
extern void ec_assert(char *s, char *f, int l);
# endif
#endif

/*
 * user interface and configuration commands
 */

void ui_register_command(char *cmd, int (*func)(int,char**), char *help);
void ui_register_help(char *topic, char *help);

/*
 * language tricks
 */
#define UNUSED(a) ((void)(a))

#endif /* UTILS_H */
