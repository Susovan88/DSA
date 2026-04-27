#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// using recursion => Remove top → sort remaining → insert element at correct position
void insertElement(stack<int>&st,int &x){
    if(st.size()==0 || st.top()<=x){
        st.push(x);
        return;
    }
    int temp=st.top();
    st.pop();
    insertElement(st,x);
    st.push(temp);
}
void sortStack(stack<int> &st) {
    if(st.size()==0 || st.size()==1)return;
    
    int x=st.top();
    st.pop();
    // sort stack
    sortStack(st);
    insertElement(st,x);
}

// using extra space 
void sortStack1(stack<int> &st) {
    map<int,int>mp;
    while(st.size()!=0){
        int t=st.top();
        st.pop();
        mp[t]++;
    }
    
    for(auto ele : mp){
        int x=ele.second;
        while(x--)st.push(ele.first);
    }
}

int main(){
    stack<int>st;
    st.push(12);
    st.push(22);
    st.push(2);
    st.push(5);
    st.push(7);
    st.push(3);
    st.push(16);
    sortStack(st);
    
        while(st.size()!=0){
        int t=st.top();
        st.pop();
        cout<<t<<" ";
    }
}