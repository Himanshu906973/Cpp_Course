
#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

bool canRepresentBST(vector<int>& arr) {
    stack<int> lower, upper;
    lower.push(INT_MIN);
    upper.push(INT_MAX);
    int lowerBound, upperBound;
    for (int i = 0; i < arr.size(); i++) {
        while (!upper.empty() && arr[i] > upper.top()) {
            lower.pop();
            upper.pop();
        }
        if (lower.empty() || arr[i] <= lower.top()|| arr[i] >= upper.top()) {
            return false;
        }
        lowerBound = lower.top();
        upperBound = upper.top();
        lower.pop();
        upper.pop();

        // Right subtree
        lower.push(arr[i]);
        upper.push(upperBound);

        // Left subtree
        lower.push(lowerBound); 
        upper.push(arr[i]);
    }

    return true;
}

int main() {
    vector<int> arr = {10, 5, 1, 7, 40, 50};

    if (canRepresentBST(arr)) {
        cout << "Yes, it represents a valid BST preorder";
    }
    else {
        cout << "No, it does not represent a valid BST preorder";
    }

    return 0;
}
