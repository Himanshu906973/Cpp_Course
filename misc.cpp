#include<iostream>
using namespace std;
int main(){

    //sizeof operator
    int a = 10;
    cout<<sizeof(a)<<endl;

    char name = 'h';
    cout<<sizeof(name)<<endl;

    //conditional operator

    int n=20;
    n%2==0 ? cout<<"Even"<<endl : cout<<"Odd"<<endl;

    //& operator
    int x=6;
    cout<<(&x)<<endl; // Address of x

    //increment and decrement operators
    int y = 5;
    cout<<y++<<endl; // Post-increment- prints 5, then increments
    cout<<y<<endl; // Now y is 6
    cout<<++y<<endl; // Pre-increment
    cout<<y--<<endl; // Post-decrement- prints 7, then decrements
    cout<<y<<endl; // Now y is 6
    cout<<--y<<endl; // Pre-decrement
    cout<<y<<endl; // Now y is 5


    return 0;
}