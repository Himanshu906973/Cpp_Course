//Given the array of integer , moving all the even intergers at the beginning of the array followed by odd integrs. The relative order of even or
// odd integer does not matter 
// return any array that satrisfies the condition

#include<iostream>
#include<vector>
using namespace std;

void sortByParity(vector<int> &v){
    int left = 0, right = v.size() - 1;

    while (left < right) {
        // Increment left pointer if it points to an even number
        while (left < right && v[left] % 2 == 0) {
            left++;
        }
        // Decrement right pointer if it points to an odd number
        while (left < right && v[right] % 2 == 1) {
            right--;
        }
        // Swap if left is less than right
        if (left < right) {
            swap(v[left], v[right]);
            left++;
            right--;
        }
    }
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

    sortByParity(v);

    cout << "Array after sorting by parity: ";
    for(int i=0; i<n; i++){
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}