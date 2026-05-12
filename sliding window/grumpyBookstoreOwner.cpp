#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// 1052. Grumpy Bookstore Owner
int maxSatisfied(vector<int>& cust, vector<int>& grum, int mnt) {
    int i=0;
    int j=0;
    int n=cust.size();
    int mxStf=0;
    int stf=0;
    for(j=0;j<mnt;j++){
        if(grum[j]==1)stf+=cust[j];
    }
    while(j<n){
        mxStf=max(mxStf,stf);
        cout<<i<<" "<<j-1<<" "<<stf<<" "<< mxStf<<" "<<endl;
        if(grum[i]==1)stf-=cust[i];
        i++;
        if(grum[j]==1)stf+=cust[j];
        j++;
    }
    mxStf=max(mxStf,stf);
    cout<<i<<" "<<j-1<<" "<<stf<<" "<< mxStf<<" "<<endl;
    stf=0;
    for(int i=0;i<n;i++){
        if(grum[i]==0)stf+=cust[i];
    }
    return stf+mxStf;
}

int main() {
    vector<int> customers = {1,0,1,2,1,1,7,5};
    vector<int> grumpy =    {0,1,0,1,0,1,0,1};

    int minutes = 3;

    cout << maxSatisfied(customers, grumpy, minutes);

    return 0;
}