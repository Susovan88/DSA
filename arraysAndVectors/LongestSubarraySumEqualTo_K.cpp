#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1
int longestSubarray(vector<int>& arr, int k) {
    int n=arr.size();
    unordered_map<int,int>prefix;
    int sum=0;
    int mxL=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        int diff=sum-k;
        if(diff==0)mxL=max(mxL,i+1);
        
        if(prefix.find(diff)!=prefix.end()){
            int ln=i-prefix[diff];
            mxL=max(mxL,ln);
        }
        // cout<<sum<<"-"<<i<<" - "<<mxL<<endl;
        if(prefix.find(sum)==prefix.end()) prefix[sum]=i;
    }
    return mxL;
}

//  560. Subarray Sum Equals K
int subarraySum(vector<int>& nums, int k) {
    unordered_map<int,int>mp;
    int n=nums.size();
    int count=0;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=nums[i];
        if(sum==k)count++;
        if(mp.find(sum-k)!=mp.end())count+=mp[sum-k];
        mp[sum]++;
    }
    return count;
}

int main(){
    vector<int>arr={10,5,2,7,5,-7,2,-13,-1,2,7,4,1,9,5,-5,10,4};
    cout<<"Max subarray length is -> "<<longestSubarray(arr,14)<<endl;
    cout<<"Total count of subarray sum equal to k is = "<<subarraySum(arr,14)<<endl;
}

/*
This approach uses the prefix sum + hashmap technique to find the longest subarray with sum k.
 As we traverse the array, we keep adding elements to a running sum (sum).
 At each index, we check if sum - k already exists in the hashmap—if it does, 
 it means the subarray between that previous index and the current index has sum k, 
 so we update the maximum length. If sum itself equals k, then the subarray from the start to current index is valid.
  We store the first occurrence of each prefix sum in the hashmap to ensure we always get the longest possible subarray. 
  This makes the solution efficient with O(n) time complexity.
*/