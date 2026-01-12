#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;


// https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
vector<vector<int>>dp;
int minMultiplicaton(int m,int n,vector<int>nums){
    if(n-m==1) return 0;
    if(dp[m][n]!=-1) return dp[m][n];

    int minM=INT_MAX;int cMul=0;
    for(int i=m+1;i<n;i++){
        int mul1=minMultiplicaton(m,i,nums);
        int mul2=minMultiplicaton(i,n,nums);
        cMul=mul1+mul2+(nums[m]*nums[i]*nums[n]);
        minM=min(minM,cMul);
    }
    return dp[m][n]=minM;
}
int minCostMultiplication(vector<int>arr){
    int n=arr.size();
    dp.clear();
    dp.resize(n+4,vector<int>(n,-1));

    return minMultiplicaton(0,n-1,arr);
}



// bottom up
int minCostMultiplication2(vector<int>arr){
    int n=arr.size();
    dp.clear();
    dp.resize(n+4,vector<int>(n,0));

    for(int len=3;len<=n;len++){  // length ->3 , 4, 5.... n
        for(int i=0;i+len-1<n;i++){
            int j=i+len-1;
            dp[i][j]=INT_MAX;
            for(int k=i+1;k<j;k++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+arr[i]*arr[k]*arr[j]);
            }
        }
    }

    return dp[0][n-1];
}


int main(){
    vector<int>arr={40,20,30,10,30,20,50,10};
    cout<<" min cost - "<<minCostMultiplication(arr)<<endl;
    cout<<" min cost - "<<minCostMultiplication2(arr);
}