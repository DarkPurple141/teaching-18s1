#include <stdio.h>

int main(void)
{
   int n, a, b, c;
   n = scanf("%d %d %d", &a, &b, &c);

   printf("n = %d\na: %d b: %d c: %d\n", n, a, b, c);

   return 0;
}

/*
if (condition) {
   a = 4
} else {
   a = 5
}

a = (condition) ? 4 : 5;

*/
