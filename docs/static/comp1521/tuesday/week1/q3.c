#include <stdio.h>

int main(void)
{
   char *str = "abc123\n";
   char *c;

   for (c = str; *c != '\0'; c++)
      putchar(*c);

   return 0;
}
