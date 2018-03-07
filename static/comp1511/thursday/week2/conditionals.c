
#include <stdio.h>

#define MONDAY 0
#define TUESDAY 1
#define WEDNESDAY 2
#define THURSDAY 3
#define FRIDAY 4
#define SATURDAY 5
#define SUNDAY 6
#define TRUE 1
#define FALSE 0

int isWeekend(int day) {
   int isValid = FALSE;

   if (day == SATURDAY || day == SUNDAY) {
      isValid = TRUE;
   }

   return isValid;
}

int main(void) {

   int day;

   printf("Welcome to the what day is it program."
          " Where we tell you what day it is.\n\n");

   printf("Please enter a number [0-6]: ");

   scanf("%d", &day);

   if (day < MONDAY || day > SUNDAY) {
      printf("You are a silly billy. :(\n");
   } else {
      // assessing the legal days
      if (day == SATURDAY || day == SUNDAY) { // isWeekend(day)
         printf("It's a weekend, hooray!\n");
         if (day == SATURDAY) {
            printf("You've got the whole weekend to gooooo (cos it's Saturday).\n");
         } else {
            printf("Oh noes, it's Sunday, get ready for your jobbb.\n");
         }
      } else {
         // the day is a weekday
         if (day == MONDAY) {
            printf("It's Monday, cool.\n");
         } else if (day == TUESDAY) {
            printf("It's not Monday, it's Tuesday.\n");
         } else if (day == WEDNESDAY) {
            printf("Blah.\n");
         } else {
            printf("It's either Thursday or Friday, this program got lazy\n");
         }
      }

   }

   return 0;
}
