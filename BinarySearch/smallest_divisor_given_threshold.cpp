#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// 1283. Find the Smallest Divisor Given a Threshold
int smallestDivisor(vector<int>& nums, int threshold) {
    int n=nums.size();
    int mx=0;
    for(int i=0;i<n;i++){
        mx=max(mx,nums[i]);
    }
    int mn=INT_MAX;
    int st=1;
    int end=mx;
    while(st<=end){
        int mid=st+(end-st)/2;
        int sum=0;
        for(int i=0;i<n;i++){
            int div=nums[i]/mid;
            if(nums[i] % mid!=0)div++;
            sum+=div;
            if(sum>threshold)break;
        }
        if(sum<=threshold){
            mn=min(mn,mid);
            end=mid-1;
        }
        if(sum>threshold)st=mid+1;
    }
    return mn;
}

int main() {
    vector<int> nums = {1, 2, 5, 9};
    int threshold = 6;

    int result = smallestDivisor(nums, threshold);
    cout << "Smallest Divisor: " << result << endl;

    return 0;
}