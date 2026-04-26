#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// 1482. Minimum Number of Days to Make m Bouquets
int minDays(vector<int>& bloom, int m, int k) {
    int n=bloom.size();
    int mx=INT_MIN;
    for(int i=0;i<n;i++)mx=max(mx,bloom[i]);

    int st=1;
    int end=mx;
    int ans=INT_MAX;    
    while(st<=end){
        int mid=st+(end-st)/2; // days
        int c=0;
        int i=0;
        while(i<n){
            if(bloom[i]>mid){
                i++;
                continue;
            }
            int adj=0;
            while(i<n && bloom[i]<=mid){
                i++;
                adj++;
                if(adj==k)break;
            }
            if(adj==k)c++;
        }
        if(c>=m){
            end=mid-1;
            ans=min(ans,mid);
        }
        else st=mid+1;
    }
    return ans==INT_MAX? -1:ans;
}

int main(){
    vector<int>arr={1,10,3,10,2};
    int m=2;
    int k=1;
    cout<<minDays(arr,m,k);
}