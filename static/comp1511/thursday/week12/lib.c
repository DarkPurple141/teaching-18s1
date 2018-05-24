#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void run_tests(void) {

   printf("Beginning Tests\n");
   Node head = new_node(0);
   for (int i = 1; i < 5; i++) {
      assert(length(head) == i);
      head = list_append(head, new_node(i));
      assert(contains(head, i));
   }
   printf("\t-> basic tests passed\n");

   delete_list(head);

   char *powers[] = {"2", "4", "8", "16"};
   head = strings_to_list(4, powers);
   assert(length(head) == 4);
   for (int i = 2; i <= 16; i*=2) {
      assert(contains(head, i));
   }

   delete_list(head);

   printf("\t-> strings_to_list tests passed\n");

   printf("All tests done.\n");

}

Node create_list(int len, int multiple) {
   Node head = new_node(0);
   for (int i = 1; i < len; i++) {
      head = list_append(head, new_node(i * multiple));
   }
   return head;
}

void delete_list(Node list) {
   if (list) {
      delete_list(list->next);
      free(list);
   }
}

int contains(Node list, int data) {
   if (list) {
      return (list->data == data) || contains(list->next, data);
   }
   return 0;
}

int length(Node list) {
   if (list) {
      return 1 + length(list->next);
   }
   return 0;
}

Node new_node(int data) {
   Node n = malloc(sizeof(struct node));
   if (!n) {
      fprintf(stderr, "Out of memory, exiting!\n");
      exit(1);
   }

   n->data = data;
   n->next = NULL;
   return n;
}

Node list_append(Node curr, Node new) {
   if (curr) {
      curr->next = list_append(curr->next, new);
   } else {
      return new;
   }
   return curr;
}

void print_list(Node list) {
   if (list) {
      printf("[%d]->", list->data);
      print_list(list->next);
   } else {
      printf("[X]\n");
   }
}
