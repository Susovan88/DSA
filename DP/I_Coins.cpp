#include<iostream>
#include<iomanip>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// https://atcoder.jp/contests/dp/tasks/dp_i
double dp[3000][2000];
double Icoins(int idx,int minH,vector<double>&p){
    if(minH==0) return 1.0;
    if(idx==p.size()) return 0.0;
    if(dp[idx][minH]>-0.1) return dp[idx][minH];

    return dp[idx][minH]=Icoins(idx+1,minH-1,p)*p[idx] + Icoins(idx+1,minH,p)*(1-p[idx]);
}

int main(){
    int n;
    cin>>n; // always odd
    vector<double>p(n);
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    memset(dp,-1,sizeof dp);
    int minH=(n+1)/2;// min 'H' need to get probability of getting more 'H' than 'T'.
    cout<<fixed<<setprecision(9)<<Icoins(0,minH,p);
}