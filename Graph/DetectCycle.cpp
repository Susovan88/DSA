#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<list>
#include<queue>
#include <bits/stdc++.h>
#define INF 2147483647
using namespace std;

// 1559. Detect Cycles in 2D Grid
int n,m;
vector<vector<bool>>vis;
vector<vector<int>>arr={{+1,0},{-1,0},{0,+1},{0,-1}}; 
bool dfs(int x,int y,int px,int py,vector<vector<char>>& grid){
    vis[x][y]=1;
    bool ans=false;
    for(auto ele : arr){
        if(x+ele[0]<0 || y+ele[1]<0 || x+ele[0]>=n || y+ele[1]>=m) continue;
        if(grid[x][y]==grid[x+ele[0]][y+ele[1]]){
            if(vis[x+ele[0]][y+ele[1]] && (px!=x+ele[0] || py!=y+ele[1] )){ // if visited and not parent then cycle exist
                ans=true;
                break;
            }
            if(!vis[x+ele[0]][y+ele[1]] && dfs(x+ele[0],y+ele[1],x,y,grid)){
                ans=true;
                break;
            }
        }
    }
    return ans;
}
bool containsCycle(vector<vector<char>>& grid) {
    n=grid.size();
    m=grid[0].size();
    vis.resize(n,vector<bool>(m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && dfs(i,j,i,j,grid)) return true;
        }
    }
    return false;
}


int main() {
    vector<vector<char>> grid = {
        {'a','a','a','a'},
        {'a','b','b','a'},
        {'a','b','b','a'},
        {'a','a','a','a'}
    };

    if(containsCycle(grid))
        cout<<"Cycle Found"<<endl;
    else
        cout<<"No Cycle"<<endl;

    return 0;
}