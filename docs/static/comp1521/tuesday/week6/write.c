#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

typedef struct _graphics {
   int   x;  // x coordinate
   int   y;  // y coordinate
   char  r;  // red level
   char  g;  // green level
   char  b;  // blue level
} Graphics;


int main(void)
{
   int pic = open("Picture", O_WRONLY | O_TRUNC | O_CREAT);
   if (pic < 0)
      perror("No Picture jeff.");

   Graphics point;

   for (size_t i = 0; i < 5; i++) {
      point = { i, i, i, i, i };
      write(pic, &point, sizeof(Graphics));
   }

   close(pic);

   return 0;
}
