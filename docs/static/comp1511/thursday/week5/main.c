#include "array.h"
#include <stdio.h>

int main(int argc, char *argv[]) {

   int originalArray[ARRAY_LENGTH];

   initArray(originalArray, ARRAY_LENGTH);

   printArray(originalArray, ARRAY_LENGTH);

   #ifdef MAP
   multArray(originalArray, ARRAY_LENGTH);
   printArray(originalArray, ARRAY_LENGTH);
   #endif

   #ifdef REDUCE
   int sum = sumArray(originalArray, ARRAY_LENGTH);
   printf("The sum is %d.\n", sum);
   #endif

   #ifdef FILTER
   int filter[ARRAY_LENGTH];
   int filter_length = filterArray(originalArray, ARRAY_LENGTH, filter);
   printArray(filter, filter_length);
   #endif

   return 0;
}
