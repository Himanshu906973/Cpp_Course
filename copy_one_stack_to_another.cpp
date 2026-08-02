#include<iostream>
#include<stack>
using namespace std;

stack<int> copyStack(stack<int> &input){
    stack<int> temp;
    while(!input.empty()){
        //do the process till the input stack doesnot become empty
        int curr=input.top();
        input.pop();
        temp.push(curr);
    }
    stack<int> result;
    while(!temp.empty()){
        int curr=temp.top();
        temp.pop();
        result.push(curr);
    }
    return result;
}

//using recursion
    void copyResursive(stack<int> st, stack<int> res){
        if(st.empty()){
            return;
        }
        int curr=st.top();
        st.pop();
        copyResursive(st, res);
        res.push(curr);
    }
int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    stack<int> res=copyStack(st);
    while (!res.empty())
    {
        int curr=res.top();
        res.pop();
        cout<<curr<<"\n";
    }

    //for recursion
    stack<int> res;
    copyResursive(st,res);
    while (!res.empty())
    {
        int curr=res.top();
        res.pop();
        cout<<curr<<"\n";
    }
    
    return 0;
}