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

Node* reverseLL(Node* head){
   Node* prevptr=NULL;
   Node* currptr=head;
   while(currptr != NULL){
      Node* nextptr=currptr->next;
      currptr->next=prevptr;
      prevptr=currptr;
      currptr=nextptr;
   }
   //when this loop ends, prevptr will be pointing to the last node which is new head
   Node* new_head=prevptr;
   return new_head;
}

//recursive approach
Node* reverseLLRecursive(Node* head){
    //base case
    if(head==NULL || head->next==NULL){
        return head;
    }
    //recursive case
    Node* new_head=reverseLLRecursive(head->next);
    head->next->next=head;
    head->next=NULL; //head is now the last node, so its next should be NULL
    return new_head;
}
int main(){
    LinkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(3);
    ll.display();
    ll.head=reverseLL(ll.head);
    ll.display();
    ll.head=reverseLLRecursive(ll.head);
    ll.display();
    return 0;
}
