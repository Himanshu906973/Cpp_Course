
#include <iostream>
#include <vector>
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

Node* BST(vector<int>& pre, int& idx, int lower, int upper) {
    if (idx >= pre.size() || pre[idx] <= lower || pre[idx] >= upper) {
        return NULL;
    }

    Node* root = new Node(pre[idx++]);

    root->left = BST(pre, idx, lower, root->data);
    root->right = BST(pre, idx, root->data, upper);

    return root;
}

void inorder(Node* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    vector<int> pre = {10, 5, 1, 7, 40, 50};

    int idx = 0;

    Node* root = BST(pre, idx, INT_MIN, INT_MAX);

    cout << "Inorder Traversal: ";
    inorder(root);

    return 0;
}
