#include "array.h"

/* filter everything in array by numbers < filterBy variable */

int filterArray(int array[], int length, int filter[], int filterBy) {
   int i = 0;
   int filterLength = 0;

   while (i < length) {
      if (array[i] < filterBy) {
         filter[filterLength] = array[i];
         filterLength++;
      }
      i++;
   }

   return filterLength;
}
