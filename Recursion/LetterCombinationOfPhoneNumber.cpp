#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// 17. Letter Combinations of a Phone Number
vector<string>ans;
int m;
void helper(vector<string>&str,string &temp,int idx){
    if(idx==m){
        ans.push_back(temp);
        return;
    }
    for(int i=0;i<str[idx].size();i++){
        temp.push_back(str[idx][i]);
        helper(str,temp,idx+1);
        temp.pop_back();
    }
    return;
}
string getString(char ch){
    if(ch=='2') return "abc";
    if(ch=='3') return "def";
    if(ch=='4') return "ghi";
    if(ch=='5') return "jkl";
    if(ch=='6') return "mno";
    if(ch=='7') return "pqrs";
    if(ch=='8') return "tuv";
    return "wxyz";
}
vector<string> letterCombinations(string digits) {
    vector<string>str;
    int n=digits.size();
    for(int i=0;i<n;i++){
        string temp=getString(digits[i]);
        str.push_back(temp);
    }
    m=str.size();
    string temp="";
    helper(str,temp,0);
    return ans;
}


int main(){
    string digits="295";
    letterCombinations(digits);
    for(auto ele : ans){
        cout<<ele<<endl;
    }
}