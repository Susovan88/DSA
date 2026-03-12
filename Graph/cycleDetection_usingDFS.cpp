#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<list>
#include <bits/stdc++.h>
using namespace std;

vector<list<int>> graph;
void add_edge(int src,int dst,bool bi_dir=true){
    graph[src].push_back(dst);
    if(bi_dir){ // if bidirectional 
        graph[dst].push_back(src);
    }
}

void viewGraph(){
    for(int i=0;i<graph.size();i++){
        cout<<i<<" -> ";
        for(auto ele : graph[i]){
            cout<<ele<<" , ";
        }
        cout<<endl;
    }
}

unordered_set<int>vis; // visited 
bool dfs(int src,int parent){
    vis.insert(src);
    bool ans=false;
    for(auto ele : graph[src]){
        if(vis.find(ele)!=vis.end() && parent!=ele) ans=true; // if (visited + not parent )=> cycle detected....
        else if(vis.find(ele)==vis.end())ans=dfs(ele,src); // if not visited => dfs call
    }
    return ans;
}

bool anyCycle(int v){
    for(int i=0;i<v;i++){
        if(vis.find(i)==vis.end() && dfs(i,-1)) return true;
    }
    return false;
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

    cout<<" any cycle exist -> "<<anyCycle(v);
    return 0;
}