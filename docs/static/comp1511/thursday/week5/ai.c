

void farnarkle_ai(int turn, int previous_guesses[MAX_TURNS][N_TILES],
                  int farnarkles[MAX_TURNS], int arkles[MAX_TURNS],
                  int guess[N_TILES]) {
      int i = 0;

      if (turn < N_TILES) {
         while (i < N_TILES) {
            guess[i] = turn;
            i++:
         }
      } else {
         // turn > N_TILES
         while (i < turn) {
            if (arkles[i] > 0) {

            }
         }

      }
}
