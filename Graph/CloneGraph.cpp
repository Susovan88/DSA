#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<list>
#include <bits/stdc++.h>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

// 133 clone Graph -> dfs traversal on graph 
vector<Node*>store=vector<Node*>(102,NULL); // store the deep copy of every node 
Node* cloneGraph(Node* node) {
    if(node==NULL) return node;
    if(store[node->val]!=NULL) return store[node->val];
    Node* temp=new Node(node->val);
    store[temp->val]=temp;

    for(Node* ele : node->neighbors){
        temp->neighbors.push_back(cloneGraph(ele));
    }
    return temp;
}

void viewGraph(Node* node){
    for(Node* temp : store){
        if(temp==NULL) continue;
        for(Node* ele : temp->neighbors){
            cout<<temp->val<<"<---------->"<<ele->val<<"  ";
        }
        cout<<endl;
    }
}

int main() {
    // Create nodes
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    // Build graph
    node1->neighbors = {node2, node4};
    node2->neighbors = {node1, node3};
    node3->neighbors = {node2, node4};
    node4->neighbors = {node1, node3};

    // Clone graph
    Node* clone = cloneGraph(node1);

    // View cloned graph
    viewGraph(clone);

    return 0;
}