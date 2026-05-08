#include<iostream>
#include<iomanip>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// 1696. Jump Game VI
int dp[100040];
int n;
int helper(int idx,vector<int>&arr,int &k){ // TLE
    if(idx>=n) return INT_MIN;
    if(dp[idx]!=-1) return dp[idx];
    if(idx==n-1) return arr[idx];
    int mxS=INT_MIN;
    int sum;
    int i=idx+1;
    while(i<n && i<=idx+k){
        sum=helper(i,arr,k);
        if(sum!=INT_MIN) mxS=max(mxS,arr[idx]+sum);
        i++;
    }
    return dp[idx]=mxS;
}
int maxResult(vector<int>& nums, int k) {
    n=nums.size();
    memset(dp,-1,sizeof dp);
    return helper(0,nums,k);
}

// DP + Deque + sliding Window
int maxResult1(vector<int>& nums, int k) {
    int dp[100040];
    int n=nums.size();
    deque<int>dq;
    memset(dp,-1,sizeof dp);
    dq.push_back(n-1);
    dp[n-1]=nums[n-1];
    // right to left 
    for(int i=n-2;i>=0;i--){
        // remove indices outside range
        while(dq.size()!=0 && dq.front()>i+k){
            dq.pop_front();
        }
        // max future dp
        dp[i]=nums[i]+dp[dq.front()];
        // maintain decreasing dp values
        while(dq.size()!=0 && dp[dq.back()]<=dp[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    return dp[0];
}
int main(){
    vector<int>arr={1,-5,-20,4,-1,3,-6,-3};
    cout<<maxResult1(arr,3);
}