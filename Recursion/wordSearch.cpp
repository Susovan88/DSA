#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// 17. Letter Combinations of a Phone Number
vector<vector<int>>dxy={{1,0},{0,1},{-1,0},{0,-1}};
int visited[7][7];
int n,m;
int w;
bool helper(vector<vector<char>>& board,string &word,int x,int y,int idx){
    if(idx>=w) return true;
    if(x<0 || y<0 || x>=n || y>=m)return false;
    if(visited[x][y]) return false;
    if(board[x][y]!=word[idx]) return false;
    for(int i=0;i<4;i++){
        visited[x][y]=1;
        bool temp=helper(board,word,x+dxy[i][0],y+dxy[i][1],idx+1);
        visited[x][y]=0;
        if(temp) return true;
    }
    return false;
}
bool exist(vector<vector<char>>& board, string word){
    n=board.size();
    m=board[0].size();
    w=word.size();
    memset(visited,0,sizeof visited);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(helper(board,word,i,j,0))return true;
        }
    }
    return false;
}

int main() {

    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    string word = "ABCCED";

    if(exist(board, word))
        cout << "Word Found";
    else
        cout << "Word Not Found";

    return 0;
}