#include "array.h"
#include <stdio.h>

void initArray(int array[], int length) {
   int i = 0;
   while (i < length) {
      array[i] = i+1;
      i++;
   }
}

void printArray(int array[], int length) {
   for (int i = 0; i < length; i++) {
      printf("%d", array[i]);
      if (i < length) {
         printf(" ");
      }
   }
   printf("\n");
}
