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

    // base case - no list node to process
    if ( n == 0 )
        return nullptr;
    
    // get left subtree
    node *left = dll_to_bst(head_ref, n/2);
    root->prev = left;

    // consume current node as root
    node *root = *head_ref;
    *head_ref = root->next;

    // get right subtree
    root->next = dll_to_bst(head_ref, (n+1)/2 - 1);

    return root;
}
