#include<iostream>
#include<vector>
using namespace std;
int partition(vector<int> &arr,int low,int high){
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}
void quickSort(vector<int> &arr,int low,int high){
    if(low<high){
        int pivIdx=partition(arr,low,high);
        quickSort(arr,low,pivIdx-1);
        quickSort(arr,pivIdx+1,high);
    }
}
int main(){
    vector<int> arr = {5, 2, 8, 1, 3};
    quickSort(arr, 0, arr.size() - 1);
    for(int x : arr) {
        cout << x << " ";
    }
    return 0;
}