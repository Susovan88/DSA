#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// 8. String to Integer (atoi)
int myAtoi(string s) {
    int n=s.size();
    int i=0;
    int num=0;
    bool ng=false;
    // Ignore any leading whitespace
    while(i<n && s[i]==' ')i++;
    //  Determine the sign 
    if(s[i]=='-')ng=true;
    if(s[i]=='-' || s[i]=='+')i++;
    // Read the integer by skipping leading zeros
    while(i<n && s[i]=='0')i++;
    if(!(s[i]>='0' && s[i]<='9')) return num;
    while(i<n && (s[i]>='0' && s[i]<='9')){
        int x=s[i]-48; // digit
        // integer range [-231, 231 - 1]
        if((num>INT_MAX/10) || (num==INT_MAX/10 && x>7)) return INT_MAX;
        else if((num<INT_MIN/10) || (num==INT_MIN/10 && x>7)) return INT_MIN; 
        num*=10;
        if(!ng)num+=x;
        else num-=x;
        i++;
        cout<<x<<" "<<num<<endl;
    }
    return num;
}

int main(){
    string num="   -143524354896975nubeoun ";
    cout<<myAtoi(num)<<endl;
}