#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
For Minimum Operations to Make a Uni-Value Grid, first check whether all elements have the same remainder when divided by x. If not, it is impossible to make all values equal because adding or subtracting x never changes the remainder, so return -1. 
Then flatten the grid into a 1D array and sort it. The minimum operations are obtained by converting every element to the median value, because the median minimizes the total absolute difference. 
For each number, count operations as abs(nums[i] - median) / x and sum them to get the final answer.
*/

// 2033. Minimum Operations to Make a Uni-Value Grid
int minOperations(vector<vector<int>>& grid, int x) {
    int rem=grid[0][0]%x;
    vector<int>nums;
    for(auto arr : grid){
        for(auto ele : arr){
            if(ele % x!=rem) return -1;
            nums.push_back(ele);
        }
    }
    sort(nums.begin(),nums.end());
    int n=nums.size();
    int steps=0;
    int mid=nums[n/2];
    for(int i=0;i<n;i++){
        steps+=abs(nums[i]-mid)/x;
    }
    return steps;
}

int main(){
    vector<vector<int>>grid={
        {1,3,5},
        {3,5,7},
        {9,3,11}
    };
    cout<<minOperations(grid,2);
}