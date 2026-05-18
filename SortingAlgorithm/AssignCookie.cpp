#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 455. Assign Cookies
int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(),g.end());
    sort(s.begin(),s.end());
    int c=0;
    int i=0,j=0;
    while(j<s.size() && i<g.size()){
        if(g[i]<=s[j]){
            j++;
            i++;
            c++;
        }else j++;
    }
    return c;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>g,s;\
    int x;
    while(n--){
        cin>>x;
        g.push_back(x);
    }

    while(m--){
        cin>>x;
        s.push_back(x);
    }
    int ans=findContentChildren(g,s);
    cout<<ans;
}