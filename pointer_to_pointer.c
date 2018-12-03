#include <stdio.h>
#include <string.h>


int main(){

  char *titles[5] = {"a sentence", "short sentence.", "the absolute longest sentence.", "just another sentence", "a word"};
  char **ptr;

  int max_len = 0;
  for (int i = 0; i <= 4; i++){
    printf("%d : %s\n", i, titles[i]);
    char s = strlen(titles[i]);
    if ( s > max_len){
      max_len = s;
      ptr = &titles[i];
    }
  }

  printf("\nMax : %s", (*ptr));
  return 0;
}
