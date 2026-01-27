#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include <climits>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// 741. Cherry Pickup (same question)
// https://www.spoj.com/problems/TOURIST/
class Solution {
public:
    int n,m;
    int dp[55][55][55];
    int maxVisits(int i,int j,int x,vector<vector<int>>&places){
        int y=i+j-x;
        if(i>=n || j>=m || x>=n || y>=m) return INT_MIN; // not valid path
        if(places[i][j]==-1 || places[x][y]==-1) return INT_MIN; // bocked place  - not valid path
        if(i==n-1 && j==m-1) return places[i][j]==1; 
        if(dp[i][j][x]!=-1) return dp[i][j][x];

        int mxV=INT_MIN;
        mxV=max(mxV,maxVisits(i+1,j,x+1,places)); // T1->R , T2->R
        mxV=max(mxV,maxVisits(i+1,j,x,places)); // T1->R , T2->B
        mxV=max(mxV,maxVisits(i,j+1,x+1,places)); // T1->B , T2->R
        mxV=max(mxV,maxVisits(i,j+1,x,places));  // T1->B , T2->B

        if((i==x &&j==i+j-x) && places[i][j]==1)mxV+=1;  // T1 in * , T2 in * (in same visiting place) 
        else{
            if(places[i][j]==1)mxV+=1; // T1 in *
            if(places[x][i+j-x]==1)mxV+=1; // T2 in *
        }
        return dp[i][j][x]=mxV;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        memset(dp,-1,sizeof dp);
        int ans = maxVisits(0,0,0,grid);
        return ans<0? 0:ans;
    }
};

int main(){
    vector<vector<int>> grid = {
        {0,  1, -1},
        {1,  0, -1},
        {1,  1,  1}
    };
    Solution sol;
    int ans =sol.cherryPickup(grid);
    cout<<ans;
}