/*
 * ec_util.c : utilities
 *
 * Copyright (C) 2000-2001 Laurent Vogel 
 * This file is part of EmulC, the Emulator on Curses library.
 *
 * This is free software covered by the GPL version 2 or later, and
 * comes with NO WARRANTY - read the file COPYING for details.  
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
             
#include "emulc.h"
#include "ecpriv.h"

static FILE *logfile;
static int logstyle = LOGNONE;

static Term ec_msg_term;

void ec_set_msg_term(Term t)
{
  ec_msg_term = t;
}

static Term get_msg_term(void)
{
  if(ec_msg_term != NULL) {
    return ec_msg_term;
  } else {
    return te_get_active_term();
  }
}

void ec_set_log_style(int s, char *f)
{
  switch(s) {
  case LOGNONE:
    if(logfile) fclose(logfile);
    logfile = NULL;
    logstyle = LOGNONE;
    break;
  case LOGSTDERR:
    if(logfile) fclose(logfile);
    logfile = NULL;
    logstyle = LOGSTDERR;
    break;
  case LOGFILE:
    if(logfile) fclose(logfile);
    logfile = fopen(f, "w");
    if(logfile == NULL) {
      logstyle = LOGNONE;
    } else {
      logstyle = LOGFILE;
    }
    break;
  case LOGBOTH:
    if(logfile) fclose(logfile);
    logfile = fopen(f, "w");
    if(logfile == NULL) {
      logstyle = LOGSTDERR;
    } else {
      logstyle = LOGBOTH;
    }
    break;
  default:
    ec_stderr("ec_set_log_file: wrong mode %d");
    if(logfile) fclose(logfile);
    logstyle = LOGNONE;
  }
}

void ec_fatal(const char *fmt, ...)
{
  char buf[200];  
  va_list ap;
  Term t ;
 
  va_start(ap, fmt);
#if 0
  (void) vsnprintf(buf, 200, fmt, ap);
#else
  (void) vsprintf(buf, fmt, ap);
#endif
  va_end(ap);

  t = get_msg_term();
  if(t == NULL) {
    fprintf(stderr, "fatal: %s\n", buf);
    exit(1);
  } else {
    te_output_string(t, "fatal: ");
    te_output_string(t, buf);
    te_output_char(t, 10);
    te_output_char(t, 13);
    switch(logstyle) {
    case LOGNONE:
      break;
    case LOGSTDERR:
      fprintf(stderr, "fatal: %s\n", buf);
      break;
    case LOGFILE:
      fprintf(logfile, "fatal: %s\n", buf);
      break;
    case LOGBOTH:
      fprintf(stderr, "fatal: %s\n", buf);
      fprintf(logfile, "fatal: %s\n", buf);
      break;
    }
    ts_block_mode();
    te_output_string(t, "[hit any key to exit]");
    ts_getch();
    ts_end();
    exit(1);
  }
}

void ec_stderr(const char *fmt, ...)
{
  va_list ap;
  
  va_start(ap, fmt);
  ec_vstderr(fmt, ap);
  va_end(ap);
}

void ec_vstderr(const char *fmt, va_list ap)
{
  char buf[2000];  
  Term t ;
  
#if 0
  vsnprintf(buf, 2000, fmt, ap);
#else
  vsprintf(buf, fmt, ap);
#endif
  
  t = get_msg_term();
  if(t == NULL) {
    fprintf(stderr, "%s", buf);
  } else {
    te_output_string(t, buf);
    switch(logstyle) {
    case LOGNONE:
      break;
    case LOGSTDERR:
      fprintf(stderr, "%s", buf);
      break;
    case LOGFILE:
      fprintf(logfile, "%s", buf);
      break;
    case LOGBOTH:
      fprintf(stderr, "%s", buf);
      fprintf(logfile, "%s", buf);
      break;
    }
  }
}

void ec_fprintf(void *dummy, const char *fmt, ...)
{
  char buf[2000];  
  va_list ap;
  Term t ;

  (void)dummy;
  
  va_start(ap, fmt);
#if 0
  vsnprintf(buf, 2000, fmt, ap);
#else
  vsprintf(buf, fmt, ap);
#endif
  va_end(ap);
  
  t = get_msg_term();
  if(t == NULL) {
    fprintf(stderr, "%s", buf);
  } else {
    te_output_string(t, buf);
    switch(logstyle) {
    case LOGNONE:
      break;
    case LOGSTDERR:
      fprintf(stderr, "%s", buf);
      break;
    case LOGFILE:
      fprintf(logfile, "%s", buf);
      break;
    case LOGBOTH:
      fprintf(stderr, "%s", buf);
      fprintf(logfile, "%s", buf);
      break;
    }
  }
}

#ifndef NDEBUG
void ec_assert(char *s, char *f, int l)
{
  ec_fatal("file %s, line %d: assertion failed %s", f, l, s);
}
#endif

