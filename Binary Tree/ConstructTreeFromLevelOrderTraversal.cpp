#include<iostream>
#include <climits>
#include <queue>
#include <vector>
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

Node* constructTreeFromLevelOrderTraversal(vector<int>&arr){
    int n=arr.size();
    Node* root=new Node(arr[0]);
    queue<Node*>qu;
    qu.push(root);
    int i=1;

    while(qu.size()!=0 && i<n){
        Node* temp=qu.front();
        qu.pop();
        if(arr[i]!=INT_MIN){
            Node* t=new Node(arr[i]);
            temp->left=t;                
            qu.push(t);
        }
        i++;
        if(arr[i]!=INT_MIN){                
            Node* t=new Node(arr[i]);
            temp->right=t;
            qu.push(t);
        }
        i++;
    }
    return root;
}
int main(){
    vector<int>arr={1,2,3,4,5,6,7,INT_MIN,INT_MIN,8,INT_MIN,INT_MIN,9,10,11,12,INT_MIN,13,14,INT_MIN,15}; // INT_MIN means -> NULL
    Node* root=constructTreeFromLevelOrderTraversal(arr);
    traversalBFS(root);
}