#include <stdio.h>
#include <stdlib.h>

#define NUM_ALPHABET 26

int isCaps(unsigned char c) {
   if (c >= 'A' && c <= 'Z') {
      return 1;
   }
   return 0;
}

int isLower(unsigned char c) {
   if (c >= 'a' && c <= 'z') {
      return 1;
   }
   return 0;
}

int isAlpha(unsigned char c) {
   if (isCaps(c) || isLower(c)) {
      return 1;
   }
   return 0;
}

char cipher(unsigned char c, int offset) {

   offset = offset % NUM_ALPHABET;

   if (offset < 0) {
      offset = NUM_ALPHABET - offset;
   }

   if (isAlpha(c)) {
      if (isCaps(c)) {
         c = c + offset;
         if (c > 'Z') {
            c = c - NUM_ALPHABET;
         }
      } else {
         c = c + offset;
         if (c > 'z') {
            c = c - NUM_ALPHABET;
         }
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
