#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// 1710. Maximum Units on a Truck
bool cmd(vector<int>p1,vector<int>p2){
    double r1=p1[1];
    double r2=p2[1];
    if(r1==r2) return p1[0]>p2[0];
    return r1>r2;
}
int maximumUnits(vector<vector<int>>& arr, int truckSize) {
    sort(arr.begin(),arr.end(),cmd);
    int i=0,maxU=0;
    int n=arr.size();
    while(truckSize!=0 && i<n){
        if(arr[i][0]>truckSize){
            maxU+=truckSize*arr[i][1];
            truckSize=0;
        }else{
            maxU+=arr[i][0]*arr[i][1];
            truckSize-=arr[i][0];
            i++;
        }
    }
    return maxU;
}

int main(){
    vector<vector<int>> boxTypes = {
        {1, 3},  // 1 box, 3 units each
        {2, 2},  // 2 boxes, 2 units each
        {3, 1}   // 3 boxes, 1 unit each
    };
    int truckSize = 4;
    cout << maximumUnits(boxTypes, truckSize);
    return 0;
}
