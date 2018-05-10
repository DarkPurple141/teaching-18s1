
#include <stdio.h>

int sum(int a, int b) {
   return a + b;
}

int main(void) {

   printf("Test 1: 21 + 21\n");
   assert(sum(21, 21) == 42);

   printf("Test 2: -1 + 21\n");
   assert(sum(-1, 21) == 20);

   printf("Test 3: 5 + 7\n");
   assert(sum(5, 7) == 12);

   printf("YOU ARE AWESOME, ALL TESTS PASSED!\n");
   return 0;
}
