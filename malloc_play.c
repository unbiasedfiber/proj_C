#include <stdio.h>
#include <stdlib.h>


void malloc_array(int *arr[], int size, int value){
  for (int i=0; i<size; i++){
    arr[i] = (int*) malloc(sizeof(int)); //allocate memory for ints
    *arr[i] = i*value;
  }
}

void display_array(int *arr[], int size){
  for(int i=0; i<size; i++){
    printf("%d -- at address : %d\n", *arr[i], arr[i]);
  }
}

void free_array(int *arr[], int size){
  for(int i=0; i<size; i++){
    free(arr[i]);
    arr[i] = NULL;
  }
}


int main () {

  int *ptr_array[5]; //init array of pointers to ints

  malloc_array(ptr_array, 5, 100);
  display_array(ptr_array, 5);
  free_array(ptr_array, 5);

  if (ptr_array[4] == 0){
    printf("\ndangling pointers resolved to null");
  }
}
