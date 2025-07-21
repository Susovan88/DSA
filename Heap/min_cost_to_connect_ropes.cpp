#include <iostream>
#include <queue> 
#include <string>
#include <vector>
using namespace std;

// Q ->>
// Given an array, arr[] of rope lengths, connect all ropes into a single rope with the minimum total cost.
// The cost to connect two ropes is the sum of their lengths. 
int minCost(vector<int>& arr) {
    // code here
    int n=arr.size();
    priority_queue<int,vector<int>, greater<int> >pq;
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
    }
    int cost=0;
    int x,y;
    while(pq.size()>1){
        x=pq.top();pq.pop();
        y=pq.top();pq.pop();
        cost+=x+y;
        pq.push(x+y);
    }
    return cost;
}

int main(){
    vector<int>arr={11,14,16,31,8,9,23,12,56,10,20,7};
    int cost=minCost(arr);
    cout<<"minimum cost to connect ropes - "<<cost;
}