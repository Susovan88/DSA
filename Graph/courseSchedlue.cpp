#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<list>
#include<queue>
#include <bits/stdc++.h>
using namespace std;

// 210. Course Schedule II
vector<list<int>>graph;
void add_edge(int src,int dest){
    graph[src].push_back(dest);
}

vector<int> tropologicalSort_khans_algo(int v){ // check is there any cycle exist or no ....
    vector<int>indegree(v,0);
    queue<int>qu;
    unordered_set<int>visited;
    for(int i=0;i<v;i++){
        for(auto ele : graph[i]){
            indegree[ele]++;
        }
    }
    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            qu.push(i);
        }
    }
    vector<int>ans;
    cout<<"Processed nodes are -> ";
    while(qu.size()!=0){
        int top=qu.front();
        qu.pop();
        cout<<top<<" ";
        ans.push_back(top);
        for(auto ele : graph[top]){
            indegree[ele]--;
            if(indegree[ele]==0)qu.push(ele);
        }
    }
    if(ans.size()!=v)return {};
    return ans;
}

vector<int> findOrder(int num, vector<vector<int>>& req) {
    graph.resize(num);
    for(auto ele : req){
        add_edge(ele[1],ele[0]);
    }
    return tropologicalSort_khans_algo(num);
}

int main() {

    int num = 4;

    vector<vector<int>> req = {
        {1,0},
        {2,0},
        {3,1},
        {3,2}
    };

    vector<int> order = findOrder(num, req);

    if(order.size() == 0){
        cout << "Cycle exists";
    }
    else{
        cout << "Topological Order: ";
        for(int x : order){
            cout << x << " ";
        }
    }
    return 0;
}