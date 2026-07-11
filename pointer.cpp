#include<iostream>
using namespace std;
int main(){
    int x;
    cout<<&x;
    int y=10;
    int *ptr=&y;
    cout<<ptr<<"\n";
    cout<<*ptr<< endl;
    return 0;

    // int *ptr;
    // int marks=100;
    // ptr=&marks;
    // cout<<*ptr;
}