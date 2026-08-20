#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

int countNonLeaf(Node* root) {

    // Empty tree
    if (root == NULL)
        return 0;

    // Leaf node
    if (root->left == NULL && root->right == NULL)
        return 0;

    // Current node is non-leaf
    return 1 + countNonLeaf(root->left)
             + countNonLeaf(root->right);
}

int main() {

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    /*
            1
           / \
          2   3
         / \
        4   5
    */

    cout << "Number of non-leaf nodes: "
         << countNonLeaf(root) << endl;

    return 0;
}