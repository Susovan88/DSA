#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// -> https://atcoder.jp/contests/dp/tasks/dp_c

int bottomUp(vector<vector<int>>&dp,int n){
    for(int i=1;i<n;i++){
        dp[i][0]=dp[i][0]+max(dp[i-1][1],dp[i-1][2]);
        dp[i][1]=dp[i][1]+max(dp[i-1][0],dp[i-1][2]);
        dp[i][2]=dp[i][2]+max(dp[i-1][0],dp[i-1][1]);
    }

    return max({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
}


int main(){
    int n;
    cin>>n;
    vector<vector<int>>arr(n,vector<int>(3,0));
    int a,b,c;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c;
        arr[i][0]=a;
        arr[i][1]=b;
        arr[i][2]=c;
    }

    cout<<bottomUp(arr,n);

}
