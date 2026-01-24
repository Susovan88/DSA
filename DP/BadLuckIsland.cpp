#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;


// https://codeforces.com/problemset/problem/540/D
double dp[101][101][101][4];
double ProbabilityOfSurvived(int r,int s,int p,int &species){
    if(species==1){ // R
        if(p==0)return 1.0;
        if(r==0||s==0) return 0.0;
    }if(species==2){ // S
        if(r==0)return 1.0;
        if(s==0||p==0) return 0.0;
    }if(species==3){ // P
        if(s==0) return 1.0;
        if(p==0||r==0) return 0.0;
    }
    if(dp[r][s][p][species]>-0.1) return dp[r][s][p][species];

    double ans=0.0;
    double total=(r*s +r*p+s*p);
    ans+=ProbabilityOfSurvived(r,s-1,p,species)*(double)((r*s)/total);
    ans+=ProbabilityOfSurvived(r-1,s,p,species)*(double)((r*p)/total);
    ans+=ProbabilityOfSurvived(r,s,p-1,species)*(double)((p*s)/total);
    return dp[r][s][p][species]=ans;
}

int main(){
    int r,s,p;
    cin>>r>>s>>p;

    memset(dp,-1,sizeof dp);
    int species=1;
    cout<<ProbabilityOfSurvived(r,s,p,species)<<" ";
    species=2;
    cout<<ProbabilityOfSurvived(r,s,p,species)<<" ";
    species=3;
    cout<<ProbabilityOfSurvived(r,s,p,species)<<" ";
}