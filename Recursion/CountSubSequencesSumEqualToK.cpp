#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int helper(vector<int>&nums,int idx,int k){
    if(nums.size()==idx){
        if(k==0){
            return 1;
        }
        return 0;
    }
    // take 
    int take=0;
    if(nums[idx]<=k){
        take=helper(nums,idx+1,k-nums[idx]);
    }
    // skip
    int skip=helper(nums,idx+1,k);
    return take+skip;
}
int countSubsequenceWithTargetSum(vector<int>& nums, int k){
    return helper(nums,0,k);;
}

int main(){
    vector<int> v = {1,2,3,14,9,12,11,8,7,10,5};
    int k=15;
    cout<<countSubsequenceWithTargetSum(v,k);
}