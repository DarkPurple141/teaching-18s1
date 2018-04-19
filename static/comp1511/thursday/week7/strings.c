#include <stdio.h>

int main(int argc, char *argv[]) {

   // five ways to declare a string
   char andrew[10] = "Hello";
   char ed[10] = {'H', 'e', 'l', 'l', 'o', '\0'};
   char al[10] = {72, 101, 108, 108, 111, 0};
   char *seli = "Hello";
   char str[] = "Hello";

   printf("%s\n", andrew);
   printf("%s\n", ed);
   printf("%s\n", al);
   printf("%s\n", seli);
   printf("%s\n", str);

   return 0;
}
