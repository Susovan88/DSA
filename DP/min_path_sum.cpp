#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// 64. Minimum Path Sum
int helper(vector<vector<int>>& grid,vector<vector<int>>& minSum,int i,int j, int m, int n){
    if(i>m-1 || j>n-1) return INT_MAX;
    if(i==m-1 && j==n-1) return grid[i][j];
    if(minSum[i][j]!=-1) return minSum[i][j];
    return minSum[i][j]=grid[i][j] + min(helper(grid,minSum,i+1,j,m,n),helper(grid,minSum,i,j+1,m,n));
}
int minPathSum(vector<vector<int>>& grid) {
    int m=grid.size(),n=grid[0].size();
    vector<vector<int>>minSum(m,vector<int>(n,-1));
    return helper(grid,minSum,0,0,m,n);
}

// bottom up solution
int minPathSumBU(vector<vector<int>>& grid) {
    int m=grid.size(),n=grid[0].size();
    vector<vector<int>>dp(m,vector<int>(n,0));
    // base case -> bottom up solution
    dp[m-1][n-1]=grid[m-1][n-1];
    for(int i=m-2;i>=0;i--){
        dp[i][n-1]=grid[i][n-1]+dp[i+1][n-1];  // next right + current 
    }
    for(int i=n-2;i>=0;i--){
        dp[m-1][i]=grid[m-1][i] + dp[m-1][i+1];  // next down + current 
    }
    // now apply this logic -> dp[i,j]=dp[i+1,j]+dp[i,j+1]
    for(int l=m-2;l>=0;l--){
        for(int r=n-2;r>=0;r--){
            dp[l][r]=grid[l][r]+min(dp[l+1][r],dp[l][r+1]);
        }
    }
    return dp[0][0];
}

int main() {
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    cout <<minPathSum(grid)<<endl;
    cout <<minPathSumBU(grid)<<endl;
    return 0;
}