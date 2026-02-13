#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// 1691
int n;
int dp[105];
int helper(vector<vector<int>>& cub,int curr){ 
    if(curr>=n) return 0;
    if(dp[curr]!=-1) return dp[curr];
    int maxL=0;
    for(int i=curr+1;i<n;i++){
        if(cub[curr][0]>=cub[i][0] && cub[curr][1]>=cub[i][1] && cub[curr][2]>=cub[i][2])
        maxL=max(maxL,helper(cub,i));
    }
    return dp[curr]=cub[curr][2]+maxL;
}
int maxHeight(vector<vector<int>>& cub) {
    n=cub.size();
    for(int i=0;i<n;i++){ // increasing order sort apply on each dimension of all cubs 
        sort(cub[i].begin(),cub[i].end());
    } 
    sort(cub.begin(), cub.end(), greater<vector<int>>()); // decreasing order sorting apply on cub
    memset(dp,-1,sizeof dp);
    int maxL=0;
    for(int i=0;i<n;i++){
        maxL=max(maxL,helper(cub,i));
    }
    return maxL;
}

int main() {
    vector<vector<int>> cub = {
        {50, 45, 20},
        {95, 37, 53},
        {45, 23, 12}
    };
    int result =maxHeight(cub);
    cout << "Maximum stack height = " << result << endl;

    return 0;
}