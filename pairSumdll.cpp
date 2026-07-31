#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val){
        data=val;
        prev=NULL;
        next=NULL;
    }
};
class doublelinkedlist {
    public:
    Node* head;
    Node* tail;

    doublelinkedlist(){
        head=NULL;
        tail=NULL;
    }

    void display(){
        Node* temp=head;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    void insertAtEnd(int val){
        Node* new_node=new Node(val);
        if(tail==NULL){
            tail=new_node;
            head=new_node;
            return;
        }
        tail->next=new_node;
        new_node->prev=tail;
        tail=new_node;
        return;
    }
}; 

vector<int> pairSumDLL(Node* head,Node* tail, int x){
    vector<int> ans(2,-1);
    while(head != tail){
        int sum=head->data+tail->data;
        if(sum==x){
            ans[0]=head->data;
            ans[1]=tail->data;
            return ans;
        }
        if(sum>x){ // we need smaller value, we will move tail back
            tail=tail->prev;
        }else { //we need larger value, we will move head forward
            head=head->next;
        }
    }
    return ans;
}
int main(){
    doublelinkedlist DLL;
    DLL.insertAtEnd(2);
    DLL.insertAtEnd(5);
    DLL.insertAtEnd(6);
    DLL.insertAtEnd(8);
    DLL.insertAtEnd(10);
    DLL.display();
    vector<int> ans=pairSumDLL(DLL.head,DLL.tail,11);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;

}