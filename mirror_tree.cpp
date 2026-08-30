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

void mirror(Node* root) {

    // Empty tree
    if (root == NULL)
        return;

    // Swap left and right child
    swap(root->left, root->right);

    // Mirror left subtree
    mirror(root->left);

    // Mirror right subtree
    mirror(root->right);
}

void inorder(Node* root) {

    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    /*
            Original tree

                1
               / \
              2   3
             / \
            4   5
    */

    cout << "Original tree (Inorder): ";
    inorder(root);

    mirror(root);

    cout << "\nMirror tree (Inorder): ";
    inorder(root);

    return 0;
}