#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void merge(vector<int>&arr,vector<int>&brr,vector<int>& res){
    int i=0,j=0,k=0;

    while(i<arr.size() && j<brr.size()){
        if(arr[i]<=brr[j]){
            res[k++]=arr[i++];
        }
        else{
            res[k++]=brr[j++];
        }
    }
    while(i<arr.size()){
        res[k++]=arr[i++];
    }
    while(j<brr.size()){
        res[k++]=brr[j++];
    }
}

void mergeSort(vector<int>&v){
    int n=v.size();
    if(n<=1) return;
    int n1=n/2,n2=n-n/2;
    vector<int>arr(n1), brr(n2);

    for(int i=0;i<n1;i++) arr[i]=v[i];
    for(int i=0;i<n2;i++) brr[i]=v[i+n1];

    // recursion
    mergeSort(arr);
    mergeSort(brr);

    // merge
    merge(arr,brr,v);

    arr.clear();
    brr.clear();

}

int main(){

    vector<int>a={23,2,0,8,5,12,9,3,-2,32,43};
    mergeSort(a);

    for(int i=0;i<a.size();i++) cout<<a[i]<<" ";
}