#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define ASCII 0x08
#define UNICODE 0xF0
// catches the top bit if it exists

#define MASK2 0xC0
// 11
// tag for 3-byte character
#define MASK3 0xE0
// 111
// tag for 4-byte character
#define MASK4 0xF0
// 1111

int unicodeNbytes(char *str) {
   int count = 0;
   for (count = 0; *str != '\0'; str++, count++);
   return count;
}

int unicodeNsymbols(char *str) {
   /* Use a mask to determine length of unicode byte */
   int count = 0;
   for (char c = *str; *str != '\0'; count++) {
      if (c & ASCII) {
         str++;
      } else if (c & UNICODE) {
         if (c & MASK2)
            str+=2;
         else if (c & MASK3)
            str+=3;
         else if (c & MASK4)
            str+=4;
      } else {
         // invalid character;
         str++;
      }
   }

   return count;
}

int main(int argc, char *argv[]) {
   /* code */
   assert(unicodeNbytes("abc\xE2\x86\xAB""def") == 9);
   assert(unicodeNsymbols("abc\xE2\x86\xAB""def") == 7);

   return 0;
}
