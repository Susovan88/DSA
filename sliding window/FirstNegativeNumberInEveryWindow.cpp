#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// First negative number in every window of size k
// https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
vector<int> FirstNegativeNumberInEveryWindow(vector<int>&nums,int k){
    int n=nums.size();
    vector<int>ans;
    int i=0,j=0;
    int ni=-1; // index of first negative element
    for(j=0;j<k;j++){
        if(nums[j]<0 && ni==-1)ni=j;
    }
    ans.push_back(ni==-1? 0:nums[ni]);
    while(j<n){
        if(ni==i){
            for(int x=i+1;x<=j;x++){
                if(nums[x]<0){
                    ni=x;
                    break;
                }
            }
            if(ni<=i)ni=-1;
        }
        else if(ni==-1 && nums[j]<0) ni=j;
        ans.push_back(ni==-1? 0:nums[ni]);
        i++;
        j++;
    }
    return ans;
}

int main(){
    vector<int> nums = {-1, 2, 3, 4};
    vector<int>ans=FirstNegativeNumberInEveryWindow(nums,2);
    for(auto ele : ans )cout<<ele<<" ";
}

// -5 -5 -9 -9 -14 -14 -1 -1 0 0 -30 -30 -30 -30