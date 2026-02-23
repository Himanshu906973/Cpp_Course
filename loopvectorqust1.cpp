//Count the number of elements of the particular ocuurance x
#include<iostream>
#include<vector>
using namespace std;
int main(){

    vector<int> v(5);
    for(int i=0;i<v.size();i++){
        cin>>v[i];
    }

    cout<<"Enter x: ";
    int x;
    cin>>x;
    
    int occurance=0; // Initialize to count occurrences
    for(int i=0;i<v.size();i++){
        if(v[i]==x){
            occurance++; // Increment count if x is found
        }
    }
    cout<<occurance<<endl; 
    
    //count thr occurance which is greater than x
    occurance=0; // Reset count
    for(int i=0;i<v.size();i++){
        if(v[i]>x){
            occurance++; // Increment count if element is greater than x
        }
    }
    cout<<occurance<<endl;

    return 0;
}
