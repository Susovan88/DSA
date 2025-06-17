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


void reverseFristKthElement(queue<int> &qu,int k){
    stack<int>st;
    int n=qu.size();
    for(int i=0;i<k;i++){
        st.push(qu.front());
        qu.pop();
    }
    for(int i=0;i<k;i++){
        qu.push(st.top());
        st.pop();
    }
    for(int i=0;i<n-k;i++){
        qu.push(qu.front());
        qu.pop();
    }
}


int main(){
    queue<int>qu;
    int k=5;

    qu.push(89);
    qu.push(9);
    qu.push(19);
    qu.push(29);
    qu.push(39);
    qu.push(49);
    qu.push(59);
    qu.push(69);
    qu.push(3);
    qu.push(4);
    qu.push(5);
    qu.push(6);

    displayQueue(qu);

    reverseFristKthElement(qu,k);

    displayQueue(qu);

}
