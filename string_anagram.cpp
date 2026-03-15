//Given two dtrings s1 and s2 return true if s1 is anagram of the string s2
#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool isAnagram(string s1,string s2){

    //create frequency array
    vector<int> freq(26,0);

    //if leangth are different it shows false
    if(s1.length()!=s2.length()){
        return false;
    }

    //store freqency of the char s1 and s2
    for(int i=0;i<s1.length();i++){
        freq[s1[i]-'a']++; //for s1, we are incrementing the freq of the char
        freq[s2[i]-'a']--; //for s2, we are decrementing thr freq of the char
    }

    //checking if the frequency of every character is 0
    for(int i=0;i<26;i++){
        if(freq[i]!=0){
            return false;
        }
    }
    return true;
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    if(isAnagram(s1,s2)){
        cout<<"Strings are ansgram"<<endl;
    }else {
        cout<<"Strings are not anagram"<<endl;
    }
    return 0;
}