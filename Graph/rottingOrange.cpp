#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<list>
#include<queue>
#include <bits/stdc++.h>
using namespace std;

// 994. Rotting Oranges
vector<vector<int>>arr={{+1,0},{-1,0},{0,+1},{0,-1}};
int orangesRotting(vector<vector<int>>& grid) {
    queue<pair<int,int>>qu;
    int count=0;
    int minutes=0;
    int n=grid.size();
    int m=grid[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                qu.push({i,j});
                count++;
            }else if(grid[i][j]==0)count++;
        }
    }
    qu.push({-1,-1});
    // {-1,-1} -> 1 minute complete...

    if(count==n*m) return 0;

    while(qu.size()!=0){
        auto top=qu.front();
        qu.pop();
        int r=top.first;
        int c=top.second;
        for(auto val:arr){
            if(r+val[0]<0 || r+val[0]>=n || c+val[1]<0 || c+val[1]>=m) continue;
            if(grid[r+val[0]][c+val[1]]==1){
                grid[r+val[0]][c+val[1]]=2;
                qu.push({r+val[0],c+val[1]});
                count++;
            }
        }
        if(qu.front()==make_pair(-1,-1)){
            minutes++;
            qu.pop();
            if(qu.size()!=0)qu.push({-1,-1});
        }
    }
    minutes--;
    return count==n*m? minutes:-1;
}


int main(){
    vector<vector<int>> image = {
        {2,1,1,1,1},
        {1,1,1,0,1},
        {1,1,1,1,0},
        {0,2,1,1,1}
    };

    cout<<"minutes -> "<<orangesRotting(image);
}