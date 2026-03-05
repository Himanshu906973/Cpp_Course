#include<iostream>
using namespace std;

void changeValue(int &z){
    z=100; // This change will affect the original variable
}

int main(){
    int x=10; // Initialize x with 10
    changeValue(x); // Call function to change value of x
    cout<<x<<endl; // Output will be 100, as x was passed by reference
    return 0; // Return 0 to indicate successful execution
}