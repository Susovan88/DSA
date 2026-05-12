#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// 1004. Max Consecutive Ones III
int longestOnes(vector<int>& nums, int k) {
    int n=nums.size();
    int i=0,j=0;
    int mxL=0;
    int flip=0;
    while(j<n){
        if(nums[j])j++;
        else if(flip<k){
            flip++;
            j++;
        }
        else{
            mxL=max(mxL,j-i);
            while(nums[i])i++; // first zero 
            i++;
            j++;
        }
    }
    mxL=max(mxL,j-i);
    return mxL;
}

int main(){
    vector<int>arr={1,1,1,0,0,0,1,1,1,1,0,1,1,1,1,1,0,1,1,};
    int k=3;
    cout<<longestOnes(arr,k);

}