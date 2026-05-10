#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// 2770. Maximum Number of Jumps to Reach the Last Index
int n;
int dp[1003];
int helper(vector<int>&nums,int idx,int &tag){
    if(idx==n-1) return 0;
    if(idx>=n) return INT_MIN;
    if(dp[idx]!=-1) return dp[idx];
    int mxJ=INT_MIN;
    for(int i=idx+1;i<n;i++){
        int x=nums[i]-nums[idx];
        if(x>=-tag && x<=tag){
            int j=helper(nums,i,tag);
            if(j==INT_MIN)continue;
            mxJ=max(mxJ,j+1);
        }
    }
    return dp[idx]=mxJ;
}

int maximumJumps(vector<int>& nums, int target) {
    n=nums.size();
    memset(dp,-1,sizeof dp);
    int ans=helper(nums,0,target);
    return ans==INT_MIN? -1 : ans;
}

int main(){
    vector<int>arr={1,3,6,4,1,2,9,1,2,3,4,12,3,1};
    int tag=3;
    cout<<maximumJumps(arr,tag);
}