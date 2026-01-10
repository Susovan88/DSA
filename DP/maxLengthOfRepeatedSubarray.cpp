#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

//  Maximum Length of Repeated Subarray - 718
class Solution {
public:
    vector<vector<int>>dp;
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        dp.clear();
        dp.resize(1005,vector<int>(1005,0));
        int maxL=INT_MIN;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    dp[i][j]=1;
                    if(i!=0 && j!=0 && dp[i-1][j-1]!=0) dp[i][j]+=dp[i-1][j-1];
                    maxL=max(maxL,dp[i][j]);
                }
            }
        }

        return maxL==INT_MIN? 0 : maxL;
    }
};


int main() {
    int n, m;
    cin >> n >> m;

    vector<int> nums1(n), nums2(m);

    for (int i = 0; i < n; i++) {
        cin >> nums1[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> nums2[i];
    }

    Solution sol;
    cout << sol.findLength(nums1, nums2) << endl;

    return 0;
}
