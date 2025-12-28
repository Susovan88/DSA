#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// leetcode - 2385


// Definition for a binary tree node. 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


int amountOfTime(TreeNode* root, int start) {
    unordered_map<TreeNode*,TreeNode*>parentMap;
    queue<pair<TreeNode*,int>>qu1; // curr_node, level
    queue<TreeNode*>qPar;
    unordered_set<int>isInfected;

    TreeNode* temp=NULL;
    TreeNode* infNode=NULL;
    qPar.push(root);
    // map all childs with parents
    while(qPar.size()!=0){
        temp=qPar.front();qPar.pop();
        if(temp->val==start) infNode=temp;  // check which node is already infected.

        if(temp->left){
            parentMap[temp->left]=temp;
            qPar.push(temp->left);
        }
        if(temp->right){
            parentMap[temp->right]=temp;
            qPar.push(temp->right);
        }
    }

    qu1.push({infNode,0});
    isInfected.insert(infNode->val);
    int lv,maxLv=0;
    while(qu1.size()!=0){
        temp=qu1.front().first;
        lv=qu1.front().second;
        qu1.pop();
        maxLv=max(maxLv,lv);
        // parent node
        if(parentMap.find(temp)!=parentMap.end() && isInfected.find(parentMap[temp]->val)==isInfected.end()){  
            qu1.push({parentMap[temp],lv+1});
            isInfected.insert(parentMap[temp]->val);
        }
        // left child node
        if(temp->left && isInfected.find(temp->left->val)==isInfected.end()){
            qu1.push({temp->left,lv+1});
            isInfected.insert(temp->left->val);
        }
        // right child node
        if(temp->right && isInfected.find(temp->right->val)==isInfected.end()){
            qu1.push({temp->right,lv+1});
            isInfected.insert(temp->right->val);
        }
    }

    return maxLv;
}


int main() {
    /*
        Example Tree:
                 1
               /   \
              5     3
               \   / \
                4 10  6
               / \
              9   2

        start = 3
        Expected Output = 4
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(5);
    root->right = new TreeNode(3);

    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(9);
    root->left->right->right = new TreeNode(2);

    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(6);

    int start = 3;

    cout << "Time to infect entire tree: "
         << amountOfTime(root, start) << endl;

    return 0;
}
