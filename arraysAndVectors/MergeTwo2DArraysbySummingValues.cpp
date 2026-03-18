#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<list>
#include<queue>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

// 2570. Merge Two 2D Arrays by Summing Values
vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
    vector<vector<int>>ans;
    int n=nums1.size();
    int m=nums2.size();
    int i=0,j=0;
    while(i<n && j<m){
        if(nums1[i][0]==nums2[j][0]){
            ans.push_back({nums1[i][0],(nums1[i][1]+nums2[j][1])});
            i++;
            j++;
        }else if(nums1[i][0]<nums2[j][0]){
            ans.push_back({nums1[i][0],nums1[i][1]});
            i++;
        }else{
            ans.push_back({nums2[j][0],nums2[j][1]});
            j++;  
        }
    }
    while(i<n){
        ans.push_back({nums1[i][0],nums1[i][1]});
        i++;
    }
    while(j<m){
        ans.push_back({nums2[j][0],nums2[j][1]});
        j++;    
    }
    return ans;
}

int main(){
    vector<vector<int>> nums1 = {{1,2},{2,3},{4,5}};
    vector<vector<int>> nums2 = {{1,4},{3,2},{4,1}};

    vector<vector<int>>ans=mergeArrays(nums1,nums2);

    // Print result
    cout << "Output:\n";
    for(auto &v : ans) {
        cout << "[" << v[0] << "," << v[1] << "] ";
    }
}