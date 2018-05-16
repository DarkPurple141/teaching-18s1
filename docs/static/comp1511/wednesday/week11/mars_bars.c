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


int mars_bars_on_board(struct bot *b) {
   return fruit_on_board(b, "Mars Bars");
}

int fruit_on_board(struct bot *b, char *type) {
   int fruit = 0;
   if (strcmp(b->fruit, type) == 0) {
      fruit = b->fruit_kg;
   }
   return fruit;
}

int fruit_at_local(struct bot *b, char* type) {
   int fruit = 0;

   struct location *curr_location = b->location;

   if (strcmp(curr_location->fruit, type) == 0) {
      fruit = curr_location->quantity;
   }

   return fruit;
}

int fruit_at_shop(struct bot *b, char *shop_name) {
   int fruit = 0;
   struct location *east = b->location->east;
   struct location *west = b->location->west;

   while (east != west && east->west != west) {
      if (strcmp(east->name, shop_name) == 0) {
         fruit = east->quantity;
         break;
      }

      if (strcmp(west->name, shop_name) == 0) {
         fruit = west->quantity;
         break;
      }

      west = west->west;
      east = east->east;
   }
   return fruit;
}
