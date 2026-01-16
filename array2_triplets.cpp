//count the total numner of triplets whose sum is equal to the given value x
#include<iostream>
using namespace std;
int main(){
    int array[]={3,1,2,4,0,6};
    int targetSum=6;
    int triplets=0;
    for(int i=0;i<6;i++){
        for(int j=i+1;j<6;j++){
            for(int k=j+1;k<6;k++){
                if(array[i] + array[j] + array[k] == targetSum) {
                    triplets++; // Increment triplets count if sum matches target
                }
            }
        }
    }
    cout << "Total triplets with sum " << targetSum << ": " << triplets << endl;
    return 0;
}