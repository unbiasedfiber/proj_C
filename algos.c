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
        int a = array[j-1];
        array[j-1] = array[j];
        array[j] = a;
      }
    }
  }
}

void swap(int array[], int i, int j){
  int temp = array[i];
  array[i] = array[j];
  array[j] = temp;
}

/* recursive sorting algo */
static void quick_sort(int array[], int left_side, int right_side){
  int i, last;  /* init variables and swap function*/
  void swap(int array[], int i, int j);

  if (left_side >= right_side) return;

  swap(array, left_side, (left_side+right_side)/2); /* partition from the middle */
  last = left_side; /* pivot point */

  for (i = left_side+1; i <= right_side; i++){
    if (array[i] < array[left_side]){
      swap(array, ++last, i);}
  }

  swap(array, left_side, last);
  quick_sort(array, left_side, last-1);
  quick_sort(array, last+1, right_side);
}


int main(){
  int this_array[] = {12,16,65,24,28,34,86,56,59,35,11,300};
  int array_length = sizeof(this_array)/4;
  int i = array_length;

  /* bubble_sort(this_array, sizeof(this_array)/4); */
  quick_sort(this_array, 0, array_length-1);

  while(i-->0){
    printf("%d\n",this_array[i]);
  }


  return 0;
}
