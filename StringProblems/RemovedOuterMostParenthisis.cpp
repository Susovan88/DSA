#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// 1021. Remove Outermost Parentheses
string removeOuterParentheses(string s) {
    int n=s.size();
    string ans="";
    int i=0;
    while(i<n){
        int j=i+1;
        int fb=1,cb=0;
        while(j<n && fb!=cb){
            ans.push_back(s[j]);
            if(s[j]=='(')fb++;
            else cb++;
            j++;
        }
        ans.pop_back();
        i=j;
    }
    return ans;
}


int main(){
    string str="(()())(())(()(()))";
    cout<<removeOuterParentheses(str);
}