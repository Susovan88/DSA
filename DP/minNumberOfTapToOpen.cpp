#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// 1326. Minimum Number of Taps to Open to Water a Garden

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int>dp(n+1,INT_MAX);

        dp[0]=0;
        for(int i=0;i<=n;i++){
            int st=max(0,i-ranges[i]);
            int end=min(n,i+ranges[i]);
            int ans=INT_MAX;
            for(int j=st;j<=end;j++){
                ans=min(ans,dp[j]);
            }
            if(ans!=INT_MAX) dp[end]=min(dp[end],ans+1);
        }

        return dp[n]==INT_MAX? -1:dp[n];
    }
};

// Greedy idea:
// Start from position 0.
// Among all taps that can start watering at or before the current position, choose the one that extends farthest to the right.
// Open that tap, move your current position to the farthest reach.
// Repeat until you reach n.
// If at any point you cannot move forward, return -1.

int main(){
    vector<int>ranges={2,4,1,1,3,2,1,2,1,1,3,2,8,9};

    Solution sol;
    cout<<sol.minTaps(ranges.size()-1,ranges);
}