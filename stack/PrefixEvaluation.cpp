#include <iostream>
#include <stack>
using namespace std;

int solve(int v1,int v2,char ch){
    if(ch=='+')return v1+v2;
    else if(ch=='-') return v1-v2;
    else if(ch=='*')return v1*v2;
    else return v1/v2;
}


int main(){
    stack<int>st;
    string str="-/*+79483";
    int n=str.size();
    for(int i=n-1;i>=0;i--){
        if(str[i]>=48 && str[i]<=57)st.push(str[i]-'0');
        else{
            int v1=st.top();st.pop();
            int v2=st.top();st.pop();
            int x=solve(v1,v2,str[i]);
            st.push(x);
        }
    }
    cout<<st.top();
}