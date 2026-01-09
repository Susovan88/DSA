#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// 1025. Divisor Game
class Solution {
public:
    vector<int>dp;
    bool helper(int n){
        if(n==1) return 0;
        if(n==2) return 1;
        if(dp[n]!=-1) return dp[n];

        vector<int>divs;
        for(int i=1;i<=sqrt(n);i++){
            if(n%i==0){
                divs.push_back(i);
                if(i!=n/i && n/i!=n) divs.push_back(n/i);
            }
        }
        bool win=false;
        for(int i=0;i<divs.size();i++){
            if(!helper(n-divs[i])){
                win=true;
                break;
            }
        }
        return dp[n]=win? 1:0;
    }
    bool divisorGame(int n) {
        dp.clear();
        dp.resize(n+1,-1);
        return helper(n);
    }
};


int main(){
    int n;
    cin>>n;

    Solution s=Solution();

    cout<<s.divisorGame(n);
}