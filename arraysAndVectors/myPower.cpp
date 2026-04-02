#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<list>
#include<queue>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

double myPow(double x, int n) {
    double ans=1;
    long long bin=n;
    if(n<0){
        x=1/x;
        bin=-bin;
    }
    double sum=x;
    while(bin>0){
        int val=bin%2;
        if(val)ans*=sum;
        sum*=sum;
        bin=bin/2;
    }
    return ans;
}


int main(){
    double x=9.99;
    int n=3;
    cout<<myPow(x,n);
}