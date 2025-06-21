#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void displayQueue(queue<int> &qu){
     cout<<" =>> ";
    for(int i=0;i<qu.size();i++){
        int a=qu.front();
        qu.pop();
        cout<<a<<" ";
        qu.push(a);
    }
    cout<<endl;
}

// void reorderQueue(queue<int>&qu){     // -> t.c - o(n) , s.c - o(n)
//     stack<int>st;   // using stack only...
//     int n=qu.size();
//     for(int i=0;i<n/2;i++){
//         st.push(qu.front());
//         qu.pop();
//     }
//     while(st.size()!=0){
//         qu.push(st.top());
//         st.pop();
//     }
//     for(int i=0;i<n/2;i++){
//         qu.push(qu.front());
//         qu.pop();
//     }
//     for(int i=0;i<n/2;i++){
//         st.push(qu.front());
//         qu.pop();
//     }
//     while(st.size()!=0){
//         qu.push(st.top());
//         st.pop();
//         qu.push(qu.front());
//         qu.pop();
//     }
// }

void reorderQueue(queue<int>&qu){  
    stack<int>st;   // using stack only...
    int n=qu.size();
    // push frist half element into the stack
    for(int i=0;i<n/2;i++){
        st.push(qu.front());
        qu.pop();
    }
    // then pop from stack and push into queue
    while(st.size()!=0){
        qu.push(st.top());
        st.pop();
    }
    // push first half elements into the stack
    for(int i=0;i<n/2;i++){
        st.push(qu.front());
        qu.pop();
    }
    // most important interliving one by one
    while(st.size()!=0){
        qu.push(st.top());
        st.pop();
        qu.push(qu.front());
        qu.pop();
    }
    // reverse the queue using stack
    while(qu.size()!=0){
        st.push(qu.front());
        qu.pop();
    }
    while(st.size()!=0){
        qu.push(st.top());
        st.pop();
    }
}



int main(){
    queue<int>qu;  // 1 2 3 4 5 6 7 8 9 10
    for(int i=1;i<=10;i++){
        qu.push(i);
    }
    displayQueue(qu);

    reorderQueue(qu);  // ->  1 6 2 7 3 8 4 9 5 10

    displayQueue(qu);
}