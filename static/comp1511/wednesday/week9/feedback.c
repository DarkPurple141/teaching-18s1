#define FALSE 0
#define TRUE 1
#define MAX_VALID_TIME 2359
#define MINS_IN_HOUR 60

int is_valid_town(int town) {
   if (town < 0 || town >= N_TOWNS) {
      return FALSE;
   }
   return TRUE;
}

int is_valid_time(int utc_time) {
   if (utc_time > MAX_VALID_TIME || utc_time < 0) {
      return FALSE;
   } else {
      // in valid range now check if over '59'
      if (utc_time % 100 >= MINS_IN_HOUR) {
         return FALSE;
      }
   }
   return TRUE;
}

int is_in_day_range(int day, int max) {
   return (day > 0 && day <= max);
}

int is_valid_date(int month, int day) {
   if (month > DECEMBER || month < JANUARY) {
      return FALSE;
   }

   if (month == FEBRUARY) {
      if (!is_in_day_range(day, 28)) {
         return FALSE;
      }
   } else if (month == APRIL || month == JUNE
      || month == SEPTEMBER || month == NOVEMBER) {
      // 30 day month
      if (!is_in_day_range(day, 30)) {
         return FALSE;
      }
   } else {
      // must be 31 day month
      if (!is_in_day_range(day, 31)) {
         return FALSE;
      }
   }
   return TRUE;
}

// Two common patterns
int is_valid_input(int utc_time, int month, int day, int town) {

   if (!is_valid_town(town)) {
      return FALSE;
   }

   if (!is_valid_time(utc_time)) {
      return FALSE;
   }

   if (!is_valid_date(month, day)) {
      return FALSE;
   }

   return TRUE;
}

// TODO ANother thing about functions

if you have this:

int NZDTandNZST(int utc_month, int utc_day, int utc_time) {

    if (utc_month == 3 && utc_day == 31 && utc_time >= 1400) {
        return TIMEZONE_NZST_OFFSET;
    } else if (utc_month == 9 && utc_day == 29 && utc_time <= 1359) {
        return TIMEZONE_NZST_OFFSET;
    } else if (utc_month == 9 && utc_day <= 28) {
        return TIMEZONE_NZST_OFFSET;
    } else if (4 <= utc_month && utc_month <= 8) {
        return TIMEZONE_NZST_OFFSET;
    } else {
        return TIMEZONE_NZDT_OFFSET;
    }
}


int read_input(int array[]) {
   int i = 0;
   int scanned = 1;
   while (scanned) {
      scanned = scanf("%d", &array[i]);
      i++;
   }
   return i;
}

int read_cards(int cards[], int array[], int numcards_in_round) {
   int i = 0;
   while (i < numcards_in_round) {
      cards[i] = array[i];
      i++;
   }
   return i;
}


// logical problems
