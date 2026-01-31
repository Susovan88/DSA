#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
class Ans {
  public:
    int n;
    int dp[1003][1003];
    int helper(int &c, vector<int> &val, vector<int> &wt,int i,int w){
        if(i==val.size()) return 0;
        if(dp[i][w]!=-1) return dp[i][w];
        if(c<w+wt[i]) return dp[i][w]=helper(c,val,wt,i+1,w);
        
        int take=val[i]+helper(c,val,wt,i+1,w+wt[i]);
        int skip=helper(c,val,wt,i+1,w);
        return dp[i][w]=max(take,skip);
    }
    int knapsack(int c, vector<int> &val, vector<int> &wt) {
        n=val.size();
        memset(dp,-1,sizeof dp);
        return helper(c,val,wt,0,0);
    }
};


int main(){
    vector<int>val={12,3,45,7,13,9,10};
    vector<int>wt={2,34,12,3,12,9,6};
    Ans sol;
    cout<<sol.knapsack(20,val,wt);
}