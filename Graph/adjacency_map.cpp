#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<list>
#include <bits/stdc++.h>
using namespace std;

vector<unordered_map<int,int>> graph;
void add_edge(int src,int dst,int wt,bool bi_dir){
    graph[src].insert({dst,wt});
    if(bi_dir){ // if bidirectional 
        graph[dst].insert({src,wt});
    }
}

void viewGraph(){
    for(int i=0;i<graph.size();i++){
        cout<<i<<" -> ";
        for(auto ele : graph[i]){
            cout<<"("<<ele.first<<","<<ele.second<<")"<<" , ";
        }
        cout<<endl;
    }
}


int main(){
    int e,v;
    bool bi_dir;
    cin>>e>>v>>bi_dir;
    graph.resize(v,unordered_map<int,int>());

    while(e--){
        int src,dst,wt;
        cin>>src>>dst>>wt;
        add_edge(src,dst,wt,bi_dir);
    }

    viewGraph();
    return 0;
}