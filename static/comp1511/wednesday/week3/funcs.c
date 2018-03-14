#include <stdio.h>

int readNumber(void) {
   int number;
   printf("Enter a number < 10000: ");
   scanf("%d", &number);

   return number;
}

int printDigit(int number, int diviser) {
     if (number > diviser - 1) {
        printf("%d ", number/diviser);
     } else if (!number){
        printf("0 ");
     }
     return number % diviser;
}

int main(void) {

   int number = readNumber();

   printf("You have entered: %d\n", number);
   int diviser = 10000;

   // this is simpler

   while (diviser) {
      /* code */
      number = printDigit(number, diviser);
      diviser = diviser / 10;
   }

   return 0;
}
