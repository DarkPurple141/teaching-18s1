#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define TRUE 1
#define FALSE 0

typedef struct _node node;

typedef struct _node {
   int data;
   node *next;
} node;

void print_list(node *head) {
   while (head) {
      printf("[%d]->", head->data);
      head = head->next;
   }
   printf("[X]\n");
}


node *new_node(int data) {
   node *new = malloc(sizeof(node));
   new->data = data;
   new->next = NULL;

   return new;
}

void delete_node(node *node) {
   node->next = NULL;
   free(node);
}
/*
int size(node *head) {
   node *temp = head;
   int size = 0;
   while (temp) {
      temp = temp->next;
      size++;
   }
   return size;
}
*/

int size(node *head) {
   if (head) {
      return 1 + size(head->next);
   } else {
      return 0;
   }
}

int contains(node *head, int data) {
   node *temp = head;

   while (temp) {
      if (temp->data == data) {
         return TRUE;
      }
      temp = temp->next;
   }
   return FALSE;
}

void append(node *head, node *curr) {

   node *temp = head;
   while (temp && temp->next) {
      temp = temp->next;
   }
   temp->next = curr;
}

void testBasic(void) {
   node *list = new_node(10);
   printf("Testing Basic functionality\n"
          "==================\n");
   for (int i = 0; i < 5; i++) {
      node *new = new_node(i);
      append(list, new);
      print_list(list);
      assert(size(list) == i + 2);
      assert(contains(list, i));
   }

   printf("Basic tests passed!\n");

}

int main(void) {

   testBasic();

   return 0;
}
