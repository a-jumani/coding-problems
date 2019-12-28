struct node {  
    int data;
    node* next;
    node* prev;
};

// convert sorted doubly-linked list to balance BST in-place,
// i.e. prev points to left subtree and next to right subtree
//
// args:
//   head_ref ptr to ptr to head of list
//   n size of list
// preconditions:
//   head_ref != nullptr
// returns root node of the BST
node *dll_to_bst(node **head_ref, int n) {
    // code
}
