#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// 852. Peak Index in a Mountain Array
int peakIndexInMountainArray(vector<int>& arr) {
    int st=0,end=arr.size()-1,mid=arr.size()-1;
    while(st<=end){
        mid=st+(end-st)/2;
        if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1]) return mid;
        else if(arr[mid]<arr[mid+1]) st=mid+1;
        else end=mid-1;
    }
    return mid;
}

// 33. Search in Rotated Sorted Array
int search(vector<int>& arr, int t) {
    int st=0,end=arr.size()-1,mid=-1;
    // // Hint => try to find that which part is sorted -> (st tp mid) or (mid+1 to end) -> then apply binary seacrh 
    while(st<=end){
        mid=st+(end-st)/2;
        if(arr[mid]==t) return mid;
        if(arr[st]<=arr[mid]){
            // sorted -> (st to mid)
            if(t>=arr[st] && t<arr[mid]) end=mid-1;
            else st=mid+1;
        }
        else{
            // sorted -> (mid+1 to end )
            if(t>arr[mid] && t<=arr[end]) st=mid+1;
            else end=mid-1;
        }
    }
    return -1;
}


int main(){
    vector<int> arr1 = {12,14,17,20,0,1,2,3,5,6,8,9,10};
    cout<<search(arr1,5)<<endl;
    vector<int> arr2 = {0,1,4,6,8,10,9,7,5,3,2};
    cout<<peakIndexInMountainArray(arr2)<<endl;
}