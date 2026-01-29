#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// 139 word break
class Solution {
public:
    int dp[305];
    bool helper(int idx,string &s, vector<string>& wordDict){
        if(idx>=s.size()) return true;
        if(dp[idx]!=-1) return dp[idx];

        for(int i=0;i<wordDict.size();i++){
            if(wordDict[i][0]==s[idx]){
                int x=idx;
                for(char ch : wordDict[i]){
                    if(ch!=s[x])break;
                    x++;
                }
                if(x-idx==wordDict[i].size() && helper(x,s,wordDict)) return dp[idx]=true;
            }
        }
        return dp[idx]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp,-1,sizeof dp);
        return helper(0,s,wordDict);
    }
};

int main(){
    string s="applepenapple";
    vector<string>wordDict={"apple","pen"};
    Solution sol;
    cout<<sol.wordBreak(s,wordDict);
}