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

bool isRootMax(TreeNode*root){   // reverse in order
    if(!root) return true;
    if(root->left && root->val<root->left->val)return false;
    if(root->right && root->val<root->right->val)return false;
    return isRootMax(root->left) && isRootMax(root->right);
}

int countNodes(TreeNode* root){
    if(!root) return 0;
    return 1+countNodes(root->left)+countNodes(root->right);
}

bool Check_CBT(TreeNode* root){   // check complet Binary tree or not
    if(!root) return true;
    int count=countNodes(root);
    int c=0;
    queue<TreeNode*>qu;
    qu.push(root);
    while(c<count){
        int n=qu.size();
        for(int i=1;i<=n;i++){
            TreeNode* temp=qu.front();qu.pop();
            if(!temp) continue;
            qu.push(temp->left);
            qu.push(temp->right);
            c++;
        }
    }
    while(qu.size()!=0){
        if(qu.front()) return false;
        qu.pop();
    }
    return true;
}

int main(){

    // BST
    TreeNode* root = new TreeNode(50);
    root->left = new TreeNode(30);
    root->right = new TreeNode(40);
    root->left->left = new TreeNode(10);
    root->left->right = new TreeNode(20);
    root->right->left = new TreeNode(35);
    root->right->right = new TreeNode(25);
     // Now 'root' points to the max heap binary tree:
    //        50
    //       /  \
    //      30   40
    //     / \   / \
    //   10  20 35  25

    bool checkBTisMaxHeap=Check_CBT(root) && isRootMax(root);

    cout<<"The Binary tree is a max Heap -> "<< checkBTisMaxHeap? "true":"false";
}
