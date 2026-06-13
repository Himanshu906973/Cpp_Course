#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    unordered_multimap<string, int> fruitCount;
    fruitCount.insert({"Apple", 10});
    fruitCount.insert({"Banana", 20});
    fruitCount.insert({"Apple", 15}); // Allows duplicate keys

    for(auto pair : fruitCount) {
        cout<<"Fruit: "<<pair.first<<" Count: "<<pair.second<<endl;   
    }
    return 0;
}
