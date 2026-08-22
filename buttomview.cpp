#include <bits/stdc++.h>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// Find minimum and maximum horizontal position
void find(Node* root, int pos, int& l, int& r) {

    if (root == NULL)
        return;

    l = min(l, pos);
    r = max(r, pos);

    find(root->left, pos - 1, l, r);
    find(root->right, pos + 1, l, r);
}

// Find Bottom View
vector<int> bottomView(Node* root) {

    vector<int> ans;

    if (root == NULL)
        return ans;

    int l = 0;
    int r = 0;

    // Find the range of horizontal positions
    find(root, 0, l, r);

    // Create result array
    vector<int> result(r - l + 1);

    // Queue for nodes
    queue<Node*> q;

    // Queue for horizontal positions
    queue<int> index;

    // Root has horizontal position 0
    q.push(root);

    // Convert position 0 into vector index
    index.push(-l);

    while (!q.empty()) {

        Node* temp = q.front();
        q.pop();

        int pos = index.front();
        index.pop();

        // Bottom View:
        // Always update the value
        result[pos] = temp->data;

        // Left child
        if (temp->left != NULL) {

            q.push(temp->left);
            index.push(pos - 1);
        }

        // Right child
        if (temp->right != NULL) {

            q.push(temp->right);
            index.push(pos + 1);
        }
    }

    return result;
}

int main() {

    /*
              1
            /   \
           2     3
            \   / \
             5 6   7
    */

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Get Bottom View
    vector<int> ans = bottomView(root);

    // Print answer
    cout << "Bottom View: ";

    for (int x : ans) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}