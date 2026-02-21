#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// 307. Range Sum Query - Mutable
class NumArray {
public:
    int n;
    vector<int>st; // segment tree...
    NumArray(vector<int>& nums) {
        n=nums.size();
        st.resize(4*n);
        buildTree(nums,0,0,n-1);
    }
    void buildTree(vector<int>&arr,int i,int lo,int hi){
        if(lo==hi){
            st[i]=arr[lo];
            return;
        }
        int mid=lo+(hi-lo)/2;
        buildTree(arr,2*i+1,lo,mid); // left call -> build the left sub tree
        buildTree(arr,2*i+2,mid+1,hi); // right call -> build the right sub tree
        st[i]=st[2*i+1]+st[2*i+2];
        return;
    }
    int getSumFromGivenRange(int i,int &l,int &h,int lo,int hi){
        int left=2*i+1,right=2*i+2;
        int mid=lo+(hi-lo)/2;

        if( h<lo || l>hi) return 0; // outside of [lo,hi]
        if(lo>=l && hi<=h) return st[i]; // [lo,hi] is subset of [l,h]
        // [l,h] is subset of [lo,hi] or, overlapping each other.
        int leftSum=getSumFromGivenRange(left,l,h,lo,mid); // get left max
        int rightSum=getSumFromGivenRange(right,l,h,mid+1,hi); // get right max
        return leftSum+rightSum;
    }
    void getUpdate(int &idx,int &val,int i,int lo,int hi){ // update the segment tree...
        if(lo==hi){
            st[i]=val;
            return;
        }
        int mid=lo+(hi-lo)/2;
        int lf=2*i+1,rg=2*i+2;
        if(idx<=mid) getUpdate(idx,val,lf,lo,mid); // only left
        else getUpdate(idx,val,rg,mid+1,hi); // only right
        st[i]=st[lf]+st[rg];
        return;
    }
    void update(int idx, int val) {
        getUpdate(idx,val,0,0,n-1);
        return;
    }
    
    int sumRange(int left, int right) {
        return getSumFromGivenRange(0,left,right,0,n-1);
    }
};


int main() {
    vector<int> nums = {1, 3, 5, 7, 9, 11};

    NumArray obj(nums);

    // Query sum from index 1 to 3 -> 3 + 5 + 7 = 15
    cout << "Sum [1, 3] = " << obj.sumRange(1, 3) << endl;

    // Update index 1 to value 10 (array becomes: 1,10,5,7,9,11)
    obj.update(1, 10);

    // Now query again: 10 + 5 + 7 = 22
    cout << "Sum [1, 3] after update = " << obj.sumRange(1, 3) << endl;

    // Another test
    cout << "Sum [0, 5] = " << obj.sumRange(0, 5) << endl; // total sum

    return 0;
}