#include<iostream>
#include<stack>
using namespace std;

bool isVaild(string str){
    stack<char> st;
    for(int i=0;i<str.size();i++){
        char ch=str[i]; //current char
        if(ch=='{' || ch=='(' || ch=='['){
            st.push(ch);
        }else {
            //closing barckets
            if(ch=='}' && !st.empty() && st.top()=='{') {
                st.pop();
            }else if( ch==')' && !st.empty() && st.top()=='(') {
                st.pop();
            }else if(ch==']' &&  !st.empty() &&st.top()=='['){
                st.pop();
            }
            else {
                return false;
            }
        }
    }
    return st.empty();
}
int main(){
    string str="(((})))";
    cout<<isVaild(str)<<endl;

    return 0;
}