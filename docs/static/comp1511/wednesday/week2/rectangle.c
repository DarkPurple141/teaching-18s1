#include <stdio.h>

int main(void) {

   int length;
   int height;

   printf("Please enter a length: ");
   scanf("%d", &length);

   printf("Please enter a height: ");
   scanf("%d", &height);

   if (length < 0 || height < 0) {
      printf("You didn't enter a correct dimension!\n");
   } else {
      printf("AREA is %d\n", height * length);
   }



   return 0;
}
