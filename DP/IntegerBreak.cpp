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
    vector<int>dp;
    int helper(int n){
        if(n==1) return 1;
        if(dp[n]!=-1) return dp[n];

        int maxC=INT_MIN;
        int pro;
        for(int i=1;i<n;i++){
            pro=i* helper(n-i);
            maxC=max(maxC,pro);
        }
        maxC=max(maxC,n);
        return dp[n]=maxC;
    }
    
    int integerBreak(int n) {
        dp.clear();
        dp.resize(60,-1);
        int maxC=INT_MIN;
        for(int i=0;i<n;i++){
            maxC=max(maxC,i*helper(n-i));
        }
        return maxC;
    }
};

int main() {
    Solution sol;

    int n;
    cout << "Enter n: ";
    cin >> n;

    int result = sol.integerBreak(n);
    cout << "Maximum product after breaking " << n << " = " << result << endl;

    return 0;
}