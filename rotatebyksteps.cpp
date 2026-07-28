#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int val){
        data=val;
        next=NULL;
    }
};
class LinkedList {
    public:
    Node* head;
    LinkedList(){
        head=NULL;
    }

    void insertAtTail(int val){
        Node* new_node=new Node(val);
        if(head==NULL){
            head=new_node;
            return;
        }
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;
    }
    void display(){
        Node* temp=head;
        while(temp != NULL){
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
};


Node* rotateByk(Node* &head ,int k){
    //find the length of linked list
    int n=0;
    //find the taila node
    Node* tail=head;
    while(tail->next != NULL){
        n++; //find the length
        tail=tail->next; //find the tail node
    }
    n++; //for including last node
    k=k%n;
    if(k==0){
        return head;
    }
    tail->next=head;
    //traverse n-k nodes
    Node* temp=head;
    for(int i=1;i<n-k;i++){
        temp=temp->next;
    }
    //temp is pointing n-k th node
    Node* newhead=temp->next;
    temp->next=NULL;
    return newhead;
}
int main(){
    LinkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    ll.insertAtTail(6);
    ll.insertAtTail(7);
    ll.insertAtTail(8);
    ll.display();
    ll.head=rotateByk(ll.head,3);
    ll.display();
    return 0;
}
