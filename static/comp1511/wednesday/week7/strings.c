
#include <stdio.h>


int main(int argc, char *argv[]) {

   char str1[3] = "Hi";
   char str2[3] = {'H', 'i', '\0'};
   char str3[3] = {72, 105, 0};
   char str4[] = "Hi";
   char *str5 = "Hi";

   printf("%s\n", str1);
   printf("%s\n", str2);
   printf("%s\n", str3);
   printf("%s\n", str4);
   printf("%s\n", str5);
   str1[0] = 'j';

   return 0;
}
