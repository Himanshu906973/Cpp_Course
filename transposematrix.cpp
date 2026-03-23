//write a program to display thr transpose of thr matrix entered by user
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> array(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>array[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<array[i][j]<<" ";
        }cout<<endl;
    }

    vector<vector<int>> Transpose(m, vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            Transpose[i][j]=array[j][i];
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<Transpose[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}