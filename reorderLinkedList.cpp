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


Node* reorderLinkedList(Node* head){
    //find the middle element of the linked lsit
    Node* slow=head;
    Node* fast=head;
    while(fast != NULL && fast->next != NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    //now slow is pointing to the middle element
    //separate the linked list and reverse the second half
    Node* curr=slow->next;
    slow->next=NULL;
    Node* prev=slow;
    while(curr != NULL){
        Node* nextPtr=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextPtr;
    }
    //merge the two halfs of the linked list
    Node* ptr1=head; //linked list first half
    Node* ptr2=prev; //linked list second half
    while(ptr1 != ptr2){
        Node* temp=ptr1->next;
        ptr1->next=ptr2;
        ptr1=ptr2;
        ptr2=temp;
    }
    return head;
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
    ll.head=reorderLinkedList(ll.head);
    ll.display();
    return 0;
}
