#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// 485. Max Consecutive Ones
int findMaxConsecutiveOnes(vector<int>& nums) {
    int n=nums.size();
    int i=0;
    int mx=0;
    while(i<n){
        if(nums[i]==0){
            i++;
            continue;
        }
        int j=0;
        while(i<n && nums[i]==1){
            i++;j++;
        }
        mx=max(mx,j);
    }
    return mx;
}

int main(){
    vector<int>arr={1,1,1,1,1,0,0,1,0,1,0,0,0,0,0,1,1,1,1,1,1,1,0};
    cout<<"Max Consecutive Ones -"<<findMaxConsecutiveOnes(arr);
    
}