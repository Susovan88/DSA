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


vector<int> topView(Node *root) {
    // code here
    vector<int>arr;
    unordered_map<int,Node*>mp;   // < vertical_level,Node >
    queue<Node*>qu1;  // <Node>
    queue<int>qu2;  // <vertical_level>
    
    qu1.push(root);
    qu2.push(0);
    mp.insert({0,root});
    
    Node* temp=NULL;
    int a; // current vertical level 
    int min_level=0;  // min index of vertical level 
    
    while(qu1.size()!=0){
        temp=qu1.front();
        a=qu2.front();
        qu1.pop(); qu2.pop();
        
        if(mp.find(a)==mp.end()){
            mp[a]=temp;
            min_level=min(min_level,a);
        }
        
        if(temp->left){ // left node -> -1
            qu1.push(temp->left);
            qu2.push(a-1);
        }
        
        if(temp->right){  // right node  -> +1
            qu1.push(temp->right);
            qu2.push(a+1);
        }
    }
    
    while(mp.find(min_level)!=mp.end()){
        arr.push_back(mp[min_level++]->data);
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

    vector<int> result = topView(root);

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}
