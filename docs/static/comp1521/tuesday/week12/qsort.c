
#include <stdlib.h>
#include <stdio.h>

void printArray(int *array, int size) {
   int i = 0;
   while (i < size) {
      printf("%d ", array[i]);
      i++;
   }
   printf("\n");
}

int compare(const void* a, const void *b) {
   int*first = (int*)a;
   int*second = (int*)b;
   return *first - *second;
}

int main(int argc, char const *argv[]) {

   int array[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
   printArray(array, 10);

   qsort(array, 10, sizeof(int), compare);

   printArray(array, 10);

   return 0;
}
