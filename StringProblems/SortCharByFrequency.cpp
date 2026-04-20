#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// 451. Sort Characters By Frequency
// 👉 Hint: Instead of storing frequency for each character separately, group characters by their frequency (bucket them) and process from highest to lowest.
string frequencySort1(string s) {  // optimize approch
    int n=s.size();
    vector<string>alp(n+1,"");  // frequency -> indx , string -> group of char 
    unordered_map<char,int>fq;
    for(int i=0;i<n;i++)fq[s[i]]++;
    for(auto ele : fq){
        alp[ele.second].push_back(ele.first);
    }
    
    string ans="";
    for(int i=n;i>=0;i--){
        int x=i;
        string group=alp[i];
        for(char ch :group){
            while(x--)ans.push_back(ch);
            x=i;
        }
        
    }
    return ans;
}

string frequencySort2(string s) {
    int n=s.size();
    vector<string>alp(n+1,"");  // frequency -> indx , string -> group of char 
    for(int i=97;i<=122;i++){ // A to Z and a to z
        char ch1=i,ch2=i-32;
        int c1=0,c2=0;
        for(int i=0;i<n;i++){
            if(s[i]==ch1)c1++;
            else if(s[i]==ch2)c2++;
        }
        if(c1!=0)alp[c1].push_back(ch1);
        if(c2!=0)alp[c2].push_back(ch2);
    }
    for(int i='0';i<='9';i++){ // 0 to 9
        char ch1=i;
        int c1=0;
        for(int i=0;i<n;i++){
            if(s[i]==ch1)c1++;
        }
        if(c1!=0)alp[c1].push_back(ch1);
    }
    string ans="";
    for(int i=n;i>=0;i--){
        int x=i;
        string group=alp[i];
        for(char ch :group){
            while(x--)ans.push_back(ch);
            x=i;
        }
        
    }
    return ans;
}

bool cmd(vector<int>&a,vector<int>&b){
    return a[0]>b[0];
}
string frequencySort3(string s) {
    int n=s.size();
    vector<vector<int>>alp;
    for(int i=97;i<=122;i++){ // A to Z and a to z
        char ch1=i,ch2=i-32;
        int c1=0,c2=0;
        for(int i=0;i<n;i++){
            if(s[i]==ch1)c1++;
            else if(s[i]==ch2)c2++;
        }
        if(c1!=0)alp.push_back({c1,ch1});
        if(c2!=0)alp.push_back({c2,ch2});
    }
    for(int i='0';i<='9';i++){ // 0 to 9
        char ch1=i;
        int c1=0;
        for(int i=0;i<n;i++){
            if(s[i]==ch1)c1++;
        }
        if(c1!=0)alp.push_back({c1,ch1});
    }
    sort(alp.begin(),alp.end(),cmd);
    string ans="";
    for(auto ele: alp){
        int x=ele[0];
        while(x--)ans.push_back(ele[1]);
    }
    return ans;
}

int main(){
    string str="2a554442f544asfasssffffasss";
    string ans=frequencySort1(str);
    cout<<ans;
}