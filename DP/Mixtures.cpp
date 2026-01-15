#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
#define mod 100
using namespace std;

// https://www.spoj.com/problems/MIXTURES/

// In the Mixtures problem, when two mixtures are combined:
// Smoke = color1 * color2
// NOT nums[l] + nums[r]

vector<vector<int>>newNum;
int newColor(vector<int>&nums,int l,int r){
    if(l==r) return nums[l]%mod;
    if(r-l==1) return (nums[l]+nums[r])%mod;
    if(newNum[l][r]!=-1) return newNum[l][r];
    return newNum[l][r]=(nums[l]%mod+newColor(nums,l+1,r)%mod)%mod;
}

vector<vector<int>>dp;// extra array for store 
int minGas(vector<int>&nums,int l,int r){
    if(l==r) return 0;
    if(r-l==1) return nums[l]*nums[r];
    if(dp[l][r]!=-1) return dp[l][r];
    int minG=INT_MAX;
    for(int i=l;i<r;i++){
        int s1=minGas(nums,l,i);
        int s2=minGas(nums,i+1,r);
        minG=min(minG,(s1+s2+(newColor(nums,l,i)*newColor(nums,i+1,r))));
    }
    return dp[l][r]=minG;
}


int bottomUp(vector<int>&nums){
    int n=nums.size();
    dp.assign(n, vector<int>(n, 0));
    for(int len=2;len<=n;len++){
        for(int l=0; l+len-1<n;l++){
            int r=l+len-1;
            int minG=INT_MAX;
            for(int i=l;i<r;i++){
                int s1=dp[l][i];
                int s2=dp[i+1][r];
                minG=min(minG,(s1+s2+(newColor(nums,l,i)*newColor(nums,i+1,r))));
            }
            dp[l][r]=minG;
        }
    }
    return dp[0][n-1];

}


int main(){
    int n;
    while(cin>>n){
        vector<int>nums(n);
        for(int i=0;i<n;i++){
            int x;
            cin>>nums[i];
        }
        dp.clear();
        dp.resize(n+1,vector<int>(n+1,-1));
        newNum.clear();
        newNum.resize(n+1,vector<int>(n+1,-1));

        // cout<<minGas(nums,0,n-1)<<endl;
        cout<<bottomUp(nums);
    }
}