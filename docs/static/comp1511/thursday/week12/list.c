
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void run_tests(void);

int main(int argc, char *argv[]) {
   run_tests();

	Node list1 	 = create_list(5, 5);
	Node list2   = create_list(4, 2);
	list1        = merge_sorted(list1, list2);

	print_list(list1);

	list2 = strings_to_list(argc - 1, argv + 1);
	print_list(list2);
   return 0;
}


Node merge_sorted(struct node *list1, struct node *list2) {
	Node curr = NULL;
	if (list1 == NULL) {
		return list2;
	} else if (list2 == NULL) {
		return list1;
	} else {
		// both are not NULL
		if (list1->data < list2->data) {
			list1->next = merge_sorted(list1->next, list2);
			curr = list1;
		} else {
			list2->next = merge_sorted(list1, list2->next);
			curr = list2;
		}
	}

	return curr;
}


Node strings_to_list(int len, char *strings[]) {
   Node head = NULL;
   int i = 0;

   while (i < len) {
   	head = list_append(head, new_node(atoi(strings[i])));
   	i++;
   }

   return head;
}

Node strings_to_list_recursive(int len, char *strings[]) {
   return NULL;
}
