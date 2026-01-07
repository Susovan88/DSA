#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// probem ->  https://cses.fi/problemset/task/1637/

int removingDigit(vector<int>&dp,int n){
    if(n==0) return 0;
    if(n<=9) return 1;
    if(dp[n]!=-1) return dp[n];

    int minC=INT_MAX;int num=n;
    while(n>0){
        if(n%10!=0){
            minC=min(minC,removingDigit(dp,num-(n%10)));
        }
        n/=10;
    }
    return dp[num]=minC+1;
}


int main(){
    vector<int>dp(1000006,-1);
    int n;
    cin>>n;
    cout<<removingDigit(dp,n);
}