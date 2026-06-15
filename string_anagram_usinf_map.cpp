#include<iostream>
#include<unordered_map>
using namespace std;

bool checkAnagrams(string s1, string s2){
    if(s1.length() != s2.length()){
        return false;
    }
    unordered_map<char,int> m;
    for(char c1 : s1){
        m[c1]++; // stroing the character and its frequency in s1
    }
    for(char c2: s2){
        if(m.find(c2)==m.end()){
            return false;
        }else {
            m[c2]--;
        }
    }
    for(auto ele : m){
        if(ele.second != 0){
            return false;
        }
    }
    return true;

}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    // unordered_map<char,int> m1,m2;
    // for(char c:s1){
    //     m1[c]++;
    // }
    // for(char c:s2){
    //     m2[c]++;
    // }
    // if(m1==m2){
    //     cout<<"Anagrams"<<endl;
    // }
    // else{
    //     cout<<"Not Anagrams"<<endl;
    // }
    cout<<(checkAnagrams(s1,s2)?"Anagrams":"Not Anagrams")<<endl;
    return 0;
}