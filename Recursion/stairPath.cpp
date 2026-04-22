#include<iostream>
#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair-1587115620/1
int dp[50];
int helper(int n) {
    if(n==1 || n==2 || n==0) return n;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=(helper(n-1) + helper(n-2));
}
int countWays(int n) {
    memset(dp,-1,sizeof dp);
    return helper(n);
}

int main(){
    int n=13;
    cout<<"count-ways-to-reach-the-nth-stair-> "<<countWays(n)<<endl;
}