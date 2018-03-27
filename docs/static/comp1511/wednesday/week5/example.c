#include <stdbool.h>
#include <stdio.h>

#define ARRAY_SIZE 8
#define TITLE_SIZE 20

typedef struct _movie {
   int    year;
   char   title[TITLE_SIZE];
   bool   showing;
   int    gross_take;
} movie;

void printMovies(movie movies[], int len);
void printMovie(movie m);
int  filterAfterYear(movie movies[], int len, movie filter[], int year);

int main(void) {
   movie movies[ARRAY_SIZE] = {
      {1977, "Star Wars", false, 280},
      {1965, "The Sound of Music", false, 81},
      {2017, "The Death of Stalin", true, 50},
      {2017, "Red Sparrow", true, 122},
      {1964, "Goldfinger", false, 110},
      {1984, "Ghostbusters", false, 201},
      {1999, "The Sixth Sense", false, 99},
      {1999, "Saving Private Ryan", false, 310}
   };

   movie filter[ARRAY_SIZE];
   int year;
   printf("Enter a year to filter by: ");
   scanf("%d", &year);
   int numResults = filterAfterYear(movies, ARRAY_SIZE, filter, year);

   printMovies(filter, numResults);

   return 0;
}

int  filterAfterYear(movie movies[], int len, movie filter[], int year) {
   int i = 0;
   int numResults = 0;
   while (i < len) {
      if (movies[i].year > year) {
         filter[numResults] = movies[i];
         numResults++;
      }
      i++;
   }

   return numResults;
}

void printMovie(movie m) {
   printf("%s (%d)\n"
          "=====================\n"
          "Currently showing:\t%s\n"
          "Gross Take ($m)  :\t$%dm\n\n",
            m.title,
            m.year,
            m.showing ? "Yes" : "No",
            m.gross_take);
}

void printMovies(movie movies[], int len) {
   int i = 0;
   while (i < len) {
      printMovie(movies[i]);
      i++;
   }
}
