#include <iostream>
#include <vector>
#include <cstring>   
#include <climits>  
using namespace std;


// https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1
class Solution {
  public: 
    int dp[1001][1001];
    int helper(vector<int>& val, vector<int>& wt, int cap,int i){
        if(i==val.size() || cap==0) return 0;
        if(dp[i][cap]!=-1) return dp[i][cap];
        if(cap<wt[i]) return dp[i][cap]=helper(val,wt,cap,i+1); // skip
        int ans=INT_MIN;
        ans=max(ans,val[i]+helper(val,wt,cap-wt[i],i)); // take any number of time 
        ans=max(ans,helper(val,wt,cap,i+1));  // skip 
        return dp[i][cap]=ans;
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        memset(dp,-1,sizeof dp);
        return helper(val,wt,capacity,0);
    }
};

int main(){
    Solution sol;
    vector<int>val={12,30,5,15,9,10,67,23};
    vector<int>wt={2,3,1,5,1,2,8,7};
    cout<<sol.knapSack(val,wt,100)<<endl;
}