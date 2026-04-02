#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<list>
#include<queue>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int maxArea(vector<int>& hig) {
    int n=hig.size();
    int l=0,r=n-1;
    int maxW=INT_MIN;
    while(l<r){
        int w=r-l;
        int h=min(hig[l],hig[r]);
        maxW=max(maxW,w*h);
        hig[l]>hig[r]? r--:l++;
    }
    return maxW;
}

int main(){
    vector<int>hight={12,8,5,4,2,8,3,9,1,0};
    cout<<maxArea(hight);
}