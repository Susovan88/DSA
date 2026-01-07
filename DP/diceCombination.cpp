#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
# define mod 1000000007
using namespace std;


// https://cses.fi/problemset/task/1633

vector<int>dp;
int diceCom(int n){
    if(n==0) return 1;
    if(dp[n]!=-1) return dp[n];

    int sum=0;
    for(int i=1;i<=6;i++){
        if(n-i<0) break;
        sum=(sum%mod)+(diceCom(n-i)%mod);
    }
    return dp[n]=sum%mod;
}

int main(){
    dp.clear();
    dp.resize(1000006,-1);
    int n;
    cin>>n;
    cout<<diceCom(n);
}