#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<list>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
void add_edge(int src,int dst,int wt,bool bi_dir=true){
    graph[src][dst]=wt;
    if(bi_dir){ // if bidirectional 
        graph[dst][src]=wt;
    }
}

void viewGraph(){
    for(int i=0;i<graph.size();i++){
        cout<<i<<" -> ";
        for(int j=0;j<graph.size();j++){
            if(graph[i][j]==-1)continue;
            cout<<"("<<i<<" <---"<<graph[i][j]<<"---> "<<j <<") ";
        }
        cout<<endl;
    }
}


int main(){
    int e,v;
    bool bi_dir;
    cin>>e>>v>>bi_dir;
    graph.resize(v,vector<int>(v,-1));

    while(e--){
        int src,dst,wt;
        cin>>src>>dst>>wt;
        add_edge(src,dst,wt,bi_dir);
    }

    viewGraph();
    return 0;
}