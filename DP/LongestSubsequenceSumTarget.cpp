#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;

// 2915. Length of the Longest Subsequence That Sums to Target

int dp[1003][1003];
int helper(vector<int>& nums, int t,int i){
    if(t==0) return 0;
    if(i==nums.size()) return INT_MIN;
    if(dp[i][t]!=-1) return dp[i][t];
    if(t<nums[i]) return dp[i][t]=helper(nums,t,i+1);
    int ans=INT_MIN;
    ans=max(ans,1+helper(nums,t-nums[i],i+1));  // take 
    ans=max(ans,helper(nums,t,i+1));  // skip
    return dp[i][t]=ans;
}
int lengthOfLongestSubsequence(vector<int>& nums, int target) {
    memset(dp,-1,sizeof dp);
    int ans=helper(nums,target,0);
    return ans<0?-1:ans;
}


int main() {
    cout<<"susovan paul";

    vector<int> nums = {1, 2, 3, 4, 5};
    int target = 7;

    int result =lengthOfLongestSubsequence(nums, target);
    cout << "Length of longest subsequence with sum = "
         << target << " is: " << result << endl;
    return 0;
}