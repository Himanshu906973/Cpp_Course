//find the difference between sum of the elements at even indices and sum of elements at odd indices
#include<iostream>
#include<vector>
using namespace std;
int main() {
    vector<int> v(5);
    for(int i=0; i<v.size(); i++) {
        cin >> v[i];
    }

    int evenSum = 0, oddSum = 0; // Initialize sums

    for(int i=0; i<v.size(); i++) {
        if(i % 2 == 0) {
            evenSum += v[i]; // Add to even indexed sum
        } else {
            oddSum += v[i]; // Add to odd indexed sum
        }
    }

    int difference = evenSum - oddSum; // Calculate the difference
    cout << "Difference: " << difference << endl;

    return 0;
}