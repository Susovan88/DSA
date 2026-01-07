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

int diceCom_booto_up(int n){
    dp.clear();
    dp.resize(1000006,0);
    dp[0]=1;

    // f(n)=f(n-1)+f(n-2)+...+f(n-6)
    for (int i = 1; i <= n; i++) {
        for (int dice = 1; dice <= 6; dice++) {
            if (i - dice >= 0) {
                dp[i] = (dp[i] + dp[i - dice]) % mod;
            }
        }
    }
    
    return dp[n];
}

int main(){
    dp.clear();
    dp.resize(1000006,-1);
    int n;
    cin>>n;
    cout<<diceCom(n);
}