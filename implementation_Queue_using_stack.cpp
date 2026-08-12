#include<iostream>
#include<stack>
using namespace std;

class Queue {
    stack<int> st;
public:
    Queue(){

    }

    void push(int x){
        st.push(x);
    }
    void pop() {
        if(st.empty()){
            return;
        }
        stack<int> temp;
        while(st.size()>1){
            temp.push(st.top());
            st.pop();
        }
        st.pop();
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
    }
    bool empty(){
        return st.empty();
    }
    int front(){
        if(st.empty()){
            return -1;
        }
        stack<int> temp;
        while(st.size()>1){
            temp.push(st.top());
            st.pop();
        }
        int res=st.top();
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
        return res;
    }
};
int main(){
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.pop();
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}