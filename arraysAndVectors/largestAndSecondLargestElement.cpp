#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int largestElemnt(vector<int>&arr){
    int n=arr.size();
    int mx=INT_MIN;
    for(int i=0;i<n;i++){
        mx=max(mx,arr[i]);
    }
    return mx;
}

int SecondLargestElemnt(vector<int>&arr){
    int n=arr.size();
    int mx1=INT_MIN;
    int mx2=INT_MIN;
    for(int i=0;i<n;i++){
        if(mx1<arr[i]){
            mx2=mx1;
            mx1=arr[i];
        }
        else if(mx2<arr[i] && mx1!=arr[i])mx2=arr[i];
    }
    if(mx2==INT_MIN) return -1;
    return mx2;
}


int main(){
    vector<int>arr={2,4,12,45,6,121,9,98,9,2,121,8,7,45,65,10};
    cout<<"largest element is -> "<<largestElemnt(arr)<<endl;
    cout<<"second largest element is -> "<<SecondLargestElemnt(arr)<<endl;
}
