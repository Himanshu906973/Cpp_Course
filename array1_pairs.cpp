//Pattern: Target sum

//Find the tootal  number of pairs in the array where the sum is equal to the given value x
#include<iostream>
using namespace std;
int main(){
    int array[]={3,4,6,7,1};
    int targetsum=7;

    int pairs=0;
    for(int i=0;i<5;i++){
        for(int j=i+1;j<5;j++){
            if(array[i]+array[j]== targetsum){
                pairs++; // Increment pairs count if sum matches target

            }
        }
    }
    cout << "Total pairs with sum " << targetsum << ": " << pairs << endl;
    return 0;
}