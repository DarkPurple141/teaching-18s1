#include <stdio.h>
#define TRUE 1

void clearInput() {
   char c;
   while ((c = getchar()) != '\n');
}

int main(int argc, char *argv[]) {

   int running = TRUE;
   printf("Welcome to my sweet application.\n");
   while (running) {

      char userInput;
      printf("Press q to quit.\n");
      scanf("%c", &userInput);
      clearInput();

      if (userInput == 'q') {
         running = 0;
      }
   }

   return 0;
}
