#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Q.
// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive in sorted order.
//There is only one repeated number in nums, return this repeated number.
int OnlyOneRepeatedNumberInSortedArray(vector<int>& arr) {
    int n=arr.size();
    if(n==1) return -1;
    int st=0,end=n-1;
    int mid;
    while(st<=end){
        mid=st+(end-st)/2;
        if(arr[mid]==mid+1)st=mid+1;
        else end=mid-1;
    }
    return arr[st];
}

int main(){

    vector<int>arr={1,2,3,4,5,6,7,7,8,9,10};
    cout<<OnlyOneRepeatedNumberInSortedArray(arr);
}