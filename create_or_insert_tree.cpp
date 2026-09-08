#include<iostream>
using namespace std;
class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }

};
Node* insert(Node* root,int value){
    if(root==NULL){
        Node* temp=new Node(value);
        return temp;
    }
    if(value<root->data){
        root->left=insert(root->left,value);
    }else {
        root->right=insert(root->right,value);
    }
    return root;
}
void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    int arr[]={6,3,4,5,8,7,9,1};
    Node* root=NULL;
    for(int i=0;i<8;i++){
        root=insert(root,arr[i]);
    }
    inorder(root);
}