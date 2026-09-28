#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int temp=n;
    int pos=0;
    while (temp>1){
        temp=temp>>1;
        pos++;
    }
    int msb=(n>>pos) & 1;
    int lsb=n & 1;
    if(msb != lsb){
        n=n^(1<<pos);
        n=n^1;
    }
    cout<<n;
    return 0; 
    
}