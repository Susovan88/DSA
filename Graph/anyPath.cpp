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

unordered_set<int>visited; // store the visited points
bool dfs(int curr,int &end){
    if(curr==end)return true;
    visited.insert(curr);
    for(auto ele:graph[curr]){
        if(visited.find(ele)==visited.end() && dfs(ele,end)){
            return true;
        }
    }
    visited.erase(curr);
    return false;
}
bool anyPath(int curr,int end){
    return dfs(curr,end);
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

    bool ans=anyPath(0,6);
    cout<<"ans = "<<ans;
    return 0;
}
