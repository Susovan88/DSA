#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<list>
#include<queue>
#include <bits/stdc++.h>
using namespace std;

// 200. Number of Islands

// // Ans 1 -> use DFS
int n,m;
bool visited[301][301]; // use extra space 
void dfs1(int x,int y,vector<vector<char>>& grid){
    if(x<0 || y<0 || x>=n || y>=m) return;
    if(grid[x][y]!='1' || visited[x][y]) return;
    visited[x][y]=true;
    dfs1(x+1,y,grid);
    dfs1(x-1,y,grid);
    dfs1(x,y+1,grid);
    dfs1(x,y-1,grid);
}
int numIslands1(vector<vector<char>>& grid) {
    n=grid.size();
    m=grid[0].size();
    memset(visited,0,sizeof visited);
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]!='0' && !visited[i][j]){
                count++;
                dfs1(i,j,grid);
            }
        }
    }
    return count;
}

// // Ans 2 -> use DFS
// no extra space use 
void dfs(int x,int y,vector<vector<char>>& grid){
    if(x<0 || y<0 || x>=n || y>=m) return;
    if(grid[x][y]!='1') return;
    grid[x][y]='2';
    dfs(x+1,y,grid);
    dfs(x-1,y,grid);
    dfs(x,y+1,grid);
    dfs(x,y-1,grid);
}
// 0 -> water , 1 -> land , 2 -> visited land
int numIslands(vector<vector<char>>& grid) {  
    n=grid.size();
    m=grid[0].size();
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]!='0' && grid[i][j]!='2'){
                count++;
                dfs(i,j,grid);
            }
        }
    }
    return count;
}


// // Ans 3
// using BFS
// 0 -> water , 1 -> land , 2 -> visited land
int numIslands(vector<vector<char>>& grid) {  
    vector<vector<int>>arr={{+1,0},{-1,0},{0,+1},{0,-1}};
    n=grid.size();
    m=grid[0].size();
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='1'){
                count++;
                grid[i][j]='2';
                queue<pair<int,int>>qu;
                qu.push({i,j});
                while(qu.size()!=0){
                    auto ele=qu.front();
                    qu.pop();
                    int r=ele.first;
                    int c=ele.second;
                    for(auto val:arr){
                        if(r+val[0]<0 || r+val[0]>=n || c+val[1]<0 || c+val[1]>=m)continue;
                        if(grid[r+val[0]][c+val[1]]!='1')continue;
                        grid[r+val[0]][c+val[1]]='2';
                        qu.push({r+val[0],c+val[1]});
                    }
                }
            }
        }
    }
    return count;
}


int main(){

    vector<vector<char>> image = {
        {'0','1','0','1'},
        {'1','1','1','0'},
        {'0','0','0','1'},
        {'1','1','1','0'}
    };

    cout<<"Total island are -> "<<numIslands(image);

    return 0;
}