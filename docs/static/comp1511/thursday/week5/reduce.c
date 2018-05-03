#include "array.h"
#include <stdio.h>

/* sum array */
int sumArray(int array[], int length) {
   int sum = 0;
   int i = 0;

   while (i < length) {
      sum = sum + array[i];
      i++;
   }

   return sum;
}
