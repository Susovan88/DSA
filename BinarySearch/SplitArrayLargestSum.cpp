#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// 410. Split Array Largest Sum
int splitArray(vector<int>& nums, int k) {
    int n=nums.size();
    int mx=INT_MIN;
    int sum=0;
    for(int i=0;i<n;i++){
        mx=max(mx,nums[i]);
        sum+=nums[i];
    }
    int st=mx;
    int end=sum;
    int ans=INT_MAX;
    while(st<=end){
        int mid=st+(end-st)/2; // max subarray sum;
        int i=0;
        int sum=0;
        int c=0;
        while(i<n){
            while(i<n && sum+nums[i]<=mid){
                sum+=nums[i];
                i++;
            }
            if(sum<=mid){
                c++;
                sum=0;
            }
        }
        if(c<=k){
            ans=min(ans,mid);
            end=mid-1;
        }else{
            st=mid+1;
        }
    }
    return ans==INT_MAX? -1:ans;
}

int main(){
    vector<int>={7,2,5,10,8};
    int k=2;
    cout<<splitArray(arr,k);
}