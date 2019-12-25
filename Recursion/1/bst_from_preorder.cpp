#include <vector>

using namespace std;

struct tree_node {
    int val;
    tree_node *left;
    tree_node *right;
    tree_node(int x) : val(x), left(nullptr), right(nullptr) {}
};

tree_node *bst_from_preorder(const vector<int> &preorder) {
    // code
}
