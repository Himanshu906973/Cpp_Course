
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Box {
public:
    bool BST;
    int size;
    int mini, maxi;

    Box() {
        BST = 1;
        size = 0;
        mini = INT_MAX;
        maxi = INT_MIN;
    }
};

class Solution {
public:

    Box* find(Node* root, int &totalSize) {

        if(root == NULL) {
            return new Box();
        }

        Box* lefthead = find(root->left, totalSize);
        Box* righthead = find(root->right, totalSize);

        if(lefthead->BST && righthead->BST &&
           lefthead->maxi < root->data &&
           righthead->mini > root->data) {

            Box* head = new Box();

            head->size = 1 + lefthead->size + righthead->size;

            head->mini = min(root->data, lefthead->mini);
            head->maxi = max(root->data, righthead->maxi);

            totalSize = max(totalSize, head->size);

            return head;
        }
        else {
            Box* head = new Box();
            head->BST = 0;
            return head;
        }
    }

    int largestBst(Node* root) {
        int totalSize = 0;
        find(root, totalSize);
        return totalSize;
    }
};

int main() {

    /*
             5
            / \
           2   4
          / \
         1   3
    */

    Node* root = new Node(5);

    root->left = new Node(2);
    root->right = new Node(4);

    root->left->left = new Node(1);
    root->left->right = new Node(3);

    Solution obj;

    cout << "Largest BST Size: "
         << obj.largestBst(root);

    return 0;
}
