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

void deleteAllEvenIdxNumber(queue<int>&qu){
    int n=qu.size();
    for(int i=0;i<n;i++){
        if(i%2==0)qu.pop();
        else{
            int a=qu.front();
            qu.pop();
            qu.push(a);
        }
    }
    cout<<"All the even index elements are poped successfully !!! ";

    displayQueue(qu);
}

void reverseQueue(queue<int>&qu){ // using stack
    stack<int>st;
    while(qu.size()!=0){
        st.push(qu.front());
        qu.pop();
    }
    while(st.size()!=0){
        qu.push(st.top());
        st.pop();
    }
    cout<<"Queue reverse successfully !!! ";
    displayQueue(qu);
}

int main(){
    queue<int> qu;
    qu.push(91);
    qu.push(93);
    qu.push(95);
    qu.push(7);
    qu.push(1);
    qu.push(3);
    qu.push(5);
    qu.push(17);
    qu.push(81);
    displayQueue(qu);
    deleteAllEvenIdxNumber(qu);

    reverseQueue(qu);

    cout<<qu.front()<<" ";
    cout<<qu.back()<<" ";
    cout<<qu.size()<<" ";
    qu.pop();
    qu.pop();
    cout<<qu.front()<<" ";
    cout<<qu.back()<<" ";
    cout<<qu.size()<<endl;

    displayQueue(qu);
    reverseQueue(qu);

}