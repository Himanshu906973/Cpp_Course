#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;

    int ans=0;
    int power=1;
    while(n>0){
        int lastdigit=n%10; // Get the last digit of n
        ans+=lastdigit*power; // Multiply the last digit by its corresponding power of 2
        power*=2; // Update the power of 2 for the next digit
        n/=10; // Remove the last digit from n
    }
    cout<<ans<<endl; // Output the final decimal value
    return 0;
}