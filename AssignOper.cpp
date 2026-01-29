#include<iostream>
using namespace std;

int main(){

    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    // Assignment operators
    a += b; // a = a + b
    cout << "After a += b, a: " << a << endl;

    a -= b; // a = a - b
    cout << "After a -= b, a: " << a << endl;

    a *= b; // a = a * b
    cout << "After a *= b, a: " << a << endl;

    if (b != 0) {
        a /= b; // a = a / b
        cout << "After a /= b, a: " << a << endl;
    } else {
        cout << "Division by zero is not allowed." << endl;
    }

    return 0;
}