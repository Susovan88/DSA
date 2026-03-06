#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<list>
#include <bits/stdc++.h>
using namespace std;

// Initialization of Graph
vector<list<int>> graph;
void add_edge(int src,int dst,bool bi_dir=true){
    graph[src].push_back(dst);
    if(bi_dir){ // if bidirectional 
        graph[dst].push_back(src);
    }
}

// view graph
void viewGraph(){
    for(int i=0;i<graph.size();i++){
        for(auto ele : graph[i]){
            cout<<i<<" <----> ";
            cout<<ele<<" , ";
        }
        cout<<endl;
    }
}

unordered_set<int>visited; // store the visited points
void dfs(int curr){
    if(visited.find(curr)!=visited.end()) return;
    visited.insert(curr);
    for(auto ele : graph[curr]){
        dfs(ele);
    }
}
// time complexity - O(V+E)
int countConnectedComponent(int v){
    int count=0;
    for(int i=0;i<v;i++){
        if(visited.find(i)!=visited.end()) continue;
        count++;
        dfs(i);
    }
    return count;
}

int main(){
    int e,v;
    cin>>e>>v;
    graph.resize(v,list<int>());
    while(e--){
        int src,dst;
        cin>>src>>dst;
        add_edge(src,dst);
    }
    viewGraph();
    cout<<" count of connected component is -> "<<countConnectedComponent(v);

}
