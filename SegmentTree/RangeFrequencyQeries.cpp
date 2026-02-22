#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// 2080. Range Frequency Queries
class RangeFreqQuery {
public:
    int n;
    vector<unordered_map<int,int>>st;// segment tree.
    RangeFreqQuery(vector<int>& arr) {
        n=arr.size();
        st.resize(4*n);
        buildTree(0,0,n-1,arr);
    }
    void buildTree(int i,int lo,int hi,vector<int>&arr){
        if(lo==hi){
            st[i][arr[lo]]++;
            return;
        }
        int mid=lo+(hi-lo)/2;
        buildTree(2*i+1,lo,mid,arr);
        buildTree(2*i+2,mid+1,hi,arr);

        for(auto ele:st[2*i+1]){
            st[i][ele.first]=ele.second;
        }
        for(auto ele:st[2*i+2]){
            if(st[i].find(ele.first)!=st[i].end()) st[i][ele.first]+=ele.second;
            else st[i][ele.first]=ele.second;
        }
    }
    int searchFqu(int i,int &l,int &h,int lo,int hi,int &val){
        int left=2*i+1,right=2*i+2;
        int mid=lo+(hi-lo)/2;

        if( h<lo || l>hi) return 0; // outside of [lo,hi]
        // [lo,hi] is subset of [l,h]
        if(lo>=l && hi<=h){
            if(st[i].find(val)!=st[i].end()) return st[i][val];
            else return 0;
        };
        // [l,h] is subset of [lo,hi] or, overlapping each other.
        int leftSum=searchFqu(left,l,h,lo,mid,val); // get left max
        int rightSum=searchFqu(right,l,h,mid+1,hi,val); // get right max
        return leftSum+rightSum;
    }
    int query(int left, int right, int value) {
        return searchFqu(0,left,right,0,n-1,value);
    }
};

int main() {
    vector<int> arr = {1, 3, 3, 2, 1, 3, 1, 2, 2, 2};

    RangeFreqQuery rfq(arr);

    cout << rfq.query(0, 9, 1) << endl; // frequency of 1 in [0,9]
    cout << rfq.query(0, 9, 3) << endl; // frequency of 3 in [0,9]
    cout << rfq.query(3, 7, 2) << endl; // frequency of 2 in [3,7]
    cout << rfq.query(2, 5, 3) << endl; // frequency of 3 in [2,5]
    cout << rfq.query(4, 8, 1) << endl; // frequency of 1 in [4,8]

    return 0;
}
