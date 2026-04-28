#include<iostream>
#include <bits/stdc++.h>
using namespace std;
// Consecutive 1's not allowed
// // https://www.geeksforgeeks.org/problems/consecutive-1s-not-allowed1912/1
// Recursion + DP
int dp[50][2];
int helper(int n, int flag){
    if(n==1){
        return flag? 2:1;
    }
    if(dp[n][flag]!=-1) return dp[n][flag];
    int ans=0;
    ans+=helper(n-1,1);
    if(flag){
        ans+=helper(n-1,0);
    }
    return dp[n][flag]=ans;
}
int countStrings(int n) {
    memset(dp,-1,sizeof dp);
    return helper(n,1);
}

// TLE
vector<string>ans;
void helper1(int n,string &temp){
    if(n==0){
        ans.push_back(temp);
        return;
    }
    temp.push_back('0');
    helper1(n-1,temp);
    temp.pop_back();
    if(temp[temp.size()-1]!='1'){
        temp.push_back('1');
        helper1(n-1,temp);
        temp.pop_back();
    }
    return;
}
int countStrings1(int n) {
    string temp="";
    helper1(n,temp);
    return ans.size();
}

int main(){
    int n=30;
    cout<<countStrings(n);
}