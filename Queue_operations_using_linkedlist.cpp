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

class Queue {
    Node* front;
    Node* rear;
    int size;
public:
    Queue(){
       front=NULL;
       rear=NULL;
       size=0;
    }

    void enqueue(int val){
        Node* newNode=new Node(val);
        if(front==NULL){ //queue is empty
            front=rear=newNode;
            return;
        }

        rear->next=newNode;
        rear=newNode;
        size++;
    }

    void dequeue() {
        if(front==NULL){
            return;
        }
        Node* temp=front;
        front=front->next;
        if(front==NULL){
            rear=NULL;
        }
        delete temp;
        size--;
    }

    int getSize(){
        return size;
    }
    bool isEmpty(){
        return front==NULL;
    }
    int getFront(){
        if(front==NULL){
            return -1;
        }
        return front->data;
    }
    
};

int main(){
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.dequeue();
    q.enqueue(40);
    while(!q.isEmpty()){
        cout<<q.getFront()<<" ";
        q.dequeue();

    }
    return 0;
}