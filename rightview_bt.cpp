#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

vector<int> printLeftView(Node* root) {

    vector<int> ans;

    if (root == NULL) {
        return ans;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {

        // First node of current level
        ans.push_back(q.front()->data);

        int n = q.size();

        while (n--) {

            Node* temp = q.front();
            q.pop();

            if (temp->right != NULL) {
                q.push(temp->right);
            }

            if (temp->left != NULL) {
                q.push(temp->left);
            }
        }
    }

    return ans;
}

int main() {

    /*
              1
             / \
            2   3
           / \   \
          4   5   6
             /
            7
    */

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->right = new Node(6);

    root->left->right->left = new Node(7);

    vector<int> ans = printLeftView(root);

    cout << "Left View: ";

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}