#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int>maxLoot; // max Lootfrom ith indx to n-1 idx.

    int topDown(vector<int>&nums,int idx){
        if(idx>=nums.size()) return 0;
        if(idx==nums.size()-1) return nums[idx];
        if(maxLoot[idx]!=-1) return maxLoot[idx]; // already calculated.
        //if not calculated.
        return maxLoot[idx]= max((nums[idx]+topDown(nums,idx+2)),topDown(nums,idx+1));
    }

    int bottomUp(vector<int>&loot,int idx){
        int n=loot.size();
        if(n>=2){
            loot[n-2]=max(loot[n-1],loot[n-2]);
        }
        for(int i=n-3;i>=0;i--){
            loot[i]=max(loot[i]+loot[i+2],loot[i+1]);
        }
        return loot[0];
    }

    int rob(vector<int>& nums) {
        maxLoot.clear();
        maxLoot.resize(102,-1);
        return bottomUp(nums,0);
    }
};

int main() {
    Solution obj;
    vector<int> nums = {2, 7, 9, 3, 1,5,4,1,9,2,1,10,2};

    cout << "Maximum loot: " << obj.rob(nums) << endl;
    return 0;
}