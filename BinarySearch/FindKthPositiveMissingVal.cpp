#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// 1539. Kth Missing Positive Number
int findKthPositive(vector<int>& arr, int k) {
    int n=arr.size();
    int st=0;
    int end=n-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        int tm=arr[mid]-(mid+1);  // total missing vals
        if(k>tm)st=mid+1;
        else end=mid-1;
    }
    return st+k;
}

int main(){
    vector<int>arr={2,4,6,8,10,17,21,30};
    cout<<findKthPositive(arr,10);
}