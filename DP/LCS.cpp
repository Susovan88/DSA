#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// 1143. Longest Common Subsequence
vector<vector<int>>dp;
// top down
int helper(string &text1, string &text2,int idx1,int idx2){  // idx means -> 0 to idx substring 
// dp[i][j] ->store  count of LCS of text1(0 to i) and tet2(0 to j)
    if(idx1<0 || idx2<0) return 0;
    if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
    if(text1[idx1]==text2[idx2]) return dp[idx1][idx2]=1+helper(text1,text2,idx1-1,idx2-1);
    else return dp[idx1][idx2]=max(helper(text1,text2,idx1-1,idx2),helper(text1,text2,idx1,idx2-1));
}

int helper2(string text1, string text2){ // bottom up
    int n=text1.size();
    int m=text2.size();
    // dp[i+1][j+1] ->store  count of LCS of text1(0 to i) and tet2(0 to j)
    dp.clear();
    dp.resize(1003,vector<int>(1003,0));
    // base case
    for(int j=0;j<=m;j++) dp[0][j]=0;
    for(int i=0;i<=n;i++) dp[i][0]=0;

    for(int i=1;i<=n;i++){
        for(int j=1; j<=m;j++){
            if(text1[i-1]==text2[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];
}

int longestCommonSubsequence(string text1, string text2) {
    dp.clear();
    dp.resize(1000,vector<int>(1000,-1));  
    return helper2(text1,text2);
}



int main(){
    string s1="abcabdababstr";
    string s2="bababdstrsdfdasb";
    cout<<"LCS length is - "<<longestCommonSubsequence(s1,s2)<<endl;

    // print the palindrom.... using dp
    int i=s1.size(),j=s2.size();
    string ans="";
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            ans.push_back(s1[i-1]);
            i--;j--;
        }else{
            if(dp[i][j]==dp[i-1][j]){
                i--;
            }else j--;
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<"LCS is - "<<ans;
}