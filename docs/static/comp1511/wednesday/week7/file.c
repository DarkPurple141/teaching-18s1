#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 4096

int main(int argc, char *argv[]) {

   FILE * file = fopen("path", "w");

   char line[MAX_LINE];

   while (fgets(line, MAX_LINE, stdin) != NULL) {

      /*
      i = 0;
      while (line[i] != '\n' && line[i] != '\0') {
           i++;
      }
      */

     fputs(line, file);


   }

   fclose(file);


   return 0;
}
