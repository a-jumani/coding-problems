#include <climits>
#include <iostream>
#include <vector>

using namespace std;

struct tree_node {
    int val;
    tree_node *left;
    tree_node *right;
    tree_node(int x) : val(x), left(nullptr), right(nullptr) {}
};

// recover binary search tree r rooted at preorder[i]
// 
// preconditions:
//   stop >= node.val if node in r
tree_node *bst_from_preorder_rec(const vector<int> &preorder, int &i, int stop = INT_MAX) {
    
    // base case
    if ( i == preorder.size() || preorder[i] > stop )
        return nullptr;
    
    // first value is the root's in pre-order traversal
    tree_node *root = new tree_node(preorder[i++]);

    // left subtree has values less than root->val
    root->left = bst_from_preorder_rec(preorder, i, root->val);

    // right subtree has values less than root's parent node
    root->right = bst_from_preorder_rec(preorder, i, stop);

}

// recover binary search tree from the given pre-order traversal
//
// preconditions:
//   preorder contains no duplicates
tree_node *bst_from_preorder(const vector<int> &preorder) {
    int i = 0;
    return bst_from_preorder_rec(preorder, i);
}
