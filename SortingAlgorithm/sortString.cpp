#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string str="AXZBYXZCWERYZXSDXXXUYWZZ";
    string s=""; // only X Y Z present here
    for(int i=0;i<str.size();i++){
        if(str[i]=='Y'||str[i]=='Z'||str[i]=='X')s+=str[i];
    }
    cout<<s<<endl;
    int n=s.size();
    for(int i=0;i<n-1;i++){
        bool flag=true;
        for(int j=0;j<n-1-i;j++){
            if(s[j]>s[j+1]){ 
                swap(s[j],s[j+1]);
                flag=false;
            }
        }
        if(flag) break;
    }

    cout<<s;
}