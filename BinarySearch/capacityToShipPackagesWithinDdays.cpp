#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// 1011. Capacity To Ship Packages Within D Days
int shipWithinDays(vector<int>& wt, int days) {
    int n=wt.size();
    int tw=0;
    int mxE=INT_MIN;
    for(int i=0;i<n;i++){
        mxE=max(mxE,wt[i]);
        tw+=wt[i];
    }
    int st=mxE;
    int end=tw;
    while(st<=end){
        int mid=st+(end-st)/2;
        int d=0;
        int sw=0;
        for(int i=0;i<n;i++){
            if(d>days)break;
            if(sw+wt[i]<=mid)sw+=wt[i];
            else{
                d++;
                sw=wt[i];
            }
        }
        d++;
        cout<<st<<" - "<<end<<" => "<<mid<<" - "<<d<<endl;
        if(d<=days)end=mid-1;  // try to minimize the capacity more...
        else st=mid+1;
    }
    return st;
}

int main(){
    vector<int> weights = {1,2,3,1,1,9,8,2,4,5,10,5,15,8,19,2,1,1,2,3,1};
    int days=7;
    cout<<"Min capacity of the ship is -> "<<shipWithinDays(weights,days);
}