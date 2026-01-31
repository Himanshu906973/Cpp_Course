#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int ans=0;
    int power=1;
    while(n>0){
        int lastdigit=n%2; // Get the last digit of n in binary
        ans+=lastdigit*power; // Multiply the last digit by its corresponding power of 2
        power*=10; // Update the power of 10 for the next digit
        n/=2; // Remove the last digit from n
    }
    cout<<ans<<endl; // Output the final binary value
    return 0;
}

