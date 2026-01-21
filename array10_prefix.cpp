//Given an integer array 'a', retur thre prefix sum or running sum in the same array without creating a new array
#include<iostream>
#include<vector>
using namespace std;
void runningSum(vector<int> &v){
    for(int i=1;i<v.size();i++){
        v[i] += v[i-1]; // Update the current element with the sum of itself and the previous element
    }
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
    runningSum(v);
    cout << "Running sum of the array: ";

    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout << endl;
    return 0;



}
