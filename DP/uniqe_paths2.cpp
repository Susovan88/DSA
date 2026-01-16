#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// top down
int helper(vector<vector<int>>&dp,vector<vector<int>>&obsGrid,int i,int j,int &m,int &n){
    if(i>m-1 || j>n-1) return 0;
    if(obsGrid[i][j]) return 0;
    if(i==m-1 && j==n-1) return 1;
    if(dp[i][j]!=-1) return dp[i][j];
    return dp[i][j]=helper(dp,obsGrid,i+1,j,m,n)+helper(dp,obsGrid,i,j+1,m,n);
}
int uniquePathsWithObstacles(vector<vector<int>>& obsGrid) {  // top down 
    int m=obsGrid.size(),n=obsGrid[0].size();
    vector<vector<int>>dp(m,vector<int>(n,-1));
    return helper(dp,obsGrid,0,0,m,n);
}


int uniquePathsWithObstaclesBottomUp(vector<vector<int>>& obsGrid) {  // bottom up
    int m=obsGrid.size(),n=obsGrid[0].size();
    if(obsGrid[m-1][n-1]==1) return 0;
    vector<vector<long long int>>dp(m,vector<long long int>(n+5,0));

    // base case -> bottom up solution
    dp[m-1][n-1]=1;
    for(int i=m-2;i>=0;i--){
        if(obsGrid[i][n-1]==1) dp[i][n-1]=0; // obstacle -> 0 no way to reach to destination
        else dp[i][n-1]=dp[i+1][n-1];  // next right of current
    }
    for(int i=n-2;i>=0;i--){
        if(obsGrid[m-1][i]==1) dp[m-1][i]=0; // obstacle -> 0 no way to reach to destination
        else dp[m-1][i]=dp[m-1][i+1];  // next down of current
    }
    // now apply this logic -> dp[i,j]=dp[i+1,j]+dp[i,j+1]
    for(int l=m-2;l>=0;l--){
        for(int r=n-2;r>=0;r--){
            if(obsGrid[l][r]==1) dp[l][r]=0;
            else dp[l][r]=dp[l+1][r]+dp[l][r+1];
        }
    }
    return dp[0][0];
}

int main() {
    vector<vector<int>> obsGrid = {
        {0, 0, 0, 1},
        {0, 0, 1, 0},
        {0, 0, 0, 0}
    };

    cout << uniquePathsWithObstacles(obsGrid) << endl;
    cout<< uniquePathsWithObstaclesBottomUp(obsGrid)<<endl;

    return 0;
}
