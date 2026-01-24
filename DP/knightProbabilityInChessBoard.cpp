#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

//  688. Knight Probability in Chessboard
class Solution {
public:
    vector<int>dx={1,2,-1,-2,1,2,-1,-2};
    vector<int>dy={2,1,2,1,-2,-1,-2,-1};
    double dp[25][25][101];
    double helper(int i,int j,int k,int &n){
        if(i<0 || j<0 || i>=n || j>=n) return 0.0; // out of board.
        if( k==0) return 1.0;
        if(dp[i][j][k]>-0.2) return dp[i][j][k];

        double ans=0.0;
        for(int a=0;a<8;a++){
            ans+=helper(i+dx[a],j+dy[a],k-1,n)/8.0;
        }
        return dp[i][j][k]=ans;

    }
    double knightProbability(int n, int k, int row, int column) {
        memset(dp,-1,sizeof dp);
        return helper(row,column,k,n);
    }
};

int main(){
    Solution sol;
    cout<<sol.knightProbability(5,4,2,1);
}