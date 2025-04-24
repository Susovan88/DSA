#include <iostream>
#include <cmath> 
#include <string>
#include <stack>
using namespace std;

void print(stack<int>&st){
    stack<int>temp;
    cout<<"top to bottom - ";
    while(st.size()>0){
        cout<<st.top()<<" ";
        temp.push(st.top());
        st.pop();
    }
    cout<<endl;
    cout<<"bottom to top - ";
    while(temp.size()>0){
        cout<<temp.top()<<" ";
        st.push(temp.top());
        temp.pop();
    }
    cout<<endl;
}

void revOfStack(stack<int>&st){
    // using 2 extra stack...
    stack<int>temp;
    stack<int>rev;
    while(st.size()>0){
        temp.push(st.top());
        st.pop();
    }

    while(temp.size()>0){
        rev.push(temp.top());
        temp.pop();
    }

    while(rev.size()>0){
        st.push(rev.top());
        rev.pop();
    }
}

void insertAtBottom(stack<int>&st,int val){
    stack<int>temp;
    while(st.size()>0){
        temp.push(st.top());
        st.pop();
    }
    st.push(val);
    while(temp.size()>0){
        st.push(temp.top());
        temp.pop();
    }
}

void insertAtIndx(stack<int>&st,int idx,int val){
    if(idx==0) insertAtBottom(st,val);
    stack<int>temp;
    while(st.size()>idx){
        temp.push(st.top());
        st.pop();
    }
    st.push(val);
    while(temp.size()>0){
        st.push(temp.top());
        temp.pop();
    }
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

    // print(st);
    // revOfStack(st);
    // print(st);
    insertAtBottom(st,78);
    print(st);
    insertAtIndx(st,2,12);
    print(st);
}

