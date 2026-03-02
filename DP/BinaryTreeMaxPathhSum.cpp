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

// 124. Binary Tree Maximum Path Sum
unordered_map<TreeNode*,int>dp;
int levelSum(TreeNode* temp){
    if(!temp) return 0;
    if(dp.find(temp)!=dp.end())return dp[temp];
    int mx=max(levelSum(temp->left),levelSum(temp->right));
    return dp[temp]=temp->val + (mx<0? 0 : mx);
}
int maxPathSum(TreeNode* root) {
    if(!root) return INT_MIN;
    int mxS=root->val;
    int leftSum=levelSum(root->right);
    int rightSum=levelSum(root->left);
    mxS=max(mxS,root->val+max(leftSum,rightSum));
    mxS=max(mxS,root->val+leftSum+rightSum);
    mxS=max(mxS,maxPathSum(root->right));
    mxS=max(mxS,maxPathSum(root->left));
    return mxS;
}

int main() {
    /*
            -10
           /    \
          9      20
                /  \
               15   7

       Expected Output: 42
    */

    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << maxPathSum(root) << endl;

    return 0;
}

