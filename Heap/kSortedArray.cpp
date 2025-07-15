#include <iostream>
#include <queue> 
#include <string>
#include <vector>
using namespace std;

void sort_kSortedArray(vector<int>&arr,int k){
    priority_queue<int,vector<int>, greater<int> >pq;  // min heap
    int n=arr.size();
    int idx=0;
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
        if(pq.size()>k){
            arr[idx++]=pq.top();
            pq.pop();
        }
    }
    while(!pq.empty()){
        arr[idx++]=pq.top();
        pq.pop();
    }
}

int main(){
    vector<int>arr={10,9,8,7,4,70,60,50};
    int k=4;
    sort_kSortedArray(arr,k);

    cout<<"sorted array is -> ";
    for(int i : arr){
        cout<<i<<" ";
    }
}