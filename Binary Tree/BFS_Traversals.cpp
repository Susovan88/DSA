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

int level(Node* temp){
    if(!temp) return 0;
    return 1+max(level(temp->left),level(temp->right));
}

void printNthLevelElements(Node* temp,int currLevel,int targetLevel){
    if(!temp) return;
    if(currLevel==targetLevel){
        cout<<temp->val<<" ";
        return;  // Base case: if we are at the target level, print the value
    }
    printNthLevelElements(temp->left,currLevel+1,targetLevel);
    printNthLevelElements(temp->right,currLevel+1,targetLevel);
}

void BFS(Node* root){
    int n=level(root);
    for(int i=1;i<=n;i++){
        printNthLevelElements(root,1,i);
        cout << endl; 
    }
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
    BFS(r);
    cout << endl;

    cout << "Elements at level 3: ";
    printNthLevelElements(r,1,3);
    cout << endl;

}