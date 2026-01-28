//Given the vector array[] sorted in the increasing order of size n and an integer x.find the number of unique pairs that exits in the array whose
//absolute sum is exactly x
#include<iostream>
using namespace std;
int main(){
    int arr[]={-4,-1,3,8,10};
    int n=5;
    int x=7;
    int i=0;
    int j=n-1;
    int count=0;
    while(i<j){
        if(abs(arr[i]+arr[j])==x){
            count++;
            i++;
            j--;
        } else if(abs(arr[i]+arr[j])<x){
            i++;
        } else {
            j--;
        }
    }
    cout<<count<<endl;
return 0;
}