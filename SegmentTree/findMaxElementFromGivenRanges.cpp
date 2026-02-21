#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

int n;
void buildTree(vector<int>&arr,int i,int lo,int hi,vector<int>&st){
    if(lo==hi){
        st[i]=arr[lo];
        return;
    }
    int mid=lo+(hi-lo)/2;
    buildTree(arr,2*i+1,lo,mid,st); // left call -> build the left sub tree
    buildTree(arr,2*i+2,mid+1,hi,st); // right call -> build the right sub tree
    st[i]=max(st[2*i+1],st[2*i+2]);
    return;
}
int getMaxFromGivenRange(int i,int &l,int &h,int lo,int hi,vector<int>&st){
    int left=2*i+1,right=2*i+2;
    int mid=lo+(hi-lo)/2;

    if( h<lo || l>hi) return INT_MIN; // outside of [lo,hi]
    if(lo>=l && hi<=h) return st[i]; // [lo,hi] is subset of [l,h]
    // [l,h] is subset of [lo,hi] or, overlapping each other.
    int leftMx=getMaxFromGivenRange(left,l,h,lo,mid,st); // get left max
    int rightMx=getMaxFromGivenRange(right,l,h,mid+1,hi,st); // get right max
    return max(leftMx,rightMx);
}
int main(){
    vector<int>arr={1,4,2,8,6,4,9,3,10,7,2,11,4,13,12};
    n=arr.size();
    vector<int>st(4*n,0); // segmentTree...
    buildTree(arr,0,0,n-1,st); // build the segment tree...
    int q;
    cout<<"enter no. of querys :";
    cin>>q;
    cout<<endl;
    while(q--){
        int l,h;
        cout<<"enter range:";
        cin>>l>>h;
        cout<<"max elemnt in give range :"<<getMaxFromGivenRange(0,l,h,0,n-1,st)<<endl;
    }
    return 0;

}