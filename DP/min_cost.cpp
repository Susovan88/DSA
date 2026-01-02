#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// // 746. Min Cost Climbing Stairs

// normal recursion  o(2^n)
void helper(int &minC,vector<int>& cost,int idx,int c){
    if(idx>=cost.size()){
        minC=min(minC,c);
        return;
    }
    c+=cost[idx];
    helper(minC,cost,idx+1,c);
    helper(minC,cost,idx+2,c);
}
int minCostClimbingStairs1(vector<int>& cost) {
    int min1=INT_MAX,min2=INT_MAX;
    helper(min1,cost,0,0);
    helper(min1,cost,1,0);
    return min(min1,min2);
}

// DP -> top down  o(n) , o(n)
int help(vector<int>& cost,vector<int>&minCost,int idx){
    if(idx==0 || idx==1) return cost[idx];
    if(minCost[idx]!=-1) return minCost[idx];
    return minCost[idx]=cost[idx] + min(help(cost,minCost,idx-1),help(cost,minCost,idx-2));
}
int minCostClimbingStairs2(vector<int>& cost) {
    vector<int>minCost(cost.size(),-1); //dp -> min cost to reach ith stair.
    int n=cost.size();
    return min(help(cost,minCost,n-1),help(cost,minCost,n-2));
}

// dp -> bottom up  o(n)
int minCostClimbingStairs3(vector<int>& cost) {
    int n=cost.size();
    for(int i=2;i<n;i++){
        cost[i]=cost[i] + min(cost[i-1],cost[i-2]);
    }
    return min(cost[n-1],cost[n-2]);
}


int main() {
    vector<int> cost = {10,1,14,9,2,17,8,20,18,12,1,23,12,13,7,1,9,15,20};

    cout << "Recursion: " << minCostClimbingStairs1(cost) << endl;
    cout << "Top Down DP: " << minCostClimbingStairs2(cost) << endl;
    cout << "Bottom Up DP: " << minCostClimbingStairs3(cost) << endl;

    return 0;
}
