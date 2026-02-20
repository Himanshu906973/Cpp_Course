//print the factorial of a number n

#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int factorial=1;
    for(int i=1;i<=n;i++){
        factorial*=i; // Multiply the current number to the factorial
        cout<<factorial<<endl; // Output the factorial at each step
    }

    return 0;
}