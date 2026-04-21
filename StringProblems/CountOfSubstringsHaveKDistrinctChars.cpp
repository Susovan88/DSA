#include<iostream>
#include <bits/stdc++.h>
using namespace std;

//Substrings with K Distinct
/*
You are given a string s consisting of lowercase characters and an integer k,
You have to count all possible substrings that have exactly k distinct characters.
*/
int countSubstrlessTahnEqualToK(string& s, int k) {
    if(k==0) return 0;
    int n=s.size();
    unordered_map<char,int>fq;
    int i=0,j=0;
    int c1=0; // count of  substrings that have <=k distinct
    while(i<n && j<n){
        fq[s[j]]++;
        while(i<j && fq.size()>k){
            fq[s[i]]--;
            if(fq[s[i]]==0)fq.erase(s[i]);
            i++;
        }
        if(fq.size()<=k){
            c1+=(j-i+1);
        }
        j++;
    }
    return c1;
}
int countSubstr(string& s, int k) {
    unordered_map<char,int>fq;
    int i=0,j=0;
    int c1=countSubstrlessTahnEqualToK(s,k); // count of  substrings that have <=k distinct
    int c2=countSubstrlessTahnEqualToK(s,k-1); // count of  substrings that have <=k-1 distinct
    return c1-c2;
}

int main(){
    string str="abcaaabcaduqddus";
    int k=4;
    int count=countSubstr(str,k);
    cout<<count;
}