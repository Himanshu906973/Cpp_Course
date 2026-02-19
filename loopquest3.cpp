//find the sum of the following series s=1-2+3-4+5-6+...+n

#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int  result=0;
    for(int i=0;i<=n;i++){
        if(i%2==0){
            result-=i;
        }else{
            result+=i;
        }

    }
    cout<<result<<endl; // Output the final result
    return 0;
}