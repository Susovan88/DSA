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

// 1614. Maximum Nesting Depth of the Parentheses
int maxDepth(string s) {
    int i=0;
    int n=s.size();
    int fb=0;
    int mx=0;
    char prev='*';
    while(i<n){
        if(s[i]=='('){
            fb++;
            prev='(';
            mx=max(mx,fb);
        }else if(s[i]==')'){
            fb--;
            prev='*';
        }
        i++;
    }
    return mx;
}


int main(){
    string str="(()())(())(()(()))";
    cout<<removeOuterParentheses(str)<<endl;
    string p="(1)+((2))+(((3)))";
    cout<<maxDepth(p)<<endl;
}