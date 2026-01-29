#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// 322. Coin Change 1
int miniMizeCoin(vector<int>&coin,vector<int>&dp,int n){
    if(n==0) return 0;
    if(dp[n]!=-2) return dp[n];

    int minC=INT_MAX;
    int c;
    for(int i=0;i<coin.size();i++){
        if(n>=coin[i]){
            c=miniMizeCoin(coin,dp,n-coin[i]);
            minC=min(minC,c);
        }
    }
    return dp[n]=(minC==INT_MAX? INT_MAX:minC+1);
}

int coinChange(vector<int>& coins, int amount) {
    if(amount==0) return 0;
    vector<int>dp(amount+1,-2);
    int count=miniMizeCoin(coins,dp,amount);
    return count==INT_MAX? -1:count;
}


int main(){
    int n,x;
    cin>>n>>x;
    vector<int>coins;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        coins.push_back(num);
    }

    cout<<coinChange(coins,x);

}