#include <iostream>
#include <cmath> 
#include <string>
#include <vector>
using namespace std;

class Node{
    public:
    int val;
    Node *next;

    Node(int val){
        this->val=val;
        this->next=NULL;
    };
};

void change(Node *temp){
    while(temp!=NULL){
        cout<<temp->val<<' ';
        temp=temp->next;
    }
    cout<<endl;
}

void recursiveDisplay(Node *temp){
    if(temp==NULL)return ;
    cout<<temp->val<<" ";
    recursiveDisplay(temp->next);
}

void reverseDispaly(Node *temp){
    if(temp==NULL)return ;
    reverseDispaly(temp->next);
    cout<<temp->val<<" ";
}

void size(Node *temp){
    int n=0;
    while(temp!=NULL){
        n++;
        temp=temp->next;
    }
    cout<<" size is - "<<n<<endl;
}

void insertAtEnd(Node *temp,int val){
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node *newNode=new Node(val);
    temp->next=newNode;
}

int main(){
    Node *a=new Node(58);
    Node *b=new Node(30);
    Node *c=new Node(90);
    Node *d=new Node(1);
    Node *e=new Node(34);

    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;

    change(a);

    size(a);

    recursiveDisplay(a);
    cout<<endl;
    reverseDispaly(a);
    cout<<endl;

    insertAtEnd(a,87);
    insertAtEnd(a,76);

    recursiveDisplay(a);
    cout<<endl;

    insertAtEnd(a,7);
    insertAtEnd(a,90);

    cout<<endl;
    reverseDispaly(a);
}