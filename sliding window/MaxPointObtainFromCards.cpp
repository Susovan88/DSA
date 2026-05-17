#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
Your logic is correct, but think about the edge case when k == n. In that case, the removed subarray size becomes n-k = 0, 
so j = n-k-1 becomes -1. Later, accessing card[j] means accessing card[-1], which causes undefined behavior/runtime error. 
Handle the case where all cards are taken separately before starting the sliding window logic.
*/

// 1423. Maximum Points You Can Obtain from Cards
int maxScore(vector<int>& card, int k) {
    int n=card.size();
    for(int i=1;i<n;i++){ // prefix sum
        card[i]+=card[i-1];
    }
    if(k == n) return card[n-1];
    int i=0;
    int j=n-k-1;
    int mxS=0;
    while(j<n){
        int leftS=0,rightS=0;
        if(i>0)leftS=card[i-1];
        if(j<n-1)rightS=card[n-1]-card[j];
        mxS=max(mxS,leftS+rightS);
        i++;
        j++;
    }
    return mxS;
}

int main(){
    vector<int>arr={1,2,3,4,5,6,1};
    cout<<maxScore(arr,4);
}