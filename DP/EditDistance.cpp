#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;
# define ll long long int

//  72. Edit Distance
class Solution {
public:
    int dp[505][505];
    int helper(string &word1, string &word2,int ch1,int ch2){
        if(ch1==word1.size() && ch2==word2.size()) return 0;
        if(dp[ch1][ch2]!=-1) return dp[ch1][ch2];
        if(ch1==word1.size()) return word2.size()-ch2; // only insert
        if(ch2==word2.size()) return word1.size()-ch1; // only delete

        if(word1[ch1]==word2[ch2]) return helper(word1,word2,ch1+1,ch2+1); // same letter
        ll ans=INT_MAX;
        ans=min(ans,(ll)helper(word1,word2,ch1,ch2+1)+1); // insert
        ans=min(ans,(ll)helper(word1,word2,ch1+1,ch2)+1); // delete
        ans=min(ans,(ll)helper(word1,word2,ch1+1,ch2+1)+1); // replace 
        return dp[ch1][ch2]=ans;
    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof dp);
        return helper(word1,word2,0,0);
    }
};


int main(){
    string s1="intention";
    string s2="execution";
    Solution sol;
    cout<<sol.minDistance(s1,s2);
}