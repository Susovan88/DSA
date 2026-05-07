#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// 287. Find the Duplicate Number
int findDuplicat1(vector<int>& nums) { // using slow fast algo
    int slow=nums[0];
    int fast=nums[0];
    do{
        slow=nums[slow]; //+1
        fast=nums[nums[fast]]; //+2
    }while(slow!=fast);

    slow=nums[0];
    while(slow!=fast){
        slow=nums[slow];
        fast=nums[fast];
    }
    return fast;
}
int findDuplicate2(vector<int>& nums) {
    unordered_set<int>st;
    for(int i=0;i<nums.size();i++){
        if(st.find(nums[i])!=st.end()) return nums[i];
        st.insert(nums[i]);
    }
    return -1;
}

int main(){
    vector<int>arr={1,3,4,5,7,9,2,10,3,3,6};
    cout<<findDuplicat1(arr);
}