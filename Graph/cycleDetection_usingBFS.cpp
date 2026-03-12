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
bool bfs(int src,vector<int>&par){
    queue<int>qu;
    qu.push(src);
    vis.insert(src);
    while(qu.size()!=0){
        int curr=qu.front();
        qu.pop();
        for( auto ele : graph[curr]){
            if(vis.find(ele)!=vis.end() && par[curr]!=ele) return true; // if (visited + not parent )=> cycle detected....
            else if(vis.find(ele)==vis.end()){
                qu.push(ele);
                vis.insert(ele);
                par[ele]=curr;
            }
        }
    }
    return false;
}

bool anyCycle(int v){
    vector<int>parent(v,-1);
    for(int i=0;i<v;i++){
        if(vis.find(i)==vis.end() && bfs(i,parent)) return true;
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