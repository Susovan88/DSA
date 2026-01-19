#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[1005][103][2];

    int helper(vector<int>& prices, int day, int t, int isBuy) {
        if (day >= prices.size()) return 0;
        if (dp[day][t][isBuy] != -1) return dp[day][t][isBuy];

        int ans = helper(prices, day + 1, t, isBuy); // skip
        if (isBuy) {
            // sell
            ans = max(ans, prices[day] + helper(prices, day + 1, t - 1, 0));
        } else {
            if (t > 0) {
                // buy
                ans = max(ans, helper(prices, day + 1, t, 1) - prices[day]);
            }
        }
        return dp[day][t][isBuy] = ans;
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp, -1, sizeof dp);
        return helper(prices, 0, k, 0);
    }
};

int main() {
    Solution sol;
    int k;
    cin >> k;
    int n;
    cin >> n;

    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        cin>> prices[i];
    }
    cout<< sol.maxProfit(k, prices) << endl;

    return 0;
}