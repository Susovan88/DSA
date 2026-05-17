#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// 992. Subarrays with K Different Integers
int atMost(vector<int>& nums,int k){
    unordered_map<int,int>mp;
    int n=nums.size();
    int i=0,j=0;
    int ans=0;
    while(j<n){
        mp[nums[j]]++;
        while(mp.size()>k){
            mp[nums[i]]--;
            if(mp[nums[i]]==0)mp.erase(nums[i]);
            i++;
        }
        ans+=(j-i+1);
        j++;
    }
    return ans;
}
int subarraysWithKDistinct(vector<int>& nums, int k) {
    return atMost(nums,k)-atMost(nums,k-1);
}

int main(){
    vector<int>arr={2,3,2,2,1,3,3,3,5,2,6,9,8,1,3,1,1,1};
    cout<<subarraysWithKDistinct(arr,3);
}