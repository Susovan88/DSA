#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
bool visited[7][7];
vector<string>ans;
int n,m;
bool anyBlock(vector<vector<int>>& maze,int x,int y){
    if(x<0 || y<0 || x>=n || y>=m) return true; // out of maze 
    if(visited[x][y]) return true; // already visisted
    if(maze[x][y]==0) return true; // blocked 
    return false;
}
void helper(vector<vector<int>>& maze,int x,int y,string &str){
    if(x==n-1 && y==m-1){ // base case
        ans.push_back(str);
        return;
    }
    //up
    if(!anyBlock(maze,x-1,y)){
        str.push_back('U');
        visited[x-1][y]=true;
        helper(maze,x-1,y,str);
        str.pop_back();
        visited[x-1][y]=false;
    }
    //left
    if(!anyBlock(maze,x,y-1)){
        str.push_back('L');
        visited[x][y-1]=true;
        helper(maze,x,y-1,str);
        str.pop_back();
        visited[x][y-1]=false;
    }
    //right
    if(!anyBlock(maze,x,y+1)){
        str.push_back('R');
        visited[x][y+1]=true;
        helper(maze,x,y+1,str);
        str.pop_back();
        visited[x][y+1]=false;
    }
    //down
    if(!anyBlock(maze,x+1,y)){
        str.push_back('D');
        visited[x+1][y]=true;
        helper(maze,x+1,y,str);
        str.pop_back();
        visited[x+1][y]=false;
    }
    return;
}
vector<string> ratInMaze(vector<vector<int>>& maze) {
    n=maze.size();
    m=maze[0].size();
    string str="";
    memset(visited,0,sizeof visited);
    visited[0][0]=1; // base case
    helper(maze,0,0,str);
    sort(ans.begin(),ans.end());
    return ans;
}

int main() {
    vector<vector<int>> maze = {
        {1, 1, 1, 1, 0, 1},
        {0, 0, 1, 1, 1, 1},
        {1, 1, 1, 0, 1, 0},
        {1, 0, 1, 1, 1, 1},
        {1, 1, 0, 1, 0, 1},
        {0, 1, 1, 1, 1, 1}
    };

    vector<string> res =ratInMaze(maze);
    cout<<"Different ways -> "<<endl;
    for (auto &s : res) {
        cout << s << endl;
    }

    return 0;
}
