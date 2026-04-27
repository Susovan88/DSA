#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// 
void insertAtBottom(stack<int>& st, int x) {
    if (st.empty()) {
        st.push(x);
        return;
    }
    int temp = st.top();
    st.pop();
    insertAtBottom(st, x);
    st.push(temp);
}
void reverseStack1(stack<int> &st) {
    if (st.empty()) return;
    int x = st.top();
    st.pop();
    reverseStack1(st);
    insertAtBottom(st, x);
}

void helper(stack<int> &st,queue<int> &qu){
    if(st.size()==0) return;
    int x=st.top();
    st.pop();
    qu.push(x);
    helper(st,qu);
    if(qu.size()==0) return;
    x=qu.front();
    qu.pop();
    st.push(x);
    return;
}
void reverseStack2(stack<int> &st) {
    queue<int>qu;
    helper(st,qu);
}

int main() {
    stack<int> st;

    // Push elements
    st.push(1);
    st.push(2);
    st.push(3);

    cout << "Original Stack (Top to Bottom): ";
    stack<int> temp = st;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
    reverseStack1(st);

    cout << "Reversed Stack (Top to Bottom): ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}