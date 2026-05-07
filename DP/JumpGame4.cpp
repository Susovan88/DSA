#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// 1340. Jump Game V
int dp[1005];
bool visited[1005];
int n;
int helper(vector<int>& arr, int &d,int idx){
    if(visited[idx]) return 0;
    if(dp[idx]!=-1) return dp[idx];
    int i=idx-1;
    int mxC=0;
    visited[idx]=true;
    while(i>=0 && i>=idx-d){
        if(arr[idx]>arr[i]){
            mxC=max(mxC,1+helper(arr,d,i));
        }else break;
        i--;
    }
    i=idx+1;
    while(i<n && i<=idx+d){
        if(arr[idx]>arr[i]){
            mxC=max(mxC,1+helper(arr,d,i));
        }else break;
        i++;
    }
    visited[idx]=false;
    return dp[idx]=mxC;
}
int maxJumps(vector<int>& arr, int d) {
    n=arr.size();
    memset(dp,-1,sizeof dp);
    memset(visited,false,sizeof visited);
    int mxC=-1;
    for(int i=0;i<n;i++){
        int c=helper(arr,d,i);
        mxC=max(mxC,c);
    }
    return mxC+1;
}

int main(){
    vector<int>arr={6,4,14,6,8,13,9,7,10,6,12};
    int d=3;
    cout<<maxJumps(arr,d);
}