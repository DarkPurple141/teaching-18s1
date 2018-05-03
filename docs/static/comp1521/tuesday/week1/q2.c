#include <stdio.h>

int main(void)
{
   int n = 1234;
   int *p;

   p = &n;
   n++;
   printf("%d\n", *p);
   printf("%p\n", p);
   p++;
   printf("%p\n", p);
   return 0;
}
