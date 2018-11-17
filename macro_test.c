#include <stdio.h>

/* cheesy preprocessing*/

#define len(array) sizeof(array)/sizeof(int)

#define sum(array)                                              \
        ({ double sum = 0;                                      \
           for (int i = 0; i < len(array); i++)                 \
               { sum+=array[i]; }                               \
           sum;                                                 \
        })

#define mean(array)                                             \
        ({ double s = sum(array);                               \
           double l = len(array);                               \
              s/l;                                              \
        })

#define print_array(array)                                      \
        ({ for (int i = 0; i < len(array); i++)                 \
               {printf("%d ", array[i]);}                       \
        })

#define print_mean_for_(array)                                  \
        ({ printf("%.2f is the mean of array : ", mean(array)); \
           print_array(array);                                  \
        })

int main() {

  int my_array[] = {4,6,10,5,3,2};

  print_mean_for_(my_array);

  return 0;
}
