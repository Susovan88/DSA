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

int main() {
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    cout <<minPathSum(grid);

    return 0;
}