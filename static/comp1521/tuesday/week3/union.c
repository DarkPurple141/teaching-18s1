
#include <stdio.h>

typedef union _all {
   int   ival;
   char cval;
   char  sval[4];
   float fval;
   unsigned int uval;
} all;

int main(int argc, char const *argv[]) {

   all var = 0x00313233;

   /* These print out different things! */
   printf("%x\n", var.uval);
   printf("%d\n", var.ival);
   printf("%c\n", var.cval);
   printf("%s\n", var.sval);
   printf("%f\n", var.fval);
   printf("%e\n", var.fval);

   return 0;
}
