#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define LENGTH_OF_ALPHABET 26

int isLower(char c) {
   if (c >= 'a' && c <= 'z') {
      return TRUE;
   }
   return FALSE;
}

int isUpper(char c) {
   if (c >= 'A' && c <= 'Z') {
      return TRUE;
   }
   return FALSE;
}

int isAlpha(char c) {
   return isUpper(c) || isLower(c);
}

char accountForWrap(unsigned char toEncode, char end, int offset) {
   toEncode = toEncode + offset;

   if (toEncode > end) {
      toEncode = toEncode - LENGTH_OF_ALPHABET;
   }
   return toEncode;
}


char cipher(char c, int offset) {

   offset = offset % LENGTH_OF_ALPHABET;

   if (offset < 0) {
      offset = offset + LENGTH_OF_ALPHABET;
   }

   if (isAlpha(c)) {
      if (isLower(c)) {
         c = accountForWrap(c, 'z', offset);
      } else {
         c = accountForWrap(c, 'Z', offset);
      }
   }

   return c;
}

int main(int argc, char *argv[]) {

   char c;
   int offset;
   printf("Enter an offset: ");
   scanf("%d", &offset);

   while ((c = getchar()) != EOF) {
      putchar(cipher(c, offset));
   }

   return 0;
}
