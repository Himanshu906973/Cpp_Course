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

void deleteDuplicateNodes(Node* head){
    Node* curr_node=head;
    while(curr_node != NULL){
        while(curr_node->next != NULL && curr_node->data == curr_node->next->data){
            Node* temp=curr_node->next; //node to be deleted
            curr_node->next=curr_node->next->next;
            free(temp);
        }
        //this loop ends when the current and next node have different values or linkedlist ends
        curr_node=curr_node->next; //move to next node
    }
    
}
int main(){
    LinkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(3);
    ll.display();
    deleteDuplicateNodes(ll.head);
    ll.display();
    return 0;
}
