#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// 518. Coin Change II

class Solution {
public:
    int dp[5002][303];
    int helper(int amount,vector<int>& coins,int idx){
        if(amount==0) return 1;
        if(idx>=coins.size()) return 0;
        if(dp[amount][idx]!=-1) return dp[amount][idx];
        int ans=0;
        for(int i=idx;i<coins.size();i++){
            if(amount>=coins[i]) ans+=helper(amount-coins[i],coins,i);
        }
        return dp[amount][idx]=ans;
    }
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof dp);
        return helper(amount,coins,0);
    }
};

int main(){
    int amount=29;
    vector<int>coins={1,2,4,5,3};
    Solution sol;
    cout<<sol.change(amount,coins);
}