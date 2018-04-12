#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
   int i = 0;

   while (i < argc) {
      int j = 0;
      while (argv[i][j] != '\0') {
         putchar(argv[i][j]);
         j++;
      }
      printf("\n");
      i++;
   }
   // for CAESER U MAY NEED TO ACCESS ARGV
   // ARGV is the on command line arguments.
   // SO if I have ./myProg something something else
   //   equates to argv[0]   argv[1]   argv[2]  argv[3]

   /*
   while ((c = getchar()) != EOF) {
      //printf("ASCII %c == NUMBER %d\n", c, c);
   }
   */

   return 0;
}
