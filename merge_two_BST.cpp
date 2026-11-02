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
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    void inorder(Node* root, vector<int>& ans) {
        if (root == nullptr) {
            return;
        }

        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }

    vector<int> merge(Node* r1, Node* r2) {
        vector<int> ans1, ans2;

        inorder(r1, ans1);
        inorder(r2, ans2);

        vector<int> ans;
        int i = 0, j = 0;

        while (i < ans1.size() && j < ans2.size()) {
            if (ans1[i] <= ans2[j]) {
                ans.push_back(ans1[i]);
                i++;
            } else {
                ans.push_back(ans2[j]);
                j++;
            }
        }

        while (i < ans1.size()) {
            ans.push_back(ans1[i]);
            i++;
        }

        while (j < ans2.size()) {
            ans.push_back(ans2[j]);
            j++;
        }

        return ans;
    }
};

// Insert a value into a BST
Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }

    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }

    return root;
}

int main() {
    Node* r1 = nullptr;
    Node* r2 = nullptr;

    // First BST: 3, 1, 5
    r1 = insert(r1, 3);
    r1 = insert(r1, 1);
    r1 = insert(r1, 5);

    // Second BST: 4, 2, 6
    r2 = insert(r2, 4);
    r2 = insert(r2, 2);
    r2 = insert(r2, 6);

    Solution sol;

    vector<int> ans = sol.merge(r1, r2);

    cout << "Merged sorted array: ";

    for (int x : ans) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}