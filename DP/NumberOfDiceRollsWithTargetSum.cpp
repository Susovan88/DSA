#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
# define ll long long int
# define mod 1000000007
using namespace std;


class Solution {
public:
    vector<vector<ll>>dp;
    ll helper(int n,int &k,int t){
        if(n==0 & t==0) return 1;
        if(n==0 || t==0) return 0;
        if(dp[n][t]!=-1) return dp[n][t];

        ll sum=0;
        for(int i=1;i<=k;i++){
            if(t-i>=0){
                sum=(sum + helper(n-1,k,t-i)%mod )%mod;
            }
            else break;
        }
        return dp[n][t]=sum;
    }
    int numRollsToTarget(int n, int k, int target) {
        dp.clear();
        dp.resize(32,vector<ll>(1005,-1));
        return helper(n,k,target);
    }
};


int main() {

    int n, k, target;
    cin >> n >> k >> target;

    Solution sol;
    cout << sol.numRollsToTarget(n, k, target) << "\n";

    return 0;
}
