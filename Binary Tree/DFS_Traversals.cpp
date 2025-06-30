#include<iostream>
#include <climits>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val=val;
        left=NULL;
        right=NULL;
    }
};

void preOder(Node* temp){
    if(!temp) return;
    cout<<temp->val<<" ";
    preOder(temp->left);
    preOder(temp->right);
}

void inOrder(Node* temp){
    if(!temp) return;
    inOrder(temp->left);
    cout<<temp->val<<" ";
    inOrder(temp->right);
}

void postOder(Node* temp){
    if(!temp) return;
    postOder(temp->left);
    postOder(temp->right);
    cout<<temp->val<<" ";
}

int main(){
    Node* r=new Node(1);
    Node* a=new Node(23);
    Node* b=new Node(2);       
    Node* c=new Node(3);
    Node* d=new Node(4);
    Node* e=new Node(5);
    Node* f=new Node(-6);
    Node* g=new Node(7);
    Node* h=new Node(8);
    Node* i=new Node(9);
    Node* j=new Node(-10);
    Node* k=new Node(11);
    Node* l=new Node(-13);

    
    r->left=a;
    r->right=b;
    a->left=c;
    a->right=d;
    b->left=e;
    b->right=f;
    c->left=g;
    c->right=h;
    d->left=i;
    d->right=j;
    e->left=k;
    f->right=l;


    preOder(r);
    cout << endl;
    inOrder(r);     
    cout << endl;
    postOder(r);
    cout << endl;
}