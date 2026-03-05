#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<list>
#include<queue>
#include <bits/stdc++.h>
using namespace std;

// 841. Keys and Rooms
int n;
vector<int>visited;
int count=0;
void helper(vector<vector<int>>& rooms,int idx,int &count){  // dfs
    if(visited[idx]==1) return;
    visited[idx]=1;
    count++;
    for(int i=0;i<rooms[idx].size();i++){
        helper(rooms,rooms[idx][i],count);
    }
}
bool canVisitAllRooms(vector<vector<int>>& rooms) {
    n=rooms.size();
    visited.resize(n,0);
    int count=0;
    helper(rooms,0,count);
    return count==n? true: false;
}


int main(){
    vector<vector<int>> rooms = {
        {1,3},
        {3,0,1},
        {2},
        {0,4},
        {1,2,0}
    };
    cout<<canVisitAllRooms(rooms);
}