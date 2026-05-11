#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// 2640. Find the Score of All Prefixes of an Array
vector<long long> findPrefixScore(vector<int>& nums) {
    int n=nums.size();
    vector<long long>prefix(n,0);
    int mx=INT_MIN;
    for(int i=0;i<n;i++){
        mx=max(mx,nums[i]);
        prefix[i]=nums[i]+mx;
    }
    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+prefix[i];
    }
    return prefix;
}

int main(){
    vector<int>arr={1,2,3,4,5,6,7,8,9,10,12,87,13,43,87};
    vector<long long>ans=findPrefixScore(arr);
    for(auto ele : ans)cout<<ele<<" ";
}