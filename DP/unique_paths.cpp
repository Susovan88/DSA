#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// top down DP
int helper(vector<vector<int>>&dp,int srow,int scol,int &erow,int &ecol){
    if(srow==erow-1 && scol==ecol-1) return 1;
    if(srow>erow-1 || scol>ecol-1) return 0;
    if(dp[srow][scol]!=-1) return dp[srow][scol];// if already pesent then return 

    int rC=helper(dp,srow,scol+1,erow,ecol); // right side ways
    int dC=helper(dp,srow+1,scol,erow,ecol); // down side ways 
    return dp[srow][scol]=rC+dC;
}
int uniquePaths1(int m, int n) {
    // store the differents ways on ith position to destinition.
    vector<vector<int>>dp(m,vector<int>(n,-1)); 
    return helper(dp,0,0,m,n);
}


// Bottom up DP
int uniquePaths2(int m, int n) {
    // store the differents ways on ith position to destinition.
    vector<vector<int>>dp(m,vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 || j==0) dp[i][j]=1;
            else dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}

int main() {
    int m = 3, n = 7;

    cout << uniquePaths1(m, n) << endl;
    cout << uniquePaths2(m, n) << endl;

    return 0;
}
