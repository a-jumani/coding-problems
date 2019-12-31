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

    // base case
    if ( root == nullptr )
        return;
    
    // convert right subtree and add to list
    bintree_to_dll(root->right, head_ref);

    // add root to list
    root->right = *head_ref;
    if ( *head_ref != nullptr )
        (*head_ref)->left = root;
    *head_ref = root;

    // convert left subtree
    bintree_to_dll(root->left, head_ref);
}
