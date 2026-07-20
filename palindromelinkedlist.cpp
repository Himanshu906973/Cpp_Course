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


bool isPalindrome(Node* head){
    if(head==NULL || head->next ==NULL){
        return true;
    }
    //find the middle element of the linked list
    Node* slow=head;
    Node* fast=head;
    while(fast != NULL && fast->next != NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    //now slow is pointing to the middle element
    //break the linked list in the middle
    Node* curr=slow->next;
    Node* prev=slow;
    slow->next=NULL;
    //reverse the second half of the linked list
    while(curr != NULL){
        Node* nextnode=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextnode;
    }
    //check if the two halfs are equals
    Node* first=head;
    Node* second=prev;
    while(second != NULL){
        if(first->data != second->data){
            return false;
        }
        first=first->next;
        second=second->next;
    }
    return true;
}
int main(){
    LinkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(3);
    ll.insertAtTail(2);
    ll.insertAtTail(1);
    ll.display();
    cout<<isPalindrome(ll.head)<<endl;
    return 0;
}
