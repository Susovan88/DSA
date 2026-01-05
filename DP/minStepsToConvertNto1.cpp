#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

/*
You are solving Minimum steps to convert N → 1, using:

1.  n - 1
2.  n / 2 (if divisible)
3.  n / 3 (if divisible)

*/

int minStep(vector<int>&minS,int n){
    if(n==1) return 0;
    if(n==2 || n==3) return 1;
    if(minS[n]!=-1) return minS[n];

    return minS[n] = 1 + min({
        minStep(minS, n - 1),
        (n % 2 == 0) ? minStep(minS, n / 2) : INT_MAX,
        (n % 3 == 0) ? minStep(minS, n / 3) : INT_MAX
    });

}

int main(){
    int n=109;
    vector<int>dp(n+1,-1);
    cout<<"min step -> "<< minStep(dp,n);
}