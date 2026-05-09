#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// 1402. Reducing Dishes
int maxSatisfaction(vector<int>& sat) {
    int n=sat.size();
    sort(sat.begin(),sat.end());
    vector<int>sufix(n);
    // sufix sum
    sufix[n-1]=sat[n-1];
    for(int i=n-2;i>=0;i--){
        sufix[i]=sufix[i+1]+sat[i];
    }
    int idx=-1;
    for(int i=0;i<n;i++){
        if(sufix[i]>=0){
            idx=i;
            break;
        }
    }
    if(idx==-1) return 0;
    int t=1;
    int sum=0;
    for(int i=idx;i<n;i++){
        sum+=(sat[i]*t);
        t++;
    }
    return sum;
}

int main(){
    vector<int>sat={-1,-8,0,5,-9,9,-12,-3,6,5,-7};
    cout<<maxSatisfaction(sat);
}