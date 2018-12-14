#include <stdio.h>
#include <stdlib.h>

int main () {
  int *pi = (int*) malloc(sizeof(int));

  *pi = 10;

  printf("%d located at %d\n", *pi, pi);
  free(pi);
  printf("%d freed at %d\n", *pi, pi);

}
