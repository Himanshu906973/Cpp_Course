#include<iostream>
using namespace std;
int main(){
    // int n,m;
    // cin>>n>>m;
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<<j;
    //     }
    //     cout<<endl; // Print a new line after each row
    // }
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            cout<<j; // Print the column number for each position
        }
        for(int j=1;j<=(i-1);j++){
            cout<<j; // Print the column number for each position in the second half
        }
        cout<<endl;
    }
    return 0;
}