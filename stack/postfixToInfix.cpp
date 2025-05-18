#include <iostream>
#include <stack>
using namespace std;

string solve(string s1,string s2,char ch){
    s1=s1+ch+s2;
    return s1;
}

int main(){
    stack<string>st;
    string str="978*52+83-*+-";
    int n=str.size();
    for(int i=0;i<n;i++){
        if(str[i]>=48 && str[i]<=57) st.push(to_string(str[i]-'0'));
        else{
            string s2=st.top();st.pop();
            string s1=st.top();st.pop();
            st.push(solve(s1,s2,str[i]));
        }
    }
    cout<<st.top();
}