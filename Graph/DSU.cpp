#include<iostream>
#include<vector>
#include<string>
using namespace std;


int findParent(int x,vector<int>&parent){
    if(parent[x]==x) return x;
    return parent[x]=findParent(parent[x],parent);
}
void unionByRank(int x,int y,vector<int>&parent,vector<int>&rank){
    int rootx=findParent(x,parent); // parent of x
    int rooty=findParent(y,parent); // parent of y
    if(rank[rootx]>=rank[rooty]){
        rank[rootx]++;
        parent[rooty]=rootx;
    }else{
        rank[rooty]++;
        parent[rootx]=rooty;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cout << "Enter number of elements and queries: ";
    cin >> n >> m;

    vector<int> parent(n);
    vector<int> rank(n, 0);

    // initialize DSU
    for(int i = 0; i < n; i++) {
        parent[i] = i;
    }

    while(m--) {
        string query;
        cin >> query;

        if(query == "union") {
            int x, y;
            cin >> x >> y;
            unionByRank(x, y, parent, rank);
        }
        else if(query == "find") {
            int x;
            cin >> x;
            cout << findParent(x, parent) << "\n";
        }
        else {
            cout << "Invalid Query\n";
        }
    }

    return 0;
}