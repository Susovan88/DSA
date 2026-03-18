#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<list>
#include<queue>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

// 15. Three Sum
vector<vector<int>> threeSum(vector<int>& nums) {
    int n=nums.size();
    vector<vector<int>>ans;
    sort(nums.begin(),nums.end());
    for(int x=0;x<n;x++){
        if(x > 0 && nums[x] == nums[x-1]) continue; // skip duplicate
        int i=x+1,j=n-1;
        while(i<j){
            if((nums[i]+nums[j])==-nums[x]){
                ans.push_back({nums[x],nums[i],nums[j]});
                i++; j--;
                //// skip duplicate
                while(i<j && nums[i]==nums[i-1])i++;
                while(i<j && nums[j]==nums[j+1])j--;
            }
            else if((nums[i]+nums[j]) > -nums[x]) j--;
            else i++;
        }

    }
    return ans;
}

int main() {

    vector<int> nums = {-1,0,1,2,-1,-4,9,0,-9,2,-7,-5,6,5};

    vector<vector<int>> result =threeSum(nums);

    cout << "Triplets are:\n";
    for(auto &vec : result) {
        for(auto &x : vec) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}