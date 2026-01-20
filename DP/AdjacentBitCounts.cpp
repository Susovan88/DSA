#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// https://www.spoj.com/problems/GNYR09F/
int dp[105][105][2];
int helper(int n,int k,int ch){
    if(k==0 && n==1) return 1;
    if(n==0 || (n==1 && k!=0)) return 0;
    if(dp[n][k][ch]!=-1) return dp[n][k][ch];

    if(ch){  
        return dp[n][k][ch]=helper(n-1,k,0)+ helper(n-1,k-1,1);
    }else{
        return dp[n][k][ch]=helper(n-1,k,0)+helper(n-1,k,1);
    }
}

int main(){
    int p;
    cin>>p;
    while(p--){
        int n,m,k;
        cin>>n>>m>>k;
        memset(dp,-1,sizeof dp);
        cout<<n<<" "<< helper(m,k,1) + helper(m,k,0) <<endl;
    }
}
