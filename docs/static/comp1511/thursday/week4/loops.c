#include <stdio.h>
#define TRUE 1

void clearInput() {
   char c;
   while ((c = getchar()) != '\n');
}

int main(int argc, char *argv[]) {

/*
   i++ // i = i + 1
   i += var // i = i + var
   i --
   i -=

   --i
   ++i
*/
   int running = 1;
   while (running) {

      checkEvents();
      processEvents();
      updateApplicationState();
      cleanUp();

   }

   return 0;
}

checkEvents() {
   while (event < numEvents) {
      if (event == true) {

      }
   }
}
