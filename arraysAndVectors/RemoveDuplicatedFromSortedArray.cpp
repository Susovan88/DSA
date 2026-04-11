#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// 26. Remove Duplicates from Sorted Array
int removeDuplicates(vector<int>& arr) {
    int curr=arr[0];
    int n=arr.size();
    int idx=0;
    int j=0;
    while(idx<n){
        arr[j]=curr;
        j++;
        while(idx<n && curr==arr[idx]) idx++;
        curr=arr[idx];
    }
    return j;
}

int main(){
    vector<int>arr={0,0,0,0,0,1,1,1,2,3,3,3,6,6,6,8,8,8,10,10,10,10,11,11,11,11,11,12,34,45,45,56,56,56,56,56};

    int k=removeDuplicates(arr);
    for(int i=0;i<k;i++){
        cout<<arr[i]<<" ";
    }
}