#include<iostream>
#include <climits>
#include <queue>
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

void traversalBFS(Node* root){
    if(!root) return;
    queue<Node*>qu;
    qu.push(root);
    while(qu.size()!=0){
        Node* temp=qu.front();
        qu.pop();
        cout<<temp->val<<" "; // work with the current node
        if(temp->left) qu.push(temp->left);
        if(temp->right) qu.push(temp->right);
    }
    cout<<endl;
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

    cout<<"BFS -> "<<endl;
    traversalBFS(r);

}