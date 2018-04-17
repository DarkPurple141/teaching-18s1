#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include "graphics.h"

static void printRecords(int fd);

// update the kth entry in the fd witht the new struct
int update(int fd, int k, Graphics new) {

   // lseek forward
   lseek(fd, k*sizeof(new), SEEK_SET);

   // write over point
   return write(fd, &new, sizeof(new));
}

int main(int argc, char const *argv[]) {

   // open file
   int fd = open("Picture", O_RDWR);

   Graphics new = {
      .x = 0,
      .y = 0,
      .g = 100,
      .b = 100,
      .r = 100
   };

   update(fd, 10, new);

   // close file
   printRecords(fd);

   close(fd);

   return 0;
}

static void printRecords(int fd) {
   lseek(fd, 0, SEEK_SET);
   Graphics g;
   int i = 0;
   while (read(fd, &g, sizeof(Graphics)) > 0) {
      printf("Entry %d\n", i++);
      printf("G.r = %d, G.b = %d, G.g = %d\n", g.r, g.b, g.g);
   }
}
