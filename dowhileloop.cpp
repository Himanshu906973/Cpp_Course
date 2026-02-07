//print the sum of stream of n integers in the input using do-while loop

#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    // do-while loop
    int sum = 0;
    int i = 1;
    do {
        sum += i;
        i++;
    } while (i <= n);
    
    cout << sum << endl;

    // for loop
    sum = 0;
    for (int j = 1; j <= n; j++) {
        sum += j;
    }
    
    cout << sum << endl;

    return 0;
}
