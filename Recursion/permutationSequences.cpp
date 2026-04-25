#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// 60. Permutation Sequence
int dp[10];
int fact(int n){
    if(n==0 || n==1) return 1;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=n*fact(n-1);
}
string helper(int &k,string &temp,string str){ // optimized
    int n=str.size();
    if(n==0){
        // cout<<temp<<" ";
        return temp;
    }
    int idx=0;
    int comb=fact(n-1);
    while(k>comb){
        idx++;
        k-=comb;
    }
    string subS=str.substr(0,idx)+str.substr(idx+1);
    cout<<idx<<" "<<k<<" "<<str[idx]<<" "<<subS<<endl;
    temp.push_back(str[idx]);
    return helper(k,temp,subS);
}
string getPermutation1(int n, int k) {
    memset(dp,-1,sizeof dp);
    char ch='1';
    string str="";
    string temp="";
    for(int i=0;i<n;i++){
        str.push_back(ch);
        ch++;
    } 
    return helper(k,temp,str);
}
/*
To find the k-th permutation, think of the sequence as divided into groups where each group has the same starting digit and contains (n-1)! permutations.
 First convert k to 0-based indexing by subtracting 1. Then at each step, determine which group your k falls into by dividing k by (n-1)! to get the index of the next digit.
 Append that digit to your answer, remove it from the available digits, and update k using modulo with (n-1)!. Repeat this process until all digits are used.
*/


// Time Limit Exceeded
vector<string>ans;
void helper2(int &n,string &temp,string str){
    if(temp.size()==n){
        cout<<temp<<" ";
        ans.push_back(temp);
        return;
    }
    for(int i=0;i<str.size();i++){
        temp.push_back(str[i]);
        string s=str.substr(0,i)+str.substr(i+1);
        helper2(n,temp,s);
        temp.pop_back();
    }
}
string getPermutation2(int n, int k) {
    char ch='1';
    string str="";
    string temp="";
    for(int i=0;i<n;i++){
        str.push_back(ch);
        ch++;
    }
    helper2(n,temp,str);
    return ans[k-1];
}

int main(){
    int n=9;
    int k=100;
    cout<<"kth Permutation Sequence-> "<<getPermutation1(n,k)<<endl;
}