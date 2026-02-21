//given two numnbers a and b, find a raise to the power of b
#include<iostream>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;

    int result=1;
    for(int i=1;i<=b;i++){
        result*=a; // Multiply a to the result b times

    }
    cout<<result<<endl; // Output the final result
    return 0;
}