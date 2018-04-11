#include <stdio.h>
#include <stdlib.h>

#define LENGTH_OF_ALPHABET 26
#define TRUE 1
#define FALSE 0

int isLowerCase(char c) {
   if (c >= 'a' && c <= 'z') {
      return TRUE;
   }
   return FALSE;
}

int isUpperCase(char c) {
   if (c >= 'A' && c <= 'Z') {
      return TRUE;
   }
   return FALSE;
}

int isAlpha(char c) {
   return isUpperCase(c) || isLowerCase(c);
}

char accountForWrap(char toEncode, char end, int offset) {
   toEncode = toEncode + offset;
   if (toEncode > end) {
      toEncode = toEncode - LENGTH_OF_ALPHABET;
   }
   return toEncode;
}

char cipher(char toEncode, int offset) {

   offset = offset % LENGTH_OF_ALPHABET;
   if (offset < 0) {
      offset = LENGTH_OF_ALPHABET + offset;
   }

   if (isAlpha(toEncode)) {
      if (isUpperCase(toEncode)) {
         toEncode = accountForWrap(toEncode, 'Z', offset);
      } else {
         toEncode = accountForWrap(toEncode, 'z', offset);
      }
   }

   return toEncode;
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
