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
    }
    void insertAtstart(int val){
        Node* new_node=new Node(val);
        if(head==NULL){
            head=new_node;
            tail=new_node;
            return;
        }
        new_node->next=head;
        head->prev=new_node;
        head=new_node;
        return;
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

    void insertAtPosition(int val,int k){
        Node* temp=head;
        int count=1; //1-based indexing
        while(count<(k-1)){
            temp=temp->next;
            count++;
        }
        //now temp is pointing to thee k-1 th node
        Node* new_node=new Node(val);
        new_node->next=temp->next;
        temp->next=new_node;
        new_node->prev=temp;
        new_node->next->prev=new_node;
        return;
    }

    //delete a node at the begin
    void deleteAtBegin(){
        if(head==NULL){
            return ;
        }
        Node* temp=head;
        head=head->next;
        if(head==NULL){ //doubly linked list has only 1 node
            tail=NULL;
        }else {
            head->prev=NULL;
        }
        free(temp);
        return;
    }

    //delete a node from the end
    void deleteAtEnd(){
        if(head==NULL){
            return;
        }
        Node* temp=tail;
        tail=tail->prev;
        if(tail==NULL){
            head=NULL;
        }else {
            tail->next=NULL;
        }
        free(temp);
        return;
    }

    //delete a node from a arbitary position
    void deleteAtPosition(int k){
        //assume k is less than or equal to the length of dll
        if(head==NULL){
            return;
        }
        Node* temp=head;
        int counter=1;
        while(counter<k){
            counter++;
            temp=temp->next;
        }
        //now temp is pointing to kth postion of dll
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
        return;
    }

};

int main(){
    doublelinkedlist dll;
    // dll.insertAtstart(2);
    // dll.insertAtstart(3);
    // dll.insertAtstart(4);
    // dll.display();
    dll.insertAtEnd(1);
    dll.insertAtEnd(2);
    dll.insertAtEnd(3);
    //dll.display();
    dll.insertAtPosition(4,3);
    //dll.display();
    //dll.deleteAtBegin();
    //dll.display();
    //dll.deleteAtEnd();
    //dll.display();
    dll.deleteAtPosition(3);
    dll.display();
    

    return 0;
}

