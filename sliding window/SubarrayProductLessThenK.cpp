#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// 713. Subarray Product Less Than K
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if(k==0) return 0;
    int n=nums.size();
    int count=0;
    int pro=1;
    int i=0,j=0;
    while(j<n){
        pro*=nums[j];
        while(i<j && pro>=k){
            pro/=nums[i];
            i++;
        }
        if(pro<k)count+=(j-i+1);
        j++;
    }
    return count;
}

int main(){
    vector<int>arr={10,5,2,6,9,8,1,3};
    cout<<numSubarrayProductLessThanK(arr,100);
}