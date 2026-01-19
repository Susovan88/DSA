#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// https://www.hackerearth.com/problem/algorithm/mancunian-and-k-ordered-lcs-e6a4b8c6/

vector<vector<vector<int>>>dp;
int helper(vector<int> &text1, vector<int> &text2,int idx1,int idx2,int k){  // idx means -> 0 to idx substring  // back to front 
    // dp[i][j][k] ->store  count of LCS of text1(0 to i) and tet2(0 to j) and at most k element changes..
    if(idx1<0 || idx2<0) return 0;
    if(dp[idx1][idx2][k]!=-1) return dp[idx1][idx2][k];
    if(text1[idx1]==text2[idx2]) return dp[idx1][idx2][k]=1+helper(text1,text2,idx1-1,idx2-1,k);
    if(k>0){
        int op1=1+helper(text1,text2,idx1-1,idx2-1,k-1); // change element 
        int op2=max(helper(text1,text2,idx1-1,idx2,k),helper(text1,text2,idx1,idx2-1,k)); // not  change element 
        return dp[idx1][idx2][k]=max(op1,op2);
    }
    else return dp[idx1][idx2][k]=max(helper(text1,text2,idx1-1,idx2,k),helper(text1,text2,idx1,idx2-1,k)); // if k==0 
}

int MAKOLCS(vector<int> &text1, vector<int> &text2,int k){
    int n=text1.size();
    int m=text2.size();
    dp.clear();
    dp.resize(n+2,vector<vector<int>>(m+2,vector<int>(k+2,-1)));
    return helper(text1,text2,n-1,m-1,k);
}

int main() {
	int n,m,k;
	cin>>n>>m>>k;
	vector<int>arr1,arr2;
	int x;
	for(int i=0;i<n;i++){
		cin>>x;
		arr1.push_back(x);
	}
		for(int i=0;i<m;i++){
		cin>>x;
		arr2.push_back(x);
	}
	cout<<MAKOLCS(arr1,arr2,k);
}


