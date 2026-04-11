#include<iostream>
#include <bits/stdc++.h>
using namespace std;

/*
Q. => Given two sorted arrays nums1 and nums2, return an array that contains the union of these two arrays.
 The elements in the union must be in ascending order.
The union of two arrays is an array where all values are distinct and are present in either the first array, 
the second array, or both.
*/
vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
    vector<int>ans;
    int n=nums1.size(),m=nums2.size();
    int i=0,j=0;
    while(i<n && j<m){
        while(i<n-1 && nums1[i]==nums1[i+1])i++; // skip duplicated 
        while(j<m-1 && nums2[j]==nums2[j+1])j++; // skip duplicated 

        if(nums1[i]<nums2[j]){
            ans.push_back(nums1[i]);
            i++;
        }else if(nums1[i]==nums2[j]){
            ans.push_back(nums1[i]);
            i++;
            j++;
        }else{
            ans.push_back(nums2[j]);
            j++;
        }
    }
    while(i<n){
        while(i<n-1 && nums1[i]==nums1[i+1])i++; // skip duplicated 
        ans.push_back(nums1[i]);
        i++;
    }
    while(j<m){
        while(j<m-1 && nums2[j]==nums2[j+1])j++; // skip duplicated 
        ans.push_back(nums2[j]);
        j++;
    }
    return ans;
}

int main(){
    vector<int>arr1={1,3,3,3,5,7,9,12,12,12,12,89,90};
    vector<int>arr2={2,2,3,4,4,6,7,7,7,11,99,100,100,100,100,199,199,199,199,199,199,200,200,200};
    vector<int>ans=unionArray(arr1,arr2);

    for(auto ele : ans)cout<<ele<<" "; // -> 1 2 3 4 5 6 7 9 11 12 89 90 99 100 199 200 
}