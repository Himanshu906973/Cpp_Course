#include <iostream>
#include <climits>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Insert node into BST
Node* insert(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    }

    if (val < root->data) {
        root->left = insert(root->left, val);
    }
    else if (val > root->data) {
        root->right = insert(root->right, val);
    }

    return root;
}

class Solution {
public:

    bool Dead(Node* root, int lower, int upper) {
        if (root == NULL) {
            return 0;
        }

        if (root->left == NULL && root->right == NULL) {
            if (root->data - lower == 1 &&
                upper - root->data == 1) {
                return 1;
            }
            else {
                return 0;
            }
        }

        return Dead(root->left, lower, root->data) ||
               Dead(root->right, root->data, upper);
    }

    bool isDeadEnd(Node* root) {
        return Dead(root, 0, INT_MAX);
    }
};

int main() {
    Node* root = NULL;

    root = insert(root, 8);
    root = insert(root, 5);
    root = insert(root, 9);
    root = insert(root, 2);
    root = insert(root, 7);
    root = insert(root, 6);

    Solution obj;

    if (obj.isDeadEnd(root)) {
        cout << "BST contains Dead End";
    }
    else {
        cout << "BST does not contain Dead End";
    }

    return 0;
}