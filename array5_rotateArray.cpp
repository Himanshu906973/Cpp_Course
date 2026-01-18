//Rotate the given array by k steps, where k ia a non-negative integer Note: k can be greater than n as well where n is the size of the array
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    // int arr[]={1,2,3,4,5};
    // int n=5;
    // int k=2; // Number of steps to rotate
    // k = k % n; // Handle cases where k is greater than n
    // int rotatedArray[n];
    // int j=0;
    // // Copy the last k elements to the beginning of the new array
    // for(int i=n-k;i<n;i++){
    //     rotatedArray[j]=arr[i];
    //     j++;
    // }
    // // Copy the first n-k elements to the end of the new array
    // for(int i=0;i<n-k;i++){
    //     rotatedArray[j]=arr[i];
    //     j++;
    // }
    // // Print the rotated array
    // cout << "Rotated array: ";
    // for(int i=0;i<n;i++){
    //     cout << rotatedArray[i] << " ";
    // }
    // cout << endl;

    // vector approach 
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    int k=2;
    k=k % v.size(); // Handle cases where k is greater than the size of the vector
    reverse(v.begin(), v.end()); // Reverse the entire vector
    reverse(v.begin(), v.begin() + k); // Reverse the first k elements
    reverse(v.begin() + k, v.end()); // Reverse the remaining elements
    cout << "Rotated vector: ";
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}