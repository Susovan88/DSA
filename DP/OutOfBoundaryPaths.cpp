#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

// Out of Boundary Paths
class Solution {
public:
    int dp[51][51][51];
    int helper(int &m, int &n, int maxMove, int i, int j){
        if(i>=m || j>=n || i<0 || j<0) return 1;
        if(maxMove==0) return 0;
        if(dp[i][j][maxMove]!=-1) return dp[i][j][maxMove];

        int ans=0;
        ans=(ans+helper(m,n,maxMove-1,i+1,j)%mod)%mod;
        ans=(ans+helper(m,n,maxMove-1,i-1,j)%mod)%mod;
        ans=(ans+helper(m,n,maxMove-1,i,j+1)%mod)%mod;
        ans=(ans+helper(m,n,maxMove-1,i,j-1)%mod)%mod;

        return dp[i][j][maxMove]=ans%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof dp);
        return helper(m,n,maxMove,startRow,startColumn);
    }
};

int main(){
    Solution sol;
    cout<<sol.findPaths(5,7,5,2,6);
}