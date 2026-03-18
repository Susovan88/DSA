#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<list>
#include<queue>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) { // O(n), extra space used .
    int n=nums.size();
    unordered_map<int,int>mp;
    vector<int>ans;
    for(int i=0;i<n;i++){
        if(mp.find(target-nums[i])!=mp.end()){
            ans.push_back(mp[target-nums[i]]);
            ans.push_back(i);
            return ans;
        }
        mp[nums[i]]=i;
    }
    return ans;
}

int main(){
  int sum;
  cout<<"Enter target : ";
  cin>>sum;
  int n;
  cout<<"Enter size of array : ";
  cin>>n;
  vector<int>v;
  cout<<"Enter element :";
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    v.push_back(x);
  }
  vector<int> ans=twoSum(v,sum);
  for(int i=0;i<ans.size();i++){  
    cout<<ans[i]<<" ";
  }
}
