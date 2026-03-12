#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<list>
#include<queue>
#include <bits/stdc++.h>
using namespace std;

// 2316. Count Unreachable Pairs of Nodes in an Undirected Graph
int findParent(int x,vector<int>&parent){
    if(parent[x]==x) return x;
    return parent[x]=findParent(parent[x],parent);
}
void unionBySize(int x,int y,vector<int>&parent,vector<int>&size){
    int px=findParent(x,parent);
    int py=findParent(y,parent);
    if(px==py) return;
    if(size[px]>=size[py]){
        size[px]+=size[py];
        parent[py]=px;
    }else{
        size[py]+=size[px];
        parent[px]=py;
    }
}
long long countPairs(int n, vector<vector<int>>& edges) {
    vector<int>parent(n);
    vector<int>size(n,1);
    for(int i=0;i<n;i++) parent[i]=i;
    for(auto ele : edges){
        unionBySize(ele[0],ele[1],parent,size);
    }

    unordered_set<int>conn; // connected component
    vector<int>szConn; // size of all connected component
    for(int i=0;i<n;i++){
        int px=findParent(i,parent);
        if(conn.size()==0 || conn.find(px)==conn.end()){
            conn.insert(px);
            szConn.push_back(size[px]);
            // cout<<size[px]<<" ";
        }
    }

    int m=szConn.size();
    vector<long long>sufix(m,0);
    sufix[m-1]=szConn[m-1];
    for(int i=m-2;i>=0;i--){ // sufix sum
        sufix[i]=(long long)szConn[i]+sufix[i+1];
    }
  
    long long sum=0;
    for(int i=0;i<m-1;i++){
        sum+=(long long)(szConn[i]*sufix[i+1]);
    }
    return sum;
}

int main() {

    int n = 7;
    vector<vector<int>> edges = {
        {0,2},
        {0,5},
        {2,4},
        {1,6},
        {5,4}
    };

    cout << countPairs(n, edges) << endl;

    return 0;
}