//print the sum of first n natural numberd where n is the input

#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;

    //while loop
    int sum=0;
    int i=1;
    while(i<=n){
        sum+=i;
        i++;
    }
    cout<<sum<<endl;

    //for loop
    sum=0;
    for(int i=1; i<=n; i++){
        sum+=i;
    }
    cout<<sum<<endl;

    return 0;
}