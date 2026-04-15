#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// 128. Longest Consecutive Sequence
int longestConsecutive(vector<int>& nums) {  // TC-> O(n), SC-> O(n)
    int n=nums.size();
    if(n==0) return n;
    int mx=0;
    unordered_set<int>st;
    for(auto ele : nums)st.insert(ele);
    for(auto ele : st){
        int x=ele-1;
        int count=0;
        while(st.find(x)!=st.end()){
            st.erase(x);
            count++;
            x--;
        }
        x=ele+1;
        while(st.find(x)!=st.end()){
            st.erase(x);
            count++;
            x++;
        }
        mx=max(mx,count+1);
    }
    return mx;
}

int longestConsecutive1(vector<int>& nums) { // TC-> O(nlogn), SC-> O(1)
    int n=nums.size();
    if(n==0) return n;
    int count=0;
    int mx=0;
    sort(nums.begin(),nums.end());
    for(int i=0;i<n-1;i++){
        if(nums[i]+1==nums[i+1])count++;
        else if (nums[i]==nums[i+1])continue;
        else{
            mx=max(mx,count+1);
            count=0;
        }
    }
    mx=max(mx,count+1);
    return mx;
}

int main(){
    vector<int>arr={0,0,9,8,11,2,13,7,6,15,5,5,4,4,8,3,1,14};
    cout<<"Longest Consecutive Sequence -> "<<longestConsecutive(arr);
}