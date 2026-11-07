#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/count-substring/1
int countSubstring(string &s) {
    // Code here
    int n=s.size();
    unordered_map<int,int>mp;
    int count=0;
    int i=0,j=0;
    while(j<n && i<n){
        while(j<n && mp.size()!=3){
            mp[s[j]]++;
            j++;
        }
        while(i<j && mp.size()==3){
            count+=(n-j+1);
            mp[s[i]]--;
            if(mp[s[i]]==0)mp.erase(s[i]);
            i++;
        }
    }
    return count;
}