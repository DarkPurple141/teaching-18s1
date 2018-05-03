#include <assert.h>
#include <limits.h>
#include <stdio.h>

unsigned int reverseBits(int number) {
   unsigned int mask = 1;
   unsigned int hiMask = 1 << 31;
   unsigned int retVal = 0;

   while (hiMask) {
      if (mask & number) {
         retVal |= hiMask;
      }
      hiMask >>= 1;
      mask <<= 1;
   }

   return retVal;
}


int main(void) {
   /* code */

   unsigned int number = 0x01234567;

   assert(reverseBits(number) == 0xE6A2C480);
   assert(reverseBits(0) == 0);
   assert(reverseBits(1) == 1<<31);
   assert(reverseBits(1<<31) == 1);

   return 0;
}
