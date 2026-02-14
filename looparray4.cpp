//linear search
//seach if the given element is pressent in the array or not if it is not present -1 the returns the index of the element

#include<iostream>
using namespace std;
int main(){
    int arr[]={4,3,9,44,89};
    int key=9;
    int ans=-1;

    for(int i=0;i<5;i++){
        if(arr[i]==key){ // Check if the current element matches the key
            ans=i; // If found, store the index in ans
            break; // Exit the loop as we found the element
        }
    }
    cout<<"Element found at index: "<<ans<<endl; // Output the index of the found element or -1 if not found
    return 0; // Return 0 to indicate successful execution

}