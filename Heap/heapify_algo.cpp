#include <iostream>
#include <queue> 
#include <string>
#include <vector>
using namespace std;

void heapify(vector<int>&arr){  // min heap
    int n=arr.size();
    for(int i=n/2-1;i>=0;i--){
        int curr=i;
        while(true){
            int left=curr*2+1,right=curr*2+2;  // 0 based indexing
            if(left>=n)break;
            if(right>=n){
                if(arr[left]<arr[curr]){
                    swap(arr[curr],arr[left]);
                    curr=left;
                }else break;
            }
            else if(arr[left]<arr[right]){
                if(arr[left]<arr[curr]){
                    swap(arr[curr],arr[left]);
                    curr=left;
                }else break;
            }
            else{
                if(arr[right]<arr[curr]){
                    swap(arr[right],arr[curr]);
                    curr=right;
                }else break;
            }
        }
    }
}

int main(){
    vector<int>arr={-1,10,2,14,11,1,4,7,3,15,6};
    heapify(arr);
    for(int i=0;i<arr.size();i++)cout<<arr[i]<<' ';
}