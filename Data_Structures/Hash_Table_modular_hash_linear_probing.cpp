#include <stdio.h>
#include "hashtable.h"

// Table size. Should be a prime number that is roughly 2x the
// number of expected records for optimal performance.
#define M 97

// Our record table definition, an array of M records.
Record record_table[M];

/*
 * FUNCTION DEFINITIONS
 */

// Hash function for integers.
static int hash(int key) {
   return (key % M);
}

// Table initialization function. Sets all indexes to NULL.
void init(void) {
	int i;
	for (i = 0; i < M; ++i) {
		record_table[i] = NULL;
	}
}

// Insert function. Inserts record at the index determined by the hash
// function. Uses linear probing if already occupied.
void insert(Record r) {
   int i = hash(r->key);
   while (record_table[i] != NULL) {
      i = (i + 1) % M;
   }
   record_table[i] = r;
}

// Search Function. Returns the record with a matching key. Search starts
// at the index determined by the hash function. Uses linear probing until
// the matching key is found. Returns NULL on search miss.
Record search(int key) {
   int i = hash(key);
   while (record_table[i] != NULL) {
      if (key == record_table[i]->key) {
         return record_table[i];
      } else {
         i = (i + 1) % M;
      }
   }
   return NULL;
}

// Delete function. Searches for and deletes the table entry with a
// matching key. Search starts at the index determined by the hash
// function. Uses linear probing until the matching key is found. Re-inserts
// the records that follow the matching record until an unocupied index is found.
void delete(int key) {
   int i = hash(key);
   Record r;

   while (record_table[i] != NULL) {
      if (key == record_table[i]->key) {
         break;
      } else {
         i = (i + 1) % M;
      }
   }

   if (record_table[i] == NULL) {
      return;
   }

   record_table[i] = NULL;

   for (i = (i + 1) % M; record_table[i] != NULL; i = (i + 1) % M) {
      r = record_table[i];
      record_table[i] = NULL;
      insert(r);
   }
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hashtable.h"

#define N        50
#define MAXVAL  1000

int main(void) {
	int i;
	Record a;

	srand(time(NULL));

	// Initialize the hash table
	init();

	// Insert N random records
	for (i = 0; i < N; ++i) {

		// Generate new random record
		a = malloc(sizeof(*a));
		a->key = rand() % MAXVAL;
		a->value = rand() % MAXVAL;

		// Don't allow duplicate keys
		if (search(a->key) != NULL) {
			--i;
			continue;
		}

		// Insert new record
		printf("Inserting: Key => %i, Value => %i\n", a->key, a->value);
		insert(a);
	}

	// Search and delete records for all possible keys
	for (i = 0; i < MAXVAL; ++i) {
		if ((a = search(i)) != NULL) {
			printf("Deleting: Key => %i, Value => %i\n", a->key, a->value);
			delete(a->key);
		}
	}

	return 0;
}