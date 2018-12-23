
#include <stdio.h>
#include <string.h>

void count_vowel(char letter, int *vowel_total, char *vowels[]){
  for (int i=0; i<5; i++){
    if (letter == *vowels[i]){
      *vowel_total+=1;
      printf("%c -- %c : %d \n", letter, *vowels[i], *vowel_total);
    }
  }
}

int main(){
  char file_name[] = "readthis.txt";
  FILE *file;

  char ch;
  char *ch_ptr = &ch;

  int total = 0;
  int* total_ptr = &total;

  char *vowels[] = {"a", "e", "i", "o", "u"};

  file = fopen(file_name,"r");

  if (file==NULL){
    return 1;
  }
  while( (ch=fgetc(file)) != EOF )
    count_vowel(ch, total_ptr, vowels);

  fclose(file);

  return 0;
}
