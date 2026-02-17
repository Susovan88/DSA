#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;


bool isSafe(vector<vector<char>>& board,int row,int col,int n,char dig){
// hirizantal safe
for(int i=0;i<n;i++){
    if(board[row][i]==dig){
        return false;
    }
}
//
for(int i=0;i<n;i++){
    if(board[i][col]==dig) return false;
}
//
int stRow=(row/3)*3;
int stCol=(col/3)*3;

for(int i =stRow;i<=stRow+2;i++){
    for(int j=stCol;j<=stCol+2;j++){
        if(board[i][j]==dig) return false;
    }
}
return true;
}
bool sudokuHelper(vector<vector<char>>& board,int row,int col,int n){
    if(row==n){
        return true;
    }
    int nexRow=row;
    int nexCol=col+1;
    if(col==n-1){
        nexRow=row+1;
        nexCol=0;
    }
    if(board[row][col]=='.'){
        for(char i='1';i<='9';i++){  // check each digit 1 to 9         
            if(isSafe(board,row,col,n,i)){
                board[row][col]=i;
                if(sudokuHelper(board,nexRow,nexCol,n)) return true;
                board[row][col]='.';
            }
        }
    } 
    else return sudokuHelper(board,nexRow,nexCol,n);
    return false;
}
void solveSudoku(vector<vector<char>>& board) {
    int n=board.size();
    sudokuHelper(board,0,0,n);
}


int main() {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    
    solveSudoku(board);

    // Print solved board
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
