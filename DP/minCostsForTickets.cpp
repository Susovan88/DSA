#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// 983. Minimum Cost For Tickets
class Solution {
public:
    int dp[370][400];
    int helper(int d,int lastP,vector<int>& days, vector<int>& costs){
        if(d==days.size()) return 0;
        if(dp[d][lastP]!=-1) return dp[d][lastP];
        if(lastP<days[d]){ // there is no remaining days....
            int ans=INT_MAX;
            ans=min(ans,costs[0]+helper(d+1,days[d]+0,days,costs)); // 1 day pass
            ans=min(ans,costs[1]+helper(d+1,days[d]+6,days,costs)); // 7 day pass
            ans=min(ans,costs[2]+helper(d+1,days[d]+29,days,costs)); // 30 day pass
            return dp[d][lastP]=ans;
        }
        return dp[d][lastP]=helper(d+1,lastP,days,costs); // lastP >= days[d]
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof dp);
        return helper(0,0,days,costs);
    }
};


int main(){
    vector<int>days={2,4,6,7,9,12,56,89,90,99,100};
    vector<int>costs={12,34,90};
    Solution sol;

    cout<<sol.mincostTickets(days,costs);

}

