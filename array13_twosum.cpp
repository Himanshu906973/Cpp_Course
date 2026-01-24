//Given a vector arr[] sorted in increasing order of n size and an integr x, find it there exists a pair in the array whose sum is exactly x.
#include<iostream>
using namespace std;

int main(){
    int arr[]={-2,-1,0,3,4,9,14,15};
    int x=14;
    int n=8;
    int i=0;
    int j=n-1;
    bool found=false;
    while(i<j){
        if(arr[i]+arr[j]==x){
            found=true;
            break;
        } else if(arr[i]+arr[j]<x){
            i++;
        } else {
            j--;
        }
    }
    if(found){
        cout<<"Pair found: "<<arr[i]<<" and "<<arr[j]<<endl;
    } else {
        cout<<"No pair found with sum "<<x<<endl;
    }
    return 0;
}