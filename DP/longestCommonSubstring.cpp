#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/longest-common-substring1452/1
int dp[1003][1003];
int longCommSubstr(string& s1, string& s2) {
    memset(dp,0,sizeof dp);
    int n=s1.size(),m=s2.size();
    int ans=0;
    int x,y;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
                if(ans<dp[i][j]){
                    ans=dp[i][j];
                    x=i;y=j;
                }
            }
        }
    }
    string substr="";
    while(dp[x][y]){
        substr.push_back(s1[x-1]);
        x--;y--;
    }
    reverse(substr.begin(),substr.end());
    cout<<"Longest common subsequence is -"<<substr<<endl;
    return ans;
}

int main(){
    string s1="abcabdbababdstr";
    string s2="bababdstrsdfdasb";
    cout<<"Longest common subsequence length is - "<<longCommSubstr(s1,s2)<<endl;
}