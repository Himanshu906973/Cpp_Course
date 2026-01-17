//find the second largest element in the array
#include<iostream>
#include<climits>
using namespace std;
// int largestElementIndex(int array[],int size){
//     int max=INT_MIN;
//     int maxindex=-1;
//     for(int i=0;i<size;i++){
//         if(array[i]>max){
//             max=array[i];
//             maxindex=i;
//         }
//     }
//     return maxindex; // Return the index of the largest element
// }
// int main(){
//     int array[]={3,4,6,8,2,8,7};
//     int n=7;
//     int indexoflargest=largestElementIndex(array,n);
//     cout <<array[indexoflargest] << endl;
//     //array[indexoflargest]=-1;
//     int largest=array[indexoflargest];
//     for(int i=0;i<n;i++){
//         if(array[i]==largest){
//             array[i]=-1; // Mark the largest element as -1
//         }
//     }
//     int indexofsecondlargest=largestElementIndex(array,n);
//     cout << array[indexofsecondlargest] << endl;
    
//     return 0;
// }

// or
int secondLargestElement(int array[], int size) {
    int max = INT_MIN;
    int sec_max = INT_MIN;

    for (int i = 0; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
    }
    }
    for (int i = 0; i < size; i++) {
        if (array[i] > sec_max && array[i]!=max) {
            sec_max = array[i];
        }
      }
    
    return sec_max;
}
int main(){
    int array[] = {3, 4, 6, 8, 2, 8, 7};
    int n = sizeof(array) / sizeof(array[0]);
    int second_largest = secondLargestElement(array, n);
    cout << "The second largest element is: " << second_largest << endl;
    
    return 0;
}