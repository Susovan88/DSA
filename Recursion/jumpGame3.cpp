#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// 1306. Jump Game III
bool helper(vector<int>& arr,int idx,vector<bool>&visited){
    if(visited[idx]) return false;
    if(arr[idx]==0) return true;
    visited[idx]=true;
    int x=arr[idx];
    int i=idx-x;
    if(i>=0 && helper(arr,i,visited)) return true;
    i=idx+x;
    if(i<arr.size() && helper(arr,i,visited)) return true;
    return false;
}
bool canReach(vector<int>& arr, int start){
    int n=arr.size();
    vector<bool>visited(n,false);
    return helper(arr,start,visited);
}

int main(){
    vector<int>arr={1,3,6,9,0,12,5,7,1,3,6,5,0,8,1,3,8,5,2,1,9};
    int st=6;
    cout<<canReach(arr,st);
}