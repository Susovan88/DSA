#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<list>
#include<queue>
#include <bits/stdc++.h>
using namespace std;

// Q.733
int n,m;
void helper(int prev,vector<vector<int>>& image, int sr, int sc, int &color){ // dfs 
    if(sr<0 || sr>=n || sc<0 || sc>=m) return;
    if(image[sr][sc]==color || prev!=image[sr][sc]) return;
    image[sr][sc]=color;
    helper(prev,image,sr+1,sc,color);
    helper(prev,image,sr-1,sc,color);
    helper(prev,image,sr,sc+1,color);
    helper(prev,image,sr,sc-1,color);
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    n=image.size();
    m=image[0].size();
    helper(image[sr][sc],image,sr,sc,color);
    return image;
}


int main(){

    vector<vector<int>> image = {
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };

    int sr = 1;
    int sc = 1;
    int color = 2;

    vector<vector<int>> result =floodFill(image,sr,sc,color);

    for(auto &row : result){
        for(auto &val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}