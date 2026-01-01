#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// top down -> recursion + memorization
int top_down(vector<int>&dp,int n){
    if(n<=1) return n;
    if(dp[n]!=-1) return dp[n];
    dp[n]=top_down(dp,n-1) + top_down(dp,n-2);
    return dp[n];
}
int fib(int n) {
    vector<int>dp(n+1,-1);
    return top_down(dp,n);
}

// botm up -> tabulation
int fibo(int n){
    if(n<=1)return n;
    vector<int>dp(n+1);
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;

    cout << "Top Down Fibonacci: " << fib(n) << endl;
    cout << "Bottom Up Fibonacci: " << fibo(n) << endl;

    return 0;
}
