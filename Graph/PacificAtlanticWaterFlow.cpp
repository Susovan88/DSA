#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<list>
#include<queue>
#include <bits/stdc++.h>
using namespace std;

// 417. Pacific Atlantic Water Flow
int n,m; 
void dfs(int x,int y,vector<vector<int>>&grid,int val,vector<vector<bool>>&visited){
    if(x<0 || x>=n || y<0 || y>=m) return;
    if(grid[x][y]<val || visited[x][y]) return;
    visited[x][y]=1;
    dfs(x+1,y,grid,grid[x][y],visited);
    dfs(x-1,y,grid,grid[x][y],visited);
    dfs(x,y+1,grid,grid[x][y],visited);
    dfs(x,y-1,grid,grid[x][y],visited);
}
vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
    n=grid.size();
    m=grid[0].size();
    vector<vector<bool>>visited1,visited2;
    visited1.resize(n,vector<bool>(m,0));
    visited2.resize(n,vector<bool>(m,0));

    for(int i=0;i<n;i++){  // it can solved by bfs and dfs
        dfs(i,0,grid,grid[i][0],visited1);
        dfs(i,m-1,grid,grid[i][m-1],visited2);
    }
    for(int i=0;i<m;i++){
        dfs(0,i,grid,grid[0][i],visited1);
        dfs(n-1,i,grid,grid[n-1][i],visited2);
    }
    vector<vector<int>>ans;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visited1[i][j] && visited2[i][j])ans.push_back({i,j});
        }
    }
    return ans;
}


int main(){
    vector<vector<int>> image = {
        {5,1,1,4,2},
        {1,8,2,3,1},
        {1,5,2,3,4},
        {3,8,7,8,9}
    };

    vector<vector<int>>ans(image);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i][0]<<","<<ans[i][1]<<endl;
    }
}