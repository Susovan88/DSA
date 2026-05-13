#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// 424. Longest Repeating Character Replacement
int characterReplacement(string s, int k) {
    unordered_map<char,int>fqr; // 0(26)
    int i=0,j=0;
    int n=s.size();
    int mxF=0;
    int mxL=0;
    while(j<n){
        fqr[s[j]]++;
        mxF=max(mxF,fqr[s[j]]);
        while((j-i+1)-mxF>k){
            fqr[s[i]]--;
            i++;
            for(auto ele : fqr){ // 26
                mxF=max(mxF,ele.second);
            }
        }
        if((j-i+1)-mxF<=k) mxL=max(mxL,j-i+1);
        j++;
    }
    return mxL;
}

int main(){
    string str="AAAABCBBCBBBBAAAABCBCAAAABCCCCD";
    int k=3;
    cout<<characterReplacement(str,k);
}