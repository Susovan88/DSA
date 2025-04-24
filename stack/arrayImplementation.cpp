#include <iostream>
#include <cmath> 
#include <string>
#include <stack>
using namespace std;

class Stack{
    public:
    int arr[6];  // if I use vector then there is no overflow condition.... vector is unlimited size.
    int size;

    Stack(){
        size=-1;
    };

    void push(int val){
        if(size==5){
            cout<<"stack is full."<<endl;
            return;
        }
        size++;
        arr[size]=val;
    };

    void pop(){
        if(size==-1){
            cout<<"stack is already empty."<<endl;;
            return;
        }
        size--;
    }

    int top(){
        if( size==-1){
            cout<<"stack is already empty."<<endl;
            return 0;
        }
        return arr[size];
    }
};

int main(){

    Stack st;
    st.pop();
    st.push(89);
    st.push(8);
    cout<<"size- "<<st.size+1<<endl;
    st.push(9);
    st.push(18);
    cout<<"size- "<<st.size+1<<endl;
    cout<<st.top()<<endl;
    st.pop();
    cout<<"size- "<<st.size+1<<endl;
    cout<<st.top()<<endl;
    st.push(29);
    st.push(84);
    st.push(10);
    cout<<"size- "<<st.size+1<<endl;
    cout<<st.top()<<endl;
    st.push(30);
    cout<<"size- "<<st.size+1<<endl;
    cout<<st.top()<<endl;
}