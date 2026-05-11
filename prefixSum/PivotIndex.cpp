#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// 724. Find Pivot Index
int pivotIndex(vector<int>& nums) {
    int n=nums.size();
    vector<int>prefix(n);
    prefix[0]=nums[0];
    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+nums[i];
    }
    for(int i=0;i<n;i++){
        int leftS=prefix[i]-nums[i];
        int rightS=prefix[n-1]-prefix[i];
        if(leftS==rightS) return i;
    }
    return -1;
}

int main(){
    vector<int>arr={1,4,2,2,-1,6,9,-2,8,5,7,-9,-3,1,0,8};
    cout<<pivotIndex(arr);
}