//Find the last occurance of the element x in a given array.

#include<iostream>
#include<vector>
using namespace std;
int main(){

    vector<int> v(6);
    for(int i=0;i<6;i++){
        cin>>v[i];
    }
    cout<<"Enter x: ";
    int x;
    cin>>x;

    int occuranc=-1; // Initialize to -1 to indicate not found
    for(int i=0;i<v.size();i++){
        if(v[i]==x){
            occuranc=i; // Update to the current index if x is found
        }
    }
    cout<<occuranc<<endl; 
    
    //reverse the traversal of the vector
    for(int i=v.size()-1;i>=0;i--){
        if(v[i]==x){
            occuranc=i;
            break; 
       }
    }
    cout<<occuranc<<endl;
    
    return 0;
}