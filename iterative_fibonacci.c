
#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ulong;

void fib_iter(int i, ulong *array){
  if (i < 2) {
    array[i] = i;
  } else {
    array[i] = array[i-1] + array[i-2];
  }
  printf("%llu\n", array[i]);
}

int main(){
  int n = 1000;

  ulong *array = (ulong*)malloc(sizeof(ulong)*n);

  for (int i = 0; i < n; i++){
    fib_iter(i, array);
  }

  //res = fib_rec(*n_ptr);
  //printf("%d\n", res);
  return 0;
}
