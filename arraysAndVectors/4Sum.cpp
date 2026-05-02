#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<list>
#include<queue>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

// 18. 4Sum
vector<vector<int>> fourSum(vector<int>& nums, int tag) {
    int n=nums.size();
    sort(nums.begin(),nums.end());
    vector<vector<int>>ans;
    for(int i=0;i<n;i++){
        if(i>0 && nums[i]==nums[i-1])continue;
        for(int j=i+1;j<n;j++){
            if(j>i+1 && nums[j]==nums[j-1])continue;
            long long ab=nums[i]+nums[j];
            long long rem=tag-ab; //cd
            int x=j+1;
            int y=n-1;
            while(x<y){
                if(x==i || x==j){
                    x++;
                    continue;
                }
                if(y==i || y==j){
                    y--;
                    continue;
                }
                long long cd=nums[x]+nums[y];
                if(rem==cd){
                    ans.push_back({nums[i],nums[j],nums[x],nums[y]});
                    x++;y--;
                    while(x < y && nums[x] == nums[x - 1]) x++;
                    while(x < y && nums[y] == nums[y + 1]) y--;
                }else if(rem<cd){
                    y--;
                }else{
                    x++;
                }
            }
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2,-3,3,0,5,-5};
    int target = 0;

    vector<vector<int>> result = fourSum(nums, target);

    cout << "Quadruplets:\n";
    for(auto &vec : result) {
        for(int x : vec) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}