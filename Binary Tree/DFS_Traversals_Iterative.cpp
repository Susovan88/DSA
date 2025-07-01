#include<iostream>
#include <climits>
#include <stack>
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

void preOder(Node* root){
    stack<Node*>st;
    st.push(root);
    while(st.size()!=0){
        Node* t=st.top();
        st.pop();
        cout<<t->val<<" ";
        if(t->right)st.push(t->right);
        if(t->left)st.push(t->left);
    }
}

void inOrder(Node* temp){

}

void postOder(Node* temp){
    
}

int main(){
    Node* r=new Node(1);
    Node* a=new Node(2);
    Node* b=new Node(3);       
    Node* c=new Node(4);
    Node* d=new Node(5);
    Node* e=new Node(6);
    Node* f=new Node(7);
    Node* g=new Node(8);
    Node* h=new Node(9);
    Node* i=new Node(10);
    Node* j=new Node(11);
    Node* k=new Node(12);
    Node* l=new Node(13);

    
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