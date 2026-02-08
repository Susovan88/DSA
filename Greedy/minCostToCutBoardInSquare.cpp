#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/minimum-cost-to-cut-a-board-into-squares/1
int minCostToCutBoardInSquare(int m,int n,vector<int>&x,vector<int>&y){
    int hB=1,vB=1; // horizontal_blocks , vertical_blocks
    int total=0;  // min cost
    sort(x.begin(),x.end()); // vertical cut 
    sort(y.begin(),y.end()); // horizontal cut
    int i=x.size()-1;
    int j=y.size()-1;

    while(i>=0 && j>=0){
        if((x[i]>y[j]) || (x[i]==y[j] && hB<vB)){   // vertical cut 
            total=total+(x[i]*vB);
            hB++;
            i--;
        }else{    // horizontal cut
            total=total+(y[j]*hB);
            vB++;   
            j--;        
        }
    }
    while (i>=0){
        total=total+(x[i]*vB);
        hB++;
        i--;
    }
    while(j>=0){
        total=total+(y[j]*hB);
        vB++;   
        j--;   
    }
    return total;
}

int main(){
    vector<int>x{2,1,3,1,4};
    vector<int>y{4,1,2};
    int m=6,n=4;
    cout<<minCostToCutBoardInSquare(m,n,x,y);
}