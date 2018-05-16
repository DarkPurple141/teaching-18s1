
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define SIZE 10000000

typedef struct _node *Node;

typedef struct _node {
   Node next;
   Node prev;
   unsigned int data;
} node;

Node create_node(unsigned int data) {
   Node n = malloc(sizeof(struct _node));
   assert(n);
   n->data = data;
   n->next = NULL;
   n->prev = NULL;
   return n;
}

Node create_list(void) {
   Node curr = create_node(0);
   Node head = curr;
   for (unsigned int i = 1; i < SIZE; i++) {
      curr->next = create_node(i);
      curr->next->prev = curr;
      curr = curr->next;
   }
   head->prev = curr;
   curr->next = head;

   return head;
}

void test_double(Node list, unsigned int data) {
   Node prev = list;
   Node next = list;
   do {
      if (prev->data == data || next->data == data) {
         break;
      }
      prev = prev->prev;
      next = next->next;
   } while(prev != next && prev->next != next);
}

void test_single(Node list, unsigned int data) {
   Node next = list;
   do {
      if (next->data == data) {
         break;
      }
      next = next->next;
   } while(next != list);
}

int main(int argc, char* argv[]) {

   if (argc < 3) {
      fprintf(stderr, "Usage: prog -[mode] [seed]\n");
      return 1;
   }

   Node list = create_list();

   if (argv[1][1] == 'd') {
      printf("Double\n");
      test_double(list, atoi(argv[2]));
   } else {
      printf("Single\n");
      test_single(list, atoi(argv[2]));
   }

   return 0;
}
