#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// 647. Palindromic Substrings
// 5. Longest Palindromic Substring

int dp[1002][1002];
int x,y;
int countSubstrings(string s) {
    memset(dp,0,sizeof dp);
    int n=s.size();
    int t=n; // how many digonal traversel need
    // 0 -> no palindrom exist from i to j
    // 1 -> palindrom exist from i to j

    // i==j  => only one char 
    // j=i+1 => 2 length string
    // dp[i+1][j-1] => if (j=i+1->false) check i-1 to j+1 string 
    int k=0;
    for(int t=0;t<n;t++){
        int i=0;
        int j=t;
        while(i<n-t && j<n){
            if(s[i]==s[j]){
                if(i==j || j==i+1 || dp[i+1][j-1]){
                    dp[i][j]=1;
                    k++;
                    x=i;y=j;
                }
                else dp[i][j]=0;
            }
            i++;
            j++;
        }
    }
    return k;
}

string longestPalindrome(string s) {
    int count=countSubstrings(s);
    cout<<"number of substring exist is - "<<count<<endl;
    string ans="";
    for(int i=x;i<=y;i++){
        ans.push_back(s[i]);
    }
    return ans;
}

int main(){
    string s2="abcabdbababdstr";
    cout<<"Longest palindromic substring is - "<<longestPalindrome(s2)<<endl;
}