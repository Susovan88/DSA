#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1
vector<int> leaders(vector<int>& nums) {
    // code here
    int n=nums.size();
    vector<int>ans;
    int mx=nums[n-1];
    ans.push_back(nums[n-1]);
    for(int i=n-2;i>=0;i--){
    if(nums[i]>=mx)ans.push_back(nums[i]);
    mx=max(mx,nums[i]);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    vector<int>arr={100,58,2,7,5,-7,25,-13,-1,21,7,4,1,19,15,-5,10,4};
    vector<int>ans=leaders(arr);
    for(auto ele : ans)cout<<ele<<" ";
}