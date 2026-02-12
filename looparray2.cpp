//calculate the sum of all elements of an array 
#include<iostream>
using namespace std;
int main(){
    int arr[]={4,7,22,9};
    int size=sizeof(arr)/sizeof(arr[0]); // Calculate the number of elements in the array
    int sum=0; // Initialize sum to 0
    for(int i=0;i<size;i++){
        sum+=arr[i]; // Add each element to sum
    }
    cout<<"Sum of all elements: "<<sum<<endl; // Output the sum of all elements in the array

    return 0; // Return 0 to indicate successful execution
}