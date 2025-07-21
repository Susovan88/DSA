#include <iostream>
#include <queue> 
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef pair<int,int>pi;
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    vector<int>ans(k,0);
    priority_queue<pi>pq; // max heap
    int n=arr.size();
    for(int i=0;i<n;i++){
        pq.push({abs(x-arr[i]),i});
        if(pq.size()>k)pq.pop();
    }
    int idx=k-1;
    while(pq.size()!=0){
        ans[idx--]=arr[pq.top().second];
        pq.pop();
    }
    sort(ans.begin(),ans.end());
    return ans;
}

int main(){
    vector<int>arr={11,10,16,31,8,9,23,12,28,10,20,7};
    vector<int>ans=findClosestElements(arr,4,22);
    cout<<"minimum cost to connect ropes - ";
    for(auto el : ans)cout<<el<<" ";
}