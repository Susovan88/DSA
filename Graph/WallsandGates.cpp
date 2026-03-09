#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<list>
#include<queue>
#include <bits/stdc++.h>
#define INF 2147483647
using namespace std;

/*
Q. Walls and Gates
Problem
You are given a 2D grid rooms where each cell can have one of three values:
-1 → A wall or obstacle
0 → A gate
INF → An empty room
INF means 2³¹ - 1 = 2147483647.
Your task is to fill each empty room with the distance to its nearest gate.
If it is impossible to reach a gate, leave it as INF.
Distance is calculated using 4 directions only:
up
down
left
right
*/
int n,m;
void wallsAndGates(vector<vector<int>>& grid){
    n=grid.size();
    m=grid[0].size();
    vector<vector<int>>arr={{+1,0},{-1,0},{0,+1},{0,-1}};
    queue<pair<int,int>>qu;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==0)qu.push({i,j});
        }
    }
    while(qu.size()!=0){
        auto top=qu.front();
        qu.pop();
        int r=top.first;
        int c=top.second;

        for(auto val : arr){
            int nR=r+val[0];
            int nC=c+val[1];
            if(nR<0 || nR>=n || nC<0 || nC>=m) continue;
            if(grid[nR][nC]==INF){
                grid[nR][nC]=grid[r][c]+1;
                qu.push({nR,nC});
            }
        }
    }
}


int main() {

    vector<vector<int>> rooms = {
        {INF,-1,0,INF},
        {INF,INF,INF,-1},
        {INF,-1,INF,-1},
        {0,-1,INF,INF}
    };

    wallsAndGates(rooms);

    cout << "Updated Grid:\n";

    for(int i=0;i<rooms.size();i++){
        for(int j=0;j<rooms[0].size();j++){
            cout << rooms[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}