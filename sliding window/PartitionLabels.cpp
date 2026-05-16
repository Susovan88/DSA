#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// 763. Partition Labels
vector<int> partitionLabels123(string s) {
    unordered_map<char,int>mp;
    int n=s.size();
    vector<int>ans;
    // // track the last index of every char;
    for(int i=0;i<n;i++)mp[s[i]]=i; 
    int j=0;
    int i=0;
    int mxIdx=-1;
    while(j<n){
        mxIdx=max(mxIdx,mp[s[j]]);
        if(mxIdx==j){
            ans.push_back(j-i+1);
            i=j+1;
            mxIdx=-1;
        }
        j++;
    }
    return ans;
}

vector<int> partitionLabels321(string s) {
    unordered_map<char,int>mp;
    unordered_map<char,int>tp;
    int n=s.size();
    vector<int>ans;
    for(auto ele: s)mp[ele]++;
    int j=0;
    int i=0;
    while(j<n){
        tp[s[j]]++;
        bool flag=true;
        for(auto ele:tp){
            if(ele.second!=mp[ele.first]){
                flag=false;
                break;
            }
        }
        if(flag){
            ans.push_back(j-i+1);
            while(i<=j){
                tp[s[i]]--;
                if(tp[s[i]]==0)tp.erase(s[i]);
                i++;
            }
        }
        j++;
    }
    return ans;
}

int main(){
    string str="ababcbacadefegdehijhklijxxyxxz";
    vector<int>ans=partitionLabels123(str);
    for(auto ele : ans)cout<<ele<<" ";
}
