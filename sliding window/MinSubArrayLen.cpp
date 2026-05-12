#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// 209. Minimum Size Subarray Sum
int minSubArrayLen2(int tag, vector<int>& nums) {
    int n=nums.size();
    int i=0;
    int j=0;
    int sum=0;
    int mnL=INT_MAX;
    while(j<n){
        sum+=nums[j];
        while(sum>=tag){
            int len=j-i+1;
            mnL=min(mnL,len);
            sum-=nums[i];
            i++;
        }
        j++;
    }
    return mnL==INT_MAX? 0:mnL;
}

int minSubArrayLen(int tag, vector<int>& nums) {
    int n=nums.size();
    int i=0;
    int j=0;
    int sum=0;
    int mnL=INT_MAX;
    while(j<n){
        sum+=nums[j];
        j++;
        if(sum>=tag)break;
    }
    if(sum<tag) return 0;
    mnL=min(mnL,j-i);
    while(j<n){
        sum-=nums[i];
        i++;
        if(sum<tag){
            while(j<n){
                sum+=nums[j];
                j++;
                if(sum>=tag)break;
            }
        }
        if(sum>=tag)mnL=min(mnL,j-i);
    }
    while(i<n && sum-nums[i]>=tag){
        sum-=nums[i];
        i++;
        mnL=min(mnL,j-i);
    }
    return mnL;
}

int main(){
    vector<int>arr={2,3,1,2,4,3,1,8,1,2,1,2,7,1,3,1,2,6,2,3,1,0,1,1,3,4};
    int tag=10;
    cout<<minSubArrayLen(tag,arr);
}