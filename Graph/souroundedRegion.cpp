#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<list>
#include<queue>
#include <bits/stdc++.h>
using namespace std;

// 130. Surrounded Regions
int n,m;
void dfs(int x,int y,vector<vector<char>>& grid){
    if(x<0 || x>=n || y<0 || y>=m) return;
    if(grid[x][y]=='X' || grid[x][y]=='Z') return;
    grid[x][y]='Z';
    dfs(x+1,y,grid);
    dfs(x-1,y,grid);
    dfs(x,y+1,grid);
    dfs(x,y-1,grid);
}
void solve(vector<vector<char>>&grid) {
    n=grid.size();
    m=grid[0].size();
    for(int i=0;i<n;i++){
        dfs(i,0,grid);
        dfs(i,m-1,grid);
    }
    for(int i=0;i<m;i++){
        dfs(0,i,grid);
        dfs(n-1,i,grid);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='O')grid[i][j]='X';
            else if(grid[i][j]=='Z') grid[i][j]='O';
        }
    }
}

int main(){
    vector<vector<char>> grid = {
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','X','O','X'},
        {'X','O','X','X'}
    };

    solve(grid);

    for(auto ele : grid ){
        for(auto val : ele){
            cout<<val <<" ";
        }
        cout<<endl;
    }

}
