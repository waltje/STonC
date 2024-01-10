/*
 * hash.h - hash table.
 *
 * Part of STonC (C) 2000 Laurent Vogel
 * Covered by the GPL version 2 or later; see COPYING for details
 */

#ifndef _HASH_H
#define _HASH_H

struct hash_struct;

typedef struct hash_struct *Hash ;

Hash HashNew(int size);

void HashInsert(Hash h, char *key, void *data);

/* returns the data, or NULL if no data. */
void *HashLookup(Hash h, char *key);

/* remove an element from the table, returning the data so
  that it can be freed by the caller */
void *HashDelete(Hash h, char *key);

/* free the hash */
void HashKill(Hash h);

void HashForeach(Hash h, void (*func)(char *, void *));

#endif /* _HASH_H */


