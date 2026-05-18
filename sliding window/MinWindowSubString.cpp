#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// 76. Minimum Window Substring
unordered_map<char,int>mp1,mp2;
bool check(){
    for(auto ele : mp1){
        if(mp2.find(ele.first)==mp2.end()) return false;
        else if(mp2[ele.first]<ele.second) return false;
    }
    return true;
}
string minWindow(string s, string t) {
    int i=0,j=0;
    int m=s.size();
    int n=t.size();
    int minS=INT_MAX;
    int x=-1,y=-1;
    for(auto ele : t){
        mp1[ele]++;
    }
    while(j<m){
        if(mp1.find(s[j])!=mp1.end()){
            mp2[s[j]]++;
        }
        bool flag=check();
        while(flag){
            if(mp1.find(s[i])!=mp1.end()){
                mp2[s[i]]--;
                if(mp2[s[i]]==0)mp2.erase(s[i]);
            }
            if(minS>(j-i+1)){
                minS=(j-i+1);
                x=i;
                y=j;
            }
            i++;
            flag=check();
        }
        j++;
    }
    if(x==-1 && y==-1) return "";
    string str="";
    for(int i=x;i<=y;i++){
        str.push_back(s[i]);
    }
    return str;
}

int main(){
    string str="aaaaaaaaaaaabbbbbcdd";
    string t="dabcd";
    cout<<minWindow(str,t);
}