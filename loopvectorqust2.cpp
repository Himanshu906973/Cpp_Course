//check if the array is sirted or not
#include<iostream>
#include<vector>
using namespace std;
int main(){

    int array[]={1,2,3,4,5};

    bool isSorted=true; // Assume the array is sorted

    for(int i=1;i<5;i++){
        if(array[i]<=array[i-1]){
            isSorted=false; // If any element is less than or equal to the previous, it's not sorted
        }
    }
    cout<<isSorted<<endl;
    return 0;
}