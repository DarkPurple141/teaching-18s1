// assume a bunch of #include's
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void handler(int sig)
{
   printf("Quitting...\n");
   exit(0);
}

int main(int argc, char *argv[])
{
   struct sigaction act;
   memset (&act, 0, sizeof(act));
   act.sa_handler = &handler;
   sigaction(SIGHUP, &act, NULL);
   sigaction(SIGINT, &act, NULL);
   sigaction(SIGKILL, &act, NULL);
   while (1) sleep(5);

   return 0;
}
