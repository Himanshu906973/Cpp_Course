//sort the array consisting of only 0s and 1s
#include<iostream>
#include<vector>
using namespace std;

// void sortZeroesAndOnes(vector<int> &v){
//     int zero_count=0;

//     // Count the number of 0s in the array
//     for(int i=0;i<v.size();i++){
//         if(v[i]==0){
//             zero_count++;
//         }
//     }
//     // Fill the array with 0s and 1s based on the count
//     for(int i=0;i<v.size();i++){
//         if(i<zero_count){
//             v[i]=0; // Fill the first zero_count positions with 0s
//         } else {
//             v[i]=1; // Fill the rest with 1s
//         }
//   } 
// } 

// Optimized version using two pointers
// void sortZeroesAndOnes(vector<int> &v) {
//     int left = 0, right = v.size() - 1;

//     while (left < right) {
//         // Increment left pointer if it points to 0
//         while (left < right && v[left] == 0) {
//             left++;
//         }
//         // Decrement right pointer if it points to 1
//         while (left < right && v[right] == 1) {
//             right--;
//         }
//         // Swap if left is less than right
//         if (left < right) {
//             swap(v[left], v[right]);
//             left++;
//             right--;
//         }
//     }
    
// }

//or
void sortZeroesAndOnes(vector<int> &v){
    int left_ptr=0;
    int right_ptr=v.size()-1;
    while(left_ptr<right_ptr){
        if(v[left_ptr]==1 && v[right_ptr]==0){
            v[left_ptr++]=0;
            v[right_ptr--]=1;

        }
        if(v[left_ptr]==0){
            left_ptr++;
        }
        if(v[right_ptr]==1){
            right_ptr--;
        }
    }
    return;

}


int main(){
    cout << "Enter number of elements in the array: ";
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){       
        int ele;
        cin>>ele;
        v.push_back(ele);
    }

    sortZeroesAndOnes(v);

    cout << "Sorted array: ";

    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";    
    }
    cout << endl;
    return 0;
}

