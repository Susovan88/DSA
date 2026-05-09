#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// 2389. Longest Subsequence With Limited Sum
vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
    int n=nums.size();
    sort(nums.begin(),nums.end());
    vector<int>ans;
    for(int i=1;i<n;i++){ // prefix sum
        nums[i]+=nums[i-1];
    }
    for(int ele : queries){
        if(ele<nums[0])ans.push_back(0);
        else if(ele>nums[n-1])ans.push_back(n);
        else{
            int i=0;
            while(i<n && nums[i]<=ele)i++;
            ans.push_back(i);
        }
    }
    return ans;
}

int main(){
    vector<int>arr={2,5,8,9,12,2,10,19,78,13};
    vector<int>qu={12,6,19,45,10};
    vector<int>ans=answerQueries(arr,qu);
    for(auto ele : ans)cout<<ele<<" ";
}