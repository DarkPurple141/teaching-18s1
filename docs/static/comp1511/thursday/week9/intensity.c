// intensity.c
// Assignment 2, COMP1511 18s1: Intensity
//
// Version 1.0.1: Minor changes to wording of comments.
// Version 1.0.0: Assignment released.

#include <stdio.h>
#include <assert.h>

// SOME USEFUL #defines - YOU WILL NEED MORE

#define ACTION_PLAYER_NAME    0
#define ACTION_DISCARD        1
#define ACTION_PLAY_CARD      2
#define ACTION_UNIT_TESTS     3

#define N_CARDS              40
#define N_CARDS_INITIAL_HAND 10
#define N_PLAYERS             4
#define N_CARDS_DISCARDED     3

#define CARD_MIN             10
#define CARD_MAX             49


// ADD EXTRA #defines HERE

void print_player_name(void);
void choose_discards(void);
void choose_card_to_play(void);
void run_unit_tests(void);


// ADD PROTOTYPES FOR YOUR FUNCTIONS HERE
int read_cards(int *array, int count) {
   int counter = 0;
   for (int i = 0; i < count; i++) {
      counter += scanf("%d", &array[i]);
   }
   return counter;
}


// You should not need to change this main function

int main(void) {

    int which_action = 0;
    scanf("%d", &which_action);
    if (which_action == ACTION_PLAYER_NAME) {
        print_player_name();
    } else if (which_action == ACTION_DISCARD) {
        choose_discards();
    } else if (which_action == ACTION_PLAY_CARD) {
        choose_card_to_play();
    }

    return 0;
}

void print_player_name(void) {
    printf("Fresh Prince of Buffalo Hearts");
}

void choose_discards(void) {
    // ADD CODE TO READ THE CARDS OF YOUR HAND INTO AN ARRAY USING SCANF
    // THEN ADD YOUR CODE HERE TO CHOOSE AND PRINT THE CARDS YOU WISH TO DISCARD

    // NOTE: THE PROVIDED CODE DOES NOT MAKE A LEGAL MOVE. YOU MUST CHANGE IT TO
    // DISCARD CARDS FROM YOUR HAND.
    printf("43 44 45\n");

}

void choose_card_to_play(void) {
    // ADD CODE TO READ THE FIRST THREE NUMBERS (NUMBER OF CARDS IN YOUR HAND,
    // NUMBER OF CARDS PLAYED THIS ROUND, TABLE POSITION)
    // ADD CODE TO READ THE CARDS OF YOUR HAND INTO AN ARRAY USING SCANF
    // ADD CODE TO READ THE CARDS PREVIOUSLY PLAYED THIS ROUND INTO AN ARRAY USING SCANF
    // ADD CODE TO READ THE CARDS PLAYED IN THE HISTORY OF THE GAME INTO AN ARRAY USING SCANF
    // ADD CODE TO READ THE CARDS YOU DISCARDED AT THE START INTO AN ARRAY USING SCANF
    // ADD CODE TO READ THE CARDS YOU RECEIVED AT THE START INTO AN ARRAY USING SCANF

    // THEN ADD YOUR CODE HERE TO CHOOSE AND PRINT THE CARD YOU WISH TO PLAY

    // NOTE: THE PROVIDED CODE DOES NOT MAKE A LEGAL MOVE. YOU MUST CHANGE IT TO
    // PLAY A CARD FROM YOUR HAND.
    printf("42\n");

}
