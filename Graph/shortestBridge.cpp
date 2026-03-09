#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<list>
#include<queue>
#include <bits/stdc++.h>
using namespace std;

// 934. Shortest Bridge
/*
Small Hints (3 Simple Steps)
1️⃣ Find first island-> Traverse grid, When first 1 is found → run DFS, Mark island cells -1 and push them into queue
2️⃣ BFS expansion->, Start BFS from all cells of first island, Expand into water (0) layer by layer
3️⃣ Stop when second island found-> When BFS reaches a cell with 1, Current distance = minimum bridge length
*/
int n;
queue<pair<int,int>>qu;
void dfs(int x,int y,vector<vector<int>>& grid){
    if(x<0 || x>=n || y<0 || y>=n)return;
    if(grid[x][y]==0 || grid[x][y]==-1) return;
    qu.push({x,y});
    grid[x][y]=-1;
    dfs(x+1,y,grid);
    dfs(x-1,y,grid);
    dfs(x,y+1,grid);
    dfs(x,y-1,grid);
}
int shortestBridge(vector<vector<int>>& grid) {
    n=grid.size();
    vector<vector<int>>dist;
    vector<vector<int>>arr={{+1,0},{-1,0},{0,+1},{0,-1}}; 
    dist.resize(n,vector<int>(n,0));

    bool done=false;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){
                dfs(i,j,grid);
                done =true;
                break;
            }
        }
        if(done)break;
    }
    cout<<qu.size();

    int minBridge=INT_MAX;
    while(qu.size()!=0){
        auto top=qu.front();
        qu.pop();
        int r=top.first;
        int c=top.second;

        for(auto val : arr){
            int nR=r+val[0];
            int nC=c+val[1];
            if(nR<0 || nR>=n || nC<0 || nC>=n) continue;
            if(grid[nR][nC]==0){
                grid[nR][nC]=-1;
                dist[nR][nC]=dist[r][c]+1;
                qu.push({nR,nC});
            }
            else if(grid[nR][nC]==1){
                minBridge=min(minBridge,dist[r][c]);
            }
        }
    }
    return minBridge;
}

int main(){
    vector<vector<int>> grid = {
        {0,1,0},
        {0,0,0},
        {0,0,1}
    };

    cout << "Shortest Bridge Length: " << shortestBridge(grid) << endl;
}
