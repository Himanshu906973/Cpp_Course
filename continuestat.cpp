//print all the values between 1 to 50 except multiples of 5
#include<iostream>
using namespace std;

int main(){
    for(int i=1; i<50; i++){
        if(i % 5 == 0) {
            continue; 
        }
        cout << i << endl;

    }
}


