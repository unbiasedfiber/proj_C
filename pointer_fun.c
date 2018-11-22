#include <stdio.h>

void point_to_types(){
  int a[5] = {1,2,3,4}; char b[] = "STRING!";

  printf("%s\n", "void pointers can be used to reference different types");
  void *ptr;
  ptr = a;
  printf("void ptr points to an array : why not dereference the second element %d at address %d\n", *((int*)ptr + 1), &ptr );

  ptr = b;
  printf("void ptr points to a character string : %s at address %d\n", ptr, &ptr );

  ptr = NULL;
  printf("void ptr points to NULL also a char string : %s at address %d\n",ptr, &ptr);

  printf("\n%s%s\n", "Cool, we can place data of different types into the same address.\n",
                       "Now lets examine pointer arithmetic.\n");
};

void pointer_arithmetic_with_types(){

  void *ptr;
  int int_array[] = {1,2};
  short short_array[] = {1,2};
  double double_array[] = {1.000,2.000};

  ptr = int_array;
  printf("int array, increment by 1, address increases by 4: %d @ %d, %d @ %d\n", *((int*)ptr), ptr, *((int*)ptr+1), ((int*)ptr+1));

  ptr = short_array;
  printf("short array, increment by 1, address increases by 2: %hi @ %d, %hi @ %d\n", *((short*)ptr), ptr, *((short*)ptr+1), ((short*)ptr+1));

  ptr = double_array;
  printf("double array, increment by 1, address increases by 8: %lf @ %d, %lf @ %d\n", *((double*)ptr), ptr, *((double*)ptr+1), ((double*)ptr+1));

  printf("\n%s\n", "What happens if we substract the address of ptr from ptr+1 ?\nSince ptr is pointed to an array of doubles, we'd expect a difference of 8 right?");

  printf("WRONG! instead the difference between %d and %d is %d\n\n%s", ((double*)ptr), ((double*)ptr+1),  ((double*)ptr+1) - ((double*)ptr),
         "This is also true for arrays of other types as long as the difference in indices is 1");
}

int main(){
  printf("%s\n\n", "Let's have a look at POINTERS ");
  point_to_types();
  pointer_arithmetic_with_types();

  return 0;
}
