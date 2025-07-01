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
   ERATIVE      this->val=val;
        left=NULL;
        right=NULL;
    }
};

void preOder(Node* root){   // root left right
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

//  left → root → right
void inOrder(Node* root) {
    stack<Node*> st;
    Node* t = root;

    while (!st.empty() || t) {
        if (t) {
            st.push(t);
            t = t->left;
        } else {
            Node* temp = st.top();
            st.pop();
            cout << temp->val << " ";
            t = temp->right;
        }
    }
}


void postOder(Node* root){   // left right root
    stack<Node*>st;
    stack<Node*>ts;
    st.push(root);
    while(st.size()!=0){
        Node* t=st.top();
        st.pop();
        ts.push(t);
        if(t->left) st.push(t->left);
        if(t->right) st.push(t->right);
    }
    while(ts.size()!=0){
        Node* t=ts.top();
        ts.pop();
        cout<<t->val<<" ";
    }

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