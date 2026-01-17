#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// https://atcoder.jp/contests/dp/tasks/dp_l

// top down 
vector<vector<int>>dp;
int helper(int i,int j,vector<int>&arr){
    if(i==j)return arr[i];
    if(dp[i][j]!=-1)return dp[i][j];
    int op1=arr[i]-helper(i+1,j,arr);
    int op2=arr[j]-helper(i,j-1,arr);
    return dp[i][j]=max(op1,op2);
}
int deque1(vector<int>arr){
    int n=arr.size();
    dp.clear();
    dp.resize(n+9,vector<int>(n+9,-1));
    return helper(0,n-1,arr);
}

// bottom up
int deque2(vector<int>arr){
    int n=arr.size();
    dp.clear();
    dp.resize(n+9,vector<int>(n+9,0));

    //base case
    for(int i=0;i<n;i++) dp[i][i]=arr[i]; // len =1 

    for(int len=2;len<=n;len++){  //  
        for(int l=0;l<=n-len;l++){
            int r=l+len-1;
            dp[l][r]=max((arr[l]-dp[l+1][r]),(arr[r]-dp[l][r-1]));
        }
    }

    return dp[0][n-1];
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans1=deque2(arr);
    int ans2=deque1(arr);
    cout<<ans1<<" "<<ans2;
}
