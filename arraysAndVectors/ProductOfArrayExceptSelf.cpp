#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<list>
#include<queue>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

// 238. Product of Array Except Self
vector<int> productExceptSelf(vector<int>& nums) {
    int n=nums.size();
    int pro=1;
    int isZ=0;
    int isN=0;
    for(int i=0;i<n;i++){
        if(nums[i]==0){
            isZ++;
            continue;
        }
        pro*=nums[i];
    }
    for(int i=0;i<n;i++){
        if((isZ>0 && nums[i]!=0) || (isZ>1 && nums[i]==0)){
            nums[i]=0;
        }
        else if(isZ==1 && nums[i]==0)nums[i]=pro;
        else nums[i]=pro/nums[i];
    }
    return nums;
}


int main(){
    vector<int>arr={1,2,43,-9,7,0,23,-7,4,5,-5,-12};
    vector<int>ans=productExceptSelf(arr);
    for(auto ele : arr)cout<<ele<<" ";
}