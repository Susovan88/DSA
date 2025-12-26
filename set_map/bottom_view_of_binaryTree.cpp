#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include <vector>
#include<queue>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


vector<int> bottomView(Node *root) {
    // code here
    vector<int>arr;
    queue<pair<Node*,int>>qu;
    unordered_map<int,Node*>mp;
    
    qu.push({root,0});
    
    int minIdx=0;
    
    Node* temp=NULL;int vIdx=0;
    while(qu.size()!=0){
        temp=qu.front().first;
        vIdx=qu.front().second;
        qu.pop();
        
        minIdx=min(minIdx,vIdx);
        
        mp[vIdx]=temp;
        
        if(temp->left){
            qu.push({temp->left,vIdx-1});
        }
        if(temp->right){
            qu.push({temp->right,vIdx+1});
        }
    }
    
    while(mp.size()!=0){
        arr.push_back(mp[minIdx]->data);
        mp.erase(minIdx++);
    }
    
    return arr;
}

int main() {
    /*
            1
           / \
          2   3
           \
            4
             \
              5
               \
                6

        Top View: 2 1 3 6
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(5);
    root->left->right->right->right = new Node(6);

    vector<int> result = bottomView(root);

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}
