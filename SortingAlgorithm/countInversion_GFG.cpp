#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;
void margeSortedArray(vector<int>&arr,int st,int mid,int end){
    vector<int>ans;
    int i=st,j=mid+1;
    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            ans.push_back(arr[i]);
            i++;
        }else{
            ans.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mid){
        ans.push_back(arr[i]);
        i++;
    }
    while(j<=end){
        ans.push_back(arr[j]);
        j++;
    }
    i=st;
    for(auto ele : ans){
        arr[i]=ele;
        i++;
    }
    return;
}
int margeAlgo(vector<int>&arr,int st,int end){
    if(st==end)return 0;
    int mid=st+(end-st)/2;
    int count=0;
    count+=margeAlgo(arr,st,mid); 
    count+=margeAlgo(arr,mid+1,end);
    // Count Inversions
    int i=st,j=mid+1;
    while(i<=mid){
        if(j>end)break;
        while(j<=end && arr[i]>arr[j]){
            j++;
            count+=(mid-i+1);
        }
        i++;
    }
    // marge two sorted array 
    margeSortedArray(arr,st,mid,end);
    return count;
}
int inversionCount(vector<int> &arr) {
    n=arr.size();
    return margeAlgo(arr,0,n-1);
}

// 493. Reverse Pairs same solution 
int main(){
    vector<int>arr;
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int count=inversionCount(arr);
    cout<<count<<endl;
}