#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// 633. Sum of Square Numbers
// solution 1
bool judgeSquareSum(int c) {
    if(c==0 || c==1 || c==2) return true;
    int mid;
    int sq=sqrt(c);
    for(int i=0;i<=sq;i++){
        long long a=i*i,b;
        int st=0;
        int end=sq;
        while(st<=end){
            mid=st+(end-st)/2;
            b=mid*mid;
            if((a+b)==c) return true;
            else if((a+b)>c)end=mid-1;
            else st=mid+1;
        }
    }
    return false;
}

// solution 2
bool isSqr(int x){
    int root=sqrt(x);
    if(root*root==x) return true;
    return false;
}
bool judgeSquareSum2(int c) {
    int a=0,b=c;
    while(a<=b){
        if(isSqr(a) && isSqr(b)) return true;
        else if(!isSqr(a)){
            a=((int)sqrt(a)+1) * ((int)sqrt(a)+1);
            b=c-a;
        }else{
            b=(int)sqrt(b)*(int)sqrt(b);
            a=c-b;
        }
    }
    return false;
}


int main(){
    int c=98752;
    cout<<judgeSquareSum(c);
}
