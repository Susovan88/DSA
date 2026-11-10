#include <iostream>
#include <cmath> 
#include <string>
#include <stack>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/the-celebrity-problem/
int celebrity(vector<vector<int>>& mat) {
    int n=mat.size();
    int top=0,down=n-1;
    while(top<down){
        if(mat[top][down]==1)top+=1;
        else if(mat[down][top]==1)down-=1;
        else{
            top+=1;
            down-=1;
        }
    }
    
    for(int i=0;i<n;i++){
        if(i!=top && mat[top][i]==1)return -1;
    }
    for(int i=0;i<n;i++){
        if(mat[i][top]==0)return -1;
    }
    return top;
}

int main(){
    vector<vector<int>>mat={
        {1,1,1,0},
        {0,1,0,0},
        {0,1,0,1},
        {1,1,0,0}
    };
    cout<<celebrity(mat);
}