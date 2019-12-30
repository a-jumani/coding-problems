struct node {  
    int data;
    node* left;
    node* right;
};

// convert binary tree to double linked list in-place
// i.e. left points to previous node and right points
// to next node in the list
//
// args:
//   root ptr to root node of the binary tree
//   head_ref ptr to ptr to head of list
// preconditions:
//   head_ref != nullptr
void bintree_to_dll(node* root, node **head_ref) {
    // code
}
