#include<iostream>
#include<queue>
#include<climits>
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

void largestAtEachLevel(Node* root) {

    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {

        int n = q.size();

        int largest = INT_MIN;

        // Process all nodes of current level
        for (int i = 0; i < n; i++) {

            Node* current = q.front();
            q.pop();

            largest = max(largest, current->data);

            if (current->left != NULL)
                q.push(current->left);

            if (current->right != NULL)
                q.push(current->right);
        }

        cout << largest << " ";
    }
}

int main() {

    Node* root = new Node(1);

    root->left = new Node(3);
    root->right = new Node(2);

    root->left->left = new Node(5);
    root->left->right = new Node(4);

    root->right->right = new Node(9);

    /*
            1
           / \
          3   2
         / \   \
        5   4   9
    */

    cout << "Largest value at each level: ";

    largestAtEachLevel(root);

    return 0;
}