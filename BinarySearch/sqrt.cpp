#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int mySqrt(int x) {
    if(x==1 || x==0) return x;
    long long st=1,end=x/2;
    int ans=0;
    while(st<=end){
        long long mid=st+(end-st)/2;
        if(mid*mid==x)return mid;
        else if(mid*mid>x)end=mid-1;
        else{
            ans=mid;
            st=mid+1;
        }
    }
    return ans;
}

// https://www.geeksforgeeks.org/problems/square-root/1
int floorSqrt(int n) {
    if(sqrt(n)*sqrt(n)==n) return sqrt(n);
    int st=0,end=n/2;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(mid*mid<=n)st=mid+1;
        else end=mid-1;
    }
    return end;
}

// https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1
int nthRoot(int n, int m) {
    if(m==0 || m==1 || n==1) return m;
    int st=1;
    int end=m;
    while(st<=end){
        int mid=st+(end-st)/2;
        long long val = 1;
        for(int i = 0; i < n; i++){
            val *= mid;
            if(val > m) break;
        }
        if(val==m) return mid;
        else if(val>m)end=mid-1;
        else st=mid+1;
    }
    return -1;
}

int main(){
    int x=871765;
    int sqrt=mySqrt(x);
    cout<<"sqrt of "<<x<<" is -> "<<sqrt<<endl;

}