#include<iostream>
#include<map>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> input(n);
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    map<int,int> m;
    for(int i=0;i<n;i++){
        //stroring the frequency of each element in the map
        m[input[i]]++;
    }
    int sum=0;
    //finding sum of retipitive elements
    //pair- element and its frequency
    for(auto pair : m){
        if(pair.second>1){
            sum+=pair.first;
        }
    }
    cout<<sum<<endl;
    return 0;
}