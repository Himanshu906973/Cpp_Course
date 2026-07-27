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

void deleteSameNeighbourNode(Node* &head, Node* &tail){
    Node* currNode=tail->prev; //second last node
    while(currNode != head){
        Node* prevNode=currNode->prev;
        Node* nextNode=currNode->next;
        if(prevNode->data==nextNode->data){
            prevNode->next=nextNode;
            nextNode->prev=prevNode;
            delete(currNode);
        }
        currNode=prevNode;
    }

}
int main(){
    doublelinkedlist DLL;
    DLL.insertAtEnd(2);
    DLL.insertAtEnd(1);
    DLL.insertAtEnd(1);
    DLL.insertAtEnd(2);
    DLL.insertAtEnd(1);
    DLL.display();
    deleteSameNeighbourNode(DLL.head,DLL.tail);
    DLL.display();
    return 0;

}