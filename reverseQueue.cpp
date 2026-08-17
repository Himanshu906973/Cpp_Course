#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void reverseQueue(queue<int> &q){
    stack<int> st;
    //queue->stack
    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }
    //stack->queue
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
}
int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    reverseQueue(q);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}