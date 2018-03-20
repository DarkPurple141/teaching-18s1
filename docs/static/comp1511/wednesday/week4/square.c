#include <stdio.h>
#define TRIANGLE 0
#define SQUARE 1
#define DIAGONAL 2

void printTrianglePixel(int row, int col, int number);
void printDiagonalPixel(int row, int col);
void printShape(int number, int SHAPE);
void printSquarePixel(void);

int main(void) {
    int number;
    // Obtain input
    printf("Enter size: ");
    scanf("%d", &number);
    printShape(number, DIAGONAL);

    return 0;
}

void printDiagonalPixel(int row, int col) {
   if (col == row) {
     printf("*");
   } else {
     printf("-");
   }
}

void printTrianglePixel(int row, int col, int number) {
   if (col <= number - row) {
     printf("-");
   } else {
     printf("*");
   }
}

void printSquarePixel() {
   printf("*");
}


void printShape(int number, int SHAPE) {
   int row, column;
   row = 1;
   while (row <= number) {
      column = 1;
      while (column <= number) {
         if (SHAPE == TRIANGLE) {
            printTrianglePixel(row, column, number);
         } else if (SHAPE == DIAGONAL) {
            printDiagonalPixel(row, column);
         } else {
            printSquarePixel();
         }

          column = column + 1;
      }
      printf("\n");
      row = row + 1;
   }
}
