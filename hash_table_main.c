#include <stdio.h>
#include "hash_table.c"

void check_array(int* array, int array_size){
  int i;
  for (i = 0; i<array_size; i++){
    printf("%d\n", array[i]);
  }
}

int main(){

  ht_hash_table* ht = ht_new();
  ht_insert(ht, "key1", "value1");

  char* val = ht_search(ht, "key1");
  printf("%s\n", val);
  ht_del_hash_table(ht);

  return 0;
}
