
#include <stdio.h>
#include <stdlib.h>



int main(int argc, char const *argv[]) {
   char c;
   // for CAESER U MAY NEED TO ACCESS ARGV
   // ARGV is the on command line arguments.
   // SO if I have ./myProg something something else
   //   equates to argv[0]   argv[1]   argv[2]  argv[3]

   while ((c = getchar()) != EOF) {
      //putchar(c);
      printf("ASCII %c == NUMBER %d\n", c, c);
   }

   return 0;
}
