#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// 1358. Number of Substrings Containing All Three Characters
int numberOfSubstrings(string s) {
    unordered_map<char,int>st;
    int n=s.size();
    int i=0,j=0;
    int count=0;
    while(j<n){
        st[s[j]]++;
        while(st.size()==3){
            st[s[i]]--;
            if(st[s[i]]==0)st.erase(s[i]);
            count+=(n-j);
            i++;
        }
        j++;
    }
    return count;
}

int main(){
    string str="abbababababcbacacacacabababcbcbaaa";
    cout<<numberOfSubstrings(str);
}