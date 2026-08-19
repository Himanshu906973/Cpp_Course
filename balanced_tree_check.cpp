#include <iostream>
#include <algorithm>
#include <cmath>
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

    int height(TreeNode* root, bool &valid){
        if(root==NULL){
            return  0;
        }

        int leftHeight=height(root->left,valid);

        if(valid){
            int rightHeight=height(root->right,valid);

            if(abs(leftHeight-rightHeight)>1){
                valid=0;
            }

            return 1+max(leftHeight,rightHeight);
        }

        return -1;
    }

    bool isBalanced(TreeNode* root) {
        bool valid=1;
        height(root,valid);
        return valid;
    }
};

int main() {

    /*
            1
           / \
          2   3
         /
        4
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    Solution obj;

    if(obj.isBalanced(root)){
        cout << "Tree is Balanced" << endl;
    }
    else{
        cout << "Tree is Not Balanced" << endl;
    }

    return 0;
}