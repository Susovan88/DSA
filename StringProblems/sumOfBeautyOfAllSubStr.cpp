#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// 1781. Sum of Beauty of All Substrings
int beautySum1(string s) {
    unordered_map<int,int>mp;
    int n=s.size();
    int mx=0,mn=n;
    int ans=0;
    for(int i=0;i<n;i++){
        vector<int>alp(30,0);
        mx=0;
        for(int j=i;j<n;j++){
            mn=n;
            int ascii=s[j]-97;
            alp[ascii]++;
            mx=max(mx,alp[ascii]);
            for(auto ele : alp){
                if(ele>0)mn=min(mn,ele);
            }
            ans+=(mx-mn);
        }
    }
    return ans;
}
int beautySum2(string s) {
    unordered_map<int,int>mp;
    int n=s.size();
    int mx=0,mn=n;
    int ans=0;
    for(int i=0;i<n;i++){
        unordered_map<char,int>fq;
        for(int j=i;j<n;j++){
            fq[s[j]]++;
            for(auto ele : fq){
                mx=max(mx,ele.second);
                mn=min(mn,ele.second);
            }
            cout<<s.substr(i,(j-i+1))<<" "<<mx<<" "<<mn<<" "<<mx-mn<<endl;
            ans+=(mx-mn);
            mx=0;mn=n;
        }
    }
    return ans;
}


int main(){
    string str="iamagoodboyandyoualso";
    cout<<"Sum of Beauty of All Substrings- "<<beautySum1(str)<<endl;
}