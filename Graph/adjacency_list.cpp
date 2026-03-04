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
    return 0;
}