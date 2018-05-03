#include "array.h"
#include <stdio.h>

/* multiply everything by 2 in array */
void multArray(int array[], int length) {
   int i = 0;

   while (i < length) {
      // array[i] = array[i] *2;
      int current = array[i];
      current = current * 2;
      array[i] = current;
      i++;
   }
}
