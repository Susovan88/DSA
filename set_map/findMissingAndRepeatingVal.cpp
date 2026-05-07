#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// 2965. Find Missing and Repeated Values
vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    unordered_set<int>st;
    int repeatingVal=-1;
    int val=1;
    int sum=0; // actual sum;
    int total=0;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(st.find(grid[i][j])!=st.end()) repeatingVal=grid[i][j];
            st.insert(grid[i][j]);
            // actual sum
            sum+=grid[i][j];
            // total sum of array elements
            total+=val;
            val++;
        }
    }
    int missingVal=total-sum+repeatingVal;
    return {repeatingVal,missingVal};
}


int main() {

    vector<vector<int>> grid = {
        {1, 3},
        {2, 2}
    };

    vector<int> ans = findMissingAndRepeatedValues(grid);

    cout << "Repeated Value: " << ans[0] << endl;
    cout << "Missing Value: " << ans[1] << endl;

    return 0;
}