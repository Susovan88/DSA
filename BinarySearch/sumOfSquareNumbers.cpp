#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// 633. Sum of Square Numbers
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


int main(){
    int c=98752;
    cout<<judgeSquareSum(c);
}
