#include <iostream>
#include <cmath> 
#include <string>
#include <stack>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

bool cmd(vector<int>& a, vector<int>& b){
    return a[0] < b[0];
}

// 2751. Robot Collisions
vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& hlt, string dir) {
    int n = pos.size();
    vector<vector<int>> arr;

    for(int i = 0; i < n; i++){
        arr.push_back({pos[i], hlt[i], dir[i]=='R'?1:0, i});
    }

    sort(arr.begin(), arr.end(), cmd);

    stack<int> st;

    for(int i = 0; i < n; i++){
        while(!st.empty()){
            int top = st.top();

            // no collision case
            if(arr[top][2] == 0 || arr[i][2] == 1) break;

            // collision happens (R vs L)
            if(arr[top][1] > arr[i][1]){
                arr[top][1]--;
                arr[i][1] = 0;
                break;
            }
            else if(arr[top][1] == arr[i][1]){
                st.pop();
                arr[i][1] = 0;
                break;
            }
            else{
                st.pop();
                arr[i][1]--;
            }
        }

        if(arr[i][1] > 0){
            st.push(i);
        }
    }

    vector<pair<int,int>> surv;

    while(!st.empty()){
        int x = st.top(); st.pop();
        surv.push_back({arr[x][3], arr[x][1]});
    }

    sort(surv.begin(), surv.end());

    vector<int> ans;
    for(auto &p : surv){
        ans.push_back(p.second);
    }

    return ans;
}

int main() {

    vector<int> pos = {3, 5, 2, 6};
    vector<int> hlt = {10, 10, 15, 12};
    string dir = "RLRL";

    vector<int> result =survivedRobotsHealths(pos, hlt, dir);

    for(int x : result) {
        cout << x << " ";
    }

    return 0;
}