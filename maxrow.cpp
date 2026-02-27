//Given a boolean 2D array,wherre each row is started .Find the row with maximum 1's.
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// int maximumOncesRow(vector<vector<int>> &v){
//     int maxOnces=INT_MIN;
//     int maxOncesRow=-1;
//     int columns=v[0].size();
//     for(int i=0;i<v.size();i++){
//         for(int j=0;j<v[i].size();j++){
//             if(v[i][j]==1){
//                 int numberOfOnces=columns-j;
//                 if(numberOfOnces>maxOnces){
//                     maxOnces=numberOfOnces;
//                     maxOncesRow=i;
//                 }
//             }
//         }
//     }
//     return maxOncesRow;
// }
// int main(){
//     int n,m;
//     cin>>n>>m;
//     vector<vector<int>> vec(n, vector<int>(m));
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cin>>vec[i][j];
//         }
//     }
//     int res=maximumOncesRow(vec);
//     cout<<res<<endl;
//     return 0;
// }


//another approach
int leftMostOne(vector<vector<int>> &v){
    int leftMostOne=-1;
    int maxOnesRow=-1;
    int j=v[0].size()-1;
    while(j>=0 && v[0][j]==1){
        leftMostOne=j;
        maxOnesRow=0;
        j--;
    }
    for(int i=1;i<v.size();i++){
        while(j>=0 && v[i][j]==1){
            leftMostOne=j;
            maxOnesRow=i;
            j--;
        }
    }
    return maxOnesRow;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> vec(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>vec[i][j];
        }
    }
    int res=leftMostOne(vec);
    cout<<res<<endl;
    return 0;
}