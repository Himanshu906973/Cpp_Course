//Reverse the digits of a number

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int reverse=0;
    while(n>0){
        int lkastdigit=n%10; // Get the last digit
        reverse=reverse*10+lkastdigit; // Build the reverse number
        n=n/10; // Remove the last digit
    }
    cout<<reverse<<endl; // Output the reversed number
    return 0;
}