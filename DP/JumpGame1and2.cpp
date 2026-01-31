#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// jump game 1
class Solution1 {
public:
    int dp[10004];
    bool helper(int idx,vector<int>& nums){
        if(idx==nums.size()-1) return true;
        if(idx>=nums.size()) return false;
        if(nums[idx]>=nums.size()-idx-1) return true; // if jump >= remaing indexs
        if(dp[idx]!=-1) return dp[idx];

        for(int i=idx+1;i<=idx+nums[idx];i++){
            bool temp=helper(i,nums);
            if(temp) return dp[idx]=true;
        }
        return dp[idx]=false;
    }
    bool canJump(vector<int>& nums) {
        memset(dp,-1,sizeof dp);
        return helper(0,nums);
    }
};

// jump game 2
class Solution2 {
public: 
    int dp[10004];
    int helper(int idx,vector<int>& nums){
        if(idx>=nums.size()-1) return 0;
        if(nums[idx]>=nums.size()-idx-1) return dp[idx]=1; // if jump >= remaing indexs
        if(dp[idx]!=-1) return dp[idx];

        int minJ=INT_MAX;
        for(int i=idx+1;i<=idx+nums[idx];i++){
            if(nums[i]!=0){
                int ans=helper(i,nums);
                if(ans!=INT_MAX)minJ=min(minJ,ans);
            }
        }
        return dp[idx]=minJ==INT_MAX? INT_MAX:minJ+1;
    }
    int jump(vector<int>& nums) {
        memset(dp,-1,sizeof dp);
        return helper(0,nums);
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Jump Game 1
    Solution1 s1;
    cout << "Can Jump (Jump Game 1): " << (s1.canJump(nums) ? "true" : "false") << endl;

    // Jump Game 2
    Solution2 s2;
    cout << "Minimum Jumps (Jump Game 2): "<< s2.jump(nums) << endl;

    return 0;
}
