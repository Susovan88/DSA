#include<iostream>
#include <bits/stdc++.h>
using namespace std;
/*
The key idea is that all rotations of a string will be present inside s + s. So instead of checking every rotation manually, 
just join the string with itself.
Then, simply check if goal exists as a substring inside this new string. If it exists, then goal is a valid rotation of s; 
otherwise, it is not.
*/

// 796. Rotate String
bool rotateString(string s, string goal) { // O(n)
    if(s==goal) return true;
    int n=s.size();
    if(n!=goal.size()) return false;
    string temp=s+s;
    int j=0;
    for(int i=0;i<n;i++){
        while(i<n && j<n && temp[i+j]==goal[j]){
            j++;
        }
        if(j==n) return true;
        else j=0;
    }
    return false;
}

bool rotateString2(string s, string goal) { // use build in function
    if(s==goal) return true;
    int n=s.size();
    if(n!=goal.size()) return false;
    string temp=s+s;
    int idx=temp.find(goal);
    return idx==string::npos?false:true;
}

bool rotateString3(string s, string goal) { // O(n^2)
    if(s==goal) return true;
    int n=s.size();
    if(n!=goal.size()) return false;
    int i=0;
    int j=n-1;
    while(i<n && j>=0){
        string sub2=s.substr(i+1);
        string sub1=s.substr(0,i+1);
        string sub3=goal.substr(0,j);
        string sub4=goal.substr(j);
        if(sub1==sub4 && sub3==sub2) return true;
        i++;
        j--;
    }
    return false;
}


int main(){
    string s = "abxybbmmscde", goal = "mmscdeabxybb";
    cout<<rotateString(s,goal);
}