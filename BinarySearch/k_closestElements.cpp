#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// 658. Find K Closest Elements
int closestIdx(vector<int>&arr,int t){ // O(log n)
    int st=0,end=arr.size()-1,mid;
    int n=arr.size();
    while(st<=end){
        mid=st+(end-st)/2;
        if(arr[mid]==t) return mid;
        else if(arr[mid]>t)end=mid-1;
        else st=mid+1;
    }// when the loop is break then end=<st , so end always lower bound.
    if(end<0) return 0;
    if(st>n-1) return n-1;
    return end;
}
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int n=arr.size();
    int idx=closestIdx(arr,x);
    cout<<idx;
    vector<int>ans;
    int left,right;
    if(idx==0){
        left=0,right=1;
    }
    else if(idx==n-1){
        right=n-1;
        left=n-2;
    }
    else{
        left=idx;
        right=idx+1;
    }
    vector<int>lf,rg;
    while(k!=0){
        if(left>=0 && right<n){
            int difL=abs(arr[left]-x);
            int difR=abs(arr[right]-x);
            if(difL<=difR){
                lf.push_back(arr[left]);
                left--;
            }else{
                rg.push_back(arr[right]);
                right++;
            }
        }else if(left>=0){
            lf.push_back(arr[left]);
            left--;
        }else{
            rg.push_back(arr[right]);
            right++;
        }
        k--;
    }
    for(int i=lf.size()-1;i>=0;i--)ans.push_back(lf[i]);
    for(int i=0;i<rg.size();i++)ans.push_back(rg[i]);
    return ans;
}


int main(){
    vector<int> arr={4,6,11,12,18,30,33,34,45,65,67,89,99,100};
    vector<int>ans=findClosestElements(arr,4,28);
    for(auto ele : ans) cout<<ele<<" ";
}