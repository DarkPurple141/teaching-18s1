#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void testCreateList(void);
void test_length(void);
void test_copy(void);
void test_identical(void);
void test_ordered(void);
void test_set_intersection(void);
void test_set_union(void);

int main(int argc, char const *argv[]) {
   testCreateList();
   test_length();

   test_copy();
   test_identical();
   test_ordered();
   test_set_intersection();
   test_set_union();

   printf("========== EVERYTHING IS WORKING PERFECTLY!! ==========\n");
   return EXIT_SUCCESS;
}

// ======= W13 Tut Problems ========
// returns a copy of the linked list
Node copy(Node head) {

   Node copied = NULL;
   Node curr;

   while (head != NULL) {
      curr = create_node(head->data);
      copied = list_append(copied, curr);
      head = head->next;
   }

   return copied;
}

// returns 1 if the two lists are identical, otherwise returns 0
int identical(Node head1, Node head2) {

   while (head1 != NULL && head2 != NULL) {
      if(head1->data == head2->data) {
         head1 = head1->next;
         head2 = head2->next;
      } else {
         return 0;
      }
   }
   return (head1 == NULL && head2 == NULL);
}
/*
int identical(Node head1, Node head2) {
   if (!head1 && !head2) {
      return 1;
   } else if (head1 && head2) {
      if (head1->data == head2->data) {
         return identical(head1->next, head2->next);
      }
   }
   return 0;
}
*/

// returns 1 if list is in strictly increasing order,
// otherwise returns 0
int ordered(Node head) {
   Node prev = NULL;
   Node curr = head;
   while (curr) {
      if (prev && prev->data >= curr->data) {
         return 0;
      }
      prev = curr;
      curr = curr->next;
   }
   return 1;
}

// given two lists in strictly increasing order,
// return a new linked list (in strictly increasing order) of the elements in both set1 and set2
Node set_intersection(Node set1, Node set2) {

   Node head = NULL;

   while (set1 && set2) {
      if (set1->data < set2->data) {
         set1 = set1->next;
      } else if (set2->data < set1->data) {
         set2 = set2->next;
      } else {
         head = list_append(head, create_node(set1->data));
         set1 = set1->next;
         set2 = set2->next;
      }
   }

   return head;
}

// given two linked lists in strictly increasing order,
// return a new linked list (in strictly increasing order) of the elements in either set1 or set2
// no duplicates (only include them once)
Node set_union(Node set1, Node set2) {
    return NULL;    // replace this
}

void test_set_union(void) {
    printf("==== Testing Set_Union ===\n");
    int vals1[] = {1, 2, 3, 4, 5};
    int vals2[] = {6, 7, 8, 9, 10};
    int vals3[] = {1, 3, 5};

    struct node *test1 = create_list(vals1, 5);
    struct node *test2 = create_list(vals2, 5);
    struct node *test3 = create_list(vals3, 3);
    struct node *test4 = create_list(vals1, 1); // just 1
    struct node *test5 = create_list(vals2, 1); // just 6

    struct node *tmp;

    printf("-- Test 1: Empty lists --\n");
    tmp = set_union(NULL, NULL);
    assert(tmp == NULL);

    tmp = set_union(test1, NULL);
    assert(length(tmp) == 5);
    assert(tmp->data == 1);
    assert(tmp->next->data == 2);
    assert(tmp->next->next->data == 3);
    assert(tmp->next->next->next->data == 4);
    assert(tmp->next->next->next->next->data == 5);
    free_list(tmp);

    // check other argument NULL also working
    tmp = set_union(NULL, test1);
    assert(length(tmp) == 5);
    assert(tmp->data == 1);
    assert(tmp->next->data == 2);
    assert(tmp->next->next->data == 3);
    assert(tmp->next->next->next->data == 4);
    assert(tmp->next->next->next->next->data == 5);
    free_list(tmp);

    printf("-- Test 2: Normal behavior --\n");
    tmp = set_union(test1, test2);
    assert(length(tmp) == 10);
    assert(tmp->data == 1);
    assert(tmp->next->data == 2);
    assert(tmp->next->next->data == 3);
    assert(tmp->next->next->next->data == 4);
    assert(tmp->next->next->next->next->data == 5);
    assert(tmp->next->next->next->next->next->data == 6);
    assert(tmp->next->next->next->next->next->next->data == 7);
    assert(tmp->next->next->next->next->next->next->next->data == 8);
    assert(tmp->next->next->next->next->next->next->next->next->data == 9);
    assert(tmp->next->next->next->next->next->next->next->next->next->data == 10);
    free_list(tmp);

    printf("-- Test 3: Single element lists --\n");
    tmp = set_union(test4, test5);
    assert(length(tmp) == 2);
    assert(tmp->data == 1);
    assert(tmp->next->data == 6);

    tmp = set_union(test4, test4);
    assert(length(tmp) == 1);
    assert(tmp->data == 1);
    free_list(tmp);

    printf("-- Test 4: Subset of list --\n");
    tmp = set_union(test1, test3);
    assert(length(tmp) == 5);
    assert(tmp->data == 1);
    assert(tmp->next->data == 2);
    assert(tmp->next->next->data == 3);
    assert(tmp->next->next->next->data == 4);
    assert(tmp->next->next->next->next->data == 5);
    free_list(tmp);

    // free everything
    free_list(test1);
    free_list(test2);
    free_list(test3);
    free_list(test4);
    free_list(test5);

    printf("All tests passed! You are awesome!\n");
}

void test_set_intersection(void) {
    printf("==== Testing Set_Intersection ===\n");
    int vals1[] = {1, 2, 3, 4, 5};
    int vals2[] = {3, 4, 5};
    int vals3[] = {6, 7, 8, 9, 10};

    struct node *test1 = create_list(vals1, 1);
    struct node *test2 = create_list(vals2, 1);
    struct node *test3 = create_list(vals1, 5);
    struct node *test4 = create_list(vals2, 3);
    struct node *test5 = create_list(vals3, 5);

    struct node *tmp;

    printf("-- Test 1: Empty lists --\n");
    tmp = set_intersection(NULL, NULL);
    assert(tmp == NULL);

    tmp = set_intersection(NULL, test1);
    assert(tmp == NULL);

    tmp = set_intersection(test2, NULL);
    assert(tmp == NULL);

    printf("-- Test 2: Single element lists --\n");
    tmp = set_intersection(test1, test1);
    assert(length(tmp) == 1);
    assert(tmp->data == 1);
    free_list(tmp);

    tmp = set_intersection(test1, test2);
    assert(length(tmp) == 0);
    assert(tmp == NULL);

    printf("-- Test 3: Disjoint --\n");
    tmp = set_intersection(test3, test5);
    assert(length(tmp) == 0);
    assert(tmp == NULL);

    printf("-- Test 4: Normal behavior --\n");
    tmp = set_intersection(test3, test4);
    assert(length(tmp) == 3);
    assert(tmp->data == 3);
    assert(tmp->next->data == 4);
    assert(tmp->next->next->data == 5);
    free_list(tmp);

    // free everything
    free_list(test1);
    free_list(test2);
    free_list(test3);
    free_list(test4);
    free_list(test5);

    printf("All tests passed! You are awesome!\n");
}

void test_ordered(void) {
    printf("==== Testing Ordered ===\n");
    int vals1[] = {1, 2, 3, 4, 5};
    int vals2[] = {1, 2, 3, 3, 5};
    int vals3[] = {1, 2, 1, 2, 1};
    int vals4[] = {5, 4, 3, 2, 1};
    int vals5[] = {-1};

    struct node *test1 = create_list(vals1, 5);
    struct node *test2 = create_list(vals2, 5);
    struct node *test3 = create_list(vals3, 5);
    struct node *test4 = create_list(vals4, 5);
    struct node *test5 = create_list(vals5, 1);

    printf("-- Test 1: Empty list --\n");
    assert(ordered(NULL) == 1);

    printf("-- Test 2: Strictly increasing list --\n");
    assert(ordered(test1) == 1);

    printf("-- Test 3: Non-decreasing list --\n");
    assert(ordered(test2) == 0);

    printf("-- Test 4: Repeats --\n");
    assert(ordered(test3) == 0);

    printf("-- Test 5: Reversed --\n");
    assert(ordered(test4) == 0);

    printf("--- Test 6: Single element --\n");
    assert(ordered(test5) == 1);

    // free everything
    free_list(test1);
    free_list(test2);
    free_list(test3);
    free_list(test4);
    free_list(test5);

    printf("All tests passed! You are awesome!\n");
}

void test_identical(void) {
    printf("==== Testing Identical ===\n");

    int vals1[] = {1, 2, 3, 4, 5};
    int vals2[] = {1, 2, 3, 4, 5};
    int vals3[] = {1, 2, 3};
    int vals4[] = {5, 4, 3, 2, 1};

    struct node *test1 = create_list(vals1, 5);
    struct node *test2 = create_list(vals2, 5);
    struct node *test3 = create_list(vals3, 3);
    struct node *test4 = create_list(vals4, 5);

    printf("-- Test 1: Empty list --\n");
    assert(identical(NULL, NULL) == 1); // two empty lists are identical
    assert(identical(test1, NULL) == 0);    // check NULL works in either argument
    assert(identical(NULL, test1) == 0);


    printf("-- Test 2: Identical lists --\n");
    assert(identical(test1, test2) == 1);
    assert(identical(test2, test1) == 1);
    assert(identical(test3, test3) == 1);   // list is identical to itself

    printf("-- Test 3: Subset of list --\n");
    assert(identical(test3, test2) == 0);   // subset is not identical
    assert(identical(test1, test3) == 0);

    printf("-- Test 1: Same values diff order --\n");
    assert(identical(test1, test4) == 0);
    assert(identical(test4, test1) == 0);

    free_list(test1);
    free_list(test2);
    free_list(test3);
    free_list(test4);

    printf("All tests passed! You are awesome!\n");
}

void test_copy(void) {
    printf("==== Testing Copy ===\n");
    int vals[] = {1, 2, 3, 4, 5};
    struct node *test1 = create_list(vals, 1);
    struct node *test2 = create_list(vals, 5);
    struct node *copyT;

    // empty list
    printf("-- Test 1: Empty list --\n");
    copyT = copy(NULL);
    assert(copyT == NULL);

    // single element list
    printf("-- Test 2: Single element list --\n");
    copyT = copy(test1);
    assert(length(copyT) == 1);
    assert(copyT->data == test1->data);
    assert(&copyT != &test1);
    free_list(copyT);
    free_list(test1);

    // 5 element list
    printf("-- Test 3: 5-element list --\n");
    copyT = copy(test2);
    assert(length(copyT) == 5);
    // test data values are the same
    assert(copyT->data == test2->data);
    assert(copyT->next->data == test2->next->data);
    assert(copyT->next->next->data == test2->next->next->data);
    assert(copyT->next->next->next->data == test2->next->next->next->data);
    assert(copyT->next->next->next->next->data == test2->next->next->next->next->data);
    assert(copyT->next->next->next->next->next == NULL);
    assert(test2->next->next->next->next->next == NULL);
    // test addresses are different
    assert(&copyT != &test2);
    assert(&(copyT->next) != &(test2->next));
    assert(&(copyT->next->next) != &(test2->next->next));
    assert(&(copyT->next->next->next) != &(test2->next->next->next));
    assert(&(copyT->next->next->next->next) != &(test2->next->next->next->next));

    free_list(copyT);
    free_list(test2);


    printf("All tests passed! You are awesome!\n");
}

void testCreateList(void) {
    printf("==== Testing Create List ===\n");

    printf("-- Test 1--\n");
    int vals[] = {1, 2, 3, 4, 5};
    struct node *test = create_list(vals, 5);
    print_list(test);

    printf("-- Test 2--\n");
    struct node *test2 = create_list(vals, 0);
    print_list(test2);

    //free_list(test);
    test = NULL;
    //free_list(test2);
    test2 = NULL;
}

void test_length(void) {
    printf("==== Testing length ===\n");
    int vals[] = {1, 2, 3, 4, 5};
    struct node *test1 = create_list(vals, 0);
    struct node *test2 = create_list(vals, 5);
    struct node *test3 = create_list(vals, 1);

    assert(length(test1) == 0);
    assert(length(test2) == 5);
    assert(length(test3) == 1);

    free_list(test1);
    free_list(test2);
    free_list(test3);

    printf("All tests passed! You are awesome!\n");
}
