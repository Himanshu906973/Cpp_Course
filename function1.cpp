#include<iostream>
using namespace std;

int add(int num1,int num2){
    return num1 + num2; // Return the sum of num1 and num2
}

int main(){
    int a=5;
    int b=8;
    int sum=add(a, b); // Call the add function with a and b
    cout<<sum<<endl; // Output the sum
    return 0; // Return 0 to indicate successful execution
}