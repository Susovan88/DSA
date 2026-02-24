#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

class NumArray {
public:
    int n;
    vector<int>st; // segment tree...
    vector<int>lazy;
    NumArray(vector<int>& nums) {
        n=nums.size();
        st.resize(4*n);
        lazy.resize(4*n,0);
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
        
        if(lazy[i]!=0){ // check pending upated  
            int count=hi-lo+1;
            st[i]+=(count*lazy[i]);
            if(lo!=hi){
                lazy[left]+=lazy[i];
                lazy[right]+=lazy[i];
            }
            lazy[i]=0;
        }

        if( h<lo || l>hi) return 0; // outside of [lo,hi]
        if(lo>=l && hi<=h) return st[i]; // [lo,hi] is subset of [l,h]
        // [l,h] is subset of [lo,hi] or, overlapping each other.
        int leftSum=getSumFromGivenRange(left,l,h,lo,mid); // get left max
        int rightSum=getSumFromGivenRange(right,l,h,mid+1,hi); // get right max
        return leftSum+rightSum;
    }
    void getUpdate(int &l,int &r,int &val,int i,int lo,int hi){ // update the segment tree...
        int left=2*i+1,right=2*i+2;
        int mid=lo+(hi-lo)/2;
        if(lazy[i]!=0){ // check pending upated 
            int count=hi-lo+1;
            st[i]+=(count*lazy[i]);
            if(lo!=hi){ // give pending update to leaf nodes....
                lazy[left]+=lazy[i];
                lazy[right]+=lazy[i];
            }
            lazy[i]=0;
        }
        if(l>hi || r<lo) return; // outside
        if(lo>=l && hi<=r){ // (lo,hi) is subset of (l,r) -> update the current element and give pending update to leaf nodes....
            int count=hi-lo+1;
            st[i]+=(count*val);
            if(lo!=hi){
                lazy[left]+=val;
                lazy[right]+=val;
            }
            return;
        }
        // overlapping -> call both leaf node for update
        getUpdate(l,r,val,left,lo,mid);
        getUpdate(l,r,val,right,mid+1,hi);
        st[i]=st[left]+st[right];
        return;
    }
    void update(int lf,int rg,int val) {
        getUpdate(lf,rg,val,0,0,n-1);
        return;
    }
    
    int sumRange(int left, int right) {
        return getSumFromGivenRange(0,left,right,0,n-1);
    }
};


int main() {
    vector<int> nums = {1, 3, 5, 7, 9, 11,4,2};

    NumArray obj(nums);

    cout << "Sum [1, 3] = " << obj.sumRange(1, 3) << endl;

    obj.update(1,5,10);

    cout << "Sum [1, 3] after update = " << obj.sumRange(1, 3) << endl;
    
    obj.update(3,7,5);
    
    cout << "Sum [0, 5] = " << obj.sumRange(0, 5) << endl; // total sum

    return 0;
}