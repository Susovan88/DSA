#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<list>
#include<queue>
#include <bits/stdc++.h>
using namespace std;

// 1034. Coloring A Border (**hints => flood Fill + also check current cell is border or not.**)
int n,m;
vector<pair<int,int>>change; // store the indexs of non border cell
void dfs(int &prev,vector<vector<int>>& grid, int row, int col, int &color){
    if(row<0 || row>=n || col<0 || col>=m) return;
    if(grid[row][col]==color || grid[row][col]!=prev) return;
    grid[row][col]=-color;
    dfs(prev,grid,row+1,col,color);
    dfs(prev,grid,row-1,col,color);
    dfs(prev,grid,row,col+1,color);
    dfs(prev,grid,row,col-1,color);
    if(row==0 || row==n-1 || col==0 || col==m-1) return;
    if((grid[row+1][col]!=-color) ||
        (grid[row-1][col]!=-color) ||
        (grid[row][col+1]!=-color) ||
        (grid[row][col-1]!=-color)) return;

    change.push_back({row,col}); // store for change again
}
vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
    n=grid.size();
    m=grid[0].size();
    int prev=grid[row][col];
    if(prev==color) return grid;
    dfs(prev,grid,row,col,color);
    for(auto ele : change){
        // cout<<ele.first<<" "<<ele.second<<endl;
        grid[ele.first][ele.second]=prev;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]<0)grid[i][j]=abs(grid[i][j]);
        }
    }
    return grid;
}

int main(){

    vector<vector<int>> image = {
        {2,1,1,1},
        {1,1,1,0},
        {1,1,1,1},
        {2,1,1,3}
    };

    int sr = 2;
    int sc = 2;
    int color = 3;

    vector<vector<int>> result =colorBorder(image,sr,sc,color);

    for(auto &row : result){
        for(auto &val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
