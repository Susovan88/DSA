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
        cout<<i<<" -> ";
        for(auto ele : graph[i]){
            cout<<ele<<" , ";
        }
        cout<<endl;
    }
}

// time complexity - O(V+E)
unordered_set<int>visited; // store the visited points
vector<vector<int>>ans; // store all paths 
void dfs(int curr,int &end,vector<int>&path){
    if(curr==end){
        path.push_back(end);
        ans.push_back(path);
        path.pop_back();
        return;
    }
    visited.insert(curr);
    path.push_back(curr);
    for(auto ele:graph[curr]){
        if(visited.find(ele)==visited.end()){
            dfs(ele,end,path);
        }
    }
    visited.erase(curr);
    path.pop_back();
    return;
}
void allPath(int curr,int end){
    vector<int>path;
    dfs(curr,end,path);
}

int main(){
    int e,v;
    cin>>e>>v;
    graph.resize(v,list<int>());
    vector<int>path;
    while(e--){
        int src,dst;
        cin>>src>>dst;
        add_edge(src,dst);
    }
    viewGraph();

    allPath(0,6);
    cout<<"The all paths are -> "<<endl;
    for(auto arr: ans){
        for(auto ele : arr){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;
}
