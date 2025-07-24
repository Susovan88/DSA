#include <iostream>
#include <queue> 
#include <string>
#include <vector>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }   
};

void leverorderPrint(TreeNode* root){
    if(!root) return;
    queue<TreeNode*>qu;
    qu.push(root);
    while(qu.size()!=0){
        int n=qu.size();
        for(int i=1;i<=n;i++){
            TreeNode* temp=qu.front();qu.pop();
            if(temp->left)qu.push(temp->left);
            if(temp->right)qu.push(temp->right);
            cout<<temp->val<<" ";
        }
    }
    cout<<endl;
}

void print(vector<int>&arr){
    for(int i=0;i<arr.size();i++) cout<<arr[i]<<" ";
    cout<<endl;
}

void helperInorder(vector<int>&arr,TreeNode*root){   // reverse in order
    if(!root) return;

    helperInorder(arr,root->right); // right
    arr.push_back(root->val);  // root
    helperInorder(arr,root->left);   // left
}

void helperPreorder(vector<int>&arr,int &idx,TreeNode* root){
    if(idx>=arr.size() || !root) return;
    root->val=arr[idx++];
    helperPreorder(arr,idx,root->left);
    helperPreorder(arr,idx,root->right);
}

void helperLevelorder(TreeNode* root,vector<int>&arr){
    if(!root) return;
    queue<TreeNode*>qu;
    int idx=0;
    qu.push(root);
    while(qu.size()!=0){
        int n=qu.size();
        for(int i=1;i<=n;i++){
            TreeNode* temp=qu.front();qu.pop();
            temp->val=arr[idx++];
            if(temp->left)qu.push(temp->left);
            if(temp->right)qu.push(temp->right);
        }
    }
    cout<<endl;
}

void convertBSTtoMaxHeap(vector<int>&arr,TreeNode*root){
    if(!root) return;
    helperInorder(arr,root);
    int idx=0;
    helperPreorder(arr,idx,root);  //--> 20 16 8 12 10 5 1
    // // or,
    // helperLevelorder(root,arr);  // --> 20 16 12 10 8 5 1
}


int main(){

    // BST
    TreeNode* a = new TreeNode(10);
    TreeNode* b = new TreeNode(5);
    TreeNode* c = new TreeNode(16);
    TreeNode* d = new TreeNode(1);
    TreeNode* e = new TreeNode(8);
    TreeNode* f = new TreeNode(12);
    TreeNode* g = new TreeNode(20);

    a->left = b; a->right = c;
    b->left = d; b->right = e;
    c->left = f; c->right = g;

    TreeNode * root=a;
    cout<<" BST(levelOrder) -> ";
    leverorderPrint(root);
    vector<int> arr;

    convertBSTtoMaxHeap(arr, root);
    cout<<" Max Heap(levelorder print) is -> ";
    leverorderPrint(root);
}
