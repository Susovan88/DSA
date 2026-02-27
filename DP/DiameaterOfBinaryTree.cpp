#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

unordered_map<TreeNode*,int>dp;
int level(TreeNode* temp){
    if(!temp) return 0;
    if(dp.find(temp)!=dp.end())return dp[temp];
    return 1+max(level(temp->left),level(temp->right));
}
int DBT(TreeNode* root) {
    if(!root) return 0;
    int mxD=0;
    mxD=max(mxD,level(root->left)+level(root->right));
    mxD=max(mxD,DBT(root->left));
    mxD=max(mxD,DBT(root->right));
    return mxD;
}

// 543. Diameter of Binary Tree
int main() {
    /*
            1
           / \
          2   3
         / \
        4   5

        Diameter = 3 (path: 4 -> 2 -> 1 -> 3)
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Diameter of Binary Tree:"<<DBT(root) << endl;

    return 0;
}