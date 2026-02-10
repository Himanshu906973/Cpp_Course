//Traversing of an array using for loop

#include<iostream>
using namespace std;

int main(){
    int arr[]={1,2,3,4};

    int size=sizeof(arr)/sizeof(arr[0]); // Calculate the number of elements in the array
    for(int i=0;i<size;i++){
        cout<<arr[i]<<endl;
    }

    //for each loop
    for(int element : arr){
        cout<<element<<endl;
    }

    //while loop
    int j=0;
    while(j<size){
        cout<<arr[j]<<endl;
        j++;
    }

return 0;
}