#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<list>
#include<queue>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

// 1584. Min Cost to Connect All Points
bool cmd(vector<int>&x,vector<int>&y){
    return x[2]<y[2];
}
class Solution {
public:
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

    int MST(int &v,vector<vector<int>>&arr){ // Kruskal's algorithm => O(ElogE + v)
        int n=arr.size();
        vector<int>parent(v+1);
        vector<int>rank(v+1,0);
        for(int i=0;i<=v;i++)parent[i]=i;

        sort(arr.begin(),arr.end(),cmd); // sort the edge list => ElogE

        int sum=0;
        int minEdge=0; // min edge need v-1 
        for(int i=0;i<n;i++){   // => O(vlog*v) =O(v)
            if(minEdge>=v-1) break;
            if(unionByRank(arr[i][0],arr[i][1],parent,rank)){ // =>O(log*v)
                sum+=arr[i][2];
                minEdge++;
            }
        }
        return sum;
    }

    int manhattanDist(vector<int>&x,vector<int>&y){
        return abs(x[0]-y[0])+abs(x[1]-y[1]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int v=points.size();
        vector<vector<int>>edges; // {source, destination, weight}
        for(int i=0;i<v;i++){
            for(int j=i+1;j<v;j++){
                vector<int>temp(3);
                temp[0]=i;temp[1]=j;
                temp[2]=manhattanDist(points[i],points[j]);
                edges.push_back(temp);
            }
        }
        return MST(v,edges);
    }
};

int main() {
    vector<vector<int>> points = {
        {0,0},
        {2,2},
        {3,10},
        {5,2},
        {7,0}
    };

    Solution sol;
    cout<<sol.minCostConnectPoints(points);

    return 0;
}