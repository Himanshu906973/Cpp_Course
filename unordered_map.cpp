#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map<int, string> m;
    m[6]="Hima";
    m[2]="Bhoi";
    m[9]="Suman";
    m.insert({4,"Sai"});
    m.insert({2,"Ravi"}); // it will not update the value of key 2 because in unordered map keys are unique
    m[2]="Ravi"; // it will update the value of key 2 because in unordered map keys are unique
    for(auto element : m){
        cout<<"Key: "<<element.first<<" Value: "<<element.second<<endl;
    }
    return 0;
}