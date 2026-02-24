#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
# define ll long long int
# define mod 1000000007
using namespace std;

// 1277. Count Square Submatrices with All Ones

// dp[i][j] = Size of the largest square of all 1s whose bottom-right corner is at (i, j).
int dp[303][303];
int countSquares(vector<vector<int>>& mat) {
    memset(dp,0,sizeof dp);
    int n=mat.size(),m=mat[0].size();

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==0)continue;
            // mat[i][j]==1
            if(i==0 || j==0)dp[i][j]=1;
            else dp[i][j]=1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans+=dp[i][j];
        }
    }
    return ans;
}


int main(){
    vector<vector<int>> matrix = {
        {1, 0, 1},
        {1, 1, 0},
        {1, 1, 0}
    };

    cout<<"count is -> "<< countSquares(matrix);

}