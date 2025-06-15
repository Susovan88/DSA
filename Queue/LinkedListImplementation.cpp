#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

class Queue{
    public:
    Node* head;
    Node* tail;
    int n;
    int i;

    Queue(int n){
        this->head=new Node(-1);
        this->tail=this->head;
        this->n=n; 
        this->i=0;       
    }

    void push(int a){
        if(i==n){
            cout<<" -> Overflow! "<<endl;
            return;
        }
        Node* newNode=new Node(a);
        tail->next=newNode;
        tail=tail->next;
        i++;
    }
    void pop(){
        if(i==0){
            cout<<" -> UnderFlow! ";
            return;
        }
        head=head->next;
        i--;
    }
    int front(){
        if(i==0){
            cout<<" -> UnderFlow! ";
            return -1;
        }
        return head->next->data;      
    }
    int back(){
        if(i==0){
            cout<<" -> UnderFlow! ";
            return -1;
        }
        return tail->data;  
    }
    int size(){
        return i;
    }
    void display(){
        if(i==0){
            cout<<" Can not display -> UnderFlow! ";
            return;
        }
        Node * t=head->next;
        cout<<"Display -> ";
        while(t){
            cout<<t->data<<" ";
            t=t->next;
        }
        cout<<endl;
    }
    bool empty(){
        return i==0? true:false;
    }

};

int main(){
    Queue qu(69);
    qu.pop();
    qu.push(91);
    qu.push(93);
    qu.push(95);
    qu.push(7);
    qu.push(1);
    qu.push(3);
    qu.push(5);
    qu.push(17);
    qu.push(81);
    qu.display();

    cout<<qu.front()<<" ";
    cout<<qu.back()<<" ";
    cout<<qu.size()<<" ";
    qu.pop();
    qu.pop();
    cout<<qu.empty()<<" ";
    qu.push(51);
    qu.push(27);
    qu.push(11);
    cout<<qu.front()<<" ";
    cout<<qu.back()<<" ";
    cout<<qu.size()<<endl;

    qu.display();

}