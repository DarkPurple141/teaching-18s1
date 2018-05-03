
#include <stdio.h>
#include <string.h>
#define MAX_MONTH_NAME 30

struct month {
   unsigned int days;
   char name[MAX_MONTH_NAME];
   unsigned int position;
};

struct month create_month(int days, char name[], int position) {
   struct month new;

   new.days = days;
   strcpy(new.name, name);
   new.position = position;

   return new;
}

void edit_month(struct month *m, int days, char name[], int position) {
   printf("Value month pointer %p\n", m);
   m->days = days;
   strcpy(m->name, name);
   m->position = position;
}

void print_month(struct month m) {
   printf("MONTH: %s\n",m.name);
   printf("DAYS: %d\n",m.days);
   printf("POSITION: %d\n",m.position);
}

int main(void) {

   struct month january = {
      .days = 31,
      .name = "January",
      .position = 1
   };

   struct month feb = create_month(28, "February", 2);

   printf("Address month %p\n", &january);
   print_month(january);

   printf("Address month %p\n", &feb);
   print_month(feb);

   edit_month(&feb, 2, "Jeffday", 9);

   print_month(feb);

   return 0;
}
