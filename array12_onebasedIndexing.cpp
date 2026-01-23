//Given an array of integers of size n, answer q queries where you need to print thr sum of values in the given range of indices 
//from l to r(both inlcuded)
//The value of l and r queries follows 1-based indexing 
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n+1, 0); // Create a vector of size n+1 to store prefix sums
    for(int i=1; i<=n; i++){
        cin>>v[i]; // Read the elements into the vector starting from index 1
   }

   //calculate prefix sum array
   for(int i=0;i<n;i++){
     v[i]+=v[i-1]; // Update the current element with the sum of itself and the previous element
   }

   int q;
   cin>>q;
   
   while(q--){
    int l,r;
    cin>>l>>r;

    int ans=0;
     //ans=prefixsumarray[r]-prefixsumarray[l-1];
    ans = v[r] - v[l-1]; // Calculate the sum from index l to r using the prefix sum array
    cout<<ans<<endl;
   }
    return 0;
}