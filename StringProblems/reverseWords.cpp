#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// 151. Reverse Words in a String
string reverseWords1(string str) {
    stringstream ss(str);
    vector<string>words;
    string temp;
    while(ss >> temp){
        words.push_back(temp);
    }
    reverse(words.begin(),words.end());
    str="";
    for(auto word : words){
        str+=word;
        str.push_back(' ');
    }
    str.pop_back();
    return str;
}
string reverseWords(string str) {
    vector<string>words;
    string temp="";
    int i=0;
    int n=str.size();
    while(i<n){
        while(i<n & str[i]!=' '){
            temp.push_back(str[i]);
            i++;
        }
        if(temp!="")words.push_back(temp);
        temp="";
        i++;
    }
    for(auto ele : words)cout<<ele<<endl;
    reverse(words.begin(),words.end());
    str="";
    for(auto word : words){
        str+=word;
        str.push_back(' ');
    }
    str.pop_back();
    return str;
}


int main(){
    string str="the sky is blue";
    cout<<reverseWords(str);
}