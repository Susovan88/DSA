#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// 38. Count and Say
string helper(int n){
    if(n==1){
        return "1";
    }
    int i=0;
    string str=helper(n-1);
    string ans="";
    int s=str.size();
    while(i<s){
        int c=0;
        char ch=str[i];
        while(i<s && str[i]==ch){
            i++;
            c++;
        }
        ans+=to_string(c);
        ans.push_back(ch);
    }
    return ans;
}
string countAndSay(int n) {
    return helper(n);
}

int main(){
    int n=15;
    cout<<countAndSay(n);
}