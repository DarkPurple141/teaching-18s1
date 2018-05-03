#include "array.h"
#include <stdio.h>

int sq(int a) {
   return a*a;
}

/* multiply everything by itself in array */
void squareArray(int array[], int length) {
   int i = 0;

   while (i < length) {
      array[i] = sq(array[i]);
      i++;
   }
}
