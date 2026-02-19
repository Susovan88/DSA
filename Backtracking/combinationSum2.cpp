#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>>ans;
void helper(vector<int>& nums, int tag,vector<int>&ele,int idx){
    if(tag==0){
        ans.push_back(ele);
        return;
    }
    if(idx==n) return;
    for(int i=idx;i<n;i++){
        if(tag<nums[i]) break;
        if(i-1>=idx && nums[i-1]==nums[i]) continue; // no repetation 
        ele.push_back(nums[i]);
        helper(nums,tag-nums[i],ele,i+1);
        ele.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int>& nums, int tag) {
    ans.clear();
    n=nums.size();
    sort(nums.begin(),nums.end());
    vector<int>ele;
    helper(nums,tag,ele,0);
    return ans;
}

int main(){
    vector<int>arr={1,5,17,9,2,3,5,7,12,10,9,4,8,19};
    int tag=19;
    vector<vector<int>>ans=combinationSum2(arr,tag);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<"+"<<ans[i][j];
        }
        cout<<endl;
    }
    return 0;
}