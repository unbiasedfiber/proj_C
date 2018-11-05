#include <stdio.h>

static int mean(int array[], int array_len){
  int sum = 0, i = array_len;
  while (--i > 0){
    sum += array[i];
  }
  return sum/array_len;
}

static void bubble_sort(int array[], int array_len){
  for (int i=0; i<array_len; i++){
    for (int j=array_len-1; j>=i+1; j--){
      if (array[j-1] > array[j]){
        int a = array[j-1], b = array[j];
        array[j-1] = b; array[j] = a;
      }
    }
  }
}


int main(){
  int this_array[] = {12,16,65,24,28,34,86,56,59,35,11,300};
  bubble_sort(this_array, sizeof(this_array)/4);
  
  int i = sizeof(this_array)/4;
  while(i-->0){
    printf("%d\n",this_array[i]);
  }


  return 0;
}
