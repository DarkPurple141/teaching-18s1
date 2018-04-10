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
   int pic = open("Picture", O_WRONLY | O_APPEND);
   if (pic < 0)
      perror("No Picture jeff.");

   Graphics point = { 0, 0, 0, 0, 0 };

   size_t gsize = sizeof(Graphics);

   for (size_t i = 0; i < 5; i++) {
      write(pic, &point, gsize);
   }

   close(pic);

   return 0;
}
