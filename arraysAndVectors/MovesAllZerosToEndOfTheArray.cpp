#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// Q4. Move all zeros to the end of the array.
vector<int> movesZeros2(vector<int>arr){ // Move all zeros to the end WITHOUT changing order of non-zero elements
    int n=arr.size();
    int k=0;// where next non-zero should go
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            swap(arr[i],arr[k]);
            k++;
        }
    }
    return arr;
}

void movesZeros(vector<int>&arr){ // but the order of non zero elements is changed ....
    int n=arr.size();
    int i=0,j=n-1;
    while(j>=0 && arr[j]==0)j--;
    while(i<n && i<j){
        if(arr[i]==0){
            swap(arr[i],arr[j]);
            j--;
            while(j>=0 && arr[j]==0)j--;
        }
        i++;
    }
    return ;
}

int main(){
    vector<int>arr={0, 6, 0, 7, 6, 0, 9, 1 , 0, 0};

    vector<int>ans=movesZeros2(arr);
    for(auto ele : ans)cout<<ele<<" ";
    cout<<endl;

    movesZeros(arr);
    for(auto ele : arr)cout<<ele<<" ";
    cout<<endl;
}