#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

vector<int>dp;
int helper(int n){
    if(n==0) return 1;
    if(n==1 || n==2) return n;
    if(dp[n]!=-1) return dp[n];
    int count=0;
    for(int i=1;i<=n;i++){ // give chance to every node to become a root node
        int leftC=helper(i-1); // total ways o get unque left BST 
        int rightC=helper(n-i); // total ways o get unque right BST 
        count+=(rightC*leftC);    
    }
    return dp[n]=count;
}
int numTrees(int n) {  // top down
    dp.clear();
    dp.resize(n+10,-1);
    return helper(n);
}

int numTreesBottomUp(int n) { // bottom up
    if(n==1) return 1;
    vector<int>dp(n+1,0);
    dp[0]=1;dp[1]=1;dp[2]=2;
    for(int len=3;len<=n;len++){
        for(int i=1;i<=len;i++){
            dp[len]+=(dp[i-1]*dp[len-i]);
        }
    }
    return dp[n];
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Number of Unique BSTs (Top-Down): " << numTrees(n) << endl;
    cout << "Number of Unique BSTs (Bottom-Up): " << numTreesBottomUp(n) << endl;

    return 0;
}
