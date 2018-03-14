// Convert height from centimetres to feet.

#include <stdio.h>

#define INCHES_IN_FOOT  12
#define CM_IN_INCH      2.54

int readCMs(void) {
   int cm;
   printf("Enter centimetres: ");
   scanf("%d", &cm);
   return cm;
}

int converCMsToFeet(int centimetres) {
   int inches  = centimetres / CM_IN_INCH;
   int feet    = inches / INCHES_IN_FOOT;

   return feet;
}

int main(void) {

   int cms = readCMs();

   int feet = converCMsToFeet(cms);

   printf("%dcm = %dfeet\n", cms, feet);

   return 0;
}
