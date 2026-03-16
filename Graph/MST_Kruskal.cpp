#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<list>
#include<queue>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;


int findParent(int x,vector<int>&parent){
    if( parent[x]==x) return x;
    return parent[x]=findParent(parent[x],parent);
}

bool unionByRank(int x,int y,vector<int>&parent,vector<int>&rank){
    int px=findParent(x,parent);
    int py=findParent(y,parent);

    if(px==py) return false; // cycle exist ...
    if(rank[px]>=rank[py]){
        rank[px]++;
        parent[py]=px;
    }else{
        rank[py]++;
        parent[px]=py;
    }
    return true;
}

bool cmd(vector<int>&x,vector<int>&y){
    return x[2]<y[2];
}

ll MST(int &v,vector<vector<int>>&arr){ // Kruskal's algorithm => O(ElogE + v)
    int n=arr.size();
    vector<int>parent(v+1);
    vector<int>rank(v+1,0);
    for(int i=0;i<=v;i++)parent[i]=i;

    sort(arr.begin(),arr.end(),cmd); // sort the edge list => ElogE

    ll sum=0;
    int minEdge=0; // min edge need v-1 
    for(int i=0;i<n;i++){   // => O(vlog*v) =O(v)
        if(minEdge>=v-1) break;
        if(unionByRank(arr[i][0],arr[i][1],parent,rank)){ // =>O(log*v)
            sum+=arr[i][2];
            cout<<arr[i][1]<<" <----"<<arr[i][2]<<"----> "<<arr[i][0]<<endl;
            minEdge++;
        }
    }
    cout<<"min weight of spamming tree is -> "<<sum;
    return sum;
}

int main() {
    int v,e; // number of vertices, edges
    cin>>v>>e; 

    vector<vector<int>> edges; // {source, destination, weight}
    while(e--){
        vector<int>temp(3);
        cin>>temp[0]>>temp[1]>>temp[2];
        edges.push_back(temp);
    }
    // Call your MST function
    MST(v, edges);
    return 0;
}