#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
Use the XOR (^) operator to solve this problem efficiently. The key idea is that XOR of a number with itself is 0 (a ^ a = 0), 
and XOR with 0 gives the number itself (a ^ 0 = a). Since XOR is order-independent, all duplicate elements cancel each other out 
when we XOR the entire array, leaving only the single unique number as the final result.
*/

// 136. Single Number  -> using XOR operation 
int singleNumber(vector<int>& nums) {// TC- O(n), SC- O(1)
    int n=nums.size();
    if(n==1) return nums[0];
    int ans=0;
    for(auto ele : nums)ans^=ele;
    return ans;
}

int singleNumber2(vector<int>& nums) { // // TC- O(nlogn), SC- O(1)
    int n=nums.size();
    if(n==1) return nums[0];
    sort(nums.begin(),nums.end());
    int st=0;
    int end=n-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(mid==n-1 && nums[mid]!=nums[n-2]) return nums[mid];
        else if(mid==0 && nums[mid]!=nums[1]) return nums[mid];
        else if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]) return nums[mid];
        else if(mid%2==0){ // even
            if(nums[mid]==nums[mid-1]) end=mid-1;
            else st=mid+1;
        }else{  // odd
            if(nums[mid]==nums[mid-1])st=mid+1;
            else end=mid-1;
        }
    }
    return nums[st]; 
}


int main(){
    vector<int>arr={2,2,5,5,9,9,1,1,0,0,7,4,4,3,3,8,8};
    cout<<"single number is -> "<<singleNumber(arr);
}