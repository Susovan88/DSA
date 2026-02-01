#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// 494 
class Solution {
public:
    int proDp[22][1005];
    int negDp[22][1005];
    int helper(vector<int>& nums,int idx,int &target,int total){
        if(idx==nums.size()){
            if(target== total) return 1;
            return 0;
        }
        if(total>0 && proDp[idx][total]!=-1) return proDp[idx][total];
        if(total<0 && negDp[idx][abs(total)]!=-1) return negDp[idx][abs(total)];

        int add=helper(nums,idx+1,target,total+nums[idx]);
        int sub=helper(nums,idx+1,target,total-nums[idx]);
        return total>0? proDp[idx][total]=add+sub:negDp[idx][abs(total)]=add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(proDp,-1,sizeof proDp);
        memset(negDp,-1,sizeof negDp);
        return helper(nums,0,target,0);
    }
};

int main(){
    cout<<"susovan paul"<<endl;
    Solution sol;
    vector<int>nums={12,10,1,45,5,8,9,3,14,10,6};
    cout<<sol.findTargetSumWays(nums,25);
    return 0;
}