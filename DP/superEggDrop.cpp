#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// 887. Super Egg Drop
int dp[10002][104];
int f(int k, int n) {
    if(k==0 || n==0) return 0;
    if(k==1 || n==1) return n;
    if(dp[n][k]!=-1) return dp[n][k];
    int minC=INT_MAX;
    int low=1,high=n; // binary search
    while(low<=high){
        int mid=(low+high)/2;
        int isBreak=f(k-1,mid-1);
        int notBreak=f(k,n-mid);
        int temp=1+max(isBreak,notBreak); // worst case 
        minC=min(minC,temp); // min attemps...

        if(isBreak>notBreak)high=mid-1; // go down
        else low=mid+1; // go up
    }
    return dp[n][k]=minC;
}
int superEggDrop(int k, int n) {
    memset(dp,-1,sizeof dp);
    return f(k,n);
}

int main(){
    int k=5; // eggs...
    int n=13; // floors...

    cout<<superEggDrop(k,n);
}