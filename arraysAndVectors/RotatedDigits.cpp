#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<list>
#include<queue>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

// 788. Rotated Digits
int getRotateDigit(int n){
    if(n==2) return 5;
    if(n==5) return 2;
    if(n==9) return 6;
    if(n==6) return 9;
    if(n==0 || n==1 || n==8) return n;
    return -1; // 7 4 3
}
int validRotationNum(int n){
    int m=0; // valid num after rotation;
    int x=10;
    int y=1;
    while(n>0){
        int dig=n%x;
        n/=10;
        int r=getRotateDigit(dig);
        if(r==-1) return -1;
        m+=(r*y);
        y*=10;
    }
    return m;
}
int rotatedDigits(int n) {
    int c=0;
    for(int i=1;i<=n;i++){
        int r=validRotationNum(i);
        if(r!=-1 && i!=r)c++;
    }
    return c;
}

int main(){
    int n=199;
    cout<<rotatedDigits(n);
}