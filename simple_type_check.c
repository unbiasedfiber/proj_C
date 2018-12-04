#include <stdio.h>
#include <stdlib.h>

//pass input, simple type checking.
int main ( int argc, const char *argv[] ) {
  //checks too many arguments
  if (argc > 2){
    printf("Expected 2 arguments, %d received.\n--Aborting program", argc);
    return 1;
  //checks type input, if not numeric value, abort.
  } else if (atoi(argv[1]) < 1){
    printf("Expected integer, '%s' character string received.\n--Aborting program", argv[1]);
    return 1;
  //execute program
  } else {
    int user_in = atoi(argv[1]);
    printf("Your input x 10: %d\n", user_in*10);
    return 0;
  }
}
