#include <stdio.h>
#define SIZE 1000

void print();

int main(int argc, char const *argv[]) {
   print();
   return 0;
}

void print_array(char * prefix, int array[], int len) {
   printf("%s", prefix);
   int i = 0;
   while (i < len) {
      printf("%d ", array[i]);
   }
   printf("\n");
}

void print() {
   int evens[SIZE];
   int odds[SIZE];

   int i, j, n;
   i = j = 0;

   while (scanf("%d", &n)) {
      if (n < 0) {
         break;
      }
      if (n % 2 == 0) {
         evens[i++] = n;
      } else {
         odds[j++] = n;
      }
   }
   print_array("Odds are: ", odds, j);
   print_array("Evens are: ", evens, i);
}
