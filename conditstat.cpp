#include<iostream>
using namespace std;

int main(){

    //if-else statements
    int num;
    cin>>num;
    if(num%2==0){
        cout<<"Even"<<endl;
    } else{
        cout<<"Odd"<<endl;
    }

    //if-else leader statement
    int age;
    cin>>age;
    if(age<12){
        cout<<"child"<<endl;
    }else if (age>12 && age<18){
        cout<<"teenager"<<endl;
    }else {
        cout<<"adult"<<endl;
    }


    //nested if-else statement

    int marks;
    cin>>marks;

    if(marks>33){
        if(marks>80){
            cout<<"Gracefully"<<endl;
        }else{
            cout<<"passs"<<endl;
        }
    }else {
        cout<<"fail"<<endl;
    }

    
    return 0;

   
}