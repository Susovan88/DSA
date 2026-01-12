#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// 714. Best Time to Buy and Sell Stock with Transaction Fee
class Solution {
public:
    vector<vector<int>>dp; // extra space -> O(2*n)
    int helper(vector<int>&prices,int &fee,int day,int buy){
        if(day>=prices.size()) return 0;
        if(dp[day][buy]!=-1) return dp[day][buy];

        int profit1=0,profit2=0;
        if(buy){
            profit1= helper(prices,fee,day+1,0) - prices[day]; // buy
            profit2= helper(prices,fee,day+1,1);   // skip
        }else{
            profit1=helper(prices,fee,day+1,1)+(prices[day]-fee);  // sell
            profit2=helper(prices,fee,day+1,0);   // skip
        }
        return dp[day][buy]=max(profit1,profit2);
    }
    int maxProfit(vector<int>& prices, int fee) {
        dp.clear();
        dp.resize(prices.size()+3,vector<int>(2,-1));
        return helper(prices,fee,0,true);
    }
};

int main() {
    Solution s;
    vector<int> prices = {1, 3, 2, 4, 8, 8, 4, 9};
    int fee = 2;

    cout << s.maxProfit(prices, fee) << endl;
    return 0;
}
