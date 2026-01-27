//Given tha vector arr[] sorted in increaseing order. Return an array of sqaure of each number sorted in increasing order.Where the
//size of vector i<size<100
#include<iostream>
using namespace std;
int main(){
    int arr[] = {-4, -1, 3, 8, 10};
    int n = 5;
    int result[5];
    int i = 0;
    int j = n - 1;
    int k = n - 1; // Start from the end
    while(i <= j){
        if(abs(arr[i]) > abs(arr[j])){
            result[k] = arr[i] * arr[i];
            i++;
        } else {
            result[k] = arr[j] * arr[j];
            j--;
        }
        k--; // Fill from the end
    }
    for(int i = 0; i < n; i++){
        cout << result[i] << " ";
    }
    return 0;
}