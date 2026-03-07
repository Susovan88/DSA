#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<list>
#include<queue>
#include <bits/stdc++.h>
using namespace std;

// 542. 01 Matrix
vector<vector<int>>arr={{+1,0},{-1,0},{0,+1},{0,-1}};
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int n=mat.size();
    int m=mat[0].size();
    vector<vector<int>>dist;
    dist.resize(n,vector<int>(m,0));
    queue<pair<int,int>>qu;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==0)qu.push({i,j});
        }
    }
    while(qu.size()!=0){
        auto top=qu.front();
        qu.pop();
        int r=top.first;
        int c=top.second;
        for(auto val:arr){
            if(r+val[0]<0 || r+val[0]>=n || c+val[1]<0 || c+val[1]>=m) continue;
            if(mat[r+val[0]][c+val[1]]==1){
                dist[r+val[0]][c+val[1]]=dist[r][c]+1;
                mat[r+val[0]][c+val[1]]=0;
                qu.push({r+val[0],c+val[1]});
            }
        }
    }
    return dist;

}


int main(){
    vector<vector<int>> image = {
        {0,1,1,1,1},
        {1,1,1,0,1},
        {1,1,1,1,1},
        {0,0,1,1,1}
    };

    vector<vector<int>>dist=updateMatrix(image);
    for(int i=0;i<dist.size();i++){
        for(int j=0;j<dist[i].size();j++){
            cout<<dist[i][j]<<",";
        }
        cout<<endl;
    }
}