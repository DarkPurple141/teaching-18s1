#include <stdio.h>
#include <string.h>
#define MAX_NAME_LENGTH 50
#define MAX_COURSE_NAME_LENGTH 30

struct full_name {
   char f_name[MAX_NAME_LENGTH];
   char l_name[MAX_NAME_LENGTH];
};

struct date {
   int month;
   int day;
   int year;
};

struct course {
   int code;
   char name[MAX_COURSE_NAME_LENGTH];
};

struct student {
   int zid;
   struct full_name name;
   struct date date_of_birth;
   struct course course;
};

void create_student(int zid,
   struct full_name name,
   struct date date_of_birth,
   struct course course, struct student *new) {

   new->zid = zid;
   new->date_of_birth = date_of_birth;
   new->course = course;
   new->name = name;
}


struct student create_student_other(int zid,
   struct full_name name,
   struct date date_of_birth,
   struct course course) {

   struct student new;

   new.zid = zid;
   new.date_of_birth = date_of_birth;
   new.course = course;
   new.name = name;

   return new;
}

struct full_name create_name(char* first, char* second) {
   struct full_name new;
   strcpy(new.f_name, first);
   strcpy(new.l_name, second);

   return new;
}

struct course create_course(char* name, int code) {
   struct course new;
   strcpy(new.name, name);
   new.code = code;

   return new;
}

struct date create_date(int day, int month, int year) {
   struct date new;
   new.day   = day;
   new.month = month;
   new.year  = year;

   return new;
}

int main(int argc, char const **argv) {

   struct student alex;
   //create_student(3420752, name, birthday, course, &alex);

   alex = create_student_other(3420752,
      create_name("Alex", "Hinds"),
      create_date(1, 1, 1970),
      create_course("Computer Science", 3978));

   return 0;
}
