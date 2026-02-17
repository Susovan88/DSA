#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// check any attack prossible or not...
bool anyAttack(vector<string>&temp,int &x,int &y,int &n){
    for(int i=x-1,j=y-1;i>=0 && j>=0;i--,j--){
        if(temp[i][j]=='Q') return true;
    }
    for(int i=0;i<x;i++){
        if(temp[i][y]=='Q') return true;
    }
    for(int i=x-1,j=y+1;i>=0 && j<n;i--,j++){
        if(temp[i][j]=='Q') return true;
    }
    return false;
}
vector<vector<string>>ans;// store all prossible combinations...
void helper(int i,vector<string>&temp,int &n){
    if(i==n){
        ans.push_back(temp);
        return;
    }
    for(int j=0;j<n;j++){
        if(anyAttack(temp,i,j,n)) continue;
        temp[i][j]='Q';
        helper(i+1,temp,n);
        temp[i][j]='.';
    }
    return;
}
vector<vector<string>> solveNQueens(int n) {
    vector<string>temp(n,string(n,'.'));
    helper(0,temp,n);
    return ans;
}

int main(){
    int n=6;
    vector<vector<string>> ans=solveNQueens(n);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}