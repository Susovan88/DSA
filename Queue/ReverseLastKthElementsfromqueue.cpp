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

void reverseLastKthElements(queue<int>&qu,int k){
    int n=qu.size();
    stack<int>st;
    for(int i=0;i<n-k;i++){
        qu.push(qu.front());
        qu.pop();
    }
    for(int i=0;i<k;i++){
        st.push(qu.front());
        qu.pop();
    }
    while(st.size()!=0){
        qu.push(st.top());
        st.pop();
    }
    cout<<"Last "<<k<<" elements are reverse successfully !!! "<<endl;
    displayQueue(qu);
}

int main(){
    queue<int> qu;
    int k=4;
    
    qu.push(91);
    qu.push(93);        
    qu.push(95);
    qu.push(7);
    qu.push(1);
    qu.push(3);
    qu.push(5);
    qu.push(17);
    qu.push(81);
    qu.push(100);
    cout<<"Original Queue: ";
    displayQueue(qu);
    reverseLastKthElements(qu,k);
    
}