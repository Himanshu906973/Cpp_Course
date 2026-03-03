#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            cout<<"*"; // Print '*' for the triangle pattern
        }
        cout<<endl; // Print a new line after each row
    }
    return 0;
}

