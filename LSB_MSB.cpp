#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    // Find LSB
    int lsb = n & 1;

    // Find MSB position
    int temp = n;
    int pos = 0;

    while (temp > 1) {
        temp = temp >> 1;
        pos++;
    }

    // Find MSB
    int msb = (n >> pos) & 1;

    cout << "LSB = " << lsb << endl;
    cout << "MSB = " << msb << endl;
    cout << "MSB position = " << pos << endl;

    return 0;
}