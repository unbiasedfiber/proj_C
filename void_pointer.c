#include <stdio.h>

int main(){

  double   a   = 3.141592;
  int      b = 69;
  char     c[] = "a string";

  // voidic pointer
  // numeric values must be dereferenced.
  void *ptr;

  ptr = &a;
  printf("ptr -> %f\n", *((double *)ptr));

  ptr = &b;
  printf("ptr -> %d\n", *((int*)ptr));

  ptr = &c;
  printf("ptr -> %s\n", ptr);

  return 0;
}
