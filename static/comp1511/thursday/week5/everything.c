#include "array.h"
#include <stdio.h>

int main(int argc, char const *argv[]) {

   int array[ARRAY_LENGTH];
   int filter[ARRAY_LENGTH];
   initArray(array, ARRAY_LENGTH);

   printArray(array, ARRAY_LENGTH);

   int size = filterArray(array, ARRAY_LENGTH, filter, 6);
   squareArray(filter, size);
   sumArray(filter, size);

   printArray(filter, size);

   return 0;
}
