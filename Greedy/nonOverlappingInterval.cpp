#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// 435 non overlapping interval
bool cmd(vector<int>&x,vector<int>&y){
    return x[1]<y[1];
}

int eraseOverlapIntervals(vector<vector<int>>& arr) {
    // sort based on ending time of interval in increasing 
    sort(arr.begin(),arr.end(),cmd);
    int lastEnd=arr[0][1];
    int i=1,count=0;
    int n=arr.size();
    while(i<n){
        if(arr[i][0]>=lastEnd){
            lastEnd=arr[i][1];
        }else{
            count++;
        }
        i++;
    }
    return count;
}

int main(){
    vector<vector<int>>arr={{1,10},{2,7},{13,19},{8,12},{10,20},{21,30}};
    cout<<eraseOverlapIntervals(arr)<<endl;
}