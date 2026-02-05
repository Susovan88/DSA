#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// 1005 Maximize sum of Array After K Negations
int largestSumAfterKNegations(vector<int>& nums, int k) {
    priority_queue<int,vector<int>,greater<int>>minH;
    for(int ele : nums){
        minH.push(ele);
    }
    int sum=0;
    while(k!=0){
        int top=minH.top();
        if(top==0)break;
        minH.pop();minH.push(-1*top);
        k--;
    }
    while(minH.size()!=0){
        sum+=minH.top();
        minH.pop();
    }
    return sum;
}

int main(){
    vector<int>arr={12,3,-9,8,-1,-2,4,-2,9,23,-12};
    int k=5;
    cout<<largestSumAfterKNegations(arr,k);
}