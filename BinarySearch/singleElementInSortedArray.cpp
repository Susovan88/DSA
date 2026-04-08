#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// 540. Single Element in a Sorted Array
int singleNonDuplicate(vector<int>& arr) {
    int n=arr.size();
    if(n%2==0) return -1;
    if(n==1) return arr[0];
    int st=0,end=n-1;
    int mid,ln;
    while(st<=end){
        mid=st+(end-st)/2;
        // cout<<st<<" - "<<end<<" => "<<mid<<" - "<<arr[mid]<<endl;
        if(mid==0 && arr[0]!=arr[1]) return arr[mid];
        if(mid==n-1 && arr[n-1]!=arr[n-2]) return arr[mid];
        if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1]) return arr[mid];
        else if(mid%2==0){ // left and right both even 
            if(arr[mid]==arr[mid-1])end=mid-1;
            else st=mid+1;
        }else{ // left and right both odd
            if(arr[mid]==arr[mid-1])st=mid+1;
            else end=mid-1;
        }
    }
    return -1;
}

int main(){

    vector<int>arr={1,1,2,2,4,4,5,5,7,8,8,9,9,10,10};
    cout<<singleNonDuplicate(arr);
}