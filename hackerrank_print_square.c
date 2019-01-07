#include <stdio.h>
#include <stdlib.h>

void make_square(int n, int arr_len, int *arr_arr[]){
  for (int i = 0; i<arr_len; i++){
    arr_arr[i] = (int*)malloc(sizeof(int)*arr_len);
    int j = 0;
    while(j<arr_len){
      arr_arr[i][j] = n;
      j++;
    }
  }
}

void print_square(int arr_len, int *arr_arr[]){
  for (int i = 0; i<arr_len; i++){
    for (int j = 0; j<arr_len; j++){
      if (j>i){
      arr_arr[i][j] = arr_arr[i][j]-i;
      } else {
      arr_arr[i][j] = arr_arr[i][j]-j;
      }
    }
  }
  for (int i = 0; i<arr_len; i++){
    int j=0;
    while(j<arr_len-1){
      printf("%d ", arr_arr[i][j]);
      j++;
    }
    int k=arr_len-1;
    while(k>-1){
      printf("%d ", arr_arr[i][k]);
      k--;
    }
    printf("\n");
  }
  for (int i = arr_len-2; i>-1; i--){
    int j=0;
    while(j<arr_len-1){
      printf("%d ", arr_arr[i][j]);
      j++;
    }
    int k=arr_len-1;
    while(k>-1){
      printf("%d ", arr_arr[i][k]);
      k--;
    }
    printf("\n");
  }
}

int main () {

  int n = 7;
  int arr_len = n;
  int *arr_arr[arr_len];

  make_square(n, arr_len, arr_arr);
  print_square(arr_len, arr_arr);

  return 0;
}
