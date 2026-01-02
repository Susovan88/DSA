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

int uniquePathsWithObstacles(vector<vector<int>>& obsGrid) {
    int m=obsGrid.size(),n=obsGrid[0].size();
    vector<vector<int>>dp(m,vector<int>(n,-1));
    return helper(dp,obsGrid,0,0,m,n);
}

int main() {
    vector<vector<int>> obsGrid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    cout << uniquePathsWithObstacles(obsGrid) << endl;

    return 0;
}
