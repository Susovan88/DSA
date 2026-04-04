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

int main(){
    int x=871765;
    int sqrt=mySqrt(x);
    cout<<"sqrt of "<<x<<" is -> "<<sqrt<<endl;

}