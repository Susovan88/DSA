#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// 75. Sort Colors
void sortColors(vector<int>& arr) {
    int n=arr.size();
    int st=0,mid=0,end=n-1;
    while(mid<=end){
        if(arr[mid]==0){
            swap(arr[st],arr[mid]);
            st++;
            mid++;
        }else if(arr[mid]==2){
            swap(arr[mid],arr[end]);
            end--;
        }
        else mid++;
    }
}

void sortColors1(vector<int>& nums) {
    int n=nums.size();
    int n0=0,n1=0,n2=0;
    for(int i=0;i<n;i++){
        if(nums[i]==0) n0++;
        else if(nums[i]==1) n1++;
        else n2++;
    }
    for(int i=0;i<n;i++){
        if(i<n0) nums[i]=0;
        else if(i<(n0+n1)) nums[i]=1;
        else nums[i]=2;
    }
}

int main(){
    vector<int>arr={2,2,2,1,0,2,0,1,2,1,1,2,0,0,1,0,2,1,1,1,0,0,0};
    sortColors(arr);
    for(auto ele : arr){
        cout<<ele<<" ";
    }
}