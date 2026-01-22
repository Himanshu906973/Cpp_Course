//check if we can partition the array into two subarrays with equal sum. More formally, check that the prefix sum of a part of that array is equal
//to the surfix sum of thr rest of the array
#include<iostream>
#include<vector>
using namespace std;

bool checkPrefixSurfixSum(vector<int> &v){
    int total_sum = 0;
    for(int i=0; i<v.size(); i++){
        total_sum += v[i];
    }

    int prefix_sum = 0;
    for(int i=0; i<v.size()-1; i++){ // We don't need to check the last element
        prefix_sum += v[i];
        int surfix_sum=total_sum-prefix_sum; // Calculate the suffix sum
        if(prefix_sum == surfix_sum){
            return true; // Found a partition where prefix sum equals suffix sum
        }
    }
    return false; // No such partition found
}
int main(){
    cout << "Enter the number of elements in the array: ";
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        v.push_back(ele);
    }

    cout<<checkPrefixSurfixSum(v)<<endl;
    return 0;
}