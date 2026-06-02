#include<iostream>
#include<map>
using namespace std;
int main(){
    map<string,int> student;
    //map<string,int, greater<string>> student; // for reverse order
    student["Hima"]=20;
    student["Bhoi"]=21;
    for(auto element : student){
        cout<<"Name: "<<element.first<<" Age: "<<element.second<<endl;
    }
}