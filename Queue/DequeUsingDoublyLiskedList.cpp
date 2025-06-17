#include <iostream>
#include <cmath> 
#include <string>
#include <vector>
using namespace std;

class Node{
    public:
    int val;
    Node *next;
    Node* prev;

    Node(int val){
        this->val=val;
        this->next=NULL;
        this->prev=NULL;
    };
};

class  Deque{   // user define data structure
    public:
    Node *head;
    Node *tail;
    int size;

    Deque(){
        head=NULL;
        tail=NULL;
        size=0;
    };

    void pushBack(int val){
        Node *temp=new Node(val);
        if(size==0){
            head=tail=temp;
        }else{
            tail->next=temp;
            temp->prev=tail;
            tail=temp;
        }
        size++;
    }

    void pushFront(int val){
        Node* temp=new Node(val);
        if(head==NULL){
            head=temp;
            tail=temp;
        }else{
            temp->next=head;
            head->prev=temp;
            head=temp;
        }
        size++;
    }

    void popFront(){
        if(size==0)cout<<"Deque is empty!";
        else if(size==1){
            head=tail=NULL;
            size--;
        }
        else{
            head=head->next;
            head->prev=NULL;
            size--;
        }
    }

    void popBack(){
        if(size==0)cout<<"Deque is empty!";
        else if(size==1){
            head=tail=NULL;
            size--;
        }else{
            tail=tail->prev;
            tail->next=NULL;
            size--;
        }
    }

    int front(){
        if(size==0){
            cout<<" -> Underflow! "<<endl;
            return -1;
        }
        return head->val;
    }

    int back(){
        if(size==0){
            cout<<" -> Underflow! "<<endl;
            return -1;
        }
        return tail->val;
    }

    bool empty(){
        return size!=0? true:false;
    }

    void display(){
        Node *temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

    void reverseDispay(){
        Node *temp=tail;
        while(temp){
            cout<<temp->val<<" ";
            temp=temp->prev;
        }
        cout<<endl;
    }

};


int main(){
    Deque qu;
    qu.popBack();
    qu.popFront();
    qu.pushBack(89);
    qu.pushFront(6);
    qu.pushBack(8);
    qu.pushFront(7);
    qu.pushBack(23);
    qu.pushFront(16);
    qu.pushBack(86);
    qu.pushFront(66);
    qu.display();
    qu.reverseDispay();

    cout<<qu.back()<<" ";
    cout<<qu.front()<<" ";
    cout<<qu.empty()<<" ";

    qu.popBack();
    qu.popFront();
    qu.display();
    qu.reverseDispay();


}