#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1
int findPages(vector<int> &arr, int k) {
    int n=arr.size();
    if(k > n) return -1;
    int mx=INT_MIN;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        mx=max(mx,arr[i]);
    }
    int st=mx;
    int end=sum;
    int ans=INT_MAX;
    while(st<=end){
        int mid=st+(end-st)/2; // max pages
        int c=0;
        int pages=0;
        for(int i=0;i<n;i++){
            if(pages+arr[i]<=mid)pages+=arr[i];
            else{
                c++;
                pages=arr[i];
            }
        }
        c++;
        if(c<=k){
            ans=min(ans,mid);
            end=mid-1;
        }
        else st=mid+1;
    }
    return ans==INT_MAX? -1 : ans;
}

int main(){
    vector<int>arr={15, 10, 19, 10, 5, 18, 7};
    int k=5;
    cout<<findPages(arr,k);
}