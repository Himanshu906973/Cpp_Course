//Pattern: Array manipulation

//find the nuique number in the given array where all the elements being repeated twice with one element being unique

#include<iostream>
using namespace std;
int main(){
    int array[]={1,2,3,1,2,3,5,6,6};
    int size = sizeof(array)/sizeof(array[0]);
    int uniqueNumber = 0; // Initialize unique number
    for(int i=0; i<size; i++) {
        for(int j=i+1;j<size;j++){
            if(array[i]==array[j]){
                array[i]=array[j]=-1;
            }
        }
    }
    for(int i=0;i<size;i++){
        if(array[i]>0){
            uniqueNumber=array[i];
        }
    }
    cout << "Unique number in the array: " << uniqueNumber << endl;
    return 0;
}
     