//count the number of digits in a given number

#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;

    int digits=0;
    while(n>0){
        n=n/10;
        digits++;
    }
    cout<<digits<<endl; // Output the number of digits
    return 0;

}