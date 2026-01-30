#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// 213. House Robber II
class Solution {
public: 
    int dp[103];
    int helper(vector<int>& nums,int i,int &n){ // top down 
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];

        int ans=INT_MIN;
        ans=max(ans,nums[i]+helper(nums,i+2,n));
        ans=max(ans,helper(nums,i+1,n));
        return dp[i]=ans;
    }
    int bottomUp(vector<int>& nums){  // bottom up
        int n=nums.size(); 
        memset(dp,-1,sizeof dp);

        n--;   // 0 to n-1;
        if(n>=1)dp[n-1]=nums[n-1];
        if(n>=2)dp[n-2]=max(nums[n-1],nums[n-2]);
        for(int i=n-3;i>=0;i--){
            dp[i]=max(nums[i]+dp[i+2],dp[i+1]);
        }
        int ans1=dp[0];

        n++; // 1 to n
        if(n>=1)dp[n-1]=nums[n-1];
        if(n>=2)dp[n-2]=max(nums[n-1],nums[n-2]);
        for(int i=n-3;i>=1;i--){
            dp[i]=max(nums[i]+dp[i+2],dp[i+1]);
        }
        int ans2=dp[1];
        return max(ans1,ans2); 
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        memset(dp,-1,sizeof dp);
        int ans1=helper(nums,1,n);
        memset(dp,-1,sizeof dp);
        n--;
        int ans2=helper(nums,0,n);
        return max(ans1,ans2); // top down
    }
};


int main() {
    Solution obj;
    vector<int> nums = {2, 7, 9, 3, 1,5,4,1,9,2,1,10,2};

    cout << "Maximum loot: " << obj.rob(nums) << endl; 
    cout << "Maximum loot: " << obj.bottomUp(nums) << endl;
    return 0;
}