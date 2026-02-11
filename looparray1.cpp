#include<iostream>
using namespace std;
int main(){
    char vowels[5];
    // cin>>vowels[0]>>vowels[1]>>vowels[2]>>vowels[3]>>vowels[4]; // Input 5 characters into the array
    for(int i=0;i<5;i++){
        cin>>vowels[i]; // Input each character in the array
    }
    for(int i=0;i<5;i++){
        cout<<vowels[i]<<" "; // Output each character in the array
    }

    //for each loop
    for(char &element : vowels){
        cin>>element;
    }

    for(char element : vowels){
        cout<<element<<" "; // Output each character in the array using for each loop
    }

    //while loop
    int j=0;
    while(j<5){
        cin>>vowels[j]; // Input each character in the array using while loop
        j++;
    }
    j=0; // Reset j to 0 for output
    while(j<5){
        cout<<vowels[j]<<" "; // Output each character in the array using while loop
        j++;
    }

    return 0;
}

