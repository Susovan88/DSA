#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// // 1901. Find a Peak Element II
// Binary search 
int findMaxElementIndex(vector<vector<int>>& mat,int x){
    int m=mat[0].size();
    int mxI=0;
    for(int i=1;i<m;i++){
        if(mat[x][mxI]<mat[x][i])mxI=i;
    }
    return mxI;
}
vector<int> findPeakGGrid1(vector<vector<int>>& mat) {
    int n=mat.size();
    int m=mat[0].size();
    int st=0;
    int end=n-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        int mxI=findMaxElementIndex(mat,mid);// index
        if(mid!=0 && mat[mid-1][mxI]>mat[mid][mxI]) end=mid-1;
        else if(mid!=n-1 && mat[mid+1][mxI]>mat[mid][mxI])st=mid+1;
        else return{mid,mxI};
    }
    return {n,m};
}

// linear search 
vector<int> findPPeakGrid2(vector<vector<int>>& mat) {
    int n=mat.size();
    int m=mat[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i>0 && mat[i][j]<=mat[i-1][j]) continue;        
            if(i<n-1 && mat[i][j]<=mat[i+1][j])continue;
            if(j>0 && mat[i][j]<=mat[i][j-1])continue;
            if(j<m-1 && mat[i][j]<=mat[i][j+1])continue;
            return {i,j};
        }
    }
    return {n,m};
}


int main() {
    vector<vector<int>> mat = {
        {10, 20, 15},
        {21, 30, 14},
        {7, 16, 32}
    };

    vector<int> ans = findPeakGGrid1(mat);

    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}