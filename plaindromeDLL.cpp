#include<iostream>
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

bool palindromeDLL(Node* head, Node* tail){
    //odd no of nodes- head != tail and even- tail != head->prev
    while(head != tail && tail != head->prev){
        if(head->data != tail->data){
            return false;
        }
        head=head->next;
        tail=tail->prev;
    }
    return true;
}
int main(){
    doublelinkedlist DLL;
    DLL.insertAtEnd(1);
    DLL.insertAtEnd(2);
    DLL.insertAtEnd(3);
    DLL.insertAtEnd(2);
    DLL.insertAtEnd(1);
    DLL.display();
    cout<<palindromeDLL(DLL.head,DLL.tail)<<endl;
    return 0;

}