//Given Q queris, check if the given number is pesent in the array pr not
//Note: value of all elements in the array is less than 10^5
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    const int N =1e5+10;
    vector<int> freq(N, 0); // Frequency array to store counts of elements
    for(int i=0; i<n; i++){
        freq[v[i]]++; // Increment the count for each element
    }

    cout << "Enter number of queries: ";
    int q;
    cin >> q;
    while(q--){
        int queryelement;
        cin >> queryelement;
        cout << "Frequency of " << queryelement << ": " << freq[queryelement] << endl;      
}   
    return 0;
}
