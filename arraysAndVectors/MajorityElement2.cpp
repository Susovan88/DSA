#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// 229. Majority Element II 
vector<int>majorityElement1(vector<int>& nums) { // without using extra space // using votting algorithom
    int n=nums.size(); // [1,2,3,1,2,1,1]
    int c1=0,c2=0;
    int el1,el2;
    for(int i=0;i<n;i++){
        if(c1==0 && el2!=nums[i])el1=nums[i];
        else if(c2==0 && el1!=nums[i])el2=nums[i];
        if(el1==nums[i])c1++;
        else if(el2==nums[i])c2++;
        else{
            c1--;
            c2--;
        }
    }
    c2=0;
    c1=0;
    for(int i=0;i<n;i++){
        if(el2==nums[i])c2++;
        else if(el1==nums[i])c1++;
        if(c2>(n/3) && c1>(n/3))break;
    }
    if(c2>(n/3) && c1>(n/3))return {el1,el2};
    if(c2>(n/3)) return {el2};
    if(c1>(n/3)) return {el1};
    return {};
}

vector<int> majorityElement2(vector<int>& nums) {
    unordered_map<int,int>mp;
    int n=nums.size();
    vector<int>ans;
    for(int i=0;i<n;i++)mp[nums[i]]++;
    for(auto ele : mp){
        if(ele.second>n/3)ans.push_back(ele.first);
    }
    return ans;
}

int main(){
    vector<int>arr={1,2,2,1,2,1,1,1,3,4,5,1,2,2,2,1};
    vector<int>ans=majorityElement1(arr);

    for(auto ele : ans){
        cout<<ele<<" ";
    }
}