#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// 125. Valid Palindrome
bool isPalindrome(string s) {
    int n=s.size();
    string temp="";
    for(int i=0;i<n;i++){
        int ascii=(int)s[i];
        if(ascii>=97 && ascii<=122 || ascii>=48 && ascii<=57)temp.push_back(s[i]);
        else if(ascii>=65 && ascii<=90)temp.push_back(tolower(s[i]));
    }
    n=temp.size();
    for(int i=0;i<n/2;i++){
        if(temp[i]!=temp[n-i-1]) return false;
    }
    return true;
}

int main(){
    string str="A man, a plan, a canal: Panama";
    cout<<"Valid Palindrome -"<<(isPalindrome(str)!=0? "True":"Flase");
}