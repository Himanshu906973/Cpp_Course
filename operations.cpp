#include<iostream>
#include<climits>
using namespace std;

class Stack {
    public:
    int capacity;
    int top;
    int* arr;

    Stack(int c){
        capacity=c;
        arr=new int[c];
        top=-1;
    }
    void push(int data){
        if(top==capacity-1){
            cout<<"Overflow\n"<<endl;
            return;
        }
        top++;
        arr[top]=data;
    }
    void pop(){
        if(top==-1){
            cout<<"Underflow\n";
            return;
        }
        top--;
    }
    int getTop(){

        if(top==-1){
            cout<<"Underflow\n";
            return INT_MIN;
        }
        return arr[top];
    }
    bool empty(){
        return top==-1;
    }
    int size(){
        return top+1;
    }
    bool isFull(){
        return top==capacity-1;
    }
};
int main(){
    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<st.getTop()<<"\n"<<endl;
    st.push(4);
    st.push(5);
    cout<<st.getTop()<<"\n"<<endl;
    st.push(8);
    st.pop();
    cout<<st.getTop()<<"\n"<<endl;
    return 0;
}