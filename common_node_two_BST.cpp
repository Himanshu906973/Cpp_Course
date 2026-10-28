#include <iostream>
#include <vector>
#include <stack>
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
//iteratuive approach
class Solution {
public:
    void inorder(Node* root, vector<int>& arr) {
        if (root == NULL) {
            return;
        }

        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right, arr);
    }

    vector<int> findCommon(Node* r1, Node* r2) {
        vector<int> arr1, arr2, ans;

        inorder(r1, arr1);
        inorder(r2, arr2);

        int i = 0, j = 0;

        while (i < arr1.size() && j < arr2.size()) {
            if (arr1[i] == arr2[j]) {
                ans.push_back(arr1[i]);
                i++;
                j++;
            }
            else if (arr1[i] < arr2[j]) {
                i++;
            }
            else {
                j++;
            }
        }

        return ans;
    }
};

//optimal solutuion
class Solution {
public:
    vector<int> findCommon(Node* r1, Node* r2) {
        vector<int> ans;
        stack<Node*> s1, s2;

        // Push all left nodes of first BST
        while (r1 != NULL) {
            s1.push(r1);
            r1 = r1->left;
        }

        // Push all left nodes of second BST
        while (r2 != NULL) {
            s2.push(r2);
            r2 = r2->left;
        }

        while (!s1.empty() && !s2.empty()) {

            // Both elements are equal
            if (s1.top()->data == s2.top()->data) {
                ans.push_back(s1.top()->data);

                r1 = s1.top()->right;
                s1.pop();

                r2 = s2.top()->right;
                s2.pop();
            }

            // First BST element is greater
            else if (s1.top()->data > s2.top()->data) {
                r2 = s2.top()->right;
                s2.pop();
            }

            // Second BST element is greater
            else {
                r1 = s1.top()->right;
                s1.pop();
            }

            // Push left nodes of first BST
            while (r1 != NULL) {
                s1.push(r1);
                r1 = r1->left;
            }

            // Push left nodes of second BST
            while (r2 != NULL) {
                s2.push(r2);
                r2 = r2->left;
            }
        }

        return ans;
    }
};

int main() {
    Node* root1 = NULL;
    Node* root2 = NULL;

    // First BST
    root1 = insert(root1, 5);
    root1 = insert(root1, 1);
    root1 = insert(root1, 10);
    root1 = insert(root1, 0);
    root1 = insert(root1, 4);

    // Second BST
    root2 = insert(root2, 10);
    root2 = insert(root2, 4);
    root2 = insert(root2, 15);
    root2 = insert(root2, 1);
    root2 = insert(root2, 20);

    Solution obj;

    vector<int> ans = obj.findCommon(root1, root2);

    cout << "Common nodes: ";

    for (int x : ans) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}