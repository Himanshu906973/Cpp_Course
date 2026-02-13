//find the maximum element of an array 
#include<iostream>
using namespace std;

int main(){
    int arr[]={4,7,23,6,5,45};
    int size=sizeof(arr)/sizeof(arr[0]); // Calculate the number of elements in the array
    int maxElement=arr[0]; // Initialize maxElement to the first element of the
    for(int i=1;i<size;i++){ // Start from the second element
        if(arr[i]>maxElement){ // If the current element is greater than maxElement
            maxElement=arr[i]; // Update maxElement
        }
    }
    cout<<"Maximum element: "<<maxElement<<endl; // Output the maximum element found in the array

    return 0;
}