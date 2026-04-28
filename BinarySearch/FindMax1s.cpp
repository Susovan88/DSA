#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1
int rowWithMax1s(vector<vector<int>> &arr) {
    int n=arr.size();
    int m=arr[0].size();
    int mx1=0;
    int row=-1;
    for(int i=0;i<n;i++){
        int st=0;
        int end=m-1;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(arr[i][mid]==1)end=mid-1;
            else st=mid+1;
        }
        int c1=m-st;
        if(c1>mx1){
            mx1=c1;
            row=i;
        }
    }
    return row;
}

int main(){
    vector<vector<int>> arr = {
        {0, 0, 1, 1},
        {0, 1, 1, 1},
        {0, 0, 0, 1}
    };
    cout<<rowWithMax1s(arr);
}