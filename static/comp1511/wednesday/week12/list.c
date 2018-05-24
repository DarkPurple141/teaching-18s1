
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void run_tests(void);


int main(int argc, char *argv[]) {
   run_tests();

   /*
   Node list = create_list(5, 1);
   Node list2 = create_list(4, 2);
   print_list(list);
   print_list(list2);

   list = merge_sorted(list, list2);
   assert(length(list) == 9);
   print_list(list);
   */
   Node list = strings_to_list_recursive(argc - 1, argv + 1);
   print_list(list);
   list = delete_list_contains(list, 5);
   print_list(list);

   return 0;
}

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

// { "2", "10", "8", "12" }
Node strings_to_list(int len, char *strings[]) {

	Node head = NULL;
	for (int i = 0; i < len; ++i)
	{
		Node new = new_node(atoi(strings[i]));
		head = list_append(head, new);
	}

	return head;
}


Node strings_to_list_recursive(int len, char *strings[]) {
	Node new = NULL;
	if (len > 0) {
		new = new_node(atoi(*strings));
		new->next = strings_to_list_recursive(len-1, strings + 1);
	}

   return new;
}
