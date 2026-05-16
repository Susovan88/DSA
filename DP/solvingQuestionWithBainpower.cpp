#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// 2140. Solving Questions With Brainpower
long long dp[100005];
int n;
long long helper(vector<vector<int>>& qu,int idx){
    if(idx>=n) return 0;
    if(dp[idx]!=-1)return dp[idx];
    long long mxP=0;
    //skip
    mxP=max(mxP,helper(qu,idx+1));
    //solved
    mxP=max(mxP, qu[idx][0]+helper(qu,idx+qu[idx][1]+1));
    return dp[idx]=mxP;
}
long long mostPoints(vector<vector<int>>& qu) {
    n=qu.size();
    memset(dp,-1,sizeof dp);
    return helper(qu,0);
}

int main(){
    vector<vector<int>>qus={
        {2,2},{1,1},{2,3},{1,2},{3,2},{4,2},{3,4},{5,2},{4,3},{3,3},{1,1},{2,5},{3,2},{4,1},{5,3},{6,2},{7,1}
    };
    cout<<mostPoints(qus);
}