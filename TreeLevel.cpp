#include<iostream>
#include<queue>
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
int main(){
    int x;
    int first,second;
    cout << "Enter root: ";
    cin >> x;
    if(x == -1) {
        return 0;
    }
    queue<Node*> q;
    Node* root =new Node(x);
    q.push(root);

    //build binary tree
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();

        //left child
        cout<<"Enter the left child of "<<temp->data<<" : ";
        cin>>first;
        if(first != -1){
            temp->left=new Node(first);
            q.push(temp->left);
        }
        //right child
        cout<<"Enter the right child of "<<temp->data<<" : ";
        cin>>second;
        if(second != -1){
            temp->right=new Node(second);
            q.push(temp->right);
        }
    }


    return 0;
}