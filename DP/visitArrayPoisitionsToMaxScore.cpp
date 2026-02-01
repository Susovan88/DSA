#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// Visit Array Positions to Maximize Score
class Solution {
public:
    long long dp[100005][2]; // At every position in the array, you only need to remember whether the last chosen number was even or odd — not the exact index
    long long helper(vector<int>& nums, int &x,int idx,int prevIdx){
        if(idx==nums.size()) return 0;
        int prity=nums[prevIdx]%2==0?0:1; //previous value-> even -0 , odd -1
        if(dp[idx][prity]!=-1) return dp[idx][prity];

        long long maxS=INT_MIN;
        // take 
        if((nums[idx]%2==0 && prity==0) || (nums[idx]%2!=0 && prity!=0)){
            maxS=max(maxS,nums[idx]+helper(nums,x,idx+1,idx));
        }
        else maxS=max(maxS,nums[idx]+helper(nums,x,idx+1,idx)-x);
        // skip
        maxS=max(maxS,helper(nums,x,idx+1,prevIdx));

        return dp[idx][prity]=maxS==INT_MIN? 0:maxS;
    }
    long long maxScore(vector<int>& nums, int x) {
        memset(dp,-1,sizeof dp);
        return nums[0]+helper(nums,x,1,0);
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int x;
    cin>>x;
    Solution sol;
    cout<<sol.maxScore(nums,x)<<endl;
}