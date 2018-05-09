
#define str_eq(x, y) (strcmp(x,y) == 0)

typedef struct node {
   int data;
   node *next;
} node;

node* createNode (int data) {
   node * new = malloc(sizeof(struct node));
   if (new == NULL) {
      fprintf(stderr, "Out of memory\n");
      exit(1);
   }

   new->data = data;
   new->next = NULL;

   return new;
}

void deleteNode(node *del) {
   if (del == NULL) {
      return;
   }
   free(del);
}

void append(node *head, node *new) {
   while (head && head->next) {
      head = head->next;
   }

   if (head) {
      head->next = new;
   }
}

void append(node *curr, node *new) {
   if (curr && curr->next) {
      append(curr->next, new);
   } else {
      if (curr) {
         curr->next = new;
      }
   }
}

int length(node *head) {
   if (head != NULL) {
      return 1 + length(head->next);
   }
   return 0;
}

int length(node *head) {
   int count = 0;
   while (head != NULL) {
      count++;
      head = head->next;
   }
   return count;
}
