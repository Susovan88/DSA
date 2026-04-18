#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// 205. Isomorphic Strings
bool isIsomorphic1(string s, string t) {
    int n=s.size();
    if(n!=t.size()) return false;
    vector<int>map(150,-1);
    
    for(int i=0;i<n;i++){
        int ascii=(int)s[i];
        if(map[ascii]!=-1){
            if(map[ascii]!=t[i]) return false;
        }
        else map[ascii]=(int)t[i];
    }

    for(int i=0;i<150;i++)map[i]=-1;

    for(int i=0;i<n;i++){
        int ascii=(int)t[i];
        if(map[ascii]!=-1){
            if(map[ascii]!=s[i]) return false;
        }
        else map[ascii]=(int)s[i];
    }
    return true;
}

bool isIsomorphic2(string s, string t) {
    int n=s.size();
    if(n!=t.size()) return false;
    unordered_set<char>st;// already mapped
    unordered_map<char,char>map;
    for(int i=0;i<n;i++){
        if(map.size()!=0 && map.find(t[i])!=map.end()){
            if(s[i]!=map[t[i]]) return false;
        }
        else{
            if(st.size()!=0 && st.find(s[i])!=st.end())return false;
            map[t[i]]=s[i];
            st.insert(s[i]);
        }
    }
    return true;
}


int main(){
    string str="paper";
    string tsr="title";
    cout<<"Isomorphic -> "<<(isIsomorphic1(str,tsr)==0?"False":"True");
}