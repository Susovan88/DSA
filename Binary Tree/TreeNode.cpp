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

void display(Node* temp){
    if(!temp) return;
    cout<<temp->val<<" ";
    display(temp->left);
    display(temp->right);
}

int size(Node* temp){
    if(!temp) return 0;
    return 1+size(temp->left)+size(temp->right);
}

int sumOfAllNode(Node* temp){
    if(!temp) return 0;
    return temp->val+sumOfAllNode(temp->left)+sumOfAllNode(temp->right);
}

int productOfAllNode(Node* temp){
    if(!temp) return 1;
    return temp->val*productOfAllNode(temp->left)*productOfAllNode(temp->right);
}

int maxVal(Node* temp){
    if(!temp) return INT_MIN;
    int leftMax=maxVal(temp->left);
    int rightMax=maxVal(temp->right);
    return max(temp->val,max(leftMax,rightMax));
}

int minVal(Node* temp){
    if(!temp) return INT_MAX;
    int leftMax=minVal(temp->left);
    int rightMax=minVal(temp->right);
    return min(temp->val,min(leftMax,rightMax));
}

int level(Node* temp){
    if(!temp) return 0;
    return 1+max(level(temp->left),level(temp->right));
}

int main(){
    Node* r=new Node(1);
    Node* a=new Node(1);
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


    display(r);

    cout<<"sum of all Nodes is -> "<< sumOfAllNode(r)<<endl;
    cout<<"product of all Nodes is -> "<< productOfAllNode(r)<<endl;

    cout<<"size of Binary Tree is -> "<< size(r)<<endl;

    cout<<"max Node of Binary Tree is -> "<< maxVal(r)<<endl;
    cout<<"min Node of Binary Tree is -> "<< minVal(r)<<endl;
    cout<<"Level of Binary Tree is -> "<< level(r)<<endl;
    cout<<"Hight of Binary Tree is -> "<< level(r)-1<<endl;

}