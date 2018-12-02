#include <stdio.h>
#include <math.h>

/* cheesy preprocessing*/

#define print_array(array)                                      \
        ({ for (int i = 0; i < len(array); i++)                 \
               {printf("%d ", array[i]);}                       \
        })

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

#define standard_deviation(array)                               \
        ({ double m = mean(array);                              \
           double s = sum(array);                               \
           double dev = 0;                                      \
           for (int i = 0; i <len(array); i++)                  \
            {                                                   \
              double sq = (pow( (array[i] - m), 2) / s);        \
              dev += sq;                                        \
            }                                                   \
            sqrt(dev);                                          \
        })

#define print_stats_for_(array)                                 \
        ({ printf("Mean : %.2f\n", mean(array));                \
           printf("Standard Devation : %.2f\n",                 \
                   standard_deviation(array));                  \
           print_array(array);                                  \
          })                                                    \

int main() {

  int my_array[] = {2,2,2,200,2,2};

  print_stats_for_(my_array);
  return 0;
}
