#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// // 169. Majority Element
// without using extra space
int majorityElement(vector<int>& arr) {
    int n=arr.size();
    int count=0;
    int val=arr[0];
    for(int i=0;i<n;i++){
        if(count==0){
            val=arr[i];
        }
        if(arr[i]==val)count++;
        else count--;
    }
    return val;
}

// using extra space 
int majorityElement1(vector<int>& nums) {
    unordered_map<int,int>mp;
    int n=nums.size();
    int mx=0;
    int val=0;
    for(int i=0;i<n;i++)mp[nums[i]]++;
    for(auto ele : mp){
        if(mx<=ele.second){
            mx=ele.second;
            val=ele.first;
        }
    }
    return val;
}


int main(){
    vector<int>arr={1,1,3,3,3,3,3,3,2,1,3,3,2,2,2,2,1,1,1,1,1,10,8,3};
    cout<<"majority Element is -> "<<majorityElement(arr);
}

