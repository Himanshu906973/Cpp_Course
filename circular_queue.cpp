#include<iostream>
#include<vector>
using namespace std;

class Queue {
    int front;
    int rear;
    vector<int> v;
    int ts;
    int cs;
public:
    Queue(int n){
        v.resize(n);
        ts=n;
        front=0;
        rear=n-1;
        cs=0;

    }
    void enqueue(int val){
        if(isFull()){
            return;
        }
        rear=(rear+1)%ts;
        v[rear]=val;
        cs++;

    }
    void dequeue(){
        if(isEmpty()){
            return;
        }
        front=(front+1)%ts;
        cs--;
    }
    int getFront(){
        if(front==-1){
            return -1;
        }
        return v[front];
    }
    bool isEmpty(){
        return cs==0;
    }
    bool isFull(){
        return cs==ts;
    }
};
int main(){
    Queue q(3);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.dequeue();
    q.enqueue(40);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.enqueue(400);
    q.enqueue(500);
    while(!q.isEmpty()){
        cout<<q.getFront()<<" ";
        q.dequeue();

    }
    return 0;
}