#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "hash_table.h"

int is_prime(const int x){
  if (x<2){return -1;} // table of size 1
  if (x<4){return 1;} // 2 and 3 are primes
  if ((x%2) == 0){return 0;} // if prime return
  for (int i = 3; i<= floor(sqrt((double) x)); i+= 2){
    if ((x%i) == 0){
      return 0;
    }
  }
  return 1;
}

int next_prime(int x){
  while(is_prime(x) != 1){
    x++;
  }
  return x;
}


//deleted items are simply marketed as deleted in order to not break chain
static ht_item HT_DELETED_ITEM = {NULL, NULL};

// static item, will only be called by ht_hash_table, exists within it's scope
static ht_item* ht_new_item(const char* k, const char* v){
  ht_item* i = malloc(sizeof(ht_item));
  i -> key = strdup(k);
  i -> value = strdup(v);
  return i;
}

// create a hashtable, malloc produces null values * size
ht_hash_table* ht_new() {
  ht_hash_table* ht = malloc(sizeof(ht_hash_table));

  ht->size = 53;
  ht->count = 0;
  ht->items = calloc((size_t)ht->size, sizeof(ht_item*));
  return ht;
}

// delete items, free up memory with free()
static void ht_del_item(ht_item* i){
  free(i->key);
  free(i->value);
  free(i);
}

// iterate over table, free items space, finally free the table
void ht_del_hash_table(ht_hash_table* ht){
  for (int i=0; i<ht->size; i++){
    ht_item* item = ht->items[i];
    if (item != NULL){
      ht_del_item(item);
    }
  }
  free(ht->items);
  free(ht);
}

// hash function.
// where 's' is the key, 'a' random variable, 'm' total keys in hash table
static int ht_hash(const char* s, const int a, const int m){
  long hash = 0;
  const int len_s = strlen(s);
  for (int i = 0; i < len_s; i++){
    hash += (long) pow(a, len_s - (i+1)) * s[i];
    hash = hash % m;
  }
  return (int) hash;
}

// get hash function
static int ht_get_hash(const char* s, const int num_buckets, const int attempt){
  const int hash_a = ht_hash(s, 30, num_buckets); //HT_PRIME_1
  const int hash_b = ht_hash(s, 50, num_buckets); // HT_PRIME_2
  return (hash_a + (attempt * (hash_b + 1))) % num_buckets;
}

void ht_insert(ht_hash_table* ht, const char* key, const char* value){
  ht_item* item = ht_new_item(key, value);
  int index = ht_get_hash(item->key, ht->size, 0);
  ht_item* cur_item = ht->items[index];
  int i = 1;
  while (cur_item != NULL && cur_item != &HT_DELETED_ITEM){
    if (strcmp(cur_item->key, key) == 0){
      ht_del_item(cur_item); //if collision
      ht->items[index] = item; //delete and update
      return;
    }
    index = ht_get_hash(item->key, ht->size, i);
    cur_item = ht->items[index];
    i++;
  }
  ht->items[index]=item;
  ht->count++;
}

char* ht_search(ht_hash_table* ht, const char* key){
  int index = ht_get_hash(key, ht->size, 0);
  ht_item* item = ht->items[index];
  int i = 1;
  while (item != NULL && item != &HT_DELETED_ITEM){
      if (strcmp(item->key, key) == 0) { //if keys match
        return item-> value;
      }
    index = ht_get_hash(key, ht->size, i); //try next index
    item = ht->items[index];
    i++;
  }
  return NULL;
}

void ht_delete(ht_hash_table* ht, const char* key){
  int index = ht_get_hash(key, ht->size, 0);
  ht_item* item = ht->items[index];
  int i = 1;
  while (item != NULL){
    if (item != &HT_DELETED_ITEM){
      if (strcmp(item->key, key) == 0){
        ht_del_item(item);
        ht->items[index] = &HT_DELETED_ITEM; //free memory, point to del address
      }
    }
    index = ht_get_hash(key, ht->size, i);
    item = ht->items[index];
    i++;
  }
  ht->count--;
}
