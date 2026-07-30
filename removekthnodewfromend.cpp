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


//assume k is always less than length of the linked list
void removeKthNodeFromEnd(Node* head, int k){
    Node* ptr1=head;
    Node* ptr2=head;
    //move ptr2 by k steps ahead
    int count=k;
    while(count--){
        ptr2=ptr2->next;
    }

    //if k is equal to the length of the linked list
    if(ptr2==NULL){
        Node* temp=head;
        head=head->next;
        free(temp);
        return;
    }
    //now ptr2 is k steps ahead of ptr1
    //ptr2 is at null(end of linked list), ptr1 will be at node to be  deleted
    while(ptr2->next != NULL){
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    //now ptr1 is pointing to the node before kth node from end
    //node to be deleted is ptr1->next
    Node* temp=ptr1->next;
    ptr1->next=ptr1->next->next;
    free(temp);
}
int main(){
    LinkedList ll;
    ll.insertAtTail(10);
    ll.insertAtTail(20);
    ll.insertAtTail(30);
    ll.insertAtTail(40);
    ll.insertAtTail(50);
    ll.display();
    removeKthNodeFromEnd(ll.head,3);
    ll.display();
    return 0;
}
