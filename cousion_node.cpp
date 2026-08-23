#include <iostream>
#include <queue>
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

// Checks whether a and b have the same parent
bool Parent(Node* root, int a, int b) {

    if (root == NULL)
        return false;

    // Check whether a and b are direct children of root
    if (root->left && root->right) {

        if (root->left->data == a &&
            root->right->data == b)
            return true;

        if (root->left->data == b &&
            root->right->data == a)
            return true;
    }

    // Search in left and right subtree
    return Parent(root->left, a, b) ||
           Parent(root->right, a, b);
}

// Checks whether a and b are cousins
bool isCousin(Node* root, int a, int b) {

    if (root == NULL)
        return false;

    queue<Node*> q;
    q.push(root);

    int l1 = -1;
    int l2 = -1;

    int level = 0;

    while (!q.empty()) {

        int n = q.size();

        while (n--) {

            Node* temp = q.front();
            q.pop();

            // Find level of a
            if (temp->data == a)
                l1 = level;

            // Find level of b
            if (temp->data == b)
                l2 = level;

            // Push left child
            if (temp->left)
                q.push(temp->left);

            // Push right child
            if (temp->right)
                q.push(temp->right);
        }

        // Both nodes have been found
        if (l1 != -1 && l2 != -1)
            break;

        level++;
    }

    // If either node was not found
    if (l1 == -1 || l2 == -1)
        return false;

    // Cousins must be at the same level
    if (l1 != l2)
        return false;

    // They must have different parents
    return !Parent(root, a, b);
}

int main() {

    /*
             1
            / \
           2   3
          /     \
         4       5
    */

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->right->right = new Node(5);

    int a = 4;
    int b = 5;

    if (isCousin(root, a, b))
        cout << "Cousins" << endl;
    else
        cout << "Not Cousins" << endl;

    return 0;
}