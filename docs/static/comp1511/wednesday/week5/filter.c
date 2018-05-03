#include "array.h"

/* filter everything in array by numbers < 5 */

int filterArray(int array[], int length, int filter[]) {
   int i, filterIndex;

   i = 0;
   filterIndex = 0;

   while (i < length) {
      if (array[i] < 5) {
         filter[filterIndex] = array[i];
         filterIndex++;
      }
      i++;
   }

   return filterIndex;
}
