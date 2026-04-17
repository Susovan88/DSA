#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// 48. Rotate Image
void rotate(vector<vector<int>>& mat) {
    int n=mat.size();
    // transform 
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            swap(mat[i][j],mat[j][i]);
        }
    }
    // pick each row and reverse it 
    for(int i=0;i<n;i++){
        for(int j=0;j<n/2;j++){
            swap(mat[i][j],mat[i][n-j-1]);
        }
    }
}


int main(){
    vector<vector<int>>mat={
        {12,13,45,78,10},{90,89,13,46,41},{11,22,33,44,55},{10,20,30,40,50},{19,29,59,39,49}
    };
    rotate(mat);
    for(auto ele : mat){
        for(auto val : ele){
            cout<<val<<" ";
        }
        cout<<endl;
    }
}