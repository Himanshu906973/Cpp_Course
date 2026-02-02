//print the first multiple of 5 which is also a multiple of 7

#include<iostream>
using namespace std;

int main(){
    
    int i=5;
    while(true){
        if(i%7==0){
            cout<<i<<endl;
            break;
        }
        i+=5;
    }

    //for loop
    for(int j=5; ; j+=5){
        if(j%7==0){
            cout<<j<<endl;
            break;
        }
        
    }

    return 0;
}

