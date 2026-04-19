#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// 1903. Largest Odd Number in String
string largestOddNumber(string num) {
    int n=num.size();
    int idx=-1;
    for(int i=n-1;i>=0;i--){
        int ascii=(int)num[i];
        if(ascii%2!=0){
            idx=i;
            break;
        }
    }
    for(int i=n-1;i>idx;i--)num.pop_back();
    return num;
}


int main(){
    string str="32314565423902246";
    cout<<largestOddNumber(str);
}