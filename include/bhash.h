/*
 * bhash.h - an interface for a hash table where keys are fixed length 
 * binary blocs.
 *
 * Part of STonC (C) 2000 Laurent Vogel
 * Covered by the GPL version 2 or later; see COPYING for details
 */

#ifndef _BHASH_H
#define _BHASH_H

struct bhash_struct;

typedef struct bhash_struct *BHash ;

BHash BHashNew(int size, int key_length);

void BHashInsert(BHash h, char *key, void *data);

/* returns the data, or NULL if no data. */
void *BHashLookup(BHash h, char *key);

/* remove an element from the table, returning the data so
  that it can be freed by the caller */
void *BHashDelete(BHash h, char *key);

/* free the hash */
void BHashKill(BHash h);

void BHashForeach(BHash h, void (*func)(char *, void *));

#endif /* _HASH_H */


