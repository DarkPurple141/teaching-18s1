struct bot {
    char            *name;
    struct location *location;
    int             cash;
    int             battery_level;
    char            *fruit;
    int             fruit_kg;
    int             turns_left;
    int             battery_capacity;
    int             maximum_move;
    int             maximum_fruit_kg;
};

struct location {
    char                *name;
    char                *fruit;
    int                 price;
    int                 quantity;
    struct location     *east;
    struct location     *west;
    struct bot_list     *bots;
};

int fruit_on_board(struct bot *b, char *name) {
   if (strcmp(name, b->fruit) == 0) {
      return b->fruit_kg;
   }
   return 0;
}

int mars_bars_on_board(struct bot *b) {
   return fruit_on_board(b, "Mars Bars");
}

int fruit_at_location(struct location *l, char *fruit) {
   if (strcmp(fruit, l->fruit) == 0) {
      return l->quantity;
   }
   return 0;
}

int mars_bars_for_sale(struct bot *b) {
   struct location *current = b->location;
   return fruit_at_location(current, "Mars Bars");
}

int nearest_fruit_for_sale(struct bot *b, char *fruit) {
   int west_distance = 0;
   int east_distance = 0;

   struct location *east = b->location;
   struct location *west = b->location;

   do {
      if (fruit_at_location(east)) {
         return east_distance;
      }
      if (fruit_at_location(west)) {
         return west_distance;
      }
      east_distance++;
      west_distance--;
      east = east->east;
      west = west->west;

   } while(east != west && east->east != west);

   return 0;
}
