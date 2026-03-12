#include<iostream>
#include<vector>
#include<string>
using namespace std;


int findParent(int x,vector<int>&parent){
    if(parent[x]==x) return x;
    return parent[x]=findParent(parent[x],parent);
}

bool unionByRank(int x,int y,vector<int>&parent,vector<int>&rank){
    int rootx=findParent(x,parent); // parent of x
    int rooty=findParent(y,parent); // parent of y

    if(rootx==rooty) return true;// both parent of x and y are same , so there is a cycle exist.

    if(rank[rootx]>=rank[rooty]){
        rank[rootx]++;
        parent[rooty]=rootx;
    }else{
        rank[rooty]++;
        parent[rootx]=rooty;
    }

    return false;
}


int main() {

    int n, m;
    cout << "Enter number of vertix and edges: ";
    cin >> n >> m;

    vector<int> parent(n);
    vector<int> rank(n, 0);

    // initialize DSU
    for(int i = 0; i < n; i++) {
        parent[i] = i;
    }
    while(m--){
        int x, y;
        cin >> x >> y;
        bool ans=unionByRank(x, y, parent, rank);
        if(ans){
            cout<<"There is a cycle exist.";
            return 0;
        }
    }

    return 0;
}