#include <bits/stdc++.h>
using namespace std;

// Structure of a binary tree node
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Function to find size of binary tree
int size(TreeNode* root) {

    // Base case
    if (root == NULL)
        return 0;

    // Count current node + left subtree + right subtree
    return 1 + size(root->left) + size(root->right);
}

int main() {

    // Creating the binary tree
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    /*
            1
           / \
          2   3
         / \
        4   5
    */

    cout << "Size of binary tree: " << size(root) << endl;

    return 0;
}