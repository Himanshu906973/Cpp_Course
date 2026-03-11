//Pattern: prefix sum in 2D array
//Given a matricx 'a' of dimension n*m, and 2 coordinators (l1,r1) and (l2,r2). Return the sum of the rectangel from (l1,r1) to (l2,r2).
#include<iostream>
#include<vector>
using namespace std;
int rectagleSum(vector<vector<int>> &a,int l1,int r1,int l2,int r2){
    // int sum=0;
    // for(int i=l1;i<=l2;i++){
    //     for(int j=r1;j<=r2;j++){
    //         sum+=a[i][j];
    //     }
    // }
    // return sum;


    // //prefix sum approach only row wise
    // //prefix sum array row wise
    // int sum=0;
    // for(int i=0;i<a.size();i++){
    //     for(int j=1;j<a[0].size();j++){
    //         a[i][j]+=a[i][j-1];
    //     }
    // }

    // //print the prefix sum array
    // for(int i=0;i<a.size();i++){
    //     for(int j=0;j<a[0].size();j++){
    //         cout<<a[i][j]<<" ";
    //     }cout<<endl;
    // }

    // for(int i=l1;i<=l2;i++){
    //     if(r1>0){
    //         sum+=a[i][r2]-a[i][r1-1];
    //     }else{
    //         sum+=a[i][r2];
    //     }
    // }
    // return sum;

    //prefix sum approach row wise and column wise
    //prefix sum array row wise
    int sum=0;
    for(int i=0;i<a.size();i++){
        for(int j=1;j<a[0].size();j++){
            a[i][j]+=a[i][j-1];
        }
    }
    //prefix sum array column wise
    for(int j=0;j<a[0].size();j++){
        for(int i=1;i<a.size();i++){
            a[i][j]+=a[i-1][j];
        }
    }
    //print the prefix sum array
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a[0].size();j++){
            cout<<a[i][j]<<" ";
        }cout<<endl;
    }

    int top_sum=0,left_sum=0,top_left_sum=0;
    if(l1 != 0){
        top_sum=a[l1-1][r2];
    }
    if(r1 != 0){
        left_sum=a[l2][r1-1];
    }
    if(l1 != 0 && r1 != 0){
        top_left_sum=a[l1-1][r1-1];
    }
    sum=a[l2][r2]-top_sum-left_sum+top_left_sum;
    return sum;

}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    int l1,r1,l2,r2;
    cin>>l1>>r1>>l2>>r2;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<a[i][j]<<" ";
        }cout<<endl;
    }

    int sum=rectagleSum(a,l1,r1,l2,r2);
    cout<<"Sum : "<< sum<<endl;
    return 0;
 
} 