// Convert height from centimetres to feet.

#include <stdio.h>

#define INCHES_IN_FOOT  12
#define CM_IN_INCH      2.54

int getInput(void) {
   printf("Enter your number of centimetres: ");
   int centimetres;
   scanf("%d", &centimetres);
   return centimetres;
}

int main(void) {

   int centimetres = getInput();

   double inches = centimetres / CM_IN_INCH;
   double feet   = inches / INCHES_IN_FOOT;

   printf("%dcms =~ %lffeet\n", centimetres, feet);

   return 0;
}
