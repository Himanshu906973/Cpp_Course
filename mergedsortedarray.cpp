//Merge the two sorted array
#include<iostream>
using namespace std;
int main(){
    int n, m;
    cout << "Enter the size of first array: ";
    cin >> n;
    cout << "Enter the size of second array: ";
    cin >> m;

    int arr1[n], arr2[m];
    cout << "Enter elements of first array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    
    cout << "Enter elements of second array: ";
    for(int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    int merged[n + m];
    int i = 0, j = 0, k = 0;

    //both i and j should be within the limits of their respective arrays
    //k should be within the limits of the merged array
    while(i < n && j < m) {
        if(arr1[i] < arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }

    while(i < n) {
        //arr2 was exuhasted and we still got element left in arr1
        merged[k++] = arr1[i++];
    }

    while(j < m) {
        //arr1 was exhausted and we still got element left in arr2
        merged[k++] = arr2[j++];
    }

    cout << "Merged sorted array: ";
    for(int i = 0; i < n + m; i++) {
        cout << merged[i] << " ";
    }
    
    cout << endl;
    return 0;
}