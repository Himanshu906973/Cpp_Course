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

//insert at frist position
void insertAtHead(Node* &head,int val){
    Node* new_node=new Node(val);
    new_node->next=head;
    head=new_node;
}

//insert at last position
void insertAtTail(Node* &head,int val){
    Node* new_node=new Node(val);
    if(head==NULL){
        head=new_node;
        return;
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    //temp has reached the last node
    temp->next=new_node;
}

//insert at any position
void insertAtPosition(Node* &head,int val,int pos){
    if(pos==0){
        insertAtHead(head,val);
        return;
    }
    Node* new_node=new Node(val);
    Node* temp=head;
    int curr_pos=0;
    while(curr_pos != pos-1){
        temp=temp->next;
        curr_pos++;
    }
    //temp is pointing to node at pos-1
    new_node->next=temp->next;
    temp->next=new_node;
}


//updation at kth position
void updateAtPosition(Node* &head, int k, int val){
    Node* temp=head;
    int curr_pos=0;
    while(curr_pos != k){
        temp=temp->next;
        curr_pos++;
    }
    //temp will be pointing to the node at position k
    temp->data=val;
}


//delete a node at first position
void deleteAtHead(Node* &head){
    Node* temp=head; //node to be deteleted
    head=head->next;
    free(temp);
}

//delete a node at the end position
void deleteAtTail(Node* &head){
    Node* sec_last=head;
    while(sec_last->next->next!=NULL){
        sec_last=sec_last->next;
    }
    //sec_last is pointing to second last node
    Node* temp=sec_last->next; //node to be deleted
    sec_last->next=NULL;
    free(temp);
}

//delete a node at kth position
void deleteAtPosition(Node* &head,int pos){
    if(pos==0){
        deleteAtHead(head);
        return;
    }
    Node* prev=head;
    int curr_pos=0;
    while(curr_pos != pos-1){
        prev=prev->next;
        curr_pos++;
    }
    //prev is pointing to node at pos-1
    Node* temp=prev->next; //node to be deleted
    prev->next=prev->next->next;
    free(temp);  
}
void traverse(Node* head){
    Node* temp=head; 
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
int main(){
    Node* head=NULL;
    insertAtHead(head,30);
    insertAtHead(head,20);
    insertAtHead(head,10);
    traverse(head);
    insertAtHead(head,5);
    traverse(head);
    insertAtTail(head,4);
    traverse(head);
    insertAtPosition(head,100,2);
    traverse(head);
    updateAtPosition(head,3,200);
    traverse(head);
    deleteAtHead(head);
    traverse(head);
    deleteAtTail(head);
    traverse(head);
    deleteAtPosition(head,2);
    traverse(head);
    return 0;
}