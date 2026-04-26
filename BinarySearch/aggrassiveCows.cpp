#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/aggressive-cows/1
int aggressiveCows(vector<int> &stall, int k) {
    sort(stall.begin(),stall.end());
    int n=stall.size();
    int mn=INT_MAX;
    for(int i=0;i<n-1;i++){
        mn=min(mn,stall[i+1]-stall[i]);
    }
    int st=mn;
    int end=stall[n-1]-stall[0];
    int mx=0;

    while(st<=end){
        int mid=st+(end-st)/2;
        int dist=mid;
        int prev=stall[0];
        int c=1;
        for(int i=1;i<n;i++){
            if(c==k)break;
            if(stall[i]-prev >= dist){
                c++;
                prev=stall[i];
            }
        }
        // cout<<st<<" "<<mid<<" "<<end<<" "<<c<<endl;
        if(c==k){
            mx=max(mx,mid);
            st=mid+1;
        }else end=mid-1;
    }
    return mx;
}

int main(){
    vector<int>arr={10,2,4,17,9,1,41,7,19,20,3,5};
    int k=8;
    cout<<aggressiveCows(arr,k);
}