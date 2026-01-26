#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

class Solution1 {  // best solution -> bottom up
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

class Solution2 {    // top down -> avg solution 
public:
    vector<vector<string>>dp; 
    int n,m;
    string LCS(string &str1, string &str2,int i,int j){
        if(i==n || j==m) return "";
        if( str1[i]==str2[j]) return dp[i][j]=str1[i]+LCS(str1,str2,i+1,j+1);
        if(dp[i][j]!="A") return dp[i][j];

        string op1=LCS(str1,str2,i+1,j); // option 1
        string op2=LCS(str1,str2,i,j+1); // option 2
        return dp[i][j]=""+(op1.size()>=op2.size()? op1:op2);
    }
    string shortestCommonSupersequence(string str1, string str2) {
        dp.clear();
        dp.resize(1001,vector<string>(1001,"A"));
        n=str1.size();
        m=str2.size();
        string lcs=LCS(str1,str2,0,0);
        string scs="";
        int i=0,j=0;
        for(char ch : lcs){
            while(i<n && str1[i]!=ch){ // take chars from str1 until LCS char
                scs.push_back(str1[i]);
                i++;
            }
            while(j<m && str2[j]!=ch){ // take chars from str2 until LCS char
                scs.push_back(str2[j]);
                j++;
            }
            scs.push_back(ch); // use LCS char one time
            i++;
            j++;
        }
        while(i<n)scs.push_back(str1[i++]);  // add remaning char of str1
        while(j<m)scs.push_back(str2[j++]); // add remaning char of str2
        return scs;
    }
};  


int main(){
    string s1="abcaa",s2="acabacaa";
    Solution1 sol;
    cout<<sol.shortestCommonSupersequence(s1,s2);
}