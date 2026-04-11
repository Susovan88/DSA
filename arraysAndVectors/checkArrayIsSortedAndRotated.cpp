#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// 1752. Check if Array Is Sorted and Rotated
bool Check(vector<int>& arr) {
    int n=arr.size();
    int bk=0;// count breaks...
    for(int i=0;i<n;i++){
        if(arr[i]>arr[(i+1)%n])bk++;
    }
    return bk<=1? true:false;
}

bool check2(vector<int>& arr) {
    int n=arr.size();
    int rIdx=0; // first indx of rotated part 
    while(rIdx!=n-1 && arr[rIdx]<=arr[rIdx+1])rIdx++;
    int mx=INT_MIN;
    for(int i=rIdx+1;i<n;i++){
        if(arr[i]>=mx)mx=arr[i];
        else return false;
    }
    for(int i=0;i<=rIdx;i++){
        if(arr[i]>=mx)mx=arr[i];
        else return false;
    }
    return true;
}

bool check3(vector<int>& arr) {
    int n=arr.size();
    int mx=INT_MIN,mn=INT_MAX;
    int idx=-1;
    for(int i=0;i<n;i++){
        if(mx<=arr[i]){
            mx=arr[i];
            mn=min(mn,arr[i]);
        }
        else{
            idx=i;
            break;
        }
    }
    if(idx==-1)return true;

    mx=INT_MIN;
    for(int i=idx;i<n;i++){
        if(arr[i]>=mx && arr[i]<=mn)mx=arr[i];
        else return false;
    }
    return true;
}

int main(){
    vector<int>arr={3,4,5,1,2};
    cout<<check2(arr)<<" "<<check3(arr)<<" "<<Check(arr);
}