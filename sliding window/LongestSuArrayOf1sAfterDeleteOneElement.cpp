#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// 1493. Longest Subarray of 1's After Deleting One Element
int longestSubarray(vector<int>& nums) {
    int n=nums.size();
    int i=0,j=0;
    int mxL=0;
    bool flip=true;
    while(j<n){
        if(nums[j])j++;
        else if(flip){
            flip=false;
            j++;
        }else{
            mxL=max(mxL,j-i-1);
            while(nums[i])i++;
            i++;
            j++;
        }
    }
    mxL=max(mxL,j-i-1);
    return mxL;
}

int main(){
    vector<int>arr={1,1,1,0,0,0,1,1,1,1,0,1,1,1,1,1,0,1,1,};
    cout<<longestSubarray(arr);
}