#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <fcntl.h>
#include <ctype.h>

int main(int argc, char const *argv[]) {
   int fd; // open file descriptor
   int nb; // # bytes read
   int ns = 0; // # spaces
   char buf[BUFSIZ]; // input buffer

   fd = open("xyz", O_RDONLY);

   assert(fd >= 0);

   while ((nb = read(fd, buf, 1000)) > 0) {
       for (int i = 0; i < nb; i++)
           if (isspace(buf[i])) ns++;
   }

   close(fd);
   return 0;
}
