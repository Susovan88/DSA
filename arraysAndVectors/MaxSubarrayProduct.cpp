#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// 152. Maximum Product Subarray 
int maxProduct(vector<int>& nums) {
    int n=nums.size();
    int mx1=INT_MIN;
    int mx2=INT_MIN;
    int pro=1;

    // prefix Product
    for(int i=0;i<n;i++){
        if(pro==0){
            pro=1;
        }
        pro*=nums[i];
        mx1=max(mx1,pro);
    }
    pro=1;
    // sufix product
    for(int i=n-1;i>=0;i--){
        if(pro==0)pro=1;
        pro*=nums[i];
        mx2=max(mx2,pro);
    }
    return max(mx1,mx2);
}


int main() {
    vector<int> nums = {12, 3, -2, 4,0,3,4,-5,8,9,-1,2,-9,0,8,1};

    cout << maxProduct(nums) << endl;

    return 0;
}