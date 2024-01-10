/* 
 * emulc.h - EmulC main header
 *
 * Part of STonC (C) 1998-2002 Laurent Vogel
 * Covered by the GPL version 2 or later; see COPYING for details
 */

#ifndef H_EMULC
#define H_EMULC

#include <stdarg.h>

struct ec_terminal;

typedef struct ec_terminal *Term;

typedef void (*ec_key_handler)(void *object, int key);

/* virtual terminal stuff */

void te_init(void);
Term te_new_term(void);
Term te_new_line_term(void);
void te_select_term(Term t);
void te_output_char(Term t, char c);
void te_output_string(Term t, char *s);

/* other functions are available in ecterm.h */

void te_key_received(int key);
void te_set_kbd_handler(Term t, ec_key_handler handler, void *obj);
void te_dummy_key_handler(void *dummy, int key);
void te_ansi_key_handler(void * Term_t, int c);
int te_get_char(Term t);

Term te_get_active_term(void);
Term te_get_term_by_nr(int n);
int te_get_nr_of_terms(void);

void ec_check_kbd(void);
void ec_periodic_tasks(void);

void ec_block_mode(void);
void ec_non_block_mode(void);

void ec_set_msg_term(Term t);
void ec_fatal(const char *format, ...);
void ec_vstderr(const char *fmt, va_list ap);
void ec_stderr(const char *fmt, ...);
int ec_fprintf_stderr(void *file, const char *fmt, ...);

#ifndef assert
# ifdef NDEBUG
#  define assert(a) ((void)0)
# else
#  define assert(a) ((a)?((void)0):ec_assert(#a, __FILE__, __LINE__))
void ec_assert(char *s, char *f, int l);
# endif
#endif


void ec_init(void);
void ec_end(void);
void ec_set_magic_handler(int key, void (*magic_handler)(int));

/* log configuration */
#define LOGNONE 0
#define LOGSTDERR 1
#define LOGFILE 2
#define LOGBOTH 3
void ec_set_log_style(int style, char *filename);

/* silly functions for key handling */
int ec_key_from_name(char *name); 
int ec_get_key_max(void);

#endif /* H_EMULC */
