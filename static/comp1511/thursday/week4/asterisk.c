#include <stdio.h>

int main(int argc, char const *argv[]) {
   /* code */
   int number;
   printf("Please enter an integer: ");
   scanf("%d", &number);

   int i = 0;
   while (i < number) {
      printf("*\n");
      i = i + 1;
      // i++;
      // i += 1;
   }

   return 0;
}
