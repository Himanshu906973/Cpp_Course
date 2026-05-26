#include<iostream>
#include<vector>
using namespace std;
void selectionSort(vector<int> array, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (array[j] < array[min_index]) {
                min_index = j;
            }
        }
        swap(array[i], array[min_index]);
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> array(n);
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    selectionSort(array, n);
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
    return 0;   
}