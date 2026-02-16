#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

//// hint -> every char get chance to be a first char of the combination
// abc -> abc,acb,bac,bca,cab,cba
void premutation1(string str,vector<string>&ans,string temp){ 
    if (str.size() == 0) {
        ans.push_back(temp);
        return;
    }
    string newStr="";
    for(int i=0;i<str.size();i++){   
        temp.push_back(str[i]);
        newStr=str.substr(0,i)+str.substr(i+1);  // left_sub_str + right_sub_str
        premutation1(newStr,ans,temp);
        temp.pop_back(); // backtrack....
    }
    return;
}

// optimized approch -> using sawp and reswap
void premutation2(string &str,vector<string>&ans,int idx){
    if(str.size()-1==idx){
        ans.push_back(str);
        return;
    }
    for(int i=idx;i<str.size();i++){   
        swap(str[i],str[idx]);
        premutation2(str,ans,idx+1);
        // backtrack....
        swap(str[i],str[idx]);
    }
    return;
}

// more optimized approch-> avoid repeatation for duplicate char...
void premutation3(string &str,vector<string>&ans,int idx){
    if(str.size()-1==idx){
        ans.push_back(str);
        return;
    }
    unordered_set<char>s;
    for(int i=idx;i<str.size();i++){  
        if(s.find(str[i])!=s.end())continue; // avoid call for duplicate char...
        s.insert(str[i]);
        swap(str[i],str[idx]);
        premutation3(str,ans,idx+1);
        // backtrack....
        swap(str[i],str[idx]);
    }
    return;
}

int main(){
    string str="abc";
    
    cout<<" combinations of string (unique char only)-> ";
    vector<string>ans2;
    premutation1(str,ans2,"");

    for(int i=0;i<ans2.size();i++){
        cout<<ans2[i]<<" , ";;
    }
    cout<<endl;

    vector<string>ans1;
    premutation2(str,ans1,0);
    cout<<"combinations of string (unique char only)-> ";
    for(int i=0;i<ans1.size();i++){
        cout<<ans1[i]<<" , ";
    }
    cout<<endl;

    string str1="abab";
    cout<<" combinations of string (duplicate char also) -> ";
    vector<string>ans3;
    premutation3(str1,ans3,0);
    for(int i=0;i<ans3.size();i++){
        cout<<ans3[i]<<" , ";;
    }
}
