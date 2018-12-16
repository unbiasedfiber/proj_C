#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIM 5

void mod_elements(char *arr, int size, int lim){
  for (int i=0; i<lim; i++){
    if (i>size-1){
      arr[i] = 0;
    } else {
      arr[i] = 'a';
    }
  }
}

void display_array(char *arr, int lim){
  for (int i=0; i<lim; i++){
    printf("  value : %c @ %d\n", arr[i], &arr[i]);
  }
}


int main(){

  int array_size = 5;
  char *my_array = calloc(array_size, sizeof(char));

  char in[4];
  char quit[5] = "quit";

  while(1){

    printf("\n*** Current array size : %d ***\n\n", array_size);
    display_array(my_array, LIM);
    printf("  Enter a number between 1 and 5 inclusive : \n\n");
    gets(in);

    if (strcmp(in, quit) == 0){
      printf("\n%s\n", "-- Quitting Application --");
      free(my_array);
      break; return 0;

    } else if (atoi(in) == 0 || atoi(in) > 5){
      printf("\n-- ERROR try again --\n");

    } else {
      array_size = atoi(in);
      printf("\nYou entered : %d\n", array_size);

      my_array = realloc(my_array, array_size);
      if (my_array == NULL){
        free(my_array);
      } else {
        mod_elements(my_array, array_size, LIM);
      }
    }
  }
}
