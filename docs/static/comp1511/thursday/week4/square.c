#include <stdio.h>

#define SQUARE 0
#define TRIANGLE 1
#define DIAGONAL 2

void printShape(int number, int shape);
void determineShape(int number, int shape, int row, int col);
void printDiagonalPixel(int row, int col);
void printTrianglePixel(int number, int row, int col);

int main(void) {
    int number;
    int shape;
    // Obtain input
    printf("What shape do you want to print?\n"
           "Square:\t\t0\n"
           "Triangle:\t1\n"
           "Diagonal:\t2\n");
    scanf("%d", &shape);
    printf("Enter size: ");
    scanf("%d", &number);

    printShape(number, shape);

    return 0;
}

/* level 2 function */
void printShape(int number, int shape) {
   int row, col;

   row = 1;
   while (row <= number) {
       col = 1;
       while (col <= number) {
         determineShape(number, shape, row, col);
         col = col + 1;
       }
       printf("\n");
       row = row + 1;
   }
}


/* level 3 function */
void determineShape(int number, int shape, int row, int col) {
   if (shape == SQUARE) {
      printf("*");
   } else if (shape == DIAGONAL) {
      printDiagonalPixel(row, col);
   } else if (shape == TRIANGLE) {
      printTrianglePixel(number, row, col);
   }
}


/* level 4 funcitons */
void printDiagonalPixel(int row, int col) {
   if (row == col) {
      printf("*");
   } else {
      printf("-");
   }
}

void printTrianglePixel(int number, int row, int col) {
   if (number < row + col) {
      printf("*");
   } else {
      printf("-");
   }
}
