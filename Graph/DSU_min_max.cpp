#include<iostream>
#include<vector>
#include<string>
using namespace std;

int findParent(int x,vector<int>&parent){
    if(parent[x]==x) return x;
    return parent[x]=findParent(parent[x],parent);
}

void unionByRank(vector<int>&parent,vector<int>&sz, vector<int>&rank,vector<int>&minimal, vector<int>&maximal,int x,int y){
    int px=findParent(x,parent);
    int py=findParent(y,parent);
    
    if(px==py) return; // already union done before ....
    if(rank[px]>=rank[py]){
        rank[px]++;
        parent[py]=px;
        sz[px]+=sz[py];
        minimal[px]=min(minimal[px],minimal[py]);
        maximal[px]=max(maximal[px],maximal[py]);
    }else{
        rank[py]++;
        parent[px]=py;
        sz[py]+=sz[px];
        minimal[py]=min(minimal[px],minimal[py]);
        maximal[py]=max(maximal[px],maximal[py]);
    }
}


int main() {

    int n, m;
    cout << "Enter number of elements and queries: ";
    cin >> n >> m;

    vector<int> parent(n+1);
    vector<int> rank(n+1, 0);
    vector<int>minimal(n+1);
    vector<int>maximal(n+1);
    vector<int>sz(n+1,1);

    // initialize DSU
    for(int i = 0; i <=n; i++) {
        parent[i] = minimal[i]=maximal[i]=i;
    }

    while(m--) {
        string query;
        cin >> query;

        if(query == "union") {
            int x, y;
            cin >> x >> y;
            unionByRank(parent,sz,rank,minimal,maximal,x,y);
        }
        else if(query == "get") {
            int x;
            cin >> x;
            int px=findParent(x,parent);
            cout <<minimal[px]<<" "<<maximal[px]<<" "<<sz[px]<<"\n";
        }
        else {
            cout << "Invalid Query\n";
        }
    }
    return 0;
}


/*
Enter number of elements and queries: 5 11
union 1 2
get 3
get 3
3 3 1
get 2
1 2 2
union 2 3
get 2
1 3 3
union 1 3
get 5
5 5 1
union 4 1
get 5
5 5 1
*/