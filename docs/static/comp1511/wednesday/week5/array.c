#include "array.h"
#include <stdio.h>

void printArray(int array[], int len) {
   for (unsigned int i = 0; i < len; i++) {
      printf("%d", array[i]);
      if (i < len) {
         printf(" ");
      }
   }
   printf("\n");
}
