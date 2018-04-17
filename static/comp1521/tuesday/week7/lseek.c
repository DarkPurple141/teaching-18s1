#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <assert.h>

int main(int argc, char const *argv[]) {

   int offset;
   int fd = open("index.json", O_RDONLY);
   char buffer[26];

   while (1) {
      // scan in an offset
      scanf("%d", &offset);

      // use lseek to move the file descripter
      int retval = lseek(fd, offset, SEEK_END);

      // read from this offset
      read(fd, buffer, 25);

      // set the 'null' terminator
      buffer[25] = 0;

      // print the buffer.
      printf("%s\n", buffer);
   }

   close(fd);
   /*
   lseek(fd, 0, SEEK_END);

   lseek(fd, -1000, SEEK_CUR);

   lseek(fd, 0, SEEK_SET);

   lseek(fd, -100, SEEK_SET);

   lseek(fd, 1000, SEEK_SET);

   lseek(fd, 1000, SEEK_CUR);
   */
   return 0;
}
