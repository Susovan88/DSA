#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>>dp; 
    int i,j;
    int LCS(string text1, string text2){ // bottom up
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
    string shortestCommonSupersequence(string str1, string str2) {
        i=str1.size();
        j=str2.size();
        string scs="";
        int lcs=LCS(str1,str2);
                while (i > 0 && j > 0) {
            if (str1[i-1] == str2[j-1]) {
                scs.push_back(str1[i-1]);
                i--; j--;
            } else if (dp[i-1][j] > dp[i][j-1]) {
                scs.push_back(str1[i-1]);
                i--;
            } else {
                scs.push_back(str2[j-1]);
                j--;
            }
        }

        while (i > 0) scs.push_back(str1[--i]);
        while (j > 0) scs.push_back(str2[--j]);

        reverse(scs.begin(), scs.end());
        return scs;
    }
};


int main(){
    string s1="abcaa",s2="acabacaa";
    Solution sol;
    cout<<sol.shortestCommonSupersequence(s1,s2);
}