#include<iostream>
using namespace std;

int main(){
    int num1=5;
    int num2=10;
    cout<<(num1<<1)<<endl; // Left shift
    cout<<(num2>>1)<<endl; // Right shift
    cout<<(num1 & num2)<<endl; // Bitwise AND
    cout<<(num1 | num2)<<endl; // Bitwise OR

    return 0;
}