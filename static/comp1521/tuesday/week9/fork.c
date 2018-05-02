#include <unistd.h>
#include <stdio.h>

int main(void)
{
   printf("Hello\n");
   if (fork() != 0) {
      printf("Gan bei\n");
      printf("Parent ppid %d\n", getppid());
      printf("Parent pid %d\n", getpid());
   }

   else {
      printf("Child ppid %d\n", getppid());
      printf("Child pid %d\n", getpid());
      printf("Prost\n");
   }

   printf("Goodbye\n");

   return 0;
}
