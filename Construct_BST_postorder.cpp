
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

Node* BST(vector<int>& post, int& idx, int lower, int upper) {
    if (idx < 0 || post[idx] <= lower || post[idx] >= upper) {
        return NULL;
    }

    Node* root = new Node(post[idx--]);

    root->right = BST(post, idx, root->data, upper);
    root->left = BST(post, idx, lower, root->data);

    return root;
}

// Inorder traversal
void inorder(Node* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    vector<int> post = {1, 7, 5, 50, 40, 10};

    int idx = post.size() - 1;

    Node* root = BST(post, idx, INT_MIN, INT_MAX);

    cout << "Inorder Traversal: ";
    inorder(root);

    return 0;
}
