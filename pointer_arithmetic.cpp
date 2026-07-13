#include<iostream>
using namespace std;

int main(){
    // int x=10;
    // int *ptr=&x;
    // cout<<ptr<<"\n";
    // cout<<*ptr<< endl;
    // cout<<(ptr+1)<<"\n";

    int arr[2]={10,20};
    int *ptr=&arr[0];
    cout<<ptr<<"\n";
    cout<<*ptr<< endl;
    cout<<*(ptr+1)<<"\n"; //it is same as arr[1]
    cout<<*ptr++<<"\n"; //it is same as arr[0]
    cout<<*ptr<<"\n"; //it is same as arr[1]
    cout<<(*ptr)++<<"\n"; //it is same as arr[1]
    return 0;

    
}