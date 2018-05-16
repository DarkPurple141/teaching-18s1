/*int size = 10;
int myarray[size];

for (int i = 0; i < size; i ++) {
   myarray[i] = 0;
}

myarray[HAND_SIZE] = {0};

int *my_array = calloc(size, sizeof(int));
int *my_array = malloc(size*sizeof(int));
*/

#include <stdio.h>

int main(void) {

   int size = 0;
   scanf("%d", &size);

   int array[size];
   int i = 0;
   while (i < size) {
      array[i] = i;
      i++;
   }

   return 0;
}
