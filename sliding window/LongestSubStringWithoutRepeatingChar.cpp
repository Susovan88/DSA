#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// 3. Longest Substring Without Repeating Characters
int lengthOfLongestSubstring(string s) {
    int i=0;
    int j=0;
    int n=s.size();
    int mxL=0;
    unordered_set<char>st;
    if(n==0 || n==1) return n;
    while(j<n){
        if(st.size()==0 || st.find(s[j])==st.end()){
            st.insert(s[j]);
        }else{
            mxL=max(mxL,(int)st.size());
            while(s[i]!=s[j]){
                st.erase(s[i]);
                i++;
            }
            i++;
        }
        j++;
    }
    mxL=max(mxL,(int)st.size());
    return mxL;
}

int main(){
    string str="bbwbibgebekasdknnelkajwojgnmvniwbo";
    cout<<lengthOfLongestSubstring(str);
}