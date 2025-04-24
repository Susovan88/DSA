#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void merge(vector<int>arr,vector<int>brr,vector<int>& res){
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

void mergeSort(vector<int>&v,int &count){
    int n=v.size();
    if(n<=1) return;
    int n1=n/2,n2=n-n/2;
    vector<int>arr(n1), brr(n2);

    for(int i=0;i<n1;i++) arr[i]=v[i];
    for(int i=0;i<n2;i++) brr[i]=v[i+n1];

    // recursion
    mergeSort(arr,count);
    mergeSort(brr,count);

    // to count inversion
    int i=0,j=0;
    while(i<n1 && j<n2){
        if(arr[i]>brr[j]){
            count+=(n1-i);
            j++;
        }else{
            i++;
        }
    }

    // merge to array
    merge(arr,brr,v);

    arr.clear();
    brr.clear();

}

int main(){

    vector<int>a={5,1,3,0,4,9,6};  // 7
    int c=0; // count number of inversions
    mergeSort(a,c);

    for(int i=0;i<a.size();i++) cout<<a[i]<<" ";

    cout<<"Number of inversions is - "<<c;
}