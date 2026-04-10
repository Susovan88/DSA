#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// 74. Search a 2D Matrix
bool binSearch(vector<int>&arr,int st,int end,int &tg){
    while(st<=end){
        int mid=st+(end-st)/2;
        if(arr[mid]==tg) return true;
        else if(arr[mid]>tg){
            end=mid-1;
        }else st=mid+1;
    }
    return false;
}
bool searchMatrix(vector<vector<int>>& mat, int tg) {
    int n=mat.size();
    int m=mat[0].size();
    int rSt=0;
    int rEnd=n-1;
    while(rSt<=rEnd){
        int rMid=rSt+(rEnd-rSt)/2;
        if(mat[rMid][0]<=tg && mat[rMid][m-1]>=tg) return binSearch(mat[rMid],0,m-1,tg);
        else if(mat[rMid][0]>tg){
            rEnd=rMid-1;
        }else{
            rSt=rMid+1;
        }
    }
    return false;
}


int main(){
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    cout<<searchMatrix(matrix,34);
}