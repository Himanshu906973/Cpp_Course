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

bool isIdentical(Node* root1, Node* root2) {

    // Both trees are empty
    if (root1 == NULL && root2 == NULL)
        return true;

    // One tree is empty and the other is not
    if (root1 == NULL || root2 == NULL)
        return false;

    // Values are different
    if (root1->data != root2->data)
        return false;

    // Check left and right subtrees
    return isIdentical(root1->left, root2->left) &&
           isIdentical(root1->right, root2->right);
}

int main() {

    // First tree
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);

    // Second tree
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);

    if (isIdentical(root1, root2))
        cout << "Trees are identical";
    else
        cout << "Trees are not identical";

    return 0;
}