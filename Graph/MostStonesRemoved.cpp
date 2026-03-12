#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<list>
#include<queue>
#include <bits/stdc++.h>
using namespace std;

// 947. Most Stones Removed with Same Row or Column
// apply DSU to create connected componentes....
int findParent(int x,vector<int>&parent){
    if(parent[x]==x) return x;
    return parent[x]=findParent(parent[x],parent);
}
void unionByRank(int x,int y,vector<int>&parent,vector<int>&rank){
    int rootx=findParent(x,parent); // parent of x
    int rooty=findParent(y,parent); // parent of y
    if(rootx==rooty) return;
    if(rank[rootx]>=rank[rooty]){
        rank[rootx]++;
        parent[rooty]=rootx;
    }else{
        rank[rooty]++;
        parent[rootx]=rooty;
    }
}

int removeStones(vector<vector<int>>& ston) {
    int n=ston.size(); // total node 
    unordered_map<int,int>row,col; // <row , node>, <col , node>
    vector<int>parent(n);
    vector<int>rank(n,0);
    for(int i=0;i<n;i++) parent[i]=i;

    row[ston[0][0]]=0;
    col[ston[0][1]]=0;
    for(int i=1;i<n;i++){
        if(row.find(ston[i][0])!=row.end()) unionByRank(i,row[ston[i][0]],parent,rank);
        else row[ston[i][0]]=i;

        if(col.find(ston[i][1])!=col.end()) unionByRank(i,col[ston[i][1]],parent,rank);
        else col[ston[i][1]]=i;
    }
    unordered_set<int>conn; // connected component
    for(int i=0;i<n;i++){
        int px=findParent(i,parent);
        if(conn.size()==0 || conn.find(px)==conn.end())conn.insert(px);
    }
    return n-conn.size();
}

int main() {

    vector<vector<int>> stones = {
        {0,0},
        {0,1},
        {1,0},
        {1,2},
        {2,1},
        {2,2}
    };
    cout <<removeStones(stones) << endl;

    return 0;
}