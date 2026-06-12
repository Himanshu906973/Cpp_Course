#include<iostream>  
#include<map>
using  namespace std;
int main(){
    multimap<string, int> m;
    m.insert({"Hima", 6});
    m.insert({"Bhoi", 2});
    m.insert({"Hima", 9});

    for(auto pair : m) {
        cout<<"Name: "<<pair.first<<" ID: "<<pair.second<<endl;   
    }
    return 0;
}