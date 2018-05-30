typedef struct node *Node;

struct node {
    Node    next;
    int     data;
};

Node copy(Node head);
int identical(Node head1, Node head2);
int ordered(Node head);
Node set_intersection(Node set1, Node set2);
Node set_union(Node set1, Node set2);
//Node create_list(int len, int multiple);
int  contains(Node list, int data);
int  length(Node list);
Node merge_sorted(Node list1, Node list2);
Node create_node(int data);
Node list_append(Node list1, Node list2);
void print_list(Node list);
void free_list(Node list);
Node delete_list_contains(Node list, int data);
