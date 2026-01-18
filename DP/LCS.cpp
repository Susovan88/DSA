#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// 1143. Longest Common Subsequence
class Solution {
public:
    vector<vector<int>>dp;
    // top down
    int helper(string &text1, string &text2,int idx1,int idx2){  // idx means -> 0 to idx substring 
    // dp[i][j] ->store  cout of LCS of text1(0 to i) and tet2(0 to j)
        if(idx1<0 || idx2<0) return 0;
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        if(text1[idx1]==text2[idx2]) return dp[idx1][idx2]=1+helper(text1,text2,idx1-1,idx2-1);
        else return dp[idx1][idx2]=max(helper(text1,text2,idx1-1,idx2),helper(text1,text2,idx1,idx2-1));
    }

    int helper2(string text1, string text2){ // bottom up
        int n=text1.size();
        int m=text2.size();
        // dp[i+1][j+1] ->store  cout of LCS of text1(0 to i) and tet2(0 to j)
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
        return helper(text1,text2,text1.size()-1,text2.size()-1);
    }
};


int main(){
    string s1="abcabdababstr";
    string s2="bababdstrsdfdasb";
    Solution sol=Solution();
    cout<<sol.longestCommonSubsequence(s1,s2)<<endl;
    cout<<sol.helper2(s1,s2);
}