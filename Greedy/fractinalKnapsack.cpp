#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

bool cmd(pair<int,int>p1,pair<int,int>p2){
    double r1=p1.first*1.0/p1.second*1.0;
    double r2=p2.first*1.0/p2.second*1.0;
    return r1>r2;
}

int fractinalKnapsack(int w,vector<int>wt,vector<int>val){
    int n=wt.size();
    vector<pair<int,int>>arr;
    for(int i=0;i<n;i++){
        arr.push_back({val[i],wt[i]});
    }
    sort(arr.begin(),arr.end(),cmd); // custom sort the array base on (val/wt)

    int i=0;int profit=0;
    while(w!=0 && i<n){
        if(arr[i].second <= w){
            profit+=arr[i].first;
            w-=arr[i].second;
            i++;
        }else{
            profit+=(arr[i].first*1.0/arr[i].second*1.0)*w;
            w=0;
        }
    }
    return profit;
}

int main(){
    vector<int>wt={12,3,9,8,11,12,44,22,19,23,62};
    vector<int>val={102,300,90,801,111,122,214,120,19,203,102};
    int w=100;
    cout<<fractinalKnapsack(w,wt,val);
}