#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

int main(){ // 1 -> win state  0 -> loss state
    int k,l,m;
    cin>>k>>l>>m;
    vector<int>dp(1000005,0);
    // winning state
    dp[1]=1;
    dp[k]=1;
    dp[l]=1;
    
    for(int i=2;i<1000000;i++){
        if(i==l || i==k) continue;
        dp[i]=!(dp[i-1] && (i-k>=1? dp[i-k]:1) && (i-l>=1? dp[i-l]:1));
    }
    int n;
    for(int i=0;i<m;i++){
        cin>>n;
        if(dp[n]==1) cout<<"A win."<<endl;
        else cout<<"B Win."<<endl;
    }
    return 0;
}