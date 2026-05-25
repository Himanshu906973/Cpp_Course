#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(vector<int> &arr,int n){
    for(int i=0;i<n-1;i++){
        int didSwap=0;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                didSwap=1;
            }
        }
        if(didSwap==0){
            break;
        }
        
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bubbleSort(arr, n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;

}