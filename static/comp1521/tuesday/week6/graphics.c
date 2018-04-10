#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>

typedef struct _graphics {
   int   x;  // x coordinate
   int   y;  // y coordinate
   char  r;  // red level
   char  g;  // green level
   char  b;  // blue level
} Graphics;


void display(int fd, Graphics g) {
   printf("g.x %d, g.y %d\n", g.x, g.y);
   write(fd, &g, sizeof(Graphics));
}

int main(void)
{

   int output = open("output.dat", O_WRONLY | O_CREAT);

   if (output < 0)
      perror("No Output jeff.");

   Graphics g = {
      .x = 5,
      .y = 10,
      .r = 200,
      .g = 100,
      .b = 5
   };

   display(output, g);

   close(output);

   return 0;
}
