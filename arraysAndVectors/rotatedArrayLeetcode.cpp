#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// // 189. Rotate Array
// using extra space 
void rotate(vector<int>& nums, int k) {
    int n=nums.size();
    if(n==1) return;
    if(k>n){
        if(k%n==0)k=n;
        else k=k%n;
    }
    vector<int>arr(nums.begin(),nums.end());
    int x=n-k;
    int j=0;
    while(x<n){
        nums[j++]=arr[x++];
    }
    x=n-k;
    for(int i=0;i<x;i++)nums[j++]=arr[i];
}

// without using extra space 
void rotate1(vector<int>& nums, int k) { //k=3
    int n=nums.size(); // -> 1,2,3,4,5,6,7
    k=k%n;
    reverse(nums.begin(),nums.end()); //-> 7 6 5  || 4 3 2 1
    reverse(nums.begin(),nums.begin()+k); // reverse first part-> 5 6 7 || 4 3 2 1
    reverse(nums.begin()+k,nums.end());   // reverse second part-> 5 6 7 1 2 3 4
}


int main(){
    vector<int>arr={ 1,2,3,4,5,6,7};
    rotate1(arr,3);
    for(auto ele :arr)cout<<ele<<" ";
}

