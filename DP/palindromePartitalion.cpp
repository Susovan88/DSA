#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
#define mod 100
using namespace std;

// https://www.geeksforgeeks.org/problems/palindromic-patitioning4845/1

/*
Given a string s, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome.
 Determine the fewest cuts needed for palindrome partitioning of the given string.
*/
int n;
int dp[1001];
bool isPalindrom(string temp){
    int j=temp.size()-1;
    int i=0;
    while(i<=j){
        if(temp[i]!=temp[j]) return false;
        i++;
        j--;
    }
    return true;
}
int helper(int idx,string &s){
    if(idx==n)return 0;
    if(dp[idx]!=-1) return dp[idx];
    int ans=INT_MAX;
    string temp="";
    for(int i=idx;i<n;i++){
        temp.push_back(s[i]);
        if(isPalindrom(temp)){
            //  cout<<temp<<" "<<i<<" true"<<endl;
            ans=min(ans,1+helper(i+1,s));
        }
    }
    return dp[idx]=(ans==INT_MAX? 0:ans);
}
int palPartition(string &s) {
    n=s.size();
    memset(dp,-1,sizeof dp);
    int ans=helper(0,s);
    return ans!=0? ans-1:ans;
}

int main(){
    string str="ababbabazaabbaabb";
    cout<<palPartition(str);
}