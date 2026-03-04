#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<list>
#include<queue>
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
        cout<<i<<" -> ";
        for(auto ele : graph[i]){
            cout<<ele<<" , ";
        }
        cout<<endl;
    }
}

// time complexity - O(V+E)
unordered_set<int>visited; // store the visited points
void bfs(int src,vector<int>&dist){ // give shortest distance from src to every point
    queue<int>qu;
    dist[src]=0;
    qu.push(src);
    visited.insert(src);

    while(qu.size()!=0){
        int curr=qu.front();
        qu.pop();
        for(auto ele : graph[curr]){
            if(visited.find(ele)==visited.end()){
                visited.insert(ele);
                qu.push(ele);
                dist[ele]=dist[curr]+1;
            }
        }
    }
}


int main(){
    int e,v;
    cin>>e>>v;
    vector<int>dist;
    graph.resize(v,list<int>());
    while(e--){
        int src,dst;
        cin>>src>>dst;
        add_edge(src,dst);
    }
    viewGraph();
    
    dist.resize(v,INT_MAX);
    int src;
    cin>>src;
    bfs(src,dist);
    for(auto i :dist){
        cout<<i<<" ";
    }

    return 0;
}
