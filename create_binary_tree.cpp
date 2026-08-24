#include <iostream>
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

Node* binaryTree() {

    int x;
    cin >> x;

    if (x == -1) {
        return NULL;
    }

    Node* temp = new Node(x);

    // Enter the left child
    cout<<"Enter the left child of "<<x<<": ";
    temp->left = binaryTree();

    // Enter the right child
    cout<<"Enter the right child of "<<x<<" : ";
    temp->right = binaryTree();

    return temp;
}

int main() {

    cout << "Enter the root node: ";

    Node* root = binaryTree();

    return 0;
}