#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// 2182. Construct String With Repeat Limit
string repeatLimitedString(string s, int limit) {
    unordered_map<char,int>mp;
    for(char ch : s)mp[ch]++;
    priority_queue<pair<char,int>>pq; // max heap lexicographically largest
    for(auto ele : mp)pq.push(ele);

    string ans="";
    pair<char,int>temp;
    pair<char,int>next;
    while(pq.size()!=0){
        temp=pq.top();pq.pop();
        int mxL=min(temp.second,limit);
        for(int i=0;i<mxL;i++) ans.push_back(temp.first);

        if(temp.second-mxL>0){
            if(pq.size()!=0){
                next=pq.top();pq.pop();
                ans.push_back(next.first);
                if(next.second>1)pq.push({next.first,next.second-1});
            }else return ans;
            pq.push({temp.first,temp.second-mxL});
        }
    }
    return ans;
}


int main(){
    string s="qqwertqwewqerterweqwreqwyuzaamklma";
    int limit=5;
    cout<<repeatLimitedString(s,limit);
}