/*
 * vars.c - variables for the embedded shell
 *
 * Part of STonC (C) 2000-2002 Laurent Vogel
 * Covered by the GPL version 2 or later; see COPYING for details
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"
 
#include "emulc.h"
#include "vtime.h"

#include "hash.h"

/* variables : 
 * - env vars, = strings
 * - internal vars = some declared as ints 
 * - user variables : strings
 */

void var_init(void);
void declare_int_var(char *name, int *var, void (*notify)(int *));
void declare_var(char *name, char **var, void (*notify)(char **));

void set_var(char *name, char *value);
char *get_var(char *name);

static char * get_env_var(char *name);

struct var_info {
  int *int_var;
  void (*int_notify)(int *);
  char **var;
  char *p;
  void (*notify)(char **);
};

typedef struct var_info *VI;

static Hash var_hash;

void var_init(void)
{
  var_hash = HashNew(50);
  if(var_hash == NULL) {
    ec_fatal("no memory for var hash");
  }
}

void declare_int_var(char *name, int *var, void (*notify)(int *))
{
  VI v ;
  assert(var_hash != NULL);
  v = (VI) malloc(sizeof(struct var_info));
  HashInsert(var_hash, name, v);
  v->int_var = var;
  v->int_notify = notify;
  v->p = malloc(10);
  if(v->p == NULL) {
    ec_fatal("mem in declare_int_var");
  }
  sprintf(v->p, "%d", *var);
  v->var = &v->p;
  v->notify = NULL;
}
  
void declare_var(char *name, char **var, void (*notify)(char **))
{
  VI v ;
  int n;
  assert(var_hash != NULL);
  v = (VI) malloc(sizeof(struct var_info));
  HashInsert(var_hash, name, v);
  v->int_var = NULL;
  v->int_notify = NULL;
  assert(var);
  assert(*var);
  n = strlen(*var)+1;
  v->p = malloc(n);
  if(v->p == NULL) {
    ec_fatal("mem in declare_var");
  }
  strcpy(v->p, *var);
  v->var = &v->p;
  v->notify = notify;
}

static char * get_env_var(char *name)
{
  return getenv(name);
}

int defined_var(char *name)
{
  char *p;
  VI v = HashLookup(var_hash, name);
  if(v == NULL) {
    p = get_env_var(name);
    if(p == NULL) {
      return 0;
    } else {
      return 1;
    }
  } else {
    return 1;
  }
}
   
void unset_var(char *name)
{
  if (NULL != HashLookup(var_hash, name)) {
    HashDelete(var_hash, name);
  }
}


char *get_var(char *name)
{
  char *p;
  int n;
  VI v = HashLookup(var_hash, name);
  if(v == NULL) {
    p = get_env_var(name);
    if(p == NULL) {
      return NULL;
    } else {
      /* add this var in the list */
      v = (VI) malloc(sizeof(struct var_info));
      HashInsert(var_hash, name, v);
      v->int_var = NULL;
      v->int_notify = NULL;
      n = strlen(p)+1;
      v->p = malloc(n);
      if(v->p == NULL) {
        ec_fatal("mem in get_var");
      }
      v->var = &v->p;
      v->notify = NULL;
      strcpy(v->p,p);
      return p;
    }
  } else {
    return *(v->var);
  }
}
  
/* returns the address of the next char, or NULL if failure */
static char *parse_int(char *c, int *valp)
{
  int val = 0;
  int i;
  while(*c == ' ' || *c == '\t') c++;
  if(*c == '0') {
    c++;
    if(*c == 'x') {
      c++;
      for(i = 0 ; i < 9 ; i++) {
        if(*c >= 'a' && *c <= 'f') {
          val <<= 4;
          val += (*c - 'a' + 10);
        } else if(*c >= 'A' && *c <= 'F') {
          val <<= 4;
          val += (*c - 'A' + 10);
        } else if(*c >= '0' && *c <= '9') {
          val <<= 4;
          val += (*c - '0');
        } else {
          break;
        }
        c++;
      }
      if(i == 0) {
        ec_stderr("not a number in %s\n", c);
        return NULL;
      } else if(i == 9) {
        ec_stderr("number too big in %s\n", c - i);
      } else {
        *valp = val;
        return c;
      }
    } else {
      for(i = 0 ; i < 12 ; i++) {
        if(*c >= '0' && *c <= '7') {
          val <<= 3;
          val += (*c - '0');
        } else {
          break;
        }
        c++;
      }
      if(i == 12) {
        ec_stderr("number too big in %s\n", c-i);
      } else {
        *valp = val;
        return c;
      }
    }
  } else if(*c >= '1' && *c <= '9') {
    for(i = 0 ; i < 12 ; i++) {
      if(*c >= '0' && *c <= '9') {
        val *= 10;
        val += (*c - '0');
      } else {
        break;
      }
      c++;
    }
    if(i == 0) {
      ec_stderr("not a number in %s\n", c);
      return NULL;
    } else if(i == 12) {
      ec_stderr("number too big in %s\n", c-i);
    } else {
      *valp = val;
      return c;
    }
  } else {
    ec_stderr("not a number in %s\n", c);
    return NULL;
  }
  return NULL;
}


void set_var(char *name, char *value)
{
  char *p;
  int n, val;
  VI v = HashLookup(var_hash, name);
  if(v == NULL) {
    /* add this var in the list */
    v = (VI) malloc(sizeof(struct var_info));
    HashInsert(var_hash, name, v);
    v->int_var = NULL;
    v->int_notify = NULL;
    n = strlen(value)+1;
    v->p = malloc(n);
    if(v->p == NULL) {
      ec_fatal("mem in set_var");
    }
    strcpy(v->p, value);
    v->var = &v->p;
    v->notify = NULL;
  } else if(v->int_var != NULL) {
    /* this is an int variable. */
    p = parse_int(value, &val);
    if(p == NULL) return;
    if(*p != 0) {
      /* special values "true" and "false" allowed */
      if(!strcmp("true", p)) {
        val = 1;
      } else if(!strcmp("false", p)) {
        val = 0;
      } else {
        ec_stderr("this is not an int value\n");
        return;
      }
    }
    n = strlen(value)+1;
    p = malloc(n);
    if(p == NULL) {
      ec_fatal("mem in set_var");
    }
    free(v->p);
    v->p = p;
    strcpy(v->p, value);
    if(val != *v->int_var) {
      *v->int_var = val;
      v->int_notify(v->int_var);
    }
    v->var = &v->p;
  } else {
    n = strlen(value)+1;
    p = malloc(n);
    if(p == NULL) {
      ec_fatal("mem in set_var");
    }
    if(v->notify != NULL) {
      if(strcmp(v->p, value)) {
        v->notify(v->var);
      }
    }
    free(v->p);
    v->p = p;
    strcpy(v->p, value);
    v->var = &v->p;
  }
}  
      
