#include<iostream>
#include <bits/stdc++.h>
using namespace std;


// 73. Set Matrix Zeroes
void setZeroes(vector<vector<int>>& mat) { // without using extra space 
    int n=mat.size();
    int m=mat[0].size();
    bool rZ=false; // first row
    bool cZ=false; // first column
    for(int i=0;i<n;i++){
        if(mat[i][0]==0){
            cZ=true;
            break;
        }
    }
    for(int i=0;i<m;i++){
        if(mat[0][i]==0){
            rZ=true;
            break;
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(mat[i][j]==0){
                mat[0][j]=0;
                mat[i][0]=0;
            }
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(mat[0][j]==0 || mat[i][0]==0){
                mat[i][j]=0;
            }
        }
    }
    for(int i=0;i<n && cZ;i++)mat[i][0]=0;
    for(int i=0;i<m && rZ;i++)mat[0][i]=0;
}
/*
HINT=>
The key point is that we use the first row and first column as markers, so we must be careful with them.
Since mat[0][0] is shared by both, we can’t rely on it alone. That’s why we use two flags (firstRowZero and firstColZero) to remember if they originally had any zero.
Without this, the solution can fail in edge cases.
*/

void setZeroes1(vector<vector<int>>& mat) { // usning hashmap
    int n=mat.size();
    int m=mat[0].size();
    unordered_set<int>st1,st2;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==0){
                if(st1.find(i)==st1.end())st1.insert(i);
                if(st2.find(j)==st2.end())st2.insert(j);
            }
        }
    }
    for(auto ele : st1){
        for(int i=0;i<m;i++){
            mat[ele][i]=0;
        }
    }
    for(auto ele : st2){
        for(int i=0;i<n;i++){
            mat[i][ele]=0;
        }
    }
}


int main() {
    vector<vector<int>> mat = {
        {9, 1, 1,3,7,9,0},
        {1, 3, 1,2,4,7,5},
        {1, 1, 1,9,0,2,1}
    };

    setZeroes(mat);

    for (auto &row : mat) {
        for (auto &val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}