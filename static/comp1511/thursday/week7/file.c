#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 4096

int countLine(char *str) {
   int i = 0;
   i = 0;
   while (str[i] != '\n' && str[i] != '\0') {
       i++;
   }
   return i;
}

int main(int argc, char *argv[]) {

   FILE *fp = fopen("happy_story.txt", "w");

   char line[MAX_LINE];
   int i = 1;

   while (fgets(line, MAX_LINE, stdin) != NULL) {
      int length = countLine(line);
      fprintf(fp, "%d %s (chars long = %d)\n", i, line, length);
      i++;
   }

   fclose(fp);

   return 0;
}
