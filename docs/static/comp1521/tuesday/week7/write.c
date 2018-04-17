#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include "graphics.h"

Graphics initGraphics(int i) {
   Graphics g = { .x = i, .y = i, .r = i, .b = i, .g = i };
   return g;
}

int main(void)
{
   int pic = open("Picture", O_WRONLY | O_TRUNC | O_CREAT);
   if (pic < 0)
      perror("No Picture was created :-(");

   Graphics point;

   for (size_t i = 0; i < 5; i++) {
      point = initGraphics(i);
      write(pic, &point, sizeof(Graphics));
   }

   close(pic);

   return 0;
}
