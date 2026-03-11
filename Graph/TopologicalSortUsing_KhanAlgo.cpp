#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<list>
#include<queue>
#include <bits/stdc++.h>
using namespace std;

vector<list<int>>graph;
void add_edge(int src,int dest,bool b_dir){
    graph[src].push_back(dest);
    if(b_dir)graph[dest].push_back(src);
}

void tropologicalSort_khans_algo(int v){
    vector<int>indegree(v,0);
    queue<int>qu;
    unordered_set<int>visited;
    for(int i=0;i<v;i++){
        for(auto ele : graph[i]){
            indegree[ele]++;
        }
    }
    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            qu.push(i);
            visited.insert(i);
        }
    }
    cout<<"Processed nodes are -> ";
    while(qu.size()!=0){
        int top=qu.front();
        qu.pop();
        cout<<top<<" ";
        for(auto ele : graph[top]){
            if(visited.find(ele)!=visited.end())continue;
            indegree[ele]--;
            if(indegree[ele]==0)qu.push(ele);
        }
    }
}

int main(){
    int e,v;
    cin>>v>>e;
    graph.resize(v,list<int>());
    while(e--){
        int src,dst;
        cin>>src>>dst;
        add_edge(src,dst,false);
    }
    tropologicalSort_khans_algo(v);
    return 0;
}


/*
8 11
0 2
1 2
1 3
2 4
2 3
2 6
2 5
3 5
5 6
4 6
6 7
Processed nodes are -> 0 1 2 4 3 5 6 7
*/