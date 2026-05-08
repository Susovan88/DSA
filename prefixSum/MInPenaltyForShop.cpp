#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// 2483. Minimum Penalty for a Shop
int bestClosingTime(string cust) {
    int n=cust.size();
    vector<int>prefix(n,0);
    vector<int>sufix(n,0);
    for(int i=1;i<n;i++){
        if(cust[i-1]=='N')prefix[i]=prefix[i-1]+1;
        else prefix[i]=prefix[i-1];
    }
    if(cust[n-1]=='Y')sufix[n-1]=1;
    for(int i=n-2;i>=0;i--){
        if(cust[i]=='Y')sufix[i]=sufix[i+1]+1;
        else sufix[i]=sufix[i+1];
    }
    int t=-1;
    int minP=INT_MAX;

    for(int i=0;i<n;i++){
        int p=prefix[i]+sufix[i];
        if(p<minP){
            minP=p;
            t=i;
        }
    }
    if(cust[n-1]=='N' && minP>prefix[n-1]+1)t=n;
    else if(minP>prefix[n-1]) t=n;
    return t;
}

int main(){
    string str="YYYYNYNYNYNNNYNYYYYNYYYYNYNYNYNYNNYYYNNNYY";
    cout<<bestClosingTime(str);
}