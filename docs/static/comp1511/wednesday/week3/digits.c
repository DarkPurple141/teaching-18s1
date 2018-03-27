// prints out digits of number as seperate digts

#include <stdio.h>

int main(void) {

   int number;
   printf("Enter a number < 10000: ");
   scanf("%d", &number);

   printf("You have entered: %d\n", number);
   int flag = 0;

   // This is bad see how similiar each block of code
   // looks maybe I should use a function see funcs.c to understand how.

   if (number > 9999) {
      printf("%d ", number / 10000);
      number = number % 10000;
   } else if(flag) printf("0 ");

   if (number > 999) {
      printf("%d ", number / 1000);
      number = number % 1000;
      flag = 1;
   } else if(flag) printf("0 ");

   if (number > 99) {
      printf("%d ", number / 100);
      number = number % 100;
      flag = 1;
   } else if(flag) printf("0 ");

   if (number > 9) {
      printf("%d ", number / 10);
      number = number % 10;
      flag = 1;
   } else if(flag) printf("0 ");

   printf("%d\n", number);


   return 0;
}
