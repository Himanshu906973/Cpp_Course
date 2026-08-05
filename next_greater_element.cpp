#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> nextGreaterElement(vector<int> &arr){
    int n=arr.size();
    vector<int>res(n,-1);
    stack<int> st; //stores indexes
    st.push(0);
    for(int i=1;i<n;i++){
        while(!st.empty() && arr[i]>arr[st.top()]){
            res[st.top()]=arr[i];
            st.pop();
        }
        st.push(i);
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    vector<int> v;
    while(n--){
        int x;
        cin>>x;
        v.push_back(x);
    }
    vector<int>res=nextGreaterElement(v);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    return 0;
}