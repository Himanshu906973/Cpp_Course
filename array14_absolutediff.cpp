//Given a vector arr[] sorted in increasing order of n size and an integr x, find it there exists a pair in the array whose absolute is exactly x

#include<iostream>
using namespace std;

int main(){
    // int arr[]={5,10,15,20,26};
    // int n=5;
    // int x=10;
    // int i=0;
    // int j=n-1;
    // bool found=false;
    // while(i<j){
    //     if(abs(arr[i]-arr[j])==x){
    //         found=true;
    //         break;
    //     } else if(abs(arr[i]-arr[j])<x){
    //         i++;
    //     } else {
    //         j--;
    //     }
    // }
    // if(found){
    //     cout<<"Pair found: "<<arr[i]<<" and "<<arr[j]<<endl;
    // } else {
    //     cout<<"No pair found with absolute difference "<<x<<endl;
    // }

    //using first and second pointer approach
    int arr[]={5,10,15,20,26};
    int n=5;
    int x=10;
    int i=0;
    int j=1;
    bool found=false;
    while(i<n && j<n){
        if(abs(arr[i]-arr[j])==x){
            found=true;
            break;
        } else if(abs(arr[i]-arr[j])<x){
            j++;
        } else {
            i++;
        }
    }
    if(found==true){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
    return 0;
}