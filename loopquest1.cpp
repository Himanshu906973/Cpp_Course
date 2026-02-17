//print the sum of digits of a number   

#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;

    int sum=0;
    while(n>0){
        int lastdigit=n%10; // Get the last digit
        sum=sum+lastdigit; // Add the last digit to the sum
        n=n/10; // Remove the last digit
    }
    cout<<sum<<endl; // Output the sum of digits
    return 0;
}