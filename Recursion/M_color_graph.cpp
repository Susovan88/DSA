#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1   
// graph -> BFS, recursion , backtracing 
vector<list<int>>graph;
unordered_map<int,int>visited;
bool check(int curr,int m){ // two adjacent vertices share the same color
    for(auto ele : graph[curr]){
        if(visited.find(ele)!=visited.end() && visited[ele]==m){
            return false;
        }
    }
    return true;
}
bool fillColor(int curr,int &m,int &v){
    if(curr==v) return true;
    for(int i=1;i<=m;i++){
        if(check(curr,i)){
            visited[curr]=i;
            if(fillColor(curr+1,m,v)) return true;
            visited.erase(curr);
        }
    }
    return false;
}
void addEdge(int src,int dist){
    graph[src].push_back(dist);
    graph[dist].push_back(src);
}
bool graphColoring(int v, vector<vector<int>> &edges, int m) {
    graph.resize(v,list<int>());
    for(int i=0;i<edges.size();i++){
        addEdge(edges[i][0],edges[i][1]);
    }
    return fillColor(0,m,v);
}

int main() {
    int v = 4;  // number of vertices
    int m = 3;  // number of colors

    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 0}
    };

    if (graphColoring(v, edges, m)) {
        cout << "Graph can be colored with " << m << " colors\n";
    } else {
        cout << "Graph cannot be colored with " << m << " colors\n";
    }

    return 0;
}