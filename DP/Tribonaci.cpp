#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(vector<int>&arr,int n){ // top down
        if(n==0) return 0;
        if(n==1 || n==2) return 1;
        if(arr[n]!=-1) return arr[n];
        return arr[n]=helper(arr,n-1)+helper(arr,n-2)+helper(arr,n-3);
    }
    int bottomUp(int n){  // bottom up with space optimizatioon  using o(1) space 
        if(n==1 || n==0) return n;
        if(n==2)return 1;

        vector<int>arr(4);
        arr[0]=0;
        arr[1]=1;
        arr[2]=1;
        for(int i=3;i<=n;i++){
            arr[3]=arr[1]+arr[2]+arr[0];
            arr[0]=arr[1];
            arr[1]=arr[2];
            arr[2]=arr[3];
        }
        return arr[3];
    }
    int tribonacci(int n) {
        vector<int>arr(n+1,-1);
        return bottomUp(n);
    }
};

int main() {
    int n;
    cin >> n;
    Solution sol;
    cout << "Top Down Fibonacci: " << sol.bottomUp(n) << endl;
    cout << "Bottom Up Fibonacci: " << sol.tribonacci(n) << endl;

    return 0;
}