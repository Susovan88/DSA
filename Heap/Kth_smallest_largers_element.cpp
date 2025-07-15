#include <iostream>
#include <queue> 
#include <string>
#include <vector>
using namespace std;

void kth_smallest_element(vector<int>arr,int k){
    priority_queue<int>pq;  // max heap
    int n=arr.size();
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
        if(pq.size()>k)pq.pop();  // pop max element
    }
    cout<<"kth smallest element is - "<<pq.top()<<endl;
}

void kth_largest_element(vector<int>arr,int k){
    priority_queue<int,vector<int>, greater<int> >pq;  // min heap
    int n=arr.size();
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
        if(pq.size()>k)pq.pop();  // pop max element
    }
    cout<<"kth largest element is - "<<pq.top()<<endl;
}

int main(){
    vector<int>arr={11,14,16,31,8,9,23,12,56,10,20,7};
    int k=4;
    kth_largest_element(arr,k);

    kth_smallest_element(arr,k);
}