#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// 452. Minimum Number of Arrows to Burst Balloons
bool cmd(vector<int>&x,vector<int>&y){
    return x[0]<y[0];
}

int findMinArrowShots(vector<vector<int>>& arr) {
    sort(arr.begin(),arr.end(),cmd);
    int arrows=0;
    vector<int>common{arr[0].begin(),arr[0].end()};
    int i=1,n=arr.size();
    while(i<n){
        if(common[1]>=arr[i][0]){
            common[0]=arr[i][0];
            common[1]=min(common[1],arr[i][1]);
        }else{
            arrows++;
            common[0]=arr[i][0];
            common[1]=arr[i][1];
        }
        i++;
    }
    arrows++;
    return arrows;
}

int main(){
    vector<vector<int>>arr={{1,10},{2,7},{13,19},{8,12},{10,20},{21,30}};
    cout<<findMinArrowShots(arr)<<endl;
}