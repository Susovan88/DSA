#include <iostream>
#include <cmath> 
#include <string>
#include <stack>
using namespace std;

void print(stack<int>&st){ // top to bottom
    if(st.size()==0) return;
    cout<<st.top()<<" ";
    int x=st.top();
    st.pop();
    print(st);
    st.push(x);
}

void printRev(stack<int>&st){
    if(st.size()==0) return;
    int x=st.top();
    st.pop();
    printRev(st);
    st.push(x);
    cout<<st.top()<<" ";
}

void pushAtBottom(stack<int>&st,int val){
    if(st.size()==0){
        st.push(val);
        return;
    }
    int x=st.top();
    st.pop();
    pushAtBottom(st,val);
    st.push(x);
}

void revOfStack(stack<int>&st){
    if(st.size()==1) return;
    int x=st.top();
    st.pop();
    revOfStack(st);
    pushAtBottom(st,x);
}

int main(){
    stack<int>st;
    cout<<st.size()<<endl;
    st.push(9);
    st.push(8);
    cout<<st.size()<<endl;
    st.push(23);
    st.push(1);
    cout<<st.size()<<endl;
    st.pop();
    cout<<st.size()<<endl;
    cout<<st.top()<<endl;

    st.push(97);
    st.push(85);
    print(st);
    cout<<endl;
    pushAtBottom(st,98);
    print(st);
    cout<<endl;
    revOfStack(st);
    print(st);
}