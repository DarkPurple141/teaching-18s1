#include "array.h"
#include <stdio.h>

/* sum array */
int sumArray(int array[], int length) {
   int sum = 0;
   int i = 0;
   while (i < length) {
      int current = array[i];
      sum = sum + current;
      i++;
   }

   return sum;
}
