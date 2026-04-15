#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/longest-subarray-with-sum-divisible-by-k1259/1
int longestSubarrayDivK(vector<int>& arr, int k) {
    // Complete the function
    unordered_map<int,int>mp;
    int n=arr.size();
    int mx=0;
    int sum=0;
    int modDiff=0;
    for(int i=0;i<n;i++){
        modDiff=((modDiff+arr[i])%k-k)%k;   // Handle negative numbers. Always keep modDiff in range [0, k-1]
        // cout<<modDiff<<" "<<i<<endl;
        if(modDiff==0){
            mx=max(mx,i+1);
        }
        if(mp.find(modDiff)!=mp.end()){
            int ln=i-mp[modDiff];
            mx=max(mx,ln);
        }
        else mp[modDiff]=i;
    }
    return mx;
}

int main(){
    vector<int>arr={10,5,2,7,5,-7,2,-13,-1,2,7,4,1,9,5,-5,10,4};
    cout<<"max subarray length is -> "<<longestSubarrayDivK(arr,4);
}

/*
This solution uses prefix sum + modulo + hashmap to find the longest subarray whose sum is divisible by k. 
Instead of storing the full sum, we store prefixSum % k (called modDiff). If the same modDiff appears again,
it means the subarray between those indices has sum divisible by k. We store the first occurrence of each modDiff in a hashmap to maximize subarray length. 
If modDiff == 0, the subarray from index 0 to i is valid.
Time complexity is O(n).
*/
