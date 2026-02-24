#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];
int lcs(string &s,string &t){
    int n=s.size(),m=t.size();

    //base case
    for(int i=0;i<=n;i++)dp[i][0]=0;
    for(int j=0;j<=m;j++)dp[0][j]=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];
}

int main(){
    string s1="abcbabdabadbstrab";
    string s2=s1;// reverse
    reverse(s2.begin(),s2.end());
    int LCS=lcs(s1,s2);
    cout<<"length of Palindrom - "<<LCS<<endl;

    // print the palindrom.... 
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
    cout<<"ans is - "<<ans;
}