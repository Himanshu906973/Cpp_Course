#include <iostream>
#include <vector>
using namespace std;

// Linked List Node
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

// Binary Tree Node
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
    TreeNode* buildTree(vector<int>& nums, int left, int right) {
        if (left > right) {
            return NULL;
        }

        int mid = (left + right) / 2;

        TreeNode* root = new TreeNode(nums[mid]);

        root->left = buildTree(nums, left, mid - 1);
        root->right = buildTree(nums, mid + 1, right);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;

        while (head != NULL) {
            nums.push_back(head->val);
            head = head->next;
        }

        return buildTree(nums, 0, nums.size() - 1);
    }
};

// Print inorder traversal
void inorder(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Print tree structure
void printTree(TreeNode* root, int space = 0) {
    if (root == NULL) {
        return;
    }

    space += 5;

    printTree(root->right, space);

    cout << endl;
    for (int i = 5; i < space; i++) {
        cout << " ";
    }
    cout << root->val << endl;

    printTree(root->left, space);
}

int main() {
    // Create sorted linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;

    TreeNode* root = sol.sortedListToBST(head);

    cout << "Inorder Traversal: ";
    inorder(root);

    cout << "\n\nBalanced BST Structure:";
    printTree(root);

    return 0;
}