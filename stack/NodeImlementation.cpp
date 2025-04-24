#include <iostream>
#include <cmath> 
#include <string>
#include <stack>
using namespace std;

class Node{
    public:
    int val;
    Node* next;

    Node(int val){
        this->val=val;
        this->next=NULL;
    };
};

class Stack{
    public:
    Node* head;  
    int size;

    Stack(){
        this->head=NULL;
        size=0;
    };

    Stack(int val){
        Node* newNode=new Node(val);
        this->head=newNode;
        size=1;
    };

    void push(int val){
        Node* newNode=new Node(val);
        if(!head && size==0){
            this->head=newNode;
            size=1;
            return;
        }
        newNode->next=head;
        head=newNode;
        size++;
    };

    void pop(){
        if(!head && size==0){
            cout<<"stack is already empty."<<endl;;
            return;
        }
        head=head->next;
        size--;
    }

    int top(){
        if(!head &&size==0){
            cout<<"stack is already empty."<<endl;
            return 0;
        }
        return head->val;
    }
};

int main(){

    Stack st;
    st.pop();
    st.push(89);
    st.push(8);
    cout<<"size- "<<st.size<<endl;
    st.push(9);
    st.push(18);
    cout<<"size- "<<st.size<<endl;
    cout<<st.top()<<endl;
    st.pop();
    cout<<"size- "<<st.size<<endl;
    cout<<st.top()<<endl;
    st.push(29);
    st.push(84);
    st.push(10);
    cout<<"size- "<<st.size<<endl;
    cout<<st.top()<<endl;
    st.push(30);
    cout<<"size- "<<st.size<<endl;
    cout<<st.top()<<endl;
}