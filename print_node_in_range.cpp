#include <iostream>
#include <vector>
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
    int n1, n2;

    void find(Node* root, vector<int>& ans) {
        if (root == NULL) {
            return;
        }

        if (root->data > n1 && root->data > n2) {
            find(root->left, ans);
        }
        else if (root->data < n1 && root->data < n2) {
            find(root->right, ans);
        }
        else {
            find(root->left, ans);
            ans.push_back(root->data);
            find(root->right, ans);
        }
    }

    vector<int> nodesInRange(Node* root, int low, int high) {
        vector<int> ans;

        n1 = low;
        n2 = high;

        find(root, ans);

        return ans;
    }
};

int main() {
    Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 18);

    int low = 7;
    int high = 15;

    Solution obj;

    vector<int> ans = obj.nodesInRange(root, low, high);

    cout << "Nodes in range: ";

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}