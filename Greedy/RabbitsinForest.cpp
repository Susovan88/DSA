#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// 781. Rabbits in Forest
int numRabbits(vector<int>& ans) {
    unordered_map<int,int>mp;
    int n=ans.size();
    int minP=0;
    for(int i=0;i<n;i++){
        if(ans[i]==0) minP++;
        else if(mp.find(ans[i]+1)!=mp.end()){
            mp[ans[i]+1]++;
            if(mp[ans[i]+1]==ans[i]+1)mp.erase(ans[i]+1);
        }else{
            mp[ans[i]+1]++;
            minP+=ans[i]+1;
        }
    }
    return minP;
}

int main(){
    vector<int>ans{3,4,12,9,1,12,12,12,12,12,12,3,4,5};
    cout<<numRabbits(ans);
}