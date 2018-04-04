// COMP1511 Farnarkling lab exercises
//
// This program by ALEXANDER HINDS (z3420752) on 31.3.18

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "farnarkle.h"
#define N_TILES 4
#define MAX_TILE 8
#define MAX_TURNS 100

// Don't change these functions
int test_farnarkle_ai(int hidden_tiles[]);
void print_two_tile_sequences(int tiles1[N_TILES], int tiles2[N_TILES]);
void read_two_tile_sequences(int tiles1[N_TILES], int tiles2[N_TILES]);
int read_tiles(int tiles[N_TILES]);
void print_tiles(int tiles[N_TILES]);
void set_tiles_to_pseudo_random_values(int tiles[N_TILES]);

// ADD YOUR #defines (if any) here

// You have to write these functions
int count_farnarkles(int tiles1[N_TILES], int tiles2[N_TILES]);
int count_arkles(int tiles1[N_TILES], int tiles2[N_TILES]);
void play_farnarkle(int hidden_tiles[]);
void farnarkle_ai(int turn, int previous_guesses[MAX_TURNS][N_TILES],
                  int farnarkles[MAX_TURNS], int arkles[MAX_TURNS],
                  int guess[N_TILES]);

// ADD PROTOTYPES FOR ANY FUNCTIONS YOU CREATE HERE

// DO NOT CHANGE THIS FUNCTION
// This main function won't be marked as part of the lab
// It tests the functions you have to write.
// Do not change this main function.  If it does not work with
// your functions you have misunderstood the lab.

int main(void) {
    int call_which_function = 0;

    printf("Enter 0 to call count_farnarkles()\n");
    printf("Enter 1 to call count_arkles()\n");
    printf("Enter 2 to call play_farnarkle()\n");
    printf("Enter 3 to call test_ai_farnarkle_player()\n");
    printf("Call which function: ");
    scanf("%d", &call_which_function);

    if (call_which_function == 0) {
        int tiles1[N_TILES], tiles2[N_TILES];
        read_two_tile_sequences(tiles1, tiles2);
        int farnarkles = count_farnarkles(tiles1, tiles2);
        printf("count_farnarkles returned %d for\n", farnarkles);
        print_two_tile_sequences(tiles1, tiles2);
    } else if (call_which_function == 1) {
        int tiles1[N_TILES], tiles2[N_TILES];
        read_two_tile_sequences(tiles1, tiles2);
        int arkles = count_arkles(tiles1, tiles2);
        printf("count_arkles returned %d for\n", arkles);
        print_two_tile_sequences(tiles1, tiles2);
    } else if (call_which_function == 2) {
        int hidden_tiles[N_TILES];
        set_tiles_to_pseudo_random_values(hidden_tiles);
        play_farnarkle(hidden_tiles);
    } else if (call_which_function == 3) {
        int hidden_tiles[N_TILES];
        printf("Enter hidden tiles: ");
        assert(read_tiles(hidden_tiles) == N_TILES);
        test_farnarkle_ai(hidden_tiles);
    }

    return 0;
}

// return number of farnarkles
int count_farnarkles(int hidden[N_TILES], int guess[N_TILES]) {

    int count = 0;
    int i     = 0;

    while (i < N_TILES) {
       if (hidden[i] == guess[i]) {
          count++;
       }
       i++;
    }

    return count;
}

// return number of arkles
int count_arkles(int hidden[N_TILES], int guess[N_TILES]) {

    int work[N_TILES] = {0};
    int copy[N_TILES] = {0};

    int arkles = 0;
    int i, j;

    i = 0;
    while (i < N_TILES) {
       copy[i] = hidden[i];
       if (hidden[i] != guess[i]) {
          work[i] = guess[i];
       } else {
          copy[i] = -1;
       }
       i++;
    }

    i = 0;
    while (i < N_TILES) {
       j = 0;
       int found = 0;
       while (j < N_TILES && !found) {
          if (copy[i] == work[j]) {
             found = 1;
             work[j] = 0;
             arkles++;
          }
          j++;
       }
       i++;
    }

    return arkles;
}

// play_farnarkle is given a sequence hidden tiles
// It reads guesses from a human player,
// printing the number of farnarkles and arkles for each guess,
// until the human player guesses the sequence.

void play_farnarkle(int hidden_tiles[N_TILES]) {
    // PUT YOUR CODE HERE
}

// farnarkle_ai is given
//
// turn: the turn number
// previous_guesses: an array of turn - 1 previous guesses
// farnarkles: an array of turn - 1 farnarkle counts for previous guesses
// arkles: an array of turn - 1 arkle counts for previous guesses
//
// it should choose a suitable guess and store it in the array guess
static void bucket_sort(int array[]) {
   int i = 0;
   int buckets[MAX_TILE + 1] = {0};

   while (i < N_TILES) {
      buckets[array[i]]++;
      i++;
   }
   i = 0;
   int j = 0;
   while (i <= MAX_TILE && j < N_TILES) {
      while (buckets[i]) {
         array[j++] = i;
         buckets[i]--;
      }
      i++;
   }
}

void farnarkle_ai(int turn, int previous_guesses[MAX_TURNS][N_TILES],
                  int farnarkles[MAX_TURNS], int arkles[MAX_TURNS],
                  int guess[N_TILES]) {
      int i = 0;
      int j = 0;
      int definite[MAX_TILE + 1] = {0};
      int pool[N_TILES] = {0};
      if (turn > 0) {
         int numArkles = 0;
         int numFarns  = 0;
         /* detemine definites */
         while (i < turn) {
            numArkles = arkles[i];
            numFarns  = farnarkles[i];
            if (numFarns + numArkles == N_TILES) {
               j = 0;
               while (j < N_TILES) {
                  definite[previous_guesses[i][j]]+=1;
                  j++;
               }
            }
            i++;
         }
         i = 1;
         int j = 0;
         while (i <= MAX_TILE) {
            if (definite[i]) {
               pool[j++] = i;
            }
            i++;
         }
         if (j) {
            int i = 0;
            while (i < j) {
               guess[i] = pool[i];
               i++;
            }
         } else {
            set_tiles_to_pseudo_random_values(guess);
         }

      } else {
         while (i < N_TILES) {
            guess[i] = 1;
            i++;
         }
      }
}

// DO NOT CHANGE THE FUNCTIONS BELOW HERE

// DO NOT CHANGE THIS FUNCTION
void print_two_tile_sequences(int tiles1[N_TILES], int tiles2[N_TILES]) {
    printf("Sequence 1: ");
    print_tiles(tiles1);
    printf("\n");
    printf("Sequence 2: ");
    print_tiles(tiles2);
    printf("\n");
}

// DO NOT CHANGE THIS FUNCTION
void read_two_tile_sequences(int tiles1[N_TILES], int tiles2[N_TILES]) {
    printf("Enter tile sequence 1: ");
    assert(read_tiles(tiles1) == N_TILES);
    printf("Enter tile sequence 2: ");
    assert(read_tiles(tiles2) == N_TILES);
}

// DO NOT CHANGE THIS FUNCTION
// read N_TILES tiles into array tiles
// returns number of tiles successfully read
int read_tiles(int tiles[N_TILES]) {
    int i = 0;
    while (i < N_TILES) {
        if (scanf("%d", &tiles[i]) != 1) {
            return i;
        }
        if (tiles[i] < 1 || tiles[i] > MAX_TILE) {
            return i;
        }
        i = i + 1;
    }
    return i;
}

// DO NOT CHANGE THIS FUNCTION
// print tiles on a single line
void print_tiles(int tiles[N_TILES]) {
    int i = 0;
    while (i < N_TILES) {
        printf("%d", tiles[i]);
        if (i < N_TILES - 1) {
            printf(" ");
        }
        i = i + 1;
    }
}

// DO NOT CHANGE THIS FUNCTION
void set_tiles_to_pseudo_random_values(int tiles[N_TILES]) {
    // seed (initialize) pseudo-random number generate with current time in seconds
    srand(time(NULL));

    int i = 0;
    while (i < N_TILES) {
        // rand() returns a pseudo-random integer in ranger 0 to RAND_MAX inclusive
        // convert to an integer in the range 1..MAX_TILE_template
        tiles[i] = rand() % MAX_TILE + 1;
        i = i + 1;
    }
}

// DO NOT CHANGE THIS FUNCTION

// test_farnarkle_ai is given a sequence of hidden tiles
// It calls the function farnarkle_ai to make a guess
// printing the number of farnarkles and arkles for each guess,
// until farnarkle_ai guesses the sequence.
// number of turns taken is returned

int test_farnarkle_ai(int hidden_tiles[N_TILES]) {
    int guesses[MAX_TURNS][N_TILES] = {{0}};
    int farnarkles[MAX_TURNS] = {0};
    int arkles[MAX_TURNS] = {0};
    int turn_limit = MAX_TILE * N_TILES;

    int turn = 0;
    while (turn <= turn_limit) {

        int i = 0;
        while (i < N_TILES) {
            guesses[turn][i] = -1;
            i = i + 1;
        }

        printf("Turn %d: farnarkle AI guess is: ", turn + 1);
        fflush(stdout); // help debugging

        farnarkle_ai(turn + 1, guesses, farnarkles, arkles, guesses[turn]);

        print_tiles(guesses[turn]);
        printf(" = ");

        int j = 0;
        while (j < N_TILES) {
            if (guesses[turn][j] < 1 || guesses[turn][j] > MAX_TILE) {
                printf("Invalid guess\nGame ended\n");
                return 0;
            }
            j = j + 1;
        }

        farnarkles[turn] = count_farnarkles(hidden_tiles, guesses[turn]);
        arkles[turn] = count_arkles(hidden_tiles, guesses[turn]);

        printf("%d farnarkles, %d arkles\n", farnarkles[turn], arkles[turn]);

        if (farnarkles[turn] == N_TILES) {
            printf("Farnarkle AI took %d turns to guess the tiles.\n", turn + 1);
            return turn + 1;
        }
        turn = turn + 1;
    }
    printf("Turn limit of %d turns exceeded\nGame ended\n", turn_limit);
    return turn + 1;
}
