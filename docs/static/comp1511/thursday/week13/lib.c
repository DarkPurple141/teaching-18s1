#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void run_tests(void) {

   printf("Beginning Tests\n");
   Node head = create_node(0);
   for (int i = 1; i < 5; i++) {
      assert(length(head) == i);
      head = list_append(head, create_node(i));
      assert(contains(head, i));
   }
   printf("\t-> basic tests passed\n");

   free_list(head);

   printf("All tests done.\n");

}

struct node *create_list(int values[], int size) {
    int i = 0;

    struct node *head = NULL;   // head of the linked list
    struct node *tmp = NULL;    // temporary item we're working with
    struct node *curr = NULL;   // current node we're looking at in the linked list

    while (i < size) {
        tmp = create_node(values[i]);

        // link this node onto our list
        if (head == NULL) {
            // this is the first node in the list
            head = tmp;
            curr = head;
        } else {
            curr->next = tmp;

            curr = tmp;
        }
        i++;
    }

    return head;
}

void free_list(Node list) {
   if (list) {
      free_list(list->next);
      free(list);
   }
}

int contains(Node list, int data) {
   if (list) {
      return (list->data == data) || contains(list->next, data);
   }
   return 0;
}

Node delete_list_contains(Node curr, int data) {
   if (curr) {
      if (curr->data == data) {
         Node temp = curr->next;
         free(curr);
         curr = temp;
      } else {
         curr->next = delete_list_contains(curr->next, data);
      }
   }
   return curr;
}

int length(Node list) {
   if (list) {
      return 1 + length(list->next);
   }
   return 0;
}

Node create_node(int data) {
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
/*
Node create_list(int len, int multiple) {
   Node head = create_node(0);
   for (int i = 1; i < len; i++) {
      head = list_append(head, create_node(i * multiple));
   }
   return head;
}
*/

Node merge_sorted(Node list1, Node list2) {
    if (list1 == NULL) {
        return list2;
    } else if (list2 == NULL) {
        return list1;
    } else if (list1->data < list2->data) {
        list1->next = merge_sorted(list1->next, list2);
        return list1;
    } else {
        list2->next = merge_sorted(list1, list2->next);
        return list2;
    }
}

void print_list(Node list) {
   if (list) {
      printf("[%d]->", list->data);
      print_list(list->next);

   } else {
      printf("[X]\n");
   }
}
