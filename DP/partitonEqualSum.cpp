#include<iostream>
#include<vector>
#include <cstring>
using namespace std;

// 416. Partition Equal Subset Sum
class Solution {
public:
    int target=0;
    int dp[202][10001];
    bool helper(int idx,vector<int>& nums,int sum){
        if(idx>=nums.size()){
            if(target==sum) return true;
            return false;
        }
        if(dp[idx][sum]!=-1) return  dp[idx][sum];
        if(sum+nums[idx]>target) return dp[idx][sum]=helper(idx+1,nums,sum);  // skip

        int op1=helper(idx+1,nums,sum+nums[idx]); // // option 1 -> take
        int op2=helper(idx+1,nums,sum); // // option 2 -> skip
        return dp[idx][sum]=op1 || op2;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)sum+=nums[i];
        if(sum%2!=0) return false;
        target=sum/2;  // half of sum 
        memset(dp,-1,sizeof dp);
        return helper(0,nums,0);  // if target is exist then  both subsets is equal .
    }
};


int main(){
    cout<<"jjiji";
    vector<int>nums={12,3,5,18,9,10,7};
    Solution sol;
    cout << (sol.canPartition(nums) ? "true" : "false") << endl;
}