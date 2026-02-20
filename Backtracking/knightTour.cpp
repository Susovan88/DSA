#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// same type quetion -> 2596. Check Knight Tour Configuration(same solution)
int n;
int cVisit=0;
vector<vector<int>>canVisit={{+2,-1},{+2,+1},{-2,-1},{-2,+1},{+1,+2},{-1,-2},{-1,+2},{+1,-2}};
bool isSafe(int x,int y,vector<vector<int>>&isVisit){
    if(x<0 || y<0 || x>=n || y>=n) return false;
    if(isVisit[x][y]!=-1) return false;
    return true;
}

bool knightTour(int x,int y,vector<vector<int>>&isVisit){
    isVisit[x][y]=cVisit;
    if(cVisit==(n*n)-1) return true;
    cVisit++;
    for(int i=0;i<canVisit.size();i++){
        if(isSafe(x+canVisit[i][0],y+canVisit[i][1],isVisit)){
            if(knightTour(x+canVisit[i][0],y+canVisit[i][1],isVisit)) return true;
        }
    }
    // backtrack...
    isVisit[x][y]=-1;
    cVisit--;
    return false;
}


int main(){
    n=5;
    vector<vector<int>>isVisit(n,vector<int>(n,-1));
    knightTour(0,0,isVisit);
    for(int i=0;i<isVisit.size();i++){
        for(int j=0;j<isVisit[i].size();j++){
            cout<<isVisit[i][j]<<" ";
        }
        cout<<endl;
    }
}


