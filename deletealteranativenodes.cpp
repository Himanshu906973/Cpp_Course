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

void deleteAlternativeNodes(Node* head){
    Node* curr_node=head;
    while(curr_node != NULL && curr_node->next != NULL){
        Node* temp=curr_node->next; //node to be deleted
        curr_node->next=curr_node->next->next;
        free(temp);
        curr_node=curr_node->next;
    }
}
int main(){
    LinkedList ll;
    ll.insertAtTail(10);
    ll.insertAtTail(20);
    ll.insertAtTail(30);
    ll.insertAtTail(40);
    ll.insertAtTail(50);
    ll.display();
    deleteAlternativeNodes(ll.head);
    ll.display();
    return 0;
}
