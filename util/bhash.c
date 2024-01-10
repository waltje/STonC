/*
 * bhash.c : a hash table where keys are binary fixed size blocks.
 *
 * Part of STonC (C) 2000 Laurent Vogel
 * Covered by the GPL version 2 or later; see COPYING for details
 */

/* modified from hash.c, public domain code by Jerry Coffin, 
 * with improvements by HenkJan Wolthuis, dated last modified: 05-Jul-1997 
 * 
 * the calling interface has changed, mostly to allow a different
 * implementation later.
 * 
 * last modified 11 october 2000. Laurent Vogel. 
 *
 * 23 nov 2000
 * - added more tests, used correct lib functions (memcmp)
 */

#include <stddef.h>     /* For size_t     */
#include <stdlib.h>         /* for malloc(), free() */
#include <string.h>     /* memcmp() */

#include "bhash.h"

typedef struct bucket {
  void *data;
  struct bucket *next;
  char key[16];
} bucket;

struct bhash_struct {
  int size;
  int key_length;
  int bucket_size;
  bucket **table;  
};

typedef struct bhash_struct bhash_table;

/* the original functions, made static */

static bhash_table *construct_table(bhash_table *table, size_t size, int key_length);
static void *insert(char *key, void *data, bhash_table *table);
static void *lookup(char *key, bhash_table *table);
static void *del(char *key, bhash_table *table);
static void free_table(bhash_table *table, void (*func)(void *));
static void enumerate( bhash_table *table, void (*func)(char *, void *));


BHash BHashNew(int size, int key_length)
{
  BHash h = malloc(sizeof(struct bhash_struct));
  if(NULL == h) return NULL;
  if(NULL == construct_table(h, size, key_length)) {
    free(h);
    h = NULL;
  }
  return h;
}

void BHashInsert(BHash h, char *key, void *data)
{
  (void) insert(key, data, h);
}

/* returns the data, or NULL if no data. */
void *BHashLookup(BHash h, char *key)
{
  return lookup(key, h);
}

/* remove an element from the table, returning the data so
  that it can be freed by the caller */
void *BHashDelete(BHash h, char *key)
{
  return del(key, h);
}

/* free the hash */
void BHashKill(BHash h)
{
  free_table(h, NULL);
  free(h);
}

void BHashForeach(BHash h, void (*func)(char *, void *))
{
  enumerate(h, func);
}

/**********************************************************************/
/* original implementation follows */

/* +++Date last modified: 05-Jul-1997 */

/*
** public domain code by Jerry Coffin, with improvements by HenkJan Wolthuis.
**
** Tested with Visual C 1.0 and Borland C 3.1.
** Compiles without warnings, and seems like it should be pretty
** portable.
*/

/*
** These are used in freeing a table.  Perhaps I should code up
** something a little less grungy, but it works, so what the heck.
*/

static void (*function)(void *) = (void (*)(void *))NULL;
static bhash_table *the_table = NULL;


/* Initialize the hash_table to the size asked for.  Allocates space
** for the correct number of pointers and sets them to NULL.  If it
** can't allocate sufficient memory, signals error by setting the size
** of the table to 0.
*/

static bhash_table *construct_table(bhash_table *table, size_t size, int key_length)
{
      size_t i;
      bucket **temp;

      table -> size  = size;
      table -> key_length = key_length;
      table -> bucket_size = sizeof(bucket);
      table -> table = (bucket * *)malloc(sizeof(bucket *) * size);
      temp = table -> table;

      if ( temp == NULL )
      {
            table -> size = 0;
            return NULL;
      }

      for (i=0;i<size;i++)
            temp[i] = NULL;
      return table;
}


/*
** Hashes a string to produce an unsigned short, which should be
** sufficient for most purposes.
*/

static unsigned hash(char *string, int key_length)
{
      unsigned ret_val = 0;
      int a,i;

      for(i = 0 ; i < key_length ; i++)
      {
            a = (int) (*string);
            ret_val ^= a;
            ret_val <<= 1;
            string ++;
      }
      return ret_val;
}

/*
** Insert 'key' into hash table.
** Returns pointer to old data associated with the key, if any, or
** NULL if the key wasn't in the table previously.
*/

static void *insert(char *key, void *data, bhash_table *table)
{
      unsigned val = hash(key, table -> key_length) % table->size;
      bucket *ptr;
      
      /*
      ** NULL means this bucket hasn't been used yet.  We'll simply
      ** allocate space for our new bucket and put our data there, with
      ** the table pointing at it.
      */

      if (NULL == (table->table)[val])
      {
            (table->table)[val] = (bucket *)malloc(table -> bucket_size);
            if (NULL==(table->table)[val])
                  return NULL;

            memcpy((table->table)[val] -> key, key, table -> key_length) ;
            (table->table)[val] -> next = NULL;
            (table->table)[val] -> data = data;
            return (table->table)[val] -> data;
      }

      /*
      ** This spot in the table is already in use.  See if the current string
      ** has already been inserted, and if so, increment its count.
      */

      for (ptr = (table->table)[val];NULL != ptr; ptr = ptr -> next)
            if (!memcmp(key, ptr->key, table -> key_length))
            {
                  void *old_data;

                  old_data = ptr->data;
                  ptr -> data = data;
                  return old_data;
            }

      /*
      ** This key must not be in the table yet.  We'll add it to the head of
      ** the list at this spot in the hash table.  Speed would be
      ** slightly improved if the list was kept sorted instead.  In this case,
      ** this code would be moved into the loop above, and the insertion would
      ** take place as soon as it was determined that the present key in the
      ** list was larger than this one.
      */

      ptr = (bucket *)malloc(table->bucket_size);
      if (NULL==ptr)
            return 0;
      memcpy(ptr->key, key, table->key_length);
      ptr -> data = data;
      ptr -> next = (table->table)[val];
      (table->table)[val] = ptr;
      return data;
}


/*
** Look up a key and return the associated data.  Returns NULL if
** the key is not in the table.
*/

static void *lookup(char *key, bhash_table *table)
{
      unsigned val = hash(key, table -> key_length) % table->size;
      bucket *ptr;

      if (NULL == (table->table)[val])
            return NULL;

      for ( ptr = (table->table)[val];NULL != ptr; ptr = ptr->next )
      {
            if (!memcmp(key, ptr->key, table->key_length ) )
                  return ptr->data;
      }
      return NULL;
}

/*
** Delete a key from the hash table and return associated
** data, or NULL if not present.
*/

static void *del(char *key, bhash_table *table)
{
      unsigned val = hash(key, table->key_length) % table->size;
      void *data;
      bucket *ptr, *last = NULL;

      if (NULL == (table->table)[val])
            return NULL;

      /*
      ** Traverse the list, keeping track of the previous node in the list.
      ** When we find the node to delete, we set the previous node's next
      ** pointer to point to the node after ourself instead.  We then delete
      ** the key from the present node, and return a pointer to the data it
      ** contains.
      */

      for (last = NULL, ptr = (table->table)[val];
            NULL != ptr;
            last = ptr, ptr = ptr->next)
      {
            if (!memcmp(key, ptr -> key, table->key_length))
            {
                  if (last != NULL )
                  {
                        data = ptr -> data;
                        last -> next = ptr -> next;
                        free(ptr);
                        return data;
                  }

                  /*
                  ** If 'last' still equals NULL, it means that we need to
                  ** delete the first node in the list. This simply consists
                  ** of putting our own 'next' pointer in the array holding
                  ** the head of the list.  We then dispose of the current
                  ** node as above.
                  */

                  else
                  {
                        data = ptr->data;
                        (table->table)[val] = ptr->next;
                        free(ptr);
                        return data;
                  }
            }
      }

      /*
      ** If we get here, it means we didn't find the item in the table.
      ** Signal this by returning NULL.
      */

      return NULL;
}

/*
** free_table iterates the table, calling this repeatedly to free
** each individual node.  This, in turn, calls one or two other
** functions - one to free the storage used for the key, the other
** passes a pointer to the data back to a function defined by the user,
** process the data as needed.
*/

static void free_node(char *key, void *data)
{
      (void) data;

      if (function)
            function(del(key,the_table));
      else  del(key,the_table);
}

/*
** Frees a complete table by iterating over it and freeing each node.
** the second parameter is the address of a function it will call with a
** pointer to the data associated with each node.  This function is
** responsible for freeing the data, or doing whatever is needed with
** it.
*/

static void free_table(bhash_table *table, void (*func)(void *))
{
      function = func;
      the_table = table;

      enumerate( table, free_node);
      free(table->table);
      table->table = NULL;
      table->size = 0;

      the_table = NULL;
      function = (void (*)(void *))NULL;
}

/*
** Simply invokes the function given as the second parameter for each
** node in the table, passing it the key and the associated data.
*/

static void enumerate( bhash_table *table, void (*func)(char *, void *))
{
      int i;
      bucket *temp;

      for (i=0;i<table->size; i++)
      {
            if ((table->table)[i] != NULL)
            {
                  for (temp = (table->table)[i];
                        NULL != temp;
                        temp = temp -> next)
                  {
                        func(temp -> key, temp->data);
                  }
            }
      }
}


#ifdef HASH_TEST

#include <stdio.h>

int seq_length = 8;

void printer(char *string, void *data)
{
  int n;
  for(n = 0 ; n < seq_length ; n++) {
    printf("%02x", (int)*string++ & 0xFF);
  }
  printf(": %d\n", (int)data);
}

int seq_index;

void seq_init()
{
  seq_index = 0;
}

char seq_fragment[8][2] = {
  {0,0}, {'a', 127}, {255,0}, {0, 128}, {150, 't'}, {1, 2}, {255,255},
  {128,128}};

void seq_next(char *buf, void **data)
{
  int i, j, k;
  i = seq_index ++;
  *data = (void *)(i+1);
  for(k = 0 ; k < seq_length ; k += 2) {
    j = i & 7;
    *buf++ = seq_fragment[j][0];
    *buf++ = seq_fragment[j][1];
    i >>= 3;
  }
}

int seq_max(void)
{
  return 1 << (3 * (seq_length / 2));
}

int main(void)
{
  BHash h;
 
  int i;
  void *j, *k;
  char buf[20];

  h = BHashNew(200, 8);

  printf("BHash test: hello\n");
  seq_init();
  
  printf("seq_max = %d\n", (int)seq_max());
  for (i = 0; i < seq_max(); i++ ) {
    seq_next(buf, &j);
    BHashInsert(h, buf, j);
  }
  
  seq_init();
  for (i = 0; i < seq_max(); i++ ) {
    seq_next(buf, &j);
    k = BHashLookup(h, buf);
    if(k != j) {
      printf("wrong lookup (i = %d)\n", i);
    }
    printer(buf, k);
  }
  printf("BHash test: done\n");
  exit(0);
}

#endif /* HASH_TEST */

