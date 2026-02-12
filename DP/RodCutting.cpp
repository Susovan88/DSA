#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;


/*Q3 Given a rod of length n inches and an array of prices that includes prices of all pieces of
size smaller than n. Determine the maximum value obtainable by cutting up the rod and
selling the pieces.*/

int dp[1000];
int rodCutting(int n,vector<int>&price){
    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];
    int maxP=0;
    for(int i=1;i<=n;i++){
        maxP=max(maxP,price[i-1]+rodCutting(n-i,price));
    }
    return dp[n]=maxP;
}

int main(){
    memset(dp,-1, sizeof dp);
    vector<int>price{2,5,7,8};
    int length=5;
    cout<<rodCutting(length,price);
}
