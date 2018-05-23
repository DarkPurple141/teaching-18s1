typedef struct node *Node;

struct node {
    Node    next;
    int     data;
};

Node create_list(int len, int multiple);
int  contains(Node list, int data);
int  length(Node list);
Node merge_sorted(Node list1, Node list2);
Node new_node(int data);
Node list_append(Node list1, Node list2);
Node strings_to_list(int len, char *strings[]);
Node strings_to_list_recursive(int len, char *strings[]);
void print_list(Node list);
void delete_list(Node list);