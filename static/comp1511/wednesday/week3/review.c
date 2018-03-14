/*
review.c
This program multiplies two numbers together.
If the number is less than 10, we print something.
By Alexander Hinds, z3420752
*/

#include <stdio.h>

int multiply(int x, int y) {
   return x*y;
}

int main(int argc, char const *argv[]) {
   int x = 10;
   int y = 22;

   int result = multiply(x1, y);

   if (result < 10) {
      printf("LESS THAN 10\n");
   }
   return 0;
}
