#include <iostream>
#include <queue>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(NULL), right(NULL) {}

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {

        // Tree is empty
        if (root == NULL) {
            return NULL;
        }

        // Key is smaller, search in left subtree
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
            return root;
        }

        // Key is greater, search in right subtree
        else if (root->val < key) {
            root->right = deleteNode(root->right, key);
            return root;
        }

        // We found the node
        else {

            // Case 1: Leaf node
            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }

            // Case 2: Only left child exists
            else if (root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3: Only right child exists
            else if (root->left == NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            // Case 4: Both children exist
            else {

                // Find greatest node in left subtree
                TreeNode* parent = root;
                TreeNode* child = root->left;

                // Go to the rightmost node
                while (child->right != NULL) {
                    parent = child;
                    child = child->right;
                }

                // Predecessor is not direct left child
                if (parent != root) {

                    parent->right = child->left;

                    child->left = root->left;
                    child->right = root->right;

                    delete root;

                    return child;
                }

                // Predecessor is direct left child
                else {

                    child->right = root->right;

                    delete root;

                    return child;
                }
            }
        }
    }
};


// Inorder traversal
void inorder(TreeNode* root) {

    if (root == NULL) {
        return;
    }

    inorder(root->left);

    cout << root->val << " ";

    inorder(root->right);
}


// Level order traversal
void levelOrder(TreeNode* root) {

    if (root == NULL) {
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {

        TreeNode* current = q.front();
        q.pop();

        cout << current->val << " ";

        if (current->left != NULL) {
            q.push(current->left);
        }

        if (current->right != NULL) {
            q.push(current->right);
        }
    }
}


int main() {

    /*
             50
            /  \
          30    70
         /  \
       20    40
    */

    TreeNode* root = new TreeNode(50);

    root->left = new TreeNode(30);
    root->right = new TreeNode(70);

    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(40);

    cout << "Original tree (Inorder): ";
    inorder(root);

    cout << endl;

    int key = 50;

    Solution solution;

    root = solution.deleteNode(root, key);

    cout << "After deleting " << key << " (Inorder): ";
    inorder(root);

    cout << endl;

    cout << "After deleting " << key << " (Level Order): ";
    levelOrder(root);

    cout << endl;

    return 0;
}