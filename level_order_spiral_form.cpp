#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        if (root == NULL) {
            return ans;
        }

        stack<TreeNode*> s1;
        stack<TreeNode*> s2;

        s1.push(root);

        while (!s1.empty() || !s2.empty()) {

            vector<int> level;

            // Left to Right
            if (!s1.empty()) {

                int size = s1.size();

                for (int i = 0; i < size; i++) {

                    TreeNode* temp = s1.top();
                    s1.pop();

                    level.push_back(temp->val);

                    if (temp->left != NULL) {
                        s2.push(temp->left);
                    }

                    if (temp->right != NULL) {
                        s2.push(temp->right);
                    }
                }

            }
            // Right to Left
            else {

                int size = s2.size();

                for (int i = 0; i < size; i++) {

                    TreeNode* temp = s2.top();
                    s2.pop();

                    level.push_back(temp->val);

                    if (temp->right != NULL) {
                        s1.push(temp->right);
                    }

                    if (temp->left != NULL) {
                        s1.push(temp->left);
                    }
                }
            }

            ans.push_back(level);
        }

        return ans;
    }
};

int main() {

    /*
              1
            /   \
           2     3
          / \   / \
         4   5 6   7
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution obj;

    vector<vector<int>> result = obj.zigzagLevelOrder(root);

    cout << "Zigzag Level Order Traversal:" << endl;

    for (vector<int> level : result) {

        for (int value : level) {
            cout << value << " ";
        }

        cout << endl;
    }

    return 0;
}