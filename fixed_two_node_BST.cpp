
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
public:
    Node* correctBST(Node* root) {
        Node* curr = NULL;
        Node* first = NULL;
        Node* second = NULL;
        Node* last = NULL;
        Node* present = NULL;

        // Save the original root
        Node* originalRoot = root;

        while (root != NULL) {

            // Left subtree does not exist
            if (root->left == NULL) {
                last = present;
                present = root;

                // Check for an inorder violation
                if (last != NULL && last->data > present->data) {
                    if (first == NULL) {
                        first = last;
                    }
                    second = present;
                }

                root = root->right;
            }
            else {
                // Find the rightmost node in the left subtree
                curr = root->left;

                while (curr->right != NULL &&
                       curr->right != root) {
                    curr = curr->right;
                }

                // Create a temporary link
                if (curr->right == NULL) {
                    curr->right = root;
                    root = root->left;
                }
                else {
                    // Remove the temporary link
                    curr->right = NULL;

                    last = present;
                    present = root;

                    // Check for an inorder violation
                    if (last != NULL && last->data > present->data) {
                        if (first == NULL) {
                            first = last;
                        }
                        second = present;
                    }

                    root = root->right;
                }
            }
        }

        // Swap the misplaced node values
        if (first != NULL && second != NULL) {
            int num = first->data;
            first->data = second->data;
            second->data = num;
        }

        return originalRoot;
    }
};

// Print the tree using inorder traversal
void inorder(Node* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    /*
             10
            /  \
           5    8
          /      \
         2        20

       Nodes 8 and 20 are swapped.
    */

    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(8);
    root->left->left = new Node(2);
    root->right->right = new Node(20);

    Solution obj;

    cout << "Before fixing: ";
    inorder(root);
    cout << endl;

    root = obj.correctBST(root);

    cout << "After fixing: ";
    inorder(root);
    cout << endl;

    return 0;
}
