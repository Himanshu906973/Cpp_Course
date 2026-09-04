#include <iostream>
#include<queue>
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

void preOrder(Node* root){
    if(root==NULL){
        return;
    }
    //Root
    cout<<root->data<<endl;
    //Left
    preOrder(root->left);
    //right
    preOrder(root->right);
}

void inOrder(Node* root){
    if(root==NULL){
        return;
    }
    //left
    inOrder(root->left);
    //root
    cout<<root->data<<endl;
    //right
    inOrder(root->right);
}

void postOrder(Node* root){
    if(root==NULL){
        return;
    }
    //left
    postOrder(root->left);
    //right
    postOrder(root->right);
    //Root
    cout<<root->data<<endl;
}

void levelOrder(Node* root) {

    if (root == NULL) {
        return;
    }

    queue<Node*> q;

    q.push(root);

    while (!q.empty()) {

        Node* current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current->left != NULL) {
            q.push(current->left);
        }

        if (current->right != NULL) {
            q.push(current->right);
        }
    }
}
Node* binaryTree() {

    int x;
    cin >> x;

    if (x == -1) {
        return NULL;
    }

    Node* temp = new Node(x);

    // Enter the left child
    cout<<"Enter the left child of "<<x<<": ";
    temp->left = binaryTree();

    // Enter the right child
    cout<<"Enter the right child of "<<x<<" : ";
    temp->right = binaryTree();

    return temp;
}

int main() {

    cout << "Enter the root node: ";

    Node* root = binaryTree();

    cout<<"Preorder : ";
    preOrder(root);
    cout<<"Inorder : ";
    inOrder(root);
    cout<<"PostOrder : ";
    postOrder(root);

    return 0;
}