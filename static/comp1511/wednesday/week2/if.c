
#include <stdio.h>
#include <stdlib.h>

#define MONDAY 0
#define TUESDAY 1
#define WEDNESDAY 2
#define THURSDAY 3
#define FRIDAY 4
#define SATURDAY 5
#define SUNDAY 6

int main(void) {

   int day;

   printf("Please enter a number [0-6] for the day: ");
   scanf("%d", &day);

   if (day >= MONDAY && day <= FRIDAY) {

      /* these are for our weekdays */
      printf("Still part of the working week :(\n");

      if (day == MONDAY) {
         printf("It's Monday! :(\n");
      } else if (day == TUESDAY) {
         printf("It's Tuesday! Cool.\n");
      } else if (day == WEDNESDAY) {
         printf("It's Wednesday hump day!\n");
      } else if (day == THURSDAY) {
         printf("Thursday shcmuzday\n");
      } else if (day == FRIDAY) {
         printf("FRI-YAY, am I right?\n");
      } else {
         printf("Something went badly wrong oops!\n");
      }

   } else if (day >= SATURDAY && day <= SUNDAY) {

      printf("It's a weekend! Have fun\n");
   } else {
      printf("Doesn't seem like you entered a number from [0-6]?\n");
   }

   return 0;
}
